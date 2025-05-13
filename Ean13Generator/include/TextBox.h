#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#define ENTER_KEY 13
#define ESCAPE_KEY 27
#define BACKSPACE_KEY 8

using namespace std;

class TextBox {
private:
	sf::RectangleShape rectangle;
	sf::Text textbox;
	string text;
	bool isSelected = false;
	bool hasLimit = false;
	int count_limit = 0;
	int limit = 12;

public:
	TextBox(sf::Vector2f rect_size, sf::Font& font, unsigned int size);

	void setTextFont(sf::Font& font);
	void setTextColor(sf::Color color);
	void setTextSize(int size);
	void setTextPosition(sf::Vector2f coords);
	void setTextString(string& string);

	void setRectPos(sf::Vector2f pos);
	void setRectOutColor(sf::Color color);
	void setRectFillColor(sf::Color color);
	void setRectThickness(int size);

	float getRectPosX();
	float getRectPosY();

	float getRectSizeX();
	float getRectSizeY();

	void setLimit();
	void setCountLimit(int count);
	void setSelected(int TypedChar);

	string& getText();
	sf::Text& getTextObject();
	sf::RectangleShape& getRectObject();

	// Ввод
	void Typed(sf::Event::TextEntered input);

	// Логика ввода
	void inputLogic(int TypedChar);

	void deleteLastChar();

	// Центрирование
	void centerPosition(sf::Vector2f position);
};

