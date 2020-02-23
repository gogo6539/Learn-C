#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include "my_func.h"
//---------------------------------------------------------------------------

FILE *getNameFile(char *name_file, char *mode, char *text)
{
	FILE *fp;
	int err;
 
	do
	{
		printf("\nВъведете име на файла %s:",text);
		err= scanf("%s", name_file);
	}while(err!=1);

	if ((fp=fopen(name_file,mode))==NULL)
	{
		printf("\nФайлът <%s> Не може да се отвори - error No % d !!!\n",name_file,errno);
		printf("ГРЕШКА No %d %s",errno,strerror( errno ));
		system("pause");
	}
	else
	{
		printf("\nФайлът <%s> е отворен успешно за обработка !\n\n", name_file);
		system("pause");
	}
	return fp;
}
//---------------------------------------------------------------------------------------------
void printTextFile()
{
	FILE *fp=NULL;
	char name_file[256],ch;
	if((fp=getNameFile(name_file, "rt", "за четене"))!=NULL)
	{
		while(1)
		{
			ch=fgetc(fp);
			if(ch==EOF)
				break;
			fputc(ch,stdout);
		}
	}
	system("pause");
	fclose(fp);
}
//---------------------------------------------------------------------------------------------

short countSymbols(FILE *fp_in,FILE *fp_out)
{
	short ascii_table[256]={0},ascii_count=0,m=0,i=0;
	rewind(fp_in);
	while ((ascii_count = fgetc(fp_in)) != EOF)
		ascii_table[ascii_count]++;

	for (i = 0; i < 256; i++)
	if (ascii_table[i]>0)
		fprintf(fp_out, "\n %c \t\t %d \t\t 0x%x \t\t %d", i, i, i, ascii_table[i]);

	if (ferror(fp_in))
	{
		printf("Error!");
		return 1;
	}
	
	return 0;  
}
//------------------------------------------------------------------------

short countChosenSymbol(FILE *fp_in,char *ch)
{
	short count=0;
	char c=0;
	rewind(fp_in);
	printf("Въведете символ за преброяване:");
	while ((c = fgetc(fp_in)) != EOF)
	{
		if (c == ch)
			count++;
	}
	printf("%d", count);
	
	return count;  
}
//------------------------------------------------------------------------
void changeSymbol(FILE *fp_in,FILE *fp_out)
{
	char ch1,ch2,c=0;
	rewind(fp_in);
	printf("Въведете символ за замяна:");

	ch1=getchar();
	fflush(stdin);
	printf("Въведете заместващ символ:");
	ch2=getchar();
	fflush(stdin);
	
}
//------------------------------------------------------------------------------
int maxMinNumbers(FILE *fp_in,int *min)
{
	int i=0,max=0,num=0;
	rewind(fp_in);
	
	return max;
}
//-------------------------------------------------------------------------------
void	writeNumbersOfInterval(FILE *fp_in,FILE *fp_out)
{
	int a,b,n,num=0,i=0;
	rewind(fp_in);

	printf("Въведете долна граница=");
	scanf("%d",&a);
	do
	{
		printf("Въведете горна граница=");
		scanf("%d",&b);
	}while(a>=b);

	printf("Въведете брой колони=");
	scanf("%d",&n);

	
}
//-------------------------------------------------------------------------------------------------------
int averageOfNumbers(FILE *fp_in, int *n)
{
	char str[20];
	int S = 0, num = 0, overflow=0;
	while (fscanf(fp_in, "%s", str) != EOF)
	{
		num = atoi(str);
		if (errno == 34)
		{
			perror("Препълване при четене");
			system("pause");
			exit(1);
		}
		S = Sum(S, num, &overflow);
		if (overflow == 1)
		{
			perror("Препълване при събиране");
			system("pause");
			exit(1);
		}
		(*n)++;
	}
	if (ferror(fp_in))
	{
		perror("Грешка във файла");
		system("pause");
		exit(1);
	}
	return S;
}
//--------------------------------------------------------
void changeNegativeNumbers(FILE *fp_in,FILE *fp_out)
{
	int num=0;
	char ch=0;
	rewind(fp_in);

}
//---------------------------------------------------------
int Sum(int x, int y, int *overflow)
{
	int S = 0, noOverflow=1;
	S = x + y;
	_asm
	{
		jno NO
			mov noOverflow,0
			NO:
	}
	if (noOverflow == 0)
		*overflow = 1;
	else
		*overflow = 0;
	return S;
}
//***************************************************
















