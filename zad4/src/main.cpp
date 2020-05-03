#include <iostream>
#include <iomanip>
#include "UkladRownanLiniowych.hh"

// Program rozwiazuje uklad 3 rownan liniowych z trzema niewiadomymi za pomoca metody Cramera
// Dane wczytywane za pomocą operatora "<" przy wywolywaniu programu w terminalu lub
// bezposrednio od uzytkownika po wpisaniu ich w terminalu (nalezy wpisac 9 liczb ztransponowanej macierzy oraz 3 liczby jako wyrazy wolne)
// Przykladowo dla danych zawartych w folderze programu:
// ./uklad_rownan < testUklad.txt

int main(){

  UkladRownanLiniowych<LZespolona, 5> ukl;

  std::cin >> ukl;
 
  std::cout << ukl << std::endl;

  std::cout << "Kolejne rozwiazania ukladu rownan: \n";

  std::cout << ukl.Oblicz() << std::endl;

  return 0;
}
