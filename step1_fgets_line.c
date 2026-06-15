// step1: fgets で color.csv の 1行目を読む
// コンパイル: gcc step1_fgets_line.c -o step1
// 実行:       ./step1

#include <stdio.h>

int main(void) {
    FILE *fp = fopen("color.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "ファイルを開けませんでした\n");
        return 1;
    }

    char line[256];   // 1行分のバッファ（256文字まで）

    fgets(line, sizeof(line), fp);   // 1行だけ読む
    printf("%s", line);              // そのまま表示

    fclose(fp);
    fp = NULL;
    return 0;
}


// 【確認】実行するとどの行が出る？ なぜ1行しか出ない？
// color.csv の1行目(名前,色相,彩度,明度,X,Y,半径)
// fgets は ファイルやキーボードから1回で1行だけ読み込む関数だから

/*
流れ
① ファイルを開く
FILE *fp = fopen("color.csv", "r");
color.csv を読み込みモード(r)で開く。

② 開けたか確認する
if (fp == NULL) {
    fprintf(stderr, "ファイルを開けませんでした\n");
    return 1;
}
ファイルが見つからなかったら終了。

③ 文字を入れる箱を作る
char line[256];
256文字まで入る文字列用の箱。

④ 1行読む
fgets(line, sizeof(line), fp);
color.csv の先頭1行を line に入れる。

⑤ 表示する
printf("%s", line);
line の中身を表示。

⑥ ファイルを閉じる
fclose(fp);
開いたファイルを閉じる。
*/