#include "TextBox.h"

TextBox::TextBox(sf::Vector2f rect_size, sf::Font& font, unsigned int size) : rectangle(rect_size), textbox(font, "", size) {};

void TextBox::setTextFont(sf::Font& font) {
	textbox.setFont(font);
}
void TextBox::setTextColor(sf::Color color) {
	textbox.setFillColor(color);
}
void TextBox::setTextSize(int size) {
	textbox.setCharacterSize(size);
}
void TextBox::setTextPosition(sf::Vector2f coords) {
	textbox.setPosition(coords);
}
void TextBox::setTextString(string& string) {
	text = string;
	textbox.setString(text);
}

void TextBox::setRectPos(sf::Vector2f pos) {
	rectangle.setPosition(pos);
}
void TextBox::setRectOutColor(sf::Color color) {
	rectangle.setOutlineColor(color);
}
void TextBox::setRectFillColor(sf::Color color) {
	rectangle.setFillColor(color);
}
void TextBox::setRectThickness(int size) {
	rectangle.setOutlineThickness(size);
}

float TextBox::getRectPosX() {
	return rectangle.getPosition().x;
}
float TextBox::getRectPosY() {
	return rectangle.getPosition().y;
}

float TextBox::getRectSizeX() {
	return rectangle.getSize().x;
}
float TextBox::getRectSizeY() {
	return rectangle.getSize().y;
}

void TextBox::setLimit() {
	hasLimit = (count_limit >= limit);
}
void TextBox::setCountLimit(int count) {
	count_limit = count;
}
void TextBox::setSelected(int TypedChar) {
	if (TypedChar == ENTER_KEY)
		isSelected = true;
	else if (TypedChar == ESCAPE_KEY)
		isSelected = false;
}

string& TextBox::getText() {
	return text;
}
sf::Text& TextBox::getTextObject() {
	return textbox;
}
sf::RectangleShape& TextBox::getRectObject() {
	return rectangle;
}


void TextBox::Typed(sf::Event::TextEntered input) {
	int TypedChar = input.unicode;
	setSelected(TypedChar);
	if (isSelected) {
		if ((TypedChar >= '0' && TypedChar <= '9') && hasLimit == false) {
			inputLogic(TypedChar);
		}
		else if (TypedChar == BACKSPACE_KEY)
			deleteLastChar();
	}
}
void TextBox::inputLogic(int TypedChar) {
	if (TypedChar != ENTER_KEY && TypedChar != ESCAPE_KEY && TypedChar != BACKSPACE_KEY){
		text += static_cast<char>(TypedChar);
		setTextString(text);
		count_limit += 1;
		setLimit();
	}
	else if (TypedChar == BACKSPACE_KEY)
		deleteLastChar();
}
void TextBox::deleteLastChar() {
	if (!text.empty()) {
		text.pop_back();
		setTextString(text);
		count_limit -= 1;
		setLimit();
	}
}

void TextBox::centerPosition(sf::Vector2f position) {
	rectangle.setOrigin(rectangle.getSize() / 2.f);
	rectangle.setPosition(position);
	textbox.setPosition({ position.x - rectangle.getSize().x / 10, position.y - rectangle.getSize().y / 4 });
}