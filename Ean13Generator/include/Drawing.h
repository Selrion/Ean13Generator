#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextBox.h"
#include "Button.h"

using namespace std;

#define width_line 4
#define height_line 108
#define ScreenSize 600

// Отрисовка штрих-кода
void barcodeDrawing(const vector<int>& binary_barcode, sf::RenderWindow& window);

// Рендер объектов
void drawUI(sf::RenderWindow& window,
    TextBox& inputBox,
    Button& barcodeGeneration,
    bool barcodeReady,
    const vector<int>& currentBinaryPattern);

// Установка параметров
void setupUI(TextBox& inputBox, Button& barcodeGeneration);


