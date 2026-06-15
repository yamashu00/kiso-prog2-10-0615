// step5: color.csv を読んで raylib で図形を描く（改造版）
// コンパイル: gcc step5_color_draw.c -o step5 $(pkg-config --cflags --libs raylib) -lm
// 実行:       ./step5

#include <stdio.h>
#include <string.h>
#include "raylib.h"

int main(void) {
    InitWindow(800, 600, "color.csv を描く");
    SetTargetFPS(60);

    // ── color.csv を読み込む ──────────────────────────
    FILE *fp = fopen("color.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "color.csv が見つかりません\n");
        return 1;
    }

    char  line[256];
    char  name[64];
    float hue, sat, bri;
    int   cx, cy, r;
    char  shape[16];

    float hues[64]; float sats[64]; float bris[64];
    int   cxs[64];  int   cys[64];  int   rs[64];
    char  shapes[64][16];
    int   count = 0;

    fgets(line, sizeof(line), fp);   // ヘッダを読み飛ばす

    while (fgets(line, sizeof(line), fp) != NULL && count < 64) {
        int fields = sscanf(line, "%63[^,],%f,%f,%f,%d,%d,%d,%15s",
                            name, &hue, &sat, &bri, &cx, &cy, &r, shape);
        if (fields >= 7) {
            hues[count] = hue;  sats[count] = sat;  bris[count] = bri;
            cxs[count]  = cx;   cys[count]  = cy;   rs[count]   = r;
            strcpy(shapes[count], fields == 8 ? shape : "circle");
            count++;
        }
    }
    fclose(fp);
    fp = NULL;

    // ── 描画ループ ────────────────────────────────────
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        for (int i = 0; i < count; i++) {
            // ColorFromHSV: 色相 0-360、彩度 0-1、明度 0-1
            Color col = ColorFromHSV(hues[i], sats[i] / 100.0f, bris[i] / 100.0f);

            if (strcmp(shapes[i], "rectangle") == 0) {
                DrawRectangle(cxs[i] - rs[i], cys[i] - rs[i],
                              rs[i] * 2, rs[i] * 2, col);
            } else if (strcmp(shapes[i], "triangle") == 0) {
                Vector2 top   = {(float)cxs[i],         (float)(cys[i] - rs[i])};
                Vector2 left  = {(float)(cxs[i] - rs[i]), (float)(cys[i] + rs[i])};
                Vector2 right = {(float)(cxs[i] + rs[i]), (float)(cys[i] + rs[i])};
                DrawTriangle(top, right, left, col);
            } else {
                DrawCircle(cxs[i], cys[i], (float)rs[i], col);
            }
        }

        DrawText("color.csv の色・位置・大きさ・図形を書き換えると絵が変わる",
                 10, 10, 16, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

// 【改造済み】color.csv に行を追加して、自分だけの絵を作成
// 【発展済み】8列目の指定に応じて円・長方形・三角形を描画
