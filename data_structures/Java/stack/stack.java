import java.lang.Math;
public class Mystack implements Stack{
  Object data[];
  int top=0,cap;
  Mystack(int size){
    data = new Object[size];
    cap = size;
  }
  public boolean IsFull(){
    if(top==cap){
      return true;
    }
    return false;
  }
  public boolean IsEmpty(){
    if(top == 0){
      return true;
    }
    return false;
  }
  public void Push(Object ele){
    if(IsFull()){
      System.out.println("Stack is Full, Can't add more elemeants.");
    }
    data[top] = ele;
    top++;
    System.out.println("Element added.");
  }
  public Object Pop(){
    if(IsEmpty()){
      System.out.println("Stack is empty, add element first.");
      return -1;
    }
    top--;
    return data[top];
  }
  public Object peek(){
    if(IsEmpty()){
      System.out.println("Stack is empty, add element first.");
      return -1;
    }
    return data[top-1];
  }

  public int Prec(char ele){
    switch(ele){
      case '+': 
      case '-': 
        return 1; 
     
      case '*': 
      case '/': 
        return 2; 
     
      case '^': 
        return 3; 
    }
    return -1;
  }

  public Object opration(int b,int a,char c){
    switch(c){
      case '+':
        return a+b;
      case '-':
        return a-b;                 
      case '*':
        return a*b;
      case '/':
        return a/b;
      // case '^':
      //   int n=1;
      //   boolean x=true;
      //   if(a==0)
      //     x=false;
      //   while(x){
      //     n*=a;
      //     a--;
      //     if(a>0)
      //       x=false;
      //   }
      //   return n;
      default:
        return -1;
    }
  }
}