/**
	线性表:顺序表(顺序存储结构)
	操作的效率分析:
	1. 顺序表的插入和删除时间复杂度最高;需要循环移动元素;时间复杂度:O(n)
	2. 其他操作与数据元素个数无关.所以时间复杂度为:O(1)
 */
typedef struct {
	DataType list[MaxSize];// to save datas , MaxSize is the capacity
	int size;// to save the the element count
} SeqList;

// 顺序表的操作实现

// 1. initiate
void ListInitiate(SeqList *L) {
	L->size = 0;
}

// 2. get length
int ListLength(SeqList L) {
	return L.size;
} 

// 3. insert element
int ListInsert(SeqList *L,int i,DataType x) {
	int j;
	if (L->size >= MaxSize) {
		printf("SeqList if full\n");
		return 0;
	} else if(i < 0 || i > L->size) {
		printf("the location param 'i' is illegal \n");
		return 0;
	} else {
		/* prepare to insert,move behend element */
		for (j = L->size; j > i; j--)
			L->list[j] = L->list[j-1];
		L->list[i] = x;
		L->size++;
		return 1;
	}
}

// 4. delete element
int ListDelete(SeqList *L,int i,DataType *x) {
	int j ;
	if (L->size <= 0) {
		printf("list is empty, can't delete element\n");
		return 0;
	} else if(i < 0 || i > L->size - 1) {
		printf("illegal param i");
		return 0;
	} else {
		*x = L->list[i];
		// move to the front
		for (j = i + 1 ; j <= L->size - 1; j++)
			L->list[j-1] = L->list[j];
		L->size--;
		return 1;
	}
}

// 5. get element by index
int ListGet(SeqList L,int i,DataType *x) {
	if (i < 0 || i > L.size - 1) {
		printf("illegal arg i\n");
		return 0;
	} else {
		*x = L.list[i];
		return 1;
	}
}
