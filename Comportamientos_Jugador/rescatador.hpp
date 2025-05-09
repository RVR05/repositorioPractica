#ifndef COMPORTAMIENTORESCATADOR_H
#define COMPORTAMIENTORESCATADOR_H

#include <chrono>
#include <time.h>
#include <thread>
#include <cstdlib>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <iostream>

#include "comportamientos/comportamiento.hpp"

struct EstadoR {
  int f;
  int c;
  int brujula;
  bool zapatillas;

  bool operator==(const EstadoR &st) const{
    return f == st.f && c == st.c && brujula == st.brujula && zapatillas == st.zapatillas;
  }
  bool operator<(const EstadoR& other) const {
    return std::tie(f, c, brujula, zapatillas) < std::tie(other.f, other.c, other.brujula, other.zapatillas);
  }
};

struct NodoR{
  EstadoR estado;
  list<Action> secuencia;
  int coste;

  bool operator==(const NodoR &node) const{
    return estado == node.estado && coste == node.coste;
  }

  bool operator!=(const NodoR &node) const{
    return !(estado == node.estado && coste == node.coste);
  }

  bool operator>(const NodoR &node) const{
    return (coste > node.coste);
  }

  bool operator<(const NodoR &node) const{
    if(coste != node.coste) return (coste < node.coste);
    if(estado.f != node.estado.f) return (estado.f < node.estado.f);
    if(estado.c != node.estado.c) return (estado.c < node.estado.c);
    if(estado.brujula != node.estado.brujula) return (estado.brujula < node.estado.brujula);
    if(estado.zapatillas != node.estado.zapatillas) return (estado.zapatillas < node.estado.zapatillas);
    return false;
  }
};

struct CompararNodoR {
  bool operator()(const NodoR& a, const NodoR& b) {
      // Priorizar por menor coste
      if (a.coste != b.coste) {
          return a.coste > b.coste;  // Orden ascendente (menor coste primero)
      }
      // Si coste igual, desempatar por coordenadas
      else {
          if (a.estado.f != b.estado.f) {
              return a.estado.f > b.estado.f;
          } else {
              return a.estado.c > b.estado.c;
          }
      }
  }
};

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
    hayPlan = false;
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
  Action ComportamientoRescatadorNivel_E(Sensores sensores);


  list<Action> DijkstraR(const EstadoR &inicio, const EstadoR &final,
    const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura);
  Action ComportamientoRNivel_E(Sensores sensores);
  void PintaPlan(const list<Action> &plan, bool zap);
  void VisualizaPlanR(const EstadoR &st, const list<Action> &plan);

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

  //variables nivel 2
  list<Action> plan;
  bool hayPlan;

};

#endif
