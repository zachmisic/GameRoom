#include "CheckersTest.h"


void CheckersTest::ResetBoardTest()
{
    Test.ResetBoard();
    std::cout << "Reset Board tested successfully\n";
}

void CheckersTest::run()
{
    ResetBoardTest();
    PromoteTest();
    getColorTest();

    std::cout << "All tests successful\n";
}

void CheckersTest::PromoteTest()
{
    Test.promote();
    std::cout << "Promote test was successfull\n";
}

void CheckersTest::getColorTest()
{
    if(Test.m_Player1->isWhite() == Test.m_Player2->isWhite())
    {
        std::cout << "The COlor assignment is wrong, Color test failed\n";
    }
    else
    {
        std::cout << "The color test was successfull\n";
    }
    
}