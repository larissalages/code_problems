#include<iostream>
using namespace std;
int f=-1;
int r=-1;
int N=3;
int Q[3];

void Enq(){int x;
	if((f==0 && r==N-1) || f-r==1){
		cout<<"Queue if Full!"<<endl;
		return;
	}
	cout<<"Enter element to insert: ";
	cin>>x;
	r=(r+1)%N;
	Q[r]=x;
	if(f==-1)
		f=0;
}

void Deq(){
	if(f==-1){
		cout<<"Queue is Empty!"<<endl;
		return;
	}
	if(f==r){
		cout<<"Removed element is "<<Q[f];
		f=r=-1;
		return;
	}
	cout<<"Removed element is "<<Q[f];
	f=(f+1)%N;
}

void Peek(){
	if(f==-1){
		cout<<"Queue is Empty!"<<endl;
		return;
	}
	cout<<"Front: "<<Q[f];
	cout<<" Rear: "<<Q[r]<<endl;
}

int main(){int n=0;
	while(n!=4){
		cout<<endl<<"1.Enqueue"<<endl<<"2.Dequeue"<<endl<<"3.Peek"<<endl<<"4.Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>n;
		cout<<endl;
		switch(n){
			case 1:	Enq();
					break;
			case 2: Deq();
					break;
			case 3: Peek();
					break;
			case 4: return 0;
			default: break;
		}
	}	
	return 0;
}
