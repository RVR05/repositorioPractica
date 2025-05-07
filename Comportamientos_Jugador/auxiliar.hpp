#ifndef COMPORTAMIENTOAUXILIAR_H
#define COMPORTAMIENTOAUXILIAR_H

#include <chrono>
#include <time.h>
#include <thread>
#include <cstdlib>

#include "comportamientos/comportamiento.hpp"

class ComportamientoAuxiliar : public Comportamiento
{

public:
  ComportamientoAuxiliar(unsigned int size = 0) : Comportamiento(size)
  {
    last_action = IDLE;
    tiene_zapatillas = false;
    giro45Izq = 0;
    mirada_derecha = false;
    mirada_izquierda = false;
    num_giros = 0;
    num_giros2 = 0;
    aleatorio = rand() % 5; //Busco generar un numero aleatorio entre 3 y 5
    if(aleatorio == 0) aleatorio+=3;
    else if(aleatorio == 1) aleatorio += 2;
    else if(aleatorio == 2) aleatorio += 1;
    mirada_izquierda_atras = false;
    mirada_derecha_atras = false;
    marcha_atras = false;
    recorrido.resize(100, vector<bool>(100, false));

  }
  ComportamientoAuxiliar(std::vector<std::vector<unsigned char>> mapaR, std::vector<std::vector<unsigned char>> mapaC) : Comportamiento(mapaR,mapaC)
  {
    // Inicializar Variables de Estado Niveles 2,3
  }
  ComportamientoAuxiliar(const ComportamientoAuxiliar &comport) : Comportamiento(comport) {}
  ~ComportamientoAuxiliar() {}

  Action think(Sensores sensores);

  int interact(Action accion, int valor);

  Action ComportamientoAuxiliarNivel_0(Sensores sensores);
  Action ComportamientoAuxiliarNivel_1(Sensores sensores);
  Action ComportamientoAuxiliarNivel_2(Sensores sensores);
  Action ComportamientoAuxiliarNivel_3(Sensores sensores);
  Action ComportamientoAuxiliarNivel_4(Sensores sensores);

private:
    // Variables de Estado
    Action last_action;
    bool mirada_izquierda;
    bool mirada_derecha;
    int aleatorio;
    int num_giros;
    int num_giros2;
    bool mirada_izquierda_atras;
    bool mirada_derecha_atras;
    bool marcha_atras;
    vector<vector<bool>> recorrido;
    bool tiene_zapatillas;
    int giro45Izq;
};

#endif
