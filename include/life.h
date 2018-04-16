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
		char characte;
		//TODO: identidade da grade
	public:
	/// construtor
	Life(int nLin, int nCol);
	Life(int nLin, int nCol, char caract){
		this->rows = nLin;
		this->cols = nCol;
		this->characte = caract;
	}
	//~Life();
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

	void set_rows(int row){
		this->rows = row;
	}

	void set_columns(int column){
		this->cols = column;
	}

	char get_caractere(){
		return this->characte;
	}

	void set_caractere(char carac){
		this->characte = carac;
	}
};
#endif
