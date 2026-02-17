#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

int isfull(){
    return top == MAX-1;
}

int isempty(){
    return top == -1;
}

void push(int data){
    if(!isfull()){
        stack[++top] = data;
    }
    else{
        printf("\n!!! Stack Overflow !!!\n");
    }
}

int pop(){
    if(!isempty()){
        return stack[top--];
    }
    else{
        printf("\n!!! Stack Underflow !!!\n");
        return -1;
    }
}

int peek(){
    if(!isempty()){
        return stack[top];
    }
    else{
        printf("\nStack is Empty\n");
        return -1;
    }
}

void display(){
    if(isempty()){
        printf("\nStack is Empty\n");
        return;
    }

    printf("The Stack : ");
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main(){
    int choice, data;

    while(1){
        printf("\n\n______ STACK MENU ______");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;

            case 2:
                data = pop();
                if(data != -1)
                    printf("Popped element: %d\n", data);
                break;

            case 3:
                data = peek();
                if(data != -1)
                    printf("Top element: %d\n", data);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}