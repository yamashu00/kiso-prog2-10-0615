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
//
// step1では fgets を1回しか実行していなかったので、
// color.csv の1行目しか表示されなかった。
//
// step2では while文を使って fgets を繰り返し実行しているため、
// ファイルの終わりまで全ての行を表示できる。

// 【改造】行数を数えて最後に「全部で X 行」と表示してみよう
#include <stdio.h>

int main(void) {
    FILE *fp = fopen("color.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "ファイルを開けませんでした\n");
        return 1;
    }

    char line[256];
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
