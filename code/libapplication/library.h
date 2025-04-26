#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#pragma once

using namespace std;
using namespace sf;

typedef struct {
    int x;
    int y;
} Point;

const int M = 20;
const int N = 10;

bool load_main_texture(Texture&);

int numbers(int, int);
bool loadTextures(
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&);
bool createSprites(
        Sprite&,
        Sprite&,
        Sprite&,
        Sprite&,
        Sprite&,
        Sprite&,
        Sprite&,
        Sprite&,
        Sprite&,
        Sprite&,
        Sprite&,
        Sprite&,
        Sprite&,
        Sprite&,
        Sprite&,
        Sprite&,
        Sprite&,
        Sprite&,
        Sprite&,
        Sprite&,
        Sprite&,
        Sprite&,
        Sprite&,
        Sprite&,
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&,
        Texture&);
bool createTexts(Text&, Text&, Text&, Text&, Text&, Text&, Text&, Text&, Font&);
bool fig_rotation(Point (&)[4]);
bool fig_dx_movement(Point (&)[4], int);
bool line_kill(int[M][N], int&);
bool drawFigure(
        RenderWindow&,
        Sprite&,
        Sprite&,
        int,
        Point[],
        Point[],
        int*,
        int*,
        bool);
