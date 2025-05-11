#include "../Comportamientos_Jugador/rescatador.hpp"
#include "motorlib/util.h"



////////////////////////////////////	NIVEL 0 Y 1
double generarNumeroAleatorioR(){

	double prob = static_cast<double>(rand())/RAND_MAX; // genero un numero entre 0.0 y 0.1 que usaré a la hora de evaluar las casillas

	return prob;

}

int VeoCasillaInteresanteR(char i, char c, char d, bool zap){


	double prob = generarNumeroAleatorioR();

	if(prob < 0.7){

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

	} else if(prob < 0.85){

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

int VeoCasillaInteresanteR_nivel1(char i, char c, char d, bool zap){

	double prob = generarNumeroAleatorioR();

	if(prob < 0.8){

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
	
	} else if(prob < 0.84){
	
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
	
	} else if(prob < 0.88){
	
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
	
	} else if(prob < 0.92){
	
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
	
	} else if(prob < 0.97){
	
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

int VeoCasillaDisponibleR(char i, char c, char d, bool zap, int posF, int posC, vector<vector<bool>> &m, Orientacion rumbo){

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

	double prob = generarNumeroAleatorioR();

	if(prob < 0.8){

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
	
	} else if(prob < 0.84){
	
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
	
	} else if(prob < 0.88){
	
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
	
	
	} else if(prob < 0.92){
	
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
	
	
	} else if(prob < 0.97){
	
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

int VeoCasillaDisponibleR_nivel1(char i, char c, char d, bool zap, int posF, int posC, vector<vector<bool>> &m, Orientacion rumbo){

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

	double prob = generarNumeroAleatorioR();

	if(prob < 0.8){

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
	
	} else if(prob < 0.84){
	
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
	
	} else if(prob < 0.88){
	
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
	
	} else if(prob < 0.92){
	
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
	
	} else if(prob < 0.97){
	
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

char ViablePorAlturaR(char c, int diff, bool zap){

	if(abs(diff) <= 1 || (zap && abs(diff) <= 2)) return c;
	return 'P';

}

void SituarSensorEnMapaR(vector<vector<unsigned char>> &m, vector<vector<unsigned char>> &a, Sensores sensores) {
    
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
////////////////////////////////////

////////////////////////////////////	NIVEL 2

void AnularMatrizR(vector<vector<unsigned char>> &m){
	for (int i = 0; i < m[0].size(); i++)
	{
		for (int j = 0; j < m.size(); j++)
		{
			m[i][j] = 0;
		}
	}
}

void ComportamientoRescatador::VisualizaPlanR(const EstadoR &st, const list<Action> &plan){
	AnularMatrizR(mapaConPlan);
	EstadoR cst = st;
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
			case TURN_L:
				cst.brujula = (cst.brujula + 6) % 8;
				break;
			case RUN:
				switch (cst.brujula)
				{
					case 0:
						cst.f-=2;
					break;
					case 1:
						cst.f-=2;
						cst.c+=2;
					break;
					case 2:
						cst.c+=2;
					break;
					case 3:
						cst.f+=2;
						cst.c+=2;
					break;
					case 4:
						cst.f+=2;
					break;
					case 5:
						cst.f+=2;
						cst.c-=2;
					break;
					case 6:
						cst.c-=2;
					break;
					case 7:
						cst.f-=2;
						cst.c-=2;
					break;
				}
				mapaConPlan[cst.f][cst.c] = 2;
			break;
				
		}
			it++;
	}
}

void ComportamientoRescatador::PintaPlan(const list<Action> &plan, bool zap)
{
auto it = plan.begin();
while (it != plan.end())
{
if (*it == WALK)
{
cout << "W ";
}
else if (*it == RUN)
{
cout << "R ";
}
else if (*it == TURN_SR)
{
cout << "r ";
}
else if (*it == TURN_L)
{
cout << "L ";
}
else if (*it == CALL_ON)
{
cout << "C ";
}
else if (*it == CALL_OFF)
{
cout << "c ";
}
else if (*it == IDLE)
{
cout << "I ";
}
else
{
cout << "-_ ";
}
it++;
}
cout << "( longitud " << plan.size();
if (zap) cout << "[Z]";
cout << ")\n";
}

EstadoR NextCasillaR(const EstadoR &st){
	EstadoR siguiente = st;
	switch (st.brujula)
	{
	case 0:
	siguiente.f = st.f - 1;
	break;
	case 1:
	siguiente.f = st.f - 1;
	siguiente.c = st.c + 1;
	break;
	case 2:
	siguiente.c = st.c + 1;
	break;
	case 3:
	siguiente.f = st.f + 1;
	siguiente.c = st.c + 1;
	break;
	case 4:
	siguiente.f = st.f + 1;
	break;
	case 5:
	siguiente.f = st.f + 1;
	siguiente.c = st.c - 1;
	break;
	case 6:
	siguiente.c = st.c - 1;
	break;
	case 7:
	siguiente.f = st.f - 1;
	siguiente.c = st.c - 1;
	}
	return siguiente;
	}

bool CasillaAccesibleR(const EstadoR &st, const vector<vector<unsigned char>> &terreno,
	const vector<vector<unsigned char>> &altura){
		EstadoR next = NextCasillaR(st);
	bool check1 = false, check2 = false, check3 = false;
	check1 = terreno[next.f][next.c] != 'P' && terreno[next.f][next.c] != 'M';
	check2 = terreno[next.f][next.c] != 'B';
	if(!st.zapatillas){
		check3 = abs(altura[next.f][next.c] - altura[st.f][st.c]) <= 1;
	}
	else {
		check3 = abs(altura[next.f][next.c] - altura[st.f][st.c]) <= 2;
	}

	return check1 && check2 && check3;
}

bool CasillaAccesibleIntermedia(const EstadoR &st, const vector<vector<unsigned char>> &terreno, int altura, int newAltura){
		EstadoR next = NextCasillaR(st);
	bool check1 = false, check2 = false, check3 = true;
	check1 = terreno[next.f][next.c] != 'P' && terreno[next.f][next.c] != 'M';
	check2 = terreno[next.f][next.c] != 'B';
	if(st.zapatillas)
		check3 = abs(altura - newAltura) <= 2;
	else
		check3 = abs(altura - newAltura) <= 1;

	return check1 && check2 && check3;
}

EstadoR applyR(Action accion, const EstadoR & st, const vector<vector<unsigned char>> &terreno,
	const vector<vector<unsigned char>> &altura){
	EstadoR next;
	next.c = -1; // valores imposibles para evitar las comparaciones entre estados, solamente tengo qeu comprobar si la fila es -1 entonces sería un estado fallido
	next.f = -1;

	switch(accion){
		case WALK:
			if (CasillaAccesibleR(st,terreno,altura)){
				next = NextCasillaR(st);
			}
		break;
		case TURN_SR:
			next = st;
			next.brujula = (next.brujula + 1 ) % 8;
		break;
		case TURN_L:
			next = st;
			next.brujula = (next.brujula + 6 ) % 8;
		break;
		case RUN:
			EstadoR intermedio = NextCasillaR(st);
			if (CasillaAccesibleIntermedia(st, terreno, 0, 0)) { 
				EstadoR temp = intermedio;
				if (terreno[temp.f][temp.c] == 'D') {
					temp.zapatillas = true;
				}
				EstadoR next2 = NextCasillaR(temp);
				if (CasillaAccesibleIntermedia(temp, terreno, altura[st.f][st.c], altura[next2.f][next2.c])) { // Altura y terreno final
					next = next2; 
				}
			}
		break;
	}

	return next;
}

int CalculaCosteR(int i, int j, int newI, int newJ, Action accion, const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura){

	int coste = 0;

	char tipo = terreno[i][j];
	int altura1 = altura[i][j];
	int altura2 = altura[newI][newJ];
	int mult = 0;
	if(altura1 - altura2 != 0)
		mult = (altura1 - altura2) < 0 ? +1 : -1;

	if(accion == WALK){
		
		switch (tipo){

			case 'A':
				coste = 100 + (10 * mult);
			break;

			case 'T':
				coste = 20 + (5 * mult);
			break;

			case 'S':
				coste = 2 + (1 * mult);
			break;
				
			default:
				coste = 1;
			break;

		};


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

	} else if(accion == TURN_L){

		switch (tipo){

			case 'A':
				coste = 30;
			break;

			case 'T':
				coste = 5;
			break;

			case 'S':
				coste = 1;
			break;
				
			default:
				coste = 1;
				break;
		};
	
	} else if(accion == RUN){

		switch (tipo){

			case 'A':
				coste = 150 + (15 * mult);
			break;

			case 'T':
				coste = 35 + (5 * mult);
			break;

			case 'S':
				coste = 3 + (2 * mult);
			break;
			
			default:
				coste = 1;
			break;

		};
	}

	return coste;
}

list<Action> ComportamientoRescatador::DijkstraR(const EstadoR &inicio, const EstadoR &final, const vector<vector<unsigned char>> &terreno, 
	const vector<vector<unsigned char>> &altura
){
    priority_queue<NodoR, vector<NodoR>, greater<NodoR>> frontier;
    map<EstadoR, int> explored;
    list<Action> path;

    NodoR current_node;
    current_node.estado = inicio;
    current_node.coste = 0;
    frontier.push(current_node);

    bool SolutionFound = (current_node.estado == final);

    while (!SolutionFound && !frontier.empty()) {

        current_node = frontier.top();
        frontier.pop();

		if (terreno[current_node.estado.f][current_node.estado.c] == 'D') {
			current_node.estado.zapatillas = true;				
		}
		
		if(explored.find(current_node.estado) != explored.end()){
			if(explored[current_node.estado] <= current_node.coste)
				continue; // salta esta exploracion de nodo si ya se ha explorado con un menor coste
		}

		explored[current_node.estado] = current_node.coste;

		if (current_node.estado.f == final.f && current_node.estado.c == final.c) {
            SolutionFound = true;
            break;
        }

        Action acciones[] = {RUN, TURN_SR, TURN_L, WALK}; // van a ser todas las posibles direcciones
        for(Action accion : acciones) {
            NodoR child = current_node;
            child.estado = applyR(accion, current_node.estado, terreno, altura);

			if(child.estado.f != -1){

				if(terreno[child.estado.f][child.estado.c] == 'D'){
					child.estado.zapatillas = true; // vuelvo a actualizar el nodo en caso de que se encuentre en una casilla de zapatillas por si fallara
				}

				int coste_casilla = CalculaCosteR(current_node.estado.f,current_node.estado.c, child.estado.f, child.estado.c, accion, terreno, altura);
				//int coste_casilla = CalcularCoste(accion, terreno[current_node.estado.f][current_node.estado.c], altura[current_node.estado.f][current_node.estado.c], altura[child.estado.f][child.estado.c]);
				child.coste = current_node.coste + coste_casilla;

				if (explored.find(child.estado) == explored.end() || child.coste < explored[child.estado]) {
					child.secuencia.push_back(accion);
					frontier.push(child);
				}
			}

        }
    }

    if (SolutionFound){
        path = current_node.secuencia;
	}

    return path;
}

//////////////////////////////////// 

////////////////////////////////////	NIVEL 3

Action ComportamientoRescatador::think(Sensores sensores)
{
	Action accion = IDLE;

	switch (sensores.nivel)
	{
	case 0:
		accion = ComportamientoRescatadorNivel_0 (sensores);
		break;
	case 1:
		accion = ComportamientoRescatadorNivel_1 (sensores);
		break;
	case 2:
		//accion = ComportamientoRescatadorNivel_E(sensores);
		accion = ComportamientoRescatadorNivel_2 (sensores);
		break;
	case 3:
		accion = IDLE;
		//accion = ComportamientoRescatadorNivel_3 (sensores);
		break;
	case 4:
		// accion = ComportamientoRescatadorNivel_4 (sensores);
		break;
	}

	return accion;
}

int ComportamientoRescatador::interact(Action accion, int valor)
{
	return 0;
}


Action ComportamientoRescatador::ComportamientoRescatadorNivel_0(Sensores sensores)
{

	recorrido[sensores.posF][sensores.posC] = true;

    Action accion;

	SituarSensorEnMapaR(mapaResultado, mapaCotas, sensores);

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


		int c = ViablePorAlturaR(sensores.superficie[2], sensores.cota[2] - sensores.cota[0], tiene_zapatillas);
		int i = ViablePorAlturaR(sensores.superficie[1], sensores.cota[1] - sensores.cota[0], tiene_zapatillas);
		int d = ViablePorAlturaR(sensores.superficie[3], sensores.cota[3] - sensores.cota[0], tiene_zapatillas);
		
		int pos = VeoCasillaDisponibleR(i, c, d, tiene_zapatillas, sensores.posF,  sensores.posC, recorrido, sensores.rumbo);

		switch(pos){

			case 2:
				if(sensores.agentes[2] == '_'){
					accion = WALK;
					mirada_derecha = false;
					mirada_izquierda = false;
					marcha_atras = false;
				}
				else{
					accion = TURN_L;
				}
				break;

			case 1:
				accion = TURN_L;
				giro45Izq = 1;
				break;

			case 3:
				accion = TURN_SR;
				break;
			
			default:

				if(!mirada_izquierda){

					accion = TURN_L;
					mirada_izquierda = true;

				} else if(!mirada_derecha){

					accion = TURN_SR;
					giro45Izq = 3;
					mirada_derecha = true;

				} else {
				
					if(marcha_atras){

						int pos2 = VeoCasillaInteresanteR(i, c, d, tiene_zapatillas);

						switch(pos2){
							case 2:
								if(sensores.agentes[2] == '_'){
									accion = WALK;
									mirada_derecha_atras = false;
									mirada_izquierda_atras = false;
								}
								else
									accion = TURN_L;
								break;

							case 1:
								accion = TURN_L;
								giro45Izq = 1;
								break;

							case 3:
								accion = TURN_SR;
								break;

							default:
								if(!mirada_izquierda_atras){

									accion = TURN_L;
									mirada_izquierda = true;
				
								} else if(!mirada_derecha_atras){
				
									accion = TURN_SR;
									giro45Izq = 3;
									mirada_derecha_atras = true;

								} else{
									
									accion = TURN_SR;
									giro45Izq = 1;

								}
								break;

						}
					} else {
						accion = TURN_SR;
						giro45Izq = 1;
						marcha_atras = true;
					}

				}

				break;

		}

	}

    last_action = accion;

    return accion;
}


Action ComportamientoRescatador::ComportamientoRescatadorNivel_1(Sensores sensores)
{

	recorrido[sensores.posF][sensores.posC] = true;

    Action accion;

	SituarSensorEnMapaR(mapaResultado, mapaCotas, sensores);

	if (sensores.superficie[0] == 'D')
        tiene_zapatillas = true;

    
	if(giro45Izq != 0) {
        accion = TURN_SR;
        giro45Izq--;
    } 

	else {


		int c = ViablePorAlturaR(sensores.superficie[2], sensores.cota[2] - sensores.cota[0], tiene_zapatillas);
		int i = ViablePorAlturaR(sensores.superficie[1], sensores.cota[1] - sensores.cota[0], tiene_zapatillas);
		int d = ViablePorAlturaR(sensores.superficie[3], sensores.cota[3] - sensores.cota[0], tiene_zapatillas);

		int pos = VeoCasillaDisponibleR_nivel1(i, c, d, tiene_zapatillas, sensores.posF,  sensores.posC, recorrido, sensores.rumbo);
		

		switch(pos){

			case 2:
				if(sensores.agentes[2] == '_'){
					accion = WALK;
					mirada_derecha = false;
					mirada_izquierda = false;
					marcha_atras = false;
				}
				else{
					accion = TURN_L;
				}
				break;

			case 1:
				accion = TURN_L;
				giro45Izq = 1;
				break;

			case 3:
				accion = TURN_SR;
				break;
			
			default:

				if(!mirada_izquierda){

					accion = TURN_L;
					mirada_izquierda = true;

				} else if(!mirada_derecha){

					accion = TURN_SR;
					giro45Izq = 3;
					mirada_derecha = true;

				} else {

					if(marcha_atras){

						int pos2 = VeoCasillaInteresanteR_nivel1(i, c, d, tiene_zapatillas);

						switch(pos2){
							case 2:
								if(sensores.agentes[2] == '_'){
									accion = WALK;
									mirada_derecha_atras = false;
									mirada_izquierda_atras = false;
								}
								else
									accion = TURN_L;
								break;

							case 1:
								accion = TURN_L;
								giro45Izq = 1;
								break;

							case 3:
								accion = TURN_SR;
								break;

							default:
								if(!mirada_izquierda_atras){

									accion = TURN_L;
									mirada_izquierda_atras = true;
				
								} else if(!mirada_derecha_atras){
				
									accion = TURN_SR;
									giro45Izq = 3;
									mirada_derecha_atras = true;

								} else{
									
									accion = TURN_SR;
									giro45Izq = 1;

								}
								break;

						}
					} else {
						accion = TURN_SR;
						giro45Izq = 1;
						marcha_atras = true;
					}

				}

				break;
		}

	}


    last_action = accion;

    return accion;
}

Action ComportamientoRescatador::ComportamientoRescatadorNivel_2(Sensores sensores)
{
	Action accion = IDLE;
	if (!hayPlan){
	// Invocar al método de búsqueda
		EstadoR inicio, fin;
		inicio.f = sensores.posF;
		inicio.c = sensores.posC;
		inicio.brujula = sensores.rumbo;
		inicio.zapatillas = tiene_zapatillas;
		fin.f = sensores.destinoF;
		fin.c = sensores.destinoC;
		plan = DijkstraR(inicio, fin, mapaResultado, mapaCotas);
		VisualizaPlanR(inicio,plan);
		PintaPlan(plan, tiene_zapatillas);
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


Action ComportamientoRescatador::ComportamientoRescatadorNivel_3(Sensores sensores)
{
}

Action ComportamientoRescatador::ComportamientoRescatadorNivel_4(Sensores sensores)
{
}
