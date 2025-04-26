#include <../libapplication/library.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

Point a[4];
Point a_next[4];
Point b[4];

int field[M][N] = {0};

int main()
{
    int queue[2] = {0, 0};
    int figureColors[] = {1, 2, 3, 4, 5, 6, 7};

    int figures[7][4] = {
            1, 3, 5, 7, // I 0
            2, 4, 5, 7, // S 1
            3, 5, 4, 6, // Z 2
            3, 5, 4, 7, // T 3
            2, 3, 5, 7, // L 4
            3, 5, 7, 6, // J 5
            2, 3, 4, 5, // O 6
    };
    Texture kubics, Initbackground, background, kubics2, score_texture,
            next_texture, one_texture, two_texture, three_texture;
    Texture level_frame, sound, sound1, home_texture, retry_texture,
            arrow_texture;
    loadTextures(
            kubics,
            Initbackground,
            background,
            kubics2,
            score_texture,
            next_texture,
            one_texture,
            two_texture,
            three_texture,
            level_frame,
            sound,
            sound1,
            home_texture,
            retry_texture,
            arrow_texture);

    Sprite kub, kub_next, Initback, bkground, net, score_txt, next_ramk,
            next_txt, level_txt, level_txt_1, level_txt_2, level_txt_3;
    Sprite frame1, frame2, frame3, song, song1;
    Sprite home_button, retry_button, arrow_up, arrow_down, arrow_left,
            arrow_right, arrow_frame;

    createSprites(
            kub,
            kub_next,
            Initback,
            bkground,
            net,
            score_txt,
            next_ramk,
            next_txt,
            level_txt,
            level_txt_1,
            level_txt_2,
            level_txt_3,
            frame1,
            frame2,
            frame3,
            song,
            song1,
            home_button,
            retry_button,
            arrow_up,
            arrow_down,
            arrow_left,
            arrow_right,
            arrow_frame,
            kubics,
            Initbackground,
            background,
            kubics2,
            score_texture,
            next_texture,
            one_texture,
            two_texture,
            three_texture,
            level_frame,
            sound,
            sound1,
            home_texture,
            retry_texture,
            arrow_texture);

    Font font2;
    Text text1, text2, text_time2, text_time, text_test3, text_game_over,
            text_pause, text_level;

    createTexts(
            text1,
            text2,
            text_time2,
            text_time,
            text_test3,
            text_game_over,
            text_pause,
            text_level,
            font2);

    Music music2;

    bool isPlaying = true;
    bool rotatePressed = false;
    bool leftPressed = false;
    bool rightPressed = false;

    int dx = 0;
    bool rotate = 0;
    float timer = 0, delay = 0.5;
    float timer2 = 0, delay2 = 0.3;
    Clock clock;
    bool beginGame = true;
    int colorNum = 1;
    srand(time(0));
    int n = rand() % 7;
    int counter = 0;
    string s_count = to_string(counter);
    int test_q = 0;
    int turn_off_drawing = 0;
    float difficulty = 0.5;
    queue[0] = rand() % 7;

    int game_pause = 0;
    int game_starter = 0;

    ConvexShape button_convex;
    button_convex.setPointCount(3);
    button_convex.setPoint(0, Vector2f(202.f, 572.f));
    button_convex.setPoint(1, Vector2f(202.f, 724.f));
    button_convex.setPoint(2, Vector2f(278.f, 646.f));
    button_convex.setFillColor(Color(0, 0, 0, 20));

    while (true) {
        RenderWindow window_pause(VideoMode(445, 765), "Tetris");
        while (window_pause.isOpen()) {
            level_txt.setPosition(185, 395);
            Event event;
            while (window_pause.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    return 0;
                    game_pause = 1;
                }
                if (button_convex.getGlobalBounds().contains(
                            window_pause.mapPixelToCoords(
                                    Mouse::getPosition(window_pause)))
                    && (game_starter == 1)) {
                    button_convex.setFillColor(Color(255, 255, 255, 50));
                    if (event.type == Event::MouseButtonPressed)
                        window_pause.close();
                } else
                    button_convex.setFillColor(Color(0, 0, 0, 20));

                if (frame1.getGlobalBounds().contains(
                            window_pause.mapPixelToCoords(
                                    Mouse::getPosition(window_pause)))) {
                    frame1.setColor(Color(255, 255, 255, 50));
                    if (event.type == Event::MouseButtonPressed) {
                        music2.openFromFile(
                                "../resources/music/Korobeyniki.mp3");
                        music2.setVolume(30.f);
                        difficulty = 0.9;
                        text_level.setString("1");
                        game_starter = 1;
                    }
                } else
                    frame1.setColor(Color(255, 255, 255, 255));

                if (frame2.getGlobalBounds().contains(
                            window_pause.mapPixelToCoords(
                                    Mouse::getPosition(window_pause)))) {
                    frame2.setColor(Color(255, 255, 255, 50));
                    if (event.type == Event::MouseButtonPressed) {
                        music2.openFromFile("../resources/music/Believer.mp3");
                        music2.setVolume(30.f);
                        difficulty = 0.5;
                        text_level.setString("2");
                        game_starter = 1;
                    }
                } else
                    frame2.setColor(Color(255, 255, 255, 255));

                if (frame3.getGlobalBounds().contains(
                            window_pause.mapPixelToCoords(
                                    Mouse::getPosition(window_pause)))) {
                    frame3.setColor(Color(255, 255, 255, 50));
                    if (event.type == Event::MouseButtonPressed) {
                        music2.openFromFile(
                                "../resources/music/Smeshariki.mp3");
                        music2.setVolume(30.f);
                        difficulty = 0.15;
                        text_level.setString("3");
                        game_starter = 1;
                    }
                } else
                    frame3.setColor(Color(255, 255, 255, 255));
            }

            window_pause.draw(Initback);
            window_pause.draw(button_convex);
            window_pause.draw(level_txt_1);
            window_pause.draw(frame1);
            window_pause.draw(level_txt_2);
            window_pause.draw(frame2);
            window_pause.draw(level_txt_3);
            window_pause.draw(frame3);
            window_pause.draw(level_txt);
            window_pause.display();
        }
        game_starter = 0;
        music2.setLoop(true);
        music2.play();
        float time;
        RenderWindow window(VideoMode(445, 765), "Tetris.exe");
        while (window.isOpen() && (game_pause != 1)) {
            if (music2.getStatus() == Music::Stopped) {
                music2.play();
            }
            if (turn_off_drawing == 0)
                time = clock.getElapsedTime().asSeconds();
            else
                time = 0;
            clock.restart();
            timer += time;
            timer2 += time;

            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    return 0;
                if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::Up) {
                        if (!rotatePressed) {
                            rotate = true;
                            rotatePressed = true;
                        }
                    } else if (event.key.code == Keyboard::Left) {
                        if (!leftPressed) {
                            dx = -1;
                            leftPressed = true;
                        }
                    } else if (event.key.code == Keyboard::Right) {
                        if (!rightPressed) {
                            dx = 1;
                            rightPressed = true;
                        }
                    }
                } else if (event.type == Event::KeyReleased) {
                    if (event.key.code == Keyboard::Up) {
                        rotatePressed = false;
                    } else if (event.key.code == Keyboard::Left) {
                        dx = 0;
                        leftPressed = false;
                    } else if (event.key.code == Keyboard::Right) {
                        dx = 0;
                        rightPressed = false;
                    }
                } else if (event.type == Event::MouseButtonPressed) {
                    if (song.getGlobalBounds().contains(
                                event.mouseButton.x, event.mouseButton.y)
                        || song1.getGlobalBounds().contains(
                                event.mouseButton.x, event.mouseButton.y)) {
                        if (isPlaying) {
                            music2.setVolume(0.f);
                            isPlaying = false;
                        } else {
                            music2.setVolume(30.f);
                            isPlaying = true;
                        }
                    }
                }
            }

            if (retry_button.getGlobalBounds().contains(
                        window.mapPixelToCoords(Mouse::getPosition(window)))
                || (home_button.getGlobalBounds().contains(
                        window.mapPixelToCoords(Mouse::getPosition(window))))) {
                if (retry_button.getGlobalBounds().contains(
                            window.mapPixelToCoords(
                                    Mouse::getPosition(window))))
                    retry_button.setColor(Color(255, 255, 255, 50));
                else
                    home_button.setColor(Color(255, 255, 255, 50));
                if ((event.type == Event::MouseButtonPressed)) {
                    for (int i = 0; i < 4; i++) {
                        a[i].x = figures[n][i] % 2 + 4;
                        if (n == 0)
                            a[i].y = figures[n][i] / 2;
                        else
                            a[i].y = figures[n][i] / 2 - 1;
                    }
                    for (int i = 0; i < M; i++) {
                        for (int j = 0; j < N; j++) {
                            field[i][j] = 0;
                        }
                    }
                    counter = 0;
                    turn_off_drawing = 0;
                    timer2 = 0;
                    if ((home_button.getGlobalBounds().contains(
                                window.mapPixelToCoords(
                                        Mouse::getPosition(window))))) {
                        window.close();
                        music2.setVolume(0.f);
                    } else
                        music2.play();
                }

            } else {
                home_button.setColor(Color(255, 255, 255, 255));
                retry_button.setColor(Color(255, 255, 255, 255));
            }
            if (Keyboard::isKeyPressed(Keyboard::Down))
                delay = 0.05;

            window.clear(Color::Blue);
            bkground.setPosition(0.f, 0.f);
            level_txt.setPosition(285, 320);
            window.draw(bkground);
            window.draw(net);

            fig_dx_movement(a, dx);

            bool checkPassed1 = true;
            for (int i = 0; i < 4; i++) {
                if (a[i].x < 0 || a[i].x >= 10 || a[i].y >= 20
                    || field[a[i].y][a[i].x]) {
                    checkPassed1 = false;
                    break;
                }
            }
            if (!checkPassed1) {
                for (int i = 0; i < 4; i++)
                    a[i] = b[i];
            }

            if (rotate) {
                fig_rotation(a);
            }

            text2.setString(s_count);
            text2.setPosition(375.f, 38.f);

            text_game_over.setString("GAME OVER");
            text_game_over.setPosition(80.f, 300.f);

            line_kill(field, counter);

            bool checkPassed = true;
            for (int i = 0; i < 4; i++) {
                if (a[i].x < 0 || a[i].x >= 10 || a[i].y >= 20
                    || field[a[i].y][a[i].x]) {
                    checkPassed = false;
                    break;
                }
            }
            if (!checkPassed) {
                for (int i = 0; i < 4; i++)
                    a[i] = b[i];
            }
            if (timer > delay) {
                for (int i = 0; i < 4; i++) {
                    b[i] = a[i];
                    a[i].y += 1;
                }
                for (int i = 0; i < 4; i++) {
                    if ((a[i].x < 0 || a[i].x >= 10 || a[i].y >= 20)
                        || (field[a[i].y][a[i].x])) {
                        for (int i = 0; i < 4; i++)
                            field[b[i].y][b[i].x] = colorNum;
                        colorNum = 1 + rand() % 7;
                        n = queue[0];
                        test_q += 1;

                        for (int i = 0; i < 4; i++) {
                            a[i].x = figures[n][i] % 2 + 4;
                            if (n == 0)
                                a[i].y = figures[n][i] / 2;
                            else
                                a[i].y = figures[n][i] / 2 - 1;
                        }
                        queue[0] = queue[1];
                        colorNum = figureColors[queue[0]];
                        queue[1] = rand() % 7;
                        for (int i = 0; i < 4; i++) {
                            a_next[i].x = figures[queue[0]][i] % 2;
                            a_next[i].y = figures[queue[0]][i] / 2;
                        }
                        if (turn_off_drawing == 0)
                            counter++;
                    }
                }
                timer = 0;
            }

            s_count = to_string(counter);
            text_time.setString(to_string(timer2));
            text_time2.setString("TIME");
            window.draw(text2);
            window.draw(text_time);
            window.draw(text_time2);
            window.draw(text_test3);
            window.draw(score_txt);
            window.draw(next_ramk);
            window.draw(next_txt);
            window.draw(level_txt);
            window.draw(text_level);
            window.draw(home_button);

            if (isPlaying) {
                window.draw(song1);
            } else {
                window.draw(song);
            }
            if (beginGame) {
                beginGame = false;
                n = rand() % 7;
                for (int i = 0; i < 4; i++) {
                    a[i].x = figures[n][i] % 2 + 4;
                    a[i].y = figures[n][i] / 2;
                }
            }

            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (field[3][j] > 0) {
                        turn_off_drawing = 1;
                        music2.stop();
                        isPlaying = false;
                        window.draw(text_game_over);
                    }

                    if (field[i][j] == 0)
                        continue;
                    kub.setTextureRect(IntRect(field[i][j] * 27, 0, 27, 27));
                    kub.setPosition(j * 27, i * 27);
                    if (turn_off_drawing == 0) {
                        window.draw(kub);
                    }
                }
            }

            drawFigure(
                    window,
                    kub,
                    kub_next,
                    colorNum,
                    a,
                    a_next,
                    figureColors,
                    queue,
                    turn_off_drawing);

            dx = 0;
            rotate = 0;
            delay = difficulty;
            window.draw(retry_button);
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Up) {
                    window.draw(arrow_up);
                } else if (event.key.code == Keyboard::Left) {
                    window.draw(arrow_left);
                } else if (event.key.code == Keyboard::Right) {
                    window.draw(arrow_right);
                } else if (event.key.code == Keyboard::Down)
                    window.draw(arrow_down);
            }

            window.draw(arrow_frame);
            window.display();
        }
    }
    return 0;
}
