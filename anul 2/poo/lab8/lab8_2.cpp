#include<iostream>

#define MAX 10000

using namespace std;
template< class T >
class Stack { 
    int top; 
  
public: 
    T a[MAX]; // Maximum size of Stack 
  
    Stack() { 
        top = -1;
    } 
    bool push(T x); 
    T pop(); 
    T peek(); 
    bool isEmpty(); 
}; 
 template <class T> 
bool Stack<T>::push(T x) 
{ 
    if (top >= (MAX - 1)) { 
        cout << "Stack Overflow"; 
        return false; 
    } 
    else { 
        a[++top] = x; 
        cout << x << " pushed into stack\n"; 
        return true; 
    } 
} 
template <class T>
T Stack<T>::pop() 
{ 
    if (top < 0) { 
        cout << "Stack Underflow"; 
        return 0; 
    } 
    else { 
        T x = a[top--]; 
        return x; 
    } 
} 
template <class T>
T Stack<T>::peek() 
{ 
    if (top < 0) { 
        cout << "Stack is Empty"; 
        return 0; 
    } 
    else { 
        T x = a[top]; 
        return x; 
    } 
} 
  template <class T>
  bool Stack<T>::isEmpty() 
{ 
    return (top < 0); 
} 

int main(){
    Stack <int> s;
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop() << " Popped from stack\n"; 
  
    cout << "Top element is : " << s.peek() << endl; 

}