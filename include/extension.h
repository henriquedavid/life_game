
/// Aplica as regras do jogo nas células.
void update( Life &lf , Warehouse &wh){

	int tamanho = wh.get_size();
	tamanho--;

	auto last_Life(wh.get_life(tamanho));

	last_Life last_lf;

	/// Aplica a Regra 1.
	for( auto i(1); i < lf.get_rows()+1 ; i++ ){
		for( auto j(1) ; j < lf.get_columns()+1; j++ ){
			if(lf.get_value(i, j) == 1){
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

				if(cont <= 1)
					lf.set_value(i, j, 0);
			}



		}
	}
	std::cout << "Regra aplicada!" << std::endl;

}