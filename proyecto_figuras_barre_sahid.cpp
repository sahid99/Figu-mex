#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <time.h>

using namespace std;

struct forma{
    int lado;
    int altura;
    int radio;
    char nombre;
    int colores;
};

void cuadrado(int lado);
void tria_equi(int lado);
void tria_iso(int lado);
void recta(int base, int altura);
void circulo(int radio);
void trapecio(int base_ma, int base_me);
void rombo(int lado);
void circu(int lado);
int color();
void que_color(int tono);

WORD GetConsoleTextAttribute (HANDLE hCon)
{
  CONSOLE_SCREEN_BUFFER_INFO con_info;
  GetConsoleScreenBufferInfo(hCon, &con_info);
  return con_info.wAttributes;
}

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int saved_colors = GetConsoleTextAttribute(hConsole);

void cuadrado(int lado){
    int i, k;
    for(i=0; i<lado; i++){
        for(k=0; k<lado; k++){
            printf("[]");
        }
        printf("\n");
    }
}
void tria_equi(int lado){
    int mitad, i, k, j;
    mitad = lado -1;
    for(i=0; i<lado; i++){
        for(k=0; k<mitad; k++){
            cout << " ";
        }
        for(j=0; j<=i; j++){
            cout << "* ";
        }
        cout << endl;
        mitad--;
    }
}
void tria_iso(int lado){
    int i, k;
    for(i=1; i<=lado; i++){
        for(k=1; k<=lado-i; k++){
            cout << " ";
        }
        for(k=1; k<=(2*i)-1; k++){
            cout << "*";
        }
        cout << endl;
    }

}
void recta(int base, int altura){
    int i, k;
    for(i=0; i<altura; i++){
        for(k=0; k<base; k++){
            cout << "[]";
        }
        cout << endl;
    }
}
void rombo(int lado){
    int i, k, j, mitad, n=0;
    mitad = lado -1;
    for(i=0; i<lado; i++){
        for(k=0; k<mitad; k++){
            cout << " ";
        }
        for(j=0; j<=i; j++){
            cout << "* ";
        }
        cout << endl;
        mitad--;
    }
    mitad = lado -1;
    for(i=lado-2; i>=0; i--){
        for(k=0; k<=n; k++){
            cout << " ";
        }
        for(j=0; j<=i; j++){
            cout << "* ";
        }
        n++;
        cout << endl;
        mitad--;
    }
}
void trapecio(int base_ma, int base_me){
    int mitad, i, k, j;
    mitad = base_ma -1;
    for(i=base_me-1; i<base_ma; i++){
        for(k=0; k<mitad; k++){
            cout << " ";
        }
        for(j=0; j<=i; j++){
            cout << "* ";
        }
        cout << endl;
        mitad--;
    }
}

void circu(int lado){
   for (int j=0; j<=lado*2; j++){
      for (int i=0; i<=lado*2; i++){
        if (pow(i-lado,2.0)+ pow(j-lado,2.0)<= pow(lado,2))
            cout << "*";
            else
            cout << " ";

    }
      cout << endl;
    }
}

int a_cuadra(int lado);
int a_cuadra(int lado){
    int area = lado * lado;
    return area;
}
float a_tequi(int lado);
float a_tequi(int lado){
    float a = lado * lado;
    float area = (sqrt(3)/4)*a;
    return area;
}
int a_recta(int base, int altura);
int a_recta(int base, int altura){
    int area = base * altura;
    return area;
}
float a_trape(int baMayo, int baMeno);
float a_trape(int baMayo, int baMeno){
    float area = ((baMayo + baMeno)*((baMayo - baMeno)+1)*1.0)/2.0;
    return area;
}
float a_rombo(int lado);
float a_rombo(int lado){
    float area = (((lado*2.0)-1)*lado)/2.0;
    return area;
}

int pe_cuadra(int lado);
int pe_cuadra(int lado){
    int perime;
    perime=lado*4;
    return perime;
}

int pe_trian(int lado);
int pe_trian(int lado){
    int perime;
    perime = lado*3;
    return perime;
}

int pe_recta(int lado, int base);
int pe_recta(int lado, int base){
    int perime;
    perime = (lado*2) + (base*2);
    return perime;
}

float pe_rombo(int lado);
float pe_rombo(int lado){
    float perime;
    float ledo;
    ledo = lado*1.0;
    perime = (sqrt(pow(ledo,2) + pow(ledo/2,2)))*4;
    return perime;
}

float pe_trap(int ba_ma, int ba_me);
float pe_trap(int ba_ma, int ba_me){
    float perime;
    float alt, diago;
    alt = (ba_ma - ba_me)*1.0;
    diago = sqrt(pow(alt,2) + pow((alt/2),2));
    perime = ba_ma + ba_me + (diago*2);
    return perime;
}

float alt_tria(int lado);
float alt_tria(int lado){
    float altur;
    float ledo;
    ledo = lado*1.0;
    altur = sqrt(pow(ledo,2) - pow(ledo/2,2));
    return altur;
}

float a_circu(int lado);
float a_circu(int lado){
    float pi;
    pi = 3.1416;
    float area;
    area = pi * pow(lado,2);
    return area;
}
float pe_circu(int lado);
float pe_circu(int lado){
    float pi, perime;
    pi = 3.1416;
    perime = (lado*2)*pi;
    return perime;
}
float a_iso(int lado);
float a_iso(int lado){
    float area;
    float diago;
    diago = lado*1.0;
    area = (diago * ((diago*2)-1))/2;
    return area;
}
float pe_iso(int lado);
float pe_iso(int lado){
    float perime;
    float diago;
    diago = lado*1.0;
    perime = diago + sqrt(pow((diago - 0.5),2) + pow(diago,2))*2;
    return perime;
}

void data(forma figura[100], int n);
void data(forma figura[100], int n){
    if(n==0){
        cout << "Sin Datos" << endl;
    }
    else{
    for(int j=0; j<n; j++){
            float perime=0;
        if(figura[j].nombre=='c'){
            cout << "Cuadrado" << endl;
            cout << " Lado: " << figura[j].lado << endl;
            cout << " Area: " << a_cuadra(figura[j].lado)<< endl;
            perime = pe_cuadra(figura[j].lado);
            cout << " Perimetro: " << perime << endl;
            que_color(figura[j].colores);
            cout << endl;
        }
        if(figura[j].nombre=='t'){
            cout << "Triangulo Equilatero" << endl;
            cout << " Base: " << figura[j].lado << endl;
            cout << " Altura: " << alt_tria(figura[j].lado) << endl;
            cout << " Area: " << a_tequi(figura[j].lado) << endl;
            perime = pe_trian(figura[j].lado);
            cout << " Perimetro: " << perime << endl;
            que_color(figura[j].colores);
            cout << endl;
        }
        if(figura[j].nombre=='s'){
            cout << "Triangulo Isosceles" << endl;
            cout << " Base: " << (figura[j].lado*2)-1 << endl;
            cout << " Altura: " << figura[j].lado << endl;
            cout << " Area: " << a_iso(figura[j].lado) << endl;
            perime = pe_iso(figura[j].lado);
            cout << " Perimetro: " << perime << endl;
            que_color(figura[j].colores);
            cout << endl;
        }
        if(figura[j].nombre=='o'){
            cout << "Rombo" << endl;
            cout << " Diagonal Menor: " << figura[j].lado << endl;
            cout << " Diagonal Mayor: " << alt_tria(figura[j].lado)*2 << endl;
            cout << " Area: " << a_rombo(figura[j].lado) << endl;
            perime = pe_rombo(figura[j].lado);
            cout << " Perimetro: " << perime << endl;
            que_color(figura[j].colores);
            cout << endl;
        }
        if(figura[j].nombre=='a'){
            cout << "Trapecio" << endl;
            cout << " Base Mayor: " << figura[j].lado << endl;
            cout << " Base Menor: " << figura[j].altura << endl;
            cout << " Altura: " << (figura[j].lado-figura[j].altura)+1 << endl;
            cout << " Area: " << a_trape(figura[j].lado, figura[j].altura) << endl;
            perime = pe_trap(figura[j].lado, figura[j].altura);
            cout << " Perimetro: " << perime << endl;
            que_color(figura[j].colores);
            cout << endl;
        }
        if(figura[j].nombre== 'e'){
            cout << "Rectangulo" << endl;
            cout << " Base: " << figura[j].lado << endl;
            cout << " Altura: " << figura[j].altura << endl;
            cout << " Area: " << a_recta(figura[j].lado, figura[j].altura) << endl;
            perime = pe_recta(figura[j].lado, figura[j].altura);
            cout << " Perimetro: " << perime << endl;
            que_color(figura[j].colores);
            cout << endl;
        }
        if(figura[j].nombre== 'i'){
            cout << "Circulo" << endl;
            cout << " Radio: " << figura[j].lado << endl;
            cout << " Area: " << a_circu(figura[j].lado) << endl;
            perime = pe_circu(figura[j].lado);
            cout << " Perimetro: " << perime << endl;
            que_color(figura[j].colores);
            cout << endl;
        }
    }
  }

}

void menu();
void menu(){


    SetConsoleTextAttribute(hConsole, 04|  FOREGROUND_INTENSITY);
    cout << "\311\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\273";
    SetConsoleTextAttribute(hConsole, 15| FOREGROUND_INTENSITY);
    cout << "\272\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\272";
    cout << "\272\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260 BIENVENIDO A FIGUMEX \260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\272";
    cout << "\272\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\272";
    SetConsoleTextAttribute(hConsole, 02| FOREGROUND_INTENSITY);
    cout << "\310\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\274";
    SetConsoleTextAttribute(hConsole, 15| FOREGROUND_INTENSITY);
    cout << endl << "                                 \257 Este es un programa para trazar figuras, disfrutalo. \256" << endl;
    SetConsoleTextAttribute(hConsole, 15| FOREGROUND_INTENSITY);
    cout << endl << " Las figuras disponibles son:" << endl << endl;
    SetConsoleTextAttribute(hConsole, 07| FOREGROUND_INTENSITY);
    cout << " CUADRADO            RECTANGULO           EQUILATERO          ROMBO           CIRCULO         TRAPECIO" << endl;
    cout << "                                          ISOSCELES    " << endl << endl;
    SetConsoleTextAttribute(hConsole, 07| FOREGROUND_INTENSITY);

    cout << "  \334\334\334\334\334\334             \334\334\334\334\334\334\334\334\334\334               \334                \334               \334\334              \334\334\334\334\334"    << endl;
    cout << "  \334\334\334\334\334\334             \334\334\334\334\334\334\334\334\334\334             \334\334\334\334\334            \334\334\334\334\334            \334\334\334\334           \334\334\334\334\334\334\334\334\334" << endl;
    cout << "  \334\334\334\334\334\334             \334\334\334\334\334\334\334\334\334\334            \334\334\334\334\334\334\334             \334               \334\334           \334\334\334\334\334\334\334\334\334\334\334 " << endl;

    cout << endl << endl;
    SetConsoleTextAttribute(hConsole, 04| FOREGROUND_INTENSITY);
    cout << "\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262";
    SetConsoleTextAttribute(hConsole, 15| FOREGROUND_INTENSITY);
    cout << "\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262 ESCRIBE CON MINUSCULAS LA FIGURA QUE DESEES. \262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262";
    cout << "\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262      ESCRIBE MENU O SALIR SEGUN DESEES.      \262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262";
    SetConsoleTextAttribute(hConsole, 02| FOREGROUND_INTENSITY);
    cout << "\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262\262";
    SetConsoleTextAttribute(hConsole, saved_colors);
}


int color(){
    int num;
    srand(time(NULL));
    num = 1 + rand() % (6);
    if(num==1){
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    }
    if(num==3){
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    }
    if(num==5){
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    }
    if(num==2){
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    }
    if(num==4){
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
    }
    if(num==6){
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    return num;
}


void que_color(int num){
    if(num==1){
        cout << " Color: Azul" << endl;
    }
    if(num==3){
        cout << " Color: Verde" << endl;
    }
    if(num==5){
        cout << " Color: Rojo" << endl;
    }
    if(num==2){
        cout << " Color: Amarillo" << endl;
    }
    if(num==4){
        cout << " Color: Magenta" << endl;
    }
    if(num==6){
        cout << " Color: Cyan" << endl;
    }
}

string instru = "none";
int main()
{

    int q=0;

    forma figura[100];

    float area = 0;
    float perime = 0;
    menu();

    do{
        cin >> instru;
    if(instru == "cuadrado"){
        cout << "De cuanto el lado" <<endl;
        cin >>  figura[q].lado;
        system("cls");
        figura[q].nombre = 'c';
        figura[q].colores = color();
        cuadrado(figura[q].lado);
        SetConsoleTextAttribute(hConsole, saved_colors);
        area = a_cuadra(figura[q].lado);
        cout << " Figura: Cuadrado" << endl;
        cout << " Lado: " << figura[q].lado << endl;
        cout << " Area: " << area << endl;
        perime = pe_cuadra(figura[q].lado);
        cout << " Perimetro: " << perime << endl;
        que_color(figura[q].colores);
        q++;
    }
    if(instru == "equilatero"){
        cout << "De cuanto la base" << endl;
        cin >> figura[q].lado;
        system("cls");
        figura[q].colores = color();
        tria_equi(figura[q].lado);
        SetConsoleTextAttribute(hConsole, saved_colors);
        figura[q].nombre= 't';
        cout << "Figura: Triangulo Equilatero" << endl;
        cout << " Base: " << figura[q].lado << endl;
        cout << " Altura: " << alt_tria(figura[q].lado) << endl;
        area= a_tequi(figura[q].lado);
        cout << " Area: " << area << endl;
        perime = pe_trian(figura[q].lado);
        cout << " Perimetro: " << perime << endl;
        que_color(figura[q].colores);
        q++;
        }
    if(instru == "isosceles"){
        cout << "De cuanto la altura" << endl;
        cin >> figura[q].lado;
        system("cls");
        figura[q].colores = color();
        tria_iso(figura[q].lado);
        SetConsoleTextAttribute(hConsole, saved_colors);
        figura[q].nombre= 's';
        cout << "Figura: Triangulo Isosceles" << endl;
        cout << " Base: " << (figura[q].lado*2)-1 << endl;
        cout << " Altura: " << figura[q].lado << endl;
        area = a_iso(figura[q].lado);
        cout << " Area: " << area << endl;
        perime = pe_iso(figura[q].lado);
        cout << " Perimetro: " << perime << endl;
        que_color(figura[q].colores);
        q++;
        }
    if(instru == "rombo"){
        cout << "De cuanto la diagonal menor" << endl;
        cin >> figura[q].lado;
        system("cls");
        figura[q].nombre= 'o';
        figura[q].colores = color();
        rombo(figura[q].lado);
        SetConsoleTextAttribute(hConsole, saved_colors);
        area = a_rombo(figura[q].lado);
        cout << "Figura: Rombo" << endl;
        cout << " Diagonal Menor: " << figura[q].lado << endl;
        cout << " Diagonal Mayor: " << alt_tria(figura[q].lado)*2 << endl;
        cout << " Area: " << area << endl;
        perime = pe_rombo(figura[q].lado);
        cout << " Perimetro: " << perime << endl;
        que_color(figura[q].colores);
        q++;
        }
    if(instru == "trapecio"){
        cout << "Dame la base mayor" << endl;
        cin >> figura[q].lado;
        figura[q].nombre= 'a';
        cout << "Dame la base menor" << endl;
        cin >> figura[q].altura;
        system("cls");
        figura[q].colores = color();
        trapecio(figura[q].lado, figura[q].altura);
        SetConsoleTextAttribute(hConsole, saved_colors);
        cout << "Figura: Trapecio" << endl;
        cout << " Base Mayor: " << figura[q].lado << endl;
        cout << " Base Menor: " << figura[q].altura << endl;
        cout << " Altura: " << (figura[q].lado - figura[q].altura)+1 << endl;
        area = a_trape(figura[q].lado, figura[q].altura);
        cout << " Area: " << area << endl;
        perime = pe_trap(figura[q].lado, figura[q].altura);
        cout << " Perimetro: " << perime << endl;
        que_color(figura[q].colores);
        q++;
    }
    if(instru == "rectangulo"){
        cout << "Dame la base" << endl;
        cin >> figura[q].lado;
        figura[q].nombre= 'e';
        cout << "Dame la altura" << endl;
        cin >> figura[q].altura;
        system("cls");
        figura[q].colores = color();
        recta(figura[q].lado, figura[q].altura);
        SetConsoleTextAttribute(hConsole, saved_colors);
        cout << "Figura: Rectangulo" << endl;
        cout << " Base: " << figura[q].lado << endl;
        cout << " Altura: " << figura[q].altura << endl;
        area = a_recta(figura[q].lado, figura[q].altura);
        cout << " Area: " << area << endl;
        perime = pe_recta(figura[q].lado, figura[q].altura);
        cout << " Perimetro: " << perime << endl;
        que_color(figura[q].colores);
        q++;

    }
     if(instru == "circulo"){
        cout << "Dame el radio" << endl;
        cin >> figura[q].lado;
        system("cls");
        figura[q].nombre= 'i';
        figura[q].colores = color();
        circu(figura[q].lado);
        SetConsoleTextAttribute(hConsole, saved_colors);
        cout << "Figura: Circulo" << endl;
        cout << " Radio: " << figura[q].lado << endl;
        area = a_circu(figura[q].lado);
        cout << " Area: " << area << endl;
        perime = pe_circu(figura[q].lado);
        cout << " Perimetro: " << perime << endl;
        que_color(figura[q].colores);
        q++;

    }

    if(instru == "datos"){
            system("cls");
        data(figura, q);
    }
    if(instru == "menu"){
            system("cls");
        menu();
    }

    }while(instru != "salir");
    cout << "Hasta luego" << endl;
    return 0;
}
