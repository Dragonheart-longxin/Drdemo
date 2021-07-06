#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

struct Cell
{
    int x;
    int y;
    bool isLive = false;
};

class CellMap;

int main()
{
    vector<Cell> cells;
    vector<Cell> newCells;

    cells.push_back({ 0, 0, true });
    cells.push_back({ 0, 0, true });
    cells.push_back({ 0, 0, true });
    cells.push_back({ 0, 0, true });
    cells.push_back({ 0, 0, true });
    cells.push_back({ 0, 0, true });

    sf::RenderWindow window(sf::VideoMode(1280, 720), "GameOfLife by DragonheartLX");


    return 0;
}

void CellMap::update(vector<Cell> cells, int deep, vector<Cell> &nextGen)
{
    vector<Cell> roundCells;

    for (Cell cell: cells)
    {
        roundCells.push_back({ cell.x - 1, cell.y + 1 , true });
        roundCells.push_back({ cell.x    , cell.y + 1 , true });
        roundCells.push_back({ cell.x + 1, cell.y + 1 , true });
        roundCells.push_back({ cell.x - 1, cell.y     , true });
        roundCells.push_back({ cell.x + 1, cell.y     , true });
        roundCells.push_back({ cell.x - 1, cell.y - 1 , true });
        roundCells.push_back({ cell.x    , cell.y - 1 , true });
        roundCells.push_back({ cell.x + 1, cell.y - 1 , true });

        if (deep == 0)
        {
            int count = 0;
            for (Cell live: cells)
            {
                for (Cell round: roundCells)
                {
                    if (round.isLive) 
                        ++count;
                }

                if (cell.isLive)
                {
                    if (count == 2 || count == 3)
                        nextGen.push_back(cell);


                }else if (!cell.isLive)
                {
                    if (count == 3)
                        nextGen.push_back({ cell.x, cell.y, true });
                }

            }
        }
        else if (deep > 0) {

            update(roundCells, deep--, nextGen);

        }
    }

}

void CellMap::clear(vector<Cell>& cells)
{
    for (unsigned int i = 0; i < cells.size(); i++)
    {
        for (unsigned int  j = i + 1; j < cells.size(); j++)
        {
            if (cells[i].x == cells[j].x && cells[i].y == cells[j].y)
                cells.erase(cells.begin() + j);
        }
    }
}

class CellMap: public sf::RectangleShape{
private:
    vector<Cell> _cells;

public:
    void update(vector<Cell> cells, int deep, vector<Cell>& nextGen);
    void clear(vector<Cell>& cells);
    void draw();
};