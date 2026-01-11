#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    // Inizializza il generatore di numeri casuali
    srand(time(NULL));

    
    int cartella1[3][9];
    int cartella2[3][9];
    bool tabellone[91]; // Da 1 a 90
    bool vittoria = false;
    int numeroEstratto;

    // Inizializziamo il tabellone a "false"
    for (int i = 0; i <= 90; i++) {
        tabellone[i] = false;
    }

    // --- GENERAZIONE CARTELLA 1 ---
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) cartella1[i][j] = 0; 
        int inseriti = 0;
        while (inseriti < 5) {
            int col = rand() % 9;
            if (cartella1[i][col] == 0) {
                
                if (col == 0) {
                    cartella1[i][col] = rand() % 9 + 1; // 1-9
                } else if (col == 1) {
                    cartella1[i][col] = rand() % 10 + 10; // 10-19
                } else if (col == 2) {
                    cartella1[i][col] = rand() % 10 + 20; // 20-29
                } else if (col == 3) {
                    cartella1[i][col] = rand() % 10 + 30; // 30-39
                } else if (col == 4) {
                    cartella1[i][col] = rand() % 10 + 40; // 40-49
                } else if (col == 5) {
                    cartella1[i][col] = rand() % 10 + 50; // 50-59
                } else if (col == 6) {
                    cartella1[i][col] = rand() % 10 + 60; // 60-69
                } else if (col == 7) {
                    cartella1[i][col] = rand() % 10 + 70; // 70-79
                } else if (col == 8) {
                    cartella1[i][col] = rand() % 11 + 80; // 80-90
                }
                inseriti++;
            }
        }
    }

    // --- GENERAZIONE CARTELLA 2 ---
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) cartella2[i][j] = 0;
        int inseriti = 0;
        while (inseriti < 5) {
            int col = rand() % 9;
            if (cartella2[i][col] == 0) {
                // Logica semplificata con IF-ELSE e RAND diretto
                if (col == 0) {
                    cartella2[i][col] = rand() % 9 + 1;
                } else if (col == 1) {
                    cartella2[i][col] = rand() % 10 + 10;
                } else if (col == 2) {
                    cartella2[i][col] = rand() % 10 + 20;
                } else if (col == 3) {
                    cartella2[i][col] = rand() % 10 + 30;
                } else if (col == 4) {
                    cartella2[i][col] = rand() % 10 + 40;
                } else if (col == 5) {
                    cartella2[i][col] = rand() % 10 + 50;
                } else if (col == 6) {
                    cartella2[i][col] = rand() % 10 + 60;
                } else if (col == 7) {
                    cartella2[i][col] = rand() % 10 + 70;
                } else if (col == 8) {
                    cartella2[i][col] = rand() % 11 + 80;
                }
                inseriti++;
            }
        }
    }

    // --- CICLO DI GIOCO ---
    while (!vittoria) {
        // Pulizia schermo ANSI
        cout << "\033[2J\033[H";

        // STAMPA TABELLONE
        cout << "\033[1;36m=== TABELLONE TOMBOLA 2026 ===\033[0m\n";
        for (int i = 1; i <= 90; i++) {
            if (tabellone[i]) cout << "\033[1;31mXX \033[0m"; 
            else {
                if (i < 10) cout << "0";
                cout << i << " ";
            }
            if (i % 10 == 0) cout << "\n";
        }

        // STAMPA CARTELLA 1
        cout << "\n\033[1;33mGIOCATORE 1:\033[0m\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 9; j++) {
                if (cartella1[i][j] == 0) cout << "    ";
                else {
                    if (tabellone[cartella1[i][j]]) cout << "\033[1;32m"; 
                    if (cartella1[i][j] < 10) cout << " ";
                    cout << cartella1[i][j] << "\033[0m  ";
                }
            }
            cout << "\n";
        }

        // STAMPA CARTELLA 2
        cout << "\n\033[1;33mGIOCATORE 2:\033[0m\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 9; j++) {
                if (cartella2[i][j] == 0) cout << "    ";
                else {
                    if (tabellone[cartella2[i][j]]) cout << "\033[1;32m";
                    if (cartella2[i][j] < 10) cout << " ";
                    cout << cartella2[i][j] << "\033[0m  ";
                }
            }
            cout << "\n";
        }

        cout << "\nPremi INVIO per estrarre...";
        cin.get();

        do {
            numeroEstratto = rand() % 90 + 1;
        } while (tabellone[numeroEstratto]);

        tabellone[numeroEstratto] = true;

        // CONTROLLO VINCITA
        int punti1 = 0;
        int punti2 = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 9; j++) {
                if (cartella1[i][j] != 0 && tabellone[cartella1[i][j]]) punti1++;
                if (cartella2[i][j] != 0 && tabellone[cartella2[i][j]]) punti2++;
            }
        }
        
        if (punti1 == 15) {
            cout << "\033[1;32m\nIL GIOCATORE 1 HA FATTO TOMBOLA!\033[0m\n";
            vittoria = true;
        } else if (punti2 == 15) {
            cout << "\033[1;32m\nIL GIOCATORE 2 HA FATTO TOMBOLA!\033[0m\n";
            vittoria = true;
        }
    }

    return 0;
}

