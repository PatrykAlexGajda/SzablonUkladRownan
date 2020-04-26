/*

#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>

// Klasa Macierzy, przechowuje tablice jednowymiarowa o ROZMIAR elementach 
// Deklaruje metody operujace na polu macierzy

class Macierz {
  
    Wektor tab[ROZMIAR];

  public:

// Konstruktor zerujacy elementy macierzy
    Macierz(); 

// Konstruktor podstawiajacy pod kolejne elementy macierzy liczby podane w argumentach
    Macierz(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3);


// konstruktor podstawiacy pod kolejne wierze macierzy wektory z argumentow
    Macierz(Wektor W1, Wektor W2, Wektor W3);

// Przeciazenie operatora indeksujacego [], pozwala dostac sie do konkretnego elementu lub wektora z macierzy (stale wartosci)
    const Wektor & operator[] (int indeks) const{
      return tab[indeks];
    }

// -||- (niestale)
    Wektor & operator[] (int indeks){

    if (indeks < 0 || indeks >= ROZMIAR) { // Blad w przypadku podania zlego indeksu
      std::cerr << "BLAD: Zly indeks macierzy."; 
      exit(1);
    }    

    return tab[indeks];
    }

// Przeciazenie operatora indeksujacego (), pozwala dostac sie do konkretnego elementu jednego z wektorow tworzacych macierz (sale wartosci)
    const double & operator() (int ind1, int ind2) const{
      return tab[ind1][ind2];
    }

// -||- (niestale)
    double & operator() (int ind1, int ind2){

    if (ind1 < 0 || ind1 >= ROZMIAR || ind2 < 0 || ind2 >= ROZMIAR) { // Blad w przypadku podania zlych indeksow
        std::cerr << "BLAD: Zle indeksy macierzy."; 
        exit(1);
    }

    return tab[ind1][ind2];
    }

// Deklaracja metody wyliczajacej wyznacznik macierzy (metoda Laplace'a)
    double WyznacznikLaplace() const;
// Deklaracja metody transponujacej macierz
    const Macierz Transpozycja() const;
// Deklaracja metody odwracajacej macierz
    const Macierz Odwrotnosc() const;

// Deklaracja przeciazenia operatora dodawania macierzy
    Macierz operator + (const Macierz & W) const; 
// Deklaracej przeciazenia operatora odewjmowania maceirzy
    Macierz operator - (const Macierz & W) const; 
// Deklaracja przeziazenia operatora mnozenia macierzy przez macierz
    Macierz operator * (const Macierz & W) const; 
// Deklaracja przeciazenia operatora mnozenia maceirzy przez wektor
    Wektor operator * (const Wektor & W) const;
};

// Deklaracja przeciazenia operatora wczytywania dla maceirzy
std::istream& operator >> (std::istream &Strm, Macierz &M);

// Deklaracja przeciazenia operatora wyswietlania dla macierzy
std::ostream& operator << (std::ostream &Strm, const Macierz &M);

#endif

*/
