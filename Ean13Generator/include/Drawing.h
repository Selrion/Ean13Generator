#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextBox.h"
#include "Button.h"

using namespace std;

#define width_line 4
#define hight_line 108
#define ScreenSize 600

void barcodeDrawing(const vector<int>& binary_barcode, sf::RenderWindow& window);

void drawUI(sf::RenderWindow& window,
    TextBox& inputBox,
    Button& barcodeGeneration,
    bool barcodeReady,
    const vector<int>& currentBinaryPattern);

void setupUI(TextBox& inputBox, Button& barcodeGeneration);


