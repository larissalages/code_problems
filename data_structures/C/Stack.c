#include<stdio.h>
#include<stdlib.h>
void PUSH(int *s,int *t){
    int val;
    printf("Enter the value : ");
    scanf("%d",&val);
    ++(*t);
    s[*t]=val;
}
void POP(int *s,int *t){
    printf("Poped value : %d\n",s[*t]);
    --(*t);
}
void DISP(int *s,int t){
    for(int i=t;i>=0;i--){
        printf("| %d |\n",s[i]);
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter the size of stack : ");
    scanf("%d",&n);
    int stack[n],t=-1,c=1;
    while(c){
        printf("Press 1 to PUSH\nPress 2 to POP\nPress 3 to DISP\nPress 0 to EXIT\n");
        scanf("%d",&c);
        switch (c) {
            case 1:
                if(t==n-1){
                    printf("STACK OVERFLOW!!\n");
                }else{
                    PUSH(stack,&t);
                }
                break;
            case 2:
                if(t==-1){
                    printf("STACK IS EMPTY!!\n");
                }else{
                    POP(stack,&t);
                }
                break;
            case 3:
                DISP(stack,t);
                break;
            case 0:
                break;
            default:printf("Enter valid operator !\n");
                break;
        }
    }
    return 0;
}


