#ifndef STACK_H
#define STACK_H
#include <iostream>

class Stack{
    int top;
    inline const static int MaxSize = 4;
    int currentSize;
    int array[MaxSize];
    public:
        Stack() : top(-1) , currentSize(0) {}

        int getCurrentSize(){
            return currentSize;
        }

        bool push(auto val){
            if (top >= MaxSize-1){
                std::cout << "Stack Overflow" << std::endl;
                return false;
            }else{
                array[++top] = val;
                currentSize++;
                return true;
            }
        }

        void pop(){
            if(top != -1){ // if stack not empty

                array[top--];
                currentSize--;
                return;

            }else{
                // stack is empty
                std::cout << "Stack Underflow" << std::endl;
                return;
            }

        }
        int peek(){
            if(top==-1){
                std::cout << "Stack is empty" <<std::endl;
                return -1;
            }else{
                std::cout <<"Top of stack: "<< array[top] <<std::endl;
                return array[top];
            }
        }

        bool isEmpty(){
            if(top<0){
                return true;
            }else{
                return false;
            }
        }

};

#endif
