#include <iomanip>
/// Configura a classe Life pelo arquivo configuração.
/// \param Classe Life
/// \param Arquivo de configuração.
void readConfig(Life &lf, arq_entrada &arquivo){
		
	int ro, col;
	char carac;

	/// Lê as informações no arquivo
	while( arquivo >> ro >> col >> carac ){
		lf.set_rows(ro);
		lf.set_columns(col);
		lf.set_caractere(carac);
		break;
	}

	char valor;

	/// Vetor reserva para armazenamento de valores temporários.
	std::vector<int> valores;

	/// Filtra os elementos para dentro de um vetor.
	while( arquivo.get(valor) ){
		if(valor == '.')
			valores.push_back(0);
		if(valor == '*')
			valores.push_back(1);
	}

	/// Verifica se o tamanho e a quantidade de elementos estão certos.
	unsigned int tamanho = ro * col;

	if( tamanho != valores.size()){
		std::cout << "Há células faltantes na configuração inicial!" << std::endl;
		exit(0);
	}

	int ax = 0;
	for( auto i(0) ; i < (ro+2) ; i++ ){
		std::vector<int> v;
		for(auto j(0) ; j < (col+2) ; j++ ){
			if(i < 1 || i > ro || j < 1 || j > col)
				v.push_back(0);
			else{
				v.push_back(valores[ax]);
				ax++;
			}
		}
		lf.add_data_vector(v);
	}

	valores.clear();
	
}

/// Gera e armazena as gerações em um arquivo de saída.
/// \param classe contendo todas as gerações.
/// \param nome do arquivo de saída especificado pelo usuário.
void save_file(Warehouse ware, palavra arquivo_saida)
{
    arq_saida arquivo;

    /// Abre o arquivo de saída.
    arquivo.open("../data/"+arquivo_saida);

    /// Verifica se não ocorreu nenhum erro.
    if( !arquivo.is_open() ){
		std::cout << "Error!\nTry again!\n" << std::endl;
		return;
    }

    // Obtém a geração de uma classe Life
    Life lf = ware.get_life(0);
    /// Recebe o caractere da clase Life.
    char c = lf.get_caractere();

    /// Imprime no arquivo gerado quantidade de linhas e colunas e o caractere da confguração inicial.
    arquivo << "Initial Configuration:" << std::endl;
    arquivo << lf.get_rows() << " " << lf.get_columns() << std::endl << c << "\n" << std::endl;
    arquivo << std::endl;

    /// Obtém o tamanho do vetor que armazena as gerações.
    int size = ware.get_size();

    /// Imprime as configurações.
    for(int k = 0; k < size; k++){

    	/// Obtém cada célula.
        lf = ware.get_life(k);

        arquivo << "Showing generation " << k << ":" << std::endl;

        /// Imprime a configuração em uma determinada célula.
        for( auto i(1) ; i < lf.get_rows() ; i++ ){
            for( auto j(1) ; j < lf.get_columns() ; j++){


            	/// Verifica se ela está viva ou morta.
                if(lf.get_value(i, j) == CELL_ALIVE)
                    arquivo << c;
                else
                    arquivo << '.';

            }
            arquivo << std::endl;
        }
        arquivo << std::endl << std::endl;
    }
    arquivo.close();
}

/// Verifica se o usuário ainda deseja gerar mais células.
/// \param classe com uma geração.
/// \param classe com todas as gerações.
/// \param valor da geração atual.
bool print_continue(Life lf, Warehouse &wh, int value = 0){
	char answer;

	if( value == 0)
		wh.add_life( lf );

	/// Recebe a reposta do usuário.
	std::cout << "Continue viewing new generations?\n(y,n)? ";
	std::cin >> answer;

	std::cout << std::endl;

	/// Retorna a resposta do usuário.
	if( answer == 'y')
		return true;
	else if( answer == 'n')
		return false;
	else{
		/// Verifica se a resposta é válida.
		std::cout << "Sorry, we didn't understand!\n" << std::endl;
		print_continue(lf, wh, 1);
	}

	return true;
}
