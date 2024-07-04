#include "../include/UI.hh"

UI::UI()
{
    if (!font.loadFromFile("res/font/Antology.ttf"))
        exit(EXIT_FAILURE);

    text.setFont(font);
    text.setCharacterSize(40);
    text.setPosition(252, 490);
    text.setString("");
    text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
}

void UI::Update(bool color)
{
    if (jaqueTime == 0)
    {
        text.setString((std::string) "Turno de las " + (std::string)(color ? "Blancas" : "Negras"));
        text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
    }
    else if (jaqueTime > 0)
        jaqueTime--;
}

void UI::Jaque(bool color)
{
    jaqueTime = 100;
    (!color) ? text.setString("Jaque para negras") : text.setString("Jaque para blancas");
    text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
}

void UI::JaqueMate(bool color)
{
    jaqueTime = -100;
    (!color) ? text.setString("Jaque mate para negras") : text.setString("Jaque mate para blancas");
    text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
}

void UI::draw(sf::RenderTarget &rt, sf::RenderStates rs) const
{
    rt.draw(text, rs);
}