#include "../Comportamientos_Jugador/rescatador.hpp"
#include "motorlib/util.h"


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

/*void SituarSensorEnMapaR(vector<vector<unsigned char>> &m, vector<vector<unsigned char>> &a, Sensores sensores){

	m[sensores.posF][sensores.posC] = sensores.superficie[0];
	a[sensores.posF][sensores.posC] = sensores.cota[0];

	int pos = 1;
	switch (sensores.rumbo){

		case norte:
			m[sensores.posF-1][sensores.posC-1] = sensores.superficie[1];
			m[sensores.posF-1][sensores.posC] = sensores.superficie[2];
			m[sensores.posF-1][sensores.posC+1] = sensores.superficie[3];
			a[sensores.posF-1][sensores.posC-1] = sensores.cota[1];
			a[sensores.posF-1][sensores.posC] = sensores.cota[2];
			a[sensores.posF-1][sensores.posC+1] = sensores.cota[3];
			
			break;
		
		case noreste:
			m[sensores.posF-1][sensores.posC] = sensores.superficie[1];
			m[sensores.posF-1][sensores.posC+1] = sensores.superficie[2];
			m[sensores.posF][sensores.posC+1] = sensores.superficie[3];
			a[sensores.posF-1][sensores.posC] = sensores.cota[1];
			a[sensores.posF-1][sensores.posC+1] = sensores.cota[2];
			a[sensores.posF][sensores.posC+1] = sensores.cota[3];
			
			break;

		case este:
			m[sensores.posF-1][sensores.posC+1] = sensores.superficie[1];
			m[sensores.posF][sensores.posC+1] = sensores.superficie[2];
			m[sensores.posF+1][sensores.posC+1] = sensores.superficie[3];
			a[sensores.posF-1][sensores.posC+1] = sensores.cota[1];
			a[sensores.posF][sensores.posC+1] = sensores.cota[2];
			a[sensores.posF+1][sensores.posC+1] = sensores.cota[3];
			
			break;

		case sureste:
			m[sensores.posF][sensores.posC+1] = sensores.superficie[1];
			m[sensores.posF+1][sensores.posC+1] = sensores.superficie[2];
			m[sensores.posF+1][sensores.posC] = sensores.superficie[3];
			a[sensores.posF][sensores.posC+1] = sensores.cota[1];
			a[sensores.posF+1][sensores.posC+1] = sensores.cota[2];
			a[sensores.posF+1][sensores.posC] = sensores.cota[3];
			
			break;
	
		case suroeste:
			m[sensores.posF+1][sensores.posC] = sensores.superficie[1];
			m[sensores.posF+1][sensores.posC-1] = sensores.superficie[2];
			m[sensores.posF][sensores.posC-1] = sensores.superficie[3];
			a[sensores.posF+1][sensores.posC] = sensores.cota[1];
			a[sensores.posF+1][sensores.posC-1] = sensores.cota[2];
			a[sensores.posF][sensores.posC-1] = sensores.cota[3];
			
			break;

		case oeste:
			m[sensores.posF+1][sensores.posC-1] = sensores.superficie[1];
			m[sensores.posF][sensores.posC-1] = sensores.superficie[2];
			m[sensores.posF-1][sensores.posC-1] = sensores.superficie[3];
			a[sensores.posF+1][sensores.posC-1] = sensores.cota[1];
			a[sensores.posF][sensores.posC-1] = sensores.cota[2];
			a[sensores.posF-1][sensores.posC-1] = sensores.cota[3];
			
			break;

		case noroeste:
			m[sensores.posF][sensores.posC-1] = sensores.superficie[1];
			m[sensores.posF-1][sensores.posC-1] = sensores.superficie[2];
			m[sensores.posF-1][sensores.posC] = sensores.superficie[3];
			a[sensores.posF][sensores.posC-1] = sensores.cota[1];
			a[sensores.posF-1][sensores.posC-1] = sensores.cota[2];
			a[sensores.posF-1][sensores.posC] = sensores.cota[3];
			
			break;

		case sur:
			m[sensores.posF+1][sensores.posC+1] = sensores.superficie[1];
			m[sensores.posF+1][sensores.posC] = sensores.superficie[2];
			m[sensores.posF+1][sensores.posC-1] = sensores.superficie[3];
			a[sensores.posF+1][sensores.posC+1] = sensores.cota[1];
			a[sensores.posF+1][sensores.posC] = sensores.cota[2];
			a[sensores.posF+1][sensores.posC-1] = sensores.cota[3];
			
			break;

	}


}*/

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

Action ComportamientoRescatador::think(Sensores sensores)
{
	Action accion = WALK;

	switch (sensores.nivel)
	{
	case 0:
		accion = ComportamientoRescatadorNivel_0 (sensores);
		break;
	case 1:
		accion = ComportamientoRescatadorNivel_1 (sensores);
		break;
	case 2:
		// accion = ComportamientoRescatadorNivel_2 (sensores);
		break;
	case 3:
		// accion = ComportamientoRescatadorNivel_3 (sensores);
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
}

Action ComportamientoRescatador::ComportamientoRescatadorNivel_3(Sensores sensores)
{
}

Action ComportamientoRescatador::ComportamientoRescatadorNivel_4(Sensores sensores)
{
}
