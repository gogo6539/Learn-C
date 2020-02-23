
#include <stdio.h>
short countSymbols(FILE *fp_in,FILE *fp_out);
FILE *getNameFile(char *name_file, char *mode, char *text);
void printTextFile();
short countChosenSymbol(FILE *fp_in,char *ch);
void changeSymbol(FILE *fp_in,FILE *fp_out);
int maxMinNumbers(FILE *fp_in,int *min);
void	writeNumbersOfInterval(FILE *fp_in,FILE *fp_out);
int averageOfNumbers(FILE *fp_in, int *n);
void changeNegativeNumbers(FILE *fp_in,FILE *fp_out);
int Sum(int x, int y, int *overflow);
