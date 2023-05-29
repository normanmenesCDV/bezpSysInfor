#include "szyfrPrzestawieniowy.h"
#include "ciagiZnakow.h"

int zwrocN(const size_t dlugosc, const bool czyWiadomoscJawna) {
    if (czyWiadomoscJawna == true) return (int)ceil(sqrt(dlugosc));
    else return (int)sqrt(dlugosc);
}

void dopelnijTablice(char** tab, int i, int j, const int n) {
    for (; i < n; ++i) {
        for (; j < n; ++j) {
            tab[i][j] = randChar();
        }
    }
}

void uzupelnijTablice(char** tab, const string tekst, const int n) {
    int idx_tekst = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j, ++idx_tekst) {
            tab[i][j] = tekst[idx_tekst];
            if (idx_tekst == tekst.length()) {
                dopelnijTablice(tab, i, j, n);
                break;
            }
        }
    }
}

string zwrocPrzeksztalconyTekst(char** tab, const int n) {
    string tekst;
    int idx_tekst = 0;
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i, ++idx_tekst) {
            tekst += tab[i][j];
        }
    }
    return tekst;
}

void zaszyfrujTekst() {
    system("CLS");
    cout << "Szyfrowanie wiadomosci" << endl;
    string tekst_jawny;
    cout << "Podaj tekst jawny: " << endl;
    getline(cin, tekst_jawny);
    int n = zwrocN(tekst_jawny.length(), true);

    // stworzenie tablicy
    char** tab = new char* [n];
    for (int i = 0; i < n; ++i)
        tab[i] = new char[n];
    uzupelnijTablice(tab, tekst_jawny, n);
    wyswietlTablice(tab, n);

    // zwrócenie zaszyfrowanego ci¹gu
    string tekst_zaszyfrowany = zwrocPrzeksztalconyTekst(tab, n);
    cout << "Tekst zaszyfrowany: " << tekst_zaszyfrowany << endl;
}

void odszyfrujTekst() {
    system("CLS");
    cout << "Odszyfrowanie wiadomosci" << endl;
    string tekst_zaszyfrowany;
    cout << "Podaj tekst zaszyfrowany: " << endl;
    getline(cin, tekst_zaszyfrowany);
    int n = zwrocN(tekst_zaszyfrowany.length(), false);
    if (n * n != tekst_zaszyfrowany.length()) {
        cout << "Nieprawidlowa dlugosc zaszyforwanego ciagu!" << endl;
        exit(1);
    }

    // stworzenie tablicy
    char** tab = new char* [n];
    for (int i = 0; i < n; ++i)
        tab[i] = new char[n];
    uzupelnijTablice(tab, tekst_zaszyfrowany, n);
    wyswietlTablice(tab, n);

    // zwrócenie odszyfrowanego ci¹gu
    string tekst_jawny = zwrocPrzeksztalconyTekst(tab, n);
    cout << "Tekst odszyfrowany: " << tekst_jawny << endl;
}
