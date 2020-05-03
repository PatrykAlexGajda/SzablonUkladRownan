#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include "Wektor.hh"

// Klasa Macierzy, przechowuje tablice jednowymiarowa o ROZMIAR elementach 
// Deklaruje metody operujace na polu macierzy

template <class TYP, int ROZMIAR>
class Macierz {
  
    Wektor<TYP, ROZMIAR> tab[ROZMIAR];

  public:

// Konstruktor zerujacy elementy macierzy
    Macierz(); 

// Przeciazenie operatora indeksujacego [], pozwala dostac sie do konkretnego elementu lub wektora z macierzy (stale wartosci)
    const Wektor<TYP, ROZMIAR> & operator[] (int indeks) const{
      return tab[indeks];
    }

// -||- (niestale)
    Wektor<TYP, ROZMIAR> & operator[] (int indeks){
    if (indeks < 0 || indeks >= ROZMIAR) { // Blad w przypadku podania zlego indeksu
      std::cerr << "BLAD: Zly indeks macierzy."; 
      exit(1);
    }    
    return tab[indeks];
    }

// Przeciazenie operatora indeksujacego (), pozwala dostac sie do konkretnego elementu jednego z wektorow tworzacych macierz (sale wartosci)
    const TYP & operator() (int ind1, int ind2) const{
      return tab[ind1][ind2];
    }

// -||- (niestale)
    TYP & operator() (int ind1, int ind2){
    if (ind1 < 0 || ind1 >= ROZMIAR || ind2 < 0 || ind2 >= ROZMIAR) { // Blad w przypadku podania zlych indeksow
        std::cerr << "BLAD: Zle indeksy macierzy."; 
        exit(1);
    }
    return tab[ind1][ind2];
    }

// Deklaracja metody transponujacej macierz
    const Macierz Transpozycja() const;
// Deklaracja metody wyliczajacej wyznacznik macierzy (metoda Laplace'a)
    TYP WyznacznikGauss() const;
// Deklaracja metody odwracajacej macierz
    const Macierz Odwrotnosc() const;

// Deklaracja przeciazenia operatora dodawania macierzy
    Macierz operator + (const Macierz & M) const; 
// Deklaracej przeciazenia operatora odewjmowania maceirzy
    Macierz operator - (const Macierz & M) const; 
// Deklaracja przeziazenia operatora mnozenia macierzy przez macierz
    Macierz operator * (const Macierz & M) const; 
// Deklaracja przeciazenia operatora mnozenia maceirzy przez wektor
    Wektor<TYP, ROZMIAR> operator * (const Wektor<TYP, ROZMIAR> & W) const;
};

// Deklaracja przeciazenia operatora wczytywania dla maceirzy
template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Macierz<TYP, ROZMIAR> &M);

// Deklaracja przeciazenia operatora wyswietlania dla macierzy
template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Macierz<TYP, ROZMIAR> &M);

#endif
