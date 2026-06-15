#include <stdio.h>

int main(void) {
    FILE *fp = fopen("color.csv", "r");

    if (fp == NULL) {
        fprintf(stderr, "color.csv を開けません\n");
        return 1;
    }

    char line[256];
    fgets(line, sizeof(line), fp);
    printf("%s", line);

    fclose(fp);
    fp = NULL;

    FILE *fp2 = fopen("log.txt", "w");
    if (fp2 == NULL) {
        fprintf(stderr, "log.txt を開けません\n");
        return 1;
    }

    fprintf(fp2, "ログ: %s", line);
    fclose(fp2);

    FILE *fp3 = fopen("no_such_dir/out.csv", "w");

    if (fp3 == NULL) {
        fprintf(stderr, "no_such_dir/out.csv を開けません\n");
        return 1;
    }

    fprintf(fp3, "data\n");
    fclose(fp3);

    return 0;
}

/*
 * ① fopen 直後に NULLチェックがない
 *    fp が NULL のまま fgets を呼ぶとクラッシュする可能性がある。
 *    修正: if (fp == NULL) { fprintf(stderr, "開けません\n"); return 1; }
 *
 * ② fclose を呼ばずに fp = NULL している
 *    ファイルを閉じないままポインタだけ消している。
 *    修正: fclose(fp); の後に fp = NULL;
 *
 * ③ fp3 の NULLチェックがない
 *    存在しないディレクトリへの書き込みでは fopen が失敗する可能性がある。
 *    fp3 が NULL のまま fprintf や fclose を呼ぶと危険。
 *    修正: if (fp3 == NULL) { fprintf(stderr, "開けません\n"); return 1; }
 */