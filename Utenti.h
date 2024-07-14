#ifndef UTENTI_H_INCLUDED
#define UTENTI_H_INCLUDED

/** @brief Dimensione massima di ogni stringa.*/
#define MAX 50

/** Struct utente [Utilizzata per gestire ogni utente all'interno del file "Utenti.csv".] */
struct utente
{
    char nickname[MAX];
    char email[MAX];
    char cognome[MAX];
    char nome[MAX];
    char genere[MAX];
    char datan[MAX];
    char ntelefono[MAX];
	char gmusicale[MAX];
};

/** @struct utente
 *  @brief Questa struttura verra' utlizzata per contenere tutti i dati di ogni utente.
*/
void RegistraUtente();
void modificadati();
void menug();
int ricercaN(char[]);
void stampautenti(char[]);

#endif // UTENTI_H_INCLUDED
