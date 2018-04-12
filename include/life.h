#ifndef LIFE_H
#define LIFE_H

#include <iostream>

enum Cell{
	CELL_ALIVE = 1,
	CELL_DIED = 0
};
class Life
{
	private:
		int** grid;
		int rows;
		int columns;
		char caractere;

	public:

	Life(int nLin = 20, int nCol = 60){
		this->rows = nLin;
		this->columns = nCol;
	}

	Life( int nLin = 20, int nCol = 60, char caract = '*' ){
		this->rows = nLin;
		this->columns = nCol;
		this->caractere = caract;
	}

	//set_alive();
	//update();
	//print();
	//stable();
	//extinct();
	// sobrecarga de operadores

	// Métodos de recuperação de valores

	/// Retorna a quantidade de linhas da matriz
	int get_rows(){
		return this->rows;
	}

	void set_rows( int row ){
		this->rows = row;
	}

	/// Retorna a quantidade de colunas da matriz
	int get_columns(){
		return this->columns;
	}

	void set_columns( int col ){
		this->columns = col;
	}

	/// Retorna o caractere utilizado para identificar as celulas vivas
	char get_caractere(){
		return this->caractere;
	}

	void set_caractere( char carac ){
		this->caractere = carac;
	}
};
#endif
