//
// Created by alonso on 31/05/19.
//

#ifndef POOII_JUGADOR_H
#define POOII_JUGADOR_H

#include "SFML/Graphics.hpp"
#include<string>
#include <vector>
#include "casilla.h"
#include "dado.h"
#include "comprables.h"
#include "juego.h"

class Jugador{
public:
    Sprite ficha;
    casilla* posicion;
    int id, Dinero, turnos_seguidos;
    string nombre;
    bool free,deuda;
    vector<int> cartas_carcel={};
    vector<comprables*> compradas;
    bool bancarrota;



    Jugador(int id_, std::string nombre_){
        posicion = nullptr;
        id = id_;
        Dinero = 150;
        turnos_seguidos = 0;
        nombre = nombre_;
        free = true;
        deuda=false;
        bancarrota=false;
        compradas = {};

    }
    void avanzar(int casillas);
    void mostrar_propiedades();
    void hipotecar();
    void deshipotecar();
    void comprar_casas();
    void vender_casas();
    void opciones(vector<Jugador*> Orden);
    void negociar(vector<Jugador*> Orden);
    void en_carcel(dado* A, dado* B);
    void cambiar_alquileres();
    void set_ficha(Sprite f);

};


#endif //POOII_JUGADOR_H
