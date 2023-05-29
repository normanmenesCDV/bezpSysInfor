#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "tablice.h"
using namespace std;

int zwrocN(const size_t dlugosc, const bool czyWiadomoscJawna);
void dopelnijTablice(char** tab, int i, int j, const int n);
void uzupelnijTablice(char** tab, const string tekst, const int n);
string zwrocPrzeksztalconyTekst(char** tab, const int n);
void zaszyfrujTekst();
void odszyfrujTekst();
