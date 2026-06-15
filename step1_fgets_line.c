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
/*
 * fgets はファイルから1行ずつ読み込む関数で1回呼ぶと、次の改行までの文字列を line に格納する。
 * そのため、1回だけ呼ぶと最初の行しか読まない。
 *全ての行を読みたい場合は、whileループで fgets を繰り返す必要がある。
 *
 * 例:
 * while (fgets(line, sizeof(line), fp) != NULL) {
 *     printf("%s", line);
 * }
 *
 */

