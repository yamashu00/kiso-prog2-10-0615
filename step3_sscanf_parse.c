// step3: sscanf で文字列をフィールドごとに分解する
// コンパイル: gcc step3_sscanf_parse.c -o step3
// 実行:       ./step3

#include <stdio.h>

int main(void) {
    // color.csv の2行目と同じ形式の文字列
    char line[] = "青空 ブルー,210,80,90,200,250,60";

    char  name[64];
    float hue, sat, bri;
    int   cx, cy, r;

    // %63[^,] = カンマ以外の文字を最大63文字読む（スペースも読める）
    int n = sscanf(line, "%63[^,],%f,%f,%f,%d,%d,%d",
                   name, &hue, &sat, &bri, &cx, &cy, &r);

    printf("読めた変数の数: %d\n", n);
    printf("名前: %s\n",       name);
    printf("色相: %.0f\n",     hue);
    printf("彩度: %.0f\n",     sat);
    printf("明度: %.0f\n",     bri);
    printf("座標: (%d, %d)\n", cx, cy);
    printf("半径: %d\n",       r);

    return 0;
}

// 【確認】n は何？ なぜその数になる？

// n は 7 になる。
// 理由は、sscanf で7個の値を読み取れているから。
// 読み取っている値は、
// name, hue, sat, bri, cx, cy, r の7つ。

// %63[^,] で「夕焼け オレンジ」を読む。
// そのあと、%f, %f, %f で 30, 90, 95 を読む。
// 最後に、%d, %d, %d で 400, 300, 80 を読む。
// だから全部で7個読み取れて、n は 7 になる。