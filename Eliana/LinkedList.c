#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    struct intNode {int data; struct intNode *next;}; //node structure
    typedef struct intNode in; //typedef to allow us of 'in' rather than 'struct intNode'
    srand(time(0)); //seed rand() with current time

    in * headNode = (in*)malloc(sizeof(in));//allocate memory for the first node in the list
    in * node = headNode;//node be the last node in the list
    int r=rand()%49+1;
    while (r !=49)//generates a random number from 1 to 49 and dynamically adds it to a linked list
    {
        node->data=r; 
        if ((r=rand()%49+1)!=49)
        {
            node->next = (in*)malloc(sizeof(in)); //allocate memory for next node, only done when next node must be created
            node = node->next; //node should always be the last node
        }
    }
    while (headNode != NULL)//prints each node and frees the memory
    {
        if (headNode != node) printf("%d, ",headNode->data);
        else printf("%d\n", headNode->data);
        in * last = headNode; //remember last node to be freed
        headNode=headNode->next;
        free(last);
    }
}