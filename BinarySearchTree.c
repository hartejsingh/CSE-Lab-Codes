//Coded By Hartej Singh

#include<stdio.h>
#include<stdlib.h>

typedef struct bst{
	struct bst* lch;
	struct bst* rch;
	int data;
}B;

B* getnode(){
	B* newnode=(B*)malloc(sizeof(B));
	newnode->lch=NULL;
	newnode->rch=NULL;
	return newnode;
}

void inorder(B*root){
	if(root!=NULL){
		inorder(root->lch);
		printf("\t%d",root->data);
		inorder(root->rch);
	}
}

void preorder(B*root){
	if(root!=NULL){
		printf("\t%d",root->data);
		preorder(root->lch);
		preorder(root->rch);
	}
}

void ins_bst_it(B*r,int ele){
	B*temp=getnode();
	temp->data=ele;
	B*ptr=r;
	B*prev=NULL;
	int ch=0;
	while(ptr!=NULL){
		prev=ptr;
		if(ele>ptr->data){
			ptr=ptr->rch;
			ch=1;
		}
		else if(ele<ptr->data){
			ptr=ptr->lch;
			ch=2;
		}
		else{
			printf("%d already exists",ele);
			return;
		}
	}
	if(ch==1){
		prev->rch=getnode();
		prev->rch->data=ele;
	}
	else {
		prev->lch=getnode();
		prev->lch->data=ele;
	}

}

B* search(B*r,int key){
	if(r!=NULL){
		if(r->data==key){
			return r;
		}
		else if(key>r->data){
			return search(r->rch,key);
		}
		else{
			return search(r->lch,key);
		}
		return NULL;
	}
}

B*searchdelete(B*r,int key){
	if(r==NULL){
		return NULL;
	}
	else if(key<r->data){
		r->lch=searchdelete(r->lch,key);
	}
	else if(key>r->data){
		r->rch=searchdelete(r->rch,key);
	}
	else if(r->lch==NULL){
		B*temp=r->rch;
		free(r);
		return temp;
	}
	else if(r->rch==NULL){
		B*temp2=r->lch;
		free(r);
		return temp2;
	}
	else{
		B*temp3=r->rch;
		while(temp3->lch!=NULL){
			temp3=temp3->lch;
		}
		r->data=temp3->data;
		r->rch=searchdelete(r->rch,temp3->data);
	}
	return r;
}

void main(){
	B*b=getnode();
	b->data=-99999;
	printf("\nEnter the operation to be performed:\n1.Insert\n2.Display\n3.Search\n4.Search and delete\n5.Exit");
	int op,ele,key;
	while(1){
		printf("\nOperation:");
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("\nEnter element:");
				scanf("%d",&ele);
				if(b->data==-99999){
					b->data=ele;
					continue;
				}
				ins_bst_it(b,ele);
				break;
			case 2:
				inorder(b);
				printf("\n");
				preorder(b);
				break;
			case 3:
				printf("Enter key:");
				scanf("%d",&key);
				B*ptr=search(b,key);
				if(ptr!=NULL)
					printf("%p\t%d",ptr,ptr->data);
				else
					printf("Requested key NA");
				break;
			case 4:
				printf("Enter element to be deleted:");
				scanf("%d",&key);
				B*ptr2=searchdelete(b,key);
				break;
			case 5:
				exit(0);
		}
	}
}
