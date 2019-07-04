//
// Created by alonso on 31/05/19.
//

#include <iostream>
#include "jugador.h"
#include "comprables.h"
#include <algorithm>
#include <numeric>
using namespace std;

void Jugador::avanzar(int casillas) {
    for (int i = 0; i < casillas; i++){
        posicion = posicion->next;
        if(posicion->nombre=="Go")
        {
            Dinero+=200;
        }
    }

    cout<<"\nEl jugador "<<nombre<<" avanzó hasta la casilla "<<posicion->nombre<<std::endl;
}

void Jugador::mostrar_propiedades()
{
    if(!compradas.empty()) {
        cout<<"Las propiedades que posee el jugador "<<nombre<<" son: "<<endl;
    for(int i=0;  i < compradas.size(); i++){
        auto aux= dynamic_cast<propiedades*>(compradas[i]);
        if(aux!= nullptr){
            if(aux->casas!=5)
                cout<< i+1 << ". " << aux->nombre<<" con "<<aux->casas<<" casas y el alquiler es de "<<aux->alquiler<<endl;
            else
                cout<<i+1 << ". " << aux->nombre<<" con 1 hotel"<<endl;
        }
        else{

        cout<< i+1 << ". " << compradas[i]->nombre<<endl;
        }
    }
    }
    else
    {
        cout<<"El jugador "<<nombre<<" no posee propiedades"<<endl;
    }
}

void Jugador::comprar_casas() {
    cout << "A que propiedad quiere comprarle una casa" << endl;
    mostrar_propiedades();
    bool posible = true;
    int respuesta;
    cin >> respuesta;
    respuesta -= 1;
    int mismo_color = 0;
    //auto destino = dynamic_cast<propiedades *>(compradas[respuesta]);
    for (auto it:compradas) {
        auto aux = dynamic_cast<propiedades *>(it);
        if (dynamic_cast<propiedades *>(compradas[respuesta])->color == aux->color) {
            mismo_color++;
            if ( (dynamic_cast<propiedades *>(compradas[respuesta])->casas > aux->casas | dynamic_cast<propiedades *>(compradas[respuesta])->casas==5)){
                if (!dynamic_cast<comprables *>(compradas[respuesta])->hipotecado) {
                    posible = false;
                }
            }
        }
    }
    if (posible) {
        if (dynamic_cast<propiedades *>(compradas[respuesta])->color == "Azul" | dynamic_cast<propiedades *>(compradas[respuesta])->color == "Marron") {
            if (mismo_color < 2) {
                cout << "Le faltan propiedades del mismo color" << endl;
            } else {
                if (Dinero > dynamic_cast<propiedades *>(compradas[respuesta])->precio_casa) {
                    Dinero -= dynamic_cast<propiedades *>(compradas[respuesta])->precio_casa;
                    dynamic_cast<propiedades *>(compradas[respuesta])->casas++;
                    dynamic_cast<propiedades*>(compradas[respuesta])->set_alquiler();
                    cout << "Compraste una casa" << endl;
                } else {
                    cout << "No tienes dinero" << endl;
                }
            }
        } else {
            if (mismo_color < 3) {
                cout << "Le faltan propiedades del mismo color" << endl;
            } else {
                if (Dinero > dynamic_cast<propiedades *>(compradas[respuesta])->precio_casa) {
                    Dinero -= dynamic_cast<propiedades *>(compradas[respuesta])->precio_casa;
                    dynamic_cast<propiedades *>(compradas[respuesta])->casas++;
                    cout << "Compraste una casa"<<endl;
                    dynamic_cast<propiedades*>(compradas[respuesta])->set_alquiler();
                } else {
                    cout << "No tienes dinero"<<endl;
                }
            }
        }
    }
    else{
        cout<<"No puede comprar una casa aqui"<<endl;
    }

}

void Jugador::vender_casas() {
    bool posible=true;
    cout<<"En que propiedad desea vender las casas"<<endl;
    mostrar_propiedades();
    int respuesta = 0;
    cin >> respuesta;
    respuesta -= 1;
    if(dynamic_cast<propiedades*>(compradas[respuesta]) == nullptr){
        cout<<"Ingrese una opcion valida"<<endl;
    }
    else{
        if(dynamic_cast<propiedades*>(compradas[respuesta])->casas==0){
            cout<<"No tiene casas esta propiedad"<<endl;
        }
        else{
            for(auto it:compradas){
                if(dynamic_cast<propiedades*>(compradas[respuesta])->casas < dynamic_cast<propiedades*>(it)->casas){
                    posible = false;
                }
            }
            if(posible){
                Dinero+= dynamic_cast<propiedades*>(compradas[respuesta])->precio_casa/2;
                dynamic_cast<propiedades*>(compradas[respuesta])->casas--;
                dynamic_cast<propiedades*>(compradas[respuesta])->set_alquiler();
                cout<<"Ahora la propiedad "<<dynamic_cast<propiedades*>(compradas[respuesta])->nombre<<" tiene "<<dynamic_cast<propiedades*>(compradas[respuesta])->casas<<" casas"<<endl;
            }
        }
    }
}

void Jugador::cambiar_alquileres() {
    for(auto it:compradas){
        it->set_alquiler();
    }
}


void Jugador::hipotecar() {
    cout << "Que propiedad desea hipotecar?" << endl;
    mostrar_propiedades();
    bool posible = true;
    int respuesta;
    cin >> respuesta;
    respuesta -= 1;
    if (compradas.size()!=0) {
        if (dynamic_cast<propiedades *>(compradas[respuesta])->casas != 0) {
            cout << "Debe vender las casas primero" << endl;
        } else {
            dynamic_cast<comprables *>(compradas[respuesta])->hipotecado = true;
            dynamic_cast<comprables *>(compradas[respuesta])->set_alquiler();
            Dinero += dynamic_cast<comprables *>(compradas[respuesta])->precio / 2;

        }
    }
}

void Jugador::deshipotecar() {
    cout<<"Que propiedad desea deshipotecar?"<<endl;
    mostrar_propiedades();
    int respuesta;
    cin >> respuesta;
    respuesta -= 1;
    auto aux = dynamic_cast<comprables*>(compradas[respuesta]);
    if(Dinero>aux->precio/2){
        aux->hipotecado=false;
        Dinero-=aux->precio/2;
        cout<<"Se ha deshipotecado la propiedad "<<aux->nombre<<endl;
    }
    else{
        cout<<"No tiene el dinero suficiente"<<endl;
    }

}

void Jugador::opciones(vector<Jugador*> Orden)
{
    int opcion;
    do {
        cout << "Ahora, ¿qué acción quieres realizar? Escribe el número de la opción que elija" << endl;
        cout << "1. Terminar mi turno" << endl;
        cout << "2. Negociar con otro jugador" << endl;
        cout << "3. Ver mis propiedades" << endl;
        cout << "4. Hipotecar mis propiedades" << endl;
        cout << "5. Deshipotecar mis propiedades"<< endl;
        cout << "6. Comprar casas" << endl;
        cout << "7. Vender casas" << endl;
        cout << "8. Bancarrota"<< endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
                break;
            case 2:
                negociar(Orden);
                break;
            case 3:
                mostrar_propiedades();
                break;
            case 4:
                hipotecar();
                break;
            case 5:
                deshipotecar();
                break;
            case 6:
                comprar_casas();
                break;
            case 7:
                vender_casas();
            case 8:
                break;
        }
    }
    while(opcion!=1);

}


void Jugador::en_carcel(dado* A, dado* B) {
    int choice;
    do {
        cout << "Estas en la carcel, que quieres hacer : " << endl;
        cout << "1. Terminar mi turno" << endl;
        cout << "2. Lanzar los dados buscando pares" << endl;
        cout << "3. Usar tarjeta de Arca Comunal o Fortuna" << endl;
        cout << "4. Pagar $50 al banco" << endl;
        cin >> choice;
    }while(choice < 1 | choice > 4);
    switch (choice) {
        case 1:
            break;

        case 2:
        {int primero = A->lanzar();
            int segundo = B->lanzar();
            cout << "Salió " << primero << " y " << segundo << ", y estos números son ";
            if( primero == segundo ){
                cout << "iguales, eres libre!" << endl;
                free = true;
            }else{
                cout << "distintos, sigues atrapado." << endl;
            }
            break;}

        case 3:
            if(!cartas_carcel.empty())
            {
                cartas_carcel.pop_back();
                free = true;
                cout<<"Tu carta fue usada con éxito, ahora eres libre"<<endl;
                break;
            }
            else
            {
                cout<<"No posees una carta para salir de la cárcel"<<endl;
                break;
            }
        case 4:
            Dinero-=50;
            cout << "Pagaste $50 al banco, ahora tienes " << Dinero;
            free = true;
            break;



    }
    if (turnos_seguidos < 3){
        turnos_seguidos+=1;
    }else{
        free = true;
    }
}

void Jugador::negociar(vector<Jugador*> Orden) {
    vector<comprables *> oferta_prop = {};
    vector<comprables *> pido_prop = {};
    int ofertor;

    for (int i = 0; i < Orden.size(); i++) {
        if (Orden[i]->nombre != nombre) {
            cout << i << " " << Orden[i]->nombre << endl;
        } else
            ofertor = i;
    }
    int destino;
    cin >> destino;
    Jugador *recibe = Orden[destino];
    int pedir_dinero;
    int dar_dinero;
    int respuesta;
    if (!compradas.empty()) {
        cout << "Que propiedades desea ofrecer?" << endl;

        while (respuesta != compradas.size()) {
            for (int j = 0; j < compradas.size(); j++) {
                cout << j << " " << compradas[j]->nombre << endl;

            }
            cout << compradas.size() << " Terminar" << endl;
            cin >> respuesta;
            if (respuesta < compradas.size()) {

                if (std::find(oferta_prop.begin(), oferta_prop.end(), compradas[respuesta]) == oferta_prop.end()) {
                    oferta_prop.push_back(compradas[respuesta]);
                } else {
                    cout << "Ya ofrecio esta propiedad" << endl;
                }



            } else if (respuesta != compradas.size())
                cout << "Numero invalido" << endl;
        }
    }
    cout << "Cuanto dinero desea ofrecer?" << endl;
    cin >> dar_dinero;

    cout << "Que propiedades quiere pedir" << endl;
    if (!recibe->compradas.empty()) {
        while (respuesta != recibe->compradas.size()) {
            for (int j = 0; j < recibe->compradas.size(); j++) {
                cout << j << " " << recibe->compradas[j]->nombre << endl;

            }
            cout << recibe->compradas.size() << " Terminar oferta_prop" << endl;
            cin >> respuesta;
            if (respuesta < recibe->compradas.size()) {
                pido_prop.push_back(recibe->compradas[respuesta]);
            } else if (respuesta != recibe->compradas.size())
                cout << "Numero invalido" << endl;
        }
    }
    cout << "Cuanto dinero desea pedir?" << endl;
    cin >> pedir_dinero;


    cout << recibe->nombre << " desea aceptar la oferta de " << nombre << " de " << endl;

    cout << "OFERTA: ";
    for (auto item:oferta_prop) {
        cout << item->nombre << " ";
    }
    cout << dar_dinero << endl;

    cout << "PIDE: ";
    for (auto item:pido_prop) {
        cout << item->nombre << " ";
    }
    cout << pedir_dinero << endl;

    cout << "Si=1, NO=0" << endl;

    cin >> respuesta;

    if (respuesta == 1) {

        if(dar_dinero<Dinero & pedir_dinero<recibe->Dinero) {
            for (auto item:oferta_prop) {
                compradas.erase(
                        std::remove(compradas.begin(), compradas.end(), item),
                        compradas.end());
                recibe->compradas.push_back(item);
            }

            recibe->Dinero += dar_dinero;
            Dinero -= dar_dinero;

            for (auto item:pido_prop) {
                recibe->compradas.erase(std::remove(recibe->compradas.begin(), recibe->compradas.end(), item),
                                        recibe->compradas.end());
                compradas.push_back(item);
            }
            recibe->Dinero -= pedir_dinero;
            Dinero += pedir_dinero;
            recibe->cambiar_alquileres();
            cambiar_alquileres();
        } else
            cout<<"No se puede"<<endl;


    }
}

void Jugador::set_ficha(Sprite f)
{
    ficha = f;

}

