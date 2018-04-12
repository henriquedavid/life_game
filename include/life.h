#ifndef LIFE_H
#define LIFE_H
#include <iostream>
enum Cell{
	CELL_ALIVE = 1,
	CELL_DIED = 0;
};
class Life
{
	private:
		int** grid;
		int height;
		int width;
	public:
	Life(int nLin, int nCol);
	set_alive();
	update();
	print();
	stable();
	extinct();
	// sobrecarga de operadores
}
#endif
