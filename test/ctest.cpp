#include "../thirdparty/ctest.h"
#include "../code/libapplication/library.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

CTEST(texture_loading_suit, load_main_texture)
{
    Texture kubics;
    int expected = 1;
    int result = load_main_texture(kubics);
    ASSERT_EQUAL(expected, result);
}

CTEST(creating_texts_test, createTexts)
{
    Text text1;
    Text text2;
    Text text_time2;
    Text text_time;
    Text text_test3;
    Text text_game_over;
    Text text_pause;
    Text text_level;
    Font font2;

    int expected = 1;
    int result = createTexts(
            text1,
            text2,
            text_time2,
            text_time,
            text_test3,
            text_game_over,
            text_pause,
            text_level,
            font2);
    ASSERT_EQUAL(expected, result);
}

CTEST(fig_check_size_tests, fig_dx_movement)
{
    Point a[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    int expected = 1;
    int result = fig_dx_movement(a, 1);
    ASSERT_EQUAL(expected, result);
}
CTEST(input_data_suite, numbers)
{
    int expected = 3;
    int result = numbers(2, 3);

    ASSERT_EQUAL(expected, result);
}
CTEST(field_checking_test, line_kill)
{
    int counter = 0;
    int field[20][10];
    int expected = 1;
    int result = line_kill(field, counter);
    ASSERT_EQUAL(expected, result);
}
CTEST(fig_rotation_tests, fig_rotation)
{
    Point a[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Point expected[4] = {{1, -1}, {1, 0}, {0, 0}, {0, -1}};

    fig_rotation(a);

    for (int i = 0; i < 4; i++) {
        ASSERT_EQUAL(expected[i].x, a[i].x);
        ASSERT_EQUAL(expected[i].y, a[i].y);
    }
}

CTEST(fig_dx_movement_tests, fig_dx_movement)
{
    Point a[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Point expected[4] = {{2, 0}, {3, 0}, {3, 1}, {2, 1}};
    int dx = 2;
    bool result = fig_dx_movement(a, dx);

    ASSERT_TRUE(result);

    for (int i = 0; i < 4; i++) {
        ASSERT_EQUAL(expected[i].x, a[i].x);
        ASSERT_EQUAL(expected[i].y, a[i].y);
    }
}
CTEST(draw_figure_neccesarities_test, drawFigure)
{
    RenderWindow window;
    Sprite kub;
    Sprite kub_next;
    int colorNum;
    Point a[4];
    Point a_next[4];
    int figureColors[] = {1, 2, 3, 4, 5, 6, 7};

    int queue[2] = {0, 0};
    bool turn_off_drawing;

    int expected = 1;
    int result = drawFigure(
            window,
            kub,
            kub_next,
            colorNum,
            a,
            a_next,
            figureColors,
            queue,
            turn_off_drawing);
    ASSERT_EQUAL(expected, result);
}

CTEST(line_kill_tests, line_kill)
{
    int field[M][N];
    int expected_field[M][N];
    for (int i = 0; i < 10; i++) {
        field[19][i] = 1;
    }
    int counter = 0;
    int expected_counter = 60;

    bool result = line_kill(field, counter);

    ASSERT_TRUE(result);
    ASSERT_EQUAL(expected_counter, counter);
}

CTEST(test_no_filled_lines, line_kill)
{
    int field[M][N] = {
            {0, 1, 0, 1, 0}, {1, 0, 1, 0, 1}, {0, 1, 0, 1, 0}, {1, 0, 1, 0, 1}};
    int expected_field[M][N] = {
            {0, 1, 0, 1, 0}, {1, 0, 1, 0, 1}, {0, 1, 0, 1, 0}, {1, 0, 1, 0, 1}};
    int counter = 0;

    bool result = line_kill(field, counter);

    ASSERT_TRUE(result);
    ASSERT_EQUAL(0, counter);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            ASSERT_EQUAL(expected_field[i][j], field[i][j]);
        }
    }
}
