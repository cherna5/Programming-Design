

/* finalExamDriver.c
 2 pm version
 */
#include <stdio.h>
#include <stdlib.h>   // So sizeof() works
// Declare your struct here, so that the rest of the code works
// ...  struct Node {        };
struct Node{
    char data;
    struct Node *pNext;
};
//-----------------------------------------------------------------
void displayList( Node *pHead)  {
    // Add code here      // ...
    {
        Node *pTemp = pHead;
        while(pTemp != NULL)
        {
            printf("%d ", pTemp->data);
            pTemp = pTemp->pNext;
        }
        printf("\n");
    }


}
//-----------------------------------------------------------------
// Prepend a new node to the beginning of the list, as demonstrated in class.
// Also set the head, third, next-to-last and tail pointers.
void prependNode( Node *&pHead, Node *&pNextToLast, Node *&pTail, int valueToAdd)  {
    static int nodeCounter = 0;
    // Counts how many nodes are created.
    // Since it is static, its value remains between calls.
    // Get a new node
    Node *pTemp = (Node *) malloc( sizeof(struct Node));
    nodeCounter++;
    // Set the tail pointer if this node is the first one
    if( nodeCounter == 1) {
        pTail = pTemp;
    }
    // Set the nextToLast pointer if this node is the second one to be created
    if( nodeCounter == 2) {
        pNextToLast = pTemp;
    }
    // Store values and update pointers
    pTemp->data = valueToAdd;
    pTemp->pNext = pHead;
    pHead = pTemp;
}
//=========================
void deleteFirstNode(Node *&pHead) {
        Node *pTemp = pHead;
        pHead = pHead->pNext;
        delete pTemp;
    }
    
//========================
void max(Node **pHead)
    {
        Node *pTemp;
        int max=0;
        pTemp= *pHead;
        while(pTemp != NULL)
        {
            if(pTemp->data > max) {
                max = pTemp->data;
            }
            pTemp = pTemp->pNext;
        }
        printf("\nThe max Node Value is %d",max);
        printf("\n");
    }

//-----------------------------------------------------------------
int main()  {
    Node *pHead = NULL;
    Node *pThirdNode = NULL;
    Node *pNextToLast = NULL;
    Node *pTail = NULL;
    int userInput = 0;
    printf("Cesar Hernandez\n");
    printf("NET ID: Cherna83\n");
    printf("Lab @ 2pm\n");
    printf("Enter at least five numbers to be used, followed by -1: ");
    do {
        scanf("%d", &userInput);
        if( userInput != -1) {
            prependNode( pHead, pNextToLast, pTail, userInput);
        }
    } while( userInput != -1);
    printf("List is: ");
    displayList( pHead);
    // Set third node pointer, counting from the head of the list.
    //    This will crash if there aren't at least 3 nodes on the list.
    pThirdNode = pHead->pNext->pNext;
    printf("Third node has %d\n", pThirdNode->data);
    printf("Next-to-last node has %d\n", pNextToLast->data);
    printf("Tail of list has %d\n", pTail->data);
    // Write your code here      // ...
    
    printf("\n");
    deleteFirstNode( pHead);
    printf("modified List: ");
    displayList( pHead);
    max(&pHead);
    
    
    
    
    
    printf("\nExiting program \n");      
    return 0;  }// end main()
