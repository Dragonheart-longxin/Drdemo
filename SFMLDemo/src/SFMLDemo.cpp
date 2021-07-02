#include <SFML/Graphics.hpp>

int main()
{
    /*���ô��� ��С200x200������SFMLDemo*/
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFMLDemo");
    /*����ͼ�� Բ �뾶 100 ����*/
    sf::CircleShape shape(100.f);
    /*���������ɫ ��*/
    shape.setFillColor(sf::Color::Blue);

    /*����ѭ��(����δ�ر�ʱ)*/
    while (window.isOpen())
    {

        sf::Event event;
        /*��ȡ�¼�*/
        while (window.pollEvent(event))
        {
            /*�¼�Ϊ�رմ���ʱ���رմ��ڣ��˳�����*/
            if (event.type == sf::Event::Closed)
                window.close();
        }

        /*����*/
        window.clear();
        /*����*/
        window.draw(shape);
        /*��ʾ*/
        window.display();
    }

    return 0;
}