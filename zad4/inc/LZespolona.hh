#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>

/*!  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze. */

/*! Modeluje pojecie liczby zespolonej */
struct LZespolona
{
  double re; /*! Pole repezentuje czesc rzeczywista. */
  double im; /*! Pole repezentuje czesc urojona. */

public:
  LZespolona()
  {
    re = 0;
    im = 0;
  }

  LZespolona operator = (double a);
  LZespolona operator += (LZespolona Skl);
  LZespolona operator -= (LZespolona Skl);
  LZespolona operator * (double r) const;
  LZespolona operator *= (LZespolona Skl);

};

/* Naglowki funkcji dzialajacych na liczbach zespolonych
lub liczacych je na podstawie zawartosci struktury LZespolona */

LZespolona Utworz(double x, double y);
LZespolona Sprzezenie(LZespolona Skl);
double Modul(LZespolona Skl);

/* Naglowki przeciazen operatorow ktore pozwalaja im operowac na strukturze
liczb zespolonych */

std::ostream &operator<<(std::ostream &str, const LZespolona &zesp);
std::istream &operator>>(std::istream &str, LZespolona &zesp);

LZespolona operator+(LZespolona Skl1, LZespolona Skl2);
LZespolona operator-(LZespolona Skl1, LZespolona Skl2);
LZespolona operator*(LZespolona Skl1, LZespolona Skl2);
LZespolona operator/(LZespolona Skl1, LZespolona Skl2);
LZespolona operator/(LZespolona Skl, double r);

bool operator==(LZespolona Skl1, LZespolona Skl2);
bool operator!=(LZespolona Skl1, LZespolona Skl2);

#endif
