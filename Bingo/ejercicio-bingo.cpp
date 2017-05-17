#include <iostream>
#include <ctime>
#include <cstddef>
#include <cstdlib>
#include <string.h>
#define M 5
using namespace std;

	// PROTOTYPE FOR RAND INIT ..
	void init_rand(void);
	// BUSCADOR DE NUMEROS YA GENERADOS del carton y de las pelotas
	int search_number(int number,int vector[25]);
	// Creador de cartones
	void crear_carton(int carton[5][5],int numeros[25]);
	// inicializa una variable del tipo vector importante!
	void init_numeros(int numeros[25]);
	// inicializa la matrix encontados
	void init_encontrados(int encontrados[5][5]);
	//void generar_numero(int numero2) XD
	void generar_numero(int numero2[25]);
	// buscar si se lleno el carton
	int carton_lleno(int encontrados1[5][5],char *name);
	// otra gun
	void imprimir_carton(int carton1[5][5], int encontrados[5][5]);
	// variable global
	int contador = 0;
	//void encontrar_en_carton(int carton1[5][5], int encontrados[5][5])
	void encontrar_en_carton(int carton1[5][5], int encontrados[5][5],int numeros[25]);
	// busca en filas
	void verificar_filas(int encontrados1[5][5],char *name);
	//busca en columnas
	void verificar_columnas(int encontrados1[5][5],char *name);
	// busca diagonales
	void busqda_diagonal_negativa(int encontrados1[5][5],char *name);
	void busqda_diagonal_positiva(int encontrados1[5][5],char *name);
	
	
int main(int argc, char *argv[]) {
//escriba un programa que permita generar 5 cartones del popular<--- jJAJAJJAJA XD  juego bingo,
//los cartones deben ser generados de manera aleatoria e inicialmente mostrados por pantalla.
//el sistema debe dar la opcion al ususario de ir generando los numeros del sorteo e ir mostrando
//por cada numero sorteado los cartones e ir distinguiendo los asiertos, el programa termina cuando en un carton
//se logra completar algunas de las siguientes asiertos:
//1 fila o columnas llenas, 4 esquinas, diagonal mayor y diagonal menor.
//Tome en cuenta todas las validaciones.
	
	// jugador 1
	int carton1[5][5];
	char nombre1[30];
	int encontrados1[5][5]; // cuatos del carton tengo de las pelotas
	// jugador 2
	int carton2[5][5];
	char nombre2[30];
	int encontrados2[5][5]; // cuatos del carton tengo de las pelotas
	// jugador 3
	int carton3[5][5];
	char nombre3[30];
	int encontrados3[5][5]; // cuatos del carton tengo de las pelotas
	// jugador 4 
	int carton4[5][5];
	char nombre4[30];
	int encontrados4[5][5]; // cuatos del carton tengo de las pelotas
	// pos el otro 
	int carton5[5][5];
	char nombre5[30];
	int encontrados5[5][5]; // cuatos del carton tengo de las pelotas
		
	// Numeros que an salido en cartones XD
	int numeros[25];
	// Numeros que an salido en pelotas XD
	int numeros2[25];
	
	// Empieza el juego
	cout << "Ingresa un nombre para el jugador1: ";
	cin.getline(nombre1,29);
	
	cout << "Ingresa un nombre para el jugador2: ";
	cin.getline(nombre2,29);
	while( strcmp(nombre1,nombre2) == 0 ){
		cout << "Ingresa un nombre para el jugador2 que no tenga otro jugador: ";
		cin.getline(nombre2,29);
	}
	
	cout << "Ingresa un nombre para el jugador3: ";
	cin.getline(nombre3,29);
	while( strcmp(nombre1,nombre3) == 0 || strcmp(nombre2,nombre3) == 0){
		cout << "Ingresa un nombre para el jugador2 que no tenga otro jugador: ";
		cin.getline(nombre3,29);
	}
	
	cout << "Ingresa un nombre para el jugador4: ";
	cin.getline(nombre4,29);
	while( strcmp(nombre1,nombre4) == 0 || strcmp(nombre2,nombre4) == 0 || strcmp(nombre3,nombre4) == 0 ){
		cout << "Ingresa un nombre para el jugador2 que no tenga otro jugador: ";
		cin.getline(nombre4,29);
	}
	
	cout << "Ingresa un nombre para el jugador5: ";
	cin.getline(nombre5,29);
	while( strcmp(nombre1,nombre5) == 0 || strcmp(nombre2,nombre5) == 0 || strcmp(nombre3,nombre5) == 0 || strcmp(nombre4,nombre5) == 0){
		cout << "Ingresa un nombre para el jugador2 que no tenga otro jugador: ";
		cin.getline(nombre5,29);
	}
	
	// carga la matriz como si no encontro ninguno
	init_encontrados(encontrados1);
	init_encontrados(encontrados2);
	init_encontrados(encontrados3);
	init_encontrados(encontrados4);
	init_encontrados(encontrados5);
	
	// mas profecional..

	init_numeros(numeros);
	
	//Carga de datos version 2.0 XD
	crear_carton(carton1,numeros);
	crear_carton(carton2,numeros);
	crear_carton(carton3,numeros);
	crear_carton(carton4,numeros);
	crear_carton(carton5,numeros);
	
	ref1:
		

	// todo listo para la logia del juego desde este punto
	system("cls");
	
	generar_numero(numeros2);
		
	encontrar_en_carton(carton1,encontrados1,numeros2);
	encontrar_en_carton(carton2,encontrados2,numeros2);
	encontrar_en_carton(carton3,encontrados3,numeros2);
	encontrar_en_carton(carton4,encontrados4,numeros2);
	encontrar_en_carton(carton5,encontrados5,numeros2);
	
	
	cout << "carton del jugador1: " << nombre1 << endl;
	imprimir_carton(carton1,encontrados1);
	cout << "carton del jugador2: " << nombre2 << endl;
	imprimir_carton(carton2,encontrados2);
	cout << "carton del jugador3: " << nombre3 << endl;
	imprimir_carton(carton3,encontrados3);
	cout << "carton del jugador4: " << nombre4 << endl;
	imprimir_carton(carton4,encontrados4);
	cout << "carton del jugador5: " << nombre5 << endl;
	imprimir_carton(carton5,encontrados5);
	
	
	
	// buscar carton lleno
	carton_lleno(encontrados1,nombre1);
	carton_lleno(encontrados2,nombre2);
	carton_lleno(encontrados3,nombre3);
	carton_lleno(encontrados4,nombre4);
	carton_lleno(encontrados5,nombre5);
	
	// buscar filas
	verificar_filas(encontrados1,nombre1);
	verificar_filas(encontrados2,nombre2);
	verificar_filas(encontrados3,nombre3);
	verificar_filas(encontrados4,nombre4);
	verificar_filas(encontrados5,nombre5);
	
	// verificar columnas
	verificar_columnas(encontrados1,nombre1);
	verificar_columnas(encontrados2,nombre2);
	verificar_columnas(encontrados3,nombre3);
	verificar_columnas(encontrados4,nombre4);
	verificar_columnas(encontrados5,nombre5);
	
	// verificar diagonales
	busqda_diagonal_negativa(encontrados1,nombre1);
	busqda_diagonal_negativa(encontrados2,nombre2);
	busqda_diagonal_negativa(encontrados3,nombre3);
	busqda_diagonal_negativa(encontrados4,nombre4);
	busqda_diagonal_negativa(encontrados5,nombre5);
	
	busqda_diagonal_positiva(encontrados1,nombre1);
	busqda_diagonal_positiva(encontrados2,nombre2);
	busqda_diagonal_positiva(encontrados3,nombre3);
	busqda_diagonal_positiva(encontrados4,nombre4);
	busqda_diagonal_positiva(encontrados5,nombre5);
	
	cout << " se a generado un numero " << endl;
	cout << "numeros que an salido " << contador << endl;
	for	( int i = 0; i < contador; i++){
		cout << numeros2[i] << " ";
		if ( i%10 == 0 && i!= 0 ){
			cout << endl;
		}
	}
	cout << endl;
	
	cout << "Presiona enter para mostar resultados y sacar otro numero... (MAXIMO 25 POR LOS MOMENTOS) " << endl;
	
	cin.get();
	
	goto ref1;

}

void busqda_diagonal_negativa(int encontrados1[5][5],char *name){
	int x = 0;
	int y = 5;
	int contador = 0;
	
	while( x < 5 && y < 5){
		if( encontrados1[x][y] == 1){
			contador++;
		}
		x++;
		y--;
	}
	if ( contador == 5){
		cout << name << " GANA! por diagoanl negativa llena " << endl;
		cin.get();
	}
}

void busqda_diagonal_positiva(int encontrados1[5][5],char *name){
	int x = 0;
	int y = 0;
	int contador = 0;
	
	while( x < 5 && y < 5){
		if( encontrados1[x][y] == 1){
			contador++;
		}
		x++;
		y++;
	}
	if ( contador == 5){
		cout << name << " GANA! por diagoanl positiva llena " << endl;
		cin.get();
	}
}

void verificar_filas(int encontrados1[5][5],char *name){
	int	contador = 0;
	// cuando llega a 5 gana...
	for( int i = 0; i < 5; i++){
		contador = 0;
		for( int x = 0; x < 5; x++){
			if( encontrados1[x][i] == 1 ){
				contador++;
			}
		}
		if	( contador == 5 ){
			cout << name << " GANA! por fila " << i << " llena!" << endl;
			cin.get();
		}	
	}
}

void verificar_columnas(int encontrados1[5][5],char *name){
	int	contador = 0;
	// cuando llega a 5 gana...
	for( int i = 0; i < 5; i++){
		contador = 0;
		for( int x = 0; x < 5; x++){
			if( encontrados1[i][x] == 1 ){
				contador++;
			}
		}
		if	( contador == 5 ){
			cout << name << " GANA! por columna " << i << " llena!" << endl;
			cin.get();
		}	
	}

}

void encontrar_en_carton(int carton1[5][5], int encontrados[5][5],int numeros[25]){
	for( int i = 0; i < 5; i++){
		for( int x = 0; x < 5; x++){
			if( search_number(carton1[i][x],numeros) ){
				encontrados[i][x] = 1;
			}
		}	
	}
}

int carton_lleno(int encontrados1[5][5],char *name){
	int	contador = 0;
	// cuando llega a 25 el carto esta lleno .. gana...
	for( int i = 0; i < 5; i++){
		for( int x = 0; x < 5; x++){
			if( encontrados1[i][x] == 1 ){
				contador++;
			}
		}	
	}
	if	( contador == 25 ){
		cout << name << " GANA! por carton lleno!" << endl;
		return 0;
		cin.get();
	}
}

void imprimir_carton(int carton1[5][5], int encontrados[5][5]){
	for ( int i = 0; i < 5; i++){
		for ( int x = 0; x < 5; x++){
			if ( carton1[i][x] > 9 ){
				if( encontrados[i][x] == 1 ){
					cout << "xx" << " ";
				}
				else
				{
					cout << carton1[i][x] <<" ";	
				}
			}	
			else
			{
				if( encontrados[i][x] == 1 ){
					cout << "x" << "  ";
				}
				else
				{
					cout << carton1[i][x] <<"  ";	
				}
			}
		}
		cout << endl;
	}
}
void generar_numero(int numero2[25]){
	
	int numero = -1;
	
		numero = rand() % 25;
		
		while ( search_number(numero,numero2) ){
			numero = rand() % 25;	
		}
		numero2[contador] = numero;
		contador += 1;
}

void init_rand(){	
	srand(time(NULL));
}

void init_numeros(int numeros[25]){
	int i = 0;
	for ( i = 0; i < 25; i++){
		numeros[i] = -1;
	}
}

int search_number(int number,int vector[25]){
	int i = 0;
	for ( i = 0; i < 25; i++){
		if( number == vector[i] ){
			return 1;
		}
	}
	return 0;
}

void crear_carton(int carton[5][5],int numeros[25]){
	int i = 0;
	int x = 0;
	int maximo = 0;
	int esto_es_una_variable = 0; /// wow es una variable!
	
	for	( i = 0; i < 5; i++){
		for	( x = 0; x < 5; x++){
				esto_es_una_variable = rand() % 25; // del 25 pa bajo el random

				while( search_number( esto_es_una_variable,numeros) && maximo > 5 ){
					esto_es_una_variable = rand() % 25;
				}
				
				if(search_number( esto_es_una_variable,numeros)){
					maximo++;
				}
				numeros[i+x] = esto_es_una_variable;
				carton[i][x] = esto_es_una_variable;	
		}
	}
}

void init_encontrados(int encontados[5][5]){
	
	int i = 0;
	int x = 0;
	
	for	( i = 0; i < 5; i++){
		for	( x = 0; x < 5; x++){
			encontados[i][x] = 0;
		// 0 cuando no se encuentra
		// 1 para encontrado	
		}
	}
}
