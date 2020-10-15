#include <iostream> 
#include <queue> 

using namespace std; 

void showPriQueue(priority_queue <int> pri_queue) {
    while (!pri_queue.empty()){ 
        cout << pri_queue.top()<<" "; 
        pri_queue.pop(); 
    } 
} 

int main (){ 
    priority_queue <int> myqueue;
    int number_values;

    cout << "Enter the total number of element: ";
    cin >> number_values;

    for (int index = 0; index < number_values; index++) {
        myqueue.push(index); 
    }

    cout << "Values in myqueue : ";
    showPriQueue(myqueue); 
    cout << "\nSize of myqueue : " << myqueue.size() << endl;
    cout << "First element of the myqueue : " << myqueue.top() << endl; 
    cout << "Pop element from myqueue ";
    myqueue.pop(); 
    cout << "\nValues in myqueue after pop : ";
    showPriQueue(myqueue); 

    return 0; 
} 
