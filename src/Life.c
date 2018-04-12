enum Cell{
	CELL_ALIVE = 1,
	CELL_DIED = 0
};
class Life
{
	private:
		std::vector<std::vector<int>> grid;
	public:
		Life(int nLin, int nCol)
		{
			grid.resize(nLIn);
			for(int i = 0; i < nLin; ++i)
			{
				grid[i].resize[nCol];
				for(int j = 0; j < nCol; ++j)
				{
					grid[i][j] = 0;
				}
			}
		
		}
		set_alive();
		update();
		print();
		stable();
		extinct();
		// sobrecarga de operadores
}
