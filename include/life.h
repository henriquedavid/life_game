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
		std::vector<std::vector<Cell>> grid;
		int rows;
		int cols;
        std::vector<int> id; // identity Vector - Formart [#n, start_x, start_y, distance_1, distance_2, ... , distance_n]
	public:
	/// construtor
	Life(int nLin, int nCol);
    ///destructor
	~Life();
	/// sobrecarga do operador =
	Life & operator=(const Life& lf);
    /// sobrecarga do operador ==
	bool operator==(const Life& lf) const;
	//set_alive();	
    //update();
    void set_id();
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
