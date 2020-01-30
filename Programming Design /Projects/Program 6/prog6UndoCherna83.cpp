/* prog6UndoCherna83.cpp
 //
 // Author: Cesar Hernandez
 // Class: CS 141, Spring 2017. Tues, 2pm Lab
 // System: Xcode on a mac
 //
 // ToDo: Same program like prog.5 with undo move
 //
 //
 // For instance:
 //
 |When prompted to provide input you may enter:
 |Enter 'r' to reset the board to user-defined values.
 |Enter 'u' to undo a move.
 |Enter 'o' for original board to be shown
 |Enter 'x' to exit the program.
 |
 |There are 500 4-letter words.
 |
 |E F G H
 |-------
 |A| t i l m
 |B| f h o s
 |C| l t e a
 |D| s e l t
 |List: 1
 |1. Enter the row or column to be rotated, and a number 1..3: o
 |You chose 'o' for the original board to be shown.  Here are the underlying words:
 |
 |E F G H
 |-------
 |A| t i l l
 |B| h o s t
 |C| t e a m
 |D| s e l f
 |
 |
 |E F G H
 |-------
 |A| t i l m
 |B| f h o s
 |C| l t e a
 |D| s e l t
 |1. Enter the row or column to be rotated, and a number 1..3: d1
 |E F G H
 |-------
 |A| t i l m
 |B| f h o s
 |C| l t e a
 |D| t s e l
 |List: 2->1
 |2. Enter the row or column to be rotated, and a number 1..3: h1
 |
 |E F G H
 |-------
 |A| t i l l
 |B| f h o m
 |C| l t e s
 |D| t s e a
 |List: 3->2->1
 |3. Enter the row or column to be rotated, and a number 1..3: u
 |You chose 'u' to undo the most recent move.
 |* Undoing move *
 |
 |E F G H
 |-------
 |A| t i l m
 |B| f h o s
 |C| l t e a
 |D| t s e l
 |List: 2->1
 |2. Enter the row or column to be rotated, and a number 1..3: u
 |You chose 'u' to undo the most recent move.
 |* Undoing move *
 |
 |E F G H
 |-------
 |A| t i l m
 |B| f h o s
 |C| l t e a
 |D| s e l t
 |List: 1
 |1. Enter the row or column to be rotated, and a number 1..3: u
 |You chose 'u' to undo the most recent move.
 |*** You cannot undo past the beginning of the game.  Please retry.
 |
 |E F G H
 |-------
 |A| t i l m
 |B| f h o s
 |C| l t e a
 |D| s e l t
 |List: 1
 |1. Enter the row or column to be rotated, and a number 1..3: c3
 |
 |E F G H
 |-------
 |A| t i l m
 |B| f h o s
 |C| t e a l
 |D| s e l t
 |List: 2->1
 |2. Enter the row or column to be rotated, and a number 1..3: h2
 |
 |E F G H
 |-------
 |A| t i l l
 |B| f h o t
 |C| t e a m
 |D| s e l s
 |List: 3->2->1
 |3. Enter the row or column to be rotated, and a number 1..3: u
 |You chose 'u' to undo the most recent move.
 |* Undoing move *
 |
 |E F G H
 |-------
 |A| t i l m
 |B| f h o s
 |C| t e a l
 |D| s e l t
 |List: 2->1
 |2. Enter the row or column to be rotated, and a number 1..3: u
 |You chose 'u' to undo the most recent move.
 |* Undoing move *
 |
 |E F G H
 |-------
 |A| t i l m
 |B| f h o s
 |C| l t e a
 |D| s e l t
 |List: 1
 |1. Enter the row or column to be rotated, and a number 1..3: o
 |You chose 'o' for the original board to be shown.  Here are the underlying words:
 |
 |E F G H
 |-------
 |A| t i l l
 |B| h o s t
 |C| t e a m
 |D| s e l f
 |
 |
 |E F G H
 |-------
 |A| t i l m
 |B| f h o s
 |C| l t e a
 |D| s e l t
 |1. Enter the row or column to be rotated, and a number 1..3: b3
 |
 |E F G H
 |-------
 |A| t i l m
 |B| h o s f
 |C| l t e a
 |D| s e l t
 |List: 2->1
 |2. Enter the row or column to be rotated, and a number 1..3: c3
 |
 |E F G H
 |-------
 |A| t i l m
 |B| h o s f
 |C| t e a l
 |D| s e l t
 |List: 3->2->1
 |3. Enter the row or column to be rotated, and a number 1..3: h2
 |
 |E F G H
 |-------
 |A| t i l l
 |B| h o s t
 |C| t e a m
 |D| s e l f
 |List: 4->3->2->1
 |Congratulations!  You solved it!
 |
 |
 |
 */
//==================================================================================================================
//==================================================================================================================

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
//defining the 4x4 board and the user board that will modified throughout the program
char originalBoard[4][4], userBoard[4][4];

//***********************************************************************
// Global Struct
struct Node{
    char userBoard[4][4]; //data
    int moveNumber; //debugging purposes (count nodes)
    Node *pNext;
};
//==================================================================================================================
// Function to display program and information
void displayIdentyfingInformation()
{
    printf ("Author: Cesar Hernandez\n");
    printf ("Program: #6, AcrossWords with Undo\n");
    printf ("TA: Moumita Samanta, Tues 2pm\n");
    printf ("Apr 26, 2017\n");
    printf("\n");
}

//==================================================================================================================
//function to display instructions for user
void displayIntructions(){
    printf("Welcome to AcrossWord puzzle, where you rotate rows or columns\n");
    printf("to restore the board back to containing four words. Each move is\n");
    printf("a row or column letter followed by the rotation distance 1,2 or 3.\n\n");
    
    printf("When prompted to provide input you may enter:\n");
    printf("\tEnter 'r' to reset the board to user-defined values.\n");
    printf("\tEnter 'o' to unveil the underlying words(show original board).\n");
    printf("\tEnter 'u' to undo move\n");
    printf("\tEnter 'x' to exit the program.\n\n");
    
    printf("Which dictionary size do you want? (1=small, 2=medium, 3=large): \n");
}

//==================================================================================================================
//since display after the Board
//made a seperate function for the user command input
void userInstructionPrompt()
{
    printf("Enter the row or column to be rotated, and a number 1..3: \n");
}
//==================================================================================================================
//***********************************************************************
// function to display number of amount List
void displayList( Node *pHead)
{
    Node *pTemp = pHead; //current node
    printf("List: ");
    while( pTemp != NULL)
    {
        printf("%d ", pTemp->moveNumber); //moveNumber counting = 1..2..
        if( pTemp->pNext != NULL)
        {
            printf( "-> "); //arrow = node
        }
        pTemp = pTemp->pNext;
    }
    printf("\n");
}

//==================================================================================================================
// function will print a 4x4 double array board
//(char)('A'+i) prints A - D in order
void displayBoard(char board[4][4], Node *pHead)
{
    printf("\n     E F G H\n");
    printf("     -------\n");
    for(int x=0; x<4; x++)
    {
        printf("  %c| ",(char)('A'+x));
        for(int y=0; y<4; y++)
        {
            printf("%c ",board[x][y]);
        }
        printf("\n");
    }
    printf("\n");
    displayList( pHead);
    //cout << endl;
}

//==================================================================================================================
//creating the function for resetting
//16 chars are put into strLetters
//all chars are put into one string into the users modified board
void resetBoard(char* strLetters)
{
    int count=0;
    for(int x=0; x<4; x++)
    {
        for(int y=0; y<4; y++)
        {
            userBoard[x][y] = strLetters[count++];
        }
    }
}

//==================================================================================================================
// this function will rotate the board accordingly
// function is divided into two parts
// first part contains if and else, will get lower case characters
// second part is for upper case letters
// both parts of the code is the same with if starting to move rows, else = columns
void rotateBoard(char* ch)
{
    // ch = character
    // first character of array for lower case
    if(ch[0] >= 'a') // first character
    {
        int temp = ch[0] - 'a'; // temp = storing row or column
        if(temp<4) // only 1,2, and 3 will cause it to rotate row wise
        {
            int rotate = ch[1] - '0'; // rotate = amount of characters to move (second char)
            char tempRow[4]; // tempArr carries over the modified array(new chars)
            for(int i=0; i<4; i++) //new characters being placed in table accordingly
            {
                tempRow[(i+rotate)%4] = userBoard[temp][i]; // i+rotate%4 to create rows
            }
            //stored into modified  userBoard
            for(int i=0 ;i<4; i++)
            {
                userBoard[temp][i] = tempRow[i];
            }
        } // end of if for rows
        else
        {
            //this part, temp > 4 will change the columns rotatins
            temp -= 4;
            int rotate = ch[1] - '0';
            char tempRow[4];
            for(int i=0; i<4; i++)
            {
                tempRow[(i+rotate)%4] = userBoard[i][temp]; // this time temp changes the columns
            }
            for(int i=0; i<4; i++) // stores columns changed into modified arrays
            {
                userBoard[i][temp] = tempRow[i];
            }
            
        }// end of else columns
    }
    //------------------------------------------------------------------------------------------------------------------
    else
    {
        int temp = ch[0] -'A'; // this part is the identical as the first but with Upper case letters (rows)
        if(temp<4)
        {
            int rotate = ch[1] - '0';
            char tempCol[4];
            for(int i=0; i<4; i++)
            {
                tempCol[(i+rotate)%4] = userBoard[temp][i];
            }
            for(int i=0;i<4;i++)
            {
                userBoard[temp][i] = tempCol[i];
            }
        } // end of if for rows
        else
        {   // this part is the identical as the first but with Upper case letters (columns)
            temp -= 4;
            int rotate = ch[1] -'0';
            char tempCol[4];
            for(int i=0; i<4; i++)
            {
                tempCol[(i+rotate)%4] = userBoard[i][temp];
            }
            for(int i=0; i<4; i++)
            {
                userBoard[i][temp] = tempCol[i];
            }
            
        }// end of else column
        
    }
} // end of rotate function

//==================================================================================================================

void randomizeBoard()
{
    //radomizeBoard randomizes two rows and one column
    // actions takes place where position is chosen
    char ch[3];
    int colShuffle = rand()%3;
    
    for(int i=0;i<3;i++)
    {
        //if i==col_change, it is the change of the column to rotate
        int tempStore; //tempStore store charcter information from row/col
        if(i==colShuffle)
        {
            tempStore = 4+rand()%4;
        }
        else
        {
            tempStore = rand()%4;
        }
        int rotate = 1+rand()%3; // number of rotations done in the movements of row/col
        
        // characters are made to rotate radomize chars
        ch[0] = (char)(tempStore + 'a'); // first character
        ch[1] = (char)(rotate + '0'); // second character (position)
        ch[2] = '\0'; // null character
        rotateBoard(ch); // performs modified rotation
    }
} // end of randomization

//==================================================================================================================
char **words; //referencing words to check w/ dictionary

int checkDoneWords(int numOfTotalWords)
{
    //if done this will check or match 4 words from the board respect towards dictionaries
    
    int x,y,i,count = 0; // x= row y=col i=chars from words count =counting words
    for(x=0;x<4;x++)
    {
        char temp[5];    //current strong of words stored into temp array.
        for(y=0; y<4; y++)
        {
            temp[y] = userBoard[x][y];
        }
        temp[4]='\0';
        for(i=0;i<numOfTotalWords;i++) // starts matching for words in dictiionaries
        {
            if(strcmp(temp,words[i])==0)
            {
                count++; // as soon as a word is matched it breaks and increments to check for more words
                break;
            }
        }
    }
    if(count == 4) // if # of words = 4 words from dictionary
    {
        return 1; //true
    }
    else
    {
        return 0;// false
    }
}

//==================================================================================================================
//**************************************************
void deleteNodeFromList(Node *&pHead,       // head  of the list
                        char userboard[][4],//modified board being used
                        int &moveNumber)    // current number
{
    // when node = null
    if( pHead->pNext == NULL) {
        printf( "\n*** You cannot undo past the beginning of the game.  Please retry.");
        printf( "\n");
        return;
    }
    printf("\n* Undoing move * \n");
    
    Node *pTemp = pHead;/////
    pHead = pHead->pNext;
    delete ( pTemp); // delete old head list
    for(int x=0; x<4; x++) // double array for userBoard
    {
        for(int y=0; y<4; y++)
        {
            userBoard[ x][ y] = pHead->userBoard[ x][ y]; //store userBoard info to userBoar
        }
    }
    moveNumber = pHead->moveNumber;
}
//================================================================================================
//**************************************************
// appending node to front of the list
void addNodeToList(Node *&pHead,       // derefrencing pointer
                   char userBoard[][4],// storing board info
                   int moveNumber)     // number counting per list
{
    // pTemp = new node
    Node *pTemp = new Node;
    for(int x=0; x<4; x++)
    {
        for(int y=0; y<4; y++)
        {
            pTemp->userBoard[ x][ y] = userBoard[ x][ y];
        } // current board info stored
    }
    pTemp->moveNumber = moveNumber;
    pTemp->pNext = pHead;
    
    pHead = pTemp; //apeend to fron list
}

//==================================================================================================================

int main()
{//intro part
    char ch[80]; // array of character
    char userStr[20]; //user inputs letters into a 16 char to whole string size
    int dictionarySize;
    int count=0; // this will keep count of # of words from dictionary
    time_t t;
    srand((unsigned) time(&t)); // for randomizing //unsigned to not be in continous
    
    
    int moveNumber = 1;// moveNumber starts w/ List 1 and counts++
    Node *pHead = NULL;// **
    
    displayIdentyfingInformation();
    displayIntructions();
    
    //------------------------------------------------------------------------------------------------------------------
    // part 2 picking a dictionary and doing commands
    
    scanf("%d",&dictionarySize); // ask user to input 1..3 for size
    FILE *fp = nullptr;
    if(dictionarySize == 1)
    { // dynamically allocated array (malloc) for size
        fp = fopen("smallDictionary.txt","rb");
        words = (char **)(malloc(sizeof(char*)*501));
    }
    
    
    while(1) // continous loop
    {
        //read the file until fscanf returns something other than 1
        char temp[200];
        int temp1 = fscanf(fp,"%s",temp);
        if(temp1 != 1)
            break;
        if(strlen(temp)== 4)
        {
            words[count] = (char *)(malloc(sizeof(char)*4)); // counting words applied from memory allocation
            strcpy(words[count],temp);
            count++;
        }
    } // end of while loop
    printf("There are %d 4-letter words.\n\n",count);
    
    for(int x=0; x<4; x++) //row chars
    {
        int tmp = (rand()%count); // randomize by # of words
        for(int y=0; y<4; y++) // col chars
        {
            originalBoard[x][y] = words[tmp][y]; //originalBoard saves the answer
            userBoard[x][y] = words[tmp][y]; //displays modified board
        }
    }// end of double array
    randomizeBoard();
    addNodeToList( pHead, userBoard, moveNumber); //after random append node to list
    displayBoard(userBoard, pHead); // display modifications
    //------------------------------------------------------------------------------------------------------------------
    //part 3 making sure specifics are in place (checking for errors)
    while(1)//while loop to run program successfully
    {
        while(1)
        {// continous loop
            userInstructionPrompt();
            scanf("%s",ch);
            
            if( strlen(ch)!=1 && strlen(ch)!=2) //length of chars is 2
            {// if more than 2 chars, then error
                printf("Invalid Input. Enter again.\n\n");
                continue;
            }
            if( strlen(ch) == 1 && //first character size
               (ch[0] != 'r' && //specifically looking for these chars or error message
                ch[0] != 'u' &&
                ch[0] != 'x' &&
                ch[0] != 'o'))
            {
                printf("Invalid Input. Enter again.\n\n");
                continue;
            }
            
            if( strlen(ch) == 2 && //character size 2 position in array
               ((ch[0]!='a' && (ch[0]!='A' && // only checking for specific letters
                                ch[0]!='b' && ch[0] !='B' &&
                                ch[0]!='c' && ch[0] !='C' &&
                                ch[0]!='d' && ch[0] !='D' &&
                                ch[0]!='e' && ch[0] !='E' &&
                                ch[0]!='f' && ch[0] !='F' &&
                                ch[0]!='g' && ch[0] !='G' &&
                                ch[0]!='h' && ch[0] !='H')) ||
                ((ch[1]-'0')>4 && (ch[1]-'0')<1 )))
            {
                printf("Invalid Input. Enter again.\n\n");
                continue;
            }
            break;
        }
        //------------------------------------------------------------------------------------------------------------------
        // part 4 actions for 'r', 'u', and 'x'
        // only if for first character input
        if(ch[0] == 'x') // user can exit anytime from program
        {
            printf("You chose 'x' to Exit...\n");
            return 0;
        }
        
        if(ch[0] == 'o')
        {
            printf("You chose 'o' to unveil. Here are the underlying words:\n");
            displayBoard(originalBoard, pHead);
            continue;
        }
        if(ch[0] == 'u')
        {
            printf("You chose 'u' to undo move:\n");
            deleteNodeFromList( pHead, userBoard, moveNumber); //fucntion to delete last node info
            displayBoard( userBoard, pHead);
            continue;
        }
        if(ch[0] == 'r')
        {
            while(1)
            {
                printf("You chose 'r' to reset the board.\n");
                printf("Enter 16 char values to reset the board: ");
                scanf("%s", userStr); // ask user for input
                
                if(strlen(userStr) != 16)// checks for only a string of 16 chars
                {
                    printf("Sorry, needed to provide exactly 16 characters ");
                    printf("of user input to reset the board.  Please retry.\n");
                    continue;
                }//end of userStr if errors
                break;
            }// end of continous loop
            resetBoard(userStr); //puts in the new chars in board

            displayBoard(userBoard, pHead);
            continue;
        }
        //------------------------------------------------------------------------------------------------------------------
        //part 5 displays actions and check for completion
        
        rotateBoard(ch); //once users commands it to move it will rotate accordingly
        moveNumber++;
        addNodeToList( pHead, userBoard, moveNumber); //to show undo correctly
        displayBoard(userBoard, pHead);// display movement
        
        if(checkDoneWords(count)) // once user starts trying to solve words
        {
            //# of words will be matched to display solved message
            printf("Congratulations! You solved it!\n\n");
            printf("End of program. Exiting...\n\n");
            return 0;
        }// end of check done function
    }// end of while loop
    
    return 0;
}// end of main
//==================================================================================================================
