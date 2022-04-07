/*  803-SDL-example.c
	Program to show how to use the SDL-library.
	How to install the library see: http://www.libsdl.org/
	by Eckhard Kruse
*/

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SDL.h"
//#include "SDL_main.h"

// Graphics data
int width, height;  // Screen resolution

// Constants for balls and their physical behavior
#define MAX_BALLS 150
#define WAIT_TIME 100
#define RADIUS 32
#define BALL_STYLES 16
#define GRAVITY 0.01
#define DAMPING 0.93
#define WEIGHT_OFFSET 0.5
#define VX 2

// Ball data
typedef struct {
	double x, y;    // x, y coordinates
	double vx, vy;  // velocity in x and y direction
	char style;     // display style
	} ball_struct;

ball_struct balls[MAX_BALLS];

int no_balls = 0;  // number of balls, start with 0

// Move a ball according to its velocity and gravity
void move_ball(ball_struct* s) {
	s->vy += GRAVITY;
	s->x += s->vx;
	s->y += s->vy;
	// Check borders
	if (s->x < RADIUS) { s->x = RADIUS; s->vx *= -DAMPING; }
	if (s->y < RADIUS) { s->y = RADIUS; s->vy *= -DAMPING; }
	if (s->x > width - RADIUS) { s->x = width - RADIUS; s->vx *= -DAMPING; }
	if (s->y > height - RADIUS) { s->y = height - RADIUS; s->vy *= -DAMPING; }
	}

// Collision between two balls
void check_collision(ball_struct* s1, ball_struct* s2) {
	double m21, dvx2, a, x21, y21, vx21, vy21, xm, ym, fac;

	// Distance bigger than twice the radius? -> balls do not touch
	if ((s1->x - s2->x) * (s1->x - s2->x) + (s1->y - s2->y) * (s1->y - s2->y) > 4 * RADIUS * RADIUS)
		return;

	m21 = (s2->style + WEIGHT_OFFSET) / (s1->style + WEIGHT_OFFSET);  // mass ratio
	x21 = s2->x - s1->x;  y21 = s2->y - s1->y;  vx21 = s2->vx - s1->vx;  vy21 = s2->vy - s1->vy;

	xm = (s1->x + s2->x) / 2.; ym = (s1->y + s2->y) / 2.;
	fac = RADIUS / sqrt((x21 * x21) + (y21 * y21));
	s1->x = (s1->x * 0.2 + xm - fac * x21) / 1.2;
	s1->y = (s1->y * 0.2 + ym - fac * y21) / 1.2;
	s2->x = (s2->x * 0.2 + xm + fac * x21) / 1.2;
	s2->y = (s2->y * 0.2 + ym + fac * y21) / 1.2;

	// Assure that balls are approaching
	if (vx21 * x21 + vy21 * y21 >= 0) return;

	if (x21 == 0.) x21 = 1.0E-5;   // Cheat to avoid special treatment for x1==x2
	a = y21 / x21;
	dvx2 = -2 * (vx21 + a * vy21) / ((1 + a * a) * (1 + m21)) * DAMPING;

	s2->vx += dvx2; s2->vy += a * dvx2; s1->vx -= m21 * dvx2; s1->vy -= m21 * a * dvx2;
	}

// Move all balls
void move_balls() {
	int i, j;
	static int cnt = 0;   // Internal counter for starting new balls

	for (i = 0; i < no_balls; i++) {
		move_ball(&balls[i]);
		for (j = i + 1; j < no_balls; j++)
			check_collision(&balls[i], &balls[j]);
		}

	if (--cnt < 0 && no_balls < MAX_BALLS) {   // Create new ball
		balls[no_balls].x = balls[no_balls].y = balls[no_balls].vy = 0;
		balls[no_balls].vx = VX;
		balls[no_balls].style = no_balls % BALL_STYLES;
		no_balls++;
		cnt = WAIT_TIME;
		}
	}

/*******************************************************************
 * Functions using the SDL-Graphics-library                        *
 * for drawing the graphics on the screen                          *
 * Hinweis: Detailliertes Verständnis der verschiedenen            *
 *          SDL-Funktionen ist fär Programmiercamp/Klausur nicht   *
 *          erforderlich. Es genügt, die bereit gestellten         *
 *          Funktionen als 'Black Box' aufzurufen.                 *
 *******************************************************************/
 // draw balls
void paint_all(SDL_Renderer* renderer, SDL_Texture* ballTexture) {
	int i;
	SDL_Rect src, dest;

	src.w = src.h = dest.w = dest.h = RADIUS * 2;
	for (i = 0; i < no_balls; i++) {
		src.x = 0; src.y = balls[i].style * RADIUS * 2;
		dest.x = (int)balls[i].x - RADIUS; dest.y = (int)balls[i].y - RADIUS;
		SDL_RenderCopy(renderer, ballTexture, &src, &dest);
		}
	}

// SDL-Function to check mouse motion and if Escape or window-close has been pressed
int escape_pressed() {
	SDL_Event keyevent;
	int i;

	SDL_PollEvent(&keyevent);

	if (keyevent.type == SDL_MOUSEMOTION) {    // If mouse motion, stir up balls
		for (i = 0; i < no_balls; i++) {
			if ((keyevent.motion.x - balls[i].x) * (keyevent.motion.x - balls[i].x)
				+ (keyevent.motion.y - balls[i].y) * (keyevent.motion.y - balls[i].y)
				< RADIUS * RADIUS) {
				balls[i].vx += keyevent.motion.xrel / 8.;
				balls[i].vy += keyevent.motion.yrel / 8.;
				}
			}
		}
	return keyevent.type == SDL_QUIT || (keyevent.type == SDL_KEYDOWN && keyevent.key.keysym.sym == SDLK_ESCAPE);
	}

// Create ball images with phong shading
SDL_Texture* init_ball_textures(SDL_Renderer* renderer) {
	short bl, i, j;
	float rgb[3], x, y, z, phong, spec;
	int rgbi[4];  // rgb + alpha
	SDL_Texture* ballTexture;
	Uint32 pixels[RADIUS * 2 * RADIUS * 2 * BALL_STYLES], c; // BALL_STYLE: Number of Balls, each with x_size=y_size=RADIUS*2 

	ballTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, 2 * RADIUS, 2 * RADIUS * BALL_STYLES);

	for (bl = 0; bl < BALL_STYLES; bl++) {
		for (j = 0; j < 3; j++) rgb[j] = (rand() % 1001) / 1000.; // Ballcolor
		for (i = 0; i < RADIUS * 2 * RADIUS * 2; i++) {
			x = (float)(i % (2 * RADIUS)) / (2 * RADIUS - 1.) * 2. - 1;
			y = (i / 2 / RADIUS) / (2 * RADIUS - 1.) * 2. - 1;
			if (x * x + y * y <= 1.) {
				z = sqrt(1 - x * x - y * y);
				phong = ((z * 0.8) + (-y * 0.5) + (-x * 0.3)); if (phong < 0) phong = 0;
				spec = phong * phong * phong * phong;
				for (j = 0; j < 3; j++) {
					rgbi[j] = (int)((rgb[j] * 0.3 + rgb[j] * phong * 0.6 + spec * 0.5) * 255);  // Ambient+Diffuse+Specular
					if (rgbi[j] > 255) rgbi[j] = 255;
					}
				z = 1 - x * x - y * y;
				rgbi[3] = z <= 2. / RADIUS ? (int)(255 * z * RADIUS / 2.) : 255; // Antialiasing
				c = rgbi[0] << 16 | rgbi[1] << 8 | rgbi[2] | rgbi[3] << 24;
				}
			else c = 0;
			pixels[i + bl * RADIUS * 2 * RADIUS * 2] = c;
			}
		}
	SDL_UpdateTexture(ballTexture, NULL, pixels, 2 * RADIUS * sizeof(Uint32));
	SDL_SetTextureBlendMode(ballTexture, SDL_BLENDMODE_BLEND);

	return ballTexture;
	}

// main function
int main(int argc, char* argv[]) {
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* ballTexture;

	if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Init SDL failed: %s\n", SDL_GetError()); exit(1);
		}
	atexit(SDL_Quit);

	width = 1000; height = 700;    // size of window

	window = SDL_CreateWindow("SDL Example",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width, height, SDL_WINDOW_RESIZABLE);

	if (window == NULL) { fprintf(stderr, "Init video failed: %s\n", SDL_GetError()); exit(1); }
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL) { fprintf(stderr, "Init renderer failed: %s\n", SDL_GetError()); exit(1); }
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoother.
	SDL_RenderSetLogicalSize(renderer, width, height);


	ballTexture = init_ball_textures(renderer);

	// main loop
	while (!escape_pressed()) {
		move_balls();

		SDL_SetRenderDrawColor(renderer, 220, 241, 255, 255);
		SDL_RenderClear(renderer);         // Draw background
		paint_all(renderer, ballTexture);  // Draw balls
		SDL_RenderPresent(renderer);       // Update frame
		}
	return 0;
	}
