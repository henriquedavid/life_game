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

#include "../include/inicial.h"
#include "../include/extension.h"

int main( int argc, char * argv[] ){

	palavra arquivo;		// arquivo de entrada.
	palavra arquivo_saida;

	/// Verifica se quantidade de argumentos.
	if(argc < 2){
		std::cout << "Wrong syntaxe!\n"
			<< "Use: life <input_cfg_file> [<output_cfg_evolution_file>]" << std::endl;
		return 0;
	}

	/// O segundo argumento é arquivo.
	arquivo = argv[1];

	// Se houver terceiro argumento então o usuário quer os dados no arquivo de saída.
	if(argc == 3)
	{
		arquivo_saida = argv[2];
	}

	/// Inicializa o objeto com a configuração padrão.
	Life lf(20, 60, '-');
	Warehouse ware;	

	// Chama o processo de leitura e inicio do life.	
	initial(lf, arquivo);

	lf.print_data_vector();

	// Condição de execução do jogo.
	while( print_continue(lf, ware) ){

		// Atualiza a geração.
		update(lf, ware);
		// Imprime a geração e qual o número da geração.
		lf.print_data_vector(ware.get_size()+1);

		// Verifica se a geração está extinta
		if(lf.is_extinct()){
			std::cout << ">>> All Cells are extinct. Exiting...\n";
			break;
		}

		// Verifica se a geração é estável.
		int result_stable = is_stable(lf, ware);
		if( result_stable != 0){
			std::cout << ">>> Cells are stable. Frequecy = " << result_stable << std::endl;
			break;
		}
	}
	// Salva o arquivo no arquivo de saída informado pelo usuário.
	if(argc == 3)
		save_file(ware, arquivo_saida);
	
	return 0;
}
