//
// Created by fabrizio on 5/31/19.
//

#include <iostream>
#include <ctime>
#include "tablero.h"
#include "comprables.h"
#include "accion.h"
//template<typename T>
casilla* tablero::crear(int i) {
    casilla* casilla;
    switch (i) {
        case 0:
            casilla = new Go("Go");
            break;
        case 1:
            casilla = new propiedades("Av. Mediterraneo","Marron", 60, 2, 50);
            break;
        case 2:
            casilla = new ArcaComunal("Arca Comunal");
            break;
        case 3:
            casilla = new propiedades("Av. Báltica","Marron", 60, 4, 50);
            break;
        case 4:
            casilla = new Impuesto("Impuesto",200,0.1);
            break;
        case 5:
            casilla = new ferrocarril("Ferrocarril Reading", 200, 50);
            break;
        case 6:
            casilla = new propiedades("Av. Oriental","Celeste", 100, 6, 50);
            break;
        case 7:
            casilla = new Fortuna("Fortuna");
            break;
        case 8:
            casilla = new propiedades("Av. Vermont","Celeste", 100, 6, 50);
            break;
        case 9:
            casilla = new propiedades("Av. Connecticut","Celeste", 120, 8, 50);
            break;
        case 10:
            casilla = new Jail("Jail");
            break;
        case 11:
            casilla = new propiedades("Plaza San Carlos","Morado",140, 10, 100);
            break;
        case 12:
            casilla = new compania("Compañia de Luz", 150, 1);
            break;
        case 13:
            casilla = new propiedades("Av. Estados","Morado", 140, 10, 100);
            break;
        case 14:
            casilla = new propiedades("Av. Virginia","Morado", 160, 10, 100);
            break;
        case 15:
            casilla = new ferrocarril("Ferrocarril Pensilvania", 200, 50);
            break;
        case 16:
            casilla = new propiedades("Plaza St James","Naranja", 180, 14, 100);
            break;
        case 17:
            casilla = new ArcaComunal("Arca Comunal");
            break;
        case 18:
            casilla = new propiedades("Av. Tennessee","Naranja", 180, 14, 100);
            break;
        case 19:
            casilla = new propiedades("Av. New York","Naranja", 200, 16, 100);
            break;
        case 20:
            casilla = new ParadaLibre("Parada Libre");
            break;
        case 21:
            casilla = new propiedades("Av. Kentucky","Rojo", 220, 18, 150);
            break;
        case 22:
            casilla = new Fortuna("Fortuna");
            break;
        case 23:
            casilla = new propiedades("Av. Indiana","Rojo", 220, 18, 150);
            break;
        case 24:
            casilla = new propiedades("Av. Illinois","Rojo", 240, 20, 150);
            break;
        case 25:
            casilla = new ferrocarril("Ferrocarril By", 200, 50);
            break;
        case 26:
            casilla = new propiedades("Av. Atlantica","Amarillo", 260, 22, 150);
            break;
        case 27:
            casilla = new compania("Compañia de Agua", 150, 1);
            break;
        case 28:
            casilla = new propiedades("Av. Ventnor","Amarillo", 260, 22, 150);
            break;
        case 29:
            casilla = new propiedades("Jardines Marvin","Amarillo", 280, 24, 150);
            break;
        case 30:
            casilla = new GoToJail("Go To Jail");
            break;
        case 31:
            casilla = new propiedades("Av. Pacifico","Verde", 300, 26, 200);
            break;
        case 32:
            casilla = new propiedades("Av. Carolina Del Norte","Verde", 320, 28, 200);
            break;
        case 33:
            casilla = new ArcaComunal("Arca Comunal");
            break;
        case 34:
            casilla = new propiedades("Av. Pensilvania","Verde", 350, 35, 200);
            break;
        case 35:
            casilla = new ferrocarril("Ferrocaril Vía Rápida", 200, 50);
            break;
        case 36:
            casilla = new Fortuna("Fortuna");
            break;
        case 37:
            casilla = new propiedades("Plaza Park","Azul", 350, 35, 200);
            break;
        case 38:
            casilla = new Impuesto("Impuesto de Lujo",75,1);
            break;
        case 39:
            casilla = new propiedades("Paseo Tablado","Azul", 400, 50, 200);
            break;
    }


    return casilla;


}


tablero::tablero(){
    head_= nullptr;
    pozo=0;
    casilla* tail_= nullptr;
    for(int i=0;i<40;i++) {
        casilla *temp = crear(i);
        if (tail_ != nullptr)
            tail_->next = temp;
        else
            head_ = temp;
            tail_ = temp;
        if(tail_->nombre=="Jail")
        {
            jail=tail_;
        }
    }
    tail_->next=head_;

    srand(time(NULL));
bool posible1=true,posible2=true;
int i=0,j=0;
do{
    int x=rand()%20;
    for(auto item:Baraja_Fortuna){
        if(x==item){
            posible1=false;
        }
    }
    if(posible1){
        Baraja_Fortuna.push_back(x);
        i++;
    }
    posible1=true;
}while(i<20);
do{
    int x=rand()%20;
    for(auto item:Baraja_Arca){
        if(x==item){
            posible2=false;
        }
    }
    if(posible2){
        Baraja_Arca.push_back(x);
        j++;
    }
    posible2=true;
}while(j<20);
}

void tablero::imprimirtablero() {
    casilla* n=head_;
    do{
        std::cout<<n->nombre<<" ";
        n=n->next;
    }while(n!=head_);
}

