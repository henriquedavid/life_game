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
	
}
// Life get_life( int posicao );
// int get_size();
void save_file(Warehouse ware, std::string arquivo_saida)
{
    arq_saida arquivo;
    arquivo.open("../"+arquivo_saida);
    if( !arquivo.is_open() ){
		std::cout << "error!\nTry again!\n" << std::endl;
		return;
    }
    Life lf = ware.get_life(0);
    char c = lf.get_caractere();
    arquivo << lf.get_rows() << " " << lf.get_columns() << std::endl << c << std::endl;
    int size = ware.get_size();
    for(int k = 0; k < size; k++){
        lf = ware.get_life(k);
        for( auto i(1) ; i < lf.get_rows()+1 ; i++ ){
            for( auto j(1) ; j < lf.get_columns() +1 ; j++){
                if(lf.get_value(i, j) == CELL_ALIVE)
                    arquivo << c;
                else
                    arquivo << '.';
            }
            arquivo << std::endl;
        }
        arquivo << std::setw(lf.get_columns()+1) << std::setfill('-') << '\n';
    }
    arquivo.close();
}
/// Verifica se o usuário ainda deseja gerar mais células.
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
