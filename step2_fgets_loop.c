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
    int line_count = 0;

    // fgets が NULL を返したらファイルの終わり
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        line_count++;
    }

    printf("全部で %d 行\n", line_count);

    fclose(fp);
    fp = NULL;
    return 0;
}

// 【確認】step1 と比べて何が変わった？
// 【改造】行数を数えて最後に「全部で X 行」と表示してみよう
// 答え: step1 は1回だけ読むが、step2 は fgets をループで呼び続けるので全行を表示できる。
