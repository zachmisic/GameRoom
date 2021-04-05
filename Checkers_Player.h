/**
* @Checkers_Player.h
* @Author: Andrew Hughes
* @Holds methods for checkers player
**/

#ifndef CHECKERS_PLAYER_H
#define CHECKERS_PLAYER_H

#include <iostream>

class Checkers_Player
{
    public:
    	/**
		* @pre The class is created and a board and color type is provided
		* @post The class is created
		* @param char*** board, the board that the player is using
        * @param bool is_Black, is the player using the black pieces
		* @return N/A
		**/
        Checkers_Player(char*** board, bool is_Black);

        /**
		* @pre The class must be destroyed
		* @post The class is destroyed
		* @return N/A
		**/
        ~Checkers_Player();

		/**
		* @pre we need to know if the player is usign white pieces
		* @post we know if the player is using white pieces
		* @return bool, return true if we use white pieces, else return false
		**/
        bool isWhite();

        /**
		* @pre a piece needs to be moved
		* @post A piece is moved
		* @return void
		**/
        void movePiece();

        

    private:
        char*** m_Board;
        bool isBlack;

        /**
		* @pre we need to know if row x, col y, is a valid position
		* @post we know if the position is valid
		* @param int Row, the Row that we are checking
        * @param int Col, the column that we are checking
		* @return bool, if the position is valid
		**/
        bool validPosition(int Row, int Col);

		/**
		* @pre we need to move a piece from one position to another
		* @post we have moved a piece from one position to another
		* @param int Row1, the starting row
        * @param int Col1, the starting column
        * @param int Row2, the ending Row
        * @param int Col2, the ending Column
		* @return bool, if the piece was successfully moved
		**/
        bool replace(int Row1, int Col1, int Row2, int Col2);

        /**
		* @pre we need to know if a move is valid
		* @post we know if a move is valid
		* @param int Row1, the starting row
        * @param int Col1, the starting column
        * @param int Row2, the ending Row
        * @param int Col2, the ending Column
		* @return bool, if the move was successful
		**/
        bool validMove(int Row1, int Col1, int Row2, int Col2);

        /**
		* @pre we need to know if a jump is valid
		* @post we know if a jump is valid
		* @param int Row1, the starting row
        * @param int Col1, the starting column
        * @param int Row2, the jumped row
        * @param int Col2, the jumped Column
		* @return bool, the jump is valid
		**/
        bool validJump(int Row1, int Col1, int Row2, int Col2);

        /**
		* @pre we need to jump a piece
		* @post we have jumped a piece
		* @param int Row1, the starting row
        * @param int Col1, the starting column
        * @param int Row2, the jumped Row
        * @param int Col2, the jumped Column
		* @return bool, if the piece was successfully jumped
		**/
        void jump(int& Row1, int& Col1, int& Row2, int& Col2);

        /**
		* @pre we need to know if we can move a piece
		* @post we know if a piece can move
		* @param int Row1, the row we check
        * @param int Col1, the column we check
		* @return bool, if the piece can move
		**/
        bool canMove(int Row1, int Col1);
};  


#endif