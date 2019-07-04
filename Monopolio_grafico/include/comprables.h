//
// Created by fabrizio on 5/31/19.
//

#ifndef PROYECTO_COMPRABLES_H
#define PROYECTO_COMPRABLES_H


#include <string>
#include "casilla.h"
class tablero;

class comprables: public casilla {
public:
    int precio;
    int alquiler,pagar;
    Jugador* dueno;
    bool disponible;
    bool hipotecado;
    comprables(std::string nombre, int precio, int alquiler):casilla{nombre}
    ,precio{precio},pagar{alquiler},disponible{true},dueno{nullptr},alquiler{alquiler},
    hipotecado{false}{}
    virtual void set_alquiler(){}
    void ejecutar(Jugador* huesped)override;
};

class propiedades: public comprables{
public:
    string color;
    int casas;
    int precio_casa;
    propiedades(string nombre,string color, int precio, int alquiler,int precio_casa)
    :comprables(nombre,precio,alquiler),color{color},precio_casa{precio_casa},casas{0}{}
    void set_alquiler()override;
};

class ferrocarril: public comprables{
public:
    ferrocarril(string nombre, int precio, int alquiler):comprables(nombre,precio,alquiler){}
    void set_alquiler()override;

};

class compania:public  comprables{
public:
    compania(string nombre, int precio, int alquiler):comprables(nombre,precio,alquiler){}
    void set_alquiler()override;
};

#endif //PROYECTO_COMPRABLES_H
