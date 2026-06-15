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

    if (fgets(line, sizeof(line), fp) == NULL) {
        fprintf(stderr, "1行目を読み取れませんでした\n");
        fclose(fp);
        fp = NULL;
        return 1;
    }

    printf("%s", line);              // そのまま表示
    printf("この行は color.csv の1行目です。\n");
    printf("1回しか fgets を呼んでいないので、1行しか出力されません。\n");

    fclose(fp);
    fp = NULL;
    return 0;
}

// 【確認】実行するとどの行が出る？ なぜ1行しか出ない？
// 答え: 1行目のヘッダ「名前,色相,彩度,明度,X,Y,半径」が出る。
//       fgets を1回しか呼ばないので、読み込まれるのは1行だけ。
