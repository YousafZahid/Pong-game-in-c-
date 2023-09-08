////#include<iostream>
////#include<SFML/Audio/Sound.hpp>
////#include<SFML/Audio.hpp>
////#include"render.h"
////using  namespace sf;
////using namespace std;
////
////
////int main()
////{
////    sf::SoundBuffer buf;
////
////    if (!buf.loadFromFile("pong-audio.wav"))
////    {
////        std::cerr << "Fatal error: Could not load sound file.";
////    }
////    sf::Sound sound(buf);
////    sound.play();
////    render r;
////    r.option();
////    system("pause");
////    return 0;
////}
//
//
//
//#include<iostream>
//#include<sstream>
//#include<SFML/Graphics.hpp>
//#include<SFML/Audio/Sound.hpp>
//
//#include<SFML/Audio.hpp>
//#include<windows.h>
////#include"mainmenu.h"
//using namespace std;
//sf::Text Stext;
//sf::Text Stext1;
//std::ostringstream s1;
//std::ostringstream s2;
//int flag = 0;
//double computerPlayerSpeed = 25;
//int counterP = 0;
//int score1 = 0;
//int score2 = 0;
//int count1 = 0;
//class Shape
//{
//public:
//    sf::RectangleShape rect;
//    sf::RectangleShape rect2;
//    sf::RectangleShape line;
//    sf::RectangleShape line1;
//    sf::CircleShape circle;
//    /*sf::Vector2f circlePosition;*/
//    // player 1
//    void Rectangle1()
//    {
//        rect.setSize(sf::Vector2f(10.f, 80.f));
//        rect.setPosition(sf::Vector2f(35.f, 265.f));
//        rect.setFillColor(sf::Color::Yellow);
//    }
//    // player 2
//    void Rectangle2()
//    {
//        rect2.setSize(sf::Vector2f(10.f, 80.f));
//        rect2.setPosition(sf::Vector2f(750.f, 265.f));
//        rect2.setFillColor(sf::Color::Yellow);
//    }
//    // ball
//    void Circle()
//    {
//        circle.setRadius(7);
//        // sf::Vector2f(400.f, 300.f)
//        sf::Vector2f circlePosition(400.f, 300.f);
//        circle.setPosition(circlePosition);
//        circle.setFillColor(sf::Color::Red);
//        circle.setOutlineThickness(1.f);
//    }
//    // upper border line
//    void Line()
//    {
//        line.setSize(sf::Vector2f(800.f, 10.f));
//        line.setFillColor(sf::Color::Green);
//    }
//    // lower border line
//    void Line1()
//    {
//        line1.setSize(sf::Vector2f(800.f, 10.f));
//        line1.setPosition(sf::Vector2f(0.f, 592.f));
//        line1.setFillColor(sf::Color::Green);
//    }
//};
//class Move
//{
//protected:
//    float speedX1;
//    float speedY1;
//    sf::Vector2f circlePosition;
//    sf::Vector2f rectanglePos1;
//    sf::Vector2f rectanglePos2;
//    Shape sp;
//public:
//    sf::CircleShape circle1;
//    sf::RectangleShape rectangle1;
//    sf::RectangleShape rectangle2;
//    sf::FloatRect getPositionR1()
//    {
//        return rectangle1.getGlobalBounds();
//    }
//    sf::FloatRect getPositionR2()
//    {
//        return rectangle2.getGlobalBounds();
//    }
//    sf::RectangleShape getshapeR1()
//    {
//        return rectangle1;
//    }
//    sf::RectangleShape getshapeR2()
//    {
//        return rectangle2;
//    }
//    sf::FloatRect getPositionC()
//    {
//        return circle1.getGlobalBounds();
//    }
//    sf::CircleShape getshapeC()
//    {
//        return circle1;
//    }
//    Move()
//    {
//        speedX1 = 3;
//        speedY1 = 3;
//        
//    }
//    void circle1shape()
//    {
//        sf::Vector2f circlePosition(400.f, 300.f);
//        circle1.setPosition(circlePosition);
//        circle1.setRadius(10);
//        circle1.setFillColor(sf::Color::Red);
//        circle1.setOutlineThickness(1.f);
//    }
//    void rect1shape()
//    {
//        sf::Vector2f rectanglePos1(35.f, 265.f);
//        rectangle1.setSize(sf::Vector2f(10.f, 80.f));
//        rectangle1.setPosition(rectanglePos1);
//        rectangle1.setFillColor(sf::Color::Yellow);
//    }
//    void rect2shape()
//    {
//        sf::Vector2f rectanglePos2(750.f, 265.f);
//        rectangle2.setSize(sf::Vector2f(10.f, 80.f));
//        rectangle2.setPosition(rectanglePos2);
//        rectangle2.setFillColor(sf::Color::Yellow);
//    }
//
//    void MovementBall()
//    {
//        // Movement of Ball
//        circlePosition.x += speedX1;
//        circlePosition.y += speedY1;
//        circle1.setPosition(circlePosition);
//        // when ball strike with left wall then come to centre and rectangle shapes also allign and update the score of playerB
//        if (circlePosition.x < 0)
//        {
//           // music2.play();
//            circlePosition.x = 400;
//            circlePosition.y = 300;
//            speedX1 = 3;
//            speedY1 = 3;
//            sf::Vector2f rectanglePos2(750.f, 265.f);
//            sf::Vector2f rectanglePos1(35.f, 265.f);
//            rectangle1.setPosition(rectanglePos1);
//            rectangle2.setPosition(rectanglePos2);
//            score2++;
//            s2.str("");
//            s2 << "PlayerB:" << score2;
//            Stext1.setString(s2.str());
//            Sleep(500);
//            if (rand() % 2 == 1)
//            {
//                speedY1 = speedY1 * -1;
//            }
//        }
//        // when ball strike with right wall then come to centre and rectangle shapes also allign and update the score of playerA
//        if (circlePosition.x > 800 - 20)
//        {
//           // music2.play();
//            circlePosition.x = 400;
//            circlePosition.y = 300;
//            speedX1 = 3;
//            speedY1 = 3;
//            sf::Vector2f rectanglePos2(750.f, 265.f);
//            sf::Vector2f rectanglePos1(35.f, 265.f);
//            rectangle1.setPosition(rectanglePos1);
//            rectangle2.setPosition(rectanglePos2);
//            score1++;
//            s1.str("");
//            s1 << "PlayerA:" << score1;
//            Stext.setString(s1.str());
//            Sleep(500);
//            if (rand() % 2 == 2)
//            {
//                speedX1 = speedX1 * -1;
//            }
//        }
//        // when ball strike with upper and lower wall it bounce back
//        if (circlePosition.y < 0 || circlePosition.y>600 - 20)
//        {
//           // music1.play();
//            speedY1 = speedY1 * -1;
//        }
//        // bounce ball when collapse with players
//        if (getPositionR1().intersects(getPositionC()))
//        {
//          //  music1.play();
//            speedX1 = speedX1 * -1 +1;
//
//        }
//        if (getPositionR2().intersects(getPositionC()))
//        {
//          //  music1.play();
//            speedX1 = speedX1 * -1-1;
//        }
//        // computer mode--> movement of computer player
//        if (flag == 1)
//        {
//            if (getPositionC().top > (getPositionR2().top) + 60)
//            {
//                if (counterP % 60 == 0)
//                {
//                    rectangle2.move(0, 100);
//                }
//            }
//            if (getPositionC().top < (getPositionR2().top) + 60)
//            {
//                if (counterP % 60 == 0)
//                {
//                    rectangle2.move(0, -100);
//                }
//            }
//            if (circlePosition.x > 800)
//            {
//
//                computerPlayerSpeed = computerPlayerSpeed * -1;
//            }
//            counterP++;
//        }
//    }
//    void MovementRect()
//    {
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
//        {
//            if (flag == 0)
//            {
//                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
//                {
//                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && rectangle2.getPosition().y == 10)
//                    {
//                        rectangle2.move(0, 0);
//                    }
//                    else
//                        rectangle2.move(0, -5);
//                }
//            }
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
//            {
//                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && rectangle1.getPosition().y == 10)
//                {
//                    rectangle1.move(0, 0);
//                }
//                else
//                    rectangle1.move(0, -5);
//            }
//        }
//        // movement of players downward
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
//        {
//            if (flag == 0)
//            {
//                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
//                {
//                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && rectangle2.getPosition().y == 510)
//                    {
//                        rectangle2.move(0, 0);
//                       
//                    }
//                    else
//                    {
//                        rectangle2.move(0, 5);
//                    }
//                }
//            }
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
//            {
//                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && rectangle1.getPosition().y == 510)
//                {
//                    rectangle1.move(0, 0);
//                }
//                else
//                {
//                    
//                    rectangle1.move(0, 5);
//                }
//            }
//        }
//    }
//};
//class Game :public Shape, public Move
//{
//private:
//    sf::Event ev;
//    Shape sp;
//    sf::Font fontA;
//public:
//
//    sf::RenderWindow* window;
//    sf::Text txtP;
//    sf::Text txtW;
//    sf::Text txtW1;
//    sf::Texture texture;
//    sf::Texture texture1;
//    sf::RectangleShape back;
//    sf::RectangleShape backGame;
//    void initialize()
//    {
//        /*window = nullptr;*/
//        window = new sf::RenderWindow(sf::VideoMode(800, 600), "PONG");
//    }
//    void Window()
//    {
//        window = new sf::RenderWindow(sf::VideoMode(800, 600), "PONG");
//        window->setFramerateLimit(40);
//        fontA.loadFromFile("C:\\Users\\zaibi\\OneDrive\\Desktop\\fonts\\BOD_R.ttf");
//        texture.loadFromFile("C:/Users/zaibi/Downloads/photo.jpg");
//        texture1.loadFromFile("gameback.jpg");
//    }
//    // show score of player1 on screen
//    void score()
//    {
//        s1 << "PlayerA:" << score1;
//        Stext.setCharacterSize(45);
//        Stext.setPosition(sf::Vector2f(10, 10));
//        Stext.setFont(fontA);
//        Stext.setFillColor(sf::Color::White);
//        Stext.setString(s1.str());
//
//    }
//    // show score of player2 on screen
//    void Score2()
//    {
//        s2 << "PlayerB:" << score2;
//        Stext1.setCharacterSize(45);
//        Stext1.setPosition(sf::Vector2f(590, 10));
//        Stext1.setFont(fontA);
//        Stext1.setFillColor(sf::Color::White);
//        Stext1.setString(s2.str());
//
//    }
//    // Pause Messege
//    void PauseMessege()
//    {
//        window->clear(sf::Color::Red);
//        txtP.setFont(fontA);
//        txtP.setString("Game Over");
//        txtP.Bold;
//        txtP.setPosition(270, 180);
//        txtP.setCharacterSize(60);
//        txtP.setFillColor(sf::Color::White);
//    }
//    // Display Winner
//    void Winner()
//    {
//        if (score1 == 5)
//        {
//            if (count1 == 0)
//            {
//               // music3.play();
//            }
//            count1++;
//            PauseMessege();
//            BackOver();
//            txtW.setFont(fontA);
//            txtW.setString("PlayerA Is Winner!");
//            txtW.Bold;
//            txtW.setPosition(180, 300);
//            txtW.setCharacterSize(60);
//            txtW.setFillColor(sf::Color::White);
//            window->draw(back);
//            window->draw(txtP);
//            window->draw(txtW);
//
//        }
//        if (score2 == 5)
//        {
//            if (count1 == 0)
//            {
//               // music3.play();
//            }
//            count1++;
//            PauseMessege();
//            BackOver();
//            txtW1.setFont(fontA);
//            txtW1.setString("PlayerB Is Winner!");
//            txtW1.Bold;
//            txtW1.setPosition(180, 300);
//            txtW1.setCharacterSize(60);
//            txtW1.setFillColor(sf::Color::White);
//            window->draw(back);
//            window->draw(txtW1);
//            window->draw(txtP);
//        }
//    }
//    // Background of Game Over Screen
//    void BackOver()
//    {
//        back.setSize(sf::Vector2f(800, 600));
//        texture.setSmooth(false);
//        back.setTexture(&texture);
//    }
//    void backgroundimg()
//    {
//        backGame.setSize(sf::Vector2f(800, 600));
//        texture1.setSmooth(false);
//        backGame.setTexture(&texture1);
//    }
//    // default constructor
//    Game()
//    {
//        initialize();
//        Window();
//        sp.Line();
//        sp.Line1();
//        circle1shape();
//        rect1shape();
//        rect2shape();
//        score();
//        Score2();
//        backgroundimg();
//    }
//
//    const bool Open() const
//    {
//        return this->window->isOpen();
//    }
//    // windows function
//    void Poll()
//    {
//        while (window->pollEvent(ev))
//        {
//            if (ev.type == sf::Event::Closed)
//            {
//                window->close();
//            }
//        }
//    }
//    // windows function
//    void update()
//    {
//        Poll();
//        cout << "Mouse position " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << endl;
//    }
//    // function to draw all shapes
//
//    void Render()
//    {
//        if (count1 == 0)
//        {
//            /*window->clear(sf::Color::Blue);*/
//            window->draw(backGame);
//            window->draw(sp.rect);
//            window->draw(sp.rect2);
//            window->draw(sp.line);
//            window->draw(sp.line1);
//            MovementBall();
//            window->draw(circle1);
//            MovementRect();
//            window->draw(rectangle1);
//            window->draw(rectangle2);
//            window->draw(Stext);
//            window->draw(Stext1);
//        }
//        Winner();
//        window->display();
//    }
//    // destructor
//    ~Game()
//    {
//        if (window != nullptr)
//        {
//            delete window;
//        }
//    }
//};
//
//
//
//int main()
//{
//    sf::SoundBuffer buf;
//    //intro a;
//    //a.intro1();
//        if (!buf.loadFromFile("pong-audio.wav"))
//        {
//            std::cerr << "fatal error: could not load sound file.";
//        }
//        sf::Sound sound(buf);
//        sound.play();
//    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");
//    // Change Background of start screen
//
//    sf::RectangleShape back;
//    back.setSize(sf::Vector2f(800, 600));
//    sf::Texture texture;
//    texture.loadFromFile("C:/Users/zaibi/Downloads/photo1.jpg");
//    texture.setSmooth(false);
//    back.setTexture(&texture);
//    // Starting Text on screen welcome note
//
//    sf::Font font;
//    font.loadFromFile("C:\\Users\\zaibi\\OneDrive\\Desktop\\fonts\\ARLRDBD.ttf");
//    sf::Text txt;
//    txt.setFont(font);
//    txt.setString("Welcome To PONG");
//    txt.Bold;
//    txt.setPosition(150, 250);
//    txt.setCharacterSize(60);
//    txt.setFillColor(sf::Color::White);
//    // press enter to play
//
//    sf::Font font1;
//    font1.loadFromFile("C:\\Users\\zaibi\\OneDrive\\Desktop\\fonts\\ARLRDBD.ttf");
//    sf::Text txt1;
//    txt1.setFont(font1);
//    txt1.setString("PRESS ENTER TO PLAY VS MODE");
//    txt1.Bold;
//    txt1.setPosition(80, 400);
//    txt1.setCharacterSize(40);
//    txt1.setFillColor(sf::Color::Cyan);
//    // press Rshift to play with computer
//    sf::Font font2;
//    font2.loadFromFile("C:\\Users\\zaibi\\OneDrive\\Desktop\\fonts\\ARLRDBD.ttf");
//    sf::Text txt2;
//    txt2.setFont(font2);
//    txt2.setString("PRESS RSHIFT TO PLAY WITH COMP.");
//    txt2.Bold;
//    txt2.setPosition(40, 500);
//    txt2.setCharacterSize(40);
//    txt2.setFillColor(sf::Color::Cyan);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//        /*window.clear();*/
//        window.draw(back);// welcome note background
//        window.draw(txt); // welcome note
//        window.draw(txt1);// enter key note
//        window.draw(txt2);//Right Shift key note
//
//
//
//        window.display();
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) == true)
//        {
//            break;
//        }
//        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift) == true)
//        {
//            flag = 1;
//            break;
//        }
//    }
//    // close previous window of welcome note
//    window.close();
//    // display game window
//    Game g;
//    while (g.Open())
//    {
//        g.update();
//        g.Render();
//    }
//   // return 0;
//}