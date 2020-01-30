/* secret.cpp
//
// Author: Ubemio Romero, Cesar Hernandez
// Class: CS 141, Spring 2017. Tues, 2pm Lab
// System: Xcode on a mac
//
// ToDo: matching a key file to a cipher file to find secret message
//
// For instance:
// 
 Welcome to the decoding program, where hidden messages are found inside of a text file.
 
 Author: Dale Reed
 Program: #4, Secret
 TA: Gail Chapman, Tues 10
 Mar 5, 2017
 
 Read in 3 keyWords, which are:
 quick
 get
 going
 
 Read in 390 cipherText characters.
 
 Choose from the following options:
 1. Display a particular sized table
 2. Find all matching key word phrases
 3. Place key word phrase into a datafile (not required for students)
 X. Exit the program
 Enter your choice -> 2
 
 Found "get" diagonally with table size 15 at 4. Secret message:  get cash prize ses

*/

//==================================================================================================
//==================================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


char cipherText[17424];
char word2[132];
int  count1;
char keystrings[151][151]; // quick get going
char table[151][151];

//==================================================================================================
// Function to display program and information
void displayIdentyfingInformation()
{
    printf ("\nAuthor(s): Ubemio Romero, Cesar Hernandez\n");
    printf ("Program: #4, Secret\n");
    printf ("TA: Moumita Samanta, Tues 2pm\n");
    printf ("Mar 18, 2017\n");
    printf("\n");
}

//==================================================================================================
// making rows based on the user input
// rowSize = userInput, count = 13 chars of keys
void makeRows(int rowSize, int keyChars)
{
    printf("Enter a row size: 13 - 132\n");
    scanf("%d", &rowSize);
    
    if (rowSize < 13 || rowSize > 132)
    {
        printf("Please enter a number greater than 13 and less than 132 :)");
    }
        else
        {
            for(int e = 0; e < keyChars; e++) // e = chars in cipher
            {
                if( e%rowSize == 0) // will execute the rows
                    {
                        printf("\n");
                    }
                printf("%c", cipherText[e]);
            }
        }
    printf("\n");
}
//=====================================================================================================
// this function will match the words from the key words to the cipher text
void matchWords(int rowSize,int count, char key1[])
{
    int e=0;
    char temp[200];
    int i,j,ct=0;
    int fl=0;
    int ct1=0;
    int colSize = ceil((double)(count)/(double)(rowSize)); // will round up or down accordinly to int
//--------------------------------------------------------------------------------------------------
// will get the match making horizonatally
    for(int i=0;i<colSize;i++)
        for(int j=0;j<rowSize;j++)
            if(e==count)
                break;
            else
                table[i][j]=cipherText[e++];
    for(int i=0;i<colSize;i++)
        for(int j=0;j<rowSize;j++){
            if(fl){
                if(table[i][j]==' ')
                    ct1++;
                if(ct1==3){
                    ct1=0;
                    fl=0;
                    printf("\n");
                }
            }
            if(table[i][j]==' ')
            {
                temp[ct++]='\0';
                if(strcmp(temp,key1)==0)
                {
                    printf("Found '%s' horizontally with row size %d at %d. ",temp,rowSize,i);
                    printf("Secret message: ");
                    printf("%s ",temp);
                    fl=1;
                }
                ct=0;
            }
            else
                temp[ct++]=table[i][j];
        }
//--------------------------------------------------------------------------------------------------
// will get the matchmaking of diagonally
    int ma=colSize;
    if(ma<rowSize)
        ma=rowSize;
    
    int pos1=-1,pos2=-1;
    for(int tt1=0;tt1<colSize;tt1++)
    {
        ct=0;
        for(int di=0;di<ma;di++)
        {
            i=tt1+di;
            j=di;
            if(i>=colSize || j>=rowSize)
                break;
            if(table[i][j]==' ' && ct==0)
                continue;
            
            if(table[i][j]==' ')
            {
                temp[ct++]='\0';
        
                if(strcmp(temp,key1)==0)
                {
                    printf("Found '%s' diagonally with table size %d at %d. ",temp,rowSize,i);
                    printf("Secret message: ");
                    printf("%s ",temp);
                    
                    pos1=i;pos2=j;
                    fl=1;
                }
                ct=0;
            }
            else
                temp[ct++]=table[i][j];
        }
    }
//--------------------------------------------------------------------------------------------------
// will get the matchingmaking after the first diagonal
// will check after every row moved 1 space to the right followed by a diagonal
    for(int tt1=0;tt1<rowSize;tt1++)
    {
        ct=0;
        for(int di=0;di<ma;di++)
        {
            i=di;
            j=tt1+di;
            if(i>=colSize || j>=rowSize)
                break;
            
            if(table[i][j]==' ')
            {
                temp[ct++]='\0';
            
                if(strcmp(temp,key1)==0)
                {
                    printf("Found '%s' diagonally with table size %d at %d. ",temp,rowSize,i+1);
                    printf("Secret message: ");
                    printf("%s ",temp);
                    
                    pos1=i;pos2=j;
                    fl=1;
                }
                ct=0;
            }
            else
                temp[ct++]=table[i][j];
        }
    }
//--------------------------------------------------------------------------------------------------
    if(pos1!=-1)
    {
        int ct2=0;

        while(ct2<3 && pos1<colSize)
        {
            pos2++;
            pos1++;
            if(pos2>=rowSize)
            {
                pos2=0;
                pos1++;
            }
            if(pos1>=colSize)
            {
                break;
            }
            printf("%c",table[pos1][pos2]);
            if(table[pos1][pos2]==' ')
            {
                ct2++;
            }
        }
        printf("\n");
    }
}
//==================================================================================================

int main()
{
    FILE *fcipher;
    FILE *fkeys;
    count1=0;
    char c; //keys file into rows
//--------------------------------------------------------------------------------------------------
    fkeys = fopen("keys.txt", "r"); // getting the file of key words
    if (fkeys == NULL){
        printf("Input file open error. Exiting program...\n");
    }
    while(1)
    {
        int ret = fscanf(fkeys,"%s",keystrings[count1++]);
        if(ret == EOF)
        {
            count1--;
            break;
        }
    }
    fclose(fkeys);
//--------------------------------------------------------------------------------------------------
// Show how to read from a filefciphernter = fopen("inputText.txt","r");
    int e =0; //elements in cipherText
    int cipherChar = 0; // cipher characters
    fcipher = fopen("cipher.txt","rb");
    if( fcipher == NULL)
    {
        printf("Input file open error. Exiting program...\n");
    }
    while((c=fgetc(fcipher))!=EOF)
    {
        cipherText[e] = c;
        e++;
        cipherChar++;
    }
    fclose(fcipher);
    printf("\n");
//--------------------------------------------------------------------------------------------------
    int rowSize;
    printf("Welcome to the decoding program, where hidden messages are found inside of a text file.\n");
    displayIdentyfingInformation();
    printf("Read in %d keyWords, which are:\n",count1 );
    for(int i=0;i<count1;i++)
    printf("%s\n",keystrings[i] ); // quick // get // going
    printf("\n");
    printf("Read in %d cipherText characters.\n",cipherChar);
    while(1)
    {
        printf("\nChoose from the following options:\n");
        printf("\t1. Display a particular sized table\n");
        printf("\t2. Find all matching key word phrases\n");
        printf("\t3. Place key word phrase into a data file\n");// (NOT REQUIRED)
        printf("\tX. Exit the program\n");
        printf("*Enter your choice-> ");
        
        char userInput[25];
        scanf(" %s", userInput);
        if(strlen(userInput)!=1) // user must enter a character
        {
            printf("Invalid Input.\n"); // more than 1 character (try agian)
            continue;
        }
        printf("\n");
        if(userInput[0]=='1') // option 1
            makeRows(rowSize, cipherChar); // will create rows based on the user input
        else if(userInput[0]=='2') // option 2
        {
            for(int rs=15;rs<=132;rs++)
            {
                for(int temp=0;temp<count1;temp++)
                    matchWords(rs,cipherChar,keystrings[temp]); // take the function to check matching key words
            }
        }
        else if(userInput[0]=='3') // option 3 just for menu purposes
        {
            //otional
        }
        else if(userInput[0]=='x' || userInput[0]=='X') // will exit the program
            break;
        else
            printf("Invalid Input.\n");
        }
    return 0;
}
//=====================================================================================================
