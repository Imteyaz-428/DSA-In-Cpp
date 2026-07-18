#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int f =0, r =-1;

void enque(int val) {
    if(r == MAX -1) {
        printf("queue is empty");
        return;
    }
    
    r++;
    queue[r] = val;
}
void dequeue() {
    if(f == MAX -1 || f>r) {
        printf("queue underflow");
        return;
    }
    f++;
}
void display() {
    if(f == MAX -1 || f>r) {
        printf("underflow condition");
    }
    for(int i=f; i<=r; i++) {
        printf("%d \n", queue[i]);
        
    }
}

int main() {
    
    int choice, val;
    while(1) {
        printf("press 1 for enqueue : \n");
        printf("press 2 for dequeue  :\n");
        printf("press 3 for display  :\n");
        printf("prees 4 for exit :\n");
        printf("please enter your choice :");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
            printf("please enter the val for enque :");
            scanf("%d", &val);
            enque(val);
            break;

            case 2:
            dequeue();
            break;

            case 3 :
            display();
            break;

            case 4:
            exit(0);

            default :
            printf("invalid choice");
        }
    }
    return 0;
}
