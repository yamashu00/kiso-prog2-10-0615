// step5: color.csv を読んで raylib で円を描く（完成版）
// コンパイル: gcc step5_color_draw.c -o step5 -lraylib -lm
// 実行:       ./step5

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

    float hues[64];
    float sats[64];
    float bris[64];
    int   cxs[64];
    int   cys[64];
    int   rs[64];
    int   count = 0;

    fgets(line, sizeof(line), fp);   // ヘッダを読み飛ばす

    while (fgets(line, sizeof(line), fp) != NULL && count < 64) {
        if (sscanf(line, "%63[^,],%f,%f,%f,%d,%d,%d",
                   name, &hue, &sat, &bri, &cx, &cy, &r) == 7) {
            hues[count] = hue;
            sats[count] = sat;
            bris[count] = bri;
            cxs[count]  = cx;
            cys[count]  = cy;
            rs[count]   = r;
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
            DrawCircle(cxs[i], cys[i], (float)rs[i], col);
        }

        DrawText("color.csv を書き換えると絵が変わる", 10, 10, 16, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

// 【改造】color.csv に行を追加して、自分だけの絵を作ってみよう

// color.csv に行を追加すると、画面に描かれる円が増える。
// このプログラムは color.csv の2行目以降を読み込んで、
// 1行につき1つの円を描いているから。


// すると、それぞれの色・位置・半径に合わせて円が描かれる。
// cx, cy は円の中心の座標で、r は半径。
// hue, sat, bri は色を決める値。
