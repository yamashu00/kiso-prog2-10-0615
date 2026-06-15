// step3: sscanf で文字列をフィールドごとに分解する
// コンパイル: gcc step3_sscanf_parse.c -o step3
// 実行:       ./step3

#include <stdio.h>

int main(void) {
    // color.csv の別の行と同じ形式の文字列
    char line[] = "澄んだ 空色,200,85,85,150,200,55";

    char  name[64];
    float hue, sat, bri;
    int   cx, cy, r;

    // %63[^,] = カンマ以外の文字を最大63文字読む（スペースも読める）
    int n = sscanf(line, "%63[^,],%f,%f,%f,%d,%d,%d",
                   name, &hue, &sat, &bri, &cx, &cy, &r);

    printf("読めた変数の数: %d\n", n);
    if (n == 7) {
        printf("名前: %s\n",       name);
        printf("色相: %.0f\n",     hue);
        printf("彩度: %.0f\n",     sat);
        printf("明度: %.0f\n",     bri);
        printf("座標: (%d, %d)\n", cx, cy);
        printf("半径: %d\n",       r);
        printf("n は sscanf が正しく読み取れた項目数です。\n");
    } else {
        fprintf(stderr, "文字列を正しく分解できませんでした\n");
        return 1;
    }

    return 0;
}

// 【確認】n は何？ なぜその数になる？
// 【改造】line の中身を変えて、別の色を試してみよう
// 答え: n は sscanf が代入できた変数の数。今回は 7 個すべて読めるので 7 になる。
