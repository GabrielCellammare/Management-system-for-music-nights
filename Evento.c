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
*	La procedura RegistraEvento(), che appartiene alla libreria "Evento.o", 
*	attraverso la funzione ricercaEvento(), stabilisce le condizioni per registrare il nuovo evento.
*
*	@return void
*/
void registraEvento()
{
	struct evento registrato={0,0,"",0,0,0,0,0,"","",0.0,0.0,0,0,0.0};
	
	FILE* apertura;
	FILE* scrittura;
	int controllo;
	
	printf("Inserisci l'id evento: ");
	scanf("%d",&registrato.id); //controlla l'input, eventuali spazi e ricordati che l'ID è solo numerico con 5 caratteri.
	
	printf("\n");
	printf("Inserisci l'anno di svolgimento:  ");
	scanf("%d",&registrato.anno); //Controlla che sia un anno valido.
	fflush(stdin);
		
	printf("\n");
	printf("Inserisci il mese di svolgimento:  "); //Controlla il mese, anche qui puoi utilizzare le gramamtiche.
	gets(registrato.mese);
	fflush(stdin);
		
	printf("\n"),
	printf("Inserisci il giorno di svolgimento:  "); //Controlla il giorno [Se hai tempo, puoi anche effettuare un controllo sull'anno...se è bisestile o meno.
	scanf("%d",&registrato.giorno);
	fflush(stdin);
	
			
	printf("\n");
	printf("Inserisci il nome del locale:  ");
	gets(registrato.nomelocale); //NO SPAZI ALTRIMENTI IL PROGRAMMA NON FUNZIONA.
	fflush(stdin);
		
	printf("\n");
	printf("Inserisci il nome dell'artista:  ");
	gets(registrato.artista);  //CONTROLLARE CHE NON CI SIANO SPAZI ALL'INTERNO DEL NOME ARTISTA.
	fflush(stdin);
	
	controllo=ricercaEvento(registrato.id,registrato.anno,registrato.mese,registrato.giorno,registrato.nomelocale,registrato.artista);

	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
	
	SetColor(9);
	
	printf("\nStiamo ricercando eventi simili/uguali gia' registrati");
	Sleep(700);
   	printf(".");
    Sleep(700);
    printf(".");
    Sleep(700);
    printf(".\n");
    Sleep(700);
	
	SetConsoleTextAttribute(hConsole, saved_attributes); //Il prompt ritorna con i colori salvati precedentemente.
	
    if(controllo>=5)
  	{
        	printf("\nErrore, evento gia' esistente o giorni incongruenti.\n\n");
	}
	
	else
	
	{
		printf("\nNon esistono eventi simili/uguali, completare la registrazione.\n");
		
		printf("\n");
		printf("Inserisci l'ora di inizio:  ");
		scanf("%d",&registrato.ora_i);
		fflush(stdin); //Controlla che sia un numero e che sia massimo 24 e minimo 1
		
		printf("\n");
		printf("Inserisci i minuti di inizio:  ");
		scanf("%d",&registrato.minuti_i);//Controlla che sia un numero e che vada 00 a 59
		fflush(stdin);
		
		printf("\n");
		printf("Inserisci l'ora di fine:  ");
		scanf("%d",&registrato.ora_f);//Controlla che sia un numero e che sia massimo 24 e minimo 1 e che sia maggiore dell'ora di inizio.
		fflush(stdin);
		
		printf("\n");
		printf("Inserisci i minuti di fine:  ");
		scanf("%d",&registrato.minuti_f);//Controlla che sia un numero e che vada 00 a 59
		fflush(stdin);

		
		printf("\n");
		printf("Inserisci il costo della prima fila:  ");
		scanf("%lf",&registrato.costo_b_primaf); //Controlla spazi o lettere
		fflush(stdin);
		
		printf("\n");
		printf("Inserisci il costo dell'ultima fila:  ");
		scanf("%lf",&registrato.costo_b_ultimaf);//Controlla spazi o lettere
		fflush(stdin);
		
		printf("\n");
		printf("Inserisci il numero di file:  ");//Controlla spazi o lettere
		scanf("%d",&registrato.n_file);
		
		printf("\n");
		printf("Inserisci il numero di posti per fila:  ");//Controlla spazi o lettere
		scanf("%d",&registrato.n_posti_perfila);
		fflush(stdin);
		
		printf("\n");
		fflush(stdin);
		
		if((scrittura=fopen("File//Eventi.csv","a+"))==NULL)
		{
			printf("\nFile non esistente.");
		}
		
		else
		{
			fprintf(scrittura,"%d,%d,%s,%d,%d,%d,%d,%d,%s,%s,%.2lf,%.2lf,%d,%d,%.2lf\n",registrato.id,registrato.anno,registrato.mese,registrato.giorno,
			registrato.ora_i,registrato.minuti_i,registrato.ora_f,registrato.minuti_f,
			registrato.nomelocale,registrato.artista,registrato.costo_b_primaf,registrato.costo_b_ultimaf,
			registrato.n_file,registrato.n_posti_perfila,0.0);
		}


	 	
		fclose(scrittura);
	}
		


}

/**
*	La funzione ricercaEvento permette in fase di registrazione, di controllare che non ci siano eventi simili o uguali.
*	@param[in] id: Id evento da controllare.
*	@param[in] anno: Anno in cui si svolgera' l'evento.
*	@param[in] mese: Mese in cui si svolgera' l'evento.
*	@param[in] giorno: Giorno in cui si svolgera' l'evento.
*	@param[in] nomelocale: Nome del locale in cui si svolgera' l'evento.
*	@param[in] nomeartista: Artista che si esibera' durante l'evento.
*	@param[out] bl: variabile di controllo che consentira' o meno la registrazione dell'evento.
*
*	@return bl
*/

int ricercaEvento(int id,int anno,char mese[],int giorno,char nomelocale[],char nomeartista[])
{
	int bl=0;
	char *virgola;
	char controllo[30];
	int temp;
	int controllo_finale=0;
	
	FILE* file;
	
	char riga[200];
	
	
	if((file=fopen("File//Eventi.csv","r"))==NULL)
	{
		printf("\nFile non esistente.");
	}
		
	else
		
	{
		fscanf(file,"%s",riga);

		
		while(!feof(file))  
		{	
			
			if(bl<5)
			{
				bl=0;
				controllo_finale=0;
				strcpy(controllo, strtok(riga, ","));
			
				temp=atoi(controllo);
			
			
            	if(temp==id) 
            	{
					bl=5;
            	}	
            
            	else
            
            	{
            		virgola=strtok(NULL,",");
        	
        			strcpy(controllo,virgola);
        	
        			temp=atoi(controllo);
        	
        			if(temp==anno)
        			{
        				bl++;
        				controllo_finale++;
        				virgola=strtok(NULL,",");
						strcpy(controllo,virgola);
				
						if(strcmp(controllo,mese)==0)
						{
							bl++;
							controllo_finale++;
						}
			
						virgola=strtok(NULL,",");
						strcpy(controllo,virgola);
						temp=atoi(controllo);
			
						if(temp==giorno)
						{
							bl++;
							controllo_finale++;
						}
			
					}
	
					virgola=strtok(NULL,",");
					virgola=strtok(NULL,",");
					virgola=strtok(NULL,",");
					virgola=strtok(NULL,",");
					virgola=strtok(NULL,",");
					strcpy(controllo,virgola);
			
						
					
					if(strcmp(controllo,nomelocale)==0)
					{
						bl++;
												
						if(controllo_finale==3)
						{	
							bl=5;
						}
					}
			
					virgola=strtok(NULL,",");
					strcpy(controllo,virgola);
						
					if(strcmp(controllo,nomeartista)==0)
					{
						bl++;
							
						if(controllo_finale==3)
						{	
							bl=5;
						}
					}
						
				}
					
            	
			}
			
			
            fscanf(file,"%s",riga);
        	
		}

			fclose(file);	
        }
        
    return bl;  
}

/**
*	La procedura cercaEvento permette di ricercare un evento in base alla data, o al nome dell'artista che partecipera'.
*
*	@return void
*/

void cercaEvento()
{
	char scelta[2];
	int numero;
	char scelta2[2];
	int numero2;
	int anno;
	char mese[20];
	int giorno; //effettuare i vari controlli
	char stringa[30];
	char str_appoggio[30];
	char *puntatore;
	int appoggio;
	int trovato=0;
	int id;
	int scelta_modifica;
	char nomeartista[200];
	char id_char[5];
	int id_temporaneo;
	int trovato_e=0;
	int id_e;
	int temp;
	struct evento vettore[100]={0,0,"",0,0,0,0,0,"","",0.0,0.0,0,0,0.0};
	int i=0;
	
	FILE* file;
	
	char riga[200];
	
	do{
	
		printf("Come vuoi effettuare la ricerca? (Scegliere un  numero)\n ");
		printf("\n1)Data");
		printf("\n2)Nome dell'artista");
		printf("\n\nInserisci la scelta: ");
		gets(scelta);
		
		numero = atoi(scelta);
		
		if(numero <1 || numero >2)
		{
			printf("\nErrore, ripetere la scelta.\n");
			system("pause");
			system("CLS");
			BenvenutoTitolo();
		}
		
	}while(numero <1 || numero >2);
	
	if(numero==1)
	{
		system("CLS");
		BenvenutoTitolo();
		
		printf("\nInserisci il giorno: ");
		scanf("%d",&giorno); //Controlla che non abbia lettere o spazi e che sia >1 o >30
		fflush(stdin);
		printf("\nInserisci il mese: ");
		gets(mese); //Controlla che non sia un numero
		fflush(stdin);
		printf("\nInserisci l'anno: ");
		scanf("%d",&anno); //Anno possibile
		fflush(stdin);
		
		if((file=fopen("File//Eventi.csv","r"))==NULL)
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
				puntatore=strtok(riga,",");
				strcpy(str_appoggio,puntatore);
				temp=atoi(str_appoggio);
				puntatore=strtok(NULL,",");
				
        		strcpy(str_appoggio,puntatore);
        		
        		appoggio=atoi(str_appoggio);
        		
        		if(appoggio==anno)
        		{
        			puntatore=strtok(NULL,",");
				
        			strcpy(str_appoggio,puntatore);
        			
        				
        			if(strcmp(str_appoggio,mese)==0)
        			{
        				
        				puntatore=strtok(NULL,",");
				
        				strcpy(str_appoggio,puntatore);
        				
        				appoggio=atoi(str_appoggio);
        				
        				if(appoggio==giorno)
        				{
        					strcpy(vettore[i].mese,mese);
        					vettore[i].anno=anno;
        					vettore[i].giorno=giorno;
        					vettore[i].id=temp;
        					trovato++;
        					i++;
						}
        			
					}
			
				
				}
			
				fscanf(file,"%s",riga);
			
			}	
		
			fclose(file);
		}
		
		if(trovato>=1)
		{
			do{
				system("CLS");
				BenvenutoTitolo();
				printf("\nLa ricerca e' stata completata correttamente.\nSono stati trovati il/i seguente/i evento/i con la data inserita: \n");
				printf("\n");
			
				for(i=0;i<trovato;i++)
				{
					printf("\nId trovato = %d \n", vettore[i].id);
					printf("\n");
				}
			
				i=0;
			
			
				printf("\nInserisci l'id evento da modificare o eliminare: ");
				scanf("%d",&id_e);
				
				do{
					if(id_e==vettore[i].id)
					{
						trovato_e=1;
						temp=vettore[i].id;
					}
					
					i++;
					
				}while(i<trovato);
					
				if(trovato_e==0)
				{
					printf("\nErrore, id non esistente o non trovato.\n");
					system("pause");
				}
				
			}while(trovato_e==0);
			
			do{
				system("CLS");
				BenvenutoTitolo();
				printf("\nDesidere modificare o eliminare l'evento?(Scegliere un  numero)\n ");
				printf("\n1)Modifica");
				printf("\n2)Elimina ");
				printf("\n\nInserisci la scelta: ");
				fflush(stdin);
				gets(scelta2);
				
				numero2=atoi(scelta2);
		
				if(numero2 <1 || numero2 >2)
				{
					printf("\nErrore, ripetere la scelta.\n");
					system("pause");
					system("CLS");
					BenvenutoTitolo();
				}
		
			}while(numero2 <1 || numero2 >2);
			
			if(numero2==1)
			{
				ModificaEvento(temp);
			}
			
			else
			
			{
				EliminaEvento(temp);
			}
	
			
		}
		
		else
		
		{
			printf("\nNessun evento trovato, data inesistente.\n");
		}
	}	
	
	else
	{
		i=0;
		trovato=0;
		system("CLS");
		BenvenutoTitolo();
		printf("\nInserisci il nome dell'artista: ");
		gets(nomeartista);
		
		
		if((file=fopen("File//Eventi.csv","r"))==NULL)
		{
			printf("\nFile non esistente.");
		}
			
		else
		
		{

			fscanf(file,"%s",riga);
		
			while(!feof(file)) 
			{	
			
				puntatore=strtok(riga,",");
				strcpy(id_char,puntatore);
				id_temporaneo=atoi(id_char);
				puntatore=strtok(NULL,",");
				puntatore=strtok(NULL,",");
				puntatore=strtok(NULL,",");
				puntatore=strtok(NULL,",");
				puntatore=strtok(NULL,",");
				puntatore=strtok(NULL,",");
				puntatore=strtok(NULL,",");
				puntatore=strtok(NULL,",");
				puntatore=strtok(NULL,",");
				strcpy(str_appoggio,puntatore);
				
        		if(strcmp(str_appoggio,nomeartista)==0)
        		{
        			trovato++;;
        			vettore[i].id=id_temporaneo;
        			i++;
				}
			
				fscanf(file,"%s",riga);
			
			}	
		
			fclose(file);
		}
		
		if(trovato>=1)
		{
			do{
				system("CLS");
				BenvenutoTitolo();
				printf("\nLa ricerca e' stata completata correttamente.\nSono stati trovati il/i seguente/i evento/i dell'artista '%s' : \n", nomeartista);
				printf("\n");
			
				for(i=0;i<trovato;i++)
				{
					printf("\nId trovato = %d \n", vettore[i].id);
					printf("\n");
				}
			
				i=0;
			
			
				printf("\nInserisci l'id evento da modificare o eliminare: ");
				scanf("%d",&id_e); //Controlla l'evento che abbia almeno e solo 5 caratteri,
				
				do{
					if(id_e==vettore[i].id)
					{
						trovato_e=1;
						temp=vettore[i].id;
					}
					
					i++;
					
				}while(i<trovato);
					
				if(trovato_e==0)
				{
					printf("\nErrore, id non esistente o non trovato.\n");
					system("pause");
				}
				
			}while(trovato_e==0);
			
			do{
				system("CLS");
				BenvenutoTitolo();
				printf("\nDesidere modificare o eliminare l'evento?(Scegliere un  numero)\n ");
				printf("\n1)Modifica");
				printf("\n2)Elimina ");
				printf("\n\nInserisci la scelta: ");
				fflush(stdin);
				gets(scelta2);
				
				numero2=atoi(scelta2);
		
				if(numero2 <1 || numero2 >2)
				{
					printf("\nErrore, ripetere la scelta.\n");
					system("pause");
					system("CLS");
					BenvenutoTitolo();
				}
		
			}while(numero2 <1 || numero2 >2);
			
			if(numero2==1)
			{
				ModificaEvento(temp);
			}
			
			else
			
			{
				EliminaEvento(temp);
			}
	
			
		}
		
		else
		
		{
			printf("\nNessun evento trovato, data inesistente.\n");
		}
	}

}

/**
*	La procedura ModificaEvento permette di modificare determinati campi all'interno del file "Eventi.csv".
*	@param[in] identificatore: Id evento da controllare per poi, effettuare le eventuali modifiche.
*
*	@return void
*/

void ModificaEvento(int identificatore)
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
			
			if(temp==identificatore)
			{
				letto.id=identificatore;
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
        		
        		system("CLS");
        		
        		BenvenutoTitolo();
        		printf("Di seguito, la stampa dei dati attuali dell'evento.\n\n\n");
             	
            	printf("1) ID ---> %d.\n",letto.id);
            	printf("2) Anno ---> %d.\n",letto.anno);
            	printf("3) Mese ---> %s.\n",letto.mese);
            	printf("4) Giorno ---> %d.\n",letto.giorno);
            	printf("5) Orario di inizio ---> %d,%d.\n",letto.ora_i,letto.minuti_i);
            	printf("6) Orario di fine ---> %d,%d.\n",letto.ora_f,letto.minuti_f);
           		printf("7) Nome locale ---> %s.\n",letto.nomelocale);
            	printf("8) Artista/Gruppo ---> %s.\n",letto.artista);
            	printf("9) Costo biglietto prima fila ---> %.2lf euro.\n",letto.costo_b_primaf);
           	 	printf("10) Costo biglietto ultima fila ---> %.2lf euro.\n",letto.costo_b_ultimaf);
           		printf("11) Numero di file ---> %d.\n",letto.n_file);
           		printf("12) Numero di posti per fila ---> %d\n",letto.n_posti_perfila);
            	printf("13) Incasso complessivo ---> %.2lf euro.\n\n\n",letto.incasso_complessivo);
   
   				system("pause"); 
                scelta_modifica=Menu_modifica_evento();
                
            	switch(scelta_modifica)
            	{
            		case 1:
            				 fflush(stdin);
            				 printf("Inserisci il nuovo dato nel campo 'Anno': ");
            				 scanf("%d",&letto.anno);
            				 printf("\n");
            				 break;
            		case 2:
            				 fflush(stdin);
            				 printf("Inserisci il nuovo dato nel campo 'Mese': ");
            				 gets(letto.mese),
            				 printf("\n");
            				 break;	
					case 3:
							 fflush(stdin);
            				 printf("Inserisci il nuovo dato nel campo 'Giorno': ");
            				 scanf("%d",&letto.giorno);
            				 printf("\n");
            				 break;	
					case 4:
							 fflush(stdin);
            				 printf("Inserisci il nuovo dato nel campo 'Ora d'inizio': ");
            				 scanf("%d",&letto.ora_i);
            				 printf("\n");
            				 break;	
					case 5:
							 fflush(stdin);
            				 printf("Inserisci il nuovo dato nel campo 'Minuti d'inizio': ");
            				 scanf("%d",&letto.minuti_i);
            				 printf("\n");
            				 break;	
					case 6:
            				 printf("Inserisci il nuovo dato nel campo 'Ora di fine': ");
            				 scanf("%d",&letto.ora_f);
            				 printf("\n");
            				 break;	
					case 7:
							 fflush(stdin);
            				 printf("Inserisci il nuovo dato nel campo 'Minuti di fine': ");
            				 scanf("%d",&letto.minuti_f);
            				 printf("\n");
            				 break;	
					case 8:
							 fflush(stdin);
            				 printf("Inserisci il nuovo dato nel campo 'Nome locale': ");
            				 gets(letto.nomelocale);
            				 printf("\n");
            				 break;	
					case 9:
							 fflush(stdin);
            				 printf("Inserisci il nuovo dato nel campo 'Nome artista': ");
            				 gets(letto.artista);
            				 printf("\n");
            				 break;	
							 
					default:
							 printf("\nAttenzione, questi campi non sono modificabili.\n");			 			 	 		 		 		 		 		 		 		 	 	 
				}
        	}
        	
        	fscanf(lettura,"%s",riga);
        }

        fclose(lettura);
    }
    
    
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
							
            if(temp==letto.id)
            {
            
			fprintf(scrittura,"%d,%d,%s,%d,%d,%d,%d,%d,%s,%s,%.2lf,%.2lf,%d,%d,%.2lf\n",letto.id,letto.anno,letto.mese,letto.giorno,
			letto.ora_i,letto.minuti_i,letto.ora_f,letto.minuti_f,
			letto.nomelocale,letto.artista,letto.costo_b_primaf,letto.costo_b_ultimaf,
			letto.n_file,letto.n_posti_perfila,letto.incasso_complessivo);						
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
*	La funzione Menu_modifica_evento permette di stampare il menu' di campi modificabili, e di scegliere quale di questi modificare.
*	@param[out] numero: Variabile che rappresenta il numero del campo da modificare.
*
*	@return numero
*/
int Menu_modifica_evento()
{
	char scelta[2];
	int numero;
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
	
	SetColor(9);
	
	printf("\nScegli quale campo dell'evento modificare\n");
	
	SetConsoleTextAttribute(hConsole, saved_attributes);
	
	do{
	
		printf("\n1) Anno");
    	printf("\n2) Mese");
    	printf("\n3) Giorno");
   		printf("\n4) Ora d'inizio");
    	printf("\n5) Minuti d'inizio");
    	printf("\n6) Ora di fine");
    	printf("\n7) Minuti di fine");
    	printf("\n8) Nome locale");
    	printf("\n9) Nome artista");
    	printf("\n10) Costo del biglietto della prima fila");
    	printf("\n11) Costo del biglietto dell'ultima fila");
    	printf("\n12) Numero di file");
    	printf("\n13) Numero di posti per fila");
		printf("\n\nInserisci la tua scelta: ");
		gets(scelta);
		
		numero = atoi(scelta);
		
		if(numero <1 || numero >13)
		{
			printf("\nErrore, ripetere la scelta.\n");
			system("pause");
			system("CLS");
			BenvenutoTitolo();
		}
		
	}while(numero <1 || numero >13);
    
    return numero;
}

/**
*	La procedura EliminaEvento permette di eliminare determinati eventi all'interno del file "Eventi.csv".
*	@param[in] identificatore: Id evento da controllare per poi, eliminarlo definitivamente.
*
*	@return void
*/
void EliminaEvento(int identificatore)
{
	char scelta[2];
	int numero;
	char riga[200];
	char appoggio[200];
	char stringa_temporanea[200];
	int temp;
	FILE* scrittura;
	FILE* apertura;
	system("CLS");
	BenvenutoTitolo();
	
	do{
		
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
   	    WORD saved_attributes;
    
    	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    	saved_attributes = consoleInfo.wAttributes;
	
		SetColor(9);
		
		printf("\nAttenzione, sei veramente sicuro di voler eliminare l'evento? (Scegli un numero) ");
		
		SetConsoleTextAttribute(hConsole, saved_attributes);
		
		printf("\n1)SI");
		printf("\n2)NO");
		printf("\n\nFai la tua scelta: ");
		gets(scelta); //Controlla che sia un numero e non una lettera o uno spazio.
		
		numero = atoi(scelta);
		
		if(numero <1 || numero >2)
		{
			printf("\nErrore, ripetere la scelta.\n");
			system("pause");
			system("CLS");
			BenvenutoTitolo();
		}
		
	}while(numero <1 || numero >2);
    
   	if(numero==2)
   	{
   		printf("\nStai per essere reindirizzato al menu di ricerca evento.\n");
   		sleep(5);
   		system("CLS");
   		cercaEvento();
   		
	}
	
	else
	{
		scrittura=fopen("File//Eventi2.csv","w");
		apertura=fopen("File//Eventi.csv","r");
				
		if(apertura==NULL || scrittura==NULL)
		{
			printf("\nFile non esistenti.");
		}	
				
		else
				
		{	
			fscanf(apertura,"%s",riga);
						
			strcpy(appoggio,riga);
						
			while(!feof(apertura)) 
			{	  
				strcpy(stringa_temporanea, strtok(riga, ","));
			
				temp=atoi(stringa_temporanea);
							
            	if(temp==identificatore)
            	{
						
				}
										
				else
				{
					fprintf(scrittura,"%s\n",appoggio); 
				}
							
				fscanf(apertura,"%s",riga);
				strcpy(appoggio,riga);
			}	
				
		fclose(apertura);
		fclose(scrittura);
				
		remove("File//Eventi.csv");
		rename("File//Eventi2.csv","File//Eventi.csv");
		}
		
	}
}

/**
*	La unzione ricercaIDEvento permette di ricercare all'interno del file "Eventi.csv", eventi con lo stesso id.
*	@param[in] id_e: Id evento da controllare.
*	@param[out] ritorno: Variabile che segnala la presenza o meno di uno stesso id evento.
*
*	@return ritorno
*/

int ricercaIDEvento(int id_e)
{
	int ritorno=0;
	
	FILE* file;
	
	char id[5];
	char riga[200];
	int temp;
	
	
	if((file=fopen("File//Eventi.csv","r"))==NULL)
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
		fscanf(file,"%s",riga);

		while(!feof(file)) 
		{	
			strcpy(id, strtok(riga, ","));
			temp=atoi(id);
			
            if(id_e==temp) 
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
*	La funzione VisualizzaIncasso permette di visualizzare all'interno del file "Eventi.csv".
*
*	idevento: La variabile idevento che identifichera' l'id dell'evento.
*	incasso_biglietto: La variabile incasso_biglietto determina la cifra da aggiungere all'incassso gia' presente.
*	incasso_totale: variabile che conterra' la somma dell'incasso letto più quello di incasso_biglietto.
*	letto.incasso_complessivo: variabile che conterra' l'incasso letto all'interno del file "Eventi.csv".
*
*	@return void
*/
void VisualizzaIncasso()
{
	FILE* lettura;
	char riga[300];
	char stringa_temporanea[300];
	char* appoggio;
	char* tempdouble;
	int temp;
	int id_evento;
	int controllo=0;
	double incasso_complessivo;

	system("CLS");
	BenvenutoTitolo();
	fflush(stdin);
	printf("Inserisci l'id dell'evento: ");
	scanf("%d",&id_evento); //Controlla che l'id evento sia di 5 caratteri e non contenga spazi.
	fflush(stdin);
	printf("\nRicerca in corso");
	Sleep(700);
    printf(".");
    Sleep(700);
    printf(".");
    Sleep(700);
    printf(".\n");
    Sleep(700);
	
	if((lettura=fopen("File//Eventi.csv","r"))==NULL)
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
		
		fscanf(lettura,"%s",riga);
		
		while(!feof(lettura)) 
		{	
			strcpy(stringa_temporanea, strtok(riga, ","));
			temp=atoi(stringa_temporanea);
			
			if(temp==id_evento)
			{
				controllo=1;
        		appoggio=strtok(NULL,",");
 	 			appoggio=strtok(NULL,",");
 	 			appoggio=strtok(NULL,",");
 	 			appoggio=strtok(NULL,",");
 	 			appoggio=strtok(NULL,",");
 	 			appoggio=strtok(NULL,",");
        		appoggio=strtok(NULL,",");
 	 			appoggio=strtok(NULL,",");
 	 			appoggio=strtok(NULL,",");
 	 			appoggio=strtok(NULL,",");
 	 			appoggio=strtok(NULL,",");
 	 			appoggio=strtok(NULL,",");
        		appoggio=strtok(NULL,",");
        		appoggio=strtok(NULL,",");
        		incasso_complessivo=strtod(appoggio,&tempdouble); //funzione per convertire una stringa in un double		
			}	
			
			
			fscanf(lettura,"%s",riga);
		}
		
		fclose(lettura);
	}
	
	
	if(controllo==1)
	{
		system("CLS");
		BenvenutoTitolo();
		printf("L'evento ricercato, e' stato trovato correttamente.");
		
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    	WORD saved_attributes;
    
    	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    	saved_attributes = consoleInfo.wAttributes;
	
		SetColor(9);

		printf("\n\nL'incassso complessivo equivale a: %.2lf euro.",incasso_complessivo);
		printf("\n\n");
		SetConsoleTextAttribute(hConsole, saved_attributes);
		
		
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
		
		printf("\nL'evento ricercato, non esiste.");
		printf("\n\n");
		SetConsoleTextAttribute(hConsole, saved_attributes);
		
	}
	
}

/**
*	La funzione Istogramma crea un istogramma per visualizzare il numero dei biglietti venduti per ogni evento.
*
*	
*	@return void
*/

void Istogramma()
{
	int vettore[99999]={0};
	char riga[200];
	char stringa_temporanea[200];	
	int i;
	int j;
	int temp;
	int controllo=0;
	FILE* file;
	
	
	printf("Benvenuto nella creazione dell'istogramma degli eventi! \n");
	system("PAUSE");
    
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
			strcpy(stringa_temporanea, strtok(riga, ","));
			strcpy(stringa_temporanea, strtok(NULL, ","));
			temp=atoi(stringa_temporanea);
			
			for(i=0;i<99999;i++)
			{
				if(temp==i)
				{
					vettore[i]++;
				}
			}
			
			fscanf(file,"%s",riga);
		}
				
		
		
		fclose(file);
	}
	
	for(i=0;i<99999;i++)
	{
		if(vettore[i]!=0)
		{
			controllo=1;
		}
	}
	
	if(controllo==1)
	{
		system("CLS");
		BenvenutoTitolo();
		printf("Creazione dell'istrogramma in corso");
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
	
    	SetColor(3);
 
    	printf("\nIstogramma creato correttamente.\n");
   
    	SetConsoleTextAttribute(hConsole, saved_attributes);

    	system("PAUSE");
    	system("CLS");
    	BenvenutoTitolo();
    
    	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    	saved_attributes = consoleInfo.wAttributes;
	
    	SetColor(3);
 
    	printf("\n* = Biglietto venduto \n\n\n");
   
    	SetConsoleTextAttribute(hConsole, saved_attributes);
    	
		for(i=0;i<99999;i++)
		{
			if(vettore[i]!=0)
			{
				printf("\nID %d = ",i);
			
				for(j=0;j<vettore[i];j++)
				{
				
    				GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    				saved_attributes = consoleInfo.wAttributes;
	
    				SetColor(3);
 
    				printf("*");
   
    				SetConsoleTextAttribute(hConsole, saved_attributes);
			
				}
			
				printf("\n");
			}	
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
	
    	SetColor(3);
 
    	printf("Non e' ancora stato prenotato nessun biglietto.");
   
    	SetConsoleTextAttribute(hConsole, saved_attributes);
	}
	
	printf("\n");
	
	system("\n\nPAUSE");
}

