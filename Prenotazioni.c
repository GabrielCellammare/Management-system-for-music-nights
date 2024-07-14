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
*	La procedura venditaBiglietto permette di vendere un biglietto ad un utente, attraverso l'inserimento di diversi parametri.
*
*	utente.nick: Nickname dell'utente che prenotera' il biglietto. \n
*	trovato: Variabile che segnalera' l'esistenza o meno dell'utente all'interno del file "Utenti.csv". \n
*   utente.id_e: Id evento che prenotera' l'utente. \n
* 	trovato_id: Variabile che segnalera' l'esistenza o meno dell'evento all'interno del file "Eventi.csv". \n
* 	utente.idp: Id della prenotazione generato casualmente. \n
*	trovato_idp: Variabile che segnalera' l'esistenza o meno di un id prenotazione uguale all'interno del file "Prenotazioni.csv". \n
*   file_disponibili: Il numero totale di file disponibili e prenotabili per quell'evento. \n
*   utente.fila: Il numero di fila scelto dall'utente. \n
*   n_postiperfila: Il numero totale di posti disponibili e prenotabili per ogni fila di quell'evento. \n
*   poltrone_totali: Il numero totale di poltrone disponibili e prenotabili per quell'evento. \n
*   utente.n_pol: Il numero di poltrona scelta da quell'utente. \n
*   controllo_filepoltrone: Variabile che segnala la disponibilita' della fila e della poltrona scelta dall'utente. \n
*
*	@return void
*/

void venditaBiglietto()
{
	struct prenotazione utente={0,0,"",0,0,0.0};
	int trovato;
	int trovato_id;
	int trovato_idp;
	int file_disponibili;
	int n_postiperfila;
	FILE* file;
	char riga[100];
	char id_char[100];
	int id;
	char temp[100];
	double c_primafila;
	double c_ultimafila;
	char* tempdouble;
	double calcolo;
	int poltrone_totali;
	int controllo_filepoltrone;
	FILE* scrittura;
	char id_ev[5];
	int i,j=0;
	int controllo_idevento=0;
	int controllo_ni=0;
	char nick[50];
	
	
	
	do{
		do{
			controllo_ni=0;
			printf("Benvenuto nella sezione della vendita di biglietti.\n");
			printf("Inserisci il tuo Nickname: ");
			fflush(stdin);
			gets(nick);
			
			for(i=0;i<50;i++)
			{
				if(nick[i]==' ')
				{
					controllo_ni=1;
				}
			}
			
			if(controllo_ni==1)
			{
				printf("\nErrore, il nickname non puo' contenere spazi.\n");
				system("PAUSE");
				system("CLS");
				BenvenutoTitolo();
				
			}
			
			else
			{
				strcpy(utente.nick,nick);
			}
			
		}while(controllo_ni==1);
		
		printf("\nRicerca in corso");
		Sleep(700);
        printf(".");
        Sleep(700);
        printf(".");
        Sleep(700);
        printf(".\n");
        Sleep(700);
		
		trovato=ricercaN(utente.nick);
		
		if(trovato!=1)
		{
			printf("\nUser non trovato, riprovare.\n");
			printf("\n");		
			system("PAUSE");
			system("CLS");
			BenvenutoTitolo();
			
		}
	}while(trovato!=1);
	
	system("cls");
	
	BenvenutoTitolo();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
	
	SetColor(9);
	
	printf("L'username e' registrato all'interno del nostro database, procedere con la prenotazione.\n");
	
	SetConsoleTextAttribute(hConsole, saved_attributes);
	
	system("PAUSE");
	
	do{
		do{
			
			system("CLS");
			BenvenutoTitolo();
			printf("Inserisci l'id dell'evento da prenotare: ");
			fflush(stdin);
			gets(id_ev); //Controlla che l'id evento abbia solo 5 NUMERI.
			
			for(i=0;i<5;i++)
			{
				if((isdigit(id_ev[i]))==1) //Se è un numero, produce il valore di ritorno 1.
				{
					j++;
				}
			}
			
			if(j==5)
			{
				utente.id_e=atoi(id_ev);
				
				if(utente.id_e<00000 || utente.id_e>99998)
				{
					printf("\nFormato errato o non valido.\n");
					system("PAUSE");
					j=0;
				}
				
				else
				
				{
					controllo_idevento=1;
				}
			}
			
			else
			
			{
				printf("\nLa lunghezza deve essere di 5 caratteri numerici OBBLIGATORIAMENTE.\n");
				system("PAUSE");
				j=0;
			}
			
		}while(controllo_idevento==0);
		
		printf("\nRicerca in corso");
		Sleep(700);
        printf(".");
        Sleep(700);
        printf(".");
        Sleep(700);
        printf(".\n");
        Sleep(700);
		
		trovato_id=ricercaIDEvento(utente.id_e);
		
		if(trovato_id!=1)
		{
			printf("\nEvento non trovato, riprovare.\n");
			system("PAUSE");
			printf("\n");		
		}
		
	}while(trovato_id!=1);
	
	if((file=fopen("File//Eventi.csv","r"))==NULL)
	{
		printf("\nFile non esistente.");
	}
		
	else
		
	{
		fscanf(file,"%s",riga);

		while(!feof(file)) 
		{	
			strcpy(id_char, strtok(riga, ","));
			id=atoi(id_char);
			
            if(id==utente.id_e) 
            {
				strcpy(id_char, strtok(NULL, ","));
				strcpy(id_char, strtok(NULL, ","));
				strcpy(id_char, strtok(NULL, ","));
				strcpy(id_char, strtok(NULL, ","));
				strcpy(id_char, strtok(NULL, ","));
				strcpy(id_char, strtok(NULL, ","));
				strcpy(id_char, strtok(NULL, ","));
				strcpy(id_char, strtok(NULL, ","));
				strcpy(id_char, strtok(NULL, ","));
				strcpy(id_char, strtok(NULL, ","));
				c_primafila=strtod(id_char,&tempdouble);
				strcpy(id_char, strtok(NULL, ","));
				c_ultimafila=strtod(id_char,&tempdouble); //funzione per convertire una stringa in un double
				strcpy(id_char, strtok(NULL, ","));
				strcpy(temp,id_char);
				file_disponibili=atoi(temp);
				strcpy(id_char, strtok(NULL, ","));
				strcpy(temp,id_char);
				n_postiperfila=atoi(temp);
            }
         
            fscanf(file,"%s",riga);
				
        }
        
        fclose(file);
	}
	
	do{
		system("CLS");
		BenvenutoTitolo();
		printf("L'evento ricercato, esiste.");
		printf("\nAttendere mentre verra' automaticamente generato l'id della prenotazione");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    	WORD saved_attributes;
    
    	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    	saved_attributes = consoleInfo.wAttributes;
	
		SetColor(9);
	
		
		printf("\nGenerazione in corso");
		Sleep(700);
        printf(".");
        Sleep(700);
        printf(".");
        Sleep(700);
        printf(".\n");
        Sleep(700);
		utente.idp=9999+rand()%90000;
		printf("L'id generato e': %d.\n\n",utente.idp);
		system("PAUSE");
		SetConsoleTextAttribute(hConsole, saved_attributes);
		
		fflush(stdin);
		printf("\n\nRicerca di un id prenotazione uguale a %d in corso",utente.idp);
		Sleep(700);
        printf(".");
        Sleep(700);
        printf(".");
        Sleep(700);
        printf(".\n");
        Sleep(1500);
		trovato_idp=ricercaPrenotazione(utente.idp);
		
		if(trovato_idp==1)
		{
			printf("\nPrenotazione gia' effettuata, riprovare.\n");
			printf("\nIl sistema ha gia' prodotto un id simile.\n");
			system("PAUSE");
			printf("\n");	
			printf("\n");	
		}
		
	}while(trovato_idp==1);
	
	system("CLS");
	BenvenutoTitolo();
	printf("\nTutti i controlli sono stati effettuati, e' possibile procedere con la vendita del biglietto.\n\n");
    
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
	
	SetColor(9);
	printf("Le file totali dell'evento sono %d.\n",file_disponibili);
	SetConsoleTextAttribute(hConsole, saved_attributes);
	
	
	do{
		printf("Inserisci la fila da prenotare: ");
		scanf("%d",&utente.fila); //Questi controlli li ho gia' fatti io.
			
		if(utente.fila<1 || utente.fila>file_disponibili)
		{
			printf("Errore, numero errato.");
			printf("\n");
			printf("\n");	
		}
			
	}while(utente.fila<1 || utente.fila>file_disponibili);
	
	poltrone_totali=file_disponibili*n_postiperfila;
    
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
	
	SetColor(9);

	printf("\nLe poltrone disponibili per ogni fila sono sono %d.\n",n_postiperfila);	
	printf("Le poltrone totali sono %d.\n\n",poltrone_totali);
	
	SetConsoleTextAttribute(hConsole, saved_attributes);
		
	do{
		printf("Inserisci il numero della poltrona da prenotare nella fila %d: ",utente.fila);
		scanf("%d",&utente.n_pol);
			
		if(utente.n_pol <1 || utente.n_pol > n_postiperfila)
		{
				printf("Errore, numero errato.");
				printf("\n");
				printf("\n");	
		}
			
	}while(utente.n_pol <1 || utente.n_pol > n_postiperfila);
		
	controllo_filepoltrone=ControllaFilaPoltrona(utente.fila,utente.n_pol,n_postiperfila,utente.id_e,file_disponibili);
	
	printf("\nAttendere mentre vengono controllati tutte le postazioni disponibili");
	Sleep(700);
    printf(".");
    Sleep(700);
    printf(".");
    Sleep(700);
    printf(".\n");
	Sleep(700);

	if(controllo_filepoltrone==0)
	{
		if(utente.fila==1)
		{
			utente.importo_p=c_primafila;
			printf("\nIl costo del biglietto per la poltrona %d della fila %d \nequivale a: %.2lf euro.",utente.n_pol,utente.fila,utente.importo_p);
			
		}
		
		else
		{
			if(utente.fila==file_disponibili)
			{
				utente.importo_p=c_ultimafila;
				printf("\nIl costo del biglietto per la poltrona %d della fila %d \nequivale a: %.2lf euro.",utente.n_pol,utente.fila,utente.importo_p);
			
			}
				
			else
			{
				calcolo=utente.fila/((double)file_disponibili);
				utente.importo_p=c_primafila-(calcolo * (c_primafila-c_ultimafila));
				printf("\nIl costo del biglietto per la poltrona %d della fila %d \nequivale a: %.2lf euro.",utente.n_pol,utente.fila,utente.importo_p);
			
			
			}
				
		}

	
		if((scrittura=fopen("File//Prenotazioni.csv","a+"))==NULL)
		{
			printf("\nFile non esistente.");
		}
		
		else
		
		{
			fprintf(scrittura,"%d,%d,%s,%d,%d,%.2lf\n",utente.idp,utente.id_e,utente.nick,utente.fila,utente.n_pol,utente.importo_p);
		}
				
        fclose(scrittura);
		
    
    	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    	saved_attributes = consoleInfo.wAttributes;
	
		SetColor(9);

		printf("\n\n\nBiglietto venduto correttamente.\n");
		
		SetConsoleTextAttribute(hConsole, saved_attributes);
		
		system("PAUSE");
		
		
	
		AggiornaIncasso(utente.id_e,utente.importo_p);
	
	}
	
	else
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   	 	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    	WORD saved_attributes;
    
    	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  	    saved_attributes = consoleInfo.wAttributes;
	
	    SetColor(9);

		printf("\nVendita del biglietto fallita, poltrona occupata o fila piena.\n");
		
		SetConsoleTextAttribute(hConsole, saved_attributes); //Il prompt ritorna con i colori salvati precedentemente.
	
	}
	
	

					
}

/**
*	La funzione ControllaFilaPoltrona permette di controllare la disponibilita' dei parametri per ogni prenotazione ad un evento..
*
*	@param[in] fila: La variabile fila indica la fila scelta dall'utente durante il controllo di una poltrona o la vendita di un biglietto.
*	@param[in] poltrona: La variabile poltrona indica il numero della poltrona scelto dall'utente durante il controllo di quest'ultima, o durante la vendita di un biglietto.
*   @param[in] n_postiperfila: La variabile n_postiperfila indica il numero di poltrone disponibili per ogni fila.
*   @param[in] idevento: La variabile idevento indica l'id dell'evento a cui si fa riferimento.
*   @param[in] file_totali: La variabile file_totali, indica il numero delle file totali disponibili per quell'evento.
* 	@param[out] ritorno: La variabile ritorno controlla che la poltrona scelta dall'utente sia libera o meno.
*
*	@return ritorno
*/
int ControllaFilaPoltrona(int fila, int poltrona,int n_postiperfila,int idevento,int file_totali)
{
	int ritorno=0;
	int controllo=0;
	int id_controllato=0;
	int controllo_file=0;
	int id_controllo_evento=1;
	FILE* file;
	
	char stringa[100];
	char riga[200];
	int temp;
	int conta_posti_perfila=0;
	int totale_poltrone=file_totali*n_postiperfila;
	
	controllo=ControllaPosti(idevento);
	
	if(controllo<totale_poltrone)
	{
	
		if((file=fopen("File//Prenotazioni.csv","r"))==NULL)
		{
		printf("\nFile non esistente.");
		}	
		
		else
		
		{
		fscanf(file,"%s",riga);

		while(!feof(file) && ritorno==0) 
		{	
			strcpy(stringa, strtok(riga, ",")); 
			strcpy(stringa, strtok(NULL, ","));
			id_controllato=atoi(stringa); // id evento
			strcpy(stringa, strtok(NULL, ","));
			strcpy(stringa, strtok(NULL, ",")); //nfile
			temp=atoi(stringa);

			if(id_controllato==idevento)
			{
				id_controllo_evento=1;
				
            	if(temp==fila) 
            	{
            		controllo_file=1;
            		conta_posti_perfila++;
            	
					if(conta_posti_perfila<=n_postiperfila)
					{
						strcpy(stringa, strtok(NULL, ","));
						temp=atoi(stringa);
						
						
						if(temp==poltrona)
						{
							ritorno=1;
						}
						
						else
						
						{
							ritorno=0;
						}
					}
				
					else
					{
						system("CLS");
						BenvenutoTitolo();
						printf("\n\nIn questa fila, tutte le poltrone sono esaurite.\n");
					}
            	}
            	
            	else
            	
            	{
            		controllo_file=0;
				}
            	
     		}
     		
     		else
			{
				id_controllo_evento=0;
			}

   
            fscanf(file,"%s",riga);
				
        }
        
        fclose(file);
	}
	
		if(controllo_file==0)
		{
			ritorno=0;
		}
		
		if(id_controllo_evento==0)
		{
			ritorno=0;
		}
	
		return ritorno;
	}
	
	else
	{
		system("CLS");
		BenvenutoTitolo();
		printf("\n\nTutti i posti sono stati gia' prenotati.");
		ritorno=1;
		return ritorno;
	}
}

/**
*	La funzione ControllaPosti permette di controllare la disponibilita' di almeno un posto all'interno dell'evento.
*
*	@param[in] id_evento: La variabile che conterra' l'id evento da controllare.
*	@param[out] ritorno: La variabile ritorno segnalera' la presenza di almeno un posto all'interno dell'evento.
*
*	@return ritorno
*/
int ControllaPosti(int id_evento)
{
	int ritorno=0;
	
	FILE* file;
	
	char id[5];
	char riga[200];
	int temp;
	int contatore=0;
	
	
	if((file=fopen("File//Prenotazioni.csv","r"))==NULL)
	{
		printf("\nFile non esistente.");
	}
		
	else
		
	{
		fscanf(file,"%s",riga);

		while(!feof(file)) 
		{	
			strcpy(id, strtok(riga, ","));
			strcpy(id, strtok(NULL, ","));
			temp=atoi(id);
			
            if(id_evento==temp) 
            {
				contatore++;
            }
         
            fscanf(file,"%s",riga);
				
        }
        
        fclose(file);
	}
	return ritorno;
}

/**
*	La funzione ricercaPrenotazione permette di controllare l'esistenza di un id prenotazione uguale.
*
*	@param[in] idp: La variabile che conterra' l'id prenotazione da controllare.
*	@param[out] ritorno: La variabile ritorno segnalera' la presenza o meno di un id prenotazione uguale.
*
*	@return ritorno
*/
int ricercaPrenotazione(int idp)
{
	int ritorno=0;
	
	FILE* file;
	
	char id[5];
	char riga[200];
	int temp;
	
	
	if((file=fopen("File//Prenotazioni.csv","r"))==NULL)
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
			strcpy(id, strtok(riga, ","));
			temp=atoi(id);
			
            if(idp==temp) 
            {
				ritorno=1;
            }
         
            fscanf(file,"%s",riga);
				
        }
        
        fclose(file);
	}

	return ritorno;
	
	
}

/**
*	La procedura AggiornaIncasso permette di aggiornare l'incasso di un evento, ogni volta che viene venduto un biglietto ad un utente, all'interno del file "Eventi.csv".
*
*	@param[in] idevento: La variabile idevento che identifichera' l'id dell'evento.
*	@param[in] incasso_biglietto: La variabile incasso_biglietto determina la cifra da aggiungere all'incassso gia' presente.
*	
*	@return void
*/
void AggiornaIncasso(int idevento,double incasso_biglietto)
{
	FILE* lettura;
	FILE* scrittura;
	FILE* apertura;
	char riga[300];
	char stringa_temporanea[300];
	char* appoggio;
	char* tempdouble;
	int temp;
	char copia[150];
	char str[150];
	struct evento letto={0,0,"",0,0,0,0,0,"","",0.0,0.0,0,0,0.0};
	int scelta_modifica;
	double incasso_parziale;
	double incasso_totale;
	
	if((lettura=fopen("File//Eventi.csv","r"))==NULL)
	{
		printf("\nFile non esistente.");
	}
		
	else
		
	{
		
		fscanf(lettura,"%s",riga);
		
		while(!feof(lettura)) 
		{	
			strcpy(stringa_temporanea, strtok(riga, ","));
			temp=atoi(stringa_temporanea);
			
			if(temp==idevento)
			{	
				letto.id=idevento;
        		appoggio=strtok(NULL,",");
        		temp=atoi(appoggio);
        		letto.anno=temp;
            	appoggio=strtok(NULL,",");
        		strcpy(letto.mese,appoggio);
        		appoggio=strtok(NULL,",");
        		temp=atoi(appoggio);
        		letto.giorno=temp;
        		appoggio=strtok(NULL,",");
        		temp=atoi(appoggio);
        		letto.ora_i=temp;
        		appoggio=strtok(NULL,",");
        		temp=atoi(appoggio);
        		letto.minuti_i=temp;
        		appoggio=strtok(NULL,",");
        		temp=atoi(appoggio);
        		letto.ora_f=temp;
        		appoggio=strtok(NULL,",");
        		temp=atoi(appoggio);
        		letto.minuti_f=temp;
        		appoggio=strtok(NULL,",");
        		strcpy(letto.nomelocale,appoggio);
        		appoggio=strtok(NULL,",");
        		strcpy(letto.artista,appoggio);
        		appoggio=strtok(NULL,",");
        		letto.costo_b_primaf=strtod(appoggio,&tempdouble); //funzione per convertire una stringa in un double
        		appoggio=strtok(NULL,",");
        		letto.costo_b_ultimaf=strtod(appoggio,&tempdouble); 
        		appoggio=strtok(NULL,",");
        		temp=atoi(appoggio);
        		letto.n_file=temp;
        		appoggio=strtok(NULL,",");
        		temp=atoi(appoggio);
        		letto.n_posti_perfila=temp;
        		appoggio=strtok(NULL,",");
        		letto.incasso_complessivo=strtod(appoggio,&tempdouble);
        	}
        	
        	fscanf(lettura,"%s",riga);
        }

        fclose(lettura);
    }
    
    incasso_totale=letto.incasso_complessivo+incasso_biglietto;
    
    scrittura=fopen("File//Eventi2.csv","w");
	apertura=fopen("File//Eventi.csv","r");
				
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
			strcpy(stringa_temporanea, strtok(str, ","));
			
			temp=atoi(stringa_temporanea);
							
            if(temp==idevento)
            {
            
			fprintf(scrittura,"%d,%d,%s,%d,%d,%d,%d,%d,%s,%s,%.2lf,%.2lf,%d,%d,%.2lf\n",letto.id,letto.anno,letto.mese,letto.giorno,
			letto.ora_i,letto.minuti_i,letto.ora_f,letto.minuti_f,
			letto.nomelocale,letto.artista,letto.costo_b_primaf,letto.costo_b_ultimaf,
			letto.n_file,letto.n_posti_perfila,incasso_totale);	
			
			system("CLS");
			BenvenutoTitolo();
			
			printf("\nAttendere mentre viene aggiornato l'incasso complessivo dell'evento");
			Sleep(700);
        	printf(".");
        	Sleep(700);
        	printf(".");
        	Sleep(700);
        	printf(".\n");
        	Sleep(700);
        	
        	
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
   			WORD saved_attributes;
        	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    		saved_attributes = consoleInfo.wAttributes;
	
			SetColor(9);

			printf("\n\nIncasso aggiornato automaticamente nel file 'Evento.csv', nel campo 'Incasso complessivo'.\n");	
			
			
			SetConsoleTextAttribute(hConsole, saved_attributes);
						
			}
										
			else
			{
				fprintf(scrittura,"%s\n",copia); 
			}
							
			fflush(stdin);
							
			fscanf(apertura,"%s",str);
			strcpy(copia,str);
		}
				
		fclose(apertura);
		fclose(scrittura);
				
		remove("File//Eventi.csv");
		rename("File//Eventi2.csv","File//Eventi.csv");
		}
}

/**
*	La procedura ControlloPoltrona permette di controllare la disponibilita' di una singola poltrona di un determinato evento.
*
*   utente.id_e: Id evento in cui controllare la poltrona. \n
* 	trovato_id: Variabile che segnalera' l'esistenza o meno dell'evento all'interno del file "Eventi.csv". \n
*   file_disponibili: Il numero totale di file disponibili e prenotabili per quell'evento. \n
*   utente.fila: Il numero di fila scelto dall'utente. \n
*   n_postiperfila: Il numero totale di posti disponibili e prenotabili per ogni fila di quell'evento. \n
*   poltrone_totali: Il numero totale di poltrone disponibili e prenotabili per quell'evento. \n
*   utente.n_pol: Il numero di poltrona scelta da quell'utente. \n
*   controllo_filepoltrone: Variabile che segnala la disponibilita' della fila e della poltrona scelta dall'utente. \n
*
*	@return void
*/
void ControlloPoltrona()
{
	struct prenotazione utente={0,0,"",0,0,0.0};
	int trovato;
	int trovato_id;
	int trovato_idp;
	int file_disponibili;
	int n_postiperfila;
	FILE* file;
	char riga[100];
	char id_char[100];
	int id;
	char temp[100];
	double c_primafila;
	double c_ultimafila;
	char* tempdouble;
	double calcolo;
	int poltrone_totali;
	int controllo_filepoltrone;
	FILE* scrittura;
	
	do{
		system("CLS");
		BenvenutoTitolo();
		printf("\nInserisci l'id dell'evento: ");
		fflush(stdin);
		scanf("%d",&utente.id_e);
		printf("\nRicerca in corso");
		Sleep(700);
        printf(".");
        Sleep(700);
        printf(".");
        Sleep(700);
        printf(".\n");
        Sleep(700);
		
		trovato_id=ricercaIDEvento(utente.id_e);
		
		if(trovato_id!=1)
		{
			
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
   			WORD saved_attributes;
    		GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    		saved_attributes = consoleInfo.wAttributes;
	
			SetColor(9);

			printf("\nEvento non trovato, riprovare.\n");
			printf("\n");	
			SetConsoleTextAttribute(hConsole, saved_attributes);
			
			system("pause");
				
		}
		
	}while(trovato_id!=1);
	
	if((file=fopen("File//Eventi.csv","r"))==NULL)
	{
		printf("\nFile non esistente.");
	}
		
	else
		
	{
		fscanf(file,"%s",riga);

		while(!feof(file)) 
		{	
			strcpy(id_char, strtok(riga, ","));
			id=atoi(id_char);
			
            if(id==utente.id_e) 
            {
				strcpy(id_char, strtok(NULL, ","));
				strcpy(id_char, strtok(NULL, ","));
				strcpy(id_char, strtok(NULL, ","));
				strcpy(id_char, strtok(NULL, ","));
				strcpy(id_char, strtok(NULL, ","));
				strcpy(id_char, strtok(NULL, ","));
				strcpy(id_char, strtok(NULL, ","));
				strcpy(id_char, strtok(NULL, ","));
				strcpy(id_char, strtok(NULL, ","));
				strcpy(id_char, strtok(NULL, ","));
				c_primafila=strtod(id_char,&tempdouble);
				strcpy(id_char, strtok(NULL, ","));
				c_ultimafila=strtod(id_char,&tempdouble); //funzione per convertire una stringa in un double
				strcpy(id_char, strtok(NULL, ","));
				strcpy(temp,id_char);
				file_disponibili=atoi(temp);
				strcpy(id_char, strtok(NULL, ","));
				strcpy(temp,id_char);
				n_postiperfila=atoi(temp);
            }
         
            fscanf(file,"%s",riga);
				
        }
        
        fclose(file);
	}
	
	system("CLS");
	BenvenutoTitolo();
	printf("\nTutti i controlli sono stati effettuati, e' possibile procedere con la verifica della poltrona.\n\n");
	
	do{
		
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    	WORD saved_attributes;
    
    	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    	saved_attributes = consoleInfo.wAttributes;
	
		SetColor(9);
		printf("Le file totali dell'evento sono %d.\n",file_disponibili);
		SetConsoleTextAttribute(hConsole, saved_attributes);
		
	
	
	
		printf("Inserisci la fila: ");
		scanf("%d",&utente.fila); //Controllare con l'atoi in modo tale da non mandare in loop il software.
			
		if(utente.fila<1 || utente.fila>file_disponibili)
		{
			printf("Errore, numero errato.");
			printf("\n\n");	
			system("PAUSE");
			system("CLS");
			BenvenutoTitolo();
		}
			
	}while(utente.fila<1 || utente.fila>file_disponibili);
	
	poltrone_totali=file_disponibili*n_postiperfila;
    
    do{
    	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    	WORD saved_attributes;
    	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    	saved_attributes = consoleInfo.wAttributes;
	
		SetColor(9);

		printf("\nLe poltrone disponibili per ogni fila sono sono %d.\n",n_postiperfila);	
		printf("Le poltrone totali sono %d.\n\n",poltrone_totali);
	
		SetConsoleTextAttribute(hConsole, saved_attributes);
		
	
		printf("Inserisci il numero della poltrona: ");
		scanf("%d",&utente.n_pol);//Controllare con l'atoi in modo tale da non mandare in loop il software.
			
		if(utente.n_pol <1 || utente.n_pol > n_postiperfila)
		{
			printf("Errore, numero errato.\n");	
			system("PAUSE");
			system("CLS");
			BenvenutoTitolo();
		}
			
	}while(utente.n_pol <1 || utente.n_pol > n_postiperfila);
	
	controllo_filepoltrone=ControllaFilaPoltrona(utente.fila,utente.n_pol,n_postiperfila,utente.id_e,file_disponibili);
			
	if(controllo_filepoltrone==1)
	{	
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    	WORD saved_attributes;
   		GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    	saved_attributes = consoleInfo.wAttributes;
	
		SetColor(9);

		printf("\nLa poltrona selezionata e' occupata.\n");
		SetConsoleTextAttribute(hConsole, saved_attributes);
		
	}
	
	else
	
	{	
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    	WORD saved_attributes;
    	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    	saved_attributes = consoleInfo.wAttributes;
	
		SetColor(9);

		printf("\nLa poltrona selezionata e' disponibile.\n");
		SetConsoleTextAttribute(hConsole, saved_attributes);
	}	
}

/**
*	La procedura StampaPrenotati permette di stampare tutti i nickname dei prenototati ad un determinato evento.
*
*   nickname: variabile che verra' utlizzata per inserire ogni volta il nickname. \n
* 	id_evento: Variabile che conterra' l'id evento da prenotare. \n
*   trovato_id: Variabile che indica la presenza o meno di quel determinato evento all'interno del file "Eventi.csv". \n
*
*	@return void
*/
void StampaPrenotati()
{	
	int id_evento;
	char nickname[30];
	FILE* file;
	int trovato_id;
	char riga[100];
	char id_char[100];
	int id;
	int c=0;
	char id_ev[5];
	int j=0;
	int i=0;
	int controllo_idevento=0;
	
	do{
		do{
		
			printf("\nInserisci l'id dell'evento: ");
			fflush(stdin);
			gets(id_ev); //Controlla che l'id evento abbia solo 5 NUMERI.
			
			for(i=0;i<5;i++)
			{
				if((isdigit(id_ev[i]))==1) //Se è un numero, produce il valore di ritorno 1.
				{
					j++;
				}
			}
			
			if(j==5)
			{
				id_evento=atoi(id_ev);
				
				if(id_evento<00000 || id_evento>99998)
				{
					printf("\nFormato errato o non valido.\n");
					system("PAUSE");
					system("CLS");
					BenvenutoTitolo();
					j=0;
				}
				
				else
				
				{
					controllo_idevento=1;
				}
			}
			
			else
			
			{
				printf("\nLa lunghezza deve essere di 5 caratteri numerici OBBLIGATORIAMENTE.\n");
				system("PAUSE");
				system("CLS");
				BenvenutoTitolo();
				j=0;
			}
			
		}while(controllo_idevento==0);
		
		printf("\nRicerca in corso");
		Sleep(700);
        printf(".");
        Sleep(700);
        printf(".");
        Sleep(700);
        printf(".\n");
        Sleep(700);
		
		trovato_id=ricercaIDEvento(id_evento);
		
		if(trovato_id!=1)
		{
			printf("\nEvento non trovato, riprovare.\n");
			printf("\n");	
			system("PAUSE");
			system("CLS");
			BenvenutoTitolo();	
		}
		
	}while(trovato_id!=1);
	
	if((file=fopen("File//Prenotazioni.csv","r"))==NULL)
	{
		printf("\nFile non esistente.");
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
		system("CLS");
		BenvenutoTitolo();
		
		
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    	WORD saved_attributes;
    
    	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    	saved_attributes = consoleInfo.wAttributes;
	
		SetColor(9);
		
		printf("\nI prenotati all'evento con ID = %d sono: \n\n",id_evento);
		
		SetConsoleTextAttribute(hConsole, saved_attributes);
		
		fscanf(file,"%s",riga);

		while(!feof(file)) 
		{	
			strcpy(id_char, strtok(riga, ","));
			strcpy(id_char, strtok(NULL, ","));
			id=atoi(id_char);
			
            if(id==id_evento) 
            {
            	c++;
				strcpy(id_char, strtok(NULL, ","));
				strcpy(nickname, id_char);
				printf("\nUtente numero %d : ",c);
				printf("%s ",nickname);
				strcpy(id_char, strtok(NULL, ","));
				printf("prenotato nella fila %s ", id_char);
				strcpy(id_char, strtok(NULL, ","));
				printf("e poltrona numero %s.\n", id_char);
				
            }
         
            fscanf(file,"%s",riga);
				
        }
        
        fclose(file);
	}
	
	printf("\n\n");
	
	if(c==0)
	{
		system("cls");
		BenvenutoTitolo();
		printf("\nNon e' stato prenotato nessun biglietto per questo evento.\n");
	}

	
}		

/**
*	La procedura StampaUtentiFiltro permette di stampare tutti gli eventi a cui ha partecipato un utente.
*
*   nickname_t: Variabile che verra' utlizzata per inserire ogni volta il nickname da controllare. \n
*	trovato: Variabile che verra' utilizzata per controllare l'esistenza di quel nickname. \n
* 	scelta_o: Variabile che conterra' la scelta dell'utente, ovvero se stampera' gli eventi in ordine cronologico o in base al prezzo. \n
*
*	@return void
*/

void StampaUtentiFiltro()
{
	int trovato=0;
	struct listautenti persona[100]={"",0,0,0,0,0.0};  
	struct listautenti appoggio={"",0,0,0,0,0.0};
	char nick[200];
	char riga[200];
	char id_event[10];
	int id_temporaneo;
	char nickname_t[30];
	FILE* file;
	int i=0,j=0;
	int conta=0;
	int mesi=0;
	char* temp_double;
	int controllo=0;
	int temp_o;
	char scelta_o[1];
	int minimo=0;
	
	printf("Benvenuto nella stampa degli eventi a cui ha partecipato un utente.\n");
	
	do{
		printf("Inserisci il tuo Nickname: ");
		fflush(stdin);
		gets(nickname_t);
		printf("\nRicerca in corso");
		Sleep(700);
        printf(".");
        Sleep(700);
        printf(".");
        Sleep(700);
        printf(".\n");
        Sleep(700);
		
		trovato=ricercaN(nickname_t);
		
		if(trovato!=1)
		{
			printf("\nUser non trovato, riprovare.\n");
			printf("\n");
			system("pause");
			system("CLS");
			BenvenutoTitolo();		
		}
	}while(trovato!=1);
	
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
   WORD saved_attributes;
    
   GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
   saved_attributes = consoleInfo.wAttributes;
	
   SetColor(3);

   printf("\nUtente trovato correttamente.\n");
   
   SetConsoleTextAttribute(hConsole, saved_attributes);

   system("PAUSE");
   system("CLS");
   strcpy(persona[i].nickname,nickname_t);

	if((file=fopen("File//Prenotazioni.csv","r"))==NULL)
	{
		printf("\nFile non esistente.");
	}
		
	else
		
	{
		fscanf(file,"%s",riga);

		while(!feof(file)) 
		{	
			strcpy(nick, strtok(riga, ","));
			strcpy(nick, strtok(NULL, ","));
			id_temporaneo=atoi(nick);
			strcpy(nick, strtok(NULL, ","));
			
            if(strcmp(nick,persona[i].nickname)==0) 
            {
            	conta++;
            	strcpy(nick, strtok(NULL, ","));
            	strcpy(nick, strtok(NULL, ","));
            	strcpy(nick, strtok(NULL, ","));
            	persona[i].costo_biglietto=strtod(nick,&temp_double); 
				persona[i].id_evento=id_temporaneo;
				strcpy(persona[i+1].nickname,persona[i].nickname);
				i++;
            }
         
            fscanf(file,"%s",riga);

        }
        
        fclose(file);
	}
		
	if((file=fopen("File//Eventi.csv","r"))==NULL)
	{
		printf("\nFile non esistente.");
	}
	
	else
	
	{
		i=0;
		
		fscanf(file,"%s",riga);

		while(!feof(file)) 
		{	
			strcpy(nick, strtok(riga, ","));
			id_temporaneo=atoi(nick);
			
			for(i=0;i<conta;i++)
			{		
				if(id_temporaneo==persona[i].id_evento)
				{
						if(controllo==0) //controllo che serve nel caso due persone partecipino allo stesso evento.
						{
							controllo=1;
							strcpy(nick, strtok(NULL, ","));
							persona[i].anno=atoi(nick);
							strcpy(nick, strtok(NULL, ","));
							mesi=ControlloMesi(nick);
							persona[i].mese=mesi;
							strcpy(nick, strtok(NULL, ","));
							persona[i].giorno=atoi(nick);	
						}
						
						else
						
						{
							for(j=0;j<conta;j++)
							{
								if(persona[i].id_evento==persona[j].id_evento)
								{
									persona[i].anno=persona[j].anno;
									persona[i].mese=persona[j].mese;
									persona[i].giorno=persona[j].giorno;
								}
							}
						}
						
				}
				
				
			}
			controllo=0;
			fscanf(file,"%s",riga);
		}
			
		fclose(file);
	}
	
	do{

		system("CLS");
		BenvenutoTitolo();
		printf("Come vuoi effettuare la stampa? (Scegli un numero)");
		printf("\n1) In ordine cronologico");
		printf("\n2) In base al prezzo del biglietto acquistato");
		printf("\n\n\nFai la tua scelta: ");
		fflush(stdin);
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
   		WORD saved_attributes;

   		GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
   		saved_attributes = consoleInfo.wAttributes;

  		SetColor(3);

		gets(scelta_o);

   		SetConsoleTextAttribute(hConsole, saved_attributes);

		temp_o=atoi(scelta_o);

		if(temp_o<1 || temp_o>2)
		{
			printf("\nErrore, scelta non definita correttamente.\n");
			system("pause");
			system("CLS");
		}
		
	}while(temp_o<1 || temp_o>2);
	
	printf("\nRicerca delle informazioni in corso");
	Sleep(700);
    printf(".");
    Sleep(700);
    printf(".");
    Sleep(700);
    printf(".\n");
    Sleep(700);
	
	if(temp_o==1)
	{
		for(i=0;i<conta-1;i++)
		{	
       		for(j=conta-1;j>1;j--)
       		{
       			if(persona[j].anno<persona[j-1].anno)
       			{
       				appoggio.anno=persona[j].anno;
       				appoggio.mese=persona[j].mese;
       				appoggio.giorno=persona[j].giorno;
       				appoggio.id_evento=persona[j].id_evento;
       				appoggio.costo_biglietto=persona[j].costo_biglietto;
       				strcpy(appoggio.nickname,persona[j].nickname);
       				
       				persona[j].anno=persona[j-1].anno;
       				persona[j].mese=persona[j-1].mese;
       				persona[j].giorno=persona[j-1].giorno;
       				persona[j].id_evento=persona[j-1].id_evento;
       				persona[j].costo_biglietto=persona[j-1].costo_biglietto;
       				strcpy(persona[j].nickname,persona[j-1].nickname);
       				
       				persona[j-1].anno=appoggio.anno;
       				persona[j-1].mese=appoggio.mese;
       				persona[j-1].giorno=appoggio.giorno;
       				persona[j-1].id_evento=appoggio.id_evento;
       				persona[j-1].costo_biglietto=appoggio.costo_biglietto;
       				strcpy(persona[j-1].nickname,appoggio.nickname);
				}
			}
		}
			
		for(i=0;i<conta-1;i++)
		{	
       		for(j=conta-1;j>1;j--)
       		{
       			if(persona[j].anno<=persona[j-1].anno)
       			{
				   
       				if(persona[j].mese<persona[j-1].mese)
       				{
       					appoggio.anno=persona[j].anno;
       					appoggio.mese=persona[j].mese;
       					appoggio.giorno=persona[j].giorno;
       					appoggio.id_evento=persona[j].id_evento;
       					appoggio.costo_biglietto=persona[j].costo_biglietto;
       					strcpy(appoggio.nickname,persona[j].nickname);
       				
       					persona[j].anno=persona[j-1].anno;
       					persona[j].mese=persona[j-1].mese;
       					persona[j].giorno=persona[j-1].giorno;
       					persona[j].id_evento=persona[j-1].id_evento;
       					persona[j].costo_biglietto=persona[j-1].costo_biglietto;
       					strcpy(persona[j].nickname,persona[j-1].nickname);
       				
       					persona[j-1].anno=appoggio.anno;
       					persona[j-1].mese=appoggio.mese;
       					persona[j-1].giorno=appoggio.giorno;
       					persona[j-1].id_evento=appoggio.id_evento;
       					persona[j-1].costo_biglietto=appoggio.costo_biglietto;
       					strcpy(persona[j-1].nickname,appoggio.nickname);
					}
				}
			}
		
			
		}
		
		for(i=0;i<conta-1;i++)
		{	
       		for(j=conta-1;j>1;j--)
       		{
       			if(persona[j].anno<=persona[j-1].anno)
       			{
       				if(persona[j].mese<=persona[j-1].mese)
       				{
       					if(persona[j].giorno<persona[j-1].giorno)
       					
       					{
       						appoggio.anno=persona[j].anno;
       						appoggio.mese=persona[j].mese;
       						appoggio.giorno=persona[j].giorno;
       						appoggio.id_evento=persona[j].id_evento;
       						appoggio.costo_biglietto=persona[j].costo_biglietto;
       						strcpy(appoggio.nickname,persona[j].nickname);
       				
       						persona[j].anno=persona[j-1].anno;
       						persona[j].mese=persona[j-1].mese;
       						persona[j].giorno=persona[j-1].giorno;
       						persona[j].id_evento=persona[j-1].id_evento;
       						persona[j].costo_biglietto=persona[j-1].costo_biglietto;
       						strcpy(persona[j].nickname,persona[j-1].nickname);
       				
       						persona[j-1].anno=appoggio.anno;
       						persona[j-1].mese=appoggio.mese;
       						persona[j-1].giorno=appoggio.giorno;
       						persona[j-1].id_evento=appoggio.id_evento;
       						persona[j-1].costo_biglietto=appoggio.costo_biglietto;
       						strcpy(persona[j-1].nickname,appoggio.nickname);
						}
					}
				}
       			
			}
		
		}	
	
	}
	
	if(temp_o==2)
	{	
		for(i=0;i<conta-1;i++)
		{	
			minimo=i;
			
       		for(j=i+1;j<conta;j++)
       		{
       			if((persona[j].costo_biglietto) < (persona[minimo].costo_biglietto))
       			{
       				minimo=j;
				}
			}
			
       		appoggio.anno=persona[minimo].anno;
       		appoggio.mese=persona[minimo].mese;
       		appoggio.giorno=persona[minimo].giorno;
       		appoggio.id_evento=persona[minimo].id_evento;
       		appoggio.costo_biglietto=persona[minimo].costo_biglietto;
       		strcpy(appoggio.nickname,persona[minimo].nickname);
       				
       		persona[minimo].anno=persona[i].anno;
       		persona[minimo].mese=persona[i].mese;
       		persona[minimo].giorno=persona[i].giorno;
       		persona[minimo].id_evento=persona[i].id_evento;
       		persona[minimo].costo_biglietto=persona[i].costo_biglietto;
       		strcpy(persona[minimo].nickname,persona[i].nickname);
       			
       		persona[i].anno=appoggio.anno;
       		persona[i].mese=appoggio.mese;
       		persona[i].giorno=appoggio.giorno;
       		persona[i].id_evento=appoggio.id_evento;
       		persona[i].costo_biglietto=appoggio.costo_biglietto;
       		strcpy(persona[i].nickname,appoggio.nickname);
		}
			
		
		
	}	
	
	if(conta>=1)
	{
	
		for(i=0;i<conta;i++)
	
		{
			system("CLS");
			BenvenutoTitolo();
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   			CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
   			WORD saved_attributes;
    
   			GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
   			saved_attributes = consoleInfo.wAttributes;
	
   			SetColor(9);
   			
   			printf("\nStampa dell'evento numero: %d .",i+1);

   			printf("\n\nL'utente '%s', ha partecipato al seguente evento (ID: %d) tenutosi in: ",persona[i].nickname,persona[i].id_evento);
   		
   			SetConsoleTextAttribute(hConsole, saved_attributes);
   		
			printf("\n\nAnno: %d\n",persona[i].anno);
			printf("\nMese: %d\n",persona[i].mese);
			printf("\nGiorno: %d\n",persona[i].giorno);
		
   			GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
   			saved_attributes = consoleInfo.wAttributes;
	
   			SetColor(9);
   			
			printf("\n\nIl costo del biglietto acquistato e' di: %.2lf euro.",persona[i].costo_biglietto);
			printf("\n\n");
			
			SetConsoleTextAttribute(hConsole, saved_attributes);
		
			system("Pause");
		}
	}
	
	else
	
	{
		system("CLS");
		BenvenutoTitolo();
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
   		WORD saved_attributes;
    
   		GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
   		saved_attributes = consoleInfo.wAttributes;
	
   		SetColor(9);

   		printf("\nL'utente non ha partecipato ancora a nessun evento.\n\n");
   		
   		SetConsoleTextAttribute(hConsole, saved_attributes);
   		
   		system("Pause");
	}
	
}
			

	
/**
*	La proceudra ControlloMesi permette di convertire tutte le stringhe, che rappresentano un mese, nel corrispettivo ma in formato INT.
*
*   @param[in] mese: Stringa che verra' convertita in int.
*
*	@return int
*/


int ControlloMesi(char mese[])
{
	if(strcmp(mese,"Gennaio")==0)
	{
		return 1;
	}
	
	if(strcmp(mese,"Febbraio")==0)
	{
		return 2;
	}
	
	if(strcmp(mese,"Marzo")==0)
	{
		return 3;
	}
	
	if(strcmp(mese,"Aprile")==0)
	{
		return 4;
	}
	
	if(strcmp(mese,"Maggio")==0)
	{
		return 5;
	}
	
	if(strcmp(mese,"Giugno")==0)
	{
		return 6;
	}
	
	if(strcmp(mese,"Luglio")==0)
	{
		return 7;
	}

	if(strcmp(mese,"Agosto")==0)
	{
		return 8;
	}
	
	if(strcmp(mese,"Settembre")==0)
	{
		return 9;
	}
	
	if(strcmp(mese,"Ottobre")==0)
	{
		return 10;
	}
	
	if(strcmp(mese,"Novembre")==0)
	{
		return 11;
	}
	
	if(strcmp(mese,"Dicembre")==0)
	{
		return 12;
	}
	
}
