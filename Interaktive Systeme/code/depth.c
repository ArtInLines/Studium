#include "raylib.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "assert.h"

#define RECTS_AMOUNT 50
#define MAX_SHADOW_OFFSET 25
#define Z_MIN 0.01f
#define Z_MAX 0.8f
#define START_FADING_AFTER 1.0 // in secs
#define FADING_SPEED 0.1f

typedef struct Rect {
	float x, y, z, w, h;
	char *text;
	Color c;
} Rect;

float randf(float min, float max)
{
	return min + (((float)rand()) / RAND_MAX)*(max-min);
}

void swap(Rect *rects, int i, int j)
{
	Rect tmp = rects[i];
	rects[i] = rects[j];
	rects[j] = tmp;
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

Rect randRect()
{
	char *text = malloc(3);
	text[0] = '1' + rand()%9;
	text[1] = '0' + rand()%10;
	text[2] = 0;
	return (Rect) {
		randf(0.0f, 0.8f),
		randf(0.0f, 0.8f),
		randf(Z_MIN, Z_MAX),
		randf(0.2f, 0.4f),
		randf(0.2f, 0.4f),
		text,
		randColor(),
	};
}

Color transformColor(Color c, float z)
{
	Vector3 hsv = ColorToHSV(c);
	hsv.y *= (1 - z*0.5);
	hsv.z *= (1 - z*0.5);
	return ColorFromHSV(hsv.x, hsv.y, hsv.z);
}

Rectangle getDrawableRect(Rect r, int win_width, int win_height)
{
	return (Rectangle) {
		.x      = r.x * win_width,
		.y      = r.y * win_height,
		.width  = r.w * win_width  * (1-r.z),
		.height = r.h * win_height * (1-r.z),
	};
}

void drawRect(Rect rect, int win_width, int win_height, bool hovered, bool selected)
{
	float roundness = 0.1f;
	int   segments  = 15;
	int   border    = 5;
	Color shadow_color = { .r = 0, .g = 0, .b = 0, .a = 50 };
	int shadow_offset  = (1-rect.z) * MAX_SHADOW_OFFSET;

	Rectangle r = getDrawableRect(rect, win_width, win_height);
	int font_size  = ((r.width < r.height) ? r.width : r.height)/2;
	int text_width = MeasureText(rect.text, font_size);
	Color c = transformColor(rect.c, rect.z);
	Rectangle ray_rect = { r.x, r.y, r.width, r.height };
	Rectangle outline_rect = { r.x + border, r.y + border, r.width - 2*border, r.height - 2*border };

	// @TODO: Shadows don't take the distance to other rectangles into account
	DrawRectangleRounded((Rectangle) { r.x + shadow_offset, r.y + shadow_offset, r.width, r.height }, roundness, segments, shadow_color); // Shadow
	DrawRectangleRounded(ray_rect, roundness, segments, c);
	if      (selected) DrawRectangleRoundedLines(outline_rect, roundness, segments, border, WHITE);
	else if (hovered)  DrawRectangleRoundedLines(outline_rect, roundness, segments, border, rect.c);
	DrawText(rect.text, r.x + (r.width - text_width)/2, r.y + (r.height - font_size)/2, font_size, WHITE);
}

bool isPointInRect(Vector2 p, Rectangle r)
{
	return r.x <= p.x && p.x < r.x + r.width && r.y <= p.y && p.y < r.y + r.height;
}

void sort(Rect *rects)
{
	for (int i = 0; i < RECTS_AMOUNT - 1; i++) {
		int min = i;
		for (int j = i + 1; j < RECTS_AMOUNT; j++) {
			if (rects[j].z < rects[min].z) min = j;
		}
		swap(rects, i, min);
	}
}

bool isSorted(Rect *rects)
{
	for (int i = 1; i < RECTS_AMOUNT; i++) {
		if (rects[i].z <= rects[i-1].z) return false;
	}
	return true;
}

int main(void)
{
	srand(time(0));
	Rect rects[RECTS_AMOUNT] = {0};
	int win_width  = 800;
	int win_height = 600;
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(win_width, win_height, "Depth Test");

start:
	for (int i = 0; i < RECTS_AMOUNT; i++) rects[i] = randRect();
	sort(rects);
	int selected = -1;
	float fading_timer = 0.0f;
	while (!WindowShouldClose()) {
		bool acted  = false;
		int hovered = -1;
		if (IsWindowResized()) {
			win_width  = GetScreenWidth();
			win_height = GetScreenHeight();
		}
		BeginDrawing();
			ClearBackground(BLUE);
			Vector2 mouse_pos   = GetMousePosition();
			Vector2 mouse_delta = GetMouseDelta();
			for (int i = 0; i < RECTS_AMOUNT && hovered < 0; i++) {
				if (hovered < 0 && isPointInRect(mouse_pos, getDrawableRect(rects[i], win_width, win_height))) {
					hovered = i;
				}
			}

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				selected = hovered;
				if (selected >= 0) acted = true;
			}
			if (selected >= 0) {
				if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
					rects[selected].x += mouse_delta.x/win_width;
					rects[selected].y += mouse_delta.y/win_height;
					acted = true;
				} else {
					float zd = GetMouseWheelMove()*0.1f;
					if (zd != 0.0f) acted = true;
					rects[selected].z += zd;
					while (zd < 0.0f && selected > 0 && rects[selected].z < rects[selected-1].z) {
						swap(rects, selected, selected-1);
						selected--;
						hovered--;
					}
					while (zd > 0.0f && selected < RECTS_AMOUNT - 1 && rects[selected].z > rects[selected+1].z) {
						swap(rects, selected, selected+1);
						selected++;
						hovered++;
					}
					if      (rects[selected].z < Z_MIN) rects[selected].z = Z_MIN;
					else if (rects[selected].z > Z_MAX) rects[selected].z = Z_MAX;
				}
			} else {
				float zd = GetMouseWheelMove()*0.1f;
				if (zd != 0.0f) acted = true;
				for (int i = 0; i < RECTS_AMOUNT; i++) {
					rects[i].z += zd;
					if      (rects[i].z < Z_MIN) rects[i].z = Z_MIN;
					else if (rects[i].z > Z_MAX) rects[i].z = Z_MAX;
				}
			}

			for (int i = RECTS_AMOUNT-1; i >= 0; i--) {
				drawRect(rects[i], win_width, win_height, hovered==i, selected==i);
			}
		EndDrawing();
		if (IsKeyPressed(KEY_R)) goto start;

		float dt = GetFrameTime();
		if (acted) fading_timer = 0.0f;
		else fading_timer += dt;
		if (fading_timer > START_FADING_AFTER) {
			for (int i = 0; i < RECTS_AMOUNT; i++) {
				rects[i].z += FADING_SPEED*dt;
				if      (rects[i].z < Z_MIN) rects[i].z = Z_MIN;
				else if (rects[i].z > Z_MAX) rects[i].z = Z_MAX;
			}
		}
	}
	CloseWindow();
	return 0;
}