//
// Created by fabrizio on 5/31/19.
//

#ifndef PROYECTO_TABLERO_H
#define PROYECTO_TABLERO_H

#include "casilla.h"
#include <deque>
#include "accion.h"

class tablero {
public:
    casilla* head_;
    casilla* jail;
    int pozo;
    deque <int> Baraja_Arca;
    deque <int> Baraja_Fortuna;
    tablero();
    void imprimirtablero();
    casilla* crear(int i);
};


#endif //PROYECTO_TABLERO_H
