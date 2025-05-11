#ifndef COMPORTAMIENTOAUXILIAR_H
#define COMPORTAMIENTOAUXILIAR_H

#include <chrono>
#include <time.h>
#include <thread>
#include <cstdlib>
#include <list>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>

#include "comportamientos/comportamiento.hpp"


struct EstadoA {
  int f;
  int c;
  int brujula;
  bool zapatillas;
  bool operator==(const EstadoA &st) const{
    return f == st.f && c == st.c && brujula == st.brujula and zapatillas ==
    st.zapatillas;
  }
  bool operator<(const EstadoA& other) const {
    return std::tie(f, c, brujula, zapatillas) < std::tie(other.f, other.c, other.brujula, other.zapatillas);
  }
};


struct NodoA {
  EstadoA estado;
  list<Action> secuencia;
  int gX; // Coste acumulado real (incluye giros y terreno)
  int hX; // Heurística (Chebyshev * 2)
  int fX;

  bool operator>(const NodoA &node) const {
      return fX > node.fX; // Ordenar por menor fX
  }

  bool operator==(const NodoA &node) const{
    return estado == node.estado && gX == node.gX && hX == node.hX && fX == node.fX;
  }
};

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
    hayPlan = false;

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

  list<Action> AnchuraAuxiliar(const EstadoA &inicio, const EstadoA &final,
    const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura);
  Action ComportamientoAuxiliarNivel_E(Sensores sensores);
  void VisualizaPlanA(const EstadoA &st, const list<Action> &plan);
  list<Action> AEstrellaAuxiliar(const EstadoA &inicio, const EstadoA &final, const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura);

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
    // Variables propias nivel 2

    list<Action> plan;
    bool hayPlan;

};

#endif
