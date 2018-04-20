#ifndef QUADBOARD_H
#define QUADBOARD_H
#include <SFML/Graphics.hpp>
class QuadBoard : public sf::Drawable, public sf::Transformable
{
public:
    /*! QuadBoard constructor
     * \param quad_size size in pixels of each quad of the board
     * \param width width in number of cols of the board
     * \param height height in number of rows of the board
     * \param magin space in pixel between quad
     * \param default_color color that will be displayed when the quad is not activated
     * \param activate color that will be displayed when the quad is activated
     */
    QuadBoard(size_t quad_size, size_t width, size_t height, size_t margin, sf::Color default_color = sf::Color::Green, sf::Color active_color = sf::Color::Yellow);
    /*!change quad color
     * \param x row of board
     * \param y column of board
     * \param color new color
     */
    void set_quad_color(unsigned int x, unsigned int y, sf::Color color);
    /*!change quad state to activated
     * \param x row of board
     * \param y column of board
     */
    void set_active(int x, int y);
    /*!change quad state to deactivated
     * \param x row of board
     * \param y column of board
     */
    void set_default(int x, int y);
    /// update board
    void update(sf::Event& e);
    /// clear board
    void clear();
    /// set board to initial state
    void reset();
    /// save actual board state
    void backup();
    /*!get board element state
     * \param x row of board
     * \param y column of board
     */
    bool get_active(int x, int y);
    /// get size in pixels of each quad
    size_t get_quad_size(){return this->quad_size;}
    /// get space in pixels between quads
    size_t get_margin(){return this->margin;}
    /// dont update board
    void disable(){this->is_enable = false;}
    /// enable board
    void enable(){this->is_enable = true;}
    /// check id the board is disable
    bool is_disable(){return not this->is_enable;}
private:
    /// draw methode, check SFML docs
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    size_t quad_size;
    size_t margin;
    size_t width;
    size_t height;
    bool is_enable;
    sf::Color active_color;
    sf::Color default_color;
    sf::VertexArray m_vertices;
    sf::VertexArray m_o_vertices; // original vertex Array
};
#endif
