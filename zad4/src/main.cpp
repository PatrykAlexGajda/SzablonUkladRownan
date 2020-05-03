#include <iostream>
#include <iomanip>
#include "UkladRownanLiniowych.hh"

// Program rozwiazuje uklad dowolnie wielu rownan liniowych z taka sama liczba niewiadomych metoda eliminacji Gaussa
// Dane wczytywane za pomocą operatora "<" przy wywolywaniu programu w terminalu
// Plik powinien zawierac elementy macierzy kwadratowej wpisane po transpozycji tej macierzy
// Oraz tyle elementow wektora wyrazow wolnych ile wymiarow ma macierz
// Przykladowo dla danych zawartych w folderze programu:
// ./uklad_rownan < testDouble.txt 
// lub
// ./uklad_rownan < testZesp.txt

int main(){

  // Przykladowe uzycie programu dla obliczenia rozwiazan ukladu rownan zespolonych z macierza glowna 5x5

  UkladRownanLiniowych<LZespolona, 5> ukl;

  std::cin >> ukl;
 
  std::cout << ukl << std::endl;

  std::cout << std::fixed << std::setprecision(2) << "Kolejne rozwiazania ukladu rownan: \n";

  std::cout << ukl.Oblicz() << std::endl;

  return 0;
}
