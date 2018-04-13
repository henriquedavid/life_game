#include "life.h"

Life::Life(int nLin = 20, int nCol = 60)
{
	this->rows = nLin;
	this->rows = nCol;
	this->grid.resize(nLin, {{0}});
	for(int i = 0; i < nLin; ++i)
	{
		this->grid[i].resize(nCol, 0);
		for(int j = 0; j < nCol; ++j)
		{
			this->grid[i][j] = 0;
		}
	}

}
Life::~Life(){
	this->grid.resize(0);
	for(int i = 0; i < this->rows; ++i)
		this->grid[i].resize(0);
}
//set_alive();
//update();
void Life::print(){
	for(int i = 0; i < this->rows; ++i){
		for(int j = 0; j < this->cols; ++j){
			if(this->grid[i][j] == CELL_ALIVE)
				std::cout << '*';
			else
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
}
//stable();
//extinct();
Life & Life::operator=(const Life& lf) {
	this->rows = lf.rows;					// !
	this->cols = lf.cols;					// iguila propriedades
	// TODO: igualar a identidade
	this->grid.resize(lf.rows);	 			// altera quantidade de linhas
	for(int i = 0; i < lf.rows; ++i){ 			// percorre cada linha
		this->grid[i].resize(lf.cols);			// redimensiona linha
		for(int j = 0; j < lf.cols; ++j){		// percorres as colunas
			this->grid[i][j] = lf.grid[i][j]; 	// realiza a atribuição
		}
	}	
	return *this; 						// permite atribuição em cascata 
}
/// sobrecarga do operador ==
bool Life::operator==(const Life& lf) const {
	if(lf==lf) // warning chato
	// TODO: usar comparação por hashing ou algo similar 
	return true;
}

