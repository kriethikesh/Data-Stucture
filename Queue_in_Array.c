#include <stdio.h>
#define MAX 100
int queue[MAX],front=-1,rear=-1;
int isfull(){
    if(rear==MAX-1 && front==0){
        return 1;
    }
    return 0;
}
void enqueue(int d)
{
    if(!isfull()){
        if(front==-1)   front++;
        queue[++rear]=d;
    }
    else{
        printf("\nQueue Overflow\n");
    }
}
int deque(){
    if(front==-1){
        printf("\nQueue Underflow");
        return -1;
    }
    else{
        int ele=queue[front];
        if(front == rear)
            front=rear=-1;
        else{
            front++;
        }
        return ele;
    }
    return -1;
}
void display(){
    if(front==-1){
        printf("\nQueue is Empty\n");
        return;
    }
    printf("Queue : ");
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
}
int main() {
    printf("____MENU____\n");
    printf("1.Add an Element\n");
    printf("2.Delete an Element\n");
    printf("3.Display Queue\n");
    printf("4.Exit\n");
    while(1){
        int choice,d,ele;
        printf("\nEnter the Choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the Data : ");
                scanf("%d",&d);
                enqueue(d);
                break;
            case 2:
                ele=deque();
                if(ele!=-1)
                    printf("\nThe Element removed is : %d",ele);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n---Exiting---\n");
                return 0;
                break;
            default:
                printf("!!!Invalid Choice!!!\n");
                break;
        }
    }
    return 0;
}