#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <string>
#include <iterator>
#include <vector>

using palavra = std::string;
using arq_entrada = std::ifstream;

#include "../include/life.h"
#include "../include/warehouse.h"
#include "../include/readFile.h"
#include "../include/extension.h"

#include "../include/inicial.h"

//#include <istream>

int main( int argc, char * argv[] ){
	
	std::string arquivo;

	/// Verifica se quantidade de argumentos.
	if(argc != 2){
		std::cout << "Wrong syntaxe!\n"
				  << "Use: life <input_cfg_file> [<output_cfg_evolution_file>]" << std::endl;
		return 0;
	}

	/// O segundo argumento é arquivo.
	arquivo = argv[1];

	/// Inicializa o objeto com a configuração padrão.
 	Life lf(20, 60, '-');
 	Warehouse ware;

 	/// Chama o processo de leitura e inicio do life.	
 	initial(lf, arquivo);

	lf.print_data_vector();

	while( print_continue(lf, ware) ){
		update(lf, ware);
		lf.print_data_vector();
		//verifica_estavel();
		//verifica_extinta();
	}

	return 0;
}