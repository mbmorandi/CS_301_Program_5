#include <iostream>
#include <new>

//node class
template<typename T>
struct Node{
    T value;
    Node* next;
};

class FullStack{
    //handles fullstack error
};

class EmptyStack{
    //handles empty stack error
};

//stack class
template<typename T>
class Stack {
    private:
        Node<T>* topNode;
    public:
        Stack();
        void push(T value);
        T pop();
        T top();
        bool isEmpty();
        bool isFull();
        void print();
        ~Stack();

};
//constructor
template<typename T>
Stack<T>::Stack(){
    topNode = nullptr;
}
//function: push
//precondition: stack exists
//postcondition: new value added to stack
template<typename T>
void Stack<T>::push(T value){
    //check if full before pushing
    if(isFull()){
        return;
    } else {
        Node<T>* newNode = new Node<T>();
        newNode->value = value;
        newNode->next = topNode;
        topNode = newNode;
    }
}
//function: pop
//precondition: stack exists
//postcondition: value removed from top of stack
template<typename T>
T Stack<T>::pop(){
    //check if empty before popping
    if(isEmpty()){
        throw EmptyStack();
    } else {
        Node<T>* temp = topNode;
        topNode = topNode->next;
        T val = temp->value;
        delete temp; 
        return val; 
    }
}

//function: top
//precondition: stack exists
//postcondition: value of top returned
template<typename T>
T Stack<T>::top(){
    if(isEmpty()){
        throw EmptyStack();
    }
    return topNode->value;

}
//function: isempty
//precondition: stack exists
//postcondition: returns true if stack is empty
template<typename T>
bool Stack<T>::isEmpty(){
    return (topNode == nullptr);
}
//function: isFull
//precondition: stack exists
//postcondition: returns true if full
template<typename T>
bool Stack<T>::isFull(){
    try {
        Node<T>* testNode = new Node<T>();
        delete testNode;
        return false;
    }
    catch(const std::bad_alloc& e) {
        return true;
    }
}
//function: print
//precondition: stack exists
//postcondition: stack values printed to terminal
template<typename T>
void Stack<T>::print(){
    Node<T>* temp = topNode;
    while(temp){
        std::cout << temp->value << std::endl;
        temp = temp->next;
    }
}
//destructor
//precondition: stack exists
//postcondition: the contents of stack are destroyed - DESTROYED
template<typename T>
Stack<T>::~Stack(){
    Node<T>* temp = topNode;
    while(topNode){
        topNode = topNode->next;
        delete temp;
        temp = topNode;
    }
}


