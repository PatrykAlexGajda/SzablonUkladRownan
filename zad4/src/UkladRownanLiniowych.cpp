/*

#include "UkladRownanLiniowych.hh"

// Przeciazenie operatora wczytywania dla ukladu rownan
// Wykorzystuje operatory wczytywania kolejno macierzy oraz wektora i wstawia pod odpoweidnie pola klasy ukladu rownan
// Zwraca strumien wejsciowy
std::istream & operator >> (std::istream &strm, UkladRownanLiniowych &UklRown){
    Macierz temp_A;
    Wektor temp_b;

    strm >> temp_A >> temp_b;

    temp_A.Transpozycja();
    
    UklRown.set_A(temp_A);
    UklRown.set_b(temp_b);

    return strm;
}

// Przeciazenie operatora wyswietlania dla ukladu rownan 
// Wykorzystuje operatory wyswietlania kolejno macierzy  oraz wektora
// Zwraca strumien wyjsciowy
std::ostream & operator << ( std::ostream &strm, const UkladRownanLiniowych &UklRown){

    std::cout << "Macierz glowna:" << "\n";
    std::cout << UklRown.get_A() << "\n";
    std::cout << "Wektor wyrazow wolnych b:" << "\n";
    std::cout << UklRown.get_b();

    return strm;
}

// Metoda obliczajaca niewiadome ukladu rownan z pol klasy (metoda Cramera)
// Zwraca wektor z wartosciami niewiadmoych
Wektor UkladRownanLiniowych::Oblicz() const{

    Wektor X;

    Macierz Ax1(b ,A[1], A[2]); // Konstrukcja macierzy zmieniajaca kolumne niewiadomych x1 macierzy klasowej na wyrazy wolne
    Macierz Ax2(A[0], b, A[2]); // Dla niewiadomych x2
    Macierz Ax3(A[0], A[1], b); // Dla niewiadomych x3

    double WyznA = A.WyznacznikLaplace();   // Wyznacznik macierzy glownej
    double WyznAx1 = Ax1.WyznacznikLaplace();   // Wyzancznik macierzy Ax1
    double WyznAx2 = Ax2.WyznacznikLaplace();   // Wyznacznik macierzy Ax2
    double WyznAx3 = Ax3.WyznacznikLaplace();   // Wyznacznik macierzy Ax3

    X[0] = WyznAx1/WyznA;
    X[1] = WyznAx2/WyznA;   // Zastosowanie metody Cramera
    X[2] = WyznAx3/WyznA;


    return X;
}

// Metoda obliczajaca wektor bledu na podstawie wyliczonych niewiadmoych, macierzy oraz wektora wolnego z klasy 
// Zwraca wektor bledu
Wektor UkladRownanLiniowych::WektorBledu() const{

    Wektor wektorBledu = (A.Transpozycja() * Oblicz()) - b; // Wzor na wektro bledu
    return wektorBledu;
}

// Metoda obliczajaca dlugosc wektora bledu (miara bledu)
// Zwraca miare bledu
double UkladRownanLiniowych::MiaraBledu() const{

    Wektor roznica = WektorBledu();
    return roznica.dlugosc();
}

*/