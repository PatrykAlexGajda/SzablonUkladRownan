#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <math.h>
#include "LZespolona.hh"

// Klasa wektora, przechowuje pole tablicy jednowymiarowej o okreslonej w ROZMIAR ilosci elementow
// Deklaruje metody operujace na tej tablicy

template <class TYP, int ROZMIAR>
class Wektor {
  
    TYP tab[ROZMIAR];

  public:

// Konstruktor zerujacy elementy tablicy
    Wektor(){
      for(int i=0; i<ROZMIAR; i++){
        tab[i] = 0;
      }
    }

// Metoda przeciazajaca operator indeksowania dla dotepu do elementow tablicy wektora (stale wartosci)
    const TYP & operator[] (int indeks) const{
      return tab[indeks];
    }

// Deklaracja metody przeciazajacej operator indeksowania
    TYP & operator[] (int indeks);

// Naglowki przeciazen operatorow dzialajacych na wektorze
    Wektor operator + (const Wektor & W2) const;
    Wektor operator - (const Wektor & W2) const;
    TYP operator * (const Wektor & W2) const;
    Wektor operator / (const double & d) const;
};

// Deklaracja przeciazenia operatora wczytywania dlawektora
template <class TYP, int ROZMIAR>
std::istream & operator >> (std::istream &Strm, Wektor<TYP, ROZMIAR> &W);

// Deklaracja przeciazenia operatora wyswietlania dla wektora
template <class TYP, int ROZMIAR>
std::ostream & operator << (std::ostream &Strm, const Wektor<TYP, ROZMIAR> &W);

#endif
