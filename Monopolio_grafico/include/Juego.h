#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "dado.h"
#include "tablero.h"
#include "jugador.h"

using namespace std;
using namespace sf;

class Juego
{
private:
    int contador_juego = 0;
    int num_jugadores;
    int turno;
    dado dado1, dado2;
    vector<Jugador*> Orden;
	RenderWindow* ventana;
	int fps;
	Texture Tablero;
	Texture pieza1;
	Texture pieza2;
	Texture pieza4;
	Texture pieza5;
	Sprite _tablero;
	Sprite _pieza1;
	Sprite _pieza2;
	Sprite _pieza4;
	Sprite _pieza5;
    Font fuente;
	Event evento;

public:
	Juego(int ancho, int largo, string titulo);
	void gameLoop();
	void inicio();
	void procesar_eventos();
	void dibujar_piezas();
	void dibujar_dados();
	void dibujar_texto(string text, int pos);
	void definir_jugadores();
	void lanzar_dado(dado d1,dado d2);
};
#endif // JUEGO_H
