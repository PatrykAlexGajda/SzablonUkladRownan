#include <iostream>
#include "Wektor.hh"
#include "LZespolona.hh"

// Program rozwiazuje uklad 3 rownan liniowych z trzema niewiadomymi za pomoca metody Cramera
// Dane wczytywane za pomocą operatora "<" przy wywolywaniu programu w terminalu lub
// bezposrednio od uzytkownika po wpisaniu ich w terminalu (nalezy wpisac 9 liczb ztransponowanej macierzy oraz 3 liczby jako wyrazy wolne)
// Przykladowo dla danych zawartych w folderze programu:
// ./uklad_rownan < uklad.txt

int main(){

/*
  Macierz A;  // Konstrukcja wyzerowanej maceirzy
  Wektor b; // Konstrukcja wyzerowanego wektora

  std::cin >> A >> b; // Wczytanie macierzy glownej oraz wektora wyrazow wolnych
  UkladRownanLiniowych UklRown(A, b); // Konstrukcja ukladu rownan z wczytanych macierzy i wektora

  std::cout << UklRown << "\n\n";

  std::cout << "Rozwiazanie x = (x1, x2, x3)" << std::endl;
  Wektor Rozw = UklRown.Oblicz(); // Obliczenie niewiadomych ukladu rownan
  std::cout << Rozw << "\n";

  std::cout << "Wektor Bledu:" << std::endl; 
  std::cout << UklRown.WektorBledu() << std::endl;
  std::cout << "Dlugosc wektora bledu:" << std::endl;
  std::cout << UklRown.MiaraBledu() << std::endl;
  */

  Wektor<LZespolona, 5> wek1;
  Wektor<LZespolona, 5> wek2;

  std::cin >> wek1 >> wek2;
  std::cout << std::endl;

  LZespolona wynik;

  wynik = wek1 * wek2;

  std::cout << wynik << std::endl;

  return 0;
}
