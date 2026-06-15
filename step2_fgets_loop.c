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

    fclose(fp);
    fp = NULL;
    return 0;
}

// 【確認】step1 と比べて何が変わった？
// 【答え】step1では fgets() を1回しか実行していなかったので1行しか読めなかった。
// 【改造】行数を数えて最後に「全部で X 行」と表示してみよう
// 【答え】step2では while 文を使って fgets() を繰り返し実行しているため、ファイルの最後まで全ての行を読むことができる。