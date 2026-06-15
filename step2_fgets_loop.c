// step2: fgets ループで color.csv を全行読む
// コンパイル: gcc step2_fgets_loop.c -o step2
// 実行:       ./step2

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

    // fgets が NULL を返したらファイルの終わり
    int n = 0;
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%s", line);
        n++;
    }

    printf("全部で%d行\n", n);

    fclose(fp);
    fp = NULL;
    return 0;
}

// 【確認】step1 と比べて何が変わった？
// 　NULLが返されるまで繰り返しprintfしてるからcolorに入ってるのが全文表示される！
// 　step1では1行しか読まなかったが、step2ではwhile文でfgetsを繰り返しているため、ファイル全体を表示できる
// 【改造】行数を数えて最後に「全部で X 行」と表示してみよう
