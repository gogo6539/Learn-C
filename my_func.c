
// ------------ file my_func.c ----------------------------

#include "my_func.h"
#include <ctype.h>


int delimiters_word[]={'"','\'',' ',',','.','?','!',':',';','/','\\','*', 
                       '<','>','(',')','{','}','[',']','\n','\t',EOF,0};


int delimiters_Sent[] = {'.', '?', '!', EOF, 0 };

int delimiters_int[] = { '"', '\'', ' ', ',', '.', '?', '!', ':', ';', '/', '\\', '*',
'<', '>', '(', ')', '{', '}', '[', ']', '\n', '\t', EOF, 0 };

int IsDelimiter(int *delimiters, int c)
{
  int i=0;
  while(delimiters[i])
  {
    if (c==delimiters[i++])
      return 1; //--- символът с е разделител ---
  }
  return 0;
}


//-----------------------------------------------------------
s_word ComputeWord(int c,      //--- текущ символ, които се анализира ---
								 char *word,   //--- символен масив за отделяне на дума
								 s_word status //--- текущ статус на автоматната функция
								)
{
  static int ind=0;
  char ch=c;

  if(status==End_Word) 
  {
    status=None;
    ind=0;
  } 
  switch (status)
  {
		case None:
	    if (!IsDelimiter(delimiters_word,ch))
			{
				status=In_Word;
				word[ind++]=c;
			}
   break;

   case In_Word:
    if( IsDelimiter(delimiters_word,ch ))
    {
      status=End_Word;
      word[ind]=0;
    }
    else
    {
			word[ind++]=c;
    }
  }
	return status;
}
//-----------------------------------------------------------

int Words(FILE *fp)
{
	int c, br_word=0;
  s_word status=None;
	char word[256];
  rewind(fp);
  do
  {
    c=fgetc(fp);
     status=ComputeWord(c, word,status);
		 if ( status==End_Word)
     {
			 br_word++;
			 printf("\n word -> %s",word);
     }
	}while(c!=EOF);
return br_word;
}
////////////////////********************

s_Sent ComputeSent(int c,      //--- текущ символ, които се анализира ---
	char *Sent,   //--- символен масив за отделяне на дума
	s_Sent status //--- текущ статус на автоматната функция
	)
{
	static int ind = 0;
	char ch = c;

	if (status == End_Sent)
	{
		status = None1;
		ind = 0;
	}
	switch (status)
	{
	case None1:
		if (!IsDelimiter(delimiters_Sent, ch))
		{
			status = In_Sent;
			Sent[ind++] = c;
		}
		break;

	case In_Sent:
		if (IsDelimiter(delimiters_Sent, ch))
		{
			status = End_Sent;
			Sent[ind++] = c;
			Sent[ind] = 0;
		}
		else
		{
			Sent[ind++] = c;
		}
	}
	return status;
}
//-----------------------------------------------------------

int Sents(FILE *fp)
{
	int c, br_sent = 0;
	s_Sent status = None1;
	char Sent[256];
	rewind(fp);
	do
	{
		c = fgetc(fp);
		status = ComputeSent(c, Sent, status);
		if (status == End_Sent)
		{
			br_sent++;
			printf("\n Sent -> %s", Sent);
		}
	} while (c != EOF);
	return br_sent;
}


//*******************************
s_int ComputeInts(int c,      //--- текущ символ, които се анализира ---
	s_int status //--- текущ статус на автоматната функция
	)
{
	static int ind = 0;
	char ch = c;

	if (status = In_End)
	{
		status = None2;
		ind = 0;
	}
	switch (status)
	{
	case None2:
		if (c == '+' || '-')
			status = In_Sign;
		else
		if (isdigit(c))
			status = In_Int;
		else
			status = None2;
		break;

	case In_Sign:
		if (isdigit(c))
			status = In_Int;
		else
			status = None2;
		break;
	case In_Int:
		if (isdigit(c))
			status = In_Int;
		else
		if (c == 'l' || c == 'L')
			status = In_Long;
		else
		if (IsDelimiter(delimiters_int, ch))
			status = In_End;
		else
			status = None2;
		break;
	case In_Long:
		if (IsDelimiter(delimiters_int, ch))
			status = In_End;
		else
			status = None2;
		break;
	}
	return status;
}
//-----------------------------------------------------------

int Ints(FILE *fp)
{
	int c, br_Int = 0;
	s_int status = None2;
	rewind(fp);
	do
	{
		c = fgetc(fp);
		status = ComputeInt(c, status);
		if (status == In_End)
		{
			br_Int++;
		}
	} while (c != EOF);
	return br_Int;
}