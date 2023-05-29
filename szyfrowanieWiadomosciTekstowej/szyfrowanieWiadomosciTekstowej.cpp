#include <iostream>
#include "szyfrPrzestawieniowy.h"

using namespace std;

int main()
{
    cout << "MENU\n"
        << "1. Zaszyfruj wiadomosc\n"
        << "2. Odszyfruj wiadomosc\n";
    cout << "Wybrana opcja: ";
    char x;
    cin >> x;
    cin.ignore();

    switch (x) {
    case '1':
        zaszyfrujTekst();
        break;
    case '2':
        odszyfrujTekst();
        break;
    default:
        cout << "Podano zly numer" << endl;
        break;
    }
}
