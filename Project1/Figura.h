#pragma once
#include <iostream>
using namespace std;
class Menu {//Clase que corre el programa desde main
private:
    int seleccion;
public:
    Menu(int);
    void eleccion();
};
class Figura {//Desarrolamos la clase padre
private:
    int Largo;
public:
    Figura(int);
    virtual void draw();//Se crea el metodo "virtual void draw" para implementra polimorfismo en las clases hijas
};
class Cuadrado : public Figura {//clase hija 1 cuadrado 
private:
    int largoC;
public:
    Cuadrado(int, int);
    void draw();
};
class Rectangulo : public Figura {//clase hija 2 rectangulo
private:
    int largoR, anchoR;
public:
    Rectangulo(int, int, int);
    void draw();
};
class Triangulo :public Figura {//clase hija 3 triangulo
private:
    int largoT;
public:
    Triangulo(int, int);
    void draw();
};//En cada clase se esta implemtando el metodo draw

Menu::Menu(int _seleccion) {
    seleccion = _seleccion;
}
Figura::Figura(int _largo) {//Inicializacion de las variables de Figura
    Largo = _largo;

}
Cuadrado::Cuadrado(int _largo, int _largoC) : Figura(_largo) {//Inicializacion de las variables de Cuadrado
    largoC = _largoC;
}
Rectangulo::Rectangulo(int _largo, int _anchoC, int _largoR) : Figura(_largo) {//Inicializacion de las variables de Rectangulo
    largoR = _largoR;
    anchoR = _anchoC;
}
Triangulo::Triangulo(int _largo, int _largoT) : Figura(_largo) {//Inicializacion de las variables de Triangulo
    largoT = _largoT;
}


void Figura::draw() {//Definimos metodo

}
void Menu::eleccion()//Metodo que sera llamado al main
{
    int sel;
    do {
        cout << "\tQue desea hacer?" << endl;
        cout << "1.Cuadrado" << endl;
        cout << "2.Rectangulo" << endl;
        cout << "3.trangulo " << endl;
        cout << "0.salir " << endl;
        Figura* f1[3];
        cin >> sel;

        switch (sel)
        {
        case 1:
            f1[0] = new Cuadrado(0, 0);//Se crea cuadrado
            f1[0]->draw();
            break;
        case 2:
            f1[1] = new Rectangulo(0, 0, 0);//Se crea rectangulo
            f1[1]->draw();
            break;
        case 3:
            f1[2] = new Triangulo(0, 0);//Se crea trangulo
            f1[2]->draw();
            break;
        }
    } while (sel != 0);
}
void Cuadrado::draw() {//Definimos metodo para dibujar cuadrado (relleno o hueco)
    Figura::draw();//<-Aqui se esta utlizando polimorfismo
    int tipo;
    cout << "Que tipo de cuadrado quieres" << endl;
    cout << "1.Relleno" << endl;
    cout << "0.Hueco" << endl;
    cin >> tipo;
    cout << "Seleccione el tamaño de la figura: " << endl;
    cin >> largoC;
    if (tipo == 1) 
    {
        for (int i = 0; i < largoC; i++)
        {
            for (int j = 0; j < largoC; j++) 
            {
                cout << "* ";
            }
            cout << endl;
        }
    }
    else {
        for (int i = 0; i < largoC; i++) 
        {
            for (int j = 0; j < largoC; j++) 
            {
                if ((i == 0) || (j == 0) || (i == largoC - 1) || (j == largoC - 1)) {
                    cout << "*";
                }
                else {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

}
void Rectangulo::draw() {//Definimos metodo para dibujar rectangulo.
    Figura::draw();

    cout << "Seleccione el largo de la figura: " << endl;
    cin >> largoR;
    cout << "Seleccione el ancho de la figura: " << endl;
    cin >> anchoR;

    for (int i = 0; i < largoR; i++) {
        for (int j = 0; j < anchoR; j++) {
            cout << "* ";

        }
        cout << endl;
    }

}
void Triangulo::draw() {//Definimos metodo para dibujar triangulo.
    Figura::draw();

    cout << "Seleccione el Tamaño de la figura: " << endl;
    cin >> largoT;
    for (int i = 0; i < largoT; i++) {
        for (int j = 0; j < i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}


