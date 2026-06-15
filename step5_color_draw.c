// step5: color.csv を読んで raylib で円を描く（完成版）
// コンパイル: gcc step5_color_draw.c -o step5 -lraylib -lm
// 実行:       ./step5

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
            DrawRectangle(cxs[i] - (rs[i] / 2), cys[i] - (rs[i] / 2), (float)rs[i], (float)rs[i], col);
        }

        DrawText("color.csv を書き換えると絵が変わる", 10, 10, 16, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

// 【改造】color.csv に行を追加して、自分だけの絵を作ってみよう

//パンケーキのような絵に改造。

// 【発展】円の代わりに DrawRectangle や DrawTriangle を使ってみよう

//DrawCircleをDrawRectangleにして、描画座標をx, yそれぞれをrs[i]/2引くと、四角いパンケーキが完成。
//rs[i]/2を引く理由は、四角形にしても中心を円の時と等しくするため。
