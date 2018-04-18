//#ifndef LIFE_H
//#define LIFE_H

#include <iostream>
#include <vector>
#include <string>

using palavra = std::string;

/// Definição para quando uma célula estiver viva e/ou morta.
enum Cell{
	CELL_ALIVE = 1,
	CELL_DIED = 0
};

/// Classe que contém todos as configurações/propriedades de uma geração.
class Life {

	private:
		std::vector<std::vector<int>> grid;
		int rows;
		int cols;
		char characte;
        std::vector<int> id;

	public:
	
	/// Contrutor padrão, sem especificar o caractere utilizado.
	Life(int nLin, int nCol);

	/// Construtor informando as configurações básicas de uma geração.
	Life(int nLin, int nCol, char caract){
		this->rows = nLin;
		this->cols = nCol;
		this->characte = caract;
	}

	/// Desconstrutor.
	~Life();

	/// Sobrecarga do operador de atribuição, transformando uma geração em uma outra.
	Life & operator=(const Life& lf);

	/// Sobrecarga do operador de igualdade, em que verifica se 2 gerações são iguais.
	bool operator==(const Life& lf) const; 

	/// Adiciona células no vetor grid.
	/// \param vetor representando as linhas.
	void add_data_vector(std::vector<int> vetor);

	/// Imprime para o usuário como está a organização das células.
	/// \param valor da geração que está utilizando.
	void print_data_vector(int numero_geracao = 1);
	
	/// Retorna o valor encontrado em uma determinada posição.
	/// \param valor da linha.
	/// \param valor da coluna.
	/// \return valor encontrado na linha e coluna especificada.
	int get_value( int x, int y );
	
	/// Modificar valor em uma determinada posição.
	/// \param número da linha
	/// \param número da coluna
	/// \param valor desejado que seja inserido na posição informada.
	void set_value( int x, int y, int value );
	
	/// Obter o número de linhas.
	/// \return retornar o número de linhas na classe Life.
	int get_rows();
	
	/// Retorna a quantidade de colunas da classe Life.
	/// \return retornar o número de colunas da classe.
	int get_columns();
	
	/// Modificar a quantidade de linhas na classe (antes de gerar o vetor)
	/// \param quantidade de linhas desejadas.
	void set_rows(int row);
	
	/// Modificar a quantidade de colunas na classe.
	/// \param quantidade de colunas.
	void set_columns(int column);
	
	/// Obter qual foi o caractere utilizado pelo usuário no arquivo configuração.
	/// \return valor de char na classe para identificar uma célula viva.
	char get_caractere();
	
	/// Modificar o caractere.
	/// \param caractere desejado.
	void set_caractere(char carac);
	
	/// Verificar se alguma geração está extinta, ou seja, não possui nenhuma célula.
	/// \return retorno do estado da geração.
	bool is_extinct();
    
    void set_id();
    
    /// Salva os dados de cada geração em um arquivo de saída.
    /// \param nome do arquivo de saída desejado.
    void save_file(palavra filename);
    
    /// Realiza transformações para que a célula "continue" em outras bordas.
    void bordas();

};
//#endif
