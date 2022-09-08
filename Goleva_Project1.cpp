//Anastasia Golev  CSC 727
//
//  Goleva_Project1.cpp
//  CSC727_Project1
//
//  Created by Anastasia Golev on 9/14/21.
/* Program to concatinate 2 stacks together using operator + */

#include <iostream>
using namespace std;
//example of operator overloading
template<class T>
class Stack {
public:
Stack(int n);
Stack(Stack<T>& s); //copy constructor
~Stack() { []stackPtr;} // destructor
Stack<T> operator + (const Stack<T>& s2) const; //overloading +
Stack<T>& operator = (const Stack<T>& s); //overloading assignment
bool Push (const T& element); // Push element onto stack
bool Pop (T& element); // Pop element off stack
private:
int size; // size of stack
int top; // location of the top element
T *stackPtr; // pointer to stack
bool Isempty (){return (top == -1);}
bool Isfull () {return (top == size - 1);}
};

// overloading assignemnt
template<class T>
Stack<T>& Stack<T> :: operator = (const Stack<T>& s) {
    if (&s != this) {
        delete [ ] stackPtr;
        size=s.size;
        top=s.top;
        stackPtr= new T [size];
        for (int i=0; i < size; i++) stackPtr[i]=s.stackPtr[i];
    }
    return *this;
}
template<class T>
Stack<T>  Stack<T> :: operator + (const Stack<T>& s2) const
{
    // do your work here
    // + operator what is does is to concatenate two stacks s1 and s2
    // example s1={1,3} and s2={4,6,7,8}, suppose that size s1=3, and
    //size s2=7 // top of stack1 = 1 (top element = 3}, top of stack2 = 3
    //(top element = 8) totsize= 10 (that is size of s1 + size of s2)
    // temp={1,3,4,6,7,8}, where the top is 5 and the top element is 8
    
    /* create an integer variable totsize = size of stack1 + size of stack2,
     plus 2 to account for index 0 for each stack */
    int totsize = (size) + (s2.size ) + 2;
    //create a Stack<T> variable called temp, of size totsize, to hold the
    //concatination of s1 and s2
    Stack<T> temp(totsize);
    //allocate space for totsize elements of type T in temp stack
    temp.stackPtr = new T[totsize];
    //now push elements of stack into temp
    for (int i = 0; i < size; i++){
        temp.Push(stackPtr[i]);
    }
    // push remaining elements of s2 into temp
    for (int i = 0; i < s2.size ; i++){
        temp.Push(s2.stackPtr[i]);
     }
    return temp;
}
//copy constructor
template<class T>
Stack<T> :: Stack (Stack<T>& s) {
    size=s.size;
    stackPtr = new T [size];
    top=s.top;
    for (int i=0; i <= size; i++)
        stackPtr[i]=s.stackPtr[i]; // allocate space for size elements of type T
}


template<class T>
Stack<T> :: Stack (int n)
{
    size = n > 0 ? n :10;
    top = -1; // empty stack
    stackPtr = new T [size]; // allocate space for size elements of type T
}

template<class T>
bool  Stack<T>::Push (const T& element)
{
    if ( !Isfull() ) { stackPtr[++top]=element; return (true); }
   return (false);
}
template<class T>
bool Stack<T>::Pop  (T& element)
{
if ( !Isempty() ) { element=stackPtr[top--]; return true;
}
  return false;
}
int main() {
    
    int size1, size2, element;
    cout << endl << "Enter size of stack1: " ;
    cin >> size1;
    cout << endl << "Enter size of stack2: " ;
    cin >> size2;
    Stack< int > intS1 (size1), intS2 (size2), intS3(1);
    
    //populate intS1 using a for loop to iterate through user inputs and
    //push elements into stack
    for (int i = 0; i < size1; i++){
        cout << endl << "Enter element of stack1: ";
        cin >> element;
        intS1.Push(element);
    }
    
    //populate intS2 using a for loop to iterate through user inputs and
    //push elements into stack
    for (int i = 0; i < size2; i++){
        cout << endl << "Enter element of stack2: ";
        cin >> element;
        intS2.Push(element);
    }

    intS3 = intS1 + intS2;
    cout << endl << "displaying S3"; cout << endl << "=============";
    while ( intS3.Pop(element))
    cout << endl << "element: " << element; cout << endl;
}


/* Output
 
 
 Enter size of stack1: 2

 Enter size of stack2: 4

 Enter element of stack1: 1

 Enter element of stack1: 3

 Enter element of stack2: 4

 Enter element of stack2: 6

 Enter element of stack2: 7

 Enter element of stack2: 8

 displaying S3
 =============
 element: 8
 element: 7
 element: 6
 element: 4
 element: 3
 element: 1
 Program ended with exit code: 0
 
 
 
 */
