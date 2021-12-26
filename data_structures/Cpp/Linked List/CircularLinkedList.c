#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
void traverselist(struct node * head)
{
    struct node * p=head;
    do
    {
      printf("%d\n",p->data);
      p=p->next;
    } while (p!=head);
    
}
struct node * insertatfirst(struct node * head, int data)
{
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    struct node * p=head;
    while (p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
    
}
int main()
{
    struct node * head=(struct node *)malloc(sizeof(struct node));
    struct node * second=(struct node *)malloc(sizeof(struct node));
    struct node * third=(struct node *)malloc(sizeof(struct node));
    struct node * fourth=(struct node *)malloc(sizeof(struct node));
    head->data=4;
    head->next=second;
    second->data=5;
    second->next=third;
    third->data=6;
    third->next=fourth;
    fourth->data=7;
    fourth->next=head;
    printf("list before the insertion\n");
    traverselist(head);
    head=insertatfirst(head,3);
    printf("list after insertion is\n");
    traverselist(head); 
    return 0;
}
