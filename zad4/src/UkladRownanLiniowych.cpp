#include "UkladRownanLiniowych.hh"

template class UkladRownanLiniowych<double, 5>;
template std::istream & operator >> (std::istream & Strm, UkladRownanLiniowych<double, 5> & k);
template std::ostream & operator << (std::ostream & Strm, const UkladRownanLiniowych<double, 5> & k);
template class UkladRownanLiniowych<LZespolona,5>;
template std::istream & operator >> (std::istream & Strm, UkladRownanLiniowych<LZespolona, 5> & k);
template std::ostream & operator << (std::ostream & Strm, const UkladRownanLiniowych<LZespolona, 5> & k);

// Przeciazenie operatora wczytywania dla ukladu rownan
// Wykorzystuje operatory wczytywania kolejno macierzy oraz wektora i wstawia pod odpoweidnie pola klasy ukladu rownan
// Zwraca strumien wejsciowy
template <class TYP, int ROZMIAR>
std::istream & operator >> (std::istream &strm, UkladRownanLiniowych<TYP, ROZMIAR> &UklRown){
    Macierz<TYP, ROZMIAR> temp_A;
    Wektor<TYP, ROZMIAR> temp_b;

    strm >> temp_A >> temp_b;
    temp_A.Transpozycja();
    
    UklRown.set_A(temp_A);
    UklRown.set_b(temp_b);

    return strm;
}

// Przeciazenie operatora wyswietlania dla ukladu rownan 
// Wykorzystuje operatory wyswietlania kolejno macierzy  oraz wektora
// Zwraca strumien wyjsciowy
template <class TYP, int ROZMIAR>
std::ostream & operator << ( std::ostream &strm, const UkladRownanLiniowych<TYP, ROZMIAR> &UklRown){

    std::cout << "Macierz glowna A^T:" << "\n";
    std::cout << UklRown.get_A() << "\n";
    std::cout << "Wektor wyrazow wolnych b:" << "\n";
    std::cout << UklRown.get_b();

    return strm;
}

// Metoda Oblicza rozwiazania ukladu rownan metoda eliminacji Gaussa
// Zwraca wektor rozwiazan
template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> UkladRownanLiniowych<TYP, ROZMIAR>::Oblicz() const{

    Wektor<TYP, ROZMIAR> wynik = b;
    Macierz<TYP, ROZMIAR> temp = A;

    if(temp.WyznacznikGauss() == 0){
        std::cerr << "BLAD: Wyznacznik macierzy rowny zero. Brak lub nieskonczenie wiele rozwiazan. Koniec programu.\n" << std::endl;
        exit(1);
    }

    for(int i=0;i<ROZMIAR;i++){
        if(temp[i][i] == 0){
            std::cerr << "BLAD: Proba dzielenia przez zero; zero na przekatnej macierzy glownej. Koniec programu.\n" << std::endl;
            exit(1);
        }
    }
 
// Petla przeksztalca macierz temp w macierz trojkatna gorna
// Te same operacje wykonywane na elementach wektora wynik

    for(int i=0;i<ROZMIAR-1;i++){
        for(int j=i+1;j<ROZMIAR;j++){
            TYP p = temp[j][i]/temp[i][i];
            for(int k=0;k<ROZMIAR;k++){

                temp[j][k] -= p * temp[i][k];
            }
            wynik[j] -= wynik[i] * p;
        }
    }

// Dzielenie wierszy macierzy i elementow wektora aby przekatna macierzy byla jedynkami

    for(int i=0;i<ROZMIAR;i++){
        TYP p = temp[i][i];
        for(int j=0;j<ROZMIAR;j++){
            temp[i][j] = temp[i][j] / p;
        }
        wynik[i] = wynik[i] / p;
    }

// Petla tworzaca z macierzy temp macierz jednostkowa (zerowanie reszty elementow)
// Te same operacje dla wektora wynik
    for(int i=ROZMIAR-1;i>0;i--){
        for(int j=i-1;j>=0;j--){

            TYP p = temp[j][i];
            for(int k=ROZMIAR-1;k>=0;k--){

                temp[j][k] -= p * temp[i][k];
            }
            wynik[j] -= wynik[i] * p;
        }
    }
    return wynik;
}



