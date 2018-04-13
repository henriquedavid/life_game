#ifndef LIFE_H
#define LIFE_H

#include <iostream>
#include <vector>

enum Cell{
	CELL_ALIVE = 1,
	CELL_DIED = 0
};

class Life {
	private:
		std::vector<std::vector<int>> grid;
		int rows;
		int cols;
		//TODO: identidade da grade
	public:
	/// construtor
	Life(int nLin, int nCol);
	Life::~Life();
	///destructor
	/// sobrecarga do operador =
	Life & operator=(const Life& lf);
	bool operator==(const Life& lf) const; 
	//set_alive();	//update();
	/// imprimi a grade
	void print();
	//stable();
	//extinct
	// sobrecarga de operadores
	// Métodos de recuperação de valores
	/// Retorna a quantidade de linhas da matriz
	int get_rows(){
		return this->rows;
	}
	/// Retorna a quantidade de colunas da matriz
	int get_columns(){
		return this->cols;
	}
};
#endif
