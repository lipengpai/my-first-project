//在头部插入一个节点
struct Node{
	int data;
	struct Node* next;
}; 
struct Node* head=NULL;
void Insert(int x){
//	struct Node* temp; 未定义,应该先分配内存
   struct Node* temp=(struct Node*)malloc(sizeof(struct Node)); 
	temp->data=x;
	temp->next=NULL;
     if(head!=NULL){
	temp->next=head;
	head=temp;}
}
void Print(){
	struct Node* temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
//任意位置插入节点
void Insertx(int x,int n){
	struct Node* temp1=(struct Node*)malloc(sizeof(struct Node));
	temp1->data=x;
	temp1->next;
	if(n==1){
		temp1->next=head;
		head=temp1;
		return;
	}
	struct Node* temp2=head;//创造遍历到n-1个位置的指针
	for(int i=0;i<n-2;i++){
		temp2=temp2->next;
	} 
	temp1->next=temp2->next;
	temp2->next=temp1;
} 
struct Node* Delete(struct Node* head,int n){
	struct Node* temp=head;
	if (n == 1) { // 删除头节点
        head = head->next;
        free(temp);
        return head;
    }
    for(int i=0;i<n-2;i++){
    	temp=temp->next;
	}
	struct Node* temp1=temp->nxet;
	temp->next=temp1->next;
	free(temp1);
	return head;
} 
struct Node* Find(int n){
	struct Node* temp=head;
	for(int i=0;i<n-1;i++){
		temp=temp->next;
	}
	return temp;
}
struct ListNode{
	int data;
	struct ListNode* prev;
	struct ListNOde* next;
};
struct ListNode* Insert_in_end(struct ListNode* head,int x){
	struct ListNode* temp=head;
	struct ListNode* newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
	newnode->data=x;
	newnode->prev=NULL;
	newnode->next=NULL;
	if(head==NULL){
		head=newnode;
		return head;
	}
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
	//temp=newnode;
	return head;
}
struct ListNode* Insert_in_head(struct ListNode* head,int x){
	struct ListNode* newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
	newnode->data=x;
	newnode->prev=NULL;
	newnode->next=NULL;
	if(head==NULL){
		head=newnode;
		return head;
	}
	struct ListNode* temp=head;
	newnode->next=temp;
	temp->prev=newnode;
	head=newnode;
	return head;
}
struct Node* Push(struct Node* top,int x){
	struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->data=x;
	newnode->next=NULL;
	if(top==NULL){
		top=newnode;
	}
	else {
		struct Node* temp=top;
		newnode->next=temp;
		top=newnode;
	}
	return top;
}
struct Node* Pop(struct Node* top){
	if(top==NULL){
		return NULL;
	}
	struct Node* temp=top->next;
	free(top);
	top=temp;
	return top;
}
int StackEmpty(struct Node* head){
	if(head==NULL)return 1;
	return 0;
}
void Reserve(char c[],int n){
	stack<char> S;
	for(int i=0;i<n;i++){
		S.push(c[i]);
	}
	for(int i=0;i<n;i++){
		c[i]=S.top();
		S.pop();
	}
}
struct Stack{
	int top;
	char* elements;
};
void push(struct Stack* stack,char c){
	if(top==maxSize-1){
		return -1;
	}
	else {
	stack->top++;
	stack->elements[stack->top]=c;
   }
}
void pop(struct Stack* stack){
	if(stack->top==-1){
		return -1;
	}
	else {
	    top--;
	}
}
int isempty(struct Stack stack){
	if(stack==NULL||stack->top==-1){
		return 1;
	}
	return 0;
}
void reserve(struct Stack* stack){
	int* temp=(int*)malloc(MAXSize*sizeof(int));
	int cnt=0;
    while(top!=-1){
    	temp[cnt++]=pop(stack);
	}
	for(int i=0;i<cnt;i++){
		stack->elements[++(stack->top)]=temp[i];
	}
}
struct Stack* stack;
  stack->top=-1;
int Ispair(char* str){
	int len=strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]=='('||'['||'{'){
			push(stack,str[i]);
		}
		else if(str[i]==')'||']'||'}'){
				if(stack->top==-1||stack->elements[stack->top]=='('&&str[i]!=')'||stack->elements[stack->top]=='['&&str[i]!=']'||stack->elements[stack->top]=='{'&&str[i]!='}'){
					return 0;
				}
				else {
					pop(stack);
				}
			}
		}
		if(isempty(stack)){
			return 1;
		}
		else {
			return 0;
		}
	}

