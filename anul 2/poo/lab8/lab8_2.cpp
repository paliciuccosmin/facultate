#include <iostream>

#define MAX 10000

using namespace std;

template <class T>
class Stack {
    int top;

public:
    T a[MAX]; 

    Stack() {
        top = -1;
    }

    bool push(T x);
    T pop();
    T peek();
    bool isEmpty();
};


template <class T>
bool Stack<T>::push(T x) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    } else {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

template <class T>
T Stack<T>::pop() {
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    } else {
        T x = a[top--];
        return x;
    }
}

template <class T>
T Stack<T>::peek() {
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    } else {
        T x = a[top];
        return x;
    }
}

template <class T>
bool Stack<T>::isEmpty() {
    return (top < 0);
}


template <class T>
class Queue {
    int front, rear, size;
    T *array;

public:
    Queue(int s);
    bool enqueue(T x);
    T dequeue();
    T frontElement();
    bool isEmpty();
};


template <class T>
Queue<T>::Queue(int s) {
    front = rear = -1;
    size = s;
    array = new T[size];
}

template <class T>
bool Queue<T>::enqueue(T x) {
    if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
        cout << "Queue is Full";
        return false;
    } else if (front == -1) {
        front = rear = 0;
        array[rear] = x;
        return true;
    } else {
        rear = (rear + 1) % size;
        array[rear] = x;
        return true;
    }
}

template <class T>
T Queue<T>::dequeue() {
    if (front == -1) {
        cout << "Queue is Empty";
        return 0;
    } else {
        T x = array[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return x;
    }
}

template <class T>
T Queue<T>::frontElement() {
    if (front == -1) {
        cout << "Queue is Empty";
        return 0;
    } else {
        return array[front];
    }
}

template <class T>
bool Queue<T>::isEmpty() {
    return (front == -1);
}

int main() {
    
    Stack<int> intStack;
    intStack.push(0);
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    cout << intStack.pop() << " Popped from stack\n";
    cout << "Top element in stack: " << intStack.peek() << endl;

   
    Stack<char> charStack;
    charStack.push('A');
    charStack.push('B');
    charStack.push('C');
    cout << charStack.pop() << " Popped from stack\n";
    cout << "Top element in stack: " << charStack.peek() << endl;

   
    Queue<int> intQueue(5);
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);
    cout << intQueue.dequeue() << " Dequeued from queue\n";
    cout << "Front element in queue: " << intQueue.frontElement() << endl;

   
    Queue<char> charQueue(3);
    charQueue.enqueue('X');
    charQueue.enqueue('Y');
    charQueue.enqueue('Z');
    cout << charQueue.dequeue() << " Dequeued from queue\n";
    cout << "Front element in queue: " << charQueue.frontElement() << endl;

    return 0;
}
