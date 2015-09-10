#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel matrix = Adafruit_NeoPixel(40, 6, NEO_GRB + NEO_KHZ800);

extern int timeHour;
extern int timeMinute;

// Index:
//   0   1   2   3   4   5   6   7
//   8   9  10  11  12  13  14  15
//  16  17  18  19  20  21  22  23
//  24  25  26  27  28  29  30  31
//  32  33  34  35  36  37  38  39

void setupUI() {
    matrix.begin(); // This initializes the NeoPixel library.
    pushMatrix();
}

void drawUpdate() {
    adjustBrightness();
    pushMatrix();
}

void adjustBrightness() {
    matrix.setBrightness(3);
}

void pushMatrix() {
    matrix.show();
}


void clearMatrix() {
    for (uint16_t i = 0; i < PIXELCOUNT; i++) {
        _setPixelNative(i, 0, 0, 0);
    }
}

/**
* Objects -> -1 ist tailing char
*/
int leftColorLine[] = {0, 8, 16, 24, 32, -1};
int minus[] = {16, 17, 18, -1};
int lift[] = {1, 8, 9, 10, 16, 18, 24, 26, 32, 33, 34, -1};
/**
* Int Index -> -1 ist tailing char
*/
int zero[] = {0, 1, 2, 10, 18, 26, 34, 33, 32, 24, 16, 8, -1};
int one[] = {2, 10, 18, 26, 34, 9, 16, -1};
int two[] = {0, 1, 2, 10, 18, 17, 16, 24, 32, 33, 34, -1};
int three[] = {0, 1, 2, 10, 16, 17, 18, 26, 32, 33, 34, -1};
int four[] = {0, 8, 16, 17, 18, 2, 10, 26, 34, -1};
int five[] = {2, 1, 0, 8, 16, 17, 18, 26, 34, 33, 32, -1};
int six[] = {2, 1, 0, 8, 16, 17, 18, 26, 34, 33, 32, 24, -1};
int seven[] = {0,1,2,10,17,24,32, -1};
int eight[] = {0, 1, 2, 8, 10, 16, 17, 18, 24, 26, 32, 33, 34, -1};
int nine[] = {0, 1, 2, 8, 10, 16, 17, 18, 26, 34, 33, 32, -1};
int *intList[] = {zero, one, two, three, four, five, six, seven, eight, nine};

void setUpdating() {
    matrix.setPixelColor(0, 100, 100, 100);
}

void unsetUpdating() {
    matrix.setPixelColor(0, 0, 0, 0);
}

/**
* draws a minus in the middle for negative values
*/
void drawMinusMiddle(int r, int g, int b) {
    _drawPixelArray(minus, 1, r, g, b);
}

/**
* draws the indicator lane
*/
void drawLeftColorLine(int r, int g, int b) {
    _drawPixelArray(leftColorLine, 0, r, g, b);
}

/**
* draws the lift warning
*/
void drawLiftMiddle(int r, int g, int b) {
    _drawPixelArray(lift, 1, r, g, b);
}

/**
* Draws an Integer in the middle of the matrix
*/
void drawIntegerMiddle(int integer, int r, int g, int b) {
    _drawIntegerWithOffset(integer, 1, r, g, b);
}

/**
* Draws an Integer on the right part of the matrix
*/
void drawIntegerRight(int integer, int r, int g, int b) {
    _drawIntegerWithOffset(integer, 5, r, g, b);
}


void _drawIntegerWithOffset(int integer, int offset, int r, int g, int b) {
    _drawPixelArray(intList[integer], offset, r, g, b);
}

/**
* Draws an color to a list of intIDs - RED GREEN BLUE
*/
void _drawPixelArray(int *array, int offset, int r, int g, int b) {
    int i = 0;
    while (array[i] != -1) {
        int value = array[i];
        matrix.setPixelColor(value + offset, r, g, b);
        i++;
    }
}

void _setPixelNative(int id, int r, int g, int b) {
    matrix.setPixelColor(id, r, g, b);
}

void _setPixelNative(int id, uint32_t color) {
    matrix.setPixelColor(id, color);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
    WheelPos = 255 - WheelPos;
    if (WheelPos < 85) {
        return matrix.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    } else if (WheelPos < 170) {
        WheelPos -= 85;
        return matrix.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    } else {
        WheelPos -= 170;
        return matrix.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
    }
}