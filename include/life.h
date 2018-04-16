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

	/// Adiciona as células no vetor.
	/// \param vetor representando as linhas.
	void add_data_vector(std::vector<int> vetor){
		grid.push_back(vetor);
	}

	/// Imprime para o usuário como está a organização das células.
	void print_data_vector(int numero_geracao = 1){
		std::cout << "Showing generation " << numero_geracao << ":\n";
		for( auto i(0) ; i < this->rows ; i++ ){
			std::cout << "[ ";
			for( auto j(0) ; j < this->cols ; j++ ){
				if( grid[i][j] == 1)
					std::cout << this->characte;
				else
					std::cout << " ";
			}
			std::cout << "]" <<std::endl;
		}
	}

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
