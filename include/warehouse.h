
class Warehouse {
	private:

		std::vector<Life> lifes;
		int generation_number;

	public:

		void add_life( Life lf ){
			this->lifes.push_back(lf);
		}

		Life get_life( int posicao ){
			return lifes[posicao];
		}

		int get_size(){
			return lifes.size();
		}
};