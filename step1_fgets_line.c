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

// 実行すると、color.csv の 1行目だけが出る。
// 理由は、fgets(line, sizeof(line), fp); を1回しか呼んでいないから。
// fgets は1回呼ぶと、ファイルから1行だけ読み込む。
// そのため、2行目以降は読み込まれず、表示されない。