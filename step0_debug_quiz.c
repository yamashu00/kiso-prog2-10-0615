#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("color.csv", "r");

    if (fp == NULL)
    {
        fprintf(stderr, "color.csv を開けません\n");
        return 1;
    }

    char line[256];
    fgets(line, sizeof(line), fp);
    printf("%s", line);

    fclose(fp);
    fp = NULL;

    FILE *fp2 = fopen("log.txt", "w");

    if (fp2 == NULL)
    {
        fprintf(stderr, "log.txt を開けません\n");
        return 1;
    }

    fprintf(fp2, "ログ: %s", line);
    fclose(fp2);

    FILE *fp3 = fopen("no_such_dir/out.csv", "w");

    if (fp3 == NULL)
    {
        fprintf(stderr, "out.csv を開けません\n");
        return 1;
    }

    fprintf(fp3, "data\n");
    fclose(fp3);

    return 0;
}