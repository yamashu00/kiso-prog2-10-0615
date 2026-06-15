// step5_color_draw: color.csv を読んでドラえもんの顔を描く
// コンパイル: gcc step5_color_draw.c -o step5 $(pkg-config --cflags --libs raylib) -framework Cocoa -framework IOKit -framework OpenGL
// 実行:       ./step5

#include <stdio.h>
#include "raylib.h"

int main(void) {
    InitWindow(800, 600, "color.csv でドラえもんを描く");
    SetTargetFPS(60);

    // ── color.csv を読み込む ──────────────────────────
    FILE *fp = fopen("color.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "color.csv が見つかりません\n");
        CloseWindow();
        return 1;
    }

    char  line[256];
    char  name[64];
    float hue, sat, bri;
    int   cx, cy, r;

    float hues[64]; float sats[64]; float bris[64];
    int   cxs[64];  int   cys[64];  int   rs[64];
    int   count = 0;

    fgets(line, sizeof(line), fp);   // ヘッダを読み飛ばす

    while (fgets(line, sizeof(line), fp) != NULL && count < 64) {
        if (sscanf(line, "%63[^,],%f,%f,%f,%d,%d,%d",
                   name, &hue, &sat, &bri, &cx, &cy, &r) == 7) {
            hues[count] = hue;  sats[count] = sat;  bris[count] = bri;
            cxs[count]  = cx;   cys[count]  = cy;   rs[count]   = r;
            count++;
        }
    }
    fclose(fp);
    fp = NULL;

    // ── 描画ループ ────────────────────────────────────
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // CSV から読んだ円を順に描く（後の行ほど手前）
        for (int i = 0; i < count; i++) {
            Color col = ColorFromHSV(hues[i], sats[i] / 100.0f, bris[i] / 100.0f);
            DrawCircle(cxs[i], cys[i], (float)rs[i], col);
        }

        // 目の白（縦長の楕円）
        DrawEllipse(372, 200, 26, 34, WHITE);
        DrawEllipse(428, 200, 26, 34, WHITE);
        DrawEllipseLines(372, 200, 26, 34, BLACK);
        DrawEllipseLines(428, 200, 26, 34, BLACK);
        // 黒目
        DrawCircle(385, 210, 9, BLACK);
        DrawCircle(415, 210, 9, BLACK);

        // ── 線のパーツ（CSV では表現しにくいのでコードで描く）──

        // 鼻から下に伸びる線
        DrawLine(400, 270, 400, 410, BLACK);

        // ヒゲ（左右3本ずつ）
        for (int i = -1; i <= 1; i++) {
            DrawLine(355, 250 + i*15, 290, 240 + i*28, BLACK); // 左
            DrawLine(445, 250 + i*15, 510, 240 + i*28, BLACK); // 右
        }

        // 鼻から下に伸びる線（鼻〜口まで）
        DrawLine(400, 270, 400, 365, BLACK);

        // 口（赤い半円：下向き）
        Vector2 mouthCenter = { 400, 365 };
        DrawCircleSector(mouthCenter, 85, 0, 180, 32, RED);

        DrawText("color.csv を書き換えると顔が変わる", 10, 10, 16, GRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

// step5: color.csv を読んで raylib で円を描く（完成版）
// コンパイル: gcc step5_color_draw.c -o step5 -lraylib -lm
// 実行:       ./step5

/*
#include <stdio.h>
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

    float hues[64]; float sats[64]; float bris[64];
    int   cxs[64];  int   cys[64];  int   rs[64];
    int   count = 0;

    fgets(line, sizeof(line), fp);   // ヘッダを読み飛ばす

    while (fgets(line, sizeof(line), fp) != NULL && count < 64) {
        if (sscanf(line, "%63[^,],%f,%f,%f,%d,%d,%d",
                   name, &hue, &sat, &bri, &cx, &cy, &r) == 7) {
            hues[count] = hue;  sats[count] = sat;  bris[count] = bri;
            cxs[count]  = cx;   cys[count]  = cy;   rs[count]   = r;
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
            DrawCircle(cxs[i], cys[i], (float)rs[i], col);
        }

        DrawText("color.csv を書き換えると絵が変わる", 10, 10, 16, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
*/

// 【改造】color.csv に行を追加して、自分だけの絵を作ってみよう
// 【発展】円の代わりに DrawRectangle や DrawTriangle を使ってみよう