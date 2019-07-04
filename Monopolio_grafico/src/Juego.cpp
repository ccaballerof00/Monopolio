#include "Juego.h"

Juego::Juego(int ancho, int alto, string titulo)
{
num_jugadores = 0;
contador_juego = 0;
ventana = new RenderWindow(VideoMode(ancho,alto),titulo);
ventana->setFramerateLimit(fps);

Tablero.loadFromFile("tablero.jpg");

pieza1.loadFromFile("Corona.png");

pieza2.loadFromFile("Gato.png");

pieza4.loadFromFile("Rallador.png");

pieza5.loadFromFile("Soldado.png");

fuente.loadFromFile("HappySchool.ttf");


_tablero.setTexture(Tablero);
_tablero.setScale(0.9,0.9);
_tablero.setOrigin(_tablero.getTexture()->getSize().x/2.0,_tablero.getTexture()->getSize().y/2.0);
_tablero.setPosition(ancho/2 -300,alto/2);

_pieza1.setTexture(pieza1);
_pieza1.setScale(0.12,0.12);
_pieza1.setPosition(710,665);

_pieza2.setTexture(pieza2);
_pieza2.setScale(0.33,0.33);
_pieza2.setPosition(640,665);

_pieza4.setTexture(pieza4);
_pieza4.setScale(0.11,0.11);
_pieza4.setPosition(700,700);

_pieza5.setTexture(pieza5);
_pieza5.setScale(0.16,0.16);
_pieza5.setPosition(655,700);

gameLoop();
}

void Juego::gameLoop()
{
    srand(time(NULL));
    tablero mesa;
    for (int i = 0; i < num_jugadores; i++) {
        Orden[i]->posicion = mesa.head_;
    }
    int primero, segundo, avance, en_turno = 0;

while(ventana->isOpen())
{
if (en_turno == num_jugadores)
    {
        en_turno = 0;
    }
procesar_eventos();
switch(contador_juego){
case 0:{
    inicio();
    break;}
case 1:{
    definir_jugadores();
    break;}
case 2:{
    //ventana->draw(dado1.spr_dado);
    //dado2.spr_dado.setPosition(800,500);
    //ventana->draw(dado2.spr_dado);
    lanzar_dado(dado1,dado2);
    //ventana->draw(dado1.spr_dado);
    //dado2.spr_dado.setPosition(800,500);
    //ventana->draw(dado2.spr_dado);
    break;
}
}
ventana->display();

}
}

void Juego::inicio()
{
ventana->draw(_tablero);
ventana->display();
bool selected = false;
while(selected == false)
{
 if(Keyboard::isKeyPressed(Keyboard::I))
{
    contador_juego = 1;
    selected = true;
}
}

}

void Juego::procesar_eventos()
{
while(ventana->pollEvent(evento))
{
    switch(evento.type)
    {
    case Event::Closed:
        ventana->close();
        break;
    }
}
}


void Juego::definir_jugadores()
{
    dibujar_texto("Presione el numero de personas que ",0);
    dibujar_texto("jugara (Minimo 2, maximo 4",1);
    //ventana->draw(_tablero);
    if(Keyboard::isKeyPressed(Keyboard::Num2))
        {
        num_jugadores = 2;
        //ventana->draw(_pieza1);
        //ventana->draw(_pieza2);
        Jugador* player1 = new Jugador(0,"Jugador 1");
        player1->set_ficha(_pieza1);
        Jugador* player2 = new Jugador(1,"Jugador 2");
        player2->set_ficha(_pieza2);
        Orden.push_back(player1);
        Orden.push_back(player2);
        contador_juego = 2;

        }
        else{
        if(Keyboard::isKeyPressed(Keyboard::Num3))
        {
        num_jugadores = 3;
        //ventana->draw(_pieza1);
        //ventana->draw(_pieza2);
        //ventana->draw(_pieza4);
        Jugador* player1 = new Jugador(0,"Jugador 1");
        player1->set_ficha(_pieza1);
        Jugador* player2 = new Jugador(1,"Jugador 2");
        player2->set_ficha(_pieza2);
        Jugador* player3 = new Jugador(2,"Jugador 3");
        player3->set_ficha(_pieza4);
        Orden.push_back(player1);
        Orden.push_back(player2);
        Orden.push_back(player3);
        contador_juego = 2;

        }
        else{
        if(Keyboard::isKeyPressed(Keyboard::Num4))
        {
        num_jugadores = 4;
        //ventana->draw(_pieza1);
        //ventana->draw(_pieza2);
        //ventana->draw(_pieza4);
        //ventana->draw(_pieza5);
        Jugador* player1 = new Jugador(0,"Jugador 1");
        player1->set_ficha(_pieza1);
        Jugador* player2 = new Jugador(1,"Jugador 2");
        player2->set_ficha(_pieza2);
        Jugador* player3 = new Jugador(2,"Jugador 3");
        player3->set_ficha(_pieza4);
        Jugador* player4 = new Jugador(3,"Jugador 4");
        player4->set_ficha(_pieza5);
        Orden.push_back(player1);
        Orden.push_back(player2);
        Orden.push_back(player3);
        Orden.push_back(player4);
        contador_juego = 2;

        }
        }
        }
        //ventana->draw(_tablero);
        dibujar_piezas();
}

void Juego::lanzar_dado(dado d1, dado d2)
{
    //ventana->clear();
    //ventana->draw(_tablero);
    //dibujar_piezas();
    if(Keyboard::isKeyPressed(Keyboard::Num5))
    {
        dado1.lanzar();
        //ventana->draw(dado1.spr_dado);
        dado2.lanzar();
        //dado2.spr_dado.setPosition(800,500);
        //ventana->draw(dado2.spr_dado);
        contador_juego = 4;

    }
    dibujar_dados();
}

void Juego::dibujar_piezas()

{
    ventana->draw(Orden[1]->ficha);
        /*for(int i = 0; i < num_jugadores; i++)
        {
            ventana->draw(Orden[i]->ficha);
        }*/
}

void Juego::dibujar_dados()
{
    ventana->draw(dado1.spr_dado);
    dado2.spr_dado.setPosition(800,500);
    ventana->draw(dado2.spr_dado);
}

void Juego::dibujar_texto(string text, int pos)
{
        Text mes;
        mes.setFont(fuente);
        mes.setString(text);
        mes.setColor(Color::White);
        mes.setPosition(800,100+(50*pos));
        ventana->draw(mes);
}

