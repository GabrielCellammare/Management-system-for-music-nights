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
*	La procedura RegistraUtente permette di registrare un nuovo utente all'interno del file "Utenti.csv".
*	Il nickname dell'utente non deve necessariamente essere preregistrato.
*
*	username.nickname: Nickname inserito dall'utente.\n
*	username.email: Email inserita dall'utente.\n
*	username.cognome: Cognome inserito dall'utente.\n
*   username.nome: Nome inserito dall'utente.\n
*   username.genere: Sesso nserito dall'utente.\n
*   username.datan: Data di nascita inserito dall'utente.\n
*	username.ntelefono: Numero di telefono inserito dall'utente.\n
*	username.gmusicale: Gusto musicale inserito dall'utente.\n
*
*	@return 0
*/
void RegistraUtente()
{
	struct utente username={"","","","","","","",""};
	
	struct utente leggi={"","","","","","","",""};
	
	FILE* apertura;
	FILE* scrittura;
	char riga[100];
	char scelta[2];
	int numero;
	int controllo=0;
	char ntelefono[10];
	int i;
	int controllo_n=0;
	char nick[50];
	
	do{
		controllo_n=0;
		fflush(stdin);	
		printf("Inserisci il nickname ");
	
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    	WORD saved_attributes;
    	
    	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
   		saved_attributes = consoleInfo.wAttributes;
	
		SetColor(1);

		printf("(ATTENZIONE! NON SARA' POSSIBILE CAMBIARE IN FUTURO QUESTO CAMPO):  ");
	
		SetConsoleTextAttribute(hConsole, saved_attributes); //Il prompt ritorna con i colori salvati precedentemente.
		gets(nick); //controlla il nickname (controlla lo spazio).
		
		for(i=0;i<strlen(nick);i++)
		{
			if(nick[i]==' ')
			{
				controllo_n=1;
			}
		}
		
		if(controllo_n==1)
		{
			printf("\nErrore, inserimento di spazi non previsto all'interno del nickname.\n");
			system("PAUSE");
			system("CLS");
			BenvenutoTitolo();
		}
		
		else
		
		{
			strcpy(username.nickname,nick);
		}
		
	}while(controllo_n==1);
	
	printf("\nRicerca in corso");
	Sleep(700);
    printf(".");
    Sleep(700);
    printf(".");
    Sleep(700);
    printf(".\n");
    Sleep(700);
	
	controllo=ricercaN(username.nickname);


	
    if(controllo==1)
  	{
        	printf("\nErrore, nickname gia' esistente.\n");
	}
	
	else
	
	{
		printf("\n");
		
		printf("Il nickname e' disponibile.\n\n\n");

		printf("Inserisci l'email dell'utente:  ");
		gets(username.email);

		printf("\n");
		
		do{
			controllo_n=0;
			fflush(stdin);	
			printf("Inserisci il cognome dell'utente: ");
	
	
			gets(nick); //controlla il nickname (controlla lo spazio).
		
			for(i=0;i<strlen(nick);i++)
			{
				if(nick[i]==' ')
				{
					controllo_n=1;
				}
			}
		
			if(controllo_n==1)
			{
				printf("\nErrore, inserimento di spazi non consentito all'interno del cognome.\n");
				system("PAUSE");
				system("CLS");
				BenvenutoTitolo();
			}
		
		else
		
		{
			strcpy(username.cognome,nick);
		}
		
	}while(controllo_n==1);
		
		
	printf("\n");
	
	do{
			controllo_n=0;
			fflush(stdin);	
			printf("Inserisci il nome dell'utente: ");
	
	
			gets(nick); 
		
			for(i=0;i<strlen(nick);i++)
			{
				if(nick[i]==' ')
				{
					controllo_n=1;
				}
			}
		
			if(controllo_n==1)
			{
				printf("\nErrore, inserimento di spazi non previsto all'interno del nome.\n");
				system("PAUSE");
				system("CLS");
				BenvenutoTitolo();
			}
		
		else
		
		{
			strcpy(username.nome,nick);
		}
		
	}while(controllo_n==1);
	
	printf("\n");
		
	controllo=0;
		
		
		do{
			printf("Inserisci il sesso dell'utente (M/F/Non specificato):  "); // controllo sull'opzionalita', e sul carattere
			gets(username.genere);
			
			if(strcmp(username.genere,"M")==0 || strcmp(username.genere,"F")==0)
			{
				controllo=1;
			}
			
			else
			
			{
				if(strcmp(username.genere,"Non specificato")==0 )
				{
					controllo=1;
				}
				
			}
			
			if(controllo==0)
			{
				printf("Errore, inserire un formato valido.");
				printf("\n");
			}
			
		}while(controllo==0);
		
		printf("\n");
		
		printf("Inserisci la data di nascita:  "); 
		gets(username.datan); 
		
		printf("\n");
		
		printf("Inserisci il numero di telefono: ");
		gets(username.ntelefono); //Controlla la lunghezza del numero e che ci siano solo numeri (La lunghezza e' 10).

		printf("\n");
		do{
			printf("Inserisci una preferenza musicale:  \n");
			menug();
		
		
			printf("Fai la tua scelta: ");
			gets(scelta);
			
			numero = atoi(scelta);
			
			if(numero < 1 || numero > 9)
			{
				printf("Errore, ripetere l'inserimento.\n");
				system("CLS");
				BenvenutoTitolo();
			}
			
		}while(numero < 1 || numero > 9);
		
		switch(numero)
		{
			case 1:
					strcpy(username.gmusicale,"BLUES");
					break;
			case 2:
					strcpy(username.gmusicale,"CLASSICA");
					break;
			case 3:
					strcpy(username.gmusicale,"HEAVY-METAL");
					break;	
			case 4:
					strcpy(username.genere,"HIP-HOP");
					break;
			case 6:
					strcpy(username.gmusicale,"JAZZ");
					break;
			case 7:
					strcpy(username.gmusicale,"ROCK");
					break;	
			case 8:
					strcpy(username.gmusicale,"PUNK");
					break;
			case 9:
					strcpy(username.gmusicale,"ALTRO");
					break;
							
		}
	
		
		if((scrittura=fopen("File//Utenti.csv","a+"))==NULL)
		{
			printf("\nFile non esistente.");
		}
		
		else
		{
			fprintf(scrittura,"%s,%s,%s,%s,%s,%s,%s,%s\n",username.nickname,username.email,username.cognome,username.nome,username.genere,username.datan,username.ntelefono,username.gmusicale);
		}
	 	
		fclose(scrittura);
	}
		


}

/**
*	La procedura modificadati permette all'utente di modificare un campo di un utente precedentemente registrato.
*	Il nickname dell'utente deve necessariamente essere preregistrato.
*
*	nickc: Nickname inserito dall'utente.\n
*	controllo: Variabile che segnala l'esistenza o meno del nickname.\n
*	numero: Variabile che determinera' il numero del campo da modificare.\n
*   leggi.email: Email modificata inserito dall'utente.\n
*   leggi.cognome: Cognome modificato inserito dall'utente.\n
*   leggi.nome: Nome modificatoinserito dall'utente.\n
*   leggi.genere: Sesso modificato inserito dall'utente.\n
*   leggi.datan: Data di nascita modificata inserito dall'utente.\n
*	leggi.ntelefono: Numero di telefono modificato inserito dall'utente.\n
*	leggi.gmusicale: Gusto musicale modificato inserito dall'utente.\n
*	boole: Variabile che controlla se il campo selezionato e' modificabile.\n
*
*	@return void
*/

void modificadati()
{
	fflush(stdin);
	char nickc[50];
	char nickt[50];
	FILE* scrittura;
	FILE* apertura;
	int controllo=0;
	char scelta[2];
	int numero;
	char scelta_musicale[2];
	int musica;
	char riga[200];
	char* appoggio;
	struct utente leggi={"","","","","","","",""};
	struct utente temp={"","","","","","","",""};
	char str[100];
	int trovato=0;
	int boole=1;
	char nickname_confronto[50];
	char copia[300];
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
	
	SetColor(4);
	
	printf("\n\nATTENZIONE! --- Durante il corso della modifica, non sara' possibile cambiare il nickname --- ATTENZIONE!\n\n\n");
	
	SetConsoleTextAttribute(hConsole, saved_attributes);
	
	printf("Inserisci il nickname per riconoscere l'utente a cui effettuare le modifiche: ");
	gets(nickc);
	
	
	controllo=ricercaN(nickc);
	
	if(controllo==0)
	{
		printf("\nNessun nickname trovato.");
		printf("\n");
	}
	

	else
	{
		printf("\n");
		printf("\nQuale campo vuoi modificare?");
		printf("\n\n\n");
		stampautenti(nickc);
		
		do{
		
			printf("\n\nInserisci numero campo da modificare: ");
			gets(scelta);
			numero= atoi(scelta);
			printf("\n\n");
			
			if(numero < 1 || numero > 9)
			
			{
				printf("\nErrore, la scelta non e'appropriata.\n");
				system("pause");
				system("CLS");
				BenvenutoTitolo();
			}
			
			else
			{
			
				if((scrittura=fopen("File//Utenti.csv","a+"))==NULL)
				{
					printf("\nFile non esistente.");
				}
		
				else
			
				{
					fscanf(scrittura,"%s",riga);
					
					while(!feof(scrittura)) 
					{	  
						strcpy(nickt, strtok(riga, ","));
						
        				if(strcmp(nickc,nickt)==0) 
            			{
            				trovato=1;
							strcpy(leggi.nickname,nickc);
        					appoggio=strtok(NULL,",");
            				strcpy(leggi.email,appoggio);
            				appoggio=strtok(NULL,",");
            				strcpy(leggi.cognome,appoggio);
            				appoggio=strtok(NULL,",");
            				strcpy(leggi.nome,appoggio);
            				appoggio=strtok(NULL,",");
            				strcpy(leggi.genere,appoggio);
            				appoggio=strtok(NULL,",");
            				strcpy(leggi.datan,appoggio);
            				appoggio=strtok(NULL,",");
            				strcpy(leggi.ntelefono,appoggio);
            				appoggio=strtok(NULL,",");
            				strcpy(leggi.gmusicale,appoggio);
					
							switch(numero)
							{	
								case 2:     printf("Inserisci la nuova email: ");
											fflush(stdin);
											gets(leggi.email);
											break;
								case 3:     printf("Inserisci il nuovo cognome: ");
											fflush(stdin);
											gets(leggi.cognome);
											break;	
								case 4:     printf("Inserisci il nuovo nome: ");
											fflush(stdin);
											gets(leggi.nome);
											break;		
								case 5:     printf("Inserisci il genere: ");
											fflush(stdin);
											gets(leggi.genere);
											break;
											
								case 6:     printf("Inserisci la nuova data di nascita: ");  //controllare tutti gli input
											fflush(stdin);
											gets(leggi.datan);
											break;
												
								case 7:     printf("Inserisci il nuovo numero di telefono: ");
											fflush(stdin);
											gets(leggi.ntelefono);
											break;	
											
								case 8:     printf("\n");
											printf("Inserisci una nuova preferenza musicale:  \n");
											menug();
		
											do{
												printf("Fai la tua scelta musicale: ");
												gets(scelta_musicale);
												musica = atoi(scelta_musicale);
			
												if(musica < 1 || musica > 9)
												{
													printf("Errore, ripetere l'inserimento.\n");
													system("pause");
													system("CLS");
													BenvenutoTitolo();
												}
			
											}while(musica < 1 || musica > 9);
		
											switch(musica)
															{
																case 1:
																		strcpy(leggi.gmusicale,"BLUES");
																		break;
																case 2:
																		strcpy(leggi.gmusicale,"CLASSICA");
																		break;
																case 3:
																		strcpy(leggi.gmusicale,"HEAVY-METAL");
																		break;	
																case 4:
																		strcpy(leggi.genere,"HIP-HOP");
																		break;
																case 6:
																		strcpy(leggi.gmusicale,"JAZZ");
																		break;
																case 7:
																		strcpy(leggi.gmusicale,"ROCK");
																		break;	
																case 8:
																		strcpy(leggi.gmusicale,"PUNK");
																		break;
																case 9:
																		strcpy(leggi.gmusicale,"ALTRO");
																		break;
							
															}
	
										
											break;
							
							default:
										printf("\nErrore, questi campi non sono modificabili.\n");
										printf("\n");
										boole=0;
            				}
            										
							
        				}
						
						fscanf(scrittura,"%s",riga);
						
						
						
         	
					}
					fclose(scrittura);	
					
				}
				
				if(boole!=0)
				{
				
				scrittura=fopen("File//Utenti2.csv","w");
				apertura=fopen("File//Utenti.csv","r");
				
				if(apertura==NULL || scrittura==NULL)
				{
					printf("\nFile non esistenti.");
				}
				
				else
				
				{
						fscanf(apertura,"%s",str);
						
						strcpy(copia,str);
						
						while(!feof(apertura)) 
						{	  

							strcpy(nickname_confronto, strtok(str, ","));
							
            				if(strcmp(nickname_confronto,leggi.nickname)==0)
            				{
            					fprintf(scrittura,"%s,%s,%s,%s,%s,%s,%s,%s\n",leggi.nickname,leggi.email,leggi.cognome,leggi.nome,leggi.genere,leggi.datan,leggi.ntelefono,leggi.gmusicale);						
							}
										
							else
							{
								fprintf(scrittura,"%s\n",copia); 
							}
							
							fflush(stdin);
							
							fscanf(apertura,"%s",str);
							strcpy(copia,str);
						}
		
					
				}
				
				fclose(apertura);
				fclose(scrittura);
				
				remove("File//Utenti.csv");
				rename("File//Utenti2.csv","File//Utenti.csv");
				
				printf("\nLe informazioni dell'utente sono state correttamente aggiornate nel file 'Utenti.csv'.\n");
				}
			}
		
		}while(numero <1 || numero >9);
		
	}
	
	
}


/**
*	La procedura menug permette all'utente di visualizzare tutti i generi disponibili durante la registrazione o la modifica di un utente.\n
*
*	@return void
*/

void menug()
{
	printf("1 ---> BLUES");
	printf("\n2 ---> CLASSICA"); 
	printf("\n3 ---> HEAVY METAL");
	printf("\n4 ---> HIP-HOP");
	printf("\n5 ---> JAZZ");
	printf("\n6 ---> POP"); 
	printf("\n7 ---> ROCK");
	printf("\n8 ---> PUNK");
	printf("\n9 ---> ALTRO");
	printf("\n");
}


/**
*	La funzione ricercaN permette all'utente di ricercare il nickname di un utente all'interno del file "Utenti.csv".
*
*	@param[in] nicknameU: Nickname che verra' controllato all'interno del file "Utenti.csv".
*	@param[out] bl: Variabile che segnala l'esistenza o meno del nickname.
*
*	@return bl
*/
int ricercaN(char nicknameU[])
{
	int bl=0;
	
	FILE* file;
	
	char nicknameI[100];
	char riga[200];
	
	
	if((file=fopen("File//Utenti.csv","r"))==NULL)
	{
		system("CLS");
		BenvenutoTitolo();
		printf("File non esistente.");
		printf("\nSarai reindirizzato al main.\n");
		system("PAUSE");
		system("CLS");
		main();
	}
		
	else
		
	{
		fscanf(file,"%s",riga);

		while(!feof(file)) 
		{	
			strcpy(nicknameI, strtok(riga, ","));
            if(strcmp(nicknameU,nicknameI)==0) 
            {
				bl=1;
            }
         
            fscanf(file,"%s",riga);
				
        }
        
        fclose(file);
	}
	
	return bl;
}


/**
*	La procedura stampautenti permette di stampare tutti i campi di un utente, attraverso il nickname fornito in input.
*	Il nickname dell'utente deve necessariamente essere preregistrato.
*
*	@param[in] nick: Nickname inserito dall'utente che verra' controllato durante la modifica di quest'ultimo.
*
*	@return void
*/

void stampautenti(char nick[]) 
{
	
	FILE* fileu;
	char riga[200];
	char* appoggio;
	char nickname_c[100];
	struct utente leggi={"","","","","","","",""};
	
	if((fileu=fopen("File//Utenti.csv","r"))==NULL)
	{
		system("CLS");
		BenvenutoTitolo();
		printf("File non esistente.");
		printf("\nSarai reindirizzato al main.\n");
		system("PAUSE");
		system("CLS");
		main();
	}
		
	else
		
	{
		fscanf(fileu,"%s",riga);
		while(!feof(fileu)) 
		{	
			strcpy(nickname_c, strtok(riga, ","));
			
			if(strcmp(nick,nickname_c)==0)
			{
			
            strcpy(leggi.nickname,nick);
        	appoggio=strtok(NULL,",");
            strcpy(leggi.email,appoggio);
            appoggio=strtok(NULL,",");
            strcpy(leggi.cognome,appoggio);
            appoggio=strtok(NULL,",");
            strcpy(leggi.nome,appoggio);
            appoggio=strtok(NULL,",");
            strcpy(leggi.genere,appoggio);
            appoggio=strtok(NULL,",");
            strcpy(leggi.datan,appoggio);
            appoggio=strtok(NULL,",");
            strcpy(leggi.ntelefono,appoggio);
            appoggio=strtok(NULL,",");
            strcpy(leggi.gmusicale,appoggio);

             	
            printf("1) Nickname attuale ---> %s\n",leggi.nickname);
            printf("2) Email attuale ---> %s\n",leggi.email);
            printf("3) Cognome attuale ---> %s\n",leggi.cognome);
            printf("4) Nome attuale ---> %s\n",leggi.nome);
            printf("5) Genere attuale ---> %s\n",leggi.genere);
            printf("6) Data di nascita attuales ---> %s\n",leggi.datan);
            printf("7) Numero di telefono ---> %s\n",leggi.ntelefono);
            printf("8) Gusto Musicale ---> %s\n",leggi.gmusicale);

        	}
        	
        	fscanf(fileu,"%s",riga);
        }

        fclose(fileu);
    }
}

