// step3: sscanf で文字列をフィールドごとに分解する
// コンパイル: gcc step3_sscanf_parse.c -o step3
// 実行:       ./step3

#include <stdio.h>

int main(void) {
    // color.csv の2行目と同じ形式の文字列
    char line[] = "青空 ブルー,210,70,90,500,200,100";

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
//  →sscanf が正常に読み取れた変数の数
// 【改造】line の中身を変えて、別の色を試してみよう

/*
scanf → キーボードから入力を読む
sscanf → 文字列からデータを読む　　CSVを読むときによく使う🙌
*/
