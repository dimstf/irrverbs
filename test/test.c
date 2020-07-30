#include "i2.h"
#include <ctest.h>
CTEST(i2, check_answer)
{
    int i, p = 0;
    IrrVerb v;
    char a2[14] = "gave";
    char a3[14] = "given";
    char b2[14] = "gaved";
    char b3[14] = "givened";
    for (i = 0; i < 5; i++) {
        v.verb[1][i] = a2[i];
    }
    for (i = 0; i < 8; i++) {
        v.verb[2][i] = a3[i];
    }
    p = check_answer(&v, a2, a3);
    ASSERT_EQUAL(p, 1);
    p = check_answer(&v, b2, b3);
    ASSERT_EQUAL(p, 0);
}
