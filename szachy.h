#include <iostream>

/*Deklaracje klas utworzonych w programie.
  W programie jest wykorzystany kreacyjny wzorzec projektowy - fabryka abstrakcyjna.
  Jest to potrzebne, aby stworzyć interfejs do tworzenia różnych obiektów jednego typu.
*/

/*typ enum określający typ figury*/
enum genre_e{KROL,WIEZA,SKOCZEK,HETMAN,GONIEC,PION_CZ, PION_B};


/*Klasa Figur - zawiera jedynie funkcje wirtualne,
  klasy poszczególnych figur są klasami pochodnymi tej klasy
*/
class Figura {
public:
    /*Funkcje ustawiające i zdejmujące z planszy figurę.*/
	virtual void usun_figura(int i, int j,short int **plansza, int szer, int wys);
	virtual void poloz_figura( int i, int j,short int **plansza, int szer, int wys);
    /*Zwraca 0, jeśli położenie na tym polu figury skutkuje biciem innej figury już postawionej na planszy*/
    virtual bool czyNieBije(int  i,int  j,short int ** plansza,int szer,int wys);
    /*Zwraca 1 jeśli jest bite przez figure*/
    virtual bool czyDanePoleBite(int i, int j, short int **plansza, int szer, int wys, int dane_i, int dane_j);
    virtual ~Figura();
};


/*klasy pochodne klasy Figura reprezentujące poszczególne figury szachowe*/

class Krol :  public Figura{
private:
	 void poloz_figura( int i, int j,short int **plansza, int szer, int wys);
	 void usun_figura(int i, int j,short int **plansza, int szer, int wys);
     bool czyNieBije(int  i,int  j,short int ** plansza,int szer,int wys);
    bool czyDanePoleBite(int i, int j, short int **plansza, int szer, int wys, int dane_i, int dane_j);
    ~Krol();

};
class Wieza : public Figura {
private:
    void poloz_figura( int i, int j,short int **plansza, int szer, int wys);
    void usun_figura(int i, int j,short int **plansza, int szer, int wys);
    bool czyNieBije(int  i,int  j,short int ** plansza,int szer,int wys);
    bool czyDanePoleBite(int i, int j, short int **plansza, int szer, int wys, int dane_i, int dane_j);
    ~Wieza();
    
};

class Skoczek : public Figura{
private:
    void poloz_figura( int i, int j,short int **plansza, int szer, int wys);
    void usun_figura(int i, int j,short int **plansza, int szer, int wys);
    bool czyNieBije(int  i,int  j,short int ** plansza,int szer,int wys);
    bool czyDanePoleBite(int i, int j, short int **plansza, int szer, int wys, int dane_i, int dane_j);
   ~Skoczek();
};

class Hetman : public Figura{
private:
    void poloz_figura( int i, int j,short int **plansza, int szer, int wys);
	void usun_figura(int i, int j,short int **plansza, int szer, int wys);
    bool czyNieBije(int  i,int  j,short int ** plansza,int szer,int wys);
    bool czyDanePoleBite(int i, int j, short int **plansza, int szer, int wys, int dane_i, int dane_j);
   ~Hetman();
};

class Goniec : public Figura{
private:
    void poloz_figura( int i, int j,short int **plansza, int szer, int wys);
    void usun_figura(int i, int j,short int **plansza, int szer, int wys);
    bool czyNieBije(int  i,int  j,short int ** plansza,int szer,int wys);
    bool czyDanePoleBite(int i, int j, short int **plansza, int szer, int wys, int dane_i, int dane_j);
   ~Goniec();
};

class PionCz : public Figura{
private:
     void poloz_figura( int i, int j,short int **plansza, int szer, int wys);
     void usun_figura(int i, int j,short int **plansza, int szer, int wys);
     bool czyNieBije(int  i,int  j,short int ** plansza,int szer,int wys);
   bool czyDanePoleBite(int i, int j, short int **plansza, int szer, int wys, int dane_i, int dane_j);
    ~PionCz();
};

class PionB : public Figura{
private:
     void poloz_figura( int i, int j,short int **plansza, int szer, int wys);
     void usun_figura(int i, int j,short int **plansza, int szer, int wys);
     bool czyNieBije(int  i,int  j,short int ** plansza,int szer,int wys);
    bool czyDanePoleBite(int i, int j, short int **plansza, int szer, int wys, int dane_i, int dane_j);
    ~PionB();

};

/*Klasa potrzebna do tworzenia figur*/
class FiguryFactory {
    public:
     Figura *getFigury(genre_e genre);
};