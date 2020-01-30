/*----------------------------------
* guessNum.c
* 
* Author: Cesar Hernandez
* Class: CS 141, Spring 2017. Tues, 2pm Lab
* System: Xcode on an Imac
*
* ToDo: To write a program that interacts with the user, and predicts their final number!
*
* For instance:
 
| Author: Cesar Hernandez
| Program: #1, Guess Number
| TA: TA: Moumita Samanta, Tues 2pm
| Jan 23, 2017
|
| Welcome to the number guessing game!
| If you concentrate, sometimes you can connect to the electrons in the computer!
| Let's try it.  Think of a three digit number. (To make it harder, make the digits
| all different from each other). Type in your number: 275
|
| I'll help you with the math.  Lets randomize those digits by reversing them, and do a subtraction:
| 572  (The reversed digits)
| - 275  (The original number)
| =====
| 297
|
| Press 'Y' to continue or 'X' to exit... y
|
| Now lets again scramble the numbers by reversing them, and adding them this time:
| 297
| + 792
| =====
| ?
|
| Before you continue, take a look at my number guess written down on paper.
|
| Press 'D' to display the answer or 'X' to exit... d
| Answer is 1089.
|
| Press 'T' to test all possible combinations or 'X' to exit... x
*/

//---------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>

// Function to display program and information
void displayIdentyfingInformation()
{

printf ("Author Cesar Hernandez\n");
printf ("Program: #1, Guess Number\n");
printf ("TA: Moumita Samanta, Tues 2pm\n");
printf ("Jan 23, 2017\n");
printf("\n");
}

//---------------------------------------------------------------------------------------------------------------------------------
// Function to display instructions
void displayInstructions()
{
    printf("Welcome to the number guessing game!\n");
    printf("If you concentrate, sometimes you can connect to the electrons in the computer!\n");
    printf("Let's try it. Think of three digit number. (To make it harder, make the digits\n");
    printf("all different from each other). ");
}
//---------------------------------------------------------------------------------------------------------------------------------

    int main(){

    int userInput = 0;
    
    int x=0;
    int digOne = 0;
    int digTwo=0;
    int digThree = 0;
    int reverse=0;
    int subtract = 0;
    int addition = 0;
    int reverseRes = 0;
    
    char ch;
    char chr;
    char cha;
    
    int i=0;
    int count = 0;
        
//---------------------------------------------------------------------------------------------------------------------------------
    displayIdentyfingInformation();
    displayInstructions();
   
    printf("Type in your number:  ");
    scanf("  %d", &userInput);
    printf("\n");
        
//---------------------------------------------------------------------------------------------------------------------------------
// this step will reverse the userInput # (i.e. seperating the 3 whole digit #)
    x = userInput/10;        // new value x to store two digits
    
    digThree = userInput%10; // right most digit extracted
    digTwo= x%10;            // middle digit extracted
    digOne = x/10;           // left most digit extracted
    
    reverse = digThree*100 + digTwo*10 + digOne; // putting the digits back together into one whole number but reversed
    
    if   ((digThree == digTwo) || (digThree == digOne) ||(digTwo == digOne)){ //exclude all duplicates
        printf("*** All three digits are not different. Exiting program...\n");
        return 0;
    }
//---------------------------------------------------------------------------------------------------------------------------------
// this step we only one a 3 whole digit unique number and making sure the computation does not give a negative number
    if ((userInput > reverse) && (userInput < 999)){ //making sure the original number goes on top if its bigger than the reverse result
        
        printf("I'll Help you with the math. Lets randomize those digits by reversing them, and do a subtraction:\n");
        printf("   %d  (The original number)\n", userInput);
        printf(" -  %d  (The reverse digits)\n", reverse);
        printf("=======\n");
        
        subtract = userInput - reverse;
        printf("   %d\n", subtract);
    }
    
    else if ((reverse > userInput) && (userInput < 999)){ //making sure reverse number goes on top if it bigger than the userInput number
        printf("I'll Help you with the math. Lets randomize those digits by reversing them, and do a subtraction:\n");
        printf("   %d  (The reverse digits)\n", reverse);
        printf(" -  %d  (The original number)\n", userInput);
        printf("=======\n");
        
        subtract = reverse - userInput; //Ans
        printf("   %d\n", subtract);
    }
    
    else {
        printf("\n");
        printf("*** All three digits are not different. Exiting program...\n");
        return 0;
    }
//---------------------------------------------------------------------------------------------------------------------------------
    
    printf("\n");
    printf("Press 'Y' to continue or 'X' to exit... ");
    scanf(" %c", &ch);
        
//---------------------------------------------------------------------------------------------------------------------------------
// this step will reverse the "subtraction result" into 3 seperate digits
// the if statement will only go through if the user exclusively enters 'x' or 'X' to exit the program
        if ((ch =='X') || (ch =='x')){
            printf("Exiting program...\n");
            return 0;
    }
        
// anything else that the user enters will continue the process to reverse the result from the subtraction
        else {
            x = subtract/10;
            digThree = subtract%10;
            digTwo = x%10;
            digOne = x/10;
        
            reverseRes = digThree*100 + digTwo*10 + digOne; // this will put the subtraction result number back together but reversed
        
            printf("\n");
            printf("Now lets again scramble the numbers by reversing them, and adding them this time:");
            printf("\n");
            printf("   %d\n", subtract);
            printf(" + %d\n", reverseRes);
        
            addition = subtract + reverseRes;
            printf("=======\n");
            printf("     ?\n\n");
    }
//---------------------------------------------------------------------------------------------------------------------------------
    
    printf("Before you continue, take a look at my number guess written down on paper.\n");
    printf("\n");
    printf("Press 'D' to display the answer or 'X' to exit... ");
    scanf(" %c", &chr);
        
//---------------------------------------------------------------------------------------------------------------------------------
// the if statement will only go through if the user exclusively enters 'x' or 'X' to exit the program
    if ((chr == 'X')||(chr == 'x')){
        printf("Exiting Program...\n");
        return 0;
    }

// any character the user enters will display the result/answer for the addition
    else {
        printf("\n");
        printf("Answer is 1089.\n"); //program guessed your number!
    }
        
//---------------------------------------------------------------------------------------------------------------------------------
    
    printf("\n");
    printf("Press 'T' to test all possible combinations or 'X' to exit... ");
    scanf(" %c", &cha);
 
//---------------------------------------------------------------------------------------------------------------------------------
// the if statement will only go through if the user exclusively enters 'x' or 'X' to exit the program
    if ((cha == 'X')||(cha == 'x')){
        printf("Exiting program...\n");
        return 0;
    }
    
    else { // checking all values that don't equal 1089 along with duplicates
        printf("For all numbers between 1...1000, the values that do not work are:\n");
        
        // the for loop will help and count all numbers from 0 to 999
        // in order ot check all values that do not yield to 1089, the interaction code will just do to find those values
        // therefore will repeat the first computation part of the code
        for (i = 0; i <= 999 ; ++i){
            
            // seperating the digits (i's)
            x        = i/10;
            digThree = i%10;
            digTwo   = x%10;
            digOne   = i/100;
            
            reverse = digThree*100 + digTwo*10 + digOne; // putting the digits (i's) back together into one whole # but reversed
            
            // this if statement will exlude all digits/numbers that are duplicates
            if   ((digThree == digTwo) || (digThree == digOne) ||(digTwo == digOne)){ //comparing the numbers
                printf("  %d  ", i);
                ++count;
            }
            
        }  // FOR LOOP BRACE
        
        printf ("\n\n");
        printf ("There are %d values that do not work.\n\n", count);
        printf ("Thanks for playing!\n");
        
    }  // ELSE STATEMENT BRACE
        
//---------------------------------------------------------------------------------------------------------------------------------
    
    return 0;
    }
