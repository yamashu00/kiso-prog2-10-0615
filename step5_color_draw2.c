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
            Color col = ColorFromHSV(hues[i], sats[i] / 100.0f, bris[i] / 100.0f);
            DrawRectangle(cxs[i] - rs[i], cys[i] - rs[i], rs[i] * 2, rs[i] * 2, col);
        }
    
        DrawText("color.csv を書き換えると絵が変わる", 10, 10, 16, LIGHTGRAY);
    
        EndDrawing();
    }
}
    
//     while (!WindowShouldClose()) {



//         BeginDrawing();
//         ClearBackground(BLACK);

//         for (int i = 0; i < count; i++) {
//             // ColorFromHSV: 色相 0-360、彩度 0-1、明度 0-1
//             Color col = ColorFromHSV(hues[i], sats[i] / 100.0f, bris[i] / 100.0f);
//             DrawRectangle(cxs[i], cys[i], (float)rs[i], col);
//         }

//         DrawText("color.csv を書き換えると絵が変わる", 10, 10, 16, LIGHTGRAY);

//         EndDrawing();
//     }

//     CloseWindow();
//     return 0;
// }

// 【改造】color.csv に行を追加して、自分だけの絵を作ってみよう
// //  追加した行：夕焼け オレンジ,30,90,95,190,300,37
// 澄んだ 空色,200,85,85,420,350,73
// 森の緑,120,70,80,230,200,50
// 薄い桃色,350,50,98,610,300,20
// 紫の霞,280,60,75,500,650,70
// 檸檬色,60,80,90,600,450,35

// 夕焼け オレンジ,30,45,95,300,190,80
// 澄んだ 空色,200,43,85,150,200,55
// 森の緑,120,35,80,370,380,40
// 薄い桃色,350,25,98,410,280,30
// 紫の霞,280,30,75,300,120,50
// 檸檬色,60,40,90,460,330,70

// 夕焼け オレンジ,30,10,70,80,100,100
// 澄んだ 空色,200,28,50,99,221,55
// 森の緑,120,59,67,300,180,39
// 薄い桃色,350,77,50,520,410,47
// 紫の霞,280,54,49,440,390,28
// 檸檬色,60,20,35,90,60,61

// 【発展】円の代わりに DrawRectangle や DrawTriangle を使ってみよう

// while (!WindowShouldClose()) {
//     BeginDrawing();
//     ClearBackground(BLACK);

//     for (int i = 0; i < count; i++) {
//         Color col = ColorFromHSV(hues[i], sats[i] / 100.0f, bris[i] / 100.0f);
//         DrawRectangle(cxs[i] - rs[i], cys[i] - rs[i], rs[i] * 2, rs[i] * 2, col);
//     }

//     DrawText("color.csv を書き換えると絵が変わる", 10, 10, 16, LIGHTGRAY);

//     EndDrawing();
// }

