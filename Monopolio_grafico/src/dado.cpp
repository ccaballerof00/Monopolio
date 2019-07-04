//
// Created by alonso on 31/05/19.
//

#include <iostream>
#include "dado.h"
#include <random>

/*dado::dado()
{
    txt_dado.loadFromFile("1.png");
    spr_dado.setTexture(txt_dado);
    spr_dado.setPosition(800,350);
}*/

int dado::lanzar() {
    int lanzamiento = 1+ rand()%6;
    std::cout << "El dado saco " << lanzamiento << std::endl;
    /*switch(lanzamiento)
    {
    case 1:
        txt_dado.loadFromFile("1.png");
        break;
    case 2:
        txt_dado.loadFromFile("2.png");
        break;
    case 3:
        txt_dado.loadFromFile("3.png");
        break;
    case 4:
        txt_dado.loadFromFile("4.png");
        break;
    case 5:
        txt_dado.loadFromFile("5.png");
        break;
    case 6:
        txt_dado.loadFromFile("6.png");
        break;
    }*/
    spr_dado.setTexture(txt_dado);
    spr_dado.setPosition(800,350);
//    return 1;
    return lanzamiento;
}

