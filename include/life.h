#ifndef LIFE_H
#define LIFE_H

#include <iostream>
#include <fstream>
#include <vector>
#include "quadboard.h"

/// Cell type
enum Cell{
	CELL_ALIVE = 1,
	CELL_DIED = 0
};

class Life {
	private:
        /// stores the cells
		std::vector<std::vector<Cell>> grid;
        /// height of the grid
		int rows;
        /// width of the grid 
		int cols;
        /// id to identify grid
        std::vector<int> id;
        /// ids historic
        std::vector<std::vector<int>> ids;
        /// initialize object
        void init(int rows, int cols);
        
	public:
        
    /// board that will show the grid
    QuadBoard *board;
    
	/// construtor
	Life(int rows = 20, int cols = 60);
    
    /// construtor
    Life(std::string filename);
    
    ///destructor
	~Life();
    
	/// = operator overload
	Life & operator=(const Life& lf);
    
    /// == operator overload
	bool operator==(std::vector<int> id) const; 
    
    /// update board grid
    void update();
    
    /// load cell grid from board quads state
    void load_from_board();
    
	/*!
     * get value of cell at (x, y)
     * \param x number of rows
     * \param y number of columns
     * \return Cell value at (x, y) 
     */
	Cell get_value( int x, int y );
    
    /*!
     * set value of cell at (x, y)
     * \param x number of rows
     * \param y number of columns
     * \param value Cell value at (x, y) 
     */
	void set_value( int x, int y, Cell value);
    
    /// get number of rows
	int get_rows();
	/// get number of columns
	int get_columns();
    /*! Check if cells are extinct
     * \return true if cells are extinct; or false othewise
     */
	bool is_extinct();
    
    /*! Check if cells are stable
     * \return true if cells are stable; or false othewise
     */
    bool is_stable();
    
    /// clear ids matrix
    void clear_ids();
    
    /// create id vector
    void set_id();
    
    /// set all bords
    void bordas();
    
    /// load bords at cell area
    void load_bordas();
};
#endif
