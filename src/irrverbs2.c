#include "i3.h"
int check_answer(IrrVerb* corr, char* s1, char* s2)
{
    int i, p = 1, l1 = strlen(s1), l2 = strlen(s1);
    int l3 = strlen(corr->verb[1]), l4 = strlen(corr->verb[2]);

    for (i = 0; i < l1; i++) {
        if (corr->verb[1][i] != s1[i]) {
            p = 0;
        }
        if (p == 0) {
            break;
        }
    }
    for (i = 0; i < l2; i++) {
        if (corr->verb[2][i] != s2[i]) {
            p = 0;
        }
        if (p == 0) {
            break;
        }
    }
    if ((l1 != l3) && (l2 != l4)) {
        p = 0;
    }
    return p;
}
int rand_verb(int* arr)
{
    srand(time(NULL));
    int value = 0;
    while (value == 0) {
        value = (rand()) % 200 + 1;
        if (arr[value] != 0) {
            value = 0;
        } else {
            arr[value]++;
        }
    }
    return value;
}
void read_verb(IrrVerb* ans, FILE* f, int line)
{
    char d;
    int l, string = 0;
    d = fgetc(f);
    while ((string <= line - 2) && (line > 2)) {
        d = fgetc(f);
        if (d == '\n') {
            string++;
        }
    }
    if (line == 1) {
        fseek(f, 0, SEEK_SET);
    }
    if (line == 2) {
        fseek(f, 20, SEEK_SET);
    }
    for (l = 0; l < 3; l++) {
        fscanf(f, "%s", ans->verb[l]);
    }
    fseek(f, 0, SEEK_SET);
}
