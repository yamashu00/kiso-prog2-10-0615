// step1: fgets で color.csv の 1行目を読む
// コンパイル: gcc step1_fgets_line.c -o step1
// 実行:       ./step1

#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("color.csv", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "ファイルを開けませんでした\n");
        return 1;
    }

    char line[256];
    // char b[256];
    // char c[256]; // 1行分のバッファ（256文字まで）

    fgets(line, sizeof(line), fp);
    // fgets(b, sizeof(b), fp);
    // fgets(c, sizeof(c), fp);      // 1行だけ読む
    // printf("%s%s%s", line, b, c); // そのまま表示

    printf("%s", line);

    fclose(fp);
    fp = NULL;
    return 0;
}

// 【確認】実行するとどの行が出る？ なぜ1行しか出ない？
// fgets()を一回しか実行してないから