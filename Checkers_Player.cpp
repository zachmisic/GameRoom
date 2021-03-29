#include "Checkers_Player.h"


Checkers_Player::Checkers_Player(char*** board, bool is_Black)
{
    m_Board = board;
    isBlack = is_Black;
}

Checkers_Player::~Checkers_Player()
{}

bool Checkers_Player::isWhite()
{
    return !isBlack;
}

void Checkers_Player::movePiece()
{
    int row;
    int col;
    bool goodInput = false;

    do
    {
        std::cout << "Select a ";
        if (isBlack)
        {
            std::cout << "black";
        }
        else
        {
            std::cout << "white";
        }
        std::cout << " Piece:\nRow: ";
        std::cin >> row;
        std::cout << "Col: ";
        std::cin >> col;

        row--;
        col--;

        //check user input
        if (validPosition(row, col))
        {
            if(((*m_Board[row][col] == 'w' || *m_Board[row][col] == 'W') && !isBlack)
            ||((*m_Board[row][col] == 'b' || *m_Board[row][col] == 'B') && isBlack))
            {
                if(canMove(row, col))
                {
                    goodInput = true;
                }
                else
                {
                    std::cout << "That piece cannot move, pick another.\n";
                }
                
            }
            else
            {
                std::cout << "You must select one of your pieces.\n";
            }
            
        }else
        {
            std::cout << "Please input a valid square. Try again.\n";
        }        
    }while(!goodInput);

    int row2;
    int col2;
    goodInput = false;
    bool jumpChain = false;
    char input;

    do
    {
        std::cout << "Select a place to move to.\nRow: ";
        std::cin >> row2;
        std::cout << "Col: ";
        std::cin >> col2;

        row2--;
        col2--;

        goodInput = validMove(row, col, row2, col2);

        if(goodInput)
        {
            //now we know the input is good
            //move the piece
            if(*m_Board[row2][col2] == '-' && !jumpChain)
            {//if not jump
                replace(row, col, row2, col2);
                jumpChain = false;
            }
            else if(*m_Board[row2][col2] == '-' && jumpChain)
            {
                std::cout << "You may not move normally after jumping. Try again\n";
            }
            else
            {   //now we're jumping
                if (validJump(row, col, row2, col2))
                {
                    jump(row, col, row2, col2);
                    jumpChain = true;
                }
            }
        }

        if(jumpChain)
        {
            std::cout << "Do you wish to keep trying to jump? If so input 'y': ";
            std::cin >> input;

            if(input == 'y')
            {
                jumpChain = true;
            }
            else
            {
                jumpChain = false;
            }
        }

    } while (!goodInput || jumpChain);
}

bool Checkers_Player::validPosition(int Row, int Col)
{
    //check if out of bounds
    if(Row < 0 || Row > 7 || Col < 0 || Col > 7)
    {
        return false;
    }

    //check if on unallowed spaces
    if ((Row + Col) % 2 == 1)
    {
        return false;
    }

    return true;
}

bool Checkers_Player::replace(int Row1, int Col1, int Row2, int Col2)
{
    if (validPosition(Row1, Col1) && validPosition(Row2, Col2))
    {
        *m_Board[Row2][Col2] = *m_Board[Row1][Col1];
        *m_Board[Row1][Col1] = '-';

        return true;
    }
    
    return false;
}

bool Checkers_Player::validMove(int Row1, int Col1, int Row2, int Col2)
{
    if(validPosition(Row2, Col2))
    {
        //if the player is white
        if (isWhite())
        {
            if ( *m_Board[Row1][Col1] == 'w' && *m_Board[Row2][Col2] != 'w' && *m_Board[Row2][Col2] != 'W')
            {
                //check new place
                if (Col2 >= Col1-1 && Col2 <= Col1+1 && Row2 == Row1-1)
                {
                    return true;
                }
                else
                {
                    std::cout << "That square is invalid for a lesser piece. try again.\n";
                }
            }
            else if(*m_Board[Row2][Col2] != 'w' && *m_Board[Row2][Col2] != 'W')
            {
                //check new place
                if (Col2 >= Col1-1 && Col2 <= Col1+1 && Row2 >= Row1-1 && Row2 <= Row1+1)
                {
                    return true;
                }
                else
                {
                    std::cout << "That square is invalid for a piece. try again.\n";
                }
            }
            else
            {
                std::cout << "that place is occupied by one of your pieces. Choose another.\n";
            }        
        }
        else
        {
            if (*m_Board[Row1][Col1] == 'b' && *m_Board[Row2][Col2] != 'b' && *m_Board[Row2][Col2] != 'B')
            {
                //check new place
                if (Col2 >= Col1-1 && Col2 <= Col1+1 && Row2 == Row1+1)
                {
                    return true;
                }
                else
                {
                    std::cout << "That square is invalid for a lesser piece. try again.\n";
                }
            }
            else if(*m_Board[Row2][Col2] != 'b' && *m_Board[Row2][Col2] != 'B')
            {
                //check new place
                if (Col2 >= Col1-1 && Col2 <= Col1+1 && Row2 >= Row1-1 && Row2 <= Row1+1)
                {
                    return true;
                }
                else
                {
                    std::cout << "That square is invalid for a piece. try again.\n";
                }
            }
            else
            {
                std::cout << "that place is occupied by one of your pieces. Choose another.\n";
            }
                
        }
    }
    else
    {
        std::cout << "Please input a valid square. Try again.\n";
    }

    return false;
}

bool Checkers_Player::validJump(int Row1, int Col1, int Row2, int Col2)
{
    if (Row1 - Row2 < 0 && Col1 - Col2 < 0)
    {
        if(validPosition(Row2+1, Col2+1))
        {
            if (*m_Board[Row2+1][Col2+1] == '-')
            {
                return true;
            }
        }
    }
    else if (Row1 - Row2 > 0 && Col1 - Col2 < 0)
    {
        if(validPosition(Row2-1, Col2+1))
        {
            if (*m_Board[Row2-1][Col2+1] == '-')
            {
                return true;
            }
        }
    }
    else if (Row1 - Row2 < 0 && Col1 - Col2 > 0)
    {
        if(validPosition(Row2+1, Col2-1))
        {
            if (*m_Board[Row2+1][Col2-1] == '-')
            {
                return true;
            }
        }
    }
    else if (Row1 - Row2 > 0 && Col1 - Col2 > 0)
    {
        if(validPosition(Row2-1, Col2-1))
        {
            if (*m_Board[Row2-1][Col2-1] == '-')
            {
                return true;
            }
        }
    }
    
    return false;
}

void Checkers_Player::jump(int& Row1, int& Col1, int& Row2, int& Col2)
{
    if (Row1 - Row2 < 0 && Col1 - Col2 < 0)
    {
        //move the first part
        replace(Row1, Col1, Row2, Col2);
                
        //set the mid position
        Row1 = Row2;
        Col1 = Col2;
        
        //set next position
        Row2--;
        Col2--;

        //final move
        replace(Row1, Col1, Row2, Col2);

        //set the final position
        Row1 = Row2;
        Col1 = Col2;
    }
    else if (Row1 - Row2 > 0 && Col1 - Col2 < 0)
    {
        //move the first part
        replace(Row1, Col1, Row2, Col2);
                
        //set the mid position
        Row1 = Row2;
        Col1 = Col2;
        
        //set next position
        Row2++;
        Col2--;

        //final move
        replace(Row1, Col1, Row2, Col2);

        //set the final position
        Row1 = Row2;
        Col1 = Col2;
    }
    else if (Row1 - Row2 < 0 && Col1 - Col2 > 0)
    {
        //move the first part
        replace(Row1, Col1, Row2, Col2);
                
        //set the mid position
        Row1 = Row2;
        Col1 = Col2;
        
        //set next position
        Row2--;
        Col2++;

        //final move
        replace(Row1, Col1, Row2, Col2);

        //set the final position
        Row1 = Row2;
        Col1 = Col2;
    }
    else if (Row1 - Row2 > 0 && Col1 - Col2 > 0)
    {
        //move the first part
        replace(Row1, Col1, Row2, Col2);
        
        //set the mid position
        Row1 = Row2;
        Col1 = Col2;
        
        //set next position
        Row2++;
        Col2++;

        //final move
        replace(Row1, Col1, Row2, Col2);

        //set the final position
        Row1 = Row2;
        Col1 = Col2;
    }
}

bool Checkers_Player::canMove(int Row1, int Col1)
{
    if(!validPosition(Row1, Col1))
    {
        return false;
    }
    if(*m_Board[Row1][Col1] == 'w')
    {
        //check if up and left is a valid position
        if(validPosition(Row1-1, Col1-1))
        {
            //check if up and left is a valid move position
            if((validMove(Row1, Col1, Row1-1, Col1-1) && *m_Board[Row1-1][Col1-1] == '-') || validJump(Row1, Col1, Row1-1, Col1-1))
            {
                return true;
            }
        }
        else if(validPosition(Row1-1, Col1+1))
        {
            if((validMove(Row1, Col1, Row1-1, Col1+1) && *m_Board[Row1-1][Col1+1] == '-') || validJump(Row1, Col1, Row1-1, Col1+1))
            {
                return true;
            }
        }
    }
    else if(*m_Board[Row1][Col1] == 'W')
    {
        //check if up and left is a valid position
        if(validPosition(Row1-1, Col1-1))
        {
            //check if up and left is a valid move position
            if((validMove(Row1, Col1, Row1-1, Col1-1) && *m_Board[Row1-1][Col1-1] == '-') || validJump(Row1, Col1, Row1-1, Col1-1))
            {
                return true;
            }
        }
        else if(validPosition(Row1-1, Col1+1))
        {
            if((validMove(Row1, Col1, Row1-1, Col1+1) && *m_Board[Row1-1][Col1+1] == '-') || validJump(Row1, Col1, Row1-1, Col1+1))
            {
                return true;
            }
        }
        else if(validPosition(Row1+1, Col1-1))
        {
            if((validMove(Row1, Col1, Row1+1, Col1-1) && *m_Board[Row1+1][Col1-1] == '-') || validJump(Row1, Col1, Row1+1, Col1-1))
            {
                return true;
            }
        }
        else if(validPosition(Row1+1, Col1+1))
        {
            if((validMove(Row1, Col1, Row1+1, Col1+1) && *m_Board[Row1+1][Col1+1] == '-') || validJump(Row1, Col1, Row1+1, Col1+1))
            {
                return true;
            }
        }
    }
    else if(*m_Board[Row1][Col1] == 'b')
    {
        if(validPosition(Row1+1, Col1-1))
        {
            if((validMove(Row1, Col1, Row1+1, Col1-1) && *m_Board[Row1+1][Col1-1] == '-') || validJump(Row1, Col1, Row1+1, Col1-1))
            {
                return true;
            }
        }
        else if(validPosition(Row1+1, Col1+1))
        {
            if((validMove(Row1, Col1, Row1+1, Col1+1) && *m_Board[Row1+1][Col1+1] == '-') || validJump(Row1, Col1, Row1+1, Col1+1))
            {
                return true;
            }
        }
    }
    else if(*m_Board[Row1][Col1] == 'B')
    {
        //check if up and left is a valid position
        if(validPosition(Row1-1, Col1-1))
        {
            //check if up and left is a valid move position
            if((validMove(Row1, Col1, Row1-1, Col1-1) && *m_Board[Row1-1][Col1-1] == '-') || validJump(Row1, Col1, Row1-1, Col1-1))
            {
                return true;
            }
        }
        else if(validPosition(Row1-1, Col1+1))
        {
            if((validMove(Row1, Col1, Row1-1, Col1+1) && *m_Board[Row1-1][Col1+1] == '-') || validJump(Row1, Col1, Row1-1, Col1+1))
            {
                return true;
            }
        }
        else if(validPosition(Row1+1, Col1-1))
        {
            if((validMove(Row1, Col1, Row1+1, Col1-1) && *m_Board[Row1+1][Col1-1] == '-') || validJump(Row1, Col1, Row1+1, Col1-1))
            {
                return true;
            }
        }
        else if(validPosition(Row1+1, Col1+1))
        {
            if((validMove(Row1, Col1, Row1+1, Col1+1) && *m_Board[Row1+1][Col1+1] == '-') || validJump(Row1, Col1, Row1+1, Col1+1))
            {
                return true;
            }
        }
    }


    return false;
}