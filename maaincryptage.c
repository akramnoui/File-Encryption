#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
#include "crypter.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SetColor(int ForgC)
 {
     WORD wColor;

      HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_SCREEN_BUFFER_INFO csbi;


     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {

          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
 }

int main(int argc, char *argv[]) {
	
	
	  system("cls");
    SetColor(10);
    int i;
    for ( i=0;i<25;i++)
    {

        if (i%2==0)
        {
            if(i<5 || i>19)
            {
                gotoxy(0,i);printf("1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0");
            }
            else
            {
                gotoxy(0,i);printf("1  0  1  0  1  0  1  0                                                        1  0  1  0  1  0  1  0");
            }
        }
        else
        {
            if(i<5 || i>19)
            {
                gotoxy(0,i);printf("0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1");
            }
            else
            {
                gotoxy(0,i);printf("0  1  0  1  0  1  0  1                                                        0  1  0  1  0  1  0  1");
            }
        }
        Sleep(50);
    }

	
	
	
	
	
	
	 char encFile[200];
    char newencFile[200];
    char decFile[200];
    char newdecFile[200];
    char key[10];

    int choice;

    printf("\nEntrer  <1> pour crypter ou bien <2> pour decrypter <3> pour comparer : ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        printf("entrer le nom du fichier a crypter :  ");
        scanf("%s",&encFile);
        strcat(encFile,".txt");
        printf("entrer le nom du fichier de destination :   ");
        scanf("%s",&newencFile);
        strcat(newencFile,".txt");
        printf("\nentrez votre cle :   \n" );
        scanf("%s" , &key);
        crypter(encFile, newencFile , key);
        break;
    case 2:
        printf("entrer le nom du fichier a decrypter :  ");
        scanf("%s",&decFile);
        strcat(decFile,".txt");
        printf("entrer le nom du fichier de destination :  ");
        scanf("%s",&newdecFile);
        strcat(newdecFile,".txt");
        printf("\nentrez votre cle :   \n");
        scanf("%s" , &key);
        decrypter(decFile, newdecFile , key);
        break;
    case 3 : 
    	 printf("\ncompariason des fichiers\n");
    	 printf("entrer le nom du fichier a comparer 1 :  ");
    	  scanf("%s",&encFile);
        strcat(encFile,".txt");
        printf("entrer le nom du fichier a comparer 2 :   ");
        scanf("%s",&newencFile);
        strcat(newencFile,".txt");
        printf("le resultat de la compariason donne :   %d" ,comparer(encFile, newencFile));
    	 
    }
	return 0;
}
