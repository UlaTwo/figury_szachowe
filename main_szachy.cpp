/*
    projekt: Szachy-rekurencyjne ustawianie figur na planszy
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;
#include "szachy.h"


/*Deklaracje funkcji */
void WypiszTab( int wys,int szer, short int ** plansza);
void kopiuj_tablice( short int **rozwiazanie, int wys,int szer, short int ** plansza);
void rekurencja(int liczba, int numer, Figura *lista[], short int **plansza, int szer, int wys, int *tablica, short int **rozwiazanie);
bool CzytaniePliku(int *tab,int argc, char **argv);
int PoliczLiczbe(int *tab);
void Wpisz(Figura *lista[],int *tab_plik, int liczba);
void WypisRozwiazanie(short int **rozwiazanie,int wys,int szer);
int licznik_rozwiazan=0;


/*Funkcja main jest wywoływana z argumentami ponieważ przez argumenty funkcji przekazywana jest nazwa pliku. */
int main(int argc, char **argv){

    /*wymiary planszy*/
	int wys;
	int szer;
    /*liczba figur danych do ustawienia*/
	int liczba;
    /*tablica pomocnicza, zawiera informacę o danych wczytanych z pliku*/
    int tab_plik[9];


    int wczytanie;
    /*CzytaniePliku zwraca 1, jeśli udało się wczytać plik (w przeciwnym razie 0)*/
    wczytanie=CzytaniePliku(tab_plik, argc, argv);
    if(wczytanie){
        /*przypisanie liczby figur do zmiennej*/
        liczba=PoliczLiczbe(tab_plik);
    
        wys=tab_plik[1];
        szer=tab_plik[0];
        /*Jesli jest więcej figur niż miejsc na planszy, to program zwraca o tym informację bez wykonywania rekurencji*/
        if(liczba>szer*wys) 
            cout<<"Ilość figur jest większa niż pól na planszy, więc nie da się ich na niej ustawić"<<endl;
        else{
            /*tablica wskażników na figury*/
            Figura*lista[liczba];
            Wpisz(lista,tab_plik,liczba);

            /*utworzenie tablic reprezentujących plansze*/
	        short int **plansza = new short int *[wys]();
            for(int i=0; i<wys; i++)
                plansza[i]=new short int [szer]();

            short int **rozwiazanie = new short int *[wys]();
            for(int i=0; i<wys; i++)
                rozwiazanie[i]=new short int [szer]();

            /*utworzenie tablicy pomocniczej,
            w której będzie przechowywana informacja o tym,
            czy dana figura już została wpisana na planszę w rekurencji */
            int tablica[liczba];
            for(int i=0;i<liczba;i++) tablica[i]=1;

            /*wywołanie funkcji rekurencyjnej szukającej rozwiązania ustawienia
             zadanych figur na planszy*/
            rekurencja(liczba, 0, lista, plansza, szer, wys, tablica, rozwiazanie);
    
            if(licznik_rozwiazan==0) cout<<"\nNiestety nie da się ustawić podanych figur na planszy."<<endl;

            else{
                cout<<"\nDa się podane figury ustawić na planszy.\n Oto przykładowe rozwiązanie:\n";
                WypisRozwiazanie(rozwiazanie, wys, szer);
            }

            /*zwolnienie pamieci*/
            for (int i = 0; i<wys; i++)
                delete [] plansza[i];
            delete [] plansza;

            for (int i = 0; i<wys; i++)
                delete [] rozwiazanie[i];
            delete [] rozwiazanie;

            for(int i=0; i<liczba; i++) {
                lista[i]->~Figura();
                
            }
        }
    }


	return 0;
}

/***********************************************************************************/

/***********************************************************************************/


/*funkcja wypisująca tablicę*/
void WypiszTab( int wys,int szer, short int ** plansza){
    for(int i=0; i<wys; i++) {
        for(int j=0; j<szer; j++) {
            cout<<plansza[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

/*funkcja kopiująca tablicę plansza do tablicy rozwiązanie*/
void kopiuj_tablice( short int **rozwiazanie, int wys,int szer, short int ** plansza){
    for(int i=0; i<wys; i++){
        for(int j=0; j<szer; j++) {
            rozwiazanie[i][j]=plansza[i][j];
        }
    }
}


/*
Funkcja rekurenycjnie ustawiająca figury na planszy:  liczba - liczba figur do ustawienia na planszy
numer - numer figury, która bedzie ukladany na danym poziomie rekurencji
*lista[liczba] - tablica adresow do figur
plansza - plansza na ktorej zostaly ustawione dotychczasowe ksztalty,
          i na której ustawiamy kolejny kształt
szer - szerokosc planszy   wys - wysokosc planszy
tablica - zawiera informacje czy dany ksztalt zostal juz ulozony na planszy:
           1-nie byl ułozżzny, czyli możemy go ukladac,  0-zostal ulozony na planszy
rozwiazanie - tablica, do której przypisywane bedzie poprawne ułozenie figur
*/
void rekurencja(int liczba, int numer, Figura *lista[], short int **plansza, int szer, int wys, int *tablica, short int **rozwiazanie) { 
    /*wykonuje program po kolei dla wszystkich figur z tablicy*/   
    for(numer; numer>=0&&numer<liczba; numer++) {
        /*jesli ksztalt nie zostal polozny jeszcze na planszy*/
        if(tablica[numer]==1) {      
            for(int i=0; i<wys; i++) {
                for(int j=0; j<szer; j++) {
                    if(plansza[i][j]==0 && lista[numer]->czyNieBije( i, j, plansza, szer, wys)) {   
                        /*ksztalt zostal ulozony, odnontowanie informacji*/
                        tablica[numer]=0;
                         /*ulozenie na planszy*/
                        lista[numer]->poloz_figura( i, j, plansza, szer, wys);

                        /*iteracyjne wywołanie rekurencji, jeśli nie zostało jeszcze odnalezione rozwiązanie*/
                        if(numer+1!=liczba) 
                            rekurencja(liczba, numer+1, lista, plansza, szer, wys, tablica, rozwiazanie);
                        /*sprawdzam, czy rozwiązanie zostało odnalezione:
                           wszystkie figury są wpisane na planszy
                        */
                        int pom=1;
                        for(int m=0;m<liczba;m++){
                            if(tablica[m]==1) pom=0;
                        }
                        /*wejście do tego warunku oznacza, że rozwiązanie zostało odnalezione*/
                        if(pom) {
                            kopiuj_tablice(rozwiazanie, wys, szer, plansza);
                            licznik_rozwiazan++;
                        }

                        /*zdjęcie figury z planszy i odnotowanie o tym informacji*/
                        tablica[numer]=1;
                        lista[numer]->usun_figura( i, j, plansza, szer, wys);
                    }
                }
            }
        }
    }

}

/*odczytuje liczbę figur z tablicy pomocniczej*/
int PoliczLiczbe(int *tab){
    int l=0;
    for(int i=2;i<9;i++){
        l+=tab[i];
    }
    return l;

}

/*funkcja wpisująca do tablicy lista[] wskaźniki do odpowiednich figur
  odczytanych z tablicy tab_plik*/
void Wpisz(Figura *lista[],int *tab_plik, int liczba){
        FiguryFactory *figurFactory = new FiguryFactory();
    int l=0;
    for(int i=2;i<9 && l<liczba;i++){
        int k = tab_plik[i];
        switch (i){
            case 2: for(int j=0; j<k;j++){lista[l]=figurFactory->getFigury(KROL); l++;} break; 
            case 3: for(int j=0; j<k;j++){lista[l]=figurFactory->getFigury(HETMAN); l++;} break; 
            case 4: for(int j=0; j<k;j++){lista[l]=figurFactory->getFigury(WIEZA); l++;} break; 
            case 5: for(int j=0; j<k;j++){lista[l]=figurFactory->getFigury(PION_CZ); l++;} break; 
            case 6: for(int j=0; j<k;j++){lista[l]=figurFactory->getFigury(PION_B); l++;} break; 
            case 7: for(int j=0; j<k;j++){lista[l]=figurFactory->getFigury(GONIEC); l++;} break; 
            case 8: for(int j=0; j<k;j++){lista[l]=figurFactory->getFigury(SKOCZEK); l++;} break; 
        }
    }
}

/*Funkcja wypisująca tablicę rozwiązanie w formie graficznej*/
void WypisRozwiazanie(short int **rozwiazanie,int wys,int szer){
    for(int i=0; i<wys; i++) {
        for(int k=0; k<szer; k++) cout<<" ——— ";
        cout<<endl;
        for(int j=0; j<szer; j++) {   
            if(rozwiazanie[i][j]>=0) cout<<"| 0 |";
            else{ 
                switch (rozwiazanie[i][j]){
                    case -1: cout<<"| K |"; break; 
                    case -2:cout<<"| W |"; break; 
                    case -3:cout<<"| S |"; break; 
                    case -4:cout<<"| H |"; break; 
                    case -5:cout<<"| G |"; break; 
                    case -6:cout<<"| PC|"; break; 
                    case -7:cout<<"| PB|"; break; 
                    default: break;
                }
            }
        }
        cout<<endl;
    }
    for(int k=0; k<szer; k++) cout<<" ——— ";
    cout<<endl<<endl;
}

/*Funkcja wczytująca dane z pliku. Zwraca 0, jeśli nie udało się wczytać pliku*/
bool CzytaniePliku(int *tab,int argc, char **argv){
    ifstream f;
    string filename;
    int petla=1;
    if(argc==2){
        /*nazwa funkcji przypisana z argumentu wypisania main*/
        filename=argv[1];
        /*Sprawdzam, czy plik jest txt*/
        char a;
        int i;
        i= filename.length();

        if (!(filename[i-1]=='t' && filename[i-2]=='x' && filename[i-3]=='t' && filename[i-4]=='.'))
            cout<<"Błędna nazwa pliku"<<endl;
        else{

            /*otwarcie pliku*/
            f.open( filename.c_str() );
            int p;
            string s,spr;
            int ok=1;

            /*Wczytywanie po kolei informacji z lini pliku
               z jednoczesnym sprawdzeniem, czy dane są poprawne (zmienna ok)
            */
            for(int i=0;i<11 && ok; i++){
                getline (f,s);
                switch(i){
                    case 0: spr="Plansza:";
                            if(spr!=s) {ok=0;}
                            break;
                    case 1: spr="szerokosc:";
                             if(spr!=s) ok=0;
                            f>>p;
                            tab[0]=p;
                            getline(f,s);
                            break;
                    case 2: spr="wysokosc:";
                            if(spr!=s) ok=0;
                            f>>p;
                            tab[1]=p;
                            getline(f,s);
                            break;
                    case 3: spr="Figury:";
                            if(spr!=s) ok=0;
                            break;
                    case 4: spr="krol:";
                            if(spr!=s) ok=0;
                            f>>p;
                            tab[2]=p;
                            getline(f,s);
                            break;
                    case 5: spr="hetman:";
                            if(spr!=s) ok=0;
                            f>>p;
                            tab[3]=p;
                            getline(f,s);
                            break;
                    case 6: spr="wieza:";
                            if(spr!=s) ok=0;
                            f>>p;
                            tab[4]=p;
                            getline(f,s);
                            break;
                    case 7: spr="pionek czarny:";
                            if(spr!=s) ok=0;
                            f>>p;
                            tab[5]=p;
                            getline(f,s);
                            break;
                    case 8: spr="pionek bialy:";
                            if(spr!=s) ok=0;
                            f>>p;
                            tab[6]=p;
                            getline(f,s);
                            break;
                    case 9: spr="goniec:";
                            if(spr!=s) ok=0;
                            f>>p;
                            tab[7]=p;
                            getline(f,s);
                            break;
                    case 10: spr="skoczek:";
                            if(spr!=s) ok=0;
                            f>>p;
                            tab[8]=p;
                            getline(f,s);
                            break;
                    default: ok=0; break;
                }
            }

            /*jeśli ok=0 to znaczy, że plik jest błędny*/
            if(ok==0) cout<<"Plik jest błędny!"<<endl; 
            else petla=0;
            if (ok) cout << "Plik został wczytany.\n";

            /*zamknięcie pliku*/
            f.close();
        }
        return !petla;
  
    }
    cout<<"\nArgumenty wywołania funkcji są błędne.\n"<<endl; 
    return 0;
}
