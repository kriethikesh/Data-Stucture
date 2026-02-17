#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *create(){
    int d;
    printf("\nEnter the Data : ");
    scanf("%d",&d);

    struct node *nn = (struct node*)malloc(sizeof(struct node));
    nn->data = d;
    nn->next = NULL;
    return nn;
}

int count_node(struct node *p){
    if(p == NULL)
        return 0;

    int c = 0;
    struct node *temp = p;

    do{
        c++;
        temp = temp->next;
    }while(temp != p);

    return c;
}

void display(struct node *p){
    if(p == NULL){
        printf("\nEmpty Circular Linked List\n");
        return;
    }

    struct node *temp = p;
    printf("\nThe Circular Linked List is : ");

    do{
        printf("%d -> ", temp->data);
        temp = temp->next;
    }while(temp != p);

    printf("(back to head)\n");
}

void insert_begin(struct node **p){
    struct node *nn = create();

    if(*p == NULL){
        nn->next = nn;
        *p = nn;
    }
    else{
        struct node *last = *p;

        while(last->next != *p){
            last = last->next;
        }

        nn->next = *p;
        last->next = nn;
        *p = nn;
    }
}

void append(struct node **p){
    struct node *nn = create();

    if(*p == NULL){
        nn->next = nn;
        *p = nn;
    }
    else{
        struct node *last = *p;

        while(last->next != *p){
            last = last->next;
        }

        last->next = nn;
        nn->next = *p;
    }
}

void insert_position(struct node **p){
    int pos, c = count_node(*p);

    printf("Enter the Position : ");
    scanf("%d",&pos);

    if(pos < 1 || pos > c+1){
        printf("\nInvalid Position\n");
        return;
    }

    if(pos == 1){
        insert_begin(p);
    }
    else if(pos == c+1){
        append(p);
    }
    else{
        struct node *nn = create();
        struct node *temp = *p;

        for(int i = 1; i < pos-1; i++){
            temp = temp->next;
        }

        nn->next = temp->next;
        temp->next = nn;
    }
}

void delete_begin(struct node **p){
    if(*p == NULL){
        printf("\nList is Empty\n");
    }
    else if((*p)->next == *p){   // Only one node
        free(*p);
        *p = NULL;
    }
    else{
        struct node *last = *p;

        while(last->next != *p){
            last = last->next;
        }

        struct node *temp = *p;
        last->next = temp->next;
        *p = temp->next;

        free(temp);
    }
}

void delete_end(struct node **p){
    if(*p == NULL){
        printf("\nList is Empty\n");
    }
    else if((*p)->next == *p){   // Only one node
        free(*p);
        *p = NULL;
    }
    else{
        struct node *temp = *p;
        struct node *pre = NULL;

        while(temp->next != *p){
            pre = temp;
            temp = temp->next;
        }

        pre->next = *p;
        free(temp);
    }
}

void delete_position(struct node **p){
    if(*p == NULL){
        printf("\nList is Empty\n");
        return;
    }

    int pos, c = count_node(*p);

    printf("Enter the Position to delete : ");
    scanf("%d",&pos);

    if(pos < 1 || pos > c){
        printf("\nInvalid Position\n");
    }
    else if(pos == 1){
        delete_begin(p);
    }
    else if(pos == c){
        delete_end(p);
    }
    else{
        struct node *temp = *p;
        struct node *pre = NULL;

        for(int i = 1; i < pos; i++){
            pre = temp;
            temp = temp->next;
        }

        pre->next = temp->next;
        free(temp);
    }
}

int main(){
    struct node *head = NULL;
    int choice;

    while(1){
        printf("\n\n_____________ MENU _____________");
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
            case 8: printf("\nNumber of Nodes = %d\n", count_node(head)); break;
            case 9: exit(0);
            default: printf("\nInvalid Choice\n");
        }
    }

    return 0;
}