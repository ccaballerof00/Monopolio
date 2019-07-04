//
// Created by alonso on 31/05/19.
//

#ifndef POOII_DADO_H
#define POOII_DADO_H

#include "SFML/Graphics.hpp"
#include <random>

using namespace sf;

class dado {
public:
    Texture txt_dado;
    Sprite spr_dado;
    dado() = default;
    int lanzar();
};


#endif //POOII_DADO_H
