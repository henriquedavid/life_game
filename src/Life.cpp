#include "../include/life.h"

/// Construtor da classe Life.
/// \param numeros de linhas, padrão é 20 linhas caso o usuário não informe
/// \param numeros de colunas, padrão é 60 colunas caso o usuário não informe
Life::Life(int nLin = 20, int nCol = 60)
{
	this->rows = nLin;
	this->rows = nCol;
	this->grid.resize(nLin, {{CELL_DIED}});
	for(int i = 0; i < nLin; ++i)
	{
		this->grid[i].resize(nCol, CELL_DIED);
		for(int j = 0; j < nCol; ++j)
		{
			this->grid[i][j] = CELL_DIED;
		}
	}

}

/// Desconstrutor da classe Life.
Life::~Life()
{
	this->grid.resize(0);
	for(int i = 0; i < this->rows; ++i)
		this->grid[i].resize(0);
}

/// Operador de atribuição da classe Life.
/// \param Classe Life.
Life & Life::operator=(const Life& lf) 
{
	this->rows = lf.rows;					    // !
	this->cols = lf.cols;					    // | iguala propriedades
	this->grid.resize(lf.rows);	 			    // altera quantidade de linhas
	for(int i = 0; i < lf.rows; ++i) 			// percorre cada linha
	{
		this->grid[i].resize(lf.cols);			// redimensiona linha
		for(int j = 0; j < lf.cols; ++j)		// percorred as colunas
		{
			this->grid[i][j] = lf.grid[i][j]; 	// realiza a atribuição
		}
	}	
	this->set_id();                             // seta Vetor de identidade
	return *this; 						        // permite atribuição em cascata 
	// TODO: traduzir comentarios
}

/// Operador de igualdade da classe life.
/// \param Classe Life.
bool Life::operator==(const Life& lf) const 
{
	int n = this->id[0];            // number of elements: number of distances + start_x + start_y + distance_1 + ... + distance_n
	for(int i = 0; i < n+3; ++i)         // if the sizes are different the loop will break at first time
	{
		if(this->id[i] != lf.id[i]) // different data
			return false;
	}
	return true;
}

void Life::set_id()
{
	int n = 0;
	int distance = 0;
	bool first_pos = true;
	this->id.reserve(3);

	for(int i = 0; i < this->rows; ++i)       // percorre cada linha    
	{ 			
		for(int j = 0; j < this->cols; ++j)   // percorre as colunas
		{
			if(grid[i][j] == CELL_ALIVE)
			{
				if(first_pos)              // aren't start_x and start_y stored?
				{
					this->id[1] = i;       // store start_x position
					this->id[2] = j;       // store start_y position
					first_pos = false;     // start_x and start_y stored
				}
				else                       // start coords are stored 
				{
					this->id.push_back(distance); // store new distance
					n++;                          // increase number of distances count
				}
				distance = 0;                     // reset distance
			}
			else
			{
				distance++; // increase distance count
			}
		}
	}
	this->id[0] = n;
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
	if(this->id[0] == 0)
		return true;
	return false;
}


/// Realiza transformações para que a célula "continue" em outras bordas.
void Life::bordas(){

	///Trata as diagonais.
	if( this->grid[0][0] == 1 ){
		this->grid[rows-2][cols-2] = 1;
	}

	if( this->grid[rows-1][cols-1] == 1 ){
		this->grid[1][1] = 1;
	}

	if( this->grid[rows-1][0] == 1 ){
		this->grid[1][cols-2] = 1;
	}

	if( this->grid[0][cols-1] == 1){
		this->grid[rows-2][1] = 1;
	}

	///  Trata os casos em que células passam a bordar, sem estar na diagonal.

	for(auto i(0); i < rows ; i++){
		if(i == 0){
			for(auto j(1) ; j < cols-2; j++){
				if( this->grid[i][j] == 1 )
					this->grid[rows-2][j] = 1;
			}

		}

		if( i == rows-1){
			for(auto j(1) ; j < cols-2; j++){
				if( this->grid[i][j] == 1 )
					this->grid[rows-2][j] = 1;
			}
		}
	}

	for(auto i(1); i < rows-2 ; i++){
		for(auto j(0) ; j < cols-1; j++){
			if( j == 0 ){
				if( this->grid[i][j] == 1 )
					this->grid[i][cols-2] = 1;
			}

			if( j == cols-1 ){
				if( this->grid[i][j] == 1 )
					this->grid[i][1] = 1;
			}
		}
	}
}