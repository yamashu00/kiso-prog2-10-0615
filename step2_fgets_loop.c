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
    int count = 0;

    // fgets が NULL を返したらファイルの終わり
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        count++;
    }

    printF("全部で%d行\n", count);

    fclose(fp);
    fp = NULL;
    return 0;
}

// 【確認】step1 と比べて何が変わった？
// 1行読む→表示するをファイルの終端まで繰り返し、ファイルの全文が表示されるようになった。

// 【改造】行数を数えて最後に「全部で X 行」と表示してみよう
// int count = 0;とcount++;（ループ文内）、printF("全部で%d行\n", count);を追加した。