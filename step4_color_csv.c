// step4: color.csv を全行読んでテキストで表示する（完成版）
// コンパイル: gcc step4_color_csv.c -o step4
// 実行:       ./step4

#include <stdio.h>

int main(void) {
    FILE *fp = fopen("color.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "ファイルを開けませんでした\n");
        return 1;
    }

    char  line[256];
    char  name[64];
    float hue, sat, bri;
    int   cx, cy, r;

    // 1行目（ヘッダ）を読み飛ばす
    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (sscanf(line, "%63[^,],%f,%f,%f,%d,%d,%d",
                   name, &hue, &sat, &bri, &cx, &cy, &r) == 7) {
            printf("%s: HSB(%.0f, %.0f, %.0f) @ (%d,%d) r=%d\n",
                   name, hue, sat, bri, cx, cy, r);
        }
    }

    if (r >= 50) {
           printf("%s: HSB(%.0f, %.0f, %.0f) @ (%d,%d) r=%d\n",
           name, hue, sat, bri, cx, cy, r);
    }

    fclose(fp);
    fp = NULL;
    return 0;
}

// /    【確認】color.csv に1行追加したら、出力はどう変わる？
/*
 * color.csv に1行追加すると、その行の内容も出力されるようになる。
 * 例えば、color.csv に "空 青,210,100,80,200,150,50" という行を追加すると、出力に "空 青: HSB(210, 100, 80) @ (200,150) r=50" という行が追加される。
 *
 * 例:
 * 空 青: HSB(210, 100, 80) @ (200,150) r=50
 *
 */
// 【改造】半径が 50 以上の行だけ表示するようにを追加して、半径が50以上の行だけを表示するようにする。