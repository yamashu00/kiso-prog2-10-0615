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
    int count = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        count++;
    }
    printf("全部で%d行",count);

    fclose(fp);
    fp = NULL;
    return 0;
}

// 【確認】step1 と比べて何が変わった？
//1行だけじゃなくて最後まで出力してくれるようになった
// 【改造】行数を数えて最後に「全部で X 行」と表示してみよう
