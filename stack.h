#ifndef STACK_H
#define STACK_H
#include <iostream>

struct TreeNode{
    int val;
    TreeNode *left_child;
    TreeNode *right_child;

    TreeNode(int val) : val(val) , left_child(nullptr) , right_child(nullptr) {}

};

class TreeNodeStack{
    int top;
    inline const static int MaxSize = 10000;
    int currentSize;
    TreeNode * array[MaxSize];
    public:
        TreeNodeStack() : top(-1) , currentSize(0) {}

        int getCurrentSize(){
            return currentSize;
        }

        bool push(TreeNode * val){
            if (top >= MaxSize-1){
                std::cout << "Stack Overflow" << std::endl;
                return false;
            }else if(val == nullptr){
                return false;
            }else{
                array[++top] = val;
                currentSize++;
                return true;
            }
        }

        TreeNode * pop(){
            if(top != -1){ // if stack not empty

                currentSize--;
                return array[top--];;

            }else{
                // stack is empty
                std::cout << "Stack Underflow" << std::endl;
                return nullptr;
            }

        }
        void peek(){
            if(top==-1){
                std::cout << "Stack is empty" <<std::endl;
            }else{
                std::cout <<"Top of stack: "<< array[top]->val <<std::endl;
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
