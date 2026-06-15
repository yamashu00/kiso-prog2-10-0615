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

    printf("全部で%d行",);

    fclose(fp);
    fp = NULL;
    return 0;
}

// 【確認】step1 と比べて何が変わった？
/*名前,色相,彩度,明度,X,Y,半径
夕焼け オレンジ,30,90,95,400,300,80
澄んだ 空色,200,85,85,150,200,55
森の緑,120,70,80,600,350,40
薄い桃色,350,50,98,500,150,30
紫の霞,280,60,75,300,450,50
ってでた。圧倒的文章量が多い。*/
// 【改造】行数を数えて最後に「全部で X 行」と表示してみよう
