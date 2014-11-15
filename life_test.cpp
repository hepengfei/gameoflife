
#include <gtest/gtest.h>

#include "life.hpp"

class GridTest : public testing::Test
{
public:
    GridTest(){}
    ~GridTest() {}

    void SetUp() {
        // *....
        // ..*..
        // ...*.
        // .....
        grid.init(4,5);
        grid.setAlive(0,0);
        grid.setAlive(1,2);
        grid.setAlive(2,3);
    }

    void TearDown() {
    }

protected:
    Grid grid;
};

TEST_F(GridTest, isAlive)
{
    EXPECT_TRUE(grid.isAlive(0,0));
    EXPECT_TRUE(grid.isAlive(1,2));
    EXPECT_TRUE(grid.isAlive(2,3));

    EXPECT_FALSE(grid.isAlive(0,1));
    EXPECT_FALSE(grid.isAlive(2,1));
    EXPECT_FALSE(grid.isAlive(3,2));
}


