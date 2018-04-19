#ifndef INICIAL_H
#define INICIAL_H

/// Inicialização do sistema
void initial( Life &ls, palavra nameFile ){
	
	std::cout << ">>> Trying to open input file [data/cfg1.dat]... ";

	arq_entrada iFile;

	/// Abre o arquivo.
	iFile.open(nameFile);

	/// Verifica se o arquivo foi aberto.
	if(iFile.fail()){

		std::cout << "error!\nTry again!\n" << std::endl;
		std::exit(1);

	} else{

		std::cout << "done!\n" << std::endl;

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
		std::cout << std::endl;


	}

	/// Fecha o arquivo.
	iFile.close();

}

#endif
