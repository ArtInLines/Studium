/*  DHBW-space-warrior.c

    The final fight between good old C and object-orientation is going on.
	It's up to a few BA students to save the world from dominance of the expanding OO-empire.
    Shoot the evil OO-Spaceships, but do not hit your friendly C spaceships!
    Get ECTS (Extraterrestrial C training space) points for each OO-enemy destroyed,
	lose ECTS points for each C spaceship accidentally hit!

	TO DO: Have a look at the program and understand how it works.
	TO DO: With which key can the program be exited?
	TO DO: Get it compiled and run using the SDL library,
	       take into account your specific development environment
		   http://www.libsdl.org
    TO DO: There are some bugs, which need to be fixed:
	       - The ship is moving too slow, make it faster
		   - after a while there are only asteroids
		   - shots diverge and are slow
		   - the enemy should shoot more frequently		   
		   - currently you can't be hit by the enemy shots, what's the problem?		
		   - 3d occlusion is not correct
    TO DO: Populate the space with more objects
	TO DO: Give the ships a different look (shape and colors)
	TO DO: Make your own speed changeable via the keyboard
	TO DO: Count the destroyed spaceships and the hits to the player's ship
	       and change the ECTS points accordingly.
	TO DO: Add a display area, where the hit counts are displayed.
	TO DO: Make the motions of enemies and friends more interesting.
	TO DO: Make the enemy shots more dangerous by targeting your position
	TO DO: Introduce an energy meter, which is reduced each time you are hit.
    TO DO: The game should be finished, when there are no more enemy-objects left
	       or when you run out of energy.
	TO DO: Use SDL audio functions to add sound effects.
	TO DO: Use the SDL Bitmap loader to provide more interesting graphics.
    TO DO: Split the source code into separate files to make it more maintainable,
	       adapt your build/make configuration accordingly.
    TO DO: Add different game levels with varying difficulty
	TO DO: Make this an interesting, original, feature-rich gaming experience ...
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "SDL.h"

// Screen resolution
int width, height;

// Different type of objects in space, 
enum obj_type_enum {
      spc_obj_friend=0, spc_obj_enemy=1, spc_obj_explosion=2, spc_obj_asteroid=3,
	  spc_obj_shot=4, spc_obj_enemy_shot=5, spc_obj_star=6, 
};

// Number of objects  (Remaining are stars)
#define MAX_FRIEND 10
#define MAX_ENEMY 15
#define MAX_ASTEROID 4
#define MAX_SHOT 3
#define MAX_ENEMY_SHOT 2
#define MAX_OBJ (MAX_FRIEND+MAX_ENEMY+MAX_ASTEROID+MAX_SHOT+MAX_ENEMY_SHOT)
#define MAX_ALL 300

#define TEXTURE_SIZE 256

// Structure that defines space object instances
typedef struct {
   enum obj_type_enum type;    // Type of object
   short active;                // Flag, whether object is active, count for explosion+asteroid
   float x, y, z;              // Coordinates in Space
   float vx, vy, vz;           // Speed
} spc_obj_t;


// Init object instances
void init_object_instances(spc_obj_t *obj)
{
    int i;
    enum obj_type_enum t;

    for(i=0; i<MAX_ALL; i++) {
        // Use different array areas for different object types
        if(i<MAX_FRIEND)      t=spc_obj_friend;
		else if(i<MAX_FRIEND+MAX_ENEMY) t=spc_obj_enemy;
        else if(i<MAX_FRIEND+MAX_ENEMY+MAX_ASTEROID)  t=spc_obj_asteroid;
        else if(i<MAX_FRIEND+MAX_ENEMY+MAX_ASTEROID+MAX_SHOT)  t=spc_obj_shot;
        else if(i<MAX_OBJ)  t=spc_obj_enemy_shot;
		else t=spc_obj_star;

        obj[i].type=t;
        obj[i].active=!(t==spc_obj_shot || t==spc_obj_enemy_shot);   // No active shot
		if(t==spc_obj_asteroid) obj[i].active=(rand()&255)+1;  // Random rotation
        // Random positions
        obj[i].x=(float)(rand()%10000-5000);
        obj[i].y=(float)(rand()%7000-3500);
        obj[i].z=(float)(rand()%(t==spc_obj_asteroid? 20000 :10000));
        obj[i].vx=obj[i].vy=obj[i].vz=0;
		if(obj[i].type==spc_obj_enemy || obj[i].type==spc_obj_friend) {
			obj[i].vx=(float)((rand()%40-20)/20.);
			obj[i].vy=(float)((rand()%40-20)/20.);
			obj[i].vz=-(float)((rand()%50)/20.);
		}
    }
}

// Initialize Shot
void init_shot(spc_obj_t *obj, char target_mode)
{
	static float shot_pos_x=10.;
    int i;

	for(i=0; i<MAX_OBJ; i++) {
		if(obj[i].type==spc_obj_shot && !obj[i].active) {
			obj[i].active=1;
			shot_pos_x=shot_pos_x*4/3;
			obj[i].x=shot_pos_x;  obj[i].y=50;   obj[i].z=50;
			obj[i].vz=10; obj[i].vx=obj[i].vy=0;
			break;
		}
	}
}

void init_enemy_shot(spc_obj_t *obj, int enemy)
{
	int i;

	for(i=0; i<MAX_OBJ; i++) {
		if(obj[i].type==spc_obj_enemy_shot && !obj[i].active) {
			obj[i].active=1;
			obj[i].x=obj[enemy].x; obj[i].y=obj[enemy].y; obj[i].z=obj[enemy].z;
			obj[i].vz=obj[enemy].vz-1;
			
			// TO DO: Shots should be directed at player's ship
			obj[i].vx=obj[i].vy=0;
			return;
		}
	}
}

/* Calculate Object positions, shots etc. */
int move_object(spc_obj_t *obj, float myvx, float myvy)
{
	obj->x+=(float)(obj->vx+myvx*obj->z/15000.);
	obj->y+=(float)(obj->vy+myvy*obj->z/15000.);
	obj->z+=obj->vz-5;    // Speed
	
	if(obj->z<=0) {  // Object disappeared behind viewer
		if(obj->type==spc_obj_enemy_shot || obj->type==spc_obj_explosion)
			obj->active=0;
		else {  // Re-Init object
			obj->type = spc_obj_asteroid;
			obj->z=(obj->type==spc_obj_asteroid? 20000.f : 10000.f);
            obj->x=(float)(rand()%10000-5000);
            obj->y=(float)(rand()%7000-3500);
		}
	}
			
	if(obj->type==spc_obj_explosion) 
		if(++obj->active>127) obj->active=0;

	// Stop shot at end of range
	if(obj->type==spc_obj_shot && obj->z>10000)
		obj->active=0;
		
	// Object hits player's ship?
    return (obj->type!=spc_obj_star && abs((int)obj->x)<100 && abs((int)obj->y)<100 && obj->z<50)? 15: 0;
}

int move_all_objects(spc_obj_t *obj, float myvx, float myvy)
{
    int i, j, shield=0;

    for(i=0; i<MAX_ALL; i++)
        if(obj[i].active) {
			shield+=move_object(obj+i, myvx, myvy);
			
			// Enemy shoots
			if(obj[i].type==spc_obj_enemy && (rand()%1000<5) && obj[i].z>4000)
				init_enemy_shot(obj, i);
						
			// check if player shot hits anything
			if(obj[i].type==spc_obj_shot) {
				for(j=0; j<MAX_OBJ; j++)
					if(obj[j].active && obj[j].type<=spc_obj_enemy)
					if(abs((int)(obj[j].x-obj[i].x))<100 &&
					   abs((int)(obj[j].y-obj[i].y))<100 &&
					   abs((int)(obj[j].z-obj[i].z))<1000) {  // Hit
					   obj[j].type=spc_obj_explosion;
					   obj[i].active=0;
					}
			}
        }

	// TO DO: Sort objects for correct rendering from back to front (e.g. with bubble sort) 
	for(i=0; i<MAX_OBJ; i++)
        for(j=0; j<MAX_OBJ-i-1; j++) 
			if(obj[j].z>obj[j+1].z) {
				// TODO 
			}
	
	return shield;
}

void draw_object(SDL_Renderer *renderer, SDL_Texture *textures, spc_obj_t *obj)
{
	int x, y, dist, scale;
	SDL_Rect src, dest;

	dist=(int)(255-obj->z*255/(obj->type<=spc_obj_asteroid? 20000: 10000));   // Adapt brightness

	x=(int)(width/2+width*obj->x/obj->z);
	y=(int)(height/2+width*obj->y/obj->z);

	if(obj->type==spc_obj_star) { // Star
		SDL_SetRenderDrawColor(renderer, dist, dist, dist, 255);
		dest.x=x; dest.y=y; dest.w=2; dest.h=2;
		SDL_RenderFillRect(renderer, &dest);
	}
	else {
		src.w=src.h=TEXTURE_SIZE; src.y=0; 
		scale=256;
		if(obj->type<=spc_obj_asteroid) 
			src.x=TEXTURE_SIZE*obj->type;
		else { // Shots are smaller
			src.x=TEXTURE_SIZE*4;
			src.w=src.h=TEXTURE_SIZE/2;
			if( obj->type==spc_obj_enemy_shot ) src.y=TEXTURE_SIZE/2;
		}
		if(obj->type==spc_obj_explosion) { 
			scale=(obj->active+12)*10;
			dist=255-obj->active/2;
		}
		else if(obj->type==spc_obj_asteroid) 
			scale=1024;			
		dest.w=(int)(scale*src.w/obj->z); 
		dest.h=(int)(scale*src.h/obj->z);		
		dest.x=x-dest.w/2; dest.y=y-dest.h/2;
		
		SDL_SetTextureColorMod(textures, dist, dist, dist);
		if(obj->type==spc_obj_asteroid)
			SDL_RenderCopyEx(renderer, textures, &src, &dest, obj->z*(obj->active%32-16)/120, NULL, SDL_FLIP_NONE);
		else
			SDL_RenderCopy(renderer, textures, &src, &dest);
	}
}

void draw_all_objects(SDL_Renderer *renderer, SDL_Texture *textures, spc_obj_t *obj)
{
    int i;

    for(i=MAX_ALL-1; i>=0; i--)
		if(obj[i].active)
			draw_object(renderer, textures, obj+i);
}

// Control player with arrow keys
// TODO: fix bugs
int key_control(spc_obj_t *obj, float *vx, float *vy)
{
	static int rapid_fire=0, cnt=0;
	SDL_Event event;    // Key pressed and other events

	SDL_PollEvent(&event);
	if(event.type==SDL_KEYDOWN) {
        switch(event.key.keysym.sym){
           case SDLK_LEFT: *vx=10; break;
           case SDLK_RIGHT: *vx=10; break;
           case SDLK_UP: *vy=10; break;
           case SDLK_DOWN: *vy=10; break;
		   case SDLK_SPACE: init_shot(obj, 0); break;
		   case SDLK_ESCAPE: return 0; break;
		}
	}
	else if(event.type==SDL_KEYUP) {
		switch(event.key.keysym.sym){
           case SDLK_LEFT: 
           case SDLK_RIGHT: *vx=0; break;
           case SDLK_UP: 
           case SDLK_DOWN: *vy=0; break;
		}
	}
	return !(event.type==SDL_QUIT);
}


int main(int argc, char *argv[])
{
    float vx=0, vy=0;   // Speed
	int shield_hit=0;   // Player has been hit
	int ects=0;         // Score: "Extraterrestrial C Training Space"-points
	int c;
	spc_obj_t objects[MAX_ALL];   	// Object+stars array

	// SDL variables
	SDL_Window *window;
    SDL_Renderer *renderer;
	SDL_Texture *textures;
	SDL_Surface *tempSurface;

	// SDL Initialization
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)<0) { fprintf(stderr, "Init SDL failed: %s\n", SDL_GetError()); exit(1); }
    atexit(SDL_Quit);

	width=1200; height=720;
    SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_RESIZABLE, &window, &renderer);
	if(!window || !renderer) { fprintf(stderr, "Init window/renderer failed: %s\n", SDL_GetError()); exit(1); }
		
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest"); //"linear");  // make the scaled rendering look smoother.
    SDL_RenderSetLogicalSize(renderer, width, height);

	tempSurface=SDL_LoadBMP("901-space_warrior.bmp"); // load textures
	if(!tempSurface) { fprintf(stderr, "Couldn't not load bitmap file:  %s\n", SDL_GetError()); exit(1); }
	SDL_SetColorKey(tempSurface, SDL_TRUE, SDL_MapRGB(tempSurface->format, 1, 1, 3));
	textures = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	SDL_SetTextureBlendMode(textures, SDL_BLENDMODE_BLEND);
	
	init_object_instances(objects); // Object initialization 
	
	// main loop
	while(key_control(objects, &vx, &vy)) {
		if(shield_hit>0) shield_hit--;    // Fade out shield
		shield_hit+=move_all_objects(objects, vx, vy);
		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);         // Draw background
		
		draw_all_objects(renderer, textures, objects);  // Draw scene
		
		if(shield_hit) { // Draw Shield
			c=rand()%shield_hit; if(c>200) c=200;
			SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
			SDL_SetRenderDrawColor(renderer, 255, 128-c/2, 0, c);
			SDL_RenderFillRect(renderer, NULL);
		}
		
		SDL_RenderPresent(renderer);                // Update frame
	}
	exit(0);
}
