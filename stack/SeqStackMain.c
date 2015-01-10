#include <stdio.h>
#include <stdlib.h>
#define MaxStackSize 100
typedef int DataType;
#include "SeqStack.h"

void main(void){
	SeqStack myStack;
	int i,x;
	
	StackInitiate(&myStack);
	for(i = 0; i < 10 ; i++){
		if (StackPush(&myStack,i+1) == 0){
			printf("Push happened error!\n");
			return ;
		}
	}

	if (StackTop(myStack,&x) == 0) {
		printf("error!\n");
		return ;
	}else
		printf("The element on the top is :%d\n",x);
	
	printf("loop the elements :\n");
	while(StackNotEmpty(myStack)) {
		StackPop(&myStack,&x);
		printf("%d   ",x);
	}
	
}
