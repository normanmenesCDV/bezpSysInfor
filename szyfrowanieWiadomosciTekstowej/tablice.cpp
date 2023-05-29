#include "tablice.h"

void wyswietlTablice(char** tab, const int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}