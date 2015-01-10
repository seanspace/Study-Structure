/*堆栈:顺序堆栈 */

// 顺序堆栈的结构体.
typedef struct {
	DataType stack [MaxStackSize];
	int top;
} SeqStack;

// 操作实现
// 1. initiate
void StackInitiate(SeqStack *S) {
	S->top = 0; // 定义初始栈顶下标值.
}

// 2. is not empty
int StackNotEmpty(SeqStack S) {
	if (S.top <= 0)
		return 0 ;
	else
		return 1 ;
}

// 3. push,return 1 if success,fail return 0
int StackPush(SeqStack *S,DataType x) {
	if (S->top >= MaxStackSize){
		printf("stack is full\n") ;
		return 0 ;
	} else {
		S->stack[S->top] = x ;
		S->top++;
		return 1;
	}
}

// 4. pop, return 1 if succes,fail return 0
int StackPop(SeqStack *S,DataType *d) {
	if(S->top <= 0) {
		printf("Stack is empty!\n");
		return 0;
	} else {
		S->top--;
		*d = S->stack[S->top];
		return 1;
	}
}

// 5. getTop
int StackTop(SeqStack S,DataType *d){
	if (S.top <= 0){
		printf("Statck is empty!\n");
		return 0;
	} else {
		*d = S.stack[S.top-1];
		return 1 ;
	}
}


