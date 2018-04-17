#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <string>
#include <iterator>
#include <vector>

using palavra = std::string;
using arq_entrada = std::ifstream;
using arq_saida = std::ofstream;
#include "../include/life.h"
#include "../include/warehouse.h"
#include "../include/readFile.h"
#include "../include/extension.h"

#include "../include/inicial.h"

//#include <istream>

int main( int argc, char * argv[] ){
	
	std::string arquivo;
    std::string arquivo_saida;
	/// Verifica se quantidade de argumentos.
	if(argc < 2){
		std::cout << "Wrong syntaxe!\n"
				  << "Use: life <input_cfg_file> [<output_cfg_evolution_file>]" << std::endl;
		return 0;
	}

	/// O segundo argumento é arquivo.
	arquivo = argv[1];
    if(argc == 3)
    {
        arquivo_saida = argv[2];
    }
	/// Inicializa o objeto com a configuração padrão.
 	Life lf(20, 60, '-');
 	Warehouse ware;	

 	/// Chama o processo de leitura e inicio do life.	
 	initial(lf, arquivo);

	lf.print_data_vector();

	while( print_continue(lf, ware) ){
		update(lf, ware);
		lf.print_data_vector(ware.get_size()+1);
		//verifica_estavel();
        
		if(lf.is_extinct()){
           std::cout << ">>> All Cells are extinct. Exiting...\n";
           return 0;
        }
	}
	if(argc == 3)
        save_file(ware, arquivo_saida);
	return 0;
}
