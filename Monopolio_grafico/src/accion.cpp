//
// Created by cristian on 6/10/19.
//

#include "accion.h"
#include "jugador.h"
#include "tablero.h"
#include "comprables.h"
#include <iostream>


void Impuesto::ejecutar(Jugador * huesped, tablero* Monopoly) {
    cout << "Tiene que pagar un impuesto"<<endl;
    if (huesped->Dinero * porciento > imp) {
        cout << "Se pago " << imp<<endl;
        huesped->Dinero -= imp;
        Monopoly->pozo += imp;
    } else {
        cout << "Se pago " << huesped->Dinero * porciento<<endl;
        Monopoly->pozo += huesped->Dinero*porciento;
        huesped->Dinero -= huesped->Dinero*porciento;
    }
}

void ArcaComunal::ejecutar(Jugador *huesped, tablero *Monopoly)
{
    int i= Monopoly->Baraja_Arca.back();
    switch (i) {
        case 0:
            cout<<"**************************************************************"<<endl;
            cout<<"*                     ARCA COMUNAL                           *"<<endl;
            cout<<"**************************************************************"<<endl;
            cout<<"* Avance hasta la Av. Virginia, si pasa por Go cobre sus 200 *"<<endl;
            cout<<"*                                                            *"<<endl;
            cout<<"*                                                            *"<<endl;
            cout<<"**************************************************************"<<endl;
            while(huesped->posicion->nombre!="Av. Virginia"){
            huesped->posicion=huesped->posicion->next;}
            cout<<huesped->nombre<<" se encuentra ahora en la casilla "<<huesped->posicion->nombre<<endl;
            huesped->posicion->ejecutar(huesped);
            break;

        case 1:
            cout<<"*******************************************"<<endl;
            cout<<"*              ARCA COMUNAL               *"<<endl;
            cout<<"*******************************************"<<endl;
            cout<<"* Avance directamente hasta la casilla Go *"<<endl;
            cout<<"*                                         *"<<endl;
            cout<<"*                                         *"<<endl;
            cout<<"*******************************************"<<endl;
            while(huesped->posicion->nombre!="Go")
            {
                huesped->posicion = huesped->posicion->next;}
                cout<<huesped->nombre<<" se encuentra ahora en la casilla "<<huesped->posicion->nombre<<endl;

            break;

        case 2:
            cout<<"********************************"<<endl;
            cout<<"*        ARCA COMUNAL          *"<<endl;
            cout<<"********************************"<<endl;
            cout<<"* Es tu cumpleaños recibe $100 *"<<endl;
            cout<<"*                              *"<<endl;
            cout<<"*                              *"<<endl;
            cout<<"********************************"<<endl;
            huesped->Dinero +=100;
            cout<<huesped->nombre<<" recibio $100"<<endl;
            break;

        case 3:
            cout<<"*************************************"<<endl;
            cout<<"*           ARCA COMUNAL            *"<<endl;
            cout<<"*************************************"<<endl;
            cout<<"* Su hospital exige un pago de $100 *"<<endl;
            cout<<"*                                   *"<<endl;
            cout<<"*                                   *"<<endl;
            cout<<"*************************************"<<endl;
            huesped->Dinero -=100;
            cout<<huesped->nombre<<" pago $100"<<endl;
            break;

        case 4:
            cout<<"************************************************************************"<<endl;
            cout<<"*                             ARCA COMUNAL                             *"<<endl;
            cout<<"************************************************************************"<<endl;
            cout<<"* Usted ha sido elegido presidente del consejo, coloque $50 en el pozo *"<<endl;
            cout<<"*                                                                      *"<<endl;
            cout<<"*                                                                      *"<<endl;
            cout<<"************************************************************************"<<endl;
            huesped->Dinero -=50;
            Monopoly->pozo +=50;
            cout<<huesped->nombre<<" colocó $50 en el pozo"<<endl;
            break;

        case 5:
            cout<<"*********************"<<endl;
            cout<<"*    ARCA COMUNAL   *"<<endl;
            cout<<"*********************"<<endl;
            cout<<"* Usted hereda $100 *"<<endl;
            cout<<"*                   *"<<endl;
            cout<<"*                   *"<<endl;
            cout<<"*********************"<<endl;
            huesped->Dinero +=100;
            cout<<huesped->nombre<<" consiguió $100"<<endl;
            break;

        case 6:
            cout<<"*****************************"<<endl;
            cout<<"*        ARCA COMUNAL       *"<<endl;
            cout<<"*****************************"<<endl;
            cout<<"* Salga de la cárcel gratis *"<<endl;
            cout<<"*                           *"<<endl;
            cout<<"*                           *"<<endl;
            cout<<"*****************************"<<endl;
            huesped->cartas_carcel.push_back(1);
            cout<<huesped->nombre<<" ahora posee una tarjeta para salir de la cárcel"<<endl;
            break;

        case 7:
            cout<<"***********************************************"<<endl;
            cout<<"*                 ARCA COMUNAL                *"<<endl;
            cout<<"***********************************************"<<endl;
            cout<<"* Le toca recibir $25 por servicios prestados *"<<endl;
            cout<<"*                                             *"<<endl;
            cout<<"*                                             *"<<endl;
            cout<<"***********************************************"<<endl;
            huesped->Dinero += 25;
            cout<<huesped->nombre<<" consiguió $25"<<endl;
            break;

        case 8:
            cout<<"*******************************************************************************"<<endl;
            cout<<"*                                ARCA COMUNAL                                 *"<<endl;
            cout<<"*******************************************************************************"<<endl;
            cout<<"* ¡Al calabozo! Vaya directamente a la cárcel sin pasar por Go ni cobrar $200 *"<<endl;
            cout<<"*                                                                             *"<<endl;
            cout<<"*                                                                             *"<<endl;
            cout<<"*******************************************************************************"<<endl;
            huesped->posicion = Monopoly->jail;
            huesped->free = false;
            cout<<huesped->nombre<<" ahora se encuentra en la casilla "<<huesped->posicion->nombre<<endl;
            break;

        case 9:
            cout<<"************************************************************************************************"<<endl;
            cout<<"*                                           ARCA COMUNAL                                       *"<<endl;
            cout<<"************************************************************************************************"<<endl;
            cout<<"* Inicio de construcción de su nuevo parque de diversiones, pague $70 por gastos en materiales *"<<endl;
            cout<<"*                                                                                              *"<<endl;
            cout<<"*                                                                                              *"<<endl;
            cout<<"************************************************************************************************"<<endl;
            huesped->Dinero -= 70;
            cout<<huesped->nombre<<" pagó $70"<<endl;
            break;

        case 10:
            cout<<"**************************************************************************************************************************"<<endl;
            cout<<"*                                                       ARCA COMUNAL                                                     *"<<endl;
            cout<<"**************************************************************************************************************************"<<endl;
            cout<<"* Su primo está en la cárcel, vaya directamente a la casilla de visita a cárcel para verlo (Si pasa por Go no cobre $200 *"<<endl;
            cout<<"*                                                                                                                        *"<<endl;
            cout<<"*                                                                                                                        *"<<endl;
            cout<<"**************************************************************************************************************************"<<endl;
            huesped->posicion = Monopoly->jail;
            cout<<huesped->nombre<<" ahora se encuentra de visita en la casilla "<<huesped->posicion->nombre<<endl;
            break;

        case 11:
            cout<<"*********************************************************************************************"<<endl;
            cout<<"*                                       ARCA COMUNAL                                        *"<<endl;
            cout<<"*********************************************************************************************"<<endl;
            cout<<"* Se está dando un altercado en la Av. Pacifico, diríjase a esta casilla para solucionarlos *"<<endl;
            cout<<"*                                                                                           *"<<endl;
            cout<<"*                                                                                           *"<<endl;
            cout<<"*********************************************************************************************"<<endl;
            while(huesped->posicion->nombre != "Av. Pacifico")
            {
                huesped->posicion = huesped->posicion->next;
            }
            cout<<huesped->nombre<<" se encuentra ahora en "<<huesped->posicion->nombre<<endl;
            huesped->posicion->ejecutar(huesped);
            break;

        case 12:
            cout<<"***************************************"<<endl;
            cout<<"*            ARCA COMUNAL             *"<<endl;
            cout<<"***************************************"<<endl;
            cout<<"* Te pagan seguro de vida, cobra $100 *"<<endl;
            cout<<"*                                     *"<<endl;
            cout<<"*                                     *"<<endl;
            cout<<"***************************************"<<endl;
            huesped->Dinero += 100;
            cout<<huesped->nombre<<" consiguió $100"<<endl;
            break;

        case 13:
            cout<<"*****************************************"<<endl;
            cout<<"*             ARCA COMUNAL              *"<<endl;
            cout<<"*****************************************"<<endl;
            cout<<"* Error bancario a tu favor, cobra $200 *"<<endl;
            cout<<"*                                       *"<<endl;
            cout<<"*                                       *"<<endl;
            cout<<"*****************************************"<<endl;
            huesped->Dinero += 200;
            cout<<huesped->nombre<<" consiguió $200"<<endl;
            break;

        case 14:
            cout<<"***************************"<<endl;
            cout<<"*       ARCA COMUNAL      *"<<endl;
            cout<<"***************************"<<endl;
            cout<<"* Cuotas médicas paga $50 *"<<endl;
            cout<<"*                         *"<<endl;
            cout<<"*                         *"<<endl;
            cout<<"***************************"<<endl;
            huesped->Dinero -=50;
            cout<<huesped->nombre<<" pagó $50"<<endl;
            break;

        case 15:
            cout<<"*****************************************"<<endl;
            cout<<"*              ARCA COMUNAL             *"<<endl;
            cout<<"*****************************************"<<endl;
            cout<<"* Te pagan prima vacacional, cobra $100 *"<<endl;
            cout<<"*                                       *"<<endl;
            cout<<"*                                       *"<<endl;
            cout<<"*****************************************"<<endl;
            huesped->Dinero +=100;
            cout<<huesped->nombre<<" consiguió $100"<<endl;
            break;

        case 16:
            cout<<"***********************************"<<endl;
            cout<<"*          ARCA COMUNAL           *"<<endl;
            cout<<"***********************************"<<endl;
            cout<<"* Por venta de acciones ganas $50 *"<<endl;
            cout<<"*                                 *"<<endl;
            cout<<"*                                 *"<<endl;
            cout<<"***********************************"<<endl;
            huesped->Dinero +=50;
            cout<<huesped->nombre<<" consiguió $50"<<endl;
            break;

        case 17:
            cout<<"*******************************************************"<<endl;
            cout<<"*                       ARCA COMUNAL                  *"<<endl;
            cout<<"*******************************************************"<<endl;
            cout<<"* Es el cumpleaños de tu hijo, el regalo te costó $70 *"<<endl;
            cout<<"*                                                     *"<<endl;
            cout<<"*                                                     *"<<endl;
            cout<<"*******************************************************"<<endl;
            huesped->Dinero += 70;
            cout<<huesped->nombre<<" consiguió $70"<<endl;
            break;

        case 18:
            cout<<"******************************************************************"<<endl;
            cout<<"*                           ARCA COMUNAL                         *"<<endl;
            cout<<"******************************************************************"<<endl;
            cout<<"* Ganaste el segundo premio en un concurso de belleza, cobra $10 *"<<endl;
            cout<<"*                                                                *"<<endl;
            cout<<"*                                                                *"<<endl;
            cout<<"******************************************************************"<<endl;
            huesped->Dinero += 10;
            cout<<huesped->nombre<<" consiguió $10"<<endl;
            break;

        case 19:
            cout<<"****************"<<endl;
            cout<<"* ARCA COMUNAL *"<<endl;
            cout<<"****************"<<endl;
            cout<<"* Heredas $100 *"<<endl;
            cout<<"*              *"<<endl;
            cout<<"*              *"<<endl;
            cout<<"****************"<<endl;
            huesped->Dinero += 100;
            cout<<huesped->nombre<<" consiguió $100"<<endl;
            break; }

            Monopoly->Baraja_Arca.pop_back();
        if(i != 6)
            Monopoly->Baraja_Arca.push_front(i);
}

void Fortuna::ejecutar(Jugador *huesped, tablero *Monopoly)
{
    int i= Monopoly->Baraja_Fortuna.back();
    switch (i) {
        case 0:
            cout<<"****************************************************************"<<endl;
            cout<<"*                            FORTUNA                           *"<<endl;
            cout<<"****************************************************************"<<endl;
            cout<<"* Avance hasta la Plaza St James, si pasa por Go cobre sus 200 *"<<endl;
            cout<<"*                                                              *"<<endl;
            cout<<"*                                                              *"<<endl;
            cout<<"****************************************************************"<<endl;
            while(huesped->posicion->nombre!="Plaza St James"){
            huesped->posicion=huesped->posicion->next;}
            cout<<huesped->nombre<<" se encuentra ahora en la casilla "<<huesped->posicion->nombre<<endl;
            huesped->posicion->ejecutar(huesped);
            break;

        case 1:
            cout<<"******************************************************"<<endl;
            cout<<"*                    FORTUNA                         *"<<endl;
            cout<<"******************************************************"<<endl;
            cout<<"* Liquidas tu préstamo para construcción, cobra $150 *"<<endl;
            cout<<"*                                                    *"<<endl;
            cout<<"*                                                    *"<<endl;
            cout<<"******************************************************"<<endl;

                huesped->Dinero += 150;
                cout<<huesped->nombre<<" recibio $150"<<endl;
            break;

        case 2:
            cout<<"**********************************************************"<<endl;
            cout<<"*                         FORTUNA                        *"<<endl;
            cout<<"**********************************************************"<<endl;
            cout<<"* Avanza hasta Av. Illinois, si pasas por Go cobra $200  *"<<endl;
            cout<<"*                                                        *"<<endl;
            cout<<"*                                                        *"<<endl;
            cout<<"**********************************************************"<<endl;
            while(huesped->posicion->nombre != "Av. Illinois")
            {
                huesped->posicion = huesped->posicion->next;
            }
            cout<<huesped->nombre<<" se encuentra ahora en la casilla "<<huesped->posicion->nombre<<endl;
            huesped->posicion->ejecutar(huesped);
            break;

        case 3:
            cout<<"*****************************"<<endl;
            cout<<"*          FORTUNA          *"<<endl;
            cout<<"*****************************"<<endl;
            cout<<"* Sales de la cárcel gratis *"<<endl;
            cout<<"*                           *"<<endl;
            cout<<"*                           *"<<endl;
            cout<<"*****************************"<<endl;
            huesped->cartas_carcel.push_back(1);
            cout<<huesped->nombre<<" ahora posee una tarjeta para salir de la cárcel"<<endl;
            break;

        case 4:
            cout<<"*****************************************"<<endl;
            cout<<"                FORTUNA                 *"<<endl;
            cout<<"*****************************************"<<endl;
            cout<<"* El banco te paga un dividendo por $50 *"<<endl;
            cout<<"*                                       *"<<endl;
            cout<<"*                                       *"<<endl;
            cout<<"*****************************************"<<endl;
            huesped->Dinero +=50;
            cout<<huesped->nombre<<" recibió $50 "<<endl;
            break;

        case 5:
            cout<<"*******************************************"<<endl;
            cout<<"*                 FORTUNA                 *"<<endl;
            cout<<"*******************************************"<<endl;
            cout<<"* Avance directamente hasta la casilla Go *"<<endl;
            cout<<"*                                         *"<<endl;
            cout<<"*                                         *"<<endl;
            cout<<"*******************************************"<<endl;
            while(huesped->posicion->nombre!="Go")
            {
                huesped->posicion = huesped->posicion->next;
                cout<<huesped->nombre<<" se encuentra ahora en la casilla "<<huesped->posicion->nombre<<endl;
            }
            break;

        case 6:
            cout<<"**************************************************************"<<endl;
            cout<<"*                           FORTUNA                          *"<<endl;
            cout<<"**************************************************************"<<endl;
            cout<<"* Vas a la cárcel, ve directamente sin cobrar $200 por el Go *"<<endl;
            cout<<"*                                                            *"<<endl;
            cout<<"*                                                            *"<<endl;
            cout<<"**************************************************************"<<endl;
            huesped->posicion = Monopoly->jail;
            huesped->free = false;
            cout<<huesped->nombre<<" ahora se encuentra en la casilla "<<huesped->posicion->nombre<<endl;
            break;

        case 7:
            cout<<"*************************************"<<endl;
            cout<<"*             FORTUNA               *"<<endl;
            cout<<"*************************************"<<endl;
            cout<<"* Avanza al ferrocarril más cercano, si está a la venta puedes comprarlo, *"
                  "* si está vendido tendrás que pagar el doble de la renta de la tarjeta.   *"<<endl;
            cout<<"*                                   *"<<endl;
            cout<<"*                                   *"<<endl;
            cout<<"*************************************"<<endl;
            while(dynamic_cast<ferrocarril*>(huesped->posicion)== nullptr)
            {huesped->posicion = huesped->posicion->next;}
            cout<<huesped->nombre<<" ahora se encuentra en la casilla "<<huesped->posicion->nombre<<endl;
            break;

        case 8:
            cout<<"*******************************************************************************"<<endl;
            cout<<"*                                FORTUNA                                 *"<<endl;
            cout<<"*******************************************************************************"<<endl;
            cout<<"* Retrocede 3 espacios *"<<endl;
            cout<<"*                                                                             *"<<endl;
            cout<<"*                                                                             *"<<endl;
            cout<<"*******************************************************************************"<<endl;
            huesped->posicion = Monopoly->jail;
            huesped->free = false;
            cout<<huesped->nombre<<" ahora se encuentra en la casilla "<<huesped->posicion->nombre<<endl;
            break;

        case 9:
            cout<<"************************************************************************************************"<<endl;
            cout<<"*                                          FORTUNA                                       *"<<endl;
            cout<<"************************************************************************************************"<<endl;
            cout<<"* Paga multa por exceso de velocidad $15 *"<<endl;
            cout<<"*                                                                                              *"<<endl;
            cout<<"*                                                                                              *"<<endl;
            cout<<"************************************************************************************************"<<endl;
            huesped->Dinero -= 70;
            cout<<huesped->nombre<<" pagó $70"<<endl;
            break;

        case 10:
            cout<<"**************************************************************************************************************************"<<endl;
            cout<<"*                                                       FORTUNA                                                     *"<<endl;
            cout<<"**************************************************************************************************************************"<<endl;
            cout<<"* Avanza al servicio más cercano, si está a la venta puedes comprarlo, *"
                  "* si está vendido debes pagar el doble de la renta de la tarjeta       *"<<endl;
            cout<<"*                                                                                                                        *"<<endl;
            cout<<"*                                                                                                                        *"<<endl;
            cout<<"**************************************************************************************************************************"<<endl;
            huesped->posicion = Monopoly->jail;
            cout<<huesped->nombre<<" ahora se encuentra de visita en la casilla "<<huesped->posicion->nombre<<endl;
            break;

        case 11:
            cout<<"*********************************************************************************************"<<endl;
            cout<<"*                                      FORTUNA                                       *"<<endl;
            cout<<"*********************************************************************************************"<<endl;
            cout<<"* Te han elegido presidente de la mesa directiva, paga $100 al pozo *"<<endl;
            cout<<"*                                                                                           *"<<endl;
            cout<<"*                                                                                           *"<<endl;
            cout<<"*********************************************************************************************"<<endl;
            while(huesped->posicion->nombre != "Av. Pacifico")
            {
                huesped->posicion = huesped->posicion->next;
            }
            cout<<huesped->nombre<<" se encuentra ahora en "<<huesped->posicion->nombre<<endl;
            huesped->posicion->ejecutar(huesped);
            break;

        case 12:
            cout<<"***************************************"<<endl;
            cout<<"*            FORTUNA             *"<<endl;
            cout<<"***************************************"<<endl;
            cout<<"* Avanza hasta Paseo Tablado *"<<endl;
            cout<<"*                                     *"<<endl;
            cout<<"*                                     *"<<endl;
            cout<<"***************************************"<<endl;
            huesped->Dinero += 100;
            cout<<huesped->nombre<<" consiguió $100"<<endl;
            break;

        case 13:
            cout<<"*****************************************"<<endl;
            cout<<"*             FORTUNA              *"<<endl;
            cout<<"*****************************************"<<endl;
            cout<<"* Haz un viaje al Ferrocarril Reading, si pasas por Go cobra $200 *"<<endl;
            cout<<"*                                       *"<<endl;
            cout<<"*                                       *"<<endl;
            cout<<"*****************************************"<<endl;
            huesped->Dinero += 200;
            cout<<huesped->nombre<<" consiguió $200"<<endl;
            break;

        case 14:
            cout<<"***************************"<<endl;
            cout<<"*       FORTUNA      *"<<endl;
            cout<<"***************************"<<endl;
            cout<<"* EL DEL FERROCARRIL LARGO OTRA VEZ*"<<endl;
            cout<<"*                         *"<<endl;
            cout<<"*                         *"<<endl;
            cout<<"***************************"<<endl;
            huesped->Dinero -=50;
            cout<<huesped->nombre<<" pagó $50"<<endl;
            break;

        case 15:
            cout<<"*****************************************"<<endl;
            cout<<"*              FORTUNA            *"<<endl;
            cout<<"*****************************************"<<endl;
            cout<<"* Te pagan prima vacacional, cobra $100 *"<<endl;
            cout<<"*                                       *"<<endl;
            cout<<"*                                       *"<<endl;
            cout<<"*****************************************"<<endl;
            huesped->Dinero +=100;
            cout<<huesped->nombre<<" consiguió $100"<<endl;
            break;

        case 16:
            cout<<"***********************************"<<endl;
            cout<<"*         FORTUNA          *"<<endl;
            cout<<"***********************************"<<endl;
            cout<<"* Por venta de acciones ganas $50 *"<<endl;
            cout<<"*                                 *"<<endl;
            cout<<"*                                 *"<<endl;
            cout<<"***********************************"<<endl;
            huesped->Dinero +=50;
            cout<<huesped->nombre<<" consiguió $50"<<endl;
            break;

        case 17:
            cout<<"*******************************************************"<<endl;
            cout<<"*                      FORTUNA                  *"<<endl;
            cout<<"*******************************************************"<<endl;
            cout<<"* Es el cumpleaños de tu hijo, el regalo te costó $70 *"<<endl;
            cout<<"*                                                     *"<<endl;
            cout<<"*                                                     *"<<endl;
            cout<<"*******************************************************"<<endl;
            huesped->Dinero += 70;
            cout<<huesped->nombre<<" consiguió $70"<<endl;
            break;

        case 18:
            cout<<"******************************************************************"<<endl;
            cout<<"*                           FORTUNA                         *"<<endl;
            cout<<"******************************************************************"<<endl;
            cout<<"* Ganaste el segundo premio en un concurso de belleza, cobra $10 *"<<endl;
            cout<<"*                                                                *"<<endl;
            cout<<"*                                                                *"<<endl;
            cout<<"******************************************************************"<<endl;
            huesped->Dinero += 10;
            cout<<huesped->nombre<<" consiguió $10"<<endl;
            break;

        case 19:
            cout<<"****************"<<endl;
            cout<<"* FORTUNA *"<<endl;
            cout<<"****************"<<endl;
            cout<<"* Heredas $100 *"<<endl;
            cout<<"*              *"<<endl;
            cout<<"*              *"<<endl;
            cout<<"****************"<<endl;
            huesped->Dinero += 100;
            cout<<huesped->nombre<<" consiguió $100"<<endl;
            break; }

            Monopoly->Baraja_Arca.pop_back();
        if(i != 6)
            Monopoly->Baraja_Arca.push_front(i);
}


void GoToJail::ejecutar(Jugador * huesped, tablero* Monopoly) {
    huesped->free= true;
    huesped->posicion=Monopoly->jail;
    cout<<"El jugador "<<huesped->nombre<<" esta en "<<huesped->posicion->nombre<<endl;
}

void ParadaLibre::ejecutar(Jugador *huesped, tablero* Monopoly) {
    huesped->Dinero+=Monopoly->pozo;
    cout << "El jugador " << huesped->nombre << " ha ganado " << Monopoly->pozo << "." << endl;
    Monopoly->pozo=0;
}

