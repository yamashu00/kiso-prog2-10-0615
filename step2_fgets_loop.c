// step2: fgets ループで color.csv を全行読む
// コンパイル: gcc step2_fgets_loop.c -o step2
// 実行:       ./step2

#include <stdio.h>

int main(void) {
    FILE *fp = fopen("color.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "ファイルを開けませんでした\n");
        return 1;
    }

    char line[256];

    // fgets が NULL を返したらファイルの終わり
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }


    int count = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        count++;
    }
    printf("全部で %d 行\n", count);
 

    fclose(fp);
    fp = NULL;
    return 0;
}

// 【確認】step1 と比べて何が変わった？
/*
 * whileループを使ってfgetsを繰り返し呼び出すことで、ファイルの全行を読み込むようになった。
 * fgetsがNULLを返すまでループが続くため、ファイルの終わりまで全ての行が表示される。
 *
 * 例:
 * while (fgets(line, sizeof(line), fp) != NULL) {
 *     printf("%s", line);
 * }
 *
 */
// 【改造】行数を数えて最後に「全部で X 行」と表示してみよう
/*
 * 行数を数えるための変数を用意し、whileループ内で行が読み込まれるたびにカウントアップする。
 * ループが終わった後に、カウントした行数を表示する。
 *
 * 例:
 * int count = 0;
 * while (fgets(line, sizeof(line), fp) != NULL) {
 *     printf("%s", line);
 *     count++;
 * }
 * printf("全部で %d 行\n", count);
 *
 */
