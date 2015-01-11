/* 单链表的实现  */

typedef struct Node {
	DataType data;
	struct Node *next ;
} SLNode;

/* 带头结点操作实现 */
// 1. initiate
void ListInitiate(SLNode * * head) {
	if ((*head = (SLNode *)malloc(sizeof(SLNode))) == NULL) {
		exit(1);
	}
	(*head)->next = NULL ;
}

// 2. length
int ListLength(SLNode *head) {
	SLNode *p = head ;
	int size = 0 ;
	
	while (p->next != NULL) {
		p = p->next ;
		size++;
	}
	return size ;
}

// 3. Insert
int ListIsert(SLNode *head,int i ,DataType x) {
	SLNode *p,*q;
	int j;

	p = head;
	j = -1;
	
	while(p->next != NULL && j < i - 1) {
		p = p->next ;
		j++;
	}

	if (j != i -1) {
		printf("insert index error\n");
		return 0;
	}

	if ((q = (SLNode *)malloc(sizeof(SLNode))) == NULL)
		exit(1) ;
	q->data = x;
	
	q->next = p->next;
	p->next = q;
	return 1 ;
}

// 4. delete
int ListDelete(SLNode *head,int i,DataType *x){
	SLNode *p,*s;
	int j;

	p = head;
	j = -1;
	while(p->next != NULL && p->next != NULL && j < i-1) {
		p = p->next;
		j++;
	}

	if (j != i-1){
		printf("index error\n");
		return 0;
	}

	s = p->next;
	*x = s->data;
	p->next = p->next->next;
	feee(s);
	return 1;
}

// 5.get
int ListGet(SLNode *head,int i,DadtaType *x){
	SLNode *p;
	int j;

	p = head;
	j = -1;
	while(p->next != NULL && j<i){
		p = p->next;
		j++;
	}

	if(j != i) {
		printf("index error\n");
		return 0;
	}

	*x = p->data;
	return 1;
}

// 6.destroy
void Destroy(SLNode **head) {
	SLNode *p,*p1;
	p = *head;
	while(p != NULL) {
		p1 = p;
		p = p->next;
		free(p1);
	}
	*head = NULL;
}
