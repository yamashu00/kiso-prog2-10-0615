#include <stdio.h>
#include "raylib.h"

int main(void) {
    InitWindow(800, 600, "color.csv を描く");
    SetTargetFPS(60);

    FILE *fp = fopen("color.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "color.csv が見つかりません\n");
        return 1;
    }

    char  line[256];
    char  name[64];
    float hue, sat, bri;
    int   cx, cy, r;

    float hues[64], sats[64], bris[64];
    int cxs[64], cys[64], rs[64];
    int count = 0;

    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp) != NULL && count < 64) {
        if (sscanf(line, "%63[^,],%f,%f,%f,%d,%d,%d",
                   name, &hue, &sat, &bri, &cx, &cy, &r) == 7) {
            hues[count] = hue;
            sats[count] = sat;
            bris[count] = bri;
            cxs[count] = cx;
            cys[count] = cy;
            rs[count] = r;
            count++;
        }
    }

    fclose(fp);
    fp = NULL;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        for (int i = 0; i < count; i++) {
            Color col = ColorFromHSV(hues[i], sats[i] / 100.0f, bris[i] / 100.0f);

            DrawTriangle(
                (Vector2){cxs[i], cys[i] - rs[i]},
                (Vector2){cxs[i] - rs[i], cys[i] + rs[i]},
                (Vector2){cxs[i] + rs[i], cys[i] + rs[i]},
                col
            );
        }

        DrawText("color.csv を書き換えると絵が変わる", 10, 10, 16, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}