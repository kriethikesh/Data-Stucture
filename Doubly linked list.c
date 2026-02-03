#include <stdlib.h>
#include <stdio.h>

struct node {
	int data;
	struct node *next,*prev;
};
struct node *create() {
	int d;
	printf("Enter the Data to be Added : ");
	scanf("%d",&d);
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	nn->data=d;
	nn->next=NULL;
	nn->prev=NULL;
	return nn;
}
void display_node(struct node *p) {
	if(p==NULL)    printf("\nEmpty Linked List\n");
	else {
		printf("\nThe Linked List is : ");
		struct node *temp=p;
		while(temp!=NULL) {
			printf("%d->",temp->data);
			temp=temp->next;
		}
        printf("NULL\n");
	}
}
int count_node(struct node *p){
    int c=0;
	if(p==NULL)    return c;
	else{
		struct node *temp=p;
		while(temp!=NULL) {
		    c++;
			temp=temp->next;
		}
	}
	return c;
}
void insert_begin(struct node **p) {
	struct node *nn=create();
    if(*p==NULL)    *p=nn;
    else{
        (*p)->prev=nn;
        nn->next=*p;
        *p=nn;
    }
}
void append(struct node **p){
    struct node *nn=create();
    if(*p==NULL)    *p=nn;
    else{
        struct node *temp=*p;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nn;
        nn->prev=temp;
    }
}
void insert_position(struct node **p){
    int pos,c=count_node(*p);
    printf("Enter the Position of Node to be Inserted : ");
    scanf("%d",&pos);
    if(pos>c+1 || pos<1)    printf("\n------Invalid Position------\n");
    else if(pos==1) insert_begin(p);
    else if(pos==c+1)   append(p);
    else{
        struct node *temp=(*p);
        struct node *nn=create();
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        nn->next=temp->next;
        temp->next=nn;
        nn->prev=temp;
        temp->next->prev=nn;
    }
}
void delete_begin(struct node **p){
    if(*p==NULL)    printf("\n-----Empty Linked-----\n");
    else{
        struct node *temp=*p;
        (*p)=temp->next;
        if(*p!=NULL)
            (*p)->prev=NULL;
        free(temp);
    }
}
void delete_end(struct node **p){
    if(*p==NULL)    printf("\n-----Empty Linked-----\n");
    else{
        struct node *temp=*p;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->prev->next=NULL;
        free(temp);
    }
}
void delete_position(struct node **p){
    int pos,c=count_node(*p);
    printf("Enter the Position to be deleted : ");
    scanf("%d",&pos);
    if(*p==NULL)    printf("\n-----Empty Linked-----\n");
    else if(pos==1)  delete_begin(p);
    else if(pos==c) delete_end(p);
    else if(pos>c || pos<1) printf("\nInvalid Position\n");
    else{
        struct node *temp=*p;
        for(int i=1;i<pos;i++){
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}
int main()
{
    struct node *head=NULL;
	int choice;
    printf("_________________MENU__________________");
    while(1){
        printf("\n1.Insert Node at Begining\n2.Insert Node at End\n3.Insert Node at Position\n4.Delete Node at Begining\n5.Delete Node at End\n6.Delete Node at Position\n7.Display Linked List\n8.Count Nodes\n9.Exit\n");
        printf("\nEnter the Choice : ");
        scanf("%d",&choice);
        switch(choice){
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
                display_node(head);
                break;
            case 8:
                printf("\nThe Number of Node in LL is %d",count_node(head));
                break;
            case 9:
                return 0;
            default:
                printf("!!!!Invalid choice!!!!\n");
                break;
        }
    }

	return 0;
}
