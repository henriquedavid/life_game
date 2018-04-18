
/// Aplica as regras do jogo nas células.
void update( Life &lf , Warehouse &wh){

	int tamanho = wh.get_size();
	tamanho--;

	Life last_lf = wh.get_life(tamanho);

	/// Aplica a Regra 1, 2, 3, 4 e 5.
	for( auto i(1); i < lf.get_rows()+1 ; i++ ){
		for( auto j(1) ; j < lf.get_columns()+1; j++ ){
			
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

			if(lf.get_value(i, j) == 1){
				if(cont <= 1 || cont >= 4)
					lf.set_value(i, j, 0);

			} else{
				if(cont == 3)
					lf.set_value(i, j, 1);
			}
		}
	}
	lf.set_id();
}

bool is_stable( Life &lf_now, Warehouse &ware){

	for(auto i(0); i < ware.get_size(); ++i){

		auto lf_temp( ware.get_life(i) );

		for(auto j(1); j < lf_now.get_rows()+2; j++){
			for(auto k(1); k < lf_now.get_columns()+2; k++){
				
				if( lf_now.get_value(j,k) != lf_temp.get_value(j,k) )
					return true;
				}

			}

		}

	return false;

}

