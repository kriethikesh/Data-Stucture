#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node* create(){
    int d;
    printf("\nEnter Data : ");
    scanf("%d",&d);

    struct node *nn = (struct node*)malloc(sizeof(struct node));
    nn->data = d;
    nn->next = nn;
    nn->prev = nn;

    return nn;
}

int count_node(struct node *head){
    if(head == NULL)
        return 0;

    int c = 0;
    struct node *temp = head;

    do{
        c++;
        temp = temp->next;
    }while(temp != head);

    return c;
}

void display(struct node *head){
    if(head == NULL){
        printf("\nList is Empty\n");
        return;
    }

    struct node *temp = head;
    printf("\nDCLL : ");

    do{
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }while(temp != head);

    printf("(back to head)\n");
}

void insert_begin(struct node **head){
    struct node *nn = create();

    if(*head == NULL){
        *head = nn;
    }
    else{
        struct node *last = (*head)->prev;

        nn->next = *head;
        nn->prev = last;

        last->next = nn;
        (*head)->prev = nn;

        *head = nn;
    }
}

void append(struct node **head){
    struct node *nn = create();

    if(*head == NULL){
        *head = nn;
    }
    else{
        struct node *last = (*head)->prev;

        nn->next = *head;
        nn->prev = last;

        last->next = nn;
        (*head)->prev = nn;
    }
}

void insert_position(struct node **head){
    int pos, c = count_node(*head);
    printf("Enter Position : ");
    scanf("%d",&pos);

    if(pos < 1 || pos > c+1){
        printf("\nInvalid Position\n");
        return;
    }

    if(pos == 1){
        insert_begin(head);
    }
    else if(pos == c+1){
        append(head);
    }
    else{
        struct node *nn = create();
        struct node *temp = *head;

        for(int i = 1; i < pos-1; i++){
            temp = temp->next;
        }

        nn->next = temp->next;
        nn->prev = temp;

        temp->next->prev = nn;
        temp->next = nn;
    }
}

void delete_begin(struct node **head){
    if(*head == NULL){
        printf("\nList Empty\n");
    }
    else if((*head)->next == *head){
        free(*head);
        *head = NULL;
    }
    else{
        struct node *last = (*head)->prev;
        struct node *temp = *head;

        *head = temp->next;

        (*head)->prev = last;
        last->next = *head;

        free(temp);
    }
}

void delete_end(struct node **head){
    if(*head == NULL){
        printf("\nList Empty\n");
    }
    else if((*head)->next == *head){
        free(*head);
        *head = NULL;
    }
    else{
        struct node *last = (*head)->prev;

        last->prev->next = *head;
        (*head)->prev = last->prev;

        free(last);
    }
}

void delete_position(struct node **head){
    if(*head == NULL){
        printf("\nList Empty\n");
        return;
    }

    int pos, c = count_node(*head);
    printf("Enter Position to Delete : ");
    scanf("%d",&pos);

    if(pos < 1 || pos > c){
        printf("\nInvalid Position\n");
    }
    else if(pos == 1){
        delete_begin(head);
    }
    else if(pos == c){
        delete_end(head);
    }
    else{
        struct node *temp = *head;

        for(int i = 1; i < pos; i++){
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        free(temp);
    }
}

int main(){
    struct node *head = NULL;
    int choice;

    while(1){
        printf("\n\n_____ DCLL MENU _____");
        printf("\n1.Insert at Beginning");
        printf("\n2.Insert at End");
        printf("\n3.Insert at Position");
        printf("\n4.Delete from Beginning");
        printf("\n5.Delete from End");
        printf("\n6.Delete from Position");
        printf("\n7.Display");
        printf("\n8.Count Nodes");
        printf("\n9.Exit");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1: insert_begin(&head); break;
            case 2: append(&head); break;
            case 3: insert_position(&head); break;
            case 4: delete_begin(&head); break;
            case 5: delete_end(&head); break;
            case 6: delete_position(&head); break;
            case 7: display(head); break;
            case 8: printf("\nTotal Nodes = %d\n", count_node(head)); break;
            case 9: exit(0);
            default: printf("\nInvalid Choice\n");
        }
    }
}