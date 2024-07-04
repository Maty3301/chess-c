#ifndef PIECE_HEADER
#define PIECE_HEADER

#include <iostream>
#include <SFML/Graphics.hpp>

class Piece : public sf::Drawable
{
private:
    sf::Sprite sprite;
    int value;

public:
    Piece(sf::Texture &texture, int x, int y, int val);
    bool ContainPosition(int, int);
    void SetPosition(int, int);
    sf::Vector2f GetPosition();
    int GetValue();
    virtual void draw(sf::RenderTarget &, sf::RenderStates) const;
};

#endif // !PIECE_HEADER