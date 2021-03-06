#include "Macierz.hh"

template class Macierz<double,5>;
template std::istream & operator >> (std::istream & Strm, Macierz<double, 5> & k);
template std::ostream & operator << (std::ostream & Strm, const Macierz<double, 5> & k);
template class Macierz<LZespolona,5>;
template std::istream & operator >> (std::istream & Strm, Macierz<LZespolona, 5> & k);
template std::ostream & operator << (std::ostream & Strm, const Macierz<LZespolona, 5> & k);

// Konstruktor zerujacy Macierz
template <class TYP, int ROZMIAR>
Macierz<TYP, ROZMIAR>::Macierz(){
    for(int i = 0; i < ROZMIAR; i++)
        for(int j = 0; j < ROZMIAR; j++){
            tab[i][j] = 0;
        }
}

// Metoda transponujaca macierz z pola klasy
// Zwraca  nowo utworzona macierz (transponowana z pola klasy)
template <class TYP, int ROZMIAR>
const Macierz<TYP, ROZMIAR> Macierz<TYP, ROZMIAR>::Transpozycja() const{

    Macierz<TYP, ROZMIAR> MacTr;

    for(int i = 0; i < ROZMIAR; i++)
        for(int j = 0; j < ROZMIAR; j++){  
            MacTr[i][j] = tab[j][i];
        }

    return MacTr;
}

// Metoda oblicza wyznacznik macierzy przy uzyciu eliminacji Gaussa do utworzenia macierzy trojkatnej
// Zwraca wyznacznik w zmiennej typu TYP
template <class TYP, int ROZMIAR>
TYP Macierz<TYP, ROZMIAR>::WyznacznikGauss() const{

    TYP wyzn;
    Macierz<TYP, ROZMIAR> temp;
    
    temp = *this;

    for(int i=0;i<ROZMIAR;i++){
        if(temp[i][i] == 0){
            std::cerr << "BLAD: Proba dzielenia przez zero; zero na przekatnej macierzy glownej. Koniec programu.\n" << std::endl;
            exit(1);
        }
    }

// Petla tworzy macierz trojkatna gorna

    for(int i=0;i<ROZMIAR-1;i++){
        for(int j=i+1;j<ROZMIAR;j++){
            TYP p = temp[j][i];
            for(int k=0;k<ROZMIAR;k++){
                temp[j][k] -= (p / temp[i][i]) * temp[i][k];
            }
        }
    }

// Przemnozenie elementow na przekatnej macierzy w celu uzyskania wyznacznika

    wyzn = 1;
    for(int i=0;i<ROZMIAR;i++){
        wyzn *= temp[i][i];
    }

    return wyzn;
}


// Metoda tworzy macierz odwrotna do macierzy z pola klasy
// Zwraca te odwrotna macierz
template <class TYP, int ROZMIAR>
const Macierz<TYP, ROZMIAR> Macierz<TYP, ROZMIAR>::Odwrotnosc() const{

    Macierz<TYP, ROZMIAR> temp;
    Macierz<TYP, ROZMIAR> I;

// Utworzenie macierzy jednostkowej

    for(int i=0;i<ROZMIAR;i++){
        I[i][i] = 1;
    }

    temp = *this;

    if(temp.WyznacznikGauss() == 0){
        std::cerr << "BLAD: Wyznacznik macierzy rowny zero. Nie mozna wyliczyc macierzy odwrotnej. Koniec programu.\n" << std::endl;
        exit(1);
    }

    for(int i=0;i<ROZMIAR;i++){
        if(temp[i][i] == 0){
            std::cerr << "BLAD: Proba dzielenia przez zero; zero na przekatnej macierzy glownej. Koniec programu.\n" << std::endl;
            exit(1);
        }
    }

// Petla tworzy macierz trojkatna gorna, te same operacje dla macierzy jednostkowej

    for(int i=0;i<ROZMIAR-1;i++){
        for(int j=i+1;j<ROZMIAR;j++){
            TYP p = temp[j][i]/temp[i][i];
            for(int k=0;k<ROZMIAR;k++){

                temp[j][k] -= p * temp[i][k];
                I[j][k] -= p * I[i][k];
            }
        }
    }

// Petla dzieli wiersze macierzy temp aby uzyskac jedynki, te same operacje dla macierzy I

    for(int i=0;i<ROZMIAR;i++){
        TYP p = temp[i][i];
        for(int j=0;j<ROZMIAR;j++){
            temp[i][j] = temp[i][j] / p;
            I[i][j] = I[i][j] / p;
        }
    }

// Petla zeruje reszte elementow, te same operacje dla macierzy I

    for(int i=ROZMIAR-1;i>0;i--){
        for(int j=i-1;j>=0;j--){
            TYP p = temp[j][i];
            for(int k=ROZMIAR-1;k>=0;k--){

                temp[j][k] -= p * temp[i][k];
                I[j][k] -= p * I[i][k];

            }
        }
    }

// Macierz I to teraz macierz odwrotna do macierzy z pola klasy

    return I;
}

// Metoda przeciazajaca operator dodawaniua dwoch macierzy
// Zwraca wynik dodawania macierzy
template <class TYP, int ROZMIAR>
Macierz<TYP, ROZMIAR> Macierz<TYP, ROZMIAR>::operator + (const Macierz & M) const{
    
    Macierz wynik;

    for(int i=0;i<ROZMIAR;i++)
        for(int j=0;j<ROZMIAR;j++){
            wynik[i][j] = tab[i][j] + M[i][j];
        }
    return wynik;
}

// Metoda przeciazajaca operator odejmwania macierzy z argumentu od macierzy z pola klasy
// Zwraca wynik odejmowania
template <class TYP, int ROZMIAR>
Macierz<TYP, ROZMIAR> Macierz<TYP, ROZMIAR>::operator - (const Macierz & M) const{

    Macierz wynik;

    for(int i=0; i<ROZMIAR; i++){
        for(int j=0; j<ROZMIAR; j++){
            wynik.tab[i][j] = tab[i][j] - M[i][j];
        }
    }
    return wynik;

}

// Metoda przeciazajaca operator mnozenia dla mnozenia macierzy przez macierz z argumentu
// Zwraca wynik mnozenia macierzy przez macierz
template <class TYP, int ROZMIAR>
Macierz<TYP, ROZMIAR> Macierz<TYP, ROZMIAR>::operator * (const Macierz & M) const{

    Macierz wynik;

    for(int i=0;i<ROZMIAR;i++)
        for(int j=0;j<ROZMIAR;j++){
            for(int k=0;k<ROZMIAR;k++){
            
            wynik.tab[i][j] +=  tab[i][k] * M[k][j];
            }
        }
    return wynik;
}

// Metoda przeciaza operator * dla mnozenia macierzy przez wektor
// Zwraca wektor wynikowy
template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Macierz<TYP, ROZMIAR>::operator * (const Wektor<TYP, ROZMIAR> & W) const{

    Wektor<TYP, ROZMIAR> wynik;
    for(int i=0;i<ROZMIAR;i++){
        for(int j=0;j<ROZMIAR;j++){
            wynik[i] += tab[i][j] * W[j];
        }
    }
    return wynik;
}

// Przeciazenie operatora wyswietlania dla macierzy
// Zwraca strumien wyjsciowy
template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Macierz<TYP, ROZMIAR> &M)
{   
    Macierz<TYP, ROZMIAR> M1;
    M1 = M.Transpozycja(); // Transponuje wyswietlana macierz (transpozycja wynika z zalozen zadania)
    
    for(int i=0;i<ROZMIAR;i++){
        Strm << M1[i] << std::endl;
    }    

    return Strm;
}

// Przeciazenie operatora wczytywania dla macierzy
// Zwraca strumien wejsciowy
template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Macierz<TYP, ROZMIAR> &M)
{
    
    for(int i=0;i<ROZMIAR;i++){
        Strm >> M[i];
    }
    M = M.Transpozycja(); // Transponuje wczytana macierz (transpozycja wynika z zalozen zadania)
    return Strm;
}

