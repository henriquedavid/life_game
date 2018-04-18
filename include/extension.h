
/// Aplica as regras do jogo nas células.
/// \param Classe Life
/// \param Classe que armazena todas as classes lifes geradas durante a execução.
void update( Life &lf , Warehouse &wh){

	int tamanho = wh.get_size();	// Recupera o tamanho.
	tamanho--;

	Life last_lf = wh.get_life(tamanho);	// Recupera a última classe salva.

	// Aplica a Regra 1, 2, 3, 4 e 5.
	for( auto i(1); i < lf.get_rows()+1 ; i++ ){
		for( auto j(1) ; j < lf.get_columns()+1; j++ ){
			// Contabiliza os vizinhos vivos de cada célula.
			int cont = 0;
			if(last_lf.get_value(i-1, j-1) == 1)
				cont++;
			if(last_lf.get_value(i-1, j)  == 1)
				cont++;
			if(last_lf.get_value(i-1, j+1) == 1)
				cont++;
			if(last_lf.get_value(i, j-1) == 1)
				cont++;
			if(last_lf.get_value(i, j+1) == 1)
				cont++;
			if(last_lf.get_value(i+1, j-1) == 1)
				cont++;
			if(last_lf.get_value(i+1, j) == 1)
				cont++;
			if(last_lf.get_value(i+1, j+1) == 1)
				cont++;

			// Aplica as regras.
			if(lf.get_value(i, j) == 1){
				if(cont <= 1 || cont >= 4)
					lf.set_value(i, j, 0);

			} else{
				if(cont == 3)
					lf.set_value(i, j, 1);
			}
		}
	}

	// Gera as bordas que ultrapassam a bordas do outro lado.
	lf.bordas();

	lf.set_id();
}

/// Verifica se a geração é estável.
/// \ṕaram Geração atual.
/// \param Classe que obtém todas as gerações.
/// \return Verdadeiro se forem iguais e falso se forem diferentes.
bool is_stable( Life &lf_now, Warehouse &ware){

	bool estado = false;

	// Recupera o tamanho do vetor que contém todas as gerações.
	int tamanho = ware.get_size();

	// Trata o caso em que não há análises suficientes.
	if(tamanho < 2){
		return false;
	}

	int last_ = 0;

	// Percorre o vetor que contém as gerações.
	for(auto i(0); i < tamanho-1; ++i){

		// Obtém cada geração.
		auto lf_temp( ware.get_life(i) );

		// Percorre os estados da geração atual e da geração obtida.
		for(auto j(0); j < lf_now.get_rows(); j++){
			for(auto k(0); k < lf_now.get_columns(); k++){
				
				// Recebe os valores de cada geração em determinada posição.
				int valor = lf_now.get_value(j,k);
				int valor1 = lf_temp.get_value(j,k);

				/* Contabilizam os valores.
				 */
				if( valor != valor1 )
					break;
				else
					last_++;
				
			}
		}

		if(last_ == ((lf_now.get_columns()) * (lf_now.get_rows())))
			estado = true;

	}

	return estado;

}

