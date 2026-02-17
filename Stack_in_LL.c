#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

int isempty(){
    return top == NULL;
}

void push(int data){
    struct node *nn = (struct node*)malloc(sizeof(struct node));

    if(nn == NULL){
        printf("\nStack Overflow (Heap Full)\n");
        return;
    }

    nn->data = data;
    nn->next = top;
    top = nn;

    printf("Inserted %d into stack\n", data);
}

int pop(){
    if(isempty()){
        printf("\nStack Underflow\n");
        return -1;
    }

    struct node *temp = top;
    int val = temp->data;

    top = temp->next;
    free(temp);

    return val;
}

int peek(){
    if(isempty()){
        printf("\nStack is Empty\n");
        return -1;
    }

    return top->data;
}

void display(){
    if(isempty()){
        printf("\nStack is Empty\n");
        return;
    }

    struct node *temp = top;
    printf("\nStack Elements (Top to Bottom): ");

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int choice, data;

    while(1){
        printf("\n\n_____ STACK USING LL _____");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Peek");
        printf("\n4.Display");
        printf("\n5.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                push(data);
                break;

            case 2:
                data = pop();
                if(data != -1)
                    printf("Popped: %d\n", data);
                break;

            case 3:
                data = peek();
                if(data != -1)
                    printf("Top Element: %d\n", data);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}