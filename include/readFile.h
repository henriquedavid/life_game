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

/// Verifica se o usuário ainda deseja gerar mais células.
bool print_continue(){
	char answer;

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
		print_continue();
	}

	return true;
}