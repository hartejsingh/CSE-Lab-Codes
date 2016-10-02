//Coded By Hartej Singh
//Only for positive numbers
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
struct node* prev;
int data;
struct node* next;
}N;

N* getnode(){
N* newnode=(N*)malloc(sizeof(N));
newnode->prev=newnode->next=NULL;
return newnode;
}

void insert_back(N*h,int data){
if(h->next==NULL){
	N*temp=getnode();
	temp->prev=h;
	temp->next=h;
	h->next=temp;
	temp->data=data;
	h->prev=temp;
	return;
	}
N*temp=getnode();
N*ptr=h;
while(ptr->next!=h){
	ptr=ptr->next;
	}
ptr->next=temp;
temp->prev=ptr;
temp->data=data;
temp->next=h;
h->prev=temp;
}

void addition(N*h1,N*h2,N*h3){
N*ptr1=h1->prev;
N*ptr2=h2->prev;
int carry=0;
while(ptr1!=h1&&ptr2!=h2){
	int temp=ptr1->data+ptr2->data;
	if(carry==1){
		temp=temp+1;
		carry=0;
		}
	if(temp>=10){
		temp=temp-10;
		carry=1;
		}
	insert_back(h3,temp);
	ptr1=ptr1->prev;
	ptr2=ptr2->prev;
	}
if(carry==1){
	insert_back(h3,carry);
		}
while(ptr1!=h1){
	insert_back(h3,ptr1->data);
	ptr1=ptr1->prev;
	}
while(ptr2!=h2){
	insert_back(h3,ptr2->data);
	ptr2=ptr2->prev;
	}
}

/*void display(N* h){
int i;
if(h->next==NULL){
	printf("List is empty");
	return;
	}
N* ptr=h->next;
while(ptr->next!=h){
	printf("\t%d",ptr->data);
	ptr=ptr->next;
	}
printf("\t%d",ptr->data);
}*/

void display(N*h,int token){
if(h->next==NULL&&h->prev==NULL){
	printf("List is empty!");
	return;
	}
N*ptr=h->next;
if(token==1){
	while(ptr!=h){
		printf("\t%d",ptr->data);
		ptr=ptr->next;
		}
}
else{
ptr=h->prev;
while(ptr!=h){
	printf("\t%d",ptr->data);
	ptr=ptr->prev;
	}
}
}


void main(){
printf("\nEnter the operation to be performed:\n1.Insert Number 1\n2.Insert Number 2\n3.Display\n4.Perform Addition\n5.Exit");
int op=0;
int i=0;
char data[100];
char data2[100];
N* h1=getnode();
N* h2=getnode();
N* h3=getnode();
while(1){
	printf("\nOP:");
	scanf("%d",&op);
	switch(op){
		case 1:
		printf("Enter data:");
		scanf("%s",data);
		for(i=0;i<strlen(data);i++){
			insert_back(h1,(int)(data[i]-'0'));
			}
		break;
		case 2:
		printf("Enter data:");
		scanf("%s",data2);
		for(i=0;i<strlen(data2);i++){
			insert_back(h2,(int)(data2[i]-'0'));
			}
		break;
		case 3:
		display(h1,1);
		printf("\n\n");
		display(h2,1);
		printf("\n\n");
		break;
		case 4:
		addition(h1,h2,h3);
		printf("\nAddition Result:\n");
		display(h3,0);
		printf("\n\n");
//		break;
		case 5:
		exit(0);
		}
	}
}
