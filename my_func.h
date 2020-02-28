
#include <stdio.h>

typedef enum sta_word{None, In_Word, End_Word} s_word;
s_word ComputeWord(int c, char *word, s_word status);
int Words(FILE *fp);

typedef enum sta_Sent{ None1, In_Sent, End_Sent } s_Sent;
s_Sent ComputeSent(int c, char *Sent, s_Sent status);
int Sents(FILE *fp);