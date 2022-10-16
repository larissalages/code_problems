#include <iostream>

using namespace std;
class node
{
public:
    int data;
    node*next;
    node*prev;
};
void insert_at_end(node* &head,int value)
{
    node*h=head;
    node* new_node=new node;
    new_node->data=value;
    node*temp=head;
    if(head==NULL)
    {
        head=new_node;
        new_node->next=head;
    }
    else
    {
        while(temp->next!=h)
        {
            temp=temp->next;
        }
        node*temp2=temp->next;
        temp->next=new_node;
        new_node->next=head;
    }
}
void delete_duplicate(node* &head)
{
    node*temp1=head;
    node*temp2=head->next;
    while(temp1->next!=head)
    {
        temp2=temp1;
        while(temp2!=head)
        {
            if(temp1->data==temp2->data)
            {
                node* dup=temp2;
                temp1->next=temp1->next->next;
                temp2=temp1->next;
                delete dup;

            }
            else
            {
                temp2=temp2->next;
            }
        }
        temp1=temp1->next;
    }


}
void display(node*  head)
{
    node*temp=head;
    do
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    } while(temp!=head);
    cout<<head->data<<endl;
}

int main()
{
   node* head=NULL;
    cout<<"Elements of 1st list:"<<endl;
    insert_at_end(head,12);
    insert_at_end(head,11);
    insert_at_end(head,12);
    insert_at_end(head,21);
    insert_at_end(head,41);
    insert_at_end(head,43);
    insert_at_end(head,21);
    display(head);
    //cout<<"After delete:"<<endl;
    delete_duplicate(head);
    display(head);
}
