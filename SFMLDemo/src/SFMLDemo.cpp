#include <SFML/Graphics.hpp>

int main()
{
    /*设置窗口 大小200x200，标题SFMLDemo*/
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFMLDemo");
    /*创建图形 圆 半径 100 像素*/
    sf::CircleShape shape(100.f);
    /*设置填充颜色 蓝*/
    shape.setFillColor(sf::Color::Blue);

    /*绘制循环(窗口未关闭时)*/
    while (window.isOpen())
    {

        sf::Event event;
        /*收取事件*/
        while (window.pollEvent(event))
        {
            /*事件为关闭窗口时，关闭窗口，退出程序*/
            if (event.type == sf::Event::Closed)
                window.close();
        }

        /*清屏*/
        window.clear();
        /*绘制*/
        window.draw(shape);
        /*显示*/
        window.display();
    }

    return 0;
}