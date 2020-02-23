#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include "menu.h"
#include "my_func.h"

//------------- ìåíþòà ------------------------------------
char *txt_menu_g[]=
{
	  "-----ÏÐÎÃÐÀÌÀ ÒÅÊÑÒÎÂ ÔÀÉË-----",
		"Èçáîð íà âõîäåí ôàéë çà îáðàáîòêà.....................",
		"Ïîêàçâàíå ñúäúðæàíèåòî íà òåêñòîâ ôàéë................",
		"Ïðåáðîÿâàíå è çàïèñ íà ñèìâîëè........................",
		"Áðîé íà ñðåùàíå íà èçáðàí ñèìâîë......................",
		"Çàìÿíà íà ñèìâîë ñ äðóã ñèìâîë è çàïèñà ìó â íîâ ôàéë.",
		"Îáðàáîòêà íà ÷èñëîâà èíôîðìàöèÿ îò òåêñòîâè ôàéë......",
		"Èçõîä...........................................",
		NULL
};
//----------------------------------------------------------
char *txt_menu_numbers[]=
{
		"-----ÏÐÅÁÐÎßÂÀÍÅ È ÇÀÏÈÑ-----",
		"Íàìèðàíå íà ìèí. è ìàêñ. ÷èñëà âúâ ôàéëà ...............................................",
		"Çàïèñ íà ÷èñëàòà â çàäàäåí èíòåðâàë â íîâ ôàéë â ïðåäâàðèòåëíî èçáðàí áðîé êîëîíè íà ðåä",
		"Èç÷èñëÿâàíå íà ñð.àð. îò ÷èñëàòà âúâ âõîäíèÿ ôàéë, êàòî ñå ñëåäè çà ïðåïúëâàíå..........",
		"Çàìÿíà íà îòð. ÷èñëà âúâ ôàéëà ñ íóëè è çàïèñ â íîâ ôàéë................................",
		"Èçõîä...................................................................................",
		NULL
};
//-----------------------------------------------------------

int main()
{
	short mode,mode1=0,mode2,flag1=0,flag2=0,count1;		
	FILE *fp_in=NULL, *fp_out=NULL;
	char name_in[256],name_out[256],ch;
	int *ptr=NULL,n=0,max,min, S=0;
//------------------------------------------------------
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	do
	{
		system("cls");
		mode=menu(txt_menu_g);
		switch (mode)
		{
//-------------------------------------------------------------------------------------------------
			case 1:
					system("cls");
					if((fp_in=getNameFile(name_in, "rt", "çà ÷åòåíå"))!=NULL)
						flag1=1;
					break;  
//----------------------------------------------------------------------------------------------
			case 2:	printTextFile();break;
			case 3:
					if(flag1==0)
					{
						printf("\nÍå ñòå îòâîðèëè ôàéë çà îáðàáîòêà!");system("pause");
						break;
					}
														
						system("cls");
																
								if((fp_out=getNameFile(name_out, "wt", "çà çàïèñ"))!=NULL)
									countSymbols(fp_in,fp_out);system("pause");
							
								fclose(fp_out);
				break;
			case 4:if(flag1==0)
						{
							printf("\nÍå ñòå îòâîðèëè ôàéë çà îáðàáîòêà!");system("pause");
							break;
						}
						count1=countChosenSymbol(fp_in,&ch);
						
						printf("Áðîé íà ñðåùàíå íà ñèìâîë \'%c\' âúâ âõîäíèÿ ôàéë å =%d",ch,count1);system("pause");
						break;
			case 5:if(flag1==0)
						{
							printf("\nÍå ñòå îòâîðèëè ôàéë çà îáðàáîòêà!");system("pause");
							break;
						}
						if((fp_out=getNameFile(name_out, "wt", "çà çàïèñ"))!=NULL)
								changeSymbol(fp_in,fp_out);
						
							fclose(fp_out);
						break;
			case 6:if(flag1==0)
						{
							printf("\nÍå ñòå îòâîðèëè ôàéë çà îáðàáîòêà!");system("pause");
							break;
						}
						do									
						{										
							system("cls");
							mode2=menu(txt_menu_numbers);
							switch(mode2)
							{
								case 1: max=maxMinNumbers(fp_in,&min);
												printf("max=%d,min=%d",max,min);system("pause");break;
								case 2:if((fp_out=getNameFile(name_out, "wt", "çà çàïèñ"))!=NULL)
											writeNumbersOfInterval(fp_in,fp_out);system("pause");
											
												fclose(fp_out);
											break;
								case 3:S= averageOfNumbers(fp_in, &n);
									if (n == 0)
									{
										printf("Íÿìà ÷èñëà âúâ ôàéëà");
										system("pause");
										exit(1);
									}
												printf("Ñðåäíî àðèòìåòè÷íîòî å =%f",S/n);system("pause");
												break;
								case 4:if((fp_out=getNameFile(name_out, "wt", "çà çàïèñ"))!=NULL)
												changeNegativeNumbers(fp_in,fp_out);system("pause");
											
												fclose(fp_out);
											break;
							}
						}while(mode2!=5);
						break;
		}			
	}while (mode != 7);
	_fcloseall();	
}


