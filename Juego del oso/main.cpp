#include "myconio.h"

#include "stdlib.h"
#include "iostream"
#include "helpers.h"
/* 

    AUTOR   : MARIO JOSUE GRIECO VULLAMIZAR
    CI      : 26205981
    PAIS    : VENEZUELA
    SEMESTRE: 01
    TODO    : RAMDON START
              PC PLAYER
    VERSION : 01 BETA

*/

int validator = 0;
/*swap y buffer*/
int opcion;
char swap1[20];
char gameloopvar;

/*nombres*/
char juegador1[20];
char juegador2[20];
/* colores*/
int cp2;
int cp1;

/* tablero */
int **tablero;
/* filas y columnas */
int fyc;

/* PARA VERIFICAR TIPO EN MATRIZ*/
int playersCords[2] = {0,0};
int turno = 1;

/* origen del sistema*/
int desdef = 2;
int desdec = 0;

/* PARA IMPRIMIR CARACTER*/
int f = 0;
int c = 0;
using namespace std;

/* contadores */
	int puntaje1;
	int puntaje2;

int main(int argc, char const *argv[])
{
	defaultColor();
	cls();
	cout <<     
		"AUTOR   : MARIO JOSUE GRIECO VULLAMIZAR\nCI      : 26205981\nPAIS    : VENEZUELA\nSEMESTRE: 01\nTODO    : RAMDON START\n        PC PLAYER\nVERSION : 01 BETA\n" << endl;

	cout << "EL JUEGO DE LOL" << endl;
	textcolor(12);
	cout << "instrucciones: debes ingresar tu nombre elejir un color para cada jugador\n Despues las dimenaciones del tablero y \nse debe ingresar por turno en teclado l u o para formar\n la palabra lol\n cada una sera un punto\n el q tenga mas puntos gana!\n" << endl;
	defaultColor();
	cout << "Ingresa nombre del juegador 1: ";
	cin.getline(swap1,19);
	strcpy(juegador1,swap1);
	cout << " Ingresa tu color de caracter " <<  juegador1 <<"\n ";
	textcolor(12);
	cout << "1.- Para esto\n";
	textcolor(10);
	cout << " 2.- Para esto\n";
	textcolor(6);
	cout << " 3.- Para esto\n";
	textcolor(13);
	cout << " 4.- Para esto\n";
	textcolor(14);
	cout << " 5.- Para esto\n";
	defaultColor();
	cout << "opcion: ";
	cin >> opcion;

	opcion = getSwapColor(opcion);
	while( opcion == -1 || opcion == 1 || opcion == 2 || opcion == 3|| opcion == 4 || opcion == 5 ){
		cout << "Ingresa un color valido!!"<< endl;
		cout << "Ingresa tu color de caracter:\n";
		textcolor(12);
		cout << "1.- Para esto\n";
		textcolor(10);
		cout << " 2.- Para esto\n";
		textcolor(6);
		cout << " 3.- Para esto\n";
		textcolor(13);
		cout << " 4.- Para esto\n";
		textcolor(14);
		cout << " 5.- Para esto\n";
		defaultColor();
		cin >> opcion;
		cout << "opcion: ";
		opcion = getSwapColor(opcion);

	}
	cp1 = opcion;
	fflush(stdin);
	fflush(stdout);
	cout << "Ingresa nombre del juegador 2: ";
	fflush(stdin);
	fflush(stdout);
	cin.getline(swap1,19);
	while ( strcmp(swap1,juegador1) == 0 ){
		cout << "EL NOMBRE DEBE SER DIFERENTE! " << endl;
		cout << "Ingresa nombre para el juegador2: ";
		cin.getline(swap1,19);
	}
	strcpy(juegador2,swap1);
		cout << " Ingresa tu color de caracter " <<  juegador2 <<"\n";
	textcolor(12);
	cout << " 1.- Para esto\n";
	textcolor(10);
	cout << " 2.- Para esto\n";
	textcolor(6);
	cout << " 3.- Para esto\n";
	textcolor(13);
	cout << " 4.- Para esto\n";
	textcolor(14);
	cout << " 5.- Para esto\n";
	defaultColor();
	cout << "opcion: ";
	cin >> opcion;

	opcion = getSwapColor(opcion);
	while( opcion == -1 || opcion == 1 || opcion == 2 || opcion == 3|| opcion == 4 || opcion == 5 || opcion == cp1){
		cout << "Ingresa un color valido!!"<< endl;
		if ( opcion == cp1 )
		{
			cout << "ese es el color del player1! " << endl;
		}
		cout << " Ingresa tu color de caracter: \n ";
		textcolor(12);
		cout << " 1.- Para esto\n";
		textcolor(10);
		cout << " 2.- Para esto\n";
		textcolor(6);
		cout << " 3.- Para esto\n";
		textcolor(13);
		cout << " 4.- Para esto\n";
		textcolor(14);
		cout << " 5.- Para esto\n";
		defaultColor();
		cout << "opcion: ";
		cin >> opcion;

		opcion = getSwapColor(opcion);

	}
	cp2 = opcion;


	cout << "Ingresa el tamano del tablero de juego!: min2 max 50: ";
	cin >> opcion;

	while ( opcion < 2 || opcion > 50 ){
		cout << "Ingresa un rago valido!\nIngresa el tamano del tablero de juego!: ";
		cin >> opcion;
	}
	fyc = opcion;
	tablero = new int*[fyc];
	for (int i = 0; i < fyc; ++i)
	{
		tablero[i] = new int[fyc];
	}

	for (int i = 0; i < fyc; ++i)
	{
		for (int x = 0; x < fyc; ++x)
		{
			tablero[i][x] = 0;
		}
	}

	cls();

	printM(fyc,tablero,desdef,desdec,'-');
	if ( turno == 1 )
	{
		printIN(desdef,desdec,f,c,'X',cp1);
	}
	else if ( turno == 2)
	{
		printIN(desdef,desdec,f,c,'X',cp2);
	}
	while( 1 == 1 ){
	if ( turno == 1 )
	{
		gotoxy(0,0);
		cout << "------------------------------------------------------------------------------------" << endl;
		gotoxy(0,0);
		cout << juegador1 << " es tu turno elige entre 'L' y 'O' ingresa el caracter desde el teclado ..." << endl;
		cout << "tu puntaje actual es: " << puntaje1 << endl;
	}
	else if ( turno == 2)
	{
		gotoxy(0,0);
		cout << "------------------------------------------------------------------------------------" << endl;
		gotoxy(0,0);
		cout << juegador2 << " es tu turno elige entre 'L' y 'O' ingresa el caracter desde el teclado ..." << endl;
		cout << "tu puntaje actual es: " << puntaje2 << endl;
	}
		
		if ( diagonalPositivaAbajoArriba(playersCords[0],playersCords[1],fyc,tablero) )
		{
			if ( turno ==  2 )
			{
				puntaje1++;
				printIN(desdef,desdec,f+2,c+4,'L',cp1);
				printIN(desdef,desdec,f+1,c+2,'O',cp1);
				printIN(desdef,desdec,f,c,'L',cp1);
			}
			else if ( turno == 1 )
			{
				puntaje2++;
				printIN(desdef,desdec,f+2,c+4,'L',cp2);
				printIN(desdef,desdec,f+1,c+2,'O',cp2);
				printIN(desdef,desdec,f,c,'L',cp2);
			}
		}
		if ( IntermedioNegativo(playersCords[0],playersCords[1],fyc,tablero) )
		{
			if ( turno ==  2 )
			{
				puntaje1++;
				printIN(desdef,desdec,f-1,c+2,'L',cp1);
				printIN(desdef,desdec,f+1,c-2,'L',cp1);
				printIN(desdef,desdec,f,c,'O',cp1);
			}
			else if ( turno == 1 )
			{
				puntaje2++;
				printIN(desdef,desdec,f-1,c+2,'L',cp2);
				printIN(desdef,desdec,f+1,c-2,'L',cp2);
				printIN(desdef,desdec,f,c,'O',cp2);
			}
		}
		if ( IntermedioPositivo(playersCords[0],playersCords[1],fyc,tablero) )
		{
			if ( turno ==  2 )
			{
				puntaje1++;
				printIN(desdef,desdec,f+1,c+2,'L',cp1);
				printIN(desdef,desdec,f,c,'O',cp1);
				printIN(desdef,desdec,f-1,c-2,'L',cp1);
			}
			else if ( turno == 1 )
			{
				puntaje2++;
				printIN(desdef,desdec,f+1,c+2,'L',cp2);
				printIN(desdef,desdec,f,c,'O',cp2);
				printIN(desdef,desdec,f-1,c-2,'L',cp2);
			}
		}
		if ( DiagonalNegativaAbajoArriba(playersCords[0],playersCords[1],fyc,tablero) )
		{
			if ( turno ==  2 )
			{
				puntaje1++;
				printIN(desdef,desdec,f+2,c-4,'L',cp1);
				printIN(desdef,desdec,f+1,c-2,'O',cp1);
				printIN(desdef,desdec,f,c,'L',cp1);
			}
			else if ( turno == 1 )
			{
				puntaje2++;
				printIN(desdef,desdec,f+2,c-4,'L',cp2);
				printIN(desdef,desdec,f+1,c-2,'O',cp2);
				printIN(desdef,desdec,f,c,'L',cp2);
			}
		}
		if ( DiagonalNegativaArribaAbajo(playersCords[0],playersCords[1],fyc,tablero) )
		{
			if ( turno ==  2 )
			{
				puntaje1++;
				printIN(desdef,desdec,f-2,c+4,'L',cp1);
				printIN(desdef,desdec,f-1,c+2,'O',cp1);
				printIN(desdef,desdec,f,c,'L',cp1);
			}
			else if ( turno == 1 )
			{
				puntaje2++;
				printIN(desdef,desdec,f-2,c+4,'L',cp1);
				printIN(desdef,desdec,f-1,c+2,'O',cp1);
				printIN(desdef,desdec,f,c,'L',cp1);
			}
		}
		if ( diagonalPositivaArribaAbajo(playersCords[0],playersCords[1],fyc,tablero) )
		{
			if ( turno ==  2 )
			{
				puntaje1++;
				printIN(desdef,desdec,f-2,c-4,'L',cp1);
				printIN(desdef,desdec,f-1,c-2,'O',cp1);
				printIN(desdef,desdec,f,c,'L',cp1);
			}
			else if ( turno == 1 )
			{
				puntaje2++;
				printIN(desdef,desdec,f-2,c-4,'L',cp2);
				printIN(desdef,desdec,f-1,c-2,'O',cp2);
				printIN(desdef,desdec,f,c,'L',cp2);
			}
		}

		if ( buscarAbajoArribaLargo(playersCords[0],playersCords[1],fyc,tablero) )
		{
			if ( turno ==  2 )
			{
				puntaje1++;
				printIN(desdef,desdec,f-2,c,'L',cp1);
				printIN(desdef,desdec,f-1,c,'O',cp1);
				printIN(desdef,desdec,f,c,'L',cp1);
			}
			else if ( turno == 1 )
			{
				puntaje2++;
				printIN(desdef,desdec,f-2,c,'L',cp2);
				printIN(desdef,desdec,f-1,c,'O',cp2);
				printIN(desdef,desdec,f,c,'L',cp2);
			}
		}
		if ( buscarArribaAbajoLargo(playersCords[0],playersCords[1],fyc,tablero) )
		{
			if ( turno ==  2 )
			{
				puntaje1++;
				printIN(desdef,desdec,f+2,c,'L',cp1);
				printIN(desdef,desdec,f+1,c,'O',cp1);
				printIN(desdef,desdec,f,c,'L',cp1);
			}
			else if ( turno == 1 )
			{
				puntaje2++;
				printIN(desdef,desdec,f+2,c,'L',cp2);
				printIN(desdef,desdec,f+1,c,'O',cp2);
				printIN(desdef,desdec,f,c,'L',cp2);
			}
		}
		if ( buscarIzqDereLargo(playersCords[0],playersCords[1],fyc,tablero) )
		{
			if ( turno ==  2 )
			{
				puntaje1++;
				printIN(desdef,desdec,f,c+4,'L',cp1);
				printIN(desdef,desdec,f,c+2,'O',cp1);
				printIN(desdef,desdec,f,c,'L',cp1);
			}
			else if ( turno == 1 )
			{
				puntaje2++;
				printIN(desdef,desdec,f,c+4,'L',cp2);
				printIN(desdef,desdec,f,c+2,'O',cp2);
				printIN(desdef,desdec,f,c,'L',cp2);
			}
		}

		if ( buscarDereIzqLargo(playersCords[0],playersCords[1],fyc,tablero) )
		{
			if ( turno ==  2 )
			{
				puntaje1++;
				printIN(desdef,desdec,f,c-4,'L',cp1);
				printIN(desdef,desdec,f,c-2,'O',cp1);
				printIN(desdef,desdec,f,c,'L',cp1);
			}
			else if ( turno == 1 )
			{
				puntaje2++;
				printIN(desdef,desdec,f,c-4,'L',cp2);
				printIN(desdef,desdec,f,c-2,'O',cp2);
				printIN(desdef,desdec,f,c,'L',cp2);
			}
		}
		if ( ArribaAbajoMed(playersCords[0],playersCords[1],fyc,tablero) )
		{
			if ( turno ==  2 )
			{
				puntaje1++;
				printIN(desdef,desdec,f+1,c,'L',cp1);
				printIN(desdef,desdec,f,c,'O',cp1);
				printIN(desdef,desdec,f-1,c,'L',cp1);
			}
			else if ( turno == 1 )
			{
				puntaje2++;
				printIN(desdef,desdec,f+1,c,'L',cp2);
				printIN(desdef,desdec,f,c,'O',cp2);
				printIN(desdef,desdec,f-1,c,'L',cp2);
			}
		}

		if ( izqDereMed(playersCords[0],playersCords[1],fyc,tablero) )
		{
			if ( turno ==  2 )
			{
				puntaje1++;
				printIN(desdef,desdec,f,c+2,'L',cp1);
				printIN(desdef,desdec,f,c,'O',cp1);
				printIN(desdef,desdec,f,c-2,'L',cp1);
			}
			else if ( turno == 1 )
			{
				puntaje2++;
				printIN(desdef,desdec,f,c+2,'L',cp2);
				printIN(desdef,desdec,f,c,'O',cp2);
				printIN(desdef,desdec,f,c-2,'L',cp2);
			}
		}

		gameloopvar = getch(); 
		

		if ( gameloopvar == 'q' )
		{
				cin.get();
				return 0;
		}
		else if ( gameloopvar == 'd' )
		{
			validator = 1;
			while ( playersCords[1]+validator < fyc ){
				if (tablero[playersCords[0]][playersCords[1]+validator] == 0)
				{
					break;
				}
				validator++;
			}
			if ( playersCords[1]+validator < fyc)
			{
				if ( tablero[playersCords[0]][playersCords[1]] == 0 )
				{
					printIN(desdef,desdec,f,c,'-',WHITE);
				}
				playersCords[1]+= validator;
				c += 2*validator;
				if ( turno == 1){
					printIN(desdef,desdec,f,c,'X',cp1);
				}
				else if ( turno == 2){
					printIN(desdef,desdec,f,c,'X',cp2);
				}
    		}	
		}
		else if ( gameloopvar == 'a' )
		{
			validator = 1;
			while ( playersCords[1]-validator > -1 ){
				if (tablero[playersCords[0]][playersCords[1]-validator] == 0)
				{
					break;
				}
				validator++;
			}
			if ( playersCords[1]-validator > -1 && tablero[playersCords[0]][playersCords[1]-validator] == 0)
			{
				if ( tablero[playersCords[0]][playersCords[1]] == 0)
				{
					printIN(desdef,desdec,f,c,'-',WHITE);
				}
				playersCords[1] -= validator;
				c -= 2*validator;
				if ( turno == 1){
					printIN(desdef,desdec,f,c,'X',cp1);
				}
				else if ( turno == 2){
					printIN(desdef,desdec,f,c,'X',cp2);
				}
				
			}	
		}
		else if ( gameloopvar == 'w' )
		{
			validator = 1;
			while ( playersCords[0]-validator > -1 ){
				if (tablero[playersCords[0]-validator][playersCords[1]] == 0)
				{
					break;
				}
				validator++;
			}
			if ( playersCords[0]-validator > -1 && tablero[playersCords[0]-validator][playersCords[1]] == 0)
			{
				if ( tablero[playersCords[0]][playersCords[1]] == 0)
				{
					printIN(desdef,desdec,f,c,'-',WHITE);
				}
				playersCords[0]-= validator;
				f -= validator;
				if ( turno == 1){
					printIN(desdef,desdec,f,c,'X',cp1);
				}
				else if ( turno == 2){
					printIN(desdef,desdec,f,c,'X',cp2);
				}
			}	
		}
		else if ( gameloopvar == 's' )
		{
			validator = 1;
			while ( playersCords[0]+validator < fyc ){
				if (tablero[playersCords[0]+validator][playersCords[1]] == 0)
				{
					break;
				}
				validator++;
			}
			if ( playersCords[0]+validator < fyc && tablero[playersCords[0]+validator][playersCords[1]] == 0)
			{
				if ( tablero[playersCords[0]][playersCords[1]] == 0)
				{
					printIN(desdef,desdec,f,c,'-',WHITE);
				}
				playersCords[0]+= validator;
				f += validator;
				if ( turno == 1){
					printIN(desdef,desdec,f,c,'X',cp1);
				}
				else if ( turno == 2){
					printIN(desdef,desdec,f,c,'X',cp2);
				}
			}	
		}
		else if ( gameloopvar == 'o' )
		{
			if ( tablero[playersCords[0]][playersCords[1]] == 0 )
			{
				if ( turno == 1)
				{
					tablero[playersCords[0]][playersCords[1]] = 2;
					printIN(desdef,desdec,f,c,'O',cp1);
					turno = 2;
				}
				else if (turno == 2)
				{
					tablero[playersCords[0]][playersCords[1]] = 2;
					printIN(desdef,desdec,f,c,'O',cp2);
					turno = 1;
				}
			}
		}
		else if ( gameloopvar == 'l' )
		{
			if ( tablero[playersCords[0]][playersCords[1]] == 0 )
			{
				if ( turno == 1)
				{
					tablero[playersCords[0]][playersCords[1]] = 3;
					printIN(desdef,desdec,f,c,'L',cp1);
					turno = 2;
				}
				else if (turno == 2)
				{
					tablero[playersCords[0]][playersCords[1]] = 3;
					printIN(desdef,desdec,f,c,'L',cp2);
					turno = 1;
				}
			}
		}

	}
}

