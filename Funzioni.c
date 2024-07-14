#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include "Funzioni.h"
#include "Evento.h"
#include "Prenotazioni.h"
#include "Utenti.h"

/**
*	La procedura menu permette di visualizzare tutte le voci del software.
*
*	@return void
*/

void menu()
{
   int n=1;
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
   WORD saved_attributes;
    
   GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
   saved_attributes = consoleInfo.wAttributes;
	
   SetColor(3);

   printf("Benvenuto nel menu di scelta\n\n");
   
   SetConsoleTextAttribute(hConsole, saved_attributes);
   
   Colora_Menu(n);
   printf("  Registra un nuovo utente\n");
   n++;
   Colora_Menu(n);
   printf("  Modifica i dati dell'utente\n");
   n++;
   Colora_Menu(n);
   printf("  Registra un nuovo evento\n");
   n++;
   Colora_Menu(n);
   printf("  Cerca un evento e modificalo o eliminalo\n");
   n++;
   Colora_Menu(n);
   printf("  Stampa la lista dei prenotati ad un certo evento\n");
   n++;
   Colora_Menu(n);
   printf("  Stampa la lista degli eventi a cui ha partecipato un utente\n");
   n++;
   Colora_Menu(n);
   printf("  Vendi un biglietto ad un utente\n");
   n++;
   Colora_Menu(n);
   printf("  Verifica se la poltrona di un evento e' libera o occupata\n");
   n++;
   Colora_Menu(n);
   printf("  Stampa l'incasso complessivo di un evento\n");
   n++;
   Colora_Menu(n);
   printf(" Riconoscimenti del software e contatti");
    
   GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
   saved_attributes = consoleInfo.wAttributes;
	
   SetColor(4);
	
   printf("\n\n\t\t\tFunzionalita' aggiuntiva\n\n");
	
   SetConsoleTextAttribute(hConsole, saved_attributes);
   
   n++;
   Colora_Menu(n);
   printf(" Crea un istogramma degli eventi\n");
   n++;
   Colora_Menu(n);
   printf("Disegna ");
   printf("\n\nInserisci la tua scelta: ");
}

/**
*	La procedura SetColor permette di manipolare il colore dell'output sul prompt dei comandi.
*
*	@param[in] color: variabile che determinera' il colore.
*
*	@return  void
*/
void SetColor(unsigned short color) //colora l'output sul prompt
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,color);
}

/**
*	La procedura BenvenutoTitolo stampa il titolo del software.
*
*
*	@return void
*/
void BenvenutoTitolo()
{
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
	
	SetColor(1);

	printf("\t\t\tBenvenuto nel programma di gestione delle serate musicali!\n");
	
	SetConsoleTextAttribute(hConsole, saved_attributes); //Il prompt ritorna con i colori salvati precedentemente.
	
	printf("\n");
}

/**
*	La procedura Copertina stampa tutti i riconoscimenti del software.
*
*
*	@return void
*/
void Copertina()
{
	printf("\nSoftware progettato e codificato da: \n");
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
	
	SetColor(3);
	
	
	printf("\n\nCellammare Gabriel (g.cellammare1@studenti.uniba.it) ---> +393927504972\n");
	printf("Ingusci Paolo (p.ingusci@studenti.uniba.it) ---> +393884935616\n\n\n");
    
    SetConsoleTextAttribute(hConsole, saved_attributes);
    
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
	
	SetColor(9);
	
	printf("\nUniversita' degli studi di Bari 'Aldo Moro' AA 2020/2021 \n\n");
	
	SetConsoleTextAttribute(hConsole, saved_attributes); //Il prompt ritorna con i colori salvati precedentemente.
	
	printf("\n\t\t       ");
	
	system("Pause");
	
	printf("\n");
	
}

/**
*	La procedura Colora_menu permette di colorare ogni volta il numero corrispondente all'interno del menu.
*
*	@param[in] numero: il numero che ogni volta verra' colorato.
*
*	@return void
*/

void Colora_Menu(int numero) //https://stackoverflow.com/questions/9203362/c-color-text-in-terminal-applications-in-windows
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes; 
	
	SetColor(9);

	printf("%d)",numero);
	
	SetConsoleTextAttribute(hConsole, saved_attributes); //Il prompt ritorna con i colori salvati precedentemente.
}

void Disegna()
{
	int matrice[40][100];
	int i,j;
	double x,y;
	
	for(i=0;i<40;i++)
	{
		x=(2*3.14/40)*i;
		y=(sin(x)+1)*50;
		
		for(j=0;j<100;j++)
		{
			if(j<y)
			{
				printf("* ");
			}
			
			else
			
			{
				printf(" ");
			}
			
		}
		
		printf("\n");
	}
}
