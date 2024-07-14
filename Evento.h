#ifndef EVENTO_H_INCLUDED
#define EVENTO_H_INCLUDED

/** @brief Dimensione massima di ogni stringa.*/
#define MAX 50 

/** Struct evento [Utilizzata per gestire ogni evento all'interno del file "Eventi.csv".] */
struct evento 
{
	int id;
	int anno;
	char mese[MAX];
	int giorno;
	int ora_i;
	int minuti_i;
	int ora_f;
	int minuti_f;
	char nomelocale[MAX];
	char artista[MAX];
	double costo_b_primaf;
	double costo_b_ultimaf;
	int n_file;
	int n_posti_perfila;
	double incasso_complessivo;
};

/** @struct evento
 *  @brief Questa struttura verra' utlizzata per contenere tutti i dati di ogni evento.
*/

void registraEvento();
int ricercaEvento(int,int,char[],int,char[],char[]);
void cercaEvento();
void ModificaEvento(int);
int Menu_modifica_evento();
void EliminaEvento(int);
int ricercaIDEvento(int);
void VisualizzaIncasso();
void Istogramma();

#endif // EVENTO_H_INCLUDED
