#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
};
struct node *create(int d) {
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=d;
	nn->next=NULL;
	return nn;
}
void insert_begin(struct node **p) {
	int d;
	printf("Enter the Data to be added at Begining : ");
	scanf("%d",&d);
	struct node *nn;
	nn=create(d);
	if(*p==NULL) {
		*p=nn;
	}
	else {
		nn->next=*p;
		*p=nn;
	}
}
void append(struct node **p) {
	int d;
	printf("Enter the Data to be added at End : ");
	scanf("%d",&d);
	struct node *nn;
	nn=create(d);
	if(*p==NULL) *p=nn;
	else {
		struct node *temp;
		temp=*p;
		while(temp->next!=NULL) {
			temp=temp->next;
		}
		temp->next=nn;
	}
}
int count_node(struct node *p) {
	int c=0;
	struct node *temp;
	temp=p;
	while(temp!=NULL) {   //1 2 3 4 NULL
		c++;
		temp=temp->next;
	}
	return c;
}
void display(struct node *p) {
	struct node *temp;
	temp=p;
	while(temp!=NULL) {
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
void insert_position(struct node **p) {
	int pos,count=count_node(*p);
	printf("Enter the Postion : ");
	scanf("%d",&pos);
	if(pos==1)  insert_begin(p);
	else if(pos==count+1)    append(p);
	else if(pos>count+1)    printf("Out of Bound");
	else {
		int d;
		printf("Enter the Data : ");
		scanf("%d",&d);
		struct node *nn;
		nn=create(d);
		struct node *temp;
		temp=*p;
		for(int i=1; i<pos-1; i++) {
			temp=temp->next;
		}
		nn->next=temp->next;
		temp->next=nn;
	}
}
void delete_begin(struct node **p){
	if(*p==NULL)	printf("No Node in List");
	else{
		struct node*temp=*p;
		*p=temp->next;
		free(temp);
	}
}
void delete_end(struct node **p){
	if(*p==NULL)	printf("No Node in List");
	else if((*p)->next==NULL){
		free(*p);
		*p=NULL;
	}
	else{
		struct node*temp=*p,*pre;
		while(temp->next!=NULL){
			pre=temp;
			temp=temp->next;
		}
		pre->next=NULL;
		free(temp);
	}
}
void delete_position(struct node **p){
	int pos,c=count_node(*p);
	printf("Enter the position of node to be deleted : ");
	scanf("%d",&pos);
	if(c==0)    printf("!!! LL is Empty !!!\n");
	else if(pos==1)	delete_begin(p);
	else if(pos==c)	delete_end(p);
	else if(pos>c || pos<=0)	printf("Invalid Position\n");
	else{
		struct node *temp=(*p),*pre;
		for(int i=1;i<pos;i++){
			pre=temp;
			temp=temp->next;
		}
		pre->next=temp->next;
		free(temp);
	}
}
int main() {
	struct node *head=NULL;
	while(1) {
		int choice,d;
		printf("\n\n____________________________MENU_____________________________");
		printf("\n1.Insert Node at Begining\n2.Insert Node at End\n3.Insert Node at Position\n4.Delete Node at Begining\n5.Delete Node at End\n6.Delete Node at a Position\n7.Display List\n8.Count the Nodes\n9.Exit\n\n");
		printf("Enter the Choice : ");
		scanf("%d",&choice);
		switch(choice) {
		case 1:
			insert_begin(&head);
			break;
		case 2:
			append(&head);
			break;
		case 3:
			insert_position(&head);
			break;
		case 4:
			delete_begin(&head);
			break;
		case 5:
			delete_end(&head);
			break;
		case 6:
			delete_position(&head);
			break;
		case 7:
			display(head);
			break;
		case 8:
			printf("The Number of Nodes Present is %d",count_node(head));
			break;
		case 9:
			printf("_____________________Exiting______________________");
			return 0;
		default:
			printf("!!!!!!!!!!!!!!!!!!Invalid Choice!!!!!!!!!!!!!!!!!");
			break;
		}
	}
	return 0;
}