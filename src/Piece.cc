#include "../include/Piece.hh"

Piece::Piece(sf::Texture &texture, int x, int y, int val)
{
    sprite.setTexture(texture);
    value = val;
    (value < 0) ? sprite.setTextureRect(sf::IntRect(56 * abs(value) - 1, 0, 56, 56))
                : sprite.setTextureRect(sf::IntRect(56 * abs(value) - 1, 56, 56, 56));
    sprite.setPosition(x, y);
    sprite.setOrigin(56 / 2, 56 / 2);
}

sf::Vector2f Piece::GetPosition()
{
    return sprite.getPosition();
}

void Piece::SetPosition(int x, int y)
{
    sprite.setPosition(x, y);
}

int Piece::GetValue()
{
    return value;
}

bool Piece::ContainPosition(int x, int y)
{
    int szX = sprite.getPosition().x;
    int szY = sprite.getPosition().y;

    sf::IntRect rect = sf::IntRect(szX - 31, szY - 31, 56, 56);
    return rect.contains(x, y);
}

void Piece::draw(sf::RenderTarget &rt, sf::RenderStates rs) const
{
    rt.draw(sprite, rs);
}