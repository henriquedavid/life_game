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
        std::vector<int> id;
	public:
	/// construtor
	Life(int nLin, int nCol);
	Life(int nLin, int nCol, char caract){
		this->rows = nLin;
		this->cols = nCol;
		this->characte = caract;
	}
	~Life();
	///destructor
	/// sobrecarga do operador =
	Life & operator=(const Life& lf);
	bool operator==(const Life& lf) const; 
	//set_alive();	//update();
	/// imprimi a grade
	//stable();
	//extinct
	// sobrecarga de operadores
	// Métodos de recuperação de valores
	/// Retorna a quantidade de linhas da matriz

	/// Adiciona as células no vetor.
	/// \param vetor representando as linhas.
	void add_data_vector(std::vector<int> vetor);

	/// Imprime para o usuário como está a organização das células.
	void print_data_vector(int numero_geracao = 1);
	int get_value( int x, int y );
	void set_value( int x, int y, int value );
	int get_rows();
	/// Retorna a quantidade de colunas da matriz
	int get_columns();
	void set_rows(int row);
	void set_columns(int column);
	char get_caractere();
	void set_caractere(char carac);
	bool is_extinct();
    void set_id();
    void save_file(std::string filename);
};
#endif
