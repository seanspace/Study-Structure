/**
	线性表应用:
	1. 建立一个线性表
	2. 插入10条数据;
	3. 删除第5个元素;
	4. 遍历显示所有元素;
*/
#include <stdio.h>
#define MaxSize 100
typedef int DataType ;
#include "SeqList.h"

void main(void) {
	SeqList myList ;
	int i,x;
	
	ListInitiate(&myList);
	for (i = 0 ; i < 10 ; i++) {
		if (ListInsert(&myList,i,i+1) == 0) {
			printf("error \n");
			return ;
		}
	}

	if (ListDelete(&myList,4,&x) == 0) {
		printf("error \n");
		return ;
	}

	for (i = 0; i < ListLength(myList); i++) {
		if (ListGet(myList,i,&x) == 0) {
			printf("error \n");
			return ;
		} else {
			printf("%d    ",x);
		}
	}
}
