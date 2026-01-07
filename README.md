# Esercizio-Tombola
esercizio classroom informatica c++
esercizio repository 

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    srand(time(0));

    // cartelle dei giocatori (2 giocatori)
    int cartella1[3][10] = {0};
    int cartella2[3][10] = {0};

    // tabellone tombola
    bool estratti[91] = {false};

    int numero, riga, colonna;
    bool presente;

    // ==========================
    // GENERAZIONE CARTELLA 1
    // ==========================
    for (riga = 0; riga < 3; riga++) {
        int inseriti = 0;
        while (inseriti < 5) {
            numero = rand() % 90 + 1;
            colonna = (numero == 90) ? 8 : numero / 10;

            if (cartella1[riga][colonna] == 0) {
                presente = false;

                // controllo duplicati
                for (int i = 0; i < 3; i++)
                    if (cartella1[i][colonna] == numero)
                        presente = true;

                if (!presente) {
                    cartella1[riga][colonna] = numero;
                    inseriti++;
                }
            }
        }
    }

    // ==========================
    // GENERAZIONE CARTELLA 2
    // ==========================
    for (riga = 0; riga < 3; riga++) {
        int inseriti = 0;
        while (inseriti < 5) {
            numero = rand() % 90 + 1;
            colonna = (numero == 90) ? 8 : numero / 10;

            if (cartella2[riga][colonna] == 0) {
                presente = false;

                for (int i = 0; i < 3; i++)
                    if (cartella2[i][colonna] == numero)
                        presente = true;

                if (!presente) {
                    cartella2[riga][colonna] = numero;
                    inseriti++;
                }
            }
        }
    }

    // ==========================
    // STAMPA CARTELLE
    // ==========================
    cout << "\nCARTELLA GIOCATORE 1\n";
    for (riga = 0; riga < 3; riga++) {
        for (colonna = 0; colonna < 10; colonna++) {
            if (cartella1[riga][colonna] == 0)
                cout << "   ";
            else
                cout << cartella1[riga][colonna] << " ";
        }
        cout << endl;
    }

    cout << "\nCARTELLA GIOCATORE 2\n";
    for (riga = 0; riga < 3; riga++) {
        for (colonna = 0; colonna < 10; colonna++) {
            if (cartella2[riga][colonna] == 0)
                cout << "   ";
            else
                cout << cartella2[riga][colonna] << " ";
        }
        cout << endl;
    }

    // ==========================
    // ESTRAZIONE NUMERI
    // ==========================
    int tombola1 = 0;
    int tombola2 = 0;

    while (true) {

        do {
            numero = rand() % 90 + 1;
        } while (estratti[numero]);

        estratti[numero] = true;
        colonna = (numero == 90) ? 8 : numero / 10;

        cout << "\nEstratto: " << numero << endl;

        // segna cartella 1
        for (riga = 0; riga < 3; riga++)
            if (cartella1[riga][colonna] == numero)
                cartella1[riga][colonna] = -1;

        // segna cartella 2
        for (riga = 0; riga < 3; riga++)
            if (cartella2[riga][colonna] == numero)
                cartella2[riga][colonna] = -1;

        // controllo tombola
        tombola1 = tombola2 = 0;

        for (riga = 0; riga < 3; riga++)
            for (colonna = 0; colonna < 10; colonna++) {
                if (cartella1[riga][colonna] <= 0) tombola1++;
                if (cartella2[riga][colonna] <= 0) tombola2++;
            }

        if (tombola1 == 30) {
            cout << "\nTOMBOLA GIOCATORE 1!\n";
            break;
        }

        if (tombola2 == 30) {
            cout << "\nTOMBOLA GIOCATORE 2!\n";
            break;
        }
    }

    return 0;
}
