#ifndef HELPERS_H
#define HELPERS_H

using namespace std;

/* 

    AUTOR   : MARIO JOSUE GRIECO VULLAMIZAR
    CI      : 26205981
    PAIS    : VENEZUELA
    SEMESTRE: 01
    TODO    : RAMDON START
              PC PLAYER
    VERSION : 01 BETA

*/

void cls(){
	system("cls");
}
	
void defaultColor(){
	textbgcolor(WHITE,BLACK);
}

int getSwapColor(int option){
	if ( option == 1)
	{
		return 12;
	}
	else if ( option == 2 )
	{
		return 10;
	}
	else if ( option == 3 )
	{
		return 6;
	}
	else if ( option == 4 )
	{
		return 13;
	}
	else if ( option == 5 )
	{
		return 14;
	}
	else {
		return -1;
	}

}

void printM(int fyc,int **tablero,int desdeF,int desdeC,char a){
	for (int i = 0; i < fyc; i++)
	{
		int c = 0;

		for (int x = 0; x < (fyc*2); x+=2)
		{
			if ( 1 == 1 )
			{
				textcolor(WHITE);
				gotoxy(x+desdeC,i+desdeF);
				cout << a;
				defaultColor();
			}
			c++;
		}
	}
}
void printM(int fyc,int **tablero,int desdeF,int desdeC){
	for (int i = 0; i < fyc; i++)
	{
		int c = 0;

		for (int x = 0; x < (fyc*2); x+=2)
		{
			if ( 1 == 1 )
			{
				textcolor(WHITE);
				gotoxy(x+desdeC,i+desdeF);
				cout << tablero[i][c];
				defaultColor();
			}
			c++;
		}
	}
}

void printIN(int desdeF,int desdeC,int f,int c,char caracter,int color){
		gotoxy(desdeC+c,desdeF+f);
		textcolor(color);
		cout << caracter;
		defaultColor();
}

int buscarAbajoArribaLargo(int f,int c,int fyc,int **matriz){

	if( f-2 > -1){
		if ( matriz[f-2][c] == 3)
		{
			if ( matriz[f-1][c] == 2)
			{
				if ( matriz[f][c] == 3)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

int buscarArribaAbajoLargo(int f,int c,int fyc,int **matriz){

	if( f+2 < fyc){
		if ( matriz[f+2][c] == 3  )
		{
			if (matriz[f+1][c] == 2 )
			{
				if (matriz[f][c] == 3 )
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

int buscarIzqDereLargo(int f,int c,int fyc,int **matriz){

	if( c+2 < fyc){
		if ( matriz[f][c+2] == 3)
		{
			if (matriz[f][c+1] == 2 )
			{
				if (matriz[f][c] == 3 )
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

int buscarDereIzqLargo(int f,int c,int fyc,int **matriz){

	if( c-2 > -1){
		if ( matriz[f][c-2] == 3)
		{
			if (matriz[f][c-1] == 2 )
			{
				if (matriz[f][c] == 3 )
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

int izqDereMed(int f,int c,int fyc,int **matriz){

	if( c-1 > -1 && c+1 < fyc){
		if ( matriz[f][c-1] == 3)
		{
			if (matriz[f][c] == 2 )
			{
				if (matriz[f][c+1] == 3 )
				{
					return 1;
				}
			}
		}
	}
	return 0;

}

int ArribaAbajoMed(int f,int c,int fyc,int **matriz){

		if( f-1 > -1 && f+1 < fyc){
		if ( matriz[f-1][c] == 3)
		{
			if (matriz[f][c] == 2 )
			{
				if (matriz[f+1][c] == 3 )
				{
					return 1;
				}
			}
		}
	}
	return 0;
	
}

int diagonalPositivaAbajoArriba(int f,int c,int fyc,int **matriz){

		if( f+2 < fyc && c+2 < fyc){
		if ( matriz[f+2][c+2] == 3)
		{
			if (matriz[f+1][c+1] == 2 )
			{
				if (matriz[f][c] == 3 )
				{
					return 1;
				}
			}
		}
	}
	return 0;
	
}

int diagonalPositivaArribaAbajo(int f,int c,int fyc,int **matriz){

		if( f-2 > -1 && c-2 > -1 ){
		if ( matriz[f-2][c-2] == 3)
		{
			if (matriz[f-1][c-1] == 2 )
			{
				if (matriz[f][c] == 3 )
				{
					return 1;
				}
			}
		}
	}
	return 0;
	
}

int DiagonalNegativaAbajoArriba(int f,int c,int fyc,int **matriz){

		if( f+2 < fyc && c-2 > -1){
		if ( matriz[f+2][c-2] == 3)
		{
			if (matriz[f+1][c-1] == 2 )
			{
				if (matriz[f][c] == 3 )
				{
					return 1;
				}
			}
		}
	}
	return 0;
	
}

int DiagonalNegativaArribaAbajo(int f,int c,int fyc,int **matriz){

		if( c+2 < fyc && f-2 > -1){
		if ( matriz[f-2][c+2] == 3)
		{
			if (matriz[f-1][c+1] == 2 )
			{
				if (matriz[f][c] == 3 )
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

int IntermedioPositivo(int f,int c,int fyc,int **matriz){

		if( c+1 < fyc && c-1 > -1 && f-1 > -1 && f+1 < fyc ){
		if ( matriz[f-1][c-1] == 3)
		{
			if (matriz[f][c] == 2 )
			{
				if (matriz[f+1][c+1] == 3 )
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

int IntermedioNegativo(int f,int c,int fyc,int **matriz){

		if( c+1 < fyc && c-1 > -1 && f-1 > -1 && f+1 < fyc ){
		 if ( matriz[f-1][c+1] == 3)
		 {
			if (matriz[f][c] == 2 )
			{
				if (matriz[f+1][c-1] == 3 )
				{
					return 1;
				}
			}
		 }
		}
		return 0;
}


#endif