#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <math.h>

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

// Konstruktor podstawiajacy pod kolejne elementy wartosci z argumentow
    Wektor(double a, double b){
      tab[0]=a, tab[1]=b;
    }

// Konstruktor podstawiajacy pod kolejne elementy wartosci z argumentow
    Wektor(double a, double b, double c, double d, double e){
      tab[0]=a, tab[1]=b, tab[2]=c; tab[3]=d, tab[4]=e;
    }

// Deklaracja metody przeciazajacej operator indeksowania
    TYP & operator[] (int indeks);

// Metoda przeciazajaca operator indeksowania dla dotepu do elementow tablicy wektora (stale wartosci)
    const TYP & operator[] (int indeks) const{
      return tab[indeks];
    }
    
// Deklaracja metody przeciazajacej operator dodawania
    Wektor operator + (const Wektor & W2) const;
  
// Deklaracja metody przeciazajacej operator odejmowania
    Wektor operator - (const Wektor & W2) const;

// Metoda przeciazajaca operator mnozenia dla mnozenia wektora z klasy oraz podane jako argument (mnozenie skalarne)
    TYP operator * (const Wektor & W2) const;

/******************************************

// Metoda obliczajaca dlugosc wektora
    double dlugosc() const{
      return sqrt(pow(tab[0], 2) + pow(tab[1], 2) + pow(tab[2], 2));
    }


*******************************************/
};

// Deklaracja przeciazenia operatora wczytywania dlawektora
template <class TYP, int ROZMIAR>
std::istream & operator >> (std::istream &Strm, Wektor<TYP, ROZMIAR> &W);

// Deklaracja przeciazenia operatora wyswietlania dla wektora
template <class TYP, int ROZMIAR>
std::ostream & operator << (std::ostream &Strm, const Wektor<TYP, ROZMIAR> &W);

#endif
