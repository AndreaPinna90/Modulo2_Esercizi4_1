/*Scrivere un programma in cui viene definita la struttura Auto con i seguenti campi: anno immatricolazione,
 * cilindrata, carburante (definire un enumerazione benzina, metano, diesel), numero cavalli.
 * Scrivere poi il codice che generi casualmente i valori relativi a due variabili di tipo Auto e
 * le stampi a video dicendo con un messaggio aggiuntivo se la cilindrata è maggiore di 900 (usare l’operatore ternario).
 * Non devono essere presenti magic number (fare quindi uso di macro opportune), commentare opportunatamente tutto il codice.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ANNO_MIN 1980
#define ANNO_MAX 2019
#define CILINDRATA_MIN 600
#define CILINDRATA_MAX 1200
#define CAVALLI_MIN 100
#define CAVALLI_MAX 200
#define ENUM_CARBURANTE 3
#define SOGLIA_CILINDRATA 900 //soglia della cilindrata superata la quale va stampato il risultato

typedef enum {BENZINA, METANO, DIESEL} Carburante; //definisco il nuovo tipo Carburante

typedef struct {
    int annoImmatricolazione;
    int cilindrata;
    Carburante tipoCarburante;
    int numeroCavalli;
} Auto; //definisco la struttura Auto

int main() {

    Auto alfaMito, fiatPunto; //definisco le due variabili di tipo Auto

    srand(time(NULL));

    //Randomizzazione dei valori delle 2 variabili di tipo Auto
    alfaMito.annoImmatricolazione = ANNO_MIN + rand() % (ANNO_MAX - ANNO_MIN + 1);
    alfaMito.cilindrata = CILINDRATA_MIN + rand() % (CILINDRATA_MAX - CILINDRATA_MIN + 1);
    alfaMito.tipoCarburante = rand() % ENUM_CARBURANTE;
    alfaMito.numeroCavalli = CAVALLI_MIN + rand() % (CAVALLI_MAX - CAVALLI_MIN + 1);

    fiatPunto.annoImmatricolazione = ANNO_MIN + rand() % (ANNO_MAX - ANNO_MIN + 1);
    fiatPunto.cilindrata = CILINDRATA_MIN + rand() % (CILINDRATA_MAX - CILINDRATA_MIN + 1);
    fiatPunto.tipoCarburante = rand() % ENUM_CARBURANTE;
    fiatPunto.numeroCavalli = CAVALLI_MIN + rand() % (CAVALLI_MAX - CAVALLI_MIN + 1);

    //Stampa dei valori delle 2 variabili di tipo Auto
    printf("\nCARATTERISTICHE ALFA MITO");
    printf("\nAnno di immatricolazione: %d", alfaMito.annoImmatricolazione);
    printf("\nCarburante [0=BENZINA, 1=METANO, 2=DIESEL]: %d", alfaMito.tipoCarburante);
    printf("\nNumero Cavalli: %d", alfaMito.numeroCavalli);
    alfaMito.cilindrata > SOGLIA_CILINDRATA ? printf("\nCilindrata: %d", alfaMito.cilindrata) : printf(""); //operatore ternario: se la cilindrata è maggiore del valore soglia, stampalo

    printf("\n\nCARATTERISTICHE FIAT PUNTO");
    printf("\nAnno di immatricolazione: %d", fiatPunto.annoImmatricolazione);
    printf("\nCarburante [0=BENZINA, 1=METANO, 2=DIESEL]: %d", fiatPunto.tipoCarburante);
    printf("\nNumero Cavalli: %d", fiatPunto.numeroCavalli);
    fiatPunto.cilindrata > SOGLIA_CILINDRATA ? printf("\nCilindrata: %d", fiatPunto.cilindrata) : printf(""); //operatore ternario: se la cilindrata è maggiore del valore soglia, stampalo

    return 0;
}
