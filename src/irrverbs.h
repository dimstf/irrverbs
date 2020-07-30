#if !defined irrverbs_h
#define irrverbs_h
typedef struct {
    char verb[3][14];
} IrrVerb;
extern void start();
extern void irrverbs(IrrVerb *correct);
#endif

