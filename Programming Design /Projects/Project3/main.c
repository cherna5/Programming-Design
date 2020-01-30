/*------------------------------------------------------------------------------------------
 * Pentago.c
 *
 * Author: Ubemio Romero, Cesar Hernandez
 * Class: CS 141, Spring 2017. Tues, 2pm Lab
 * System: Xcode on an Mac
 *
 * ToDo: To rebuild the game "pentago" in c program, with arrays; giving two players to
 * make a set of plays with X and O.
 *
 * For instance:
 
 | Author: Ubemio Romero, Cesar Hernandez
 | Program: #3, Pentago
 | TA: TA: Moumita Samanta, Tues 2pm
 | Feb 27, 2017
 |
 |
 |   This program represents the game pentago
 |
 |
 |
 |
 |
 |Play the two-player game of Pentago. Be the first to get 5 in a row.
 |
 |Pentago is played on a 6 by 6 board, divided into four 3 by 3
 |quadrants.  There are two players, X and O, who alternate turns.
 |The goal of each player is to get five of their pieces in a row,
 |either horizontally, vertically, or diagonally.
 |
 |Players take turns placing one of their pieces into an empty
 |space anywhere on the board, then choosing one of the four
 |board quadrants to rotate 90 degrees left or right.
 |
 |If both players get five in a row at the same time, or the
 |last move is played with no five in a row, the game is a tie.
 |If a player makes five a row by placing a piece, there is no need
 |to rotate a quadrant and the player wins immediately.
 |
 |Play online at:  https://perfect-pentago.net
 |Purchase at:     www.mindtwisterusa.com
 |
 |For each move provide four inputs:
 |row (A-F), column (1-6), quadrant (1-4), rotation direction (L or R)
 |For instance input of B32R places the next piece at B3 and then
 |would rotate quadrant 2 (upper-right) to the right (clockwise).
 |
 |At any point enter 'x' to exit the program.
 |
 |1   1 2 3 4 5 6   2
 |-----------
 |A:  . . . . . .  :A
 |B:  . . . . . .  :B
 |C:  . . . . . .  :C
 |D:  . . . . . .  :D
 |E:  . . . . . .  :E
 |F:  . . . . . .  :F
 |-----------
 |3   1 2 3 4 5 6   4
 |
 |1. Enter row, column, quadrant, direction for X: c31r
 |
 |1   1 2 3 4 5 6   2
 |-----------
 |A:  . . . . . .  :A
 |B:  . . . . . .  :B
 |C:  X . . . . .  :C
 |D:  . . . . . .  :D
 |E:  . . . . . .  :E
 |F:  . . . . . .  :F
 |-----------
 |3   1 2 3 4 5 6   4
 |
 |2. Enter row, column, quadrant, direction for O: A5 3R
 |
 |1   1 2 3 4 5 6   2
 |-----------
 |A:  . . . . O .  :A
 |B:  . . . . . .  :B
 |C:  X . . . . .  :C
 |D:  . . . . . .  :D
 |E:  . . . . . .  :E
 |F:  . . . . . .  :F
 |-----------
 |3   1 2 3 4 5 6   4
 |
 |3. Enter row, column, quadrant, direction for X: A51R
 |*** That board location is already taken.  Please retry.
 |3. Enter row, column, quadrant, direction for X: G05h
 |*** Invalid move row.  Please retry.
 |3. Enter row, column, quadrant, direction for X: c05h
 |*** Invalid move column.  Please retry.
 |3. Enter row, column, quadrant, direction for X: c25h
 |*** Selected quadrant is invalid.  Please retry.
 |3. Enter row, column, quadrant, direction for X: c21h
 |*** Quadrant rotation direction is invalid.  Please retry.
 |3. Enter row, column, quadrant, direction for X: c2 1r
 |
 |1   1 2 3 4 5 6   2
 |-----------
 |A:  X . . . O .  :A
 |B:  X . . . . .  :B
 |C:  . . . . . .  :C
 |D:  . . . . . .  :D
 |E:  . . . . . .  :E
 |F:  . . . . . .  :F
 |-----------
 |3   1 2 3 4 5 6   4
 |
 |etc ....
 |
 |10. Enter row, column, quadrant, direction for O: f2 3l
 |O has won the game!
 |
 |1   1 2 3 4 5 6   2
 |-----------
 |A:  . X X X . .  :A
 |B:  . . . X . O  :B
 |C:  . . . X O .  :C
 |D:  . . . O . .  :D
 |E:  . . O . . .  :E
 |F:  . O . . . .  :F
 |-----------
 |3   1 2 3 4 5 6   4
 |
 |Thanks for playing.  Exiting...
 |
 |
 |--------------------------------------------------------------------------------------------*/

//==============================================================================================
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

const int boardSize = 6;
const int buffer = 50;
const int maxInputChar = 4;


//==============================================================================================
void displayIdentyfingInformation()
{
    printf ("Author(s) Ubemio Romero, Cesar Hernandez\n");
    printf ("Program: #3, Pentago\n");
    printf ("TA: Moumita Samanta, Tues 2pm\n");
    printf ("Feb 27, 2017\n");
    printf ("\n");
}


//==============================================================================================
// Function to display instructions
void displayInstructions()
{
    printf("Welcome to Pentago!\n");
    printf("For each move provide four inputs:  \n");
    printf("row (A-F), column (1-6), quadrant (1-4), rotation direction (L or R)\n");
    printf("For instance input of B32R places the next piece at B3 and then ");
    printf("would rotate quadrant 2 (upper-right) to the right (clockwise). \n");
}


//==============================================================================================
// This function displays the board
void displayBoard(char board[][boardSize])
{
    int row =0;
    int column =0;
    
    printf("\n 1   1  2  3  4  5  6   2\n");
    printf("     ----------------    \n");
    
    for(row = 0; row < boardSize; row++)
    {
        printf(" %c: ",(char) ('A' + row));	//prints out thw left hand side of row letters
        
        for(column = 0; column < boardSize; column++)
        {
            printf(" %c ", board[row][column]);	//prints out the locations of the possible elemets
        }
        
        printf(" :%c\n", (char) ('A' + row));		//prints out the right hand side of row letters
    } // end of for loop for the board
    
    printf("\n 3   1  2  3  4  5  6   4\n");
    printf("     ----------------    \n");
}


//==============================================================================================
// This function starts the board for the start of play
// it will also be the function to update the board while user(s) input moves
void updateBoard(char board[][boardSize])
{
    int row=0;
    int column=0;
    
    for(row = 0; row < boardSize; row++) {
        for(column = 0; column < boardSize; column++)
        {
            board[row][column] = '.';		//sets all elements in the 2D array to '.'
        } // end of for loop for column
    }// end of for loop for row
}// end of updateBoard


//==============================================================================================
// This function simply ask's the user for an input
// inputs are Row, Column, Quadrant, Direction all stored in "charInputs"
int usersInput(char charInputs[], char temp[])
{
    int elements = 0;
    int long length = strlen(charInputs); // converting to a long sting length
    int i =0;
    
    for(i = 0; i < length; i++)
    {
        // This is true if the characterInputs are alphabet or numeric
        // i.e. temp. holds 4 elements to make expression true
        if(isalnum(charInputs[i])) // isalnum()  checks if the passed character is alphanumeric.
        {
            temp[elements++] = charInputs[i];
        }
    }
    if(elements == 4) //will strictly take in 4 characters
        return 1;
    else
        return 0;
} // end of userInput


//==============================================================================================
// This function validates the input given by the user at each step
// Based on what the user inputs the character will be stored on 'final' for execution
int moveBeingMade(char charInputs[], int final[])
{
    char temp[maxInputChar];
    int flag = usersInput(charInputs, temp);
    
    // if the first element is entered as character of 'x' ot 'X'
    if(temp[0] == 'x' || temp[0] == 'X')
        return -1;	// Exit the game
    
    if(!flag)
    {
        return 1;			// Denotes more than 4 chars in user command
    }
    else
    {
        int row, col, quad, dir;
        //https://www.tutorialspoint.com/c_standard_library/c_function_tolower.htm reference for tolower
        temp[0] = tolower(temp[0]); // counter example for toUpper
        
        if(!(temp[0] >= 'a' && temp[0] <= 'f'))
            return 2;							// Incorrect row
        
        row = temp[0] - 'a';
        
        if(!(temp[1] >= '1' && temp[1] <= '6'))
            return 3;							// Incorrect col
        
        col = temp[1] - '1';
        
        if(!(temp[2] >= '1' && temp[2] <= '4'))	// Incorrect quadrant
            return 4;
        
        quad = temp[2] - '1';
        
        temp[3] = tolower(temp[3]);
        
        if(!(temp[3] == 'l' || temp[3] == 'r'))	// Incorrect direction
            return 5;
        
        if(temp[3] == 'l')
            dir = 0;
        else
            dir = 1;
        
        final[0] = row, final[1] = col, final[2] = quad, final[3] = dir;
    }
    
    return 0;		// Successful execution
}


//==============================================================================================
// This function is used to copy contents of 'from' into 'to'
// important function for rotation
// The function serves as catching the characters to place in destination
void movedFromAndTo(char to[][boardSize], char from[][boardSize])
{
    
    int i = 0;
    int j = 0;
    
    for(i = 0; i < boardSize; i++)
    {
        for(j = 0; j < boardSize; j++)
        {
            to[i][j] = from[i][j];
        }
    }
    return;
}


//==============================================================================================
// This function rotates the given quadrant by 90 degree conter clockwise (left)
// divided by two sides(left side = 1st and 3rd qudrants)
// (right side = 2nd and 4th quadrants)
void leftRotate(char board[][boardSize], int quadrant)
{
    int leftSideRow, leftSideColumn, rightSideRow, rightSideColumn;
    
    // specifying the quadrants
    switch(quadrant)
    {
        case 0:
            leftSideRow = 0, leftSideColumn = 0, rightSideRow = 3, rightSideColumn = 3; // 1st qudrant
            break;
        case 1:
            leftSideRow = 0, leftSideColumn = 3, rightSideRow = 3, rightSideColumn = 6; // 2nd quadrant
            break;
        case 2:
            leftSideRow = 3, leftSideColumn = 0, rightSideRow = 6, rightSideColumn = 3; // 3rd quadrant
            break;
        case 3:
            leftSideRow = 3, leftSideColumn = 3, rightSideRow = 6, rightSideColumn = 6; // 4th quadrant
            break;
        default:
            printf("Unexpected quadrant found in leftRotate\n");
            return;
    }
    
    char destination[boardSize][boardSize];
    int quadrantSize = 3; // 4 quadrants but counting from 0
    
    movedFromAndTo(destination, board);
    
    // Rotate it
    int row = 0;
    int column = 0;
    
    // rotation for the left side
    // taking all specified quadrant and moving the columns and rows
    for(row = leftSideRow; row < rightSideRow; row++)
    {
        for(column = leftSideColumn; column < rightSideColumn; column++)
        {
            destination[(quadrantSize-column-1 +leftSideColumn+leftSideRow)][(row - leftSideRow + leftSideColumn)]
            = board[row][column];
        } // column arrays
    } // row arrays
    
    movedFromAndTo(board, destination);
    return;
}


//==============================================================================================
// This function rotates the given quadrant by 90 clockwise, right direction
// Just like the leftRotate this will also be similar and gather the Right sides
void rightRotate(char board[][boardSize], int quadrant)
{
    int leftSideRow, leftSideColumn, rightSideRow, rightSideColumn;
    
    switch(quadrant)
    {
        case 0:
            leftSideRow = 0, leftSideColumn = 0, rightSideRow = 3, rightSideColumn = 3; //1st quadrant
            break;
        case 1:
            leftSideRow = 0, leftSideColumn = 3, rightSideRow = 3, rightSideColumn = 6; // 2nd quadrant
            break;
        case 2:
            leftSideRow = 3, leftSideColumn = 0, rightSideRow = 6, rightSideColumn = 3;// 3r quadrant
            break;
        case 3:
            leftSideRow = 3, leftSideColumn = 3, rightSideRow = 6, rightSideColumn = 6;// 4th quadrant
            break;
        default:
            printf("Unexpected quadrant found in rightRotate\n");
            return;
    }
    
    char destination[boardSize][boardSize];
    int quadrantSize = 3; // 4 quadrants
    
    movedFromAndTo(destination, board);
    
    // Rotating it  it
    int row = 0;
    int column = 0;
    // This time as to oppose to moving it to the left, we're moving the rows first and columns
    for(row = leftSideRow; row < rightSideRow; row++)
    {
        for(column = leftSideColumn; column < rightSideColumn; column++)
        {
            destination[(column - leftSideColumn + leftSideRow)][(quadrantSize + leftSideColumn + leftSideRow - row - 1)]
            = board[row][column];
        }
    }
    movedFromAndTo(board, destination);
    
    return;
}


//==============================================================================================
// This function is the one that puts/ coordinates the 'X' and 'O'
void playerMove(char board[][boardSize], int temp[], char moveCharacter)
{
    
    int row = temp[0];
    int column = temp[1];
    
    board[row][column] = moveCharacter;			// Place the character
    
    int quadrant = temp[2]; //quadrant to be picked
    int dir = temp[3]; // for the rotation switch
    
    if(dir == 0)
    {
        leftRotate(board, quadrant);	// Left Rotation
    }
    else
    {
        rightRotate(board, quadrant);	// Right Rotation
    }
}


//==============================================================================================
// This function checks if char 'X' is the winner according to current state of the board
// will check for rows,columns and diagonals
int charWinner(char board[][boardSize], char moveCharacter)
{
    int possibleWin = 0;
    // will check up to at most 5 possibilities indexes/elements marked as 'X'
    int checkUpTo = 5;
    
//------------------------------------------------------------------------------------------------
    // This checks all the rows
    int row = 0;
    int column = 0;
    int count;
    
    for(row = 0; row < boardSize && !possibleWin; row++)
    {
        for(column = 0; column < boardSize && !possibleWin; column++)
        {
            if(board[row][column] == moveCharacter)
            {
                for(count = 1; count <= (checkUpTo-1) && (column + count) < boardSize; count++)
                {
                    if(board[row][column+count] != moveCharacter)
                    {
                        break;
                    }
                }
                
                if(count == (checkUpTo))
                {
                    possibleWin = 1;	// This player is the winner
                }
            }
        }
    }
//------------------------------------------------------------------------------------------------
    // This checks for all columns
    
    for(column = 0; column < boardSize && !possibleWin; column++)
    {
        for(row = 0; row < boardSize && !possibleWin; row++)
        {
            if(board[row][column] == moveCharacter)
            {
                for(count = 1; count <= (checkUpTo-1) && (count + row) < boardSize; count++) {
                    if(board[row+count][column] != moveCharacter) {
                        break;
                    }
                }
                if(count == (checkUpTo)) {
                    possibleWin = 1;	// This player is the winner
                }
            }
        }
    }
//------------------------------------------------------------------------------------------------
    // This checks for all diagonals
    for(row = 0; row < boardSize && !possibleWin; row++)
    {
        for(column = 0; column < boardSize && !possibleWin; column++)
        {
            if(board[row][column] == moveCharacter)
            {
                for(count = 1; count <= (checkUpTo-1) && (row + count) < boardSize && (column + count) < boardSize; count++) {
                    if(board[(row+count)][(column+count)] != moveCharacter) {
                        break;
                    }
                }
                if(count == (checkUpTo)) {
                    possibleWin = 1;	// This player is the winner
                }
                for(count = 1; count <= (checkUpTo-1) && (row - count) >= 0 && (column + count) < boardSize; count++) {
                    if(board[(row-count)][(column+count)] != moveCharacter) {
                        break;
                    }
                }
                if(count == (checkUpTo)) {
                    possibleWin = 1;   // This player is the winner
                }
            }
        }
    }
//------------------------------------------------------------------------------------------------
    return possibleWin;
} // end of charWinner


//==============================================================================================


int main()
{
    char board[boardSize][boardSize];	//makes the 2D array for the board a 6 x 6
    char buffer[buffer];
    int final[maxInputChar];
    
    
    displayIdentyfingInformation();
    displayInstructions();
    updateBoard(board); // Initialize and display the board
    displayBoard(board);
    
    int flag = 1;
    int moveNum = 1;
    
    while(flag) {
        
        char moveCharacter;// either 'X' or 'O'
        
        printf("%d. Enter row, column, quadrant, direction for ", moveNum);
        
        if(moveNum & 1) {
            moveCharacter = 'X';
        } else {
            moveCharacter = 'O';
        }
        
        printf("%c: ", moveCharacter);
        
        // will scan for every character up to a new line and stops to display
        scanf(" %[^\n]%*c", buffer);
        
        int response = moveBeingMade(buffer, final);
        
        if(response == -1) {
            flag = 0;
            continue;
        } else if(response == 0) {
            playerMove(board, final, moveCharacter);
        } else {
            
            switch(response) {
                case 1:
                    printf("\t*** Invalid move: more than 4 characters. Please retry.\n");
                    break;
                case 2:
                    printf("\t*** Invalid move row. Please retry.\n");
                    break;
                case 3:
                    printf("\t*** Invalid move column. Please retry.\n");
                    break;
                case 4:
                    printf("\t*** Selected quadrant is invalid. Please retry\n");
                    break;
                case 5:
                    printf("\t*** Quadrant rotation direction is invalid.  Please retry.\n");
                    break;
                default:
                    break;
            }
            
            continue;
        }
        
        int isWinnerX = charWinner(board, 'X');
        int isWinnerO = charWinner(board, 'O');
        
        if(isWinnerX && !isWinnerO) {
            printf("X has won the game\n");
            flag = 0;
            continue;
        } else if(!isWinnerX && isWinnerO) {
            printf("O has won the game\n");
            flag = 0;
            continue;
        } else if(isWinnerX && isWinnerO) {
            printf("The game is a tie.\n");
            flag = 0;
            continue;
        }
        
        displayBoard(board);
        moveNum += 1;
    }
    
    displayBoard(board);
    printf("Thanks for playing.  Exiting...\n\n");
    return 0;
}
//==============================================================================================
