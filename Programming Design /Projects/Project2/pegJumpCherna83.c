/*----------------------------------
 * JumpPeg.c (Late Submission)
 *
 * Author: Cesar Hernandez
 * Class: CS 141, Spring 2017. Tues, 2pm Lab
 * System: Xcode on an Mac
 *
 * ToDo: To write a program that interacts with the user called JumpPeg a game that will display moves
 * based on the user outputs.
 *
 * For instance:
 
 | Author: Cesar Hernandez
 | Program: #1, Guess Number
 | TA: TA: Moumita Samanta, Tues 2pm
 | Feb 15, 2017
 | LATE SUBMISSION
 |
 |   This program represents the peg jumping puzzle.
 |
 |   The board starts out with a single blank position, represented by
 |   the 'O'.  To make a move, select the letter of the peg to be moved,
 |   then the letter of the destination position. (e.g. the first move
 |   might be: d a, meaning we move peg ‘d’ into blank position ‘a’.)
 |   A peg must be able to jump over an adjacent peg into a blank for a
 |   move to be valid.  The jumped peg is then removed from the board.
 |   The game is over when there are no valid moves left to be made, or
 |   when there is a single peg left.
 |
 |  At any point enter 'x' to exit the program.
 | -----------------------
 | Board    Positions
 | o          A
 | + +        B C
 | + + +      D E F
 | + + + +    G H I J
 | + + + + +  K L M N O
 |
 | 1. Enter your move: D a
 |
 |
 | -----------------------
 | Board    Positions
 | +          A
 | o +        B C
 | o + +      D E F
 | + + + +    G H I J
 | + + + + +  K L M N O
 |
 | 2. Enter your move: K D
 |
 | ...... etc
 |
 | # left  Rating
 | ------  ---------------
 | >4    Dufus
 | 4     Poor
 | 3     Mediocre
 | 2     Good Job
 | 1     Awesome Genius!
 |
 | You had 1 left.  Awesome Genius!
 |
 | Thanks for playing.  Exiting...
 |   */
//====================================================================================================
//====================================================================================================

#include <stdio.h>
#include <ctype.h> // important for "toupper"
//====================================================================================================


void authorInformation()
{
    printf("Author: Cesar Hernandez\n");
    printf("Assignment: 2, PegJump (Late Submission)\n");
    printf("TA: Moumita Samanta, Tues 2pm\n");
    printf("Feb 15, 2017\n\n");
}
//====================================================================================================


void displayInstructions()
{
    printf("This program represents the peg jumping puzzle.\n\n");
    printf("The board starts out with a single blank position, represented by the 'O'.\n");
    printf("To make a move, select the letter of the peg to be moved, then the letter of the destination position.\n");
    printf("(e.g. the first move might be: 'D' 'A', meaning we move peg 'D' into blank position 'A'.)\n");
    printf("A peg must be able to jump over an adjacent peg into a blank for a move to be valid.\n");
    printf("The jumped peg is then removed from the board.\n");
    printf("The game is over when there are no valid moves left to be made,");
    printf(" or when there is a single peg left.\n\n");
}


//====================================================================================================


void displayBoard( char p1, char p2, char p3, char p4, char  p5, char p6, char p7, char p8,
                  char p9, char p10, char p11, char p12, char p13, char  p14, char p15)
{
    printf("--------------------------------------------------------------\n");
    printf("   Board       Positions   \n");
    printf("     %c             A\n"        ,                       p1);
    printf("    %c %c           B C\n"      ,                   p2, p3);
    printf("   %c %c %c         D E F\n"    ,               p4, p5, p6);
    printf("  %c %c %c %c       G H I J\n"  ,          p7, p8, p9, p10);
    printf(" %c %c %c %c %c     K L M N O\n",  p11, p12, p13, p14, p15);
}

//----------------------------------------------------------------------------------------------------

// The characters in getCharAt are all the characters in the board, i.e A, B, C... etc...
// catching all the characters into their position
char getCharAt( char p1, char p2, char p3, char p4, char p5, char p6, char p7, char p8, char p9,
               char p10, char p11, char p12, char p13, char p14, char p15, char Position)
{
    switch(Position)
    {
        case 'A': return Position = p1; break;
        case 'B': return Position = p2; break;
        case 'C': return Position = p3; break;
        case 'D': return Position = p4; break;
        case 'E': return Position = p5; break;
        case 'F': return Position = p6; break;
        case 'G': return Position = p7; break;
        case 'H': return Position = p8; break;
        case 'I': return Position = p9; break;
        case 'J': return Position = p10; break;
        case 'K': return Position = p11; break;
        case 'L': return Position = p12; break;
        case 'M': return Position = p13; break;
        case 'N': return Position = p14; break;
        case 'O': return Position = p15; break;
        default: printf("Invalid option, Exiting program... \n");
            return 0;
    }// end of SWITCH
}


//====================================================================================================


void setCharTo( char destination, char newCharacter, char *p1, char *p2, char *p3, char *p4, char *p5, char *p6,
               char *p7, char *p8, char *p9, char *p10, char *p11, char *p12, char *p13, char *p14, char *p15)
{
    switch( destination) {
        case 'A': *p1 = newCharacter; break;
        case 'B': *p2 = newCharacter; break;
        case 'C': *p3 = newCharacter; break;
        case 'D': *p4 = newCharacter; break;
        case 'E': *p5 = newCharacter; break;
        case 'F': *p6 = newCharacter; break;
        case 'G': *p7 = newCharacter; break;
        case 'H': *p8 = newCharacter; break;
        case 'I': *p9 = newCharacter; break;
        case 'J': *p10 = newCharacter; break;
        case 'K': *p11 = newCharacter; break;
        case 'L': *p12 = newCharacter; break;
        case 'M': *p13 = newCharacter; break;
        case 'N': *p14 = newCharacter; break;
        case 'O': *p15 = newCharacter; break;
        default: printf("Invalid option...  Exiting program... \n");
            break;
    }
}//end setCharTo()

//----------------------------------------------------------------------------------------------------

// Will find a possible peg to be jumped
// takes the acsii # of the characters that are put in from and to and divide the added number
// by the average which is 2 and will give a new character position
char pegToBeJumped( char from, char to)
{   // will give a new character position based on the chars picked
    char pegJumped = (char) ((from + to) / 2);
    
    return pegJumped; // returns the final character and places an 'o'
}//end of


//----------------------------------------------------------------------------------------------------

// this function will test all the possible invalid moves
// will notify the user if they have entered an invalid move
int notValidMoves( char p1, char p2, char p3, char p4, char p5, char p6, char p7, char p8, char p9,
                  char p10, char p11, char p12, char p13, char p14, char p15, char from, char to)
{
    // 1. Source is the character between 'a' and 'o'
    if( from < 'A' || from > 'O') {
        printf("*** Invalid source.  Please retry ****\n");
        return 1;    // while input is invalid return 1 for true
    }
    
    // 2. requires the 'to' to be empty
    if( to < 'A' || to > 'O') {
        printf("*** Invalid destination.  Please retry ****\n");
        return 1;    // while input is invalid return 1 for true
    }
    
    // 3. Source needs to have a peg of '+'
    if( getCharAt(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15, from) != '+') {
        printf("*** Source must have a piece.  Please retry. ***\n");
        return 1;    // while input is invalid return 1 for true
    }
    
    // 4. Position being jumped does not have a peg.
    char pegJumped = pegToBeJumped( from, to);
    if( getCharAt(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15, pegJumped) != '+') {
        printf("*** Must jump a piece.  Please retry. ***\n");
        return 1;    // while input is invalid return 1 for true
    }
    
    // 5. Destination is not empty.
    if( getCharAt(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15, to) != 'o') {
        printf("*** Destination must be empty.  Please retry. ***\n");
        return 1;   // while input is invalid return 1 for true
    }
    
    // the above code was for all possible moves that the user can't enter
    // i.e now everything else will resut in false
    return 0;
}//end notValidInput()


//====================================================================================================

// This will mkae the move of the peg
// since it's grabbing the other functions it already has the astrick causing no need to update the code below
// Everything is being put together from updating the character to returning the new charcater in a new position
void makeMove( char *p1, char *p2, char *p3, char *p4, char *p5, char *p6, char *p7, char *p8, char *p9, char *p10,
              char *p11, char *p12, char *p13, char *p14, char *p15, char from, char to)
{
    // Finding the piece being jumped
    char jumpedPeg = pegToBeJumped( from, to);
    
    setCharTo( from, 'o', p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15);
    
    // this will jump the peg
    setCharTo( jumpedPeg, 'o', p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15);
    
    // destination
    setCharTo( to, '+', p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15);
}//end makeMove()



//====================================================================================================

// This function will obtain the user's results of the peg game
// based on the moves that user did it will let the user know how well the user did
void displayEndTableScore( int numPegs)
{
    printf("# left  Rating             \n");
    printf("------  ---------------    \n");
    printf("  >4    Try again !        \n");
    printf("  4     Poor               \n");
    printf("  3     Average            \n");
    printf("  2     Good Job           \n");
    printf("  1     Awesome!           \n");
    printf(" \n");
    printf("You had %d left. ",  numPegs);
    
    // Print message according to the numPegs that the user was able to move
    switch( numPegs) {
        case 1: printf(" Awesome!       \n"); break;
        case 2: printf(" Good Job       \n"); break;
        case 3: printf(" Average        \n"); break;
        case 4: printf(" Poor           \n"); break;
        default: printf(" Try Again !   \n"); break;
    }
    printf("\n");
}//end displayEndTableScore()


//====================================================================================================


int main(){
    
//----------------------------------------------------------------------------------------------------
    
int countPegs = 14; // 14 free open pegs
int countMoves = 1; // starting with 1 possible choice to move
    
//----------------------------------------------------------------------------------------------------
    
char from = '0', To;
char p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15; // all pegs such as 'A', 'B'...
    
p2=p3=p4=p5=p6=p7=p8=p9=p10=p11=p12=p13=p14=p15 = '+'; // intializing all pegs to '+'
p1 = 'o'; // since we're starting at A p1 is declared as 'o'
    
//----------------------------------------------------------------------------------------------------
    
authorInformation();
displayInstructions();
    
//----------------------------------------------------------------------------------------------------
    
displayBoard(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
    
//----------------------------------------------------------------------------------------------------
    
while (countPegs > 1) // once there are no pegs it will not go
{
    while(1)
    {
        printf(" %d Enter your move: ", countMoves);
        scanf(" %c", &from);
            
        if( toupper(from == 'X' || from == 'x')) // will either take capital or lower case 'X' to exit
        {
            displayEndTableScore(countPegs);
            printf("Exiting program...\n");
            return (0);
        }
        scanf(" %c", &To);
        from = toupper( from);
        To   = toupper( To);
            
        if( notValidMoves(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15, from, To))
        {
            continue;   // this allows the user to be aware of an invaid move
        }
        else {
            // if the move is valid it will proceed to make the move
            printf(" \n");
            break;
            }
        }//end while( 1)
        
        // Make move
        makeMove( &p1,&p2,&p3,&p4,&p5,&p6,&p7,&p8,&p9,&p10,&p11,&p12,&p13,&p14,&p15, from, To);
        
        countMoves++; // user's moves entered
        countPegs--; // everytimes a peg moves the num of pegs reduces from initial of 14
        
        // keeps on updating the board
        displayBoard(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15);
}//end while( notDone(...)
    
// displays the final board and will use the output of the switch based on the user's performance
    displayEndTableScore( countPegs);
    
    printf("Thanks for playing.  Exiting... \n");
    printf("\n");
    
//----------------------------------------------------------------------------------------------------
    
    return 0;
    
} // END OF MAIN


//====================================================================================================





