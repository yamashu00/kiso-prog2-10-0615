// step3: sscanf で文字列をフィールドごとに分解する
// コンパイル: gcc step3_sscanf_parse.c -o step3
// 実行:       ./step3

#include <stdio.h>

int main(void) {
    // color.csv の2行目と同じ形式の文字列
    char line[] = "空 青,210,100,80,200,150,50";

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
/*
 * nはsscanfが読み取れた変数の数で、この場合は7になる。
 * フォーマット文字列に7つの変数（name, hue, sat, bri, cx, cy, r）が指定されているため、全てが正しく読み取れれば7が返される。
 *
 * 例:
 * int n = sscanf(line, "%63[^,],%f,%f,%f,%d,%d,%d",
 *                name, &hue, &sat, &bri, &cx, &cy, &r);
 *
 */
// 【改造】line の中身を変えて、別の色を試してみよう
/*
 * char line[] = "空 青,210,100,80,200,150,50";
 *
 */
