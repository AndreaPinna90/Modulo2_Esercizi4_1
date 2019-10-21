/*Scrivere un programma in cui viene definita la struttura Auto con i seguenti campi: anno immatricolazione,
 * cilindrata, carburante (definire un enumerazione benzina, metano, diesel), numero cavalli.
 * Scrivere poi il codice che generi casualmente i valori relativi a due variabili di tipo Auto e
 * le stampi a video dicendo con un messaggio aggiuntivo se la cilindrata è maggiore di 900 (usare l’operatore ternario).
 * Non devono essere presenti magic number (fare quindi uso di macro opportune), commentare opportunatamente tutto il codice.*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define ANNO_MIN 1980
#define ANNO_MAX 2019
#define CILINDRATA_MIN 600
#define CILINDRATA_MAX 1200
#define CAVALLI_MIN 100
#define CAVALLI_MAX 200

typedef enum {BENZINA, METANO, DIESEL} Carburante;

typedef struct {
    int annoImmatricolazione;
    int cilindrata;
    Carburante tipoCarburante;
    int numeroCavalli;
} Auto;

int main() {

    srand(time(NULL));

    Auto alfaMito;
    Auto fiatPunto;
    int sogliaCilindrata = 900; //soglia della cilindrata superata la quale va stampato il risultato

    //Randomizzazione dei valori delle 2 variabili di tipo Auto
    alfaMito.annoImmatricolazione = ANNO_MIN + rand() % (ANNO_MAX - ANNO_MIN + 1);
    alfaMito.cilindrata = CILINDRATA_MIN + rand() % (CILINDRATA_MAX - CILINDRATA_MIN + 1);
    alfaMito.tipoCarburante = 0 + rand() % (2 - 0 + 1); //0, 1 e 2 rappresentano i valori della enumerazione Carburante
    alfaMito.numeroCavalli = CAVALLI_MIN + rand() % (CAVALLI_MAX - CAVALLI_MIN + 1);

    fiatPunto.annoImmatricolazione = ANNO_MIN + rand() % (ANNO_MAX - ANNO_MIN + 1);
    fiatPunto.cilindrata = CILINDRATA_MIN + rand() % (CILINDRATA_MAX - CILINDRATA_MIN + 1);
    fiatPunto.tipoCarburante = 0 + rand() % (2 - 0 + 1);
    fiatPunto.numeroCavalli = CAVALLI_MIN + rand() % (CAVALLI_MAX - CAVALLI_MIN + 1);

    //Stampa dei valori delle 2 variabili di tipo Auto
    printf("\nCARATTERISTICHE ALFA MITO");
    printf("\nAnno di immatricolazione: %d", alfaMito.annoImmatricolazione);
    printf("\nCarburante [0=BENZINA, 1=METANO, 2=DIESEL]: %d", alfaMito.tipoCarburante);
    printf("\nNumero Cavalli: %d", alfaMito.numeroCavalli);
    (alfaMito.cilindrata > sogliaCilindrata) > false ? printf("\nCilindrata: %d", alfaMito.cilindrata) : printf(""); //operatore ternario: se la cilindrata è maggiore del valore soglia, stampalo

    printf("\n\nCARATTERISTICHE FIAT PUNTO");
    printf("\nAnno di immatricolazione: %d", fiatPunto.annoImmatricolazione);
    printf("\nCarburante [0=BENZINA, 1=METANO, 2=DIESEL]: %d", fiatPunto.tipoCarburante);
    printf("\nNumero Cavalli: %d", fiatPunto.numeroCavalli);
    (fiatPunto.cilindrata > sogliaCilindrata) > false ? printf("\nCilindrata: %d", fiatPunto.cilindrata) : printf(""); //operatore ternario: se la cilindrata è maggiore del valore soglia, stampalo

    return 0;
}
