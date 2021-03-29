#include "Checkers.h"

Checkers::Checkers()
{
    //setup board
    m_Board = new char*[8];
    for(int i = 0; i < 8; i++)
    {
        m_Board[i] = new char[8];
    }

    ResetBoard();

    //create the players
    m_Player1 = new Checkers_Player(&m_Board, true); //player one is black
    m_Player2 = new Checkers_Player(&  m_Board, false); //player two is white
}

Checkers::~Checkers()
{
    //delete board
    for(int i = 0; i < 8; i++)
    {
        delete m_Board[i];
    }
    delete[] m_Board;


    //delete the players
    delete m_Player1;
    delete m_Player2;
}

void Checkers::ResetBoard()
{
    //empty board
        for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            m_Board[i][j] = '-';
        }
    }

    //setup Black
    for(int i = 0; i < 8; i += 2)
    {
        m_Board[0][i] = 'b';
    }

    for(int i = 1; i < 8; i += 2)
    {
        m_Board[1][i] = 'b';
    }    

    //setup White
    for(int i = 0; i < 8; i += 2)
    {
        m_Board[6][i] = 'w';
    }

    for(int i = 1; i < 8; i += 2)
    {
        m_Board[7][i] = 'w';
    }
}

void Checkers::printBoard()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            std::cout << m_Board[i][j];
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void Checkers::run()
{
    bool gameover = false;
    ResetBoard();
    do
    {
        printBoard();
        m_Player1->movePiece();
        promote();
        gameover = Gameover();

        if(!gameover)
        {
            printBoard();
            m_Player2->movePiece();
            promote();
            gameover = Gameover();
        }
    } while (!gameover);
    
    printBoard();
}

bool Checkers::Gameover()
{
    bool foundWhite = false;
    bool foundBlack = false;
    
    for(int i = 0; i<8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(m_Board[i][j] == 'w' || m_Board[i][j] == 'W')
            {
                foundWhite = true;
            }
            if(m_Board[i][j] == 'b' || m_Board[i][j] == 'B')
            {
                foundBlack = true;
            }
        }
    }

    if (foundWhite && foundBlack)
    {
        return false;
    }
    return true;
}

bool Checkers::promote()
{
    bool promoted = false;
    for(int i = 0; i < 8; i++)
    {
        if (m_Board[7][i] == 'b')
        {
            /* code */
            m_Board[7][i] = 'B';
            promoted = true;
        }

        if (m_Board[0][i] == 'w')
        {
            /* code */
            m_Board[0][i] = 'W';
            promoted = true;
        }
    }

    return promoted;
}