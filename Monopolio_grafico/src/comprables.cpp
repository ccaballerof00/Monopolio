//
// Created by fabrizio on 5/31/19.
//

#include <iostream>
#include "comprables.h"
#include "jugador.h"
#include "tablero.h"
using namespace std;

void comprables::ejecutar(Jugador* huesped) {
    string respuesta;
    if(disponible){
        do {
            cout << "Desea comprar la propiedad " << nombre <<" que cuesta "<<precio<<" y cuyo alquiler es de "<<alquiler<<endl;
            cin >> respuesta;
        }while(respuesta != "si" && respuesta !="no");
        if(respuesta=="si"){
            if(huesped->Dinero >= precio){
                huesped->Dinero -= precio;
                disponible = false;
                huesped->compradas.push_back(dynamic_cast<comprables*>(huesped->posicion));
                dueno = huesped;
                cout << huesped->nombre << " compro " << huesped->posicion->nombre << endl;
//               dynamic_cast<comprables*>(huesped->posicion)->set_alquiler();
                huesped->cambiar_alquileres();

            }
        }
        }
    else
   {
        if (hipotecado) {
            cout << "Se encuentra hipotecada" << endl;
        } else {
//            do {
                if (huesped->Dinero > alquiler) {
                    huesped->deuda=false;
                    if (dynamic_cast<compania*>(huesped->posicion) == nullptr) {
                        cout << "Debe pagarle a " << dueno->nombre << " un total de " << alquiler << endl;
                        huesped->Dinero -= alquiler;
                        dueno->Dinero += alquiler;
                    } else {
                        dado uno, dos;
                        cout << "Debe pagar " << alquiler * (uno.lanzar() + dos.lanzar()) << endl;
                        huesped->Dinero -= alquiler * (uno.lanzar() + dos.lanzar());
                        dueno->Dinero += alquiler * (uno.lanzar() + dos.lanzar());
                    }
                } else {
                    huesped->deuda=true;
                    cout<<"Debe pagar la deuda para seguir jugando o se declara en bancarrota"<<endl;
                    cout<<"1) Seguir jugando"<<endl;
                    cout<<"2) Declararse en bancarrota"<<endl;
                    int r;
                    cin>>r;
                    if(r==2){
                        huesped->bancarrota=true;
                        for(auto item:huesped->compradas){
                            item->dueno=dueno;
                            dueno->compradas.push_back(item);
                            huesped->compradas.pop_back();
                        }
                        dueno->Dinero+=huesped->Dinero;
                        huesped->Dinero=0;
                    }
                }
//            }while(huesped->Dinero<alquiler);
            }
        }
    }

void propiedades::set_alquiler() {
    int mismo_color = 0;
    if (casas == 0 & hipotecado!=1) {
        for (auto it:dueno->compradas) {
            if (color == dynamic_cast<propiedades *>(it)->color) {
                mismo_color++;

            }
        }
        if (color == "Azul" || color == "Marron") {
            if (mismo_color == 2) {
                alquiler = pagar * 2;
            } else
                alquiler = pagar;
        } else {
            if (mismo_color == 3) {
                alquiler = pagar * 2;
            } else
                alquiler = pagar;
        }
    }
    else if (casas<=1)
    {
        switch(casas)
        {
            case 1: alquiler=pagar*5/2;
                    break;
            case 2: alquiler=pagar*15/2;
                    break;
            case 3: alquiler=pagar*75/4;
                    break;
            case 4: alquiler=pagar*375/16;
                    break;
            case 5: alquiler=pagar*225/8;
                    break;
        }
    }
    else alquiler=pagar;
}
void ferrocarril::set_alquiler(){
    int numero_ferrocarriles=0;
    for(auto it:dueno->compradas){
        if(dynamic_cast<ferrocarril*>(it)){
            numero_ferrocarriles++;
        }
    }
    alquiler=25*pow(2,numero_ferrocarriles-1);

}

void compania::set_alquiler() {
    int numero_compania=0;
    for(auto it:dueno->compradas){
        if(dynamic_cast<compania*>(it)){
            numero_compania++;
        }
    }
    if(numero_compania==2){
        alquiler=10;
    }
    else
        alquiler=4;
}
