

class Grid
{
public:
    void init(int x, int y);    // all dead
    void setAlive(int x, int y);
    bool isAlive(int x, int y) const;
    int numberOfAliveAround(int x, int y) const;

private:
    int _x;
    int _y;
    char *_grid;
};

void nextGeneration(const Grid &prev,
                    Grid &next);



