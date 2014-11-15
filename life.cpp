
#include <cstring>

#include "life.hpp"

void Grid::init(int x, int y)
{
    _x = x;
    _y = y;
    _grid = new char[_x * _y];
    std::memset(_grid, '.', _x * _y);
}

void Grid::setAlive(int x, int y)
{
    if(x >= 0 && x < _x &&
       y >= 0 && y < _y)
    {
        _grid[_x * x + y] = '*';
    }
}

bool Grid::isAlive(int x, int y) const
{
    if(x >= 0 && x < _x &&
       y >= 0 && y < _y)
    {
        return _grid[_x * x + y] == '*';
    }
    return false;
}

int Grid::numberOfAliveAround(int x, int y) const
{
    int number = 0;
    
    if(isAlive(x-1, y-1)) ++number;
    if(isAlive(x-1, y)) ++number;
    if(isAlive(x-1, y+1)) ++number;
    
    if(isAlive(x, y-1)) ++number;
    if(isAlive(x, y+1)) ++number;
    
    if(isAlive(x+1, y-1)) ++number;
    if(isAlive(x+1, y)) ++number;
    if(isAlive(x+1, y+1)) ++number;

    return number;
}

void nextGeneration(const Grid &prev,
                    Grid &next)
{
    int x = prev.x();
    int y = prev.y();

    next.init(x, y);

    for(int i=0; i<x; ++i)
    {
        for(int j=0; j<y; ++j)
        {
            int num = prev.numberOfAliveAround(i,j);
            if(prev.isAlive(i,j))
            {
                if(num == 2 || num == 3)
                {
                    next.setAlive(i,j);
                }
            }
            else
            {
                if(num == 3)
                {
                    next.setAlive(i,j);
                }
            }
        }
    }
}

