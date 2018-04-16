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

	if(argc != 2){
		std::cout << "Wrong syntaxe!\n"
				  << "Use: life <input_cfg_file> [<output_cfg_evolution_file>]" << std::endl;
		return 0;
	}


 	Life lf(20, 60, '-');
 	initial(lf, "TESTE");

	return 0;
}