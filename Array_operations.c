#include <stdio.h>
int arr[100],pos,ele,choice;;
void insert(int *n){
    printf("Enter the position and element : ");
    scanf("%d %d",&pos,&ele);
    if(pos>=1 && pos<50){
        for(int i=*n;i>=pos;i--){
            arr[i]=arr[i-1];
        }
        arr[pos-1]=ele;
        (*n)++;
    }
    else{
        printf("Invalid position");
    }
}
void del(int *n){
    printf("Enter the position : ");
    scanf("%d",&pos);
    if(pos>=1 && pos<50){
        for(int i=pos-1;i<*n-1;i++){
            arr[i]=arr[i+1];
        }
        (*n)--;
    }
    else{
        printf("Invalid position");
    }
}
void search(int *n){
    int found=0;
    printf("Enter the element : ");
    scanf("%d",&ele);
    for(int i=0;i<*n;i++){
        if(ele==arr[i]){
            found=1;
            break;
        }
    }
    if(found){
        printf("%d is there in the Array",ele);
    }
    else{
        printf("%d is not found",ele);
    }
}
int main() {
    int n;
    printf("Enter the No. of elements in the Array : ");
    scanf("%d",&n);
    printf("Enter the array elements : ");
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    printf("_______________MENU________________");
    while(1){
        printf("\n\n1. Insert an element\n2. Delete an element\n3. Display the array\n4. Search an element\n5. Exit\nEnter the choice : ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            insert(&n);
            break;
        case 2:
            del(&n);
            break;
        case 3:
            printf("The array is : ");
            for(int i=0;i<n;i++){
                printf("%d ",*(arr+i));
            }
            break;
        case 4:
            search(&n);
            break;
        case 5:
            return 0;
            break;
        default:
            printf("!!!!!!!!!!!Invalid choice!!!!!!!!!!!");
            break;
        }
    }
    return 0;
}