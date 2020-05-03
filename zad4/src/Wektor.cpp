#include "Wektor.hh"

template class Wektor<double,5>;
template std::istream & operator >> (std::istream & Strm, Wektor<double, 5> & k);
template std::ostream & operator << (std::ostream & Strm, const Wektor<double, 5> & k);
template class Wektor<LZespolona,5>;
template std::istream & operator >> (std::istream & Strm, Wektor<LZespolona, 5> & k);
template std::ostream & operator << (std::ostream & Strm, const Wektor<LZespolona, 5> & k);



//Metoda zezwala na dostep do elementu indeks tablicy wektora
template <class TYP, int ROZMIAR>
TYP & Wektor<TYP, ROZMIAR>::operator[] (int indeks) {
    if (indeks < 0 || indeks >= ROZMIAR) { // Blad w przypadku podania zlego indeksu
      std::cerr << "BLAD: Zly indeks wektora."; 
      exit(1);
    }
    return tab[indeks];
}

// Przeciazenie operatora dodawania dwoch wektorow
// Zwraca wynik dodania wektora klasy z wektorem podanym w argumencie
template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>::operator + (const Wektor & W2) const{

    Wektor wynik;
    for(int i=0; i<ROZMIAR; i++){
    wynik.tab[i] = tab[i] + W2.tab[i];
    }
    return wynik;
}

// Przeciazenie operatora odejmowania wektora od wektora
// Zwraca wynik odejmowania wektora podanego w argumencie od wektora klasy
template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>::operator - (const Wektor & W2) const{

    Wektor wynik;
    for(int i=0; i<ROZMIAR; i++){
    wynik.tab[i] = tab[i] - W2.tab[i];
    }
    return wynik;
}

template <class TYP, int ROZMIAR>
TYP Wektor<TYP, ROZMIAR>::operator * (const Wektor & W2) const{

    TYP a;
    a=0;
    for(int i=0; i < ROZMIAR; i++){
        a += tab[i] * W2[i];
    }
    return a;
}

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>::operator / (const double & d) const{

    Wektor<TYP, ROZMIAR> wynik;
    for(int i=0; i<ROZMIAR; i++){
        wynik[i] = wynik[i] / d;
    }

    return wynik;
}

// Przeciazenie operatora wczytywania wektora
// Podstawia wczytane dane pod kolejne elementy wektora i zwraza strumien wejsciowy
template <class TYP, int ROZMIAR>
std::istream & operator >> (std::istream &Strm, Wektor<TYP, ROZMIAR> &W)
{
    for(int i=0; i<ROZMIAR; i++){
        Strm >> W[i];
    }
    return Strm;
}

// Przeciazenie operatora wyswietlania dla wektora
// Wyswietla kolejne elementy wektora i zwraca strumien wyjsciowy
template <class TYP, int ROZMIAR>
std::ostream & operator << (std::ostream &Strm, const Wektor<TYP, ROZMIAR> &W)
{   
    for(int i=0; i<ROZMIAR; i++){
        Strm << W[i] << "\t";
    }
    std::cout << std::endl;
    
    return Strm;
}





