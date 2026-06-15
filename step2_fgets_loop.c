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

    printf("全部で %d 行\n", count);

    fclose(fp);
    fp = NULL;
    return 0;
}

// 【確認】step1 と比べて何が変わった？

// step1 では fgets を1回だけ呼んでいたので、color.csv の1行目だけが表示された。
// step2 では while 文で fgets を繰り返し呼んでいるので、color.csv の全行が表示される。
// fgets が NULL を返すとファイルの終わりなので、そこでループが止まる。