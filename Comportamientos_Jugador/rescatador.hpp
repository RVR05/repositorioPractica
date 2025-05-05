#ifndef COMPORTAMIENTORESCATADOR_H
#define COMPORTAMIENTORESCATADOR_H

#include <chrono>
#include <time.h>
#include <thread>
#include <cstdlib>

#include "comportamientos/comportamiento.hpp"

class ComportamientoRescatador : public Comportamiento
{

public:
  ComportamientoRescatador(unsigned int size = 0) : Comportamiento(size)
  {
    // Inicializar Variables de Estado Niveles 0,1,4
    last_action = IDLE;
    tiene_zapatillas = false;
    giro45Izq = 0;
    mirada_izquierda = false;
    mirada_derecha = false;
    num_walks = 0;
    aleatorio = rand() % 5; //Busco generar un numero aleatorio entre 3 y 5
    if(aleatorio == 0) aleatorio+=3;
    else if(aleatorio == 1) aleatorio += 2;
    else if(aleatorio == 2) aleatorio += 1;

    mirada_izquierda_atras = false;
    mirada_derecha_atras = false;
    marcha_atras = false;
    recorrido.resize(100, vector<bool>(100, false));
    
  }
  ComportamientoRescatador(std::vector<std::vector<unsigned char>> mapaR, std::vector<std::vector<unsigned char>> mapaC) : Comportamiento(mapaR,mapaC)
  {
    // Inicializar Variables de Estado Niveles 2,3
  }
  ComportamientoRescatador(const ComportamientoRescatador &comport) : Comportamiento(comport) {}
  ~ComportamientoRescatador() {}

  Action think(Sensores sensores);

  int interact(Action accion, int valor);

  Action ComportamientoRescatadorNivel_0(Sensores sensores);
  Action ComportamientoRescatadorNivel_1(Sensores sensores);
  Action ComportamientoRescatadorNivel_2(Sensores sensores);
  Action ComportamientoRescatadorNivel_3(Sensores sensores);
  Action ComportamientoRescatadorNivel_4(Sensores sensores);

private:
  // Variables de Estado
  Action last_action;
  bool mirada_izquierda;
  bool mirada_derecha;
  int aleatorio;
  int num_walks;
  bool mirada_izquierda_atras;
  bool mirada_derecha_atras;
  bool marcha_atras;
  vector<vector<bool>> recorrido;
  bool tiene_zapatillas;
  int giro45Izq;
};

#endif
