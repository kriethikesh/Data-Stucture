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
void append(struct node **p) {
	int d;
	printf("Enter the Data : ");
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
void delete_begin(struct node **p){
	if(*p==NULL)	printf("No Node in List");
	else{
		struct node*temp=*p;
		*p=temp->next;
		free(temp);
	}
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
int main() {
	struct node *head=NULL;
    printf("\n____________________________MENU_____________________________");
	printf("\n1.Insert data\n2.Delete data\n3.Display List\n4.Exit\n");
	while(1) {
		int choice,d;
		printf("\nEnter the Choice : ");
		scanf("%d",&choice);
		switch(choice) {
		case 1:
			append(&head);
			break;
		case 2:
			delete_begin(&head);
			break;
		case 3:
			display(head);
			break;
		case 4:
			printf("_____________________Exiting______________________");
			return 0;
		default:
			printf("!!!!!!!!!!!!!!!!!!Invalid Choice!!!!!!!!!!!!!!!!!");
			break;
		}
	}
	return 0;
}