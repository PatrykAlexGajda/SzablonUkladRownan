#include "LZespolona.hh"
#include <iostream>
#include <math.h>

LZespolona LZespolona::operator=(double a)
{
  re = a;
  im = 0;
  return *this;
}

LZespolona LZespolona::operator+=(LZespolona Skl)
{

  re = re + Skl.re;
  im = im + Skl.im;

  return Skl;
}

LZespolona LZespolona::operator*(double r)
{
  re = re * r;
  im = im * r;
  return *this;
}

/* Funkcja tworzy liczbe zespolona wczytujac do struktury dwie liczby rzeczywiste: czesc rzeczywista i zespolona. 
  Funkcja zwraca utworzona liczbe zespolona*/

LZespolona Utworz(double x, double y)
{
  LZespolona liczba_zesp;
  liczba_zesp.re = x;
  liczba_zesp.im = y;

  return liczba_zesp;
}

/* Funkcja tworzy sprzezenie liczby zespolonej dajac czesci zespolonej znak przeciwny.
  Funkcja zwraca sprzezenie podanej jako parametr liczby zespolonej. */

LZespolona Sprzezenie(LZespolona Skl)
{
  LZespolona Wynik;

  Wynik.re = Skl.re;
  Wynik.im = -Skl.im;
  return Wynik;
}

/* Funkcja tworzy modul podanej liczby zespolonej.
  Zwraca ten modul jako liczba juz rzeczywista. */

double Modul(LZespolona Skl)
{
  double Wynik;
  Wynik = sqrt((Skl.re * Skl.re) + (Skl.im * Skl.im));
  return Wynik;
}

/* Funkcja przeciaza operator >> aby mogl on wczytywac okreslona postac liczby zespolonej.
  Jesli wczytany zapis nie bedzie taki jaki powinien funkcja odpowiednio ustawi blad wczytania.
  Funkcja zwraca strumien z pierwszego parametru.  */

std::istream &operator>>(std::istream &str, LZespolona &zesp)
{
  char znak;
  str >> znak;
  if (znak != '(')
  {
    str.setstate(std::ios::failbit);
  }
  str >> zesp.re;
  str >> zesp.im;
  str >> znak;
  if (znak != 'i')
  {
    str.setstate(std::ios::failbit);
  }
  str >> znak;
  if (znak != ')')
  {
    str.setstate(std::ios::failbit);
  }
  return str;
}

/* Funkcja przeciaza operator << aby mogl on wypisywac na standardowe wyjscie zapis liczby zespolonej
  Funkcja zwraca ten zapis. */

std::ostream &operator<<(std::ostream &str, const LZespolona &zesp)
{
  return str << "(" << zesp.re << std::showpos << zesp.im << std::noshowpos << "i)";
}

/* Funkcja przeciaza operator + aby mogl on dodawac liczby zespolone.
  Funkcja zwraca wynik dodawania podanych liczb zespolonych. */

LZespolona operator+(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;

  return Wynik;
}

/* Funkcja przeciaza operator - aby mogl odejmowac liczby zespolone.
  Funkcja zwraca wynik odejmowania podanych liczb zespolonych. */

LZespolona operator-(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;

  return Wynik;
}

/* Funkcja przeciaz operator * aby mogl mnozyc liczby zespolone.
  Funkcja zwraca wynik mnozenia podanych liczbe zespolonych. */

LZespolona operator*(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = (Skl1.re * Skl2.re) - (Skl1.im * Skl2.im);
  Wynik.im = (Skl1.re * Skl2.im) + (Skl1.im * Skl2.re);

  return Wynik;
}

/* Funkcja dzieli liczbe zespolona przez liczbe rzeczywista.
  Funkcja zwraca podzielona liczbe zespolona. */

LZespolona operator/(LZespolona Skl, double r)
{
  LZespolona Wynik;

  if (r == 0)
  {
    std::cerr << "Proba dzielenia przez zero!" << std::endl;
    std::exit(1);
  }

  Wynik.re = Skl.re / r;
  Wynik.im = Skl.im / r;
  return Wynik;
}

/* Funkcja przeciaza operator / aby mogl dzielic liczby zespolone.
  Funkcja zwraca wynik dzielenia podanych liczb zespolonych, 
  a w przypadku dzielenia przez zero zespoloną z mianownika. */

LZespolona operator/(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;
  LZespolona Licznik = Skl1 * Sprzezenie(Skl2);
  double Mianownik = pow(Modul(Skl2), 2);

  if (Mianownik == 0)
  {
    std::cerr << "Proba dzielenia przez zero!" << std::endl;
    std::exit(1);
  }
  else
  {
    Wynik = Licznik / Mianownik;
    return Wynik;
  }
}

/* Funkcja przeciaza operaor == aby mogl porownywac liczby zespolone.
  Funkcja zwraca wynik porownania jako bool false lub true. */

bool operator==(LZespolona Skl1, LZespolona Skl2)
{
  if ((Skl1.re == Skl2.re) && (Skl1.im == Skl2.im))
  {
    return true;
  }
  else
  {
    return false;
  }
}

/* Analogicznie do poprzedniej funkcji tylko dla nierownosci.
  Zwraca bool false lub true. */

bool operator!=(LZespolona Skl1, LZespolona Skl2)
{

  return !(Skl1 == Skl2);
}
