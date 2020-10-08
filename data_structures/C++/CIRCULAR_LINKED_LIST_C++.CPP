#include<iostream>
using namespace std;
	int size;

struct Node
{
	int data;
	struct Node *next;
}*first=NULL,*last=NULL;
void create()
{
	struct Node *t;
	first=new Node;
	last =new Node;
	cout<<"enter size of linked list"<<endl;
	cin>>size;
	cout<<"enter elements"<<endl;
	cin>>first->data;
    first->next=first;
    last=first;



	for(int i=2;i<=size;i++)
	{   t=new Node;
		cin>>t->data;
		t->next=last->next;
		last->next=t;
		last=t;
	}


}
void Display(struct Node *p)
{
     do
	{
		cout<<p->data<<" "<<endl;
		p=p->next;
	}while(p!=first);
}
void insert(struct Node *p,int pos,int x)
{
	Node *t;
	if(pos==1)
	{
		t=new Node;
		t->data=x;
		if(first==NULL)
		{
			first=t;
			first->next=first;
		}
		else
		{
			p=first;
			while(p->next!=first)
			p=p->next;
			p->next=t;
			t->next=first;
			first=t;
		}
	}
	else
	{
		p=first;
		for(int i=1;i<pos-1;i++)
		p=p->next;
		t=new Node;
		t->data=x;
		t->next=p->next;
		p->next=t;

	}
}
int search(struct Node *p,int el)
{   int flag=0;
	do
	{
		if(p->data==el)
		{
			flag=1;
			return flag;
			break;
		}
		else
		flag=0;
		p=p->next;
	}while(p!=first);
	return flag;
}
int del(struct Node *p,int pos)
{   struct Node *q;
    int x=-1;
	if(pos==1)
	{
		p=first;
		while(p->next!=first)
		p=p->next;
		x=first->data;
		if(p==first)
		{
			delete first;
			first=NULL;
		}
		else
		{
			p->next=first->next;
			q=first;
			first=first->next;
			delete q;
		
		}
		
	}
	else
	{
		p=first;
		for(int i=1;i<pos-1;i++)
		p=p->next;
		q=p->next;
		x=q->data;
		delete q;
	}
	return x;
}
int main()
{    int choice;
	cout<<"......MENU......."<<endl;
          cout<<"1)CREATE"<<endl;
          cout<<"2)DISPLAY"<<endl;
          cout<<"3)INSERT"<<endl;
          cout<<"4)SEARCH"<<endl;
          cout<<"5)DELETE"<<endl;
          do
          {

          	cout<<"enter choice";
          	cin>>choice;
          	switch(choice)
          	{
          		case 1: create();break;
			    case 2: Display(first);break;
			    case 3: int el,pos;
			            cout<<"enter position and element"<<endl;
			            cin>>pos>>el;
				        insert(first,pos,el);break;
				case 4: int searchel;
				        cout<<"enter element to be searched:";
				        cin>>searchel;
				        int z;
				        z=search(first,searchel);
				        if(z==1)
				        cout<<"search successful"<<endl;
				        else
				        cout<<"unsuccessful"<<endl;break;
				case 5: int pos1;
				         cout<<"enter position of node you want to delete:";
				         cin>>pos1;
				         int y;
				         y=del(first,pos1);
				         cout<<y<<" is deleted "<<endl;break;

			  }
		  }while(choice>0);
		  return 0;
}
