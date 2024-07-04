#ifndef UI_HEADER
#define UI_HEADER

#include <SFML/Graphics.hpp>
#include <iostream>

class UI : public sf::Drawable
{
private:
    sf::Font font;
    sf::Text text;
    int jaqueTime;

public:
    UI();
    void Update(bool);
    void Jaque(bool);
    void JaqueMate(bool);
    virtual void draw(sf::RenderTarget &, sf::RenderStates) const;
};

#endif // !UI_HEADER