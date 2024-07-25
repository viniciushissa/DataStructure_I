#include <stdio.h>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct node{
	void* dataPtr;
	struct node*link;

}NODE;

NODE* criarNode(void* itemPtr){
	NODE* nodePtr;
	nodePtr = (NODE*) malloc(sizeof(NODE));
	nodePtr -> dataPtr = itemPtr;
	nodePtr -> link = NULL;
	return nodePtr;
}


int main(int argc, char *argv[]) {
	int* newData;
	int* nodeData;
	NODE* node;
	
	newData = (int*)malloc(sizeof(int));
	*newData = 7;
	node = criarNode(newData);
	
	
	nodeData = (int*)node->dataPtr;
	printf("Data from node 1: %d\n",*nodeData);
	
    newData = (int*)malloc(sizeof(int));
    *newData= 75;
    node->link = criarNode(newData);
    
    nodeData = (int*)node->link->dataPtr;
	printf("Data from node 2: %d\n",*nodeData);
    
	
	
	return 0;
}
