#include "raylib.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "assert.h"
#include "math.h"

#define MIN_VELOCITY_DELTA 0.001
#define FRICTION_FACTOR 0.2
#define GRAVITY 0.5

typedef struct Rect {
	Color col;
	float x, y, w, h, weight, rot, rotVelocity;
	Vector2 velocity;
} Rect;

float randf(float min, float max)
{
	return min + (((float)rand()) / RAND_MAX)*(max-min);
}

Color randColor()
{
	return (Color) {
		rand()%256,
		rand()%256,
		rand()%256,
		255
	};
}

void drawRect(Rect r)
{
	Rectangle drawable = { r.x, r.y, r.w, r.h };
	DrawRectanglePro(drawable, (Vector2) { 0, 0 }, r.rot, r.col);
}

bool isPointInRect(Vector2 p, Rect r)
{
	return r.x <= p.x && p.x < r.x + r.w && r.y <= p.y && p.y < r.y + r.h;
}

int main(void)
{
	int win_width  = 800;
	int win_height = 600;
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(win_width, win_height, "Physics Test");

	bool dragging = false;
	float dragDist = 0.0f; // Distance to center of rectangle when starting to drag it. In range from -1 to 1

	Rect rect = {
		.x = win_width/2.0f,
		.y = win_height/2.0f,
		.w = 100,
		.h = 100,
		.col = RED,
		.rot = 0.0f,
		.weight = 15,
		.velocity = (Vector2) { 0.0f, 0.0f },
		.rotVelocity = 0.0f,
	};

	while (!WindowShouldClose()) {
		if (IsWindowResized()) {
			win_width  = GetScreenWidth();
			win_height = GetScreenHeight();
		}

		float dt = GetFrameTime();
		BeginDrawing();
			ClearBackground(BLACK);
			Vector2 mousePos   = GetMousePosition();
			Vector2 mouseDelta = GetMouseDelta();
			if (!IsKeyDown(MOUSE_LEFT_BUTTON)) dragging = false;
			else if (!dragging) {
				dragging = isPointInRect(mousePos, rect);
				Vector2 center = {
					rect.x + rect.w/2.0f,
					rect.y + rect.h/2.0f,
				};
				float maxDX = rect.w/2.0f - rect.x;
				float maxDY = rect.h/2.0f - rect.y;
				float dx = (mousePos.x - center.x)/maxDX;
				float dy = (mousePos.y - center.y)/maxDY;
				dragDist = sqrtf(dx*dx + dy*dy);
			}
			SetMouseCursor(dragging || isPointInRect(mousePos, rect) ? MOUSE_CURSOR_CROSSHAIR : MOUSE_CURSOR_DEFAULT);

			if (dragging) {
				printf("Dragging\n");
				rect.velocity.x += dt*mouseDelta.x;
				rect.velocity.y += dt*mouseDelta.y;
				rect.rotVelocity += dt*dragDist*(mouseDelta.x + mouseDelta.y)/2.0f;
			}
			drawRect(rect);

			// Update rect
			rect.x += dt*rect.velocity.x;
			rect.y += dt*rect.velocity.y;
			rect.rot += dt*rect.rotVelocity;
		EndDrawing();

	}
	CloseWindow();
	return 0;
}