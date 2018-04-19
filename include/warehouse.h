#ifndef WAREHOUSE_H
#define WAREHOUSE_H

/// Classe que armazena todos as configurações/gerações formadas.
class Warehouse {
	private:

		std::vector<Life> lifes;
		int generation_number;

	public:

		/// Inicializador da classe Warehouse.
		/// \param número de gerações.
		Warehouse( int gen_numb = 0 ){
			this->generation_number = gen_numb;
		}

		/// Desconstrutor para apagar o vetor e não deixar espaço na memória após finalizar o vetor.
		~Warehouse(){
			this->lifes.clear();
		}

		/// Adiciona uma nova classe Life ao vetor lifes.
		/// \param classe de configuração.
		void add_life( Life lf ){
			this->lifes.push_back(lf);
		}

		/// Retorna uma classe Life do vetor lifes.
		/// \param posição desejada no vetor lifes.
		/// \return retorna a classe na posição desejada.
		Life get_life( int posicao ){
			return lifes[posicao];
		}

		/// Obter o tamanho do vetor lifes, quantidade total de gerações.
		/// \return retorna a quantidade de classes Life no vetor lifes.
		int get_size(){
			return lifes.size();
		}
};

#endif
