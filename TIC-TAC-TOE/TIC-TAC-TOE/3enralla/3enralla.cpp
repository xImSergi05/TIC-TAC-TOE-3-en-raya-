#include <iostream>
#include "Player1.h"
#include "Player2.h"
using namespace std;

char tablero[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
bool turno1 = true;
char ganador = '_';

void mostrarTablero();
char revisarGanador();
bool realizarJugada(int numero_casilla);

int main() {
    cout << "JUEGO DEL 3 EN RAYA\n";
    Player1 jugador1('X');
    Player2 jugador2('O');

    for (int i = 1; i <= 9; i++) {
        mostrarTablero();
        int casilla;
        if (turno1)
            casilla = jugador1.ferJugada();
        else
            casilla = jugador2.ferJugada();


        if (!realizarJugada(casilla)) continue;
        ganador = revisarGanador();
        if (ganador != '_') break;

    }

        mostrarTablero();

        if (ganador != '_')
            cout << "\nHA GANADO EL JUGADOR " << ganador << "!\n";
        else
            cout << "\nEMPATE!\n";
    
    }

void mostrarTablero() {
    cout << "\nTablero:\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << tablero[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
}

char revisarGanador() {
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2])
            return tablero[i][0];
        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i])
            return tablero[0][i];
    }
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2])
        return tablero[0][0];
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])
        return tablero[0][2];
    return '_';
}

bool realizarJugada(int num) {
    if (num < 1 || num > 9) {
        cout << "Casilla inválida.\n";
        return false;
    }

    int fila = (num - 1) / 3;
    int col = (num - 1) % 3;

    if (tablero[fila][col] == 'X' || tablero[fila][col] == 'O') {
        cout << "Casilla ocupada.\n";
        return false;
    }

    tablero[fila][col] = turno1 ? 'X' : 'O'; // condició ? valor_si_cert : valor_si_fals

    turno1 = !turno1; // canvia el torn
    return true;
}