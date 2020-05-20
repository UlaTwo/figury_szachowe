#include <iostream>
#include "szachy.h"
using namespace std;



/*Metody wirtualne klasy Figura*/
void Figura:: usun_figura(int i, int j,short int **plansza, int szer, int wys){}
void Figura:: poloz_figura( int i, int j,short int **plansza, int szer, int wys){}
bool Figura:: czyNieBije(int  i,int  j,short int ** plansza,int szer,int wys){}
bool Figura :: czyDanePoleBite(int i, int j, short int **plansza, int szer, int wys, int dane_i, int dane_j){}
 Figura:: ~Figura(){}


/***********************************************************************************/
/*Każda z figur ma pięć metod:
  1. metoda poloz_figura - w podanym miejscu na planszy wpisuje ujemną liczbę odpowiadającą w programie danej figurze
      następnie zwiększa o jeden liczbę na polach planszym które będą bite przez tę figurę
  2. metoda usun_figura - zeruje pole na którym stała figura i zmniejsza o jeden te pola, które były bite przez figurę
  3. metoda czNieBije - sprawdza, czy w zasięgu bicia postawionej figury występuje jakaś inna figura
  4. metoda czyDanePoleBite - bada czy zadane pole jest bite przez figurę postawioną na danym polu
  5. dekonstruktor figury
*/

/***********************************************************************************/
void Krol::poloz_figura( int i, int j,short int **plansza, int szer, int wys){
		plansza[i][j]=-1;
    if (j-1>=0) plansza[i][j-1]=plansza[i][j-1]+1; 
    if(j+1<szer) plansza [i][j+1]=plansza [i][j+1]+1;
    if(i-1>=0) plansza[i-1][j]=plansza[i-1][j]+1;
    if(i+1<wys) plansza [i+1][j]=plansza [i+1][j]+1;

    if(j-1>=0 && i-1>=0) plansza [i-1][j-1]=plansza [i-1][j-1]+1;
    if(j+1<szer && i+1<wys) plansza [i+1][j+1]=plansza [i+1][j+1]+1;
    if(j-1>=0 && i+1<wys ) plansza [i+1][j-1]=plansza [i+1][j-1]+1;
    if(j+1<szer && i-1>=0) plansza [i-1][j+1]=plansza [i-1][j+1]+1;
}

void  Krol:: usun_figura(int i, int j,short int **plansza, int szer, int wys){
		plansza[i][j]=0;
		if (j-1>=0) plansza[i][j-1]=plansza[i][j-1]-1; 
		if(j+1<szer) plansza [i][j+1]=plansza [i][j+1]-1;
		if(i-1>=0) plansza[i-1][j]=plansza[i-1][j]-1;
		if(i+1<wys) plansza [i+1][j]=plansza [i+1][j]-1;

    if(j-1>=0 && i-1>=0) plansza [i-1][j-1]=plansza [i-1][j-1]-1;
    if(j+1<szer && i+1<wys) plansza [i+1][j+1]=plansza [i+1][j+1]-1;
    if(j-1>=0 && i+1<wys ) plansza [i+1][j-1]=plansza [i+1][j-1]-1;
    if(j+1<szer && i-1>=0) plansza [i-1][j+1]=plansza [i-1][j+1]-1;
}

bool Krol:: czyNieBije(int  i,int  j,short int ** plansza,int szer,int wys){
    int pom=1;
    for(int m=0; m<wys; m++) {
        for(int k=0; k<szer; k++) {
            if(czyDanePoleBite(i,j,plansza,szer,wys,m,k) && plansza[m][k]<0) pom=0;
        }
    }
    return pom;
}

bool Krol:: czyDanePoleBite(int i, int j, short int **plansza, int szer, int wys, int dane_i, int dane_j){
    int pom=0;
    if((dane_i==i && dane_j==j-1) || (dane_i==i && dane_j==j+1) || (dane_i==i-1 && dane_j==j)|| (dane_i==i+1 && dane_j==j)) pom=1;
    if((dane_i==i-1 && dane_j==j-1) || (dane_i==i+1 && dane_j==j+1) || (dane_i==i+1 && dane_j==j-1)|| (dane_i=i-1 && dane_j==j+1)) pom=1;
    return pom;
}

Krol::~Krol(){};

/***********************************************************************************/

void Wieza:: poloz_figura( int i, int j,short int **plansza, int szer, int wys){
    plansza[i][j]=-2;
    int k;
    for (k=i-1;k>=0;k--){plansza[k][j]=plansza[k][j]+1;}
    for (k=j-1;k>=0;k--){plansza[i][k]=plansza[i][k]+1;}
    for (k=i+1;k<wys;k++){plansza[k][j]=plansza[k][j]+1;}
    for (k=j+1;k<szer;k++){plansza[i][k]=plansza[i][k]+1;}
}

void Wieza:: usun_figura(int i, int j,short int **plansza, int szer, int wys){
    plansza[i][j]=0;
    int k;
    for (k=i-1;k>=0;k--){plansza[k][j]=plansza[k][j]-1;}
    for (k=j-1;k>=0;k--){plansza[i][k]=plansza[i][k]-1;}
    for (k=i+1;k<wys;k++){plansza[k][j]=plansza[k][j]-1;}
    for (k=j+1;k<szer;k++){plansza[i][k]=plansza[i][k]-1;}
}

bool Wieza:: czyNieBije(int  i,int  j,short int ** plansza,int szer,int wys){
    int pom=1;
    for(int m=0; m<wys; m++) {
        for(int k=0; k<szer; k++) {
            if(czyDanePoleBite(i,j,plansza,szer,wys,m,k) && plansza[m][k]<0) pom=0;
        }
    }   
    return pom;
}

bool Wieza:: czyDanePoleBite(int i, int j, short int **plansza, int szer, int wys, int dane_i, int dane_j){
    int pom=0;
    if((dane_i!=i && dane_j==j) || (dane_j!=j && dane_i==i)) pom=1;
    return pom;
}
Wieza::~Wieza(){};

/***********************************************************************************/
void Skoczek:: poloz_figura( int i, int j,short int **plansza, int szer, int wys){
    plansza[i][j]=-3;
    if (j-2>=0 && i-1>=0) plansza[i-1][j-2]=plansza[i-1][j-2]+1; 
    if (j-1>=0 && i-2>=0) plansza[i-2][j-1]=plansza[i-2][j-1]+1; 
    if (j+1<szer && i-2>=0) plansza[i-2][j+1]=plansza[i-2][j+1]+1; 
    if (j+2<szer && i-1>=0) plansza[i-1][j+2]=plansza[i-1][j+2]+1; 

    if (j-2>=0 && i+1<wys) plansza[i+1][j-2]=plansza[i+1][j-2]+1; 
    if (j-1>=0 && i+2<wys) plansza[i+2][j-1]=plansza[i+2][j-1]+1;
    if (j+1<szer && i+2<wys) plansza[i+2][j+1]=plansza[i+2][j+1]+1;
    if (j+2<szer && i+1<wys) plansza[i+1][j+2]=plansza[i+1][j+2]+1;
}

void Skoczek:: usun_figura(int i, int j,short int **plansza, int szer, int wys){
    plansza[i][j]=0;
    if (j-2>=0 && i-1>=0) plansza[i-1][j-2]=plansza[i-1][j-2]-1; 
    if (j-1>=0 && i-2>=0) plansza[i-2][j-1]=plansza[i-2][j-1]-1; 
    if (j+1<szer && i-2>=0) plansza[i-2][j+1]=plansza[i-2][j+1]-1; 
    if (j+2<szer && i-1>=0) plansza[i-1][j+2]=plansza[i-1][j+2]-1; 

    if (j-2>=0 && i+1<wys) plansza[i+1][j-2]=plansza[i+1][j-2]-1; 
    if (j-1>=0 && i+2<wys) plansza[i+2][j-1]=plansza[i+2][j-1]-1;
    if (j+1<szer && i+2<wys) plansza[i+2][j+1]=plansza[i+2][j+1]-1;
    if (j+2<szer && i+1<wys) plansza[i+1][j+2]=plansza[i+1][j+2]-1;
}

bool Skoczek:: czyNieBije(int  i,int  j,short int ** plansza,int szer,int wys){
    int pom=1;
    for(int m=0; m<wys; m++){
        for(int k=0; k<szer; k++) {
            if(czyDanePoleBite(i,j,plansza,szer,wys,m,k) && plansza[m][k]<0) pom=0;
        }
      }
    return pom;
}
bool Skoczek:: czyDanePoleBite(int i, int j, short int **plansza, int szer, int wys, int dane_i, int dane_j){
    int pom=0;
    if((dane_i==i-1 && dane_j==j-2) ||(dane_i==i-2 && dane_j==j-1) ||(dane_i==i-2 && dane_j==j+1) ||(dane_i==i-1 && dane_j==j+2) ) pom=1;
    if((dane_i==i+1 && dane_j==j-2) ||(dane_i==i+2 && dane_j==j-1) ||(dane_i==i+2 && dane_j==j+1) ||(dane_i==i+1 && dane_j==j+2) ) pom=1;
    return pom;
}
Skoczek::~Skoczek(){};

/***********************************************************************************/

void Hetman:: poloz_figura( int i, int j,short int **plansza, int szer, int wys){
    plansza[i][j]=-4;
    int k;

    for (k=i-1;k>=0;k--){plansza[k][j]=plansza[k][j]+1;}
    for (k=j-1;k>=0;k--){plansza[i][k]=plansza[i][k]+1;}
    for (k=i+1;k<wys;k++){plansza[k][j]=plansza[k][j]+1;}
    for (k=j+1;k<szer;k++){plansza[i][k]=plansza[i][k]+1;}

    int m;
    for (k=i-1, m=j-1;k>=0&&m>=0;k--, m--){plansza[k][m]=plansza[k][m]+1;}
    for (k=i-1, m=j+1;k>=0 && m<szer;k--,m++){plansza[k][m]=plansza[k][m]+1;}
    for (k=i+1, m=j+1;k<wys && m<szer;k++, m++){plansza[k][m]=plansza[k][m]+1;}
    for (k=i+1, m=j-1;k<wys && m>=0;k++, m--){plansza[k][m]=plansza[k][m]+1;}
}

void Hetman:: usun_figura(int i, int j,short int **plansza, int szer, int wys){
    plansza[i][j]=0;
    int k;

    for (k=i-1;k>=0;k--){plansza[k][j]=plansza[k][j]-1;}
    for (k=j-1;k>=0;k--){plansza[i][k]=plansza[i][k]-1;}
    for (k=i+1;k<wys;k++){plansza[k][j]=plansza[k][j]-1;}
    for (k=j+1;k<szer;k++){plansza[i][k]=plansza[i][k]-1;}

    int m;
    for (k=i-1, m=j-1;k>=0&&m>=0;k--, m--){plansza[k][m]=plansza[k][m]-1;}
    for (k=i-1, m=j+1;k>=0 && m<szer;k--,m++){plansza[k][m]=plansza[k][m]-1;}
    for (k=i+1, m=j+1;k<wys && m<szer;k++, m++){plansza[k][m]=plansza[k][m]-1;}
    for (k=i+1, m=j-1;k<wys && m>=0;k++, m--){plansza[k][m]=plansza[k][m]-1;}
}

bool Hetman:: czyNieBije(int  i,int  j,short int ** plansza,int szer,int wys){
    int pom=1;
    for(int m=0; m<wys; m++){
        for(int k=0; k<szer; k++) {
                if(czyDanePoleBite(i,j,plansza,szer,wys,m,k) && plansza[m][k]<0) pom=0;
            }
        }
    return pom;
}
bool Hetman:: czyDanePoleBite(int i, int j, short int **plansza, int szer, int wys, int dane_i, int dane_j){
    int pom=0;
    if((dane_i!=i && dane_j==j) || (dane_j!=j && dane_i==i)) pom=1;
    if((i-dane_i==j-dane_j) || i-dane_i==(-1)*(j-dane_j)) pom=1;
    return pom;
}
Hetman::~Hetman(){};

/***********************************************************************************/
void Goniec:: poloz_figura( int i, int j,short int **plansza, int szer, int wys){
    plansza[i][j]=-5;
    int k;
    int m;
    for (k=i-1, m=j-1;k>=0&&m>=0;k--, m--){plansza[k][m]=plansza[k][m]+1;}
    for (k=i-1, m=j+1;k>=0 && m<szer;k--,m++){plansza[k][m]=plansza[k][m]+1;}
    for (k=i+1, m=j+1;k<wys && m<szer;k++, m++){plansza[k][m]=plansza[k][m]+1;}
    for (k=i+1, m=j-1;k<wys && m>=0;k++, m--){plansza[k][m]=plansza[k][m]+1;}
}

void Goniec:: usun_figura(int i, int j,short int **plansza, int szer, int wys){
    plansza[i][j]=0;   
    int k;
    int m;
    for (k=i-1, m=j-1;k>=0&&m>=0;k--, m--){plansza[k][m]=plansza[k][m]-1;}
    for (k=i-1, m=j+1;k>=0 && m<szer;k--,m++){plansza[k][m]=plansza[k][m]-1;}
    for (k=i+1, m=j+1;k<wys && m<szer;k++, m++){plansza[k][m]=plansza[k][m]-1;}
    for (k=i+1, m=j-1;k<wys && m>=0;k++, m--){plansza[k][m]=plansza[k][m]-1;}
}

bool Goniec:: czyNieBije(int  i,int  j,short int ** plansza,int szer,int wys){
    int pom=1;
    for(int m=0; m<wys; m++){
      for(int k=0; k<szer; k++) {
          if(czyDanePoleBite(i,j,plansza,szer,wys,m,k) && plansza[m][k]<0) pom=0;
      }
    }

    return pom;
}

bool Goniec:: czyDanePoleBite(int i, int j, short int **plansza, int szer, int wys, int dane_i, int dane_j){
    int pom=0;
    if((i-dane_i==j-dane_j) || i-dane_i==(-1)*(j-dane_j)) pom=1;
    return pom;
}
Goniec:: ~Goniec(){};

/***********************************************************************************/

void PionCz:: poloz_figura( int i, int j,short int **plansza, int szer, int wys){
    plansza[i][j]=-6;

    if(j+1<szer && i+1<wys) plansza [i+1][j+1]=plansza [i+1][j+1]+1;
    if(j-1>=0 && i+1<wys ) plansza [i+1][j-1]=plansza [i+1][j-1]+1;
}
     
void PionCz:: usun_figura(int i, int j,short int **plansza, int szer, int wys){
    plansza[i][j]=0;
    if(j+1<szer && i+1<wys) plansza [i+1][j+1]=plansza [i+1][j+1]-1;
    if(j-1>=0 && i+1<wys ) plansza [i+1][j-1]=plansza [i+1][j-1]-1;
}

bool PionCz:: czyNieBije(int  i,int  j,short int ** plansza,int szer,int wys){
    int pom=1;
    for(int m=0; m<wys; m++){
      for(int k=0; k<szer; k++) {
          if(czyDanePoleBite(i,j,plansza,szer,wys,m,k) && plansza[m][k]<0) pom=0;
      }
    }
    return pom;
}
bool PionCz:: czyDanePoleBite(int i, int j, short int **plansza, int szer, int wys, int dane_i, int dane_j){
    int pom=0;
    if((dane_i==i+1 && dane_j==j+1) || (dane_i==i+1 && dane_j==j-1)) pom=1;
    return pom;
}
PionCz::~PionCz(){};
/***********************************************************************************/

void PionB:: poloz_figura( int i, int j,short int **plansza, int szer, int wys){
    plansza[i][j]=-7;
    if(j-1>=0 && i-1>=0) plansza [i-1][j-1]=plansza [i-1][j-1]+1;
    if(j+1<szer && i-1>=0) plansza [i-1][j+1]=plansza [i-1][j+1]+1;
}
void PionB:: usun_figura(int i, int j,short int **plansza, int szer, int wys){
    plansza[i][j]=0;
    if(j-1>=0 && i-1>=0) plansza [i-1][j-1]=plansza [i-1][j-1]-1;
    if(j+1<szer && i-1>=0) plansza [i-1][j+1]=plansza [i-1][j+1]-1;
}

bool PionB:: czyNieBije(int  i,int  j,short int ** plansza,int szer,int wys){
    int pom=1;
    for(int m=0; m<wys; m++){
      for(int k=0; k<szer; k++) {
        if(czyDanePoleBite(i,j,plansza,szer,wys,m,k) && plansza[m][k]<0) pom=0;
      }
    }        
    return pom;
}
bool PionB:: czyDanePoleBite(int i, int j, short int **plansza, int szer, int wys, int dane_i, int dane_j){
    int pom=0;
    if((dane_i==i-1 && dane_j==j+1) || (dane_i==i-1 && dane_j==j-1)) pom=1;
    return pom;
}
PionB:: ~PionB(){};

/***********************************************************************************/

/* Funkcja, która w zależności od zadanej wartości enum konstruuje obiekt odpowiedniej klasy*/

Figura* FiguryFactory:: getFigury(genre_e genre) {
    Figura *figur = NULL;

    switch(genre) {
      case KROL:
         figur = new Krol();
         break;
       case WIEZA:
         figur = new Wieza();
          break;
       case SKOCZEK:
         figur = new Skoczek();
         break;
       case HETMAN:
         figur= new Hetman();
         break;
       case GONIEC:
         figur= new Goniec();
         break;
       case PION_CZ:
         figur = new PionCz();
         break;
       case PION_B:
         figur = new PionB();
         break;
    }
    return figur;
}
