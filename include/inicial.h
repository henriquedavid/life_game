#include <iostream>

bool openConfiguration(){
	ifstream iFile;
	iFile.open("../data/cfg1.dat");

	if(iFile != null)
		return true;
	else
		return false;
}

void initial(){
	
	std::cout << ">>> Trying to open input file [data/cfg1.dat]... ";

	//Life life_;
	bool abertura = openConfiguration();

	if( !abertura ){
		std::cout << "error!\nTry again!" << std::endl;
		break;

	} else{

		std::cout << "done!" << std::endl;

		std::cout << ">>> Processing data, please wait..." << std::endl;
		//Life life_ = openData(Life lif);

		//std::cout << ">>> Grid size read from input file: " << <life_.xgrid> << " rows by " << <life_.ygrid> << " cols." << std::endl;
		//std::cout << ">>> Character that represents a living cell read from input file: '" << <life_.character> << "'" << std::endl;

		std::cout << setw(40) << setfill('*') << " " << std::endl;
		/*std::cout << "Welcome to Conways game of Life.\n" 
					  << "By default this game uses a grid of size 20 by 60 in which\n"
					  << "each cell can either be occupied by an organism or not.\n"
					  << "The occupied cells change from generation to generation\n"
					  << "according to the number of neighboring cells which are alive." << std::endl;
		*/std::cout << setw(40) << setfill('*') << std::endl;

	}

}

int main(){

	initial();

	return 0;
}