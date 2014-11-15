
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
}

