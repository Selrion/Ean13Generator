#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Button {
private:
	sf::Text text;
	sf::RectangleShape rectangle;
	sf::Color colorPointed = sf::Color::Green;
	sf::Color colorNotPointed = sf::Color{210, 210, 210, 225};
	bool statusPointed = 0;

public:

	Button(sf::Vector2f rect_size, sf::Font& font, unsigned int size);

	void setTextFont(sf::Font& font);
	void setTextSize(unsigned int size);
	void setTextColor(sf::Color color);
	void setTextString(const std::string& txt);
	void setTextPos(sf::Vector2f pos);

	void setRectPos(sf::Vector2f pos);
	void setRectOutColor(sf::Color color);
	void setRectFillColor(sf::Color color);
	void setRectThickness(int size);

	float getRectPosX();
	float getRectPosY();

	float getRectSizeX();
	float getRectSizeY();

	sf::Text& getTextObject();
	sf::RectangleShape& getRectObject();

	bool getPointed();
	void isPointed(sf::Vector2i coords);

	void draw(sf::RenderWindow& window);

	void centerPosition(sf::Vector2f position);

};

