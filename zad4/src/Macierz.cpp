/*

#include "Macierz.hh"

// Konstruktor zerujacy Macierz
Macierz::Macierz(){
    for(int i = 0; i < ROZMIAR; i++)
        for(int j = 0; j < ROZMIAR; j++){
            tab[i][j] = 0;
        }
}

// Konstruktor wstawiajacy kolenje argumenty do elementow macierzy
Macierz::Macierz(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3){

    tab[0][0] = a1, tab[0][1] = a2, tab[0][2] = a3;
    tab[1][0] = b1, tab[1][1] = b2, tab[1][2] = b3;
    tab[2][0] = c1, tab[2][1] = c2, tab[2][2] = c3;
}

// Konstruktor wstawiajacy wektory z argumentow do wierszy macierzy
Macierz::Macierz(Wektor W1, Wektor W2, Wektor W3){

    tab[0] = W1;
    tab[1] = W2;
    tab[2] = W3;
}

// Metoda obliczajaca wyznacznk macierzy z pola klasy (metoda Laplace'a)
// Zwraca wyznacznik
double Macierz::WyznacznikLaplace() const{

    return 
    (tab[0][0]*((tab[1][1]*tab[2][2])-(tab[1][2]*tab[2][1]))
    -tab[1][0]*((tab[0][1]*tab[2][2])-(tab[0][2]*tab[2][1]))    // Wzor metody Laplace'a
    +tab[2][0]*((tab[0][1]*tab[1][2])-(tab[0][2]*tab[1][1])));
}

// Metoda transponujaca macierz z pola klasy
// Zwraca  nowo utworzona macierz (transponowana z pola klasy)
const Macierz Macierz::Transpozycja() const{

    Macierz MacTr;

    for(int i = 0; i < ROZMIAR; i++)
        for(int j = 0; j < ROZMIAR; j++){   // Podstawienie kolejnych elementow macierzy z pola klasy pod odwrotne elementy nowej macierzy 
            MacTr[i][j] = tab[j][i];
        }

    return MacTr;
}

// Metoda oblicza odwrotnosc macierzy z pola klasy
// Zwraca nowo utworzona macierz (odwrotna do macierzy z pola)
const Macierz Macierz::Odwrotnosc() const{

    double det = WyznacznikLaplace();

    if(det == 0){
        std::cerr << "Blad: Macierz nieodwracalna!" << std::endl;
        exit(1);
    }

    Macierz MacDop;

    MacDop[0][0] = tab[1][1]*tab[2][2] - tab[1][2]*tab[2][1];
    MacDop[0][1] = -(tab[1][0]*tab[2][2] - tab[1][2]*tab[2][0]);
    MacDop[0][2] = tab[1][0]*tab[2][1] - tab[1][1]*tab[2][0];
    MacDop[1][0] = -(tab[0][1]*tab[2][2] - tab[0][2]*tab[2][1]);
    MacDop[1][1] = tab[0][0]*tab[2][2] - tab[0][2]*tab[2][0];       // Dopelnienia potrzebne do wzoru na odwrotnosc macierzy
    MacDop[1][2] = -(tab[0][0]*tab[2][1] - tab[0][1]*tab[2][0]);
    MacDop[2][0] = tab[0][1]*tab[1][2] - tab[0][2]*tab[1][1];
    MacDop[2][1] = -(tab[0][0]*tab[1][2] - tab[1][0]*tab[0][2]);
    MacDop[2][2] = tab[0][0]*tab[1][1] - tab[0][1]*tab[1][0];

    MacDop = MacDop.Transpozycja();

    Macierz MacOdw;

    for(int i = 0; i < ROZMIAR; i++ )
        for(int j = 0; j < ROZMIAR; j++){           // Zastosowanie wzoru na odwrotnosc macierzy
            MacOdw[i][j] = (1/det)*MacDop[i][j];
        }

    return MacOdw;
}

// Metoda przeciazajaca operator dodawaniua dwoch macierzy
// Zwraca wynik dodawania macierzy
Macierz Macierz::operator + (const Macierz & M) const{
    
    Macierz wynik;
    for(int i=0;i<ROZMIAR;i++)
        for(int j=0;j<ROZMIAR;j++){
            wynik[i][j] = tab[i][j] + M[i][j];
        }
    return wynik;
}

// Metoda przeciazajaca operator odejmwania macierzy z argumentu od macierzy z pola klasy
// Zwraca wynik odejmowania
Macierz Macierz::operator - (const Macierz & M) const{

    Macierz wynik;

    for(int i=0; i<ROZMIAR; i++){
        for(int j=0; j<ROZMIAR; j++){
            wynik.tab[i][j] = this->tab[i][j] - M.tab[i][j];
        }
    }
    return wynik;

}

// Metoda przeciazajaca operator mnozenia dla mnozenia macierzy przez macierz z argumentu
// Zwraca wynik mnozenia macierzy przez macierz
Macierz Macierz::operator * (const Macierz & M) const{
    Macierz wynik;
    for(int j=0;j<ROZMIAR;j++)
        for(int i=0;i<ROZMIAR;i++){
            wynik[i][j] = tab[i][0]*M[0][j]+tab[i][1]*M[1][j]+tab[i][2]*M[2][j];
        }
    return wynik;
}

// Metoda przeciazajaca operator mnozenia dla mnozenia macierzy przez wektor
// Zwraca wynizk mnozenia macierzy przez wektor
Wektor Macierz::operator * (const Wektor & W) const{

    Wektor wynik;
    for(int i=0;i<ROZMIAR;i++){
        wynik[i] = tab[i][0]*W[0] + tab[i][1]*W[1] + tab[i][2]*W[2];
    }
    return wynik;
}

// Przeciazenie operatora wyswietlania dla macierzy
// Zwraca strumien wyjsciowy
std::ostream& operator << (std::ostream &Strm, const Macierz &M)
{   
    Macierz M1;
    M1 = M.Transpozycja(); // Transponuje wyswietlana macierz (transpozycja wynika z zalozen zadania)
    return Strm << M1[0] << std::endl << M1[1] << std::endl << M1[2] << std::endl;
}

// Przeciazenie operatora wczytywania dla macierzy
// Zwraca strumien wejsciowy
std::istream& operator >> (std::istream &Strm, Macierz &M)
{
    Strm >> M[0] >> M[1] >> M[2];
    M.Transpozycja(); // Transponuje wczytana macierz (transpozycja wynika z zalozen zadania)
    return Strm;
}

*/
