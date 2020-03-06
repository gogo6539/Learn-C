#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "menu.h"
#include "my_func.h"

//------------- менюта -----------------------
char *txt_menu_g[]=
{
	  "Програма текстов файл:",
		"Избор на входен файл:",
		"Преброяване на думите",
		"Преброяване на изреченията",
		"Преброяване на целите константи",
		"Преброяване на реалните константи от тип float",
		"Изход",
		NULL
};

void empty_function (int mode)
{
  printf("\n\n Empy Function !!! -  actual mode %d\n\n   Press any key to continue !!!\n\n",mode);
  _getch();  
}
//--------------------------------------------

int main()
{
	int mode;
	FILE *fp_in=NULL, *fp_out=NULL;
	char name_file[256];
  //------------------------------------------------------
	unsigned long br_words=0, br_sents=0, br_ints=0;
//------------------------------------------------------------------------
	SetConsoleOutputCP(1251);
	do
	{
	  mode=menu(txt_menu_g);
    switch (mode)
		{
	    case 1:
        printf("\ntype name file:");
        scanf("%s",name_file);
				if ( (fp_in=fopen(name_file,"rt")) == NULL ) //--- 
				   printf ("\nERROR: no open file !!!\n");
				else
				   printf ("\nOK - file %s open !\n", name_file);
			break;

      case 2:
				// -- да се добави задължителна проверка за достъп до входния файл ....
				br_words=Words(fp_in);
        if (br_words)
					printf("\n\n compute %d words in to file %s", br_words, name_file); 
			break;

	    case 3:
			br_sents = Sents(fp_in);
			if (br_sents)
				printf("\n\n compute %d Sents in to file %s", br_sents, name_file);

			break;

	    case 4:
			br_ints = Ints(fp_in);
			if (br_ints)
				printf("\n\n compute %d constants in to file %s", br_ints, name_file);

			break;

    }
	}while (mode != 6);
}
//--- end program --- 

