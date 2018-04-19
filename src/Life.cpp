#include "../include/life.h"

/// Construtor da classe Life.
/// \param numeros de linhas, padrão é 20 linhas caso o usuário não informe
/// \param numeros de colunas, padrão é 60 colunas caso o usuário não informe
Life::Life(int nLin = 20, int nCol = 60)
{
	this->rows = nLin;
	this->rows = nCol;
	this->grid.resize(nLin+2, {{CELL_DIED}}); // aloca linhas com valor padrao
	for(int i = 0; i < nLin+2; ++i) // percorre linhas
	{
		this->grid[i].resize(nCol+2, CELL_DIED); // aloca colunas da linha com valor padrao
	}

}

Life::Life(int nLin, int nCol, char caract){
	this->rows = nLin;
	this->cols = nCol;
	this->characte = caract;
}

/// Desconstrutor da classe Life.
Life::~Life()
{
	for(int i = 0; i < this->rows; ++i)
		this->grid[i].resize(0);
	this->grid.resize(0);
}

/// Operador de atribuição da classe Life.
/// \param Classe Life.
Life & Life::operator=(const Life& lf) 
{
	this->rows = lf.rows;					    // !
	this->cols = lf.cols;					    // | iguala propriedades
	this->grid.resize(lf.rows+2);	 			    // altera quantidade de linhas
	for(int i = 0; i < lf.rows+2; ++i) 			// percorre cada linha
	{
		this->grid[i].resize(lf.cols+2);			// redimensiona linha
		for(int j = 0; j < lf.cols+2; ++j)		// percorred as colunas
		{
			this->grid[i][j] = lf.grid[i][j]; 	// realiza a atribuição
		}
	}	                            		// seta Vetor de identidade
	return *this; 						        // permite atribuição em cascata 
	// TODO: traduzir comentarios
}

/// Adiciona dados ao vetor da classe Grid na classe Life.
void Life::add_data_vector(std::vector<int> vetor){
	grid.push_back(vetor);
}

/// Imprime para o usuário como está a organização das células.
void Life::print_data_vector(int numero_geracao){
	std::cout << "Showing generation " << numero_geracao << ":\n";
	for( auto i(1) ; i < this->rows+1 ; i++ ){
		std::cout << "[ ";
		for( auto j(1) ; j < this->cols+1 ; j++ ){
			if( grid[i][j] == 1)
				std::cout << this->characte;
			else
				std::cout << " ";
		}
		std::cout << "]" <<std::endl;
	}
}

/// Retorna o valor em uma determinada posição em [linha] e [coluna].
/// \param número da linha.
/// \param número da coluna.
/// \return valor na posição informada.
int Life::get_value( int x, int y ){
	return this->grid[x][y];
}

/// Modificar valor em uma determinada posição.
/// \param número da linha
/// \param número da coluna
/// \param valor desejado que seja inserido na posição informada.
void Life::set_value( int x, int y, int value ){
	this->grid[x][y] = value;
}

/// Obter o número de linhas.
/// \return retornar o número de linhas na classe Life.
int Life::get_rows(){
	return this->rows;
}
/// Retorna a quantidade de colunas da classe Life.
/// \return retornar o número de colunas da classe.
int Life::get_columns(){
	return this->cols;
}

/// Modificar a quantidade de linhas na classe (antes de gerar o vetor)
/// \param quantidade de linhas desejadas.
void Life::set_rows(int row){
	this->rows = row;
}

/// Modificar a quantidade de colunas na classe.
/// \param quantidade de colunas.
void Life::set_columns(int column){
	this->cols = column;
}

/// Obter qual foi o caractere utilizado pelo usuário no arquivo configuração.
/// \return valor de char na classe para identificar uma célula viva.
char Life::get_caractere(){
	return this->characte;
}

/// Modificar o caractere.
/// \param caractere desejado.
void Life::set_caractere(char carac){
	this->characte = carac;
}

/// Verificar se alguma geração está extinta.
/// \return retorno do estado da geração.
bool Life::is_extinct(){
	for( auto i(1) ; i < this->rows+1 ; i++ ){
		for( auto j(1) ; j < this->cols+1 ; j++ ){
			if(this->grid[i][j] == CELL_ALIVE)
				return false;
		}
	}
	return true;
}

/// Transfere os valores dos limites da grid para a borda.
void Life::bordas()
{
    int rows = this->rows;
    int cols = this->cols;
	///Trata as diagonais.
    set_value(rows, cols, this->grid[0][0]);
    set_value(1, 1, this->grid[rows+1][cols+1]);
    set_value(1, cols, this->grid[rows+1][0]);
    set_value(rows, 1, this->grid[0][cols+1]);
	///  Borda esquerda
	for(auto i(1); i <= rows; i++)
            set_value(i, cols, this->grid[i][0]);
    //  Borda direita
	for(auto i(1); i <= rows ; i++){
            set_value(i, 1, this->grid[i][cols+1]);
    }
    ///  Borda superior
	for(auto j(1); j <= cols ; j++)
            set_value(rows, j, this->grid[0][j]);
    ///  Borda superior
	for(auto j(1); j <= cols ; j++)
            set_value(1, j, this->grid[rows+1][j]);
}
/// Transfere valores dos limites da grid para a borda.
void Life::load_bordas()
{
    int rows = this->rows;
    int cols = this->cols;
	/// Trata as diagonais.
    set_value(rows+1, cols+1, this->grid[1][1]);
    set_value(0, 0, this->grid[rows][cols]);
    set_value(0, cols+1, this->grid[rows][1]);
    set_value(rows+1, 0, this->grid[1][cols]);
	///  Borda esquerda recebe lado direito
	for(auto i(1); i <= rows; i++)
            set_value(i, 0, this->grid[i][cols]);
    //  Borda direita recebe lado esquerdo
	for(auto i(1); i <= rows ; i++){
            set_value(i, cols+1, this->grid[i][1]);
    }
    ///  Borda inferior recebe lado superior
	for(auto j(1); j <= cols ; j++)
            set_value(rows+1, j, this->grid[1][j]);
    ///  Borda superior recebe lado inferior
	for(auto j(1); j <= cols ; j++)
            set_value(0, j, this->grid[rows][j]);
}
