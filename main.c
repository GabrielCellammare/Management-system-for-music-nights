#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "Funzioni.h"
#include "Evento.h"
#include "Prenotazioni.h"
#include "Utenti.h"

/** 
*****************************************************
* Copyright (C) Cellammare Gabriel & Ingusci Paolo  
*                               				   
* Serate musicali
*\n
* Traccia 4
*\n
*Cellammare Gabriel -> g.cellammare1@studenti.uniba.it
*\n
*Ingusci Paolo -> p.ingusci@studenti.uniba.it
*\n
**/

/**
*
*
*/

/**
*	La funzione main permette di navigare all'interno del software, scegliendo dal menu le operazioni da effettuare.
*
*	Quando il software viene avviato, la funzione "int main()", richiama dapprima le funzioni BenvenutoTitolo() e Copertina(), 
*   che appartengono alla libreria "Funzioni.o". Dopodichè, viene richiamato il menù appartenente ancora alla libreria "Funzioni.o", 
*   che permetterà all'utente di scegliere come navigare all'interno del software. 
*
*	@return 0
*/

int main()
{
	int controllo=0; 
	char scelta[1]; 
	char scelta_m[1];
	int temp_m=0;
	int temp; 
	FILE* apertura; 
	srand(time(NULL));

	BenvenutoTitolo();  
	Copertina(); 


	printf("\nRicerca dei file necessari in corso");
	Sleep(700);
   	printf(".");
    Sleep(700);
    printf(".");
    Sleep(700);
    printf(".\n");
    Sleep(700);


	if((apertura=fopen("File//Eventi.csv","r"))==NULL)
	{
		controllo--;
	}

	else
	{
		controllo++;
		fclose(apertura);
	}

	if((apertura=fopen("File//Utenti.csv","r"))==NULL)
	{
		controllo--;
	}

	else
	{
		controllo++;
		fclose(apertura);
	}

	if((apertura=fopen("File//Prenotazioni.csv","r"))==NULL)
	{
		controllo--;
	}

	else
	{
		controllo++;
		fclose(apertura);
	}

	if(controllo==3)
	{
		printf("\nTutti i file richiesti dal software, sono presenti all'interno della cartella.\n");
	}

	else
	{
			printf("\nTutti i file richiesti dal software non esistono, ma verranno creati correttamente in seguito.\n");
	}

	do{
		system("pause");
		system("CLS");

		do{
			BenvenutoTitolo();
			menu();  
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   			CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
   			WORD saved_attributes;

   			GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
   			saved_attributes = consoleInfo.wAttributes;

  			SetColor(3);  
			
			fflush(stdin);
			gets(scelta);

   			SetConsoleTextAttribute(hConsole, saved_attributes);

			temp=atoi(scelta);

			if(temp<1 || temp>12)
			{
				printf("\nErrore, scelta non definita correttamente.\n");
				system("pause");
				system("CLS");
			}
			
		}while(temp<1 || temp>12);

		switch(temp)
		{
			case 1:
					system("CLS");
					BenvenutoTitolo();
					RegistraUtente();
					system("pause");
					system("CLS");
					break;
			case 2:
					system("CLS");
					BenvenutoTitolo();
					modificadati();
					system("pause");
					system("CLS");
					break;
			case 3:
					system("CLS");
					BenvenutoTitolo();
					registraEvento();
					system("pause");
					system("CLS");
					break;

			case 4:
					system("CLS");
					BenvenutoTitolo();
					cercaEvento();
					system("pause");
					system("CLS");
					break;

			case 5:
					system("CLS");
					BenvenutoTitolo();
					StampaPrenotati();
					system("pause");
					system("CLS");
					break;
			case 6:
					system("CLS");
					BenvenutoTitolo();
					StampaUtentiFiltro();
					system("CLS");
					break;
			case 7:
					system("CLS");
					BenvenutoTitolo();
					venditaBiglietto();
					system("pause");
					system("CLS");
					break;
			case 8:
					system("CLS");
					BenvenutoTitolo();
					ControlloPoltrona();
					system("pause");
					system("CLS");
					break;
			case 9:
					system("CLS");
					BenvenutoTitolo();
					VisualizzaIncasso();
					system("pause");
					system("CLS");
					break;

			case 10:
					system("CLS");
					BenvenutoTitolo();
					Copertina();
					break;
					
			case 11:
					system("CLS");
					BenvenutoTitolo();
					Istogramma();
					break;	
			case 12:
					system("CLS");
					BenvenutoTitolo();
					Disegna();
					system("PAUSE");
					break;	
				
		}

		do{

			system("CLS");
			BenvenutoTitolo();
			printf("Vuoi ritornare al menu o uscire completamente dal software?");
			printf("\n1) Torna al menu");
			printf("\n2) Esci dal software");
			printf("\n\n\nFai la tua scelta: ");
			fflush(stdin);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   			CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
   			WORD saved_attributes;

   			GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
   			saved_attributes = consoleInfo.wAttributes;

  			SetColor(3);

			gets(scelta_m);

   			SetConsoleTextAttribute(hConsole, saved_attributes);

			temp_m=atoi(scelta_m);

			if(temp_m<1 || temp_m>2)
			{
				printf("\nErrore, scelta non definita correttamente.\n");
				system("pause");
				system("CLS");
			}
		}while(temp_m<1 || temp_m>2);

	}while(temp_m==1);

	system("CLS");
	BenvenutoTitolo();
	Copertina();
	printf("\n\n\nGrazie per aver utlizzato il nostro software.\n\n");
	printf("\n© Copyright Gabriel Cellammare & Paolo Ingusci\nAll rights reserved");
	return 0;
}
