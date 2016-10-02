//Coded By Hartej Singh

#include<stdio.h>
#include<stdlib.h>

typedef struct tnode{
struct tnode* lch;
int data;
struct tnode* rch;
}N;

N* getnode(){
N*newnode=(N*)malloc(sizeof(N));
newnode->rch=NULL;
newnode->lch=NULL;
newnode->data=-99999;
return newnode;
}


typedef struct stack{		//STACK FOR TRAVERSAL
struct tnode* arr[10];
int tos;
}S;

void push(S*s,N*ele){		//PUSH FUNCTION FOR STACK
	if(s->tos<10){
		s->arr[++(s->tos)]=ele;
	}
}

N*pop(S*s){			//POP FUNCTION FOR STACK
	if(s->tos>=0){
		N*temp=s->arr[s->tos--];
		return temp;
	}
	else
	return NULL;
}

void BuildTree(N* r){	//RECURSIVE INSERTION
	int data=0;
	N*t;
	printf("Enter a value for left child of %d (enter -1 to skip insertion at this location)",r->data);
	scanf("%d",&data);
	if(data!=-1){
		t=getnode();
		t->data=data;
		r->lch=t;
		BuildTree(r->lch);
	}
	printf("Enter a value for right child of %d (enter -1 to skip insertion at this location)",r->data);
	scanf("%d",&data);
	if(data!=-1){
		t=getnode();
		t->data=data;
		r->rch=t;
		BuildTree(r->rch);
	}
}

void Insert_Iterative(N*r,int d){	//ITERATIVE INSERTION
if(r->rch==NULL&&r->lch==NULL&&r->data==-99999){
	r->data=d;
	return;
	}
N*ptr=r;
N*temp;
while(1){
	printf("\nEnter 'l' for left child of %d 'r' for right child of %d : ",ptr->data,ptr->data);
	char s;
	scanf(" %c",&s);
	if(s=='l'&&ptr->lch!=NULL){
		ptr=ptr->lch;
		}
	else if(s=='r'&&ptr->rch!=NULL){
		ptr=ptr->rch;
		}
	else if(s=='l'&&ptr->lch==NULL){
		temp=getnode();
		temp->data=d;
		ptr->lch=temp;
		return;
		}
	else if(s=='r'&&ptr->rch==NULL){
		temp=getnode();
		temp->data=d;
		ptr->rch=temp;
		return;
		}
	else{
		printf("\nInvalid option!");
		}
	}
}

void Inorder_R(N*root){		//RECURSIVE INORDER
	if(root!=NULL){
		if(root->data==-99999){
			printf("Tree Empty");
			return;
		}
		Inorder_R(root->lch);
		printf("\t%d",root->data);
		Inorder_R(root->rch);
	}
}

void Preorder_R(N*root){		//RECURSIVE PREORDER
	if(root!=NULL){
		if(root->data==-99999){
			printf("Tree Empty");
			return;
		}
		printf("\t%d",root->data);
		Preorder_R(root->lch);
		Preorder_R(root->rch);
	}
}

void Postorder_R(N*root){		//RECURSIVE POSTORDER
	if(root!=NULL){
		if(root->data==-99999){
			printf("Tree Empty");
			return;
		}
		Postorder_R(root->lch);
		Postorder_R(root->rch);
		printf("\t%d",root->data);
	}
}

void Inorder_I(N*r){		//ITERATIVE INORDER
	if(r->data==-99999){
		printf("Tree Empty");
		return;
	}
	N*t=r;
	S s;
	s.tos=-1;
	while(1){
		while(t){
			push(&s,t);
			t=t->lch;
		}
		t=pop(&s);
		if(t==NULL)
			break;
		printf("\t%d",t->data);
		t=t->rch;
	}
}

void Preorder_I(N*r){		//ITERATIVE PREORDER
	if(r->data==-99999){
		printf("Tree Empty");
		return;
	}
	N*t=r;
	S s;
	s.tos=-1;
	while(1){
		while(t){
			printf("\t%d",t->data);
			push(&s,t);
			t=t->lch;
		}
		t=pop(&s);
		if(t==NULL)
			break;

		t=t->rch;
	}
}

void Postorder_I(N*r){		//ITERATIVE POSTORDER
	if(r->data==-99999){
		printf("Tree Empty");
		return;
	}
	N*t=r;
	S s1;
	S s2;
	s1.tos=-1;
	s2.tos=-1;
	push(&s1,r);
	while(s1.tos>=0){
		t=pop(&s1);
		if(t->lch)
			push(&s1,t->lch);
		if(t->rch)
			push(&s1,t->rch);
		push(&s2,t);
		}

	while(s2.tos>=0){
		t=pop(&s2);
		printf("\t%d",t->data);
	}
}

int height(N*root){
	int m,n;
	if(root==NULL){
		return -1;
		}
	else {
		m=1+height(root->lch);
		n=1+height(root->rch);
	}
	return((m>n)?m:n);
}

void main(){
	N*root=getnode();
	int ch,data;
	printf("\nOPERATIONS AVAILABLE:\n1.INSERT RECURSIVELY\n2.INSERT ITERATIVELY\n3.RECURSIVE DISPLAY\n4.ITERATIVE DISPLAY\n5.EXIT\n6.CALCULATE HEIGHT");
	while(1){
		printf("\nOperation:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				if(root->data==-99999){
					printf("\nEnter data for root node:");
					scanf("%d",&data);
					root->data=data;
				}
				BuildTree(root);
				break;
			case 2:
				printf("\nEnter data:");
				scanf("%d",&data);
				Insert_Iterative(root,data);
				break;
			case 3:
				printf("\n\nRECURSIVE INORDER:");
				Inorder_R(root);
				printf("\n\nRECURSIVE PREORDER:");
				Preorder_R(root);
				printf("\n\nRECURSIVE POSTORDER:");
				Postorder_R(root);
				break;
			case 4:
				printf("\n\nITERATIVE INORDER:");
				Inorder_I(root);
				printf("\n\nITERATIVE PREORDER:");
				Preorder_I(root);
				printf("\n\nITERATIVE POSTORDER:");
				Postorder_I(root);
				break;
			case 5:
				exit(0);
			case 6:
				printf("Height of the tree is: %d",height(root));
		}
	}
}
