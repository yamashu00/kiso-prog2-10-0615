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

    int i = 0;

    // fgets が NULL を返したらファイルの終わり
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        i++;
    }

    fclose(fp);
    fp = NULL;
    printf("全部で %d 行\n", i);
    return 0;
}

// 【確認】step1 と比べて何が変わった？
// 【改造】行数を数えて最後に「全部で X 行」と表示してみよう
// step1 では fgets を1回だけ呼んでいたが、step2 では while ループで何度も呼んでいる
// fgets が NULL を返すまでループすることで、ファイルの全行を読むことができる
