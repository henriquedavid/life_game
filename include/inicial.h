#include "readFile.h"

/// Inicialização do sistema
/*
void initial( Life &ls, palavra nameFile ){
	
	std::cout << ">>> Trying to open input file [data/cfg1.dat]... ";

	arq_entrada iFile;

	/// Abre o arquivo.
	iFile.open("../data/cfg1.dat");

	/// Verifica se o arquivo foi aberto.
	if( !iFile.is_open() ){

		std::cout << "error!\nTry again!" << std::endl;
		return;

	} else{

		std::cout << "done!" << std::endl;

		std::cout << ">>> Processing data, please wait..." << std::endl;
		
		/// Lê e configura a classe Life para ficar como no arquivo configuração.
		readConfig(ls, iFile);


		std::cout << ">>> Grid size read from input file: " << ls.get_rows() << " rows by " << ls.get_columns() << " cols." << std::endl;
		std::cout << ">>> Character that represents a living cell read from input file: '" << ls.get_caractere() << "'\n" << std::endl;

		/// Breve descrição sobre o jogo
		std::cout << std::setw(80) << std::setfill('*') << " " << std::endl;
		std::cout << "Welcome to Conways game of Life.\n" 
					  << "By default this game uses a grid of size 20 by 60 in which\n"
					  << "each cell can either be occupied by an organism or not.\n"
					  << "The occupied cells change from generation to generation\n"
					  << "according to the number of neighboring cells which are alive." << std::endl;
		std::cout << std::setw(80) << std::setfill('*') << " " << std::endl;

	}

	/// Fecha o arquivo.
	iFile.close();

}
int main(){

	Life lf( 20, 60, '-');

	initial(lf, "TESTE");

	return 0;
}
*/
