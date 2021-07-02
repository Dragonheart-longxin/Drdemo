#include <SFML/Graphics.hpp>

struct SnakeNode
{
    float x = 0;
    float y = 0;
    SnakeNode* forward = nullptr;
    SnakeNode* next = nullptr;

    SnakeNode(float x, float y) :x(x), y(y) {};
};


class Snake
{
public:
    Snake();
    ~Snake();

    void addNode(SnakeNode* body);
    void deleteNode(SnakeNode* body);
    void drawNode(sf::RenderWindow& win);
    void draw(SnakeNode* body, sf::RenderWindow& win);
private:
    SnakeNode* head;
    SnakeNode* tail;
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "GluttonousSnake");

    Snake snake;

    /*test*/
    snake.addNode(new SnakeNode(0.f, 0.f));
    snake.addNode(new SnakeNode(10.f, 10.f));
    snake.addNode(new SnakeNode(20.f, 20.f));
    snake.addNode(new SnakeNode(30.f, 30.f));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        snake.drawNode(window);
        window.display();
    }

    return 0;
}


Snake::Snake():
    head(nullptr),
    tail(nullptr)
{
    
}

Snake::~Snake()
{
    deleteNode(head);
}

void Snake::addNode(SnakeNode* body)
{

    tail->next = body;
    body->forward = tail;
    tail = body;

}

void Snake::deleteNode(SnakeNode* body)
{
    if (body->next == nullptr)
    {
        delete body;
    }

    if (!(body->next == nullptr))
    {
        deleteNode(body->next);
    }
}

void Snake::drawNode(sf::RenderWindow& win)
{
    draw(head, win);
}

void Snake::draw(SnakeNode* body, sf::RenderWindow & win)
{
    if (body->next == nullptr)
    {
        sf::CircleShape node(10.f);
        node.setFillColor(sf::Color::Blue);
        node.setPosition(body->x, body->y);

        win.draw(node);
    }

    if (!(body->next == nullptr))
    {
        draw(body->next, win);
    }

}
