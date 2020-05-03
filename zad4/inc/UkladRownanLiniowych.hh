#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"

// Klasa ukladu rownan liniowych, przechowuje macierz glowna ukladu oraz wektor wyrazow wolnych
// Deklaruje metody operujace na polach tej klasy 
template <class TYP, int ROZMIAR>
class UkladRownanLiniowych {

  Macierz<TYP, ROZMIAR> A;
  Wektor<TYP, ROZMIAR> b;

public:

// Konstruktor tworzacy pola wyzerowanej macierzy oraz wyzerowanego wektora
  UkladRownanLiniowych(){ 
    Macierz<TYP, ROZMIAR> A();
    Wektor<TYP, ROZMIAR> b();  
  }

// Konstruktor podstawiajacy wczytane dane do pol odpowiednich pol klasy
  UkladRownanLiniowych(Macierz<TYP, ROZMIAR> AA, Wektor<TYP, ROZMIAR> bb) : A(AA), b(bb){ 
    A = AA;
    b = bb;
  }

// Daje dostep do macierzy poza metodami klasy
  const Macierz<TYP, ROZMIAR> & get_A() const{ 
    return A;
  }

// Daje dostep do wektora poza metodami klasy
  const Wektor<TYP, ROZMIAR> & get_b() const{
    return b;
  }

// Daje mozliwosc podstawienia wczytanej macierzy pod pole w klasie
  void set_A(const Macierz<TYP, ROZMIAR> & AA){
    A=AA;    
  }

// Daje mozliwosc podstawienia wczytanego wektora pod pole w klasie
  void set_b(const Wektor<TYP, ROZMIAR> & bb){
    b=bb;
  }

// Deklaracja metody wyliczajacej niewiadome ukladu rownan
  Wektor<TYP, ROZMIAR> Oblicz() const;
};

// Deklaracja przeciazenia operatora wczytywania ukladu rownan
template <class TYP, int ROZMIAR>
std::istream & operator >> (std::istream &strm, UkladRownanLiniowych<TYP, ROZMIAR> &UklRown);

// Deklaracja przeciazenia operatora wyswietlania ukladu rownan
template <class TYP, int ROZMIAR>
std::ostream & operator << ( std::ostream &strm, const UkladRownanLiniowych<TYP, ROZMIAR> &UklRown);

#endif



