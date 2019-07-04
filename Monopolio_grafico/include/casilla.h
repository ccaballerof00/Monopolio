//
// Created by fabrizio on 5/31/19.
//

#ifndef PROYECTO_CASILLA_H
#define PROYECTO_CASILLA_H
#include <string>

using namespace std;

class Jugador;
class tablero;


class casilla {
public:
    string nombre;
    casilla* next;
    casilla(string nombre):nombre{nombre},next{nullptr}{}
    virtual void ejecutar(Jugador* huesped, tablero* Monopoly){};
    virtual void ejecutar(Jugador* huesped){};
};


#endif //PROYECTO_CASILLA_H
