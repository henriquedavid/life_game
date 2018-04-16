#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <string>

using palavra = std::string;
using arq_entrada = std::ifstream;

#include "../include/life.h"
#include "../include/inicial.h"

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

 	/// Chama o processo de leitura e inicio do life.	
 	initial(lf, arquivo);

	return 0;
}