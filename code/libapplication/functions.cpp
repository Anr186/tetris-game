#include "library.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

int numbers(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
bool loadTextures(
        Texture& kubics,
        Texture& Initbackground,
        Texture& background,
        Texture& kubics2,
        Texture& score_texture,
        Texture& next_texture,
        Texture& one_texture,
        Texture& two_texture,
        Texture& three_texture,
        Texture& level_frame,
        Texture& sound,
        Texture& sound1,
        Texture& home_texture,
        Texture& retry_texture,
        Texture& arrow_texture)
{
    kubics.loadFromFile("../resources/images/tiles.png");
    Initbackground.loadFromFile("../resources/images/Initback.png");
    background.loadFromFile("../resources/images/f3.png");
    kubics2.loadFromFile("../resources/images/net.png", IntRect(0, 0, 27, 27));
    kubics2.setRepeated(true);
    score_texture.loadFromFile("../resources/images/score.png");
    next_texture.loadFromFile("../resources/images/next.png");
    one_texture.loadFromFile("../resources/images/n-1.png");
    two_texture.loadFromFile("../resources/images/n-2.png");
    three_texture.loadFromFile("../resources/images/n-3.png");
    level_frame.loadFromFile("../resources/images/level_frame.png");
    sound.loadFromFile("../resources/images/sound.png");
    sound1.loadFromFile("../resources/images/sound1.png");
    home_texture.loadFromFile("../resources/images/home.png");
    retry_texture.loadFromFile("../resources/images/retry.png");
    arrow_texture.loadFromFile("../resources/images/arrow.png");
    return true;
}
bool load_main_texture(Texture& kubics)
{
    if (kubics.loadFromFile("../resources/images/tiles.png"))
        return true;
    else
        return false;
}
bool createSprites(
        Sprite& kub,
        Sprite& kub_next,
        Sprite& Initback,
        Sprite& bkground,
        Sprite& net,
        Sprite& score_txt,
        Sprite& next_ramk,
        Sprite& next_txt,
        Sprite& level_txt,
        Sprite& level_txt_1,
        Sprite& level_txt_2,
        Sprite& level_txt_3,
        Sprite& frame1,
        Sprite& frame2,
        Sprite& frame3,
        Sprite& song,
        Sprite& song1,
        Sprite& home_button,
        Sprite& retry_button,
        Sprite& arrow_up,
        Sprite& arrow_down,
        Sprite& arrow_left,
        Sprite& arrow_right,
        Sprite& arrow_frame,
        Texture& kubics,
        Texture& Initbackground,
        Texture& background,
        Texture& kubics2,
        Texture& score_texture,
        Texture& next_texture,
        Texture& one_texture,
        Texture& two_texture,
        Texture& three_texture,
        Texture& level_frame,
        Texture& sound,
        Texture& sound1,
        Texture& home_texture,
        Texture& retry_texture,
        Texture& arrow_texture)
{
    kub.setTexture(kubics);
    kub.setTextureRect(IntRect(0, 0, 27, 27));
    kub_next.setTexture(kubics);
    kub_next.setTextureRect(IntRect(0, 0, 27, 27));

    Initback.setTexture(Initbackground);
    bkground.setTexture(background);
    net.setTexture(kubics2);
    net.setTextureRect(IntRect(0, 0, 270, 540));
    net.setColor(Color(255, 255, 255, 70));

    score_txt.setTexture(score_texture);
    score_txt.setTextureRect(IntRect(0, 0, 75, 26));
    score_txt.setPosition(283, 43);
    next_ramk.setTexture(next_texture);
    next_ramk.setTextureRect(IntRect(1, 41, 110, 150));
    next_ramk.setPosition(300, 150);
    next_ramk.setScale(1.15f, 1.15f);
    next_txt.setTexture(next_texture);
    next_txt.setTextureRect(IntRect(28, 5, 80, 34));
    next_txt.setPosition(336, 100);

    level_txt.setTexture(score_texture);
    level_txt.setTextureRect(IntRect(3, 26, 83, 59));
    level_txt.setPosition(185, 395);
    level_txt_1.setTexture(one_texture);
    level_txt_1.setPosition(110, 470);
    level_txt_2.setTexture(two_texture);
    level_txt_2.setPosition(215, 470);
    level_txt_3.setTexture(three_texture);
    level_txt_3.setPosition(325, 470);

    frame1.setTexture(level_frame);
    frame1.setPosition(80, 447);
    frame1.setScale(0.2f, 0.2f);
    frame2.setTexture(level_frame);
    frame2.setPosition(185, 447);
    frame2.setScale(0.2f, 0.2f);
    frame3.setTexture(level_frame);
    frame3.setPosition(295, 447);
    frame3.setScale(0.2f, 0.2f);

    song.setTexture(sound);
    song.setTextureRect(IntRect(3, 3, 68, 69));
    song.setPosition(317, 470);

    song1.setTexture(sound1);
    song1.setTextureRect(IntRect(3, 3, 68, 69));
    song1.setPosition(317, 470);

    home_button.setTexture(home_texture);
    home_button.setPosition(315, 550);
    retry_button.setTexture(retry_texture);
    retry_button.setPosition(315, 390);

    arrow_up.setTexture(arrow_texture);
    arrow_up.setOrigin(132, 180);
    arrow_up.setPosition(163, 565);
    arrow_up.setRotation(270);
    arrow_up.setScale(0.20f, 0.20f);
    arrow_up.setColor(Color(255, 255, 255, 255));

    arrow_down.setTexture(arrow_texture);
    arrow_down.setOrigin(132, 180);
    arrow_down.setPosition(135, 670);
    arrow_down.setRotation(90);
    arrow_down.setScale(0.20f, 0.20f);
    arrow_down.setColor(Color(255, 255, 255, 255));

    arrow_left.setTexture(arrow_texture);
    arrow_left.setOrigin(132, 180);
    arrow_left.setPosition(95, 600);
    arrow_left.setRotation(180);
    arrow_left.setScale(0.20f, 0.20f);
    arrow_left.setColor(Color(255, 255, 255, 255));

    arrow_right.setTexture(arrow_texture);
    arrow_right.setOrigin(132, 180);
    arrow_right.setPosition(202, 629);
    arrow_right.setScale(0.20f, 0.20f);
    arrow_right.setColor(Color(255, 255, 255, 255));

    arrow_frame.setTexture(next_texture);
    arrow_frame.setTextureRect(IntRect(1, 41, 110, 150));
    arrow_frame.setPosition(80, 550);
    arrow_frame.setScale(1.25f, 1.25f);

    return true;
}

bool createTexts(
        Text& text1,
        Text& text2,
        Text& text_time2,
        Text& text_time,
        Text& text_test3,
        Text& text_game_over,
        Text& text_pause,
        Text& text_level,
        Font& font2)
{
    font2.loadFromFile("../resources/fonts/Comic.ttf");

    text1.setFont(font2);
    text1.setCharacterSize(30);
    text1.setString("");
    text1.setFillColor(Color::White);

    text2.setFont(font2);
    text2.setCharacterSize(30);
    text2.setString("");
    text2.setFillColor(Color::White);

    text_time2.setFont(font2);
    text_time2.setCharacterSize(25);
    text_time2.setString("");
    text_time2.setFillColor(Color::White);
    text_time2.setPosition(300, 660);

    text_time.setFont(font2);
    text_time.setCharacterSize(26);
    text_time.setString("");
    text_time.setFillColor(Color::White);
    text_time.setPosition(300, 700);

    text_test3.setFont(font2);
    text_test3.setCharacterSize(20);
    text_test3.setString("");
    text_test3.setFillColor(Color::Red);

    text_game_over.setFont(font2);
    text_game_over.setCharacterSize(45);
    text_game_over.setString("");
    text_game_over.setFillColor(Color::Red);

    text_pause.setFont(font2);
    text_pause.setCharacterSize(45);
    text_pause.setString("");
    text_pause.setFillColor(Color::White);

    text_level.setFont(font2);
    text_level.setCharacterSize(30);
    text_level.setString("2");
    text_level.setFillColor(Color::White);
    text_level.setPosition(375, 315);

    return true;
}

bool fig_rotation(Point (&a)[4])
{
    if (sizeof(a) / sizeof(Point) != 4) {
        return false;
    }
    Point p = a[1];
    for (int i = 0; i < 4; i++) {
        int x = a[i].y - p.y;
        int y = a[i].x - p.x;
        a[i].x = p.x - x;
        a[i].y = p.y + y;
    }

    return true;
}
bool fig_dx_movement(Point (&a)[4], int dx)
{
    if (sizeof(a) / sizeof(Point) != 4) {
        return false;
    }
    for (int i = 0; i < 4; i++) {
        a[i].x += dx;
    }
    return true;
}

bool line_kill(int field[M][N], int& counter)
{
    if (M <= 0 && N <= 0) {
        return false;
    }

    int k = M - 1;
    for (int i = M - 1; i >= 0; i--) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (field[i][j])
                count++;
            field[k][j] = field[i][j];
        }
        if (count < N)
            k--;
        else
            counter += 10;
    }

    return true;
}

bool drawFigure(
        RenderWindow& window,
        Sprite& kub,
        Sprite& kub_next,
        int colorNum,
        Point a[4],
        Point a_next[4],
        int* figureColors,
        int* queue,
        bool turn_off_drawing)
{
    if (a == nullptr || a_next == nullptr || figureColors == nullptr
        || queue == nullptr) {
        return false;
    }

    for (int i = 0; i < 4; i++) {
        kub.setTextureRect(IntRect(colorNum * 27, 0, 27, 27));
        kub.setPosition(a[i].x * 27, a[i].y * 27);
        if (!turn_off_drawing) {
            window.draw(kub);
        }

        kub_next.setTextureRect(
                IntRect(figureColors[queue[1]] * 27, 0, 27, 27));
        kub_next.setPosition(
                a_next[i].x * 27 + 27 * 12, a_next[i].y * 27 + 27 * 6 - 4);
        if (!turn_off_drawing) {
            window.draw(kub_next);
        }
    }

    return true;
}
