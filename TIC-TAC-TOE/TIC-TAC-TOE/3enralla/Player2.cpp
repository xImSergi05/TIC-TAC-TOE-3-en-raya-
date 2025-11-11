#include "Player2.h"


Player2::Player2(char s)
{
	simbolo = s;
}

int Player2::ferJugada()
{
    int casella;

    while (true) {
        cout << "Turno de " << simbolo << ". Introduce la casilla (1-9): ";
        cin >> casella;


        if (casella < 1 || casella > 9) {
            cout << "Casilla fuera del rango. Escribr un numero entre 1 y 9.\n";
            continue;
        }

        // Entrada correcta
        break;
    }

    return casella;
}