#include <iostream>
#include <new>
template<typename T>
struct Node{
    T value;
    Node* next;
};

class FullStack{

};

class EmptyStack{

};

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
template<typename T>
Stack<T>::Stack(){
    topNode = nullptr;
}
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
template<typename T>
T Stack<T>::top(){
    if(isEmpty()){
        throw EmptyStack();
    }
    return topNode->value;

}
template<typename T>
bool Stack<T>::isEmpty(){
    return (topNode == nullptr);
}
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

template<typename T>
void Stack<T>::print(){
    Node<T>* temp = topNode;
    while(temp){
        std::cout << temp->value << std::endl;
        temp = temp->next;
    }
}

template<typename T>
Stack<T>::~Stack(){
    Node<T>* temp = topNode;
    while(topNode){
        topNode = topNode->next;
        delete temp;
        temp = topNode;
    }
}


