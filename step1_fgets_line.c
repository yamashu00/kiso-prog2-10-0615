// step1: fgets で color.csv の 1行目を読む
// コンパイル: gcc step1_fgets_line.c -o step1
// 実行:       ./step1

#include <stdio.h>

int main(void) {
    FILE *fp = fopen("color.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "ファイルを開けませんでした\n");
        return 1;
    }

    char line[256];   // 1行分のバッファ（256文字まで）

    fgets(line, sizeof(line), fp);   // 1行だけ読む
    printf("%s", line);              // そのまま表示

    fclose(fp);
    fp = NULL;
    return 0;
}

// 【確認】実行するとどの行が出る？ なぜ1行しか出ない？

//繰り返し処理で複数回ファイルの読み書きをせずに、一行分のchar * 256のみを読み取るようにしているから。
//名前,色相,彩度,明度,X,Y,半径