#if !defined irrverbs_h
#define irrverbs_h
typedef struct {
    char verb[3][14];
} IrrVerb;
extern int check_answer(IrrVerb *corr,char *s1,char *s2);
#endif
