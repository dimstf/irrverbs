#include "i2.h"
void start()
{
    printf("\nThis program is for checking the");
    printf("knowledge of irregular verbs\n");
}
void irrverbs(IrrVerb* correct)
{
    FILE* a;
    a = fopen("dictionary/IV.txt", "r");
    if (a == NULL) {
        printf("\nCannot open file IV.txt\n");
        exit(0);
    }
    int score = 0, point, mas[200] = { 0 }, i, k, n = 40;
    for (i = 0; i < n; i++) {
        point = 0;
        char str1[16], str2[16];
        k = rand_verb(mas);
        read_verb(correct, a, k);
        printf("%s ", correct->verb[0]);
        scanf("%s%s", str1, str2);
        str1[15] = '\0';
        str2[15] = '\0';
        for (i = 0; i < strlen(str1); i++) {
            str1[i] = tolower(str1[i]);
        }
        for (i = 0; i < strlen(str2); i++) {
            str2[i] = tolower(str2[i]);
        }
        point = check_answer(correct, str1, str2);
        score = score + point;
        if (point == 0) {
            printf("\n%s %s ", correct->verb[0], correct->verb[1]);
            printf("%s\n\n", correct->verb[2]);
        } else {
            printf("\n+\n\n");
        }
        printf("****************************************(%d)\n\n", i + 1);
    }
    float result;
    result = (score / 40.0) * 100.0;
    printf("Percentage of correct answers %3.2f\n", result);
}
