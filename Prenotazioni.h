#ifndef PRENOTAZIONI_H_INCLUDED
#define PRENOTAZIONI_H_INCLUDED

/** @brief Dimensione massima di ogni stringa.*/
#define MAX 50

/** Struct prenotazione [Utilizzata per registrare ogni prenotazione all'interno del file "Prenotazioni.csv".] */
struct prenotazione
{
	int idp; 
	int id_e;
	char nick[MAX];
	int fila;
	int n_pol;
	double importo_p;	
};
/** @struct prenotazione
 *  @brief Questa struttura verra' utlizzata per contenere tutte le prenotazioni registrate di ogni evento per ogni utente.
*/

/** Struct listautenti [Utilizzata per gestire la stampa di ogni prenotazione effettuata da un determinato utente.] */
struct listautenti
{
	char nickname[MAX];
	int id_evento;
	int anno;
	int mese;
	int giorno;
	double costo_biglietto;
};
/** @struct listautenti
 *  @brief Questa struttura verra' utlizzata per gestire la stampa di ogni prenotazione effettuata da un determinato utente.
*/


void venditaBiglietto();
int ControllaFilaPoltrona(int,int,int,int,int);
int ControllaPosti(int);
int ricercaPrenotazione(int);
void AggiornaIncasso(int,double);
void ControlloPoltrona();
void StampaUtentiFiltro();
void StampaPrenotati();
int ControlloMesi(char []);


#endif // PRENOTAZIONI_H_INCLUDED
