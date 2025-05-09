#include "../Comportamientos_Jugador/auxiliar.hpp"
#include <iostream>
#include "motorlib/util.h"

Action ComportamientoAuxiliar::think(Sensores sensores)
{
	Action accion = WALK;

	switch (sensores.nivel)
	{
	case 0:
		//accion = ComportamientoAuxiliarNivel_0 (sensores);
		break;
	case 1:
		//accion = ComportamientoAuxiliarNivel_1 (sensores);
		break;
	case 2:
		accion = IDLE;
		//accion = ComportamientoAuxiliarNivel_2 (sensores);
		break;
	case 3:
		accion = IDLE;
		//accion = ComportamientoAuxiliarNivel_3 (sensores);
		//accion = ComportamientoAuxiliarNivel_E(sensores);
		break;
	case 4:
		// accion = ComportamientoAuxiliarNivel_4 (sensores);
		break;
	}

	return accion;
}

////////////////////////////////////// NIVEL 0 y 1

double generarNumeroAleatorioA(){

	double prob = static_cast<double>(rand())/RAND_MAX; // genero un numero entre 0.0 y 0.1 que usaré a la hora de evaluar las casillas

	return prob;

}

int VeoCasillaInteresanteA(char i, char c, char d, bool zap){

	double prob = generarNumeroAleatorioA();

	if(prob < 0.9){

		if(c == 'X')
			return 2;
		else if(i == 'X')
			return 1;
		else if(d == 'X')
			return 3;
		else if(!zap){
			if(c == 'D')
				return 2;
			else if(i == 'D')
				return 1;
			else if(d == 'D')
				return 3;
		}
		if(c == 'C')
			return 2;
		else if(i == 'C')
			return 1;
		else if(d == 'C')
			return 3;

	} else if(prob < 0.95){

		if(d == 'X')
			return 3;
		else if(i == 'X')
			return 1;
		else if(c == 'X')
			return 2;
		else if(!zap){
			if(d == 'D')
				return 3;
			else if(i == 'D')
				return 1;
			else if(c == 'D')
				return 2;
		}
		if(d == 'C')
			return 3;
		else if(i == 'C')
			return 1;
		else if(c == 'C')
			return 2;

	} else if(prob < 1.0){

		if(i == 'X')
			return 1;
		else if(c == 'X')
			return 2;
		else if(d == 'X')
			return 3;
		else if(!zap){
			if(i == 'D')
				return 1;
			else if(c == 'D')
				return 2;
			else if(d == 'D')
				return 3;
		}
		if(i == 'C')
			return 1;
		else if(c == 'C')
			return 2;
		else if(d == 'C')
			return 3;

	}

	return 0;
}

int VeoCasillaInteresanteA_nivel1(char i, char c, char d, bool zap){

	double prob = generarNumeroAleatorioA();

	if(prob < 0.9){

		// Orden: c, i, d
		if(c == 'X') return 2;
		else if(i == 'X') return 1;
		else if(d == 'X') return 3;
	
		if(c == 'D') return 2;
		else if(i == 'D') return 1;
		else if(d == 'D') return 3;
	
		if(c == 'C') return 2;
		else if(i == 'C') return 1;
		else if(d == 'C') return 3;
	
		if(c == 'S') return 2;
		else if(i == 'S') return 1;
		else if(d == 'S') return 3;
	
	} else if(prob < 0.92){
	
		// Orden: c, d, i
		if(c == 'X') return 2;
		else if(d == 'X') return 3;
		else if(i == 'X') return 1;
	
		if(c == 'D') return 2;
		else if(d == 'D') return 3;
		else if(i == 'D') return 1;
	
		if(c == 'C') return 2;
		else if(d == 'C') return 3;
		else if(i == 'C') return 1;
	
		if(c == 'S') return 2;
		else if(d == 'S') return 3;
		else if(i == 'S') return 1;
	
	} else if(prob < 0.94){
	
		// Orden: d, i, c
		if(d == 'X') return 3;
		else if(i == 'X') return 1;
		else if(c == 'X') return 2;
	
		if(d == 'D') return 3;
		else if(i == 'D') return 1;
		else if(c == 'D') return 2;
	
		if(d == 'C') return 3;
		else if(i == 'C') return 1;
		else if(c == 'C') return 2;
	
		if(d == 'S') return 3;
		else if(i == 'S') return 1;
		else if(c == 'S') return 2;
	
	} else if(prob < 0.97){
	
		// Orden: d, c, i
		if(d == 'X') return 3;
		else if(c == 'X') return 2;
		else if(i == 'X') return 1;
	
		if(d == 'D') return 3;
		else if(c == 'D') return 2;
		else if(i == 'D') return 1;
	
		if(d == 'C') return 3;
		else if(c == 'C') return 2;
		else if(i == 'C') return 1;
	
		if(d == 'S') return 3;
		else if(c == 'S') return 2;
		else if(i == 'S') return 1;
	
	} else if(prob < 0.99){
	
		// Orden: i, c, d
		if(i == 'X') return 1;
		else if(c == 'X') return 2;
		else if(d == 'X') return 3;
	
		if(i == 'D') return 1;
		else if(c == 'D') return 2;
		else if(d == 'D') return 3;
	
		if(i == 'C') return 1;
		else if(c == 'C') return 2;
		else if(d == 'C') return 3;
	
		if(i == 'S') return 1;
		else if(c == 'S') return 2;
		else if(d == 'S') return 3;
	
	} else {
	
		// Orden: i, d, c
		if(i == 'X') return 1;
		else if(d == 'X') return 3;
		else if(c == 'X') return 2;
	
		if(i == 'D') return 1;
		else if(d == 'D') return 3;
		else if(c == 'D') return 2;
	
		if(i == 'C') return 1;
		else if(d == 'C') return 3;
		else if(c == 'C') return 2;
	
		if(i == 'S') return 1;
		else if(d == 'S') return 3;
		else if(c == 'S') return 2;
	}	

	return 0;
}

int VeoCasillaDisponibleA(char i, char c, char d, bool zap, int posF, int posC, vector<vector<bool>> &m, Orientacion rumbo){

	bool izq, cent, der;

	switch (rumbo){

		case norte:
			izq = m[posF-1][posC-1];
			cent = m[posF-1][posC];
			der = m[posF-1][posC+1];
			
			break;
		
		case noreste:
			izq = m[posF-1][posC];
			cent = m[posF-1][posC+1];
			der = m[posF][posC+1];
			
			break;

		case este:
			izq = m[posF-1][posC+1];
			cent = m[posF][posC+1];
			der = m[posF+1][posC+1];
			
			break;

		case sureste:
			izq = m[posF][posC+1];
			cent = m[posF+1][posC+1];
			der = m[posF+1][posC];
			
			break;
	
		case suroeste:
			izq = m[posF+1][posC];
			cent = m[posF+1][posC-1];
			der = m[posF][posC-1];
			
			break;

		case oeste:
			izq = m[posF+1][posC-1];
			cent = m[posF][posC-1];
			der = m[posF-1][posC-1];
			
			break;

		case noroeste:
			izq = m[posF][posC-1];
			cent = m[posF-1][posC-1];
			der = m[posF-1][posC];
				
			break;

		case sur:
			izq = m[posF+1][posC+1];
			cent = m[posF+1][posC];
			der = m[posF+1][posC-1];
			
			break;

	}

	double prob = generarNumeroAleatorioA();

	if(prob < 0.9){

		// Orden: c, i, d
		if(c == 'X' && !cent) return 2;
		else if(i == 'X' && !izq) return 1;
		else if(d == 'X' && !der) return 3;

		if(!zap){
			if(c == 'D' && !cent) return 2;
			else if(i == 'D' && !izq) return 1;
			else if(d == 'D' && !der) return 3;
		}
	
		if(c == 'C' && !cent) return 2;
		else if(i == 'C' && !izq) return 1;
		else if(d == 'C' && !der) return 3;
	
	} else if(prob < 0.92){
	
		// Orden: c, d, i
		if(c == 'X' && !cent) return 2;
		else if(d == 'X' && !der) return 3;
		else if(i == 'X' && !izq) return 1;
		
		if(!zap){
			if(c == 'D' && !cent) return 2;
			else if(d == 'D' && !der) return 3;
			else if(i == 'D' && !izq) return 1;
		}
	
		if(c == 'C' && !cent) return 2;
		else if(d == 'C' && !der) return 3;
		else if(i == 'C' && !izq) return 1;
	
	} else if(prob < 0.94){
	
		// Orden: d, i, c
		if(d == 'X'&& !der) return 3;
		else if(i == 'X' && !izq) return 1;
		else if(c == 'X' && !cent) return 2;
	
		if(!zap){
			if(d == 'D' && !der) return 3;
			else if(i == 'D' && !izq) return 1;
			else if(c == 'D' && !cent) return 2;
		}
	
		if(d == 'C' && !der) return 3;
		else if(i == 'C' && !izq) return 1;
		else if(c == 'C' && !cent) return 2;
	
	
	} else if(prob < 0.97){
	
		// Orden: d, c, i
		if(d == 'X' && !der) return 3;
		else if(c == 'X' && !cent) return 2;
		else if(i == 'X' && !izq) return 1;
	
		if(!zap){
			if(d == 'D' && !der) return 3;
			else if(c == 'D' && !cent) return 2;
			else if(i == 'D' && !izq) return 1;
		}
	
		if(d == 'C' && !der) return 3;
		else if(c == 'C' && !cent) return 2;
		else if(i == 'C' && !izq) return 1;
	
	
	} else if(prob < 0.99){
	
		// Orden: i, c, d
		if(i == 'X' && !izq) return 1;
		else if(c == 'X' && !cent) return 2;
		else if(d == 'X' && !der) return 3;
	
		if(!zap){
			if(i == 'D' && !izq) return 1;
			else if(c == 'D' && !cent) return 2;
			else if(d == 'D' && !der) return 3;
		}
	
		if(i == 'C' && !izq) return 1;
		else if(c == 'C' && !cent) return 2;
		else if(d == 'C' && !der) return 3;
	
	
	} else {
	
		// Orden: i, d, c
		if(i == 'X' && !izq) return 1;
		else if(d == 'X' && !der) return 3;
		else if(c == 'X' && !cent) return 2;
	
		if(!zap){
			if(i == 'D' && !izq) return 1;
			else if(d == 'D' && !der) return 3;
			else if(c == 'D' && !cent) return 2;
		}
	
		if(i == 'C' && !izq) return 1;
		else if(d == 'C' && !der) return 3;
		else if(c == 'C' && !cent) return 2;
	}

	return 0;

}

int VeoCasillaDisponibleA_nivel1(char i, char c, char d, bool zap, int posF, int posC, vector<vector<bool>> &m, Orientacion rumbo){

	bool izq, cent, der;

	switch (rumbo){

		case norte:
			izq = m[posF-1][posC-1];
			cent = m[posF-1][posC];
			der = m[posF-1][posC+1];
			
			break;
		
		case noreste:
			izq = m[posF-1][posC];
			cent = m[posF-1][posC+1];
			der = m[posF][posC+1];
			
			break;

		case este:
			izq = m[posF-1][posC+1];
			cent = m[posF][posC+1];
			der = m[posF+1][posC+1];
			
			break;

		case sureste:
			izq = m[posF][posC+1];
			cent = m[posF+1][posC+1];
			der = m[posF+1][posC];
			
			break;
	
		case suroeste:
			izq = m[posF+1][posC];
			cent = m[posF+1][posC-1];
			der = m[posF][posC-1];
			
			break;

		case oeste:
			izq = m[posF+1][posC-1];
			cent = m[posF][posC-1];
			der = m[posF-1][posC-1];
			
			break;

		case noroeste:
			izq = m[posF][posC-1];
			cent = m[posF-1][posC-1];
			der = m[posF-1][posC];
				
			break;

		case sur:
			izq = m[posF+1][posC+1];
			cent = m[posF+1][posC];
			der = m[posF+1][posC-1];
			
			break;

	}

	double prob = generarNumeroAleatorioA();

	if(prob < 0.9){

		// Orden: c, i, d
		if(c == 'X' && !cent) return 2;
		else if(i == 'X' && !izq) return 1;
		else if(d == 'X' && !der) return 3;
	
		if(c == 'D' && !cent) return 2;
		else if(i == 'D' && !izq) return 1;
		else if(d == 'D' && !der) return 3;
	
		if(c == 'C' && !cent) return 2;
		else if(i == 'C' && !izq) return 1;
		else if(d == 'C' && !der) return 3;
	
		if(c == 'S' && !cent) return 2;
		else if(i == 'S' && !izq) return 1;
		else if(d == 'S' && !der) return 3;
	
	} else if(prob < 0.92){
	
		// Orden: c, d, i
		if(c == 'X' && !cent) return 2;
		else if(d == 'X' && !der) return 3;
		else if(i == 'X' && !izq) return 1;
	
		if(c == 'D' && !cent) return 2;
		else if(d == 'D' && !der) return 3;
		else if(i == 'D' && !izq) return 1;
	
		if(c == 'C' && !cent) return 2;
		else if(d == 'C' && !der) return 3;
		else if(i == 'C' && !izq) return 1;
	
		if(c == 'S' && !cent) return 2;
		else if(d == 'S' && !der) return 3;
		else if(i == 'S' && !izq) return 1;
	
	} else if(prob < 0.94){
	
		// Orden: d, i, c
		if(d == 'X'&& !der) return 3;
		else if(i == 'X' && !izq) return 1;
		else if(c == 'X' && !cent) return 2;
	
		if(d == 'D' && !der) return 3;
		else if(i == 'D' && !izq) return 1;
		else if(c == 'D' && !cent) return 2;
	
		if(d == 'C' && !der) return 3;
		else if(i == 'C' && !izq) return 1;
		else if(c == 'C' && !cent) return 2;
	
		if(d == 'S' && !der) return 3;
		else if(i == 'S' && !izq) return 1;
		else if(c == 'S' && !cent) return 2;
	
	} else if(prob < 0.97){
	
		// Orden: d, c, i
		if(d == 'X' && !der) return 3;
		else if(c == 'X' && !cent) return 2;
		else if(i == 'X' && !izq) return 1;
	
		if(d == 'D' && !der) return 3;
		else if(c == 'D' && !cent) return 2;
		else if(i == 'D' && !izq) return 1;
	
		if(d == 'C' && !der) return 3;
		else if(c == 'C' && !cent) return 2;
		else if(i == 'C' && !izq) return 1;
	
		if(d == 'S' && !der) return 3;
		else if(c == 'S' && !cent) return 2;
		else if(i == 'S' && !izq) return 1;
	
	} else if(prob < 0.99){
	
		// Orden: i, c, d
		if(i == 'X' && !izq) return 1;
		else if(c == 'X' && !cent) return 2;
		else if(d == 'X' && !der) return 3;
	
		if(i == 'D' && !izq) return 1;
		else if(c == 'D' && !cent) return 2;
		else if(d == 'D' && !der) return 3;
	
		if(i == 'C' && !izq) return 1;
		else if(c == 'C' && !cent) return 2;
		else if(d == 'C' && !der) return 3;
	
		if(i == 'S' && !izq) return 1;
		else if(c == 'S' && !cent) return 2;
		else if(d == 'S' && !der) return 3;
	
	} else {
	
		// Orden: i, d, c
		if(i == 'X' && !izq) return 1;
		else if(d == 'X' && !der) return 3;
		else if(c == 'X' && !cent) return 2;
	
		if(i == 'D' && !izq) return 1;
		else if(d == 'D' && !der) return 3;
		else if(c == 'D' && !cent) return 2;
	
		if(i == 'C' && !izq) return 1;
		else if(d == 'C' && !der) return 3;
		else if(c == 'C' && !cent) return 2;
	
		if(i == 'S' && !izq) return 1;
		else if(d == 'S' && !der) return 3;
		else if(c == 'S' && !cent) return 2;
	}

	return 0;
}

char ViablePorAlturaA(char c, int diff){

	if(abs(diff) <= 1) return c;
	return 'P';

}

void SituarSensorEnMapaA(vector<vector<unsigned char>> &m, vector<vector<unsigned char>> &a, Sensores sensores) {
    
    m[sensores.posF][sensores.posC] = sensores.superficie[0];
    a[sensores.posF][sensores.posC] = sensores.cota[0];

    switch (sensores.rumbo) {

        case norte:

            m[sensores.posF-1][sensores.posC-1] = sensores.superficie[1];
            m[sensores.posF-1][sensores.posC]   = sensores.superficie[2];
            m[sensores.posF-1][sensores.posC+1] = sensores.superficie[3];
            a[sensores.posF-1][sensores.posC-1] = sensores.cota[1];
            a[sensores.posF-1][sensores.posC]   = sensores.cota[2];
            a[sensores.posF-1][sensores.posC+1] = sensores.cota[3];

            m[sensores.posF-2][sensores.posC-2] = sensores.superficie[4];
            m[sensores.posF-2][sensores.posC-1] = sensores.superficie[5];
            m[sensores.posF-2][sensores.posC]   = sensores.superficie[6];
            m[sensores.posF-2][sensores.posC+1] = sensores.superficie[7];
            m[sensores.posF-2][sensores.posC+2] = sensores.superficie[8];
            a[sensores.posF-2][sensores.posC-2] = sensores.cota[4];
            a[sensores.posF-2][sensores.posC-1] = sensores.cota[5];
            a[sensores.posF-2][sensores.posC]   = sensores.cota[6];
            a[sensores.posF-2][sensores.posC+1] = sensores.cota[7];
            a[sensores.posF-2][sensores.posC+2] = sensores.cota[8];

            m[sensores.posF-3][sensores.posC-3] = sensores.superficie[9];
            m[sensores.posF-3][sensores.posC-2] = sensores.superficie[10];
            m[sensores.posF-3][sensores.posC-1] = sensores.superficie[11];
            m[sensores.posF-3][sensores.posC]   = sensores.superficie[12];
            m[sensores.posF-3][sensores.posC+1] = sensores.superficie[13];
            m[sensores.posF-3][sensores.posC+2] = sensores.superficie[14];
            m[sensores.posF-3][sensores.posC+3] = sensores.superficie[15];
            a[sensores.posF-3][sensores.posC-3] = sensores.cota[9];
            a[sensores.posF-3][sensores.posC-2] = sensores.cota[10];
            a[sensores.posF-3][sensores.posC-1] = sensores.cota[11];
            a[sensores.posF-3][sensores.posC]   = sensores.cota[12];
            a[sensores.posF-3][sensores.posC+1] = sensores.cota[13];
            a[sensores.posF-3][sensores.posC+2] = sensores.cota[14];
            a[sensores.posF-3][sensores.posC+3] = sensores.cota[15];
            break;

        case noreste:

            m[sensores.posF-1][sensores.posC]   = sensores.superficie[1];
            m[sensores.posF-1][sensores.posC+1] = sensores.superficie[2];
            m[sensores.posF][sensores.posC+1]   = sensores.superficie[3];
            a[sensores.posF-1][sensores.posC]   = sensores.cota[1];
            a[sensores.posF-1][sensores.posC+1] = sensores.cota[2];
            a[sensores.posF][sensores.posC+1]   = sensores.cota[3];

            m[sensores.posF-2][sensores.posC]   = sensores.superficie[4];
            m[sensores.posF-2][sensores.posC+1] = sensores.superficie[5];
            m[sensores.posF-2][sensores.posC+2] = sensores.superficie[6];
            m[sensores.posF-1][sensores.posC+2]   = sensores.superficie[7];
            m[sensores.posF][sensores.posC+2] = sensores.superficie[8];
            a[sensores.posF-2][sensores.posC]   = sensores.cota[4];
            a[sensores.posF-2][sensores.posC+1] = sensores.cota[5];
            a[sensores.posF-2][sensores.posC+2] = sensores.cota[6];
            a[sensores.posF-1][sensores.posC+2]   = sensores.cota[7];
            a[sensores.posF][sensores.posC+2] = sensores.cota[8];

            m[sensores.posF-3][sensores.posC] = sensores.superficie[9];
            m[sensores.posF-3][sensores.posC+1] = sensores.superficie[10];
            m[sensores.posF-3][sensores.posC+2] = sensores.superficie[11];
            m[sensores.posF-3][sensores.posC+3] = sensores.superficie[12];
            m[sensores.posF-2][sensores.posC+3]   = sensores.superficie[13];
            m[sensores.posF-1][sensores.posC+3] = sensores.superficie[14];
            m[sensores.posF][sensores.posC+3] = sensores.superficie[15];
			a[sensores.posF-3][sensores.posC] = sensores.cota[9];
            a[sensores.posF-3][sensores.posC+1] = sensores.cota[10];
            a[sensores.posF-3][sensores.posC+2] = sensores.cota[11];
            a[sensores.posF-3][sensores.posC+3] = sensores.cota[12];
            a[sensores.posF-2][sensores.posC+3]   = sensores.cota[13];
            a[sensores.posF-1][sensores.posC+3] = sensores.cota[14];
            a[sensores.posF][sensores.posC+3] = sensores.cota[15];
            break;

        case este:

            m[sensores.posF-1][sensores.posC+1] = sensores.superficie[1];
            m[sensores.posF][sensores.posC+1]   = sensores.superficie[2];
            m[sensores.posF+1][sensores.posC+1] = sensores.superficie[3];
            a[sensores.posF-1][sensores.posC+1] = sensores.cota[1];
            a[sensores.posF][sensores.posC+1]   = sensores.cota[2];
            a[sensores.posF+1][sensores.posC+1] = sensores.cota[3];

            m[sensores.posF-2][sensores.posC+2] = sensores.superficie[4];
            m[sensores.posF-1][sensores.posC+2] = sensores.superficie[5];
            m[sensores.posF][sensores.posC+2]   = sensores.superficie[6];
            m[sensores.posF+1][sensores.posC+2] = sensores.superficie[7];
            m[sensores.posF+2][sensores.posC+2] = sensores.superficie[8];
            a[sensores.posF-2][sensores.posC+2] = sensores.cota[4];
            a[sensores.posF-1][sensores.posC+2] = sensores.cota[5];
            a[sensores.posF][sensores.posC+2]   = sensores.cota[6];
            a[sensores.posF+1][sensores.posC+2] = sensores.cota[7];
            a[sensores.posF+2][sensores.posC+2] = sensores.cota[8];

            m[sensores.posF-3][sensores.posC+3] = sensores.superficie[9];
            m[sensores.posF-2][sensores.posC+3] = sensores.superficie[10];
            m[sensores.posF-1][sensores.posC+3] = sensores.superficie[11];
            m[sensores.posF][sensores.posC+3]   = sensores.superficie[12];
            m[sensores.posF+1][sensores.posC+3] = sensores.superficie[13];
            m[sensores.posF+2][sensores.posC+3] = sensores.superficie[14];
            m[sensores.posF+3][sensores.posC+3] = sensores.superficie[15];
            a[sensores.posF-3][sensores.posC+3] = sensores.cota[9];
            a[sensores.posF-2][sensores.posC+3] = sensores.cota[10];
            a[sensores.posF-1][sensores.posC+3] = sensores.cota[11];
            a[sensores.posF][sensores.posC+3]   = sensores.cota[12];
            a[sensores.posF+1][sensores.posC+3] = sensores.cota[13];
            a[sensores.posF+2][sensores.posC+3] = sensores.cota[14];
            a[sensores.posF+3][sensores.posC+3] = sensores.cota[15];
            break;

        case sureste:
            m[sensores.posF][sensores.posC+1]   = sensores.superficie[1];
            m[sensores.posF+1][sensores.posC+1] = sensores.superficie[2];
            m[sensores.posF+1][sensores.posC]   = sensores.superficie[3];
            a[sensores.posF][sensores.posC+1]   = sensores.cota[1];
            a[sensores.posF+1][sensores.posC+1] = sensores.cota[2];
            a[sensores.posF+1][sensores.posC]   = sensores.cota[3];

            m[sensores.posF][sensores.posC+2] = sensores.superficie[4];
            m[sensores.posF+1][sensores.posC+2] = sensores.superficie[5];
            m[sensores.posF+2][sensores.posC+2]   = sensores.superficie[6];
            m[sensores.posF+2][sensores.posC+1] = sensores.superficie[7];
            m[sensores.posF+2][sensores.posC]   = sensores.superficie[8];
			a[sensores.posF][sensores.posC+2] = sensores.cota[4];
            a[sensores.posF+1][sensores.posC+2] = sensores.cota[5];
            a[sensores.posF+2][sensores.posC+2]   = sensores.cota[6];
            a[sensores.posF+2][sensores.posC+1] = sensores.cota[7];
            a[sensores.posF+2][sensores.posC]   = sensores.cota[8];

            m[sensores.posF][sensores.posC+3] = sensores.superficie[9];
            m[sensores.posF+1][sensores.posC+3] = sensores.superficie[10];
            m[sensores.posF+2][sensores.posC+3] = sensores.superficie[11];
            m[sensores.posF+3][sensores.posC+3]   = sensores.superficie[12];
            m[sensores.posF+3][sensores.posC+2] = sensores.superficie[13];
            m[sensores.posF+3][sensores.posC+1] = sensores.superficie[14];
            m[sensores.posF+3][sensores.posC]   = sensores.superficie[15];
            a[sensores.posF][sensores.posC+3] = sensores.cota[9];
            a[sensores.posF+1][sensores.posC+3] = sensores.cota[10];
            a[sensores.posF+2][sensores.posC+3] = sensores.cota[11];
            a[sensores.posF+3][sensores.posC+3]   = sensores.cota[12];
            a[sensores.posF+3][sensores.posC+2] = sensores.cota[13];
            a[sensores.posF+3][sensores.posC+1] = sensores.cota[14];
            a[sensores.posF+3][sensores.posC]   = sensores.cota[15];
            break;

        case sur:

            m[sensores.posF+1][sensores.posC+1] = sensores.superficie[1];
            m[sensores.posF+1][sensores.posC]   = sensores.superficie[2];
            m[sensores.posF+1][sensores.posC-1] = sensores.superficie[3];
            a[sensores.posF+1][sensores.posC+1] = sensores.cota[1];
            a[sensores.posF+1][sensores.posC]   = sensores.cota[2];
            a[sensores.posF+1][sensores.posC-1] = sensores.cota[3];

            m[sensores.posF+2][sensores.posC+2] = sensores.superficie[4];
            m[sensores.posF+2][sensores.posC+1] = sensores.superficie[5];
            m[sensores.posF+2][sensores.posC]   = sensores.superficie[6];
            m[sensores.posF+2][sensores.posC-1] = sensores.superficie[7];
            m[sensores.posF+2][sensores.posC-2] = sensores.superficie[8];
            a[sensores.posF+2][sensores.posC+2] = sensores.cota[4];
            a[sensores.posF+2][sensores.posC+1] = sensores.cota[5];
            a[sensores.posF+2][sensores.posC]   = sensores.cota[6];
            a[sensores.posF+2][sensores.posC-1] = sensores.cota[7];
            a[sensores.posF+2][sensores.posC-2] = sensores.cota[8];

            m[sensores.posF+3][sensores.posC+3] = sensores.superficie[9];
            m[sensores.posF+3][sensores.posC+2] = sensores.superficie[10];
            m[sensores.posF+3][sensores.posC+1] = sensores.superficie[11];
            m[sensores.posF+3][sensores.posC]   = sensores.superficie[12];
            m[sensores.posF+3][sensores.posC-1] = sensores.superficie[13];
            m[sensores.posF+3][sensores.posC-2] = sensores.superficie[14];
            m[sensores.posF+3][sensores.posC-3] = sensores.superficie[15];
            a[sensores.posF+3][sensores.posC+3] = sensores.cota[9];
            a[sensores.posF+3][sensores.posC+2] = sensores.cota[10];
            a[sensores.posF+3][sensores.posC+1] = sensores.cota[11];
            a[sensores.posF+3][sensores.posC]   = sensores.cota[12];
            a[sensores.posF+3][sensores.posC-1] = sensores.cota[13];
            a[sensores.posF+3][sensores.posC-2] = sensores.cota[14];
            a[sensores.posF+3][sensores.posC-3] = sensores.cota[15];
            break;

        case suroeste:

            m[sensores.posF+1][sensores.posC]   = sensores.superficie[1];
            m[sensores.posF+1][sensores.posC-1] = sensores.superficie[2];
            m[sensores.posF][sensores.posC-1]   = sensores.superficie[3];
            a[sensores.posF+1][sensores.posC]   = sensores.cota[1];
            a[sensores.posF+1][sensores.posC-1] = sensores.cota[2];
            a[sensores.posF][sensores.posC-1]   = sensores.cota[3];

            m[sensores.posF+2][sensores.posC]   = sensores.superficie[4];
            m[sensores.posF+2][sensores.posC-1] = sensores.superficie[5];
            m[sensores.posF+2][sensores.posC-2] = sensores.superficie[6];
            m[sensores.posF+1][sensores.posC-2]   = sensores.superficie[7];
            m[sensores.posF][sensores.posC-2] = sensores.superficie[8];
			a[sensores.posF+2][sensores.posC]   = sensores.cota[4];
            a[sensores.posF+2][sensores.posC-1] = sensores.cota[5];
            a[sensores.posF+2][sensores.posC-2] = sensores.cota[6];
            a[sensores.posF+1][sensores.posC-2]   = sensores.cota[7];
            a[sensores.posF][sensores.posC-2] = sensores.cota[8];

            m[sensores.posF+3][sensores.posC]   = sensores.superficie[9];
            m[sensores.posF+3][sensores.posC-1] = sensores.superficie[10];
            m[sensores.posF+3][sensores.posC-2] = sensores.superficie[11];
            m[sensores.posF+3][sensores.posC-3] = sensores.superficie[12];
            m[sensores.posF+2][sensores.posC-3]   = sensores.superficie[13];
            m[sensores.posF+1][sensores.posC-3] = sensores.superficie[14];
            m[sensores.posF][sensores.posC-3] = sensores.superficie[15];
			a[sensores.posF+3][sensores.posC]   = sensores.cota[9];
            a[sensores.posF+3][sensores.posC-1] = sensores.cota[10];
            a[sensores.posF+3][sensores.posC-2] = sensores.cota[11];
            a[sensores.posF+3][sensores.posC-3] = sensores.cota[12];
            a[sensores.posF+2][sensores.posC-3]   = sensores.cota[13];
            a[sensores.posF+1][sensores.posC-3] = sensores.cota[14];
            a[sensores.posF][sensores.posC-3] = sensores.cota[15];
            break;

        case oeste:

            m[sensores.posF+1][sensores.posC-1] = sensores.superficie[1];
            m[sensores.posF][sensores.posC-1]   = sensores.superficie[2];
            m[sensores.posF-1][sensores.posC-1] = sensores.superficie[3];
            a[sensores.posF+1][sensores.posC-1] = sensores.cota[1];
            a[sensores.posF][sensores.posC-1]   = sensores.cota[2];
            a[sensores.posF-1][sensores.posC-1] = sensores.cota[3];

            m[sensores.posF+2][sensores.posC-2] = sensores.superficie[4];
            m[sensores.posF+1][sensores.posC-2] = sensores.superficie[5];
            m[sensores.posF][sensores.posC-2]   = sensores.superficie[6];
            m[sensores.posF-1][sensores.posC-2] = sensores.superficie[7];
            m[sensores.posF-2][sensores.posC-2] = sensores.superficie[8];
            a[sensores.posF+2][sensores.posC-2] = sensores.cota[4];
            a[sensores.posF+1][sensores.posC-2] = sensores.cota[5];
            a[sensores.posF][sensores.posC-2]   = sensores.cota[6];
            a[sensores.posF-1][sensores.posC-2] = sensores.cota[7];
            a[sensores.posF-2][sensores.posC-2] = sensores.cota[8];

            m[sensores.posF+3][sensores.posC-3] = sensores.superficie[9];
            m[sensores.posF+2][sensores.posC-3] = sensores.superficie[10];
            m[sensores.posF+1][sensores.posC-3] = sensores.superficie[11];
            m[sensores.posF][sensores.posC-3]   = sensores.superficie[12];
            m[sensores.posF-1][sensores.posC-3] = sensores.superficie[13];
            m[sensores.posF-2][sensores.posC-3] = sensores.superficie[14];
            m[sensores.posF-3][sensores.posC-3] = sensores.superficie[15];
            a[sensores.posF+3][sensores.posC-3] = sensores.cota[9];
            a[sensores.posF+2][sensores.posC-3] = sensores.cota[10];
            a[sensores.posF+1][sensores.posC-3] = sensores.cota[11];
            a[sensores.posF][sensores.posC-3]   = sensores.cota[12];
            a[sensores.posF-1][sensores.posC-3] = sensores.cota[13];
            a[sensores.posF-2][sensores.posC-3] = sensores.cota[14];
            a[sensores.posF-3][sensores.posC-3] = sensores.cota[15];
            break;

        case noroeste:

            m[sensores.posF][sensores.posC-1]   = sensores.superficie[1];
            m[sensores.posF-1][sensores.posC-1] = sensores.superficie[2];
            m[sensores.posF-1][sensores.posC]   = sensores.superficie[3];
            a[sensores.posF][sensores.posC-1]   = sensores.cota[1];
            a[sensores.posF-1][sensores.posC-1] = sensores.cota[2];
            a[sensores.posF-1][sensores.posC]   = sensores.cota[3];

            m[sensores.posF][sensores.posC-2]   = sensores.superficie[4];
            m[sensores.posF-1][sensores.posC-2] = sensores.superficie[5];
            m[sensores.posF-2][sensores.posC-2] = sensores.superficie[6];
            m[sensores.posF-2][sensores.posC-1]   = sensores.superficie[7];
            m[sensores.posF-2][sensores.posC] = sensores.superficie[8];
			a[sensores.posF][sensores.posC-2]   = sensores.cota[4];
            a[sensores.posF-1][sensores.posC-2] = sensores.cota[5];
            a[sensores.posF-2][sensores.posC-2] = sensores.cota[6];
            a[sensores.posF-2][sensores.posC-1]   = sensores.cota[7];
            a[sensores.posF-2][sensores.posC] = sensores.cota[8];

            m[sensores.posF][sensores.posC-3]   = sensores.superficie[9];
            m[sensores.posF-1][sensores.posC-3] = sensores.superficie[10];
            m[sensores.posF-2][sensores.posC-3] = sensores.superficie[11];
            m[sensores.posF-3][sensores.posC-3] = sensores.superficie[12];
            m[sensores.posF-3][sensores.posC-2]   = sensores.superficie[13];
            m[sensores.posF-3][sensores.posC-1] = sensores.superficie[14];
            m[sensores.posF-3][sensores.posC] = sensores.superficie[15];
			a[sensores.posF][sensores.posC-3]   = sensores.cota[9];
            a[sensores.posF-1][sensores.posC-3] = sensores.cota[10];
            a[sensores.posF-2][sensores.posC-3] = sensores.cota[11];
            a[sensores.posF-3][sensores.posC-3] = sensores.cota[12];
            a[sensores.posF-3][sensores.posC-2]   = sensores.cota[13];
            a[sensores.posF-3][sensores.posC-1] = sensores.cota[14];
            a[sensores.posF-3][sensores.posC] = sensores.cota[15];
            break;
    }
}

///////////////////////////////////////

int ComportamientoAuxiliar::interact(Action accion, int valor)
{
	return 0;
}

/////////////////////////////////////// NIVEL 2 Y 3

void AnularMatrizA(vector<vector<unsigned char>> &m){
	for (int i = 0; i < m[0].size(); i++)
	{
		for (int j = 0; j < m.size(); j++)
		{
			m[i][j] = 0;
		}
	}
}

void ComportamientoAuxiliar::VisualizaPlanA(const EstadoA &st, const list<Action> &plan){
	AnularMatrizA(mapaConPlan);
	EstadoA cst = st;
	auto it = plan.begin();
	while (it != plan.end())
	{
		switch (*it)
		{
			case WALK:
				switch (cst.brujula)
				{
					case 0:
						cst.f--;
					break;
					case 1:
						cst.f--;
						cst.c++;
					break;
					case 2:
						cst.c++;
					break;
					case 3:
						cst.f++;
						cst.c++;
					break;
					case 4:
						cst.f++;
					break;
					case 5:
						cst.f++;
						cst.c--;
					break;
					case 6:
						cst.c--;
					break;
					case 7:
						cst.f--;
						cst.c--;
					break;
				}
				mapaConPlan[cst.f][cst.c] = 2;
				break;
			case TURN_SR:
				cst.brujula = (cst.brujula + 1) % 8;
				break;
		}
			it++;
	}
}

EstadoA NextCasillaAuxiliar(const EstadoA &st){
	EstadoA siguiente = st;
	switch (st.brujula)
	{
	case norte:
	siguiente.f = st.f - 1;
	break;
	case noreste:
	siguiente.f = st.f - 1;
	siguiente.c = st.c + 1;
	break;
	case este:
	siguiente.c = st.c + 1;
	break;
	case sureste:
	siguiente.f = st.f + 1;
	siguiente.c = st.c + 1;
	break;
	case sur:
	siguiente.f = st.f + 1;
	break;
	case suroeste:
	siguiente.f = st.f + 1;
	siguiente.c = st.c - 1;
	break;
	case oeste:
	siguiente.c = st.c - 1;
	break;
	case noroeste:
	siguiente.f = st.f - 1;
	siguiente.c = st.c - 1;
	}
	return siguiente;
	}

bool CasillaAccesibleAuxiliar(const EstadoA &st, const vector<vector<unsigned char>> &terreno,
	const vector<vector<unsigned char>> &altura){
	EstadoA next = NextCasillaAuxiliar(st);
	bool check1 = false, check2 = false, check3 = false;
	check1 = terreno[next.f][next.c] != 'P' and terreno[next.f][next.c] != 'M';
	check2 = terreno[next.f][next.c] != 'B' or (terreno[next.f][next.c] == 'B' and
	st.zapatillas);
	check3 = abs(altura[next.f][next.c] - altura[st.f][st.c]) <= 1;
	return check1 and check2 and check3;
}

EstadoA applyA(Action accion, const EstadoA & st, const vector<vector<unsigned char>> &terreno,
	const vector<vector<unsigned char>> &altura){
	EstadoA next = st;
	switch(accion){
	case WALK:
	if (CasillaAccesibleAuxiliar(st,terreno,altura)){
	next = NextCasillaAuxiliar(st);
	}
	break;
	case TURN_SR:
	next.brujula = (next.brujula+1)%8;
	break;
	}
	return next;
	}

bool Find (const NodoA & st, const list<NodoA> &lista){
	auto it = lista.begin();
	while (it != lista.end() and !((*it) == st)){
		it++;
	}
	return (it != lista.end());
}

int CalculaCosteA(int i, int j, int newI, int newJ, bool zapatillas, Action accion, vector<vector<unsigned char>> &terreno, vector<vector<unsigned char>> &altura){

	int coste = 0;

	char tipo = terreno[newI][newJ];

	if(accion == WALK){
		
		if(altura[i][j] > altura[newI][newJ]){

			switch (tipo){

				case 'A':
					coste = 110;
				break;

				case 'T':
					coste = 25;
				break;

				case 'S':
					coste = 3;
				break;
				
				default:
					coste = 1;
				break;

			};

		} else if(altura[i][j] < altura[newI][newJ]){

			switch (tipo){

				case 'A':
					coste = 90;
				break;

				case 'T':
					coste = 15;
				break;

				case 'S':
					coste = 1;
				break;
				
				default:
					coste = 1;
				break;

			};
			
		} else {

			switch (tipo){

				case 'A':
					coste = 100;
				break;

				case 'T':
					coste = 20;
				break;

				case 'S':
					coste = 2;
				break;
				
				default:
					coste = 1;
				break;

			};

		}

	} else if (accion == TURN_SR){

		switch (tipo){

			case 'A':
				coste = 16;
			break;

			case 'T':
				coste = 3;
			break;

			case 'S':
				coste = 1;
			break;
				
			default:
				coste = 1;
				break;
		};

	}

}

list<Action> avanzaCaballo(){

	list<Action> secuencia;

	secuencia.push_back(WALK);
	secuencia.push_back(WALK);
	secuencia.push_back(TURN_SR);
	secuencia.push_back(TURN_SR);
	secuencia.push_back(WALK);

	return secuencia;
}

list<Action> ComportamientoAuxiliar::AnchuraAuxiliar(const EstadoA &inicio, const EstadoA &final,
	const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura){

	NodoA current_node;
	list<NodoA> frontier;
	list<NodoA> explored;
	list<Action> path;

	current_node.estado = inicio;
	frontier.push_back(current_node);
	bool SolutionFound = (current_node.estado.f == final.f and current_node.estado.c == final.c);

	while (!SolutionFound and !frontier.empty()){

		current_node = frontier.front();
		frontier.pop_front();
		explored.push_back(current_node);

		if (terreno[current_node.estado.f][current_node.estado.c] == 'D') {
			current_node.estado.zapatillas = true;
		}

		NodoA child_WALK = current_node;
		child_WALK.estado = applyA(WALK, current_node.estado, terreno, altura);
		if (!Find(child_WALK, frontier) and !Find(child_WALK, explored)) {
			if (child_WALK.estado.f == final.f and child_WALK.estado.c == final.c){
				child_WALK.secuencia.push_back(WALK);
				SolutionFound = true;
				current_node = child_WALK;
			} else {
				child_WALK.secuencia.push_back(WALK);
				frontier.push_back(child_WALK);
			}
		}

		if (!SolutionFound) {
			NodoA child_TURN_SR = current_node;
			child_TURN_SR.estado = applyA(TURN_SR, current_node.estado, terreno, altura);
			if (!Find(child_TURN_SR, frontier) and !Find(child_TURN_SR, explored)) {
				if (child_TURN_SR.estado.f == final.f and child_TURN_SR.estado.c == final.c){
					child_TURN_SR.secuencia.push_back(TURN_SR);
					SolutionFound = true;
					current_node = child_TURN_SR;
				} else {
					child_TURN_SR.secuencia.push_back(TURN_SR);
					frontier.push_back(child_TURN_SR);
				}
			}
		}
	}

	if (SolutionFound)
		path = current_node.secuencia;

	return path;

}

list<Action> ComportamientoAuxiliar::DijkstraAuxiliar(const EstadoA &inicio, const EstadoA &final, const vector<vector<unsigned char>> &terreno, 
	const vector<vector<unsigned char>> &altura
){
    // Priority queue para Dijkstra (ordenada por coste ascendente)
    priority_queue<NodoA, vector<NodoA>, greater<NodoA>> frontier;
    list<NodoA> explored;
    list<Action> path;

    NodoA current_node;
    current_node.estado = inicio;
    current_node.coste = 0; // Coste inicial
    frontier.push(current_node);

    bool SolutionFound = (current_node.estado == final);

    while (!SolutionFound && !frontier.empty()) {
        current_node = frontier.top(); // Extrae el nodo con menor coste
        frontier.pop();

        if (current_node.estado == final) {
            SolutionFound = true;
            break;
        }

        // Si ya fue explorado con un coste menor, lo ignoramos
        if (Find(current_node, explored))
            continue;

        explored.push_back(current_node);

        // Actualizar zapatillas si está en casilla 'D'
        if (terreno[current_node.estado.f][current_node.estado.c] == 'D') {
            current_node.estado.zapatillas = true;
        }

        // Generar hijos (WALK y TURN_SR)
        Action acciones[] = {WALK, TURN_SR};
        for(Action accion : acciones) {
            NodoA child = current_node;
            child.estado = applyA(accion, current_node.estado, terreno, altura);
            
			if(child == current_node){
				int coste_casilla = CalculaCosteA(current_node.estado.f,	current_node.estado.c, child.estado.f, child.estado.c, child.estado.zapatillas, accion, mapaResultado, mapaCotas);
				child.coste = current_node.coste + coste_casilla;
			}

            if (!Find(child, explored)) {
                child.secuencia.push_back(accion);
                frontier.push(child); // da igual que se inserte duplicado, porque si el nodo ya ha sido explorado simplemente se ignorará aunque sea menos eficiente
            }
        }
    }

    if (SolutionFound)
        path = current_node.secuencia;

    return path;
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_E(Sensores sensores){
	Action accion = IDLE;
	if (!hayPlan){
	// Invocar al método de búsqueda
		EstadoA inicio, fin;
		inicio.f = sensores.posF;
		inicio.c = sensores.posC;
		inicio.brujula = sensores.rumbo;
		inicio.zapatillas = tiene_zapatillas;
		fin.f = sensores.destinoF;
		fin.c = sensores.destinoC;
		plan = AnchuraAuxiliar(inicio, fin, mapaResultado, mapaCotas);
		VisualizaPlanA(inicio,plan);
		hayPlan = plan.size() != 0 ;
	}
	if (hayPlan and plan.size()>0){
		accion = plan.front();
		plan.pop_front();
	}
	if (plan.size()== 0){
		hayPlan = false;
	}
	return accion;
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_0(Sensores sensores)
{
	
	recorrido[sensores.posF][sensores.posC] = true;

    Action accion;

	SituarSensorEnMapaA(mapaResultado, mapaCotas, sensores);

	if (sensores.superficie[0] == 'D')
        tiene_zapatillas = true;

    if (sensores.superficie[0] == 'X') {
        accion = IDLE;
    }
    else if (giro45Izq != 0) {
        accion = TURN_SR;
        giro45Izq--;
    } 
	
	else {


		int c = ViablePorAlturaA(sensores.superficie[2], sensores.cota[2] - sensores.cota[0]);
		int i = ViablePorAlturaA(sensores.superficie[1], sensores.cota[1] - sensores.cota[0]);
		int d = ViablePorAlturaA(sensores.superficie[3], sensores.cota[3] - sensores.cota[0]);

		int pos = VeoCasillaDisponibleA(i, c, d, tiene_zapatillas, sensores.posF, sensores.posC, recorrido, sensores.rumbo);

		switch(pos){

			case 2:
				if(sensores.agentes[2] == '_'){
					accion = WALK;
					mirada_derecha = false;
					mirada_izquierda = false;
				}
				else
					
					if(c == 'X'){
						accion = TURN_SR;
						giro45Izq = 5;
					} else {
						accion = IDLE;
					}

				break;

			case 1:
				accion = TURN_SR;
				giro45Izq = 6;
				break;

			case 3:
				accion = TURN_SR;
				break;
			
			default:


				if(num_giros < 6){
							
					accion = TURN_SR;
					num_giros++;
					if(num_giros == 3){
						num_giros+=3;
						giro45Izq+=3;
					}

				} else {

					if(marcha_atras){

						int pos2 = VeoCasillaInteresanteA(i, c, d, tiene_zapatillas);

						switch(pos2){
							case 2:
								if(sensores.agentes[2] == '_'){
									accion = WALK;
									num_giros2 = 0;
									mirada_derecha_atras = false;
									mirada_izquierda_atras = false;
								}
								else{
									accion = TURN_SR;
									giro45Izq = 5;
								}
								break;

							case 1:
								accion = TURN_SR;
								giro45Izq = 6;
								break;

							case 3:
								accion = TURN_SR;
								break;

							default:
								if(num_giros2 < 6){
							
									accion = TURN_SR;
									num_giros2++;
									if(num_giros2 == 3){
										num_giros2+=3;
										giro45Izq+=3;
									}

								} else{
									
									accion = TURN_SR;
									giro45Izq = 5;

								}
								break;

						}
					} else {
						accion = TURN_SR;
						giro45Izq = 5;
						marcha_atras = true;
					}
				}

			break;
		}

	}

	last_action = accion;

	return last_action;
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_1(Sensores sensores)
{

	recorrido[sensores.posF][sensores.posC] = true;
	
    Action accion;

	SituarSensorEnMapaA(mapaResultado, mapaCotas, sensores);

	if(last_action == WALK){

		num_giros = 0;

	}

	if (sensores.superficie[0] == 'D')
        tiene_zapatillas = true;

    if (giro45Izq != 0) {
        accion = TURN_SR;
        giro45Izq--;
    } 
	
	else {


		int c = ViablePorAlturaA(sensores.superficie[2], sensores.cota[2] - sensores.cota[0]);
		int i = ViablePorAlturaA(sensores.superficie[1], sensores.cota[1] - sensores.cota[0]);
		int d = ViablePorAlturaA(sensores.superficie[3], sensores.cota[3] - sensores.cota[0]);

		int pos = VeoCasillaDisponibleA_nivel1(i, c, d, tiene_zapatillas, sensores.posF,  sensores.posC, recorrido, sensores.rumbo);

		switch(pos){

			case 2:
				if(sensores.agentes[2] == '_')
					accion = WALK;
				else{

					accion = TURN_SR;
					giro45Izq = 5;
				}

				break;

			case 1:
				accion = TURN_SR;
				giro45Izq = 6;
				break;

			case 3:
				accion = TURN_SR;
				break;
			
			default:

				if(num_giros < 6){
						
					accion = TURN_SR;
					num_giros++;
					if(num_giros == 3){
						num_giros+=3;
						giro45Izq+=3;
					}

				} else {

					if(marcha_atras){

						int pos2 = VeoCasillaInteresanteA_nivel1(i, c, d, tiene_zapatillas);

						switch(pos2){
							case 2:
								if(sensores.agentes[2] == '_'){
									accion = WALK;
									num_giros2 = 0;
									mirada_derecha_atras = false;
									mirada_izquierda_atras = false;
								}
								else{
									accion = TURN_SR;
									giro45Izq = 5;
								}
								break;

							case 1:
								accion = TURN_SR;
								giro45Izq = 6;
								break;

							case 3:
								accion = TURN_SR;
								break;

							default:
								if(num_giros2 < 6){
							
									accion = TURN_SR;
									num_giros2++;
									if(num_giros2 == 3){
										num_giros2+=3;
										giro45Izq+=3;
									}

								} else{
									
									accion = TURN_SR;
									giro45Izq = 5;

								}
								break;

						}
					} else {
						accion = TURN_SR;
						giro45Izq = 5;
						marcha_atras = true;
					}
				}

			break;
		}

	}

	last_action = accion;

	return last_action;
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_2(Sensores sensores)
{
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_3(Sensores sensores)
{
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_4(Sensores sensores)
{
}