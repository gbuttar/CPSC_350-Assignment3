#include <iostream>

using namespace std;

template <class T>
class GenStack{
public:
  GenStack(); // default constructor
  GenStack(int maxSize); //overloaded constructor
  ~GenStack(); //deconstructor

  void push(T element);
  T pop();

  bool isEmpty();
  bool isFull();
  T peak();

  int top;
  int mSize;

  T *myArray; //char pointer
};

template <class T>
GenStack<T>::GenStack(){ //default constructor
  myArray = new T[5];
  mSize = 5;
  top = -1;
}

template <class T>
GenStack<T>::GenStack(int maxSize){ //overloaded constructor
  myArray = new T[maxSize];
  mSize = maxSize;
  top = -1;
}

template <class T>
GenStack<T>::~GenStack(){ //deconstructor
  delete []myArray;
}

template <class T>
void GenStack<T>::push(T element) {
  if(isFull() == true) {

    T* newStack = new T[mSize * 2]; // create new stack with more space

    for( int i = 0; i < mSize; ++i){
      newStack[i] = myArray[i]; //new stack getting myArray items
    }
    delete myArray;
    myArray = newStack;
    mSize = mSize * 2; //changes the size
  }
  myArray[++top] = element; //putting element into stack
}

template <class T>  //removes value from top of stack
T GenStack<T>::pop(){
  if(isEmpty() == true){
    cout<<"Stack is empty! Cannot pop more elements."<<endl;
    exit(1);
  }
  else{
    return myArray[top--];
  }
}

template <class T> //checks if empty
bool GenStack<T>::isEmpty(){
  return top == -1;
}

template <class T> //checks if full
bool GenStack<T>::isFull(){
  return top == mSize -1;
}

template <class T> //shows whats at the top of the stack 
T GenStack<T>:: peak(){
  if(isEmpty() == true){
    cout<<"Stack is empty! There is nothing to peak!"<<endl;
    exit(1);
  }
  else{
    return myArray[top];
  }
}
