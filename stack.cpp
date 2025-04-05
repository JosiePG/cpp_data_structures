#include <iostream>
using namespace std;

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

        bool push(int val){
            if (top >= MaxSize-1){
                cout << "Stack Overflow" << endl;
                return false;
            }else{
                array[++top] = val;
                currentSize++;
                return true;
            }
        }

        void pop(){
            if(top != -1){ // if stack not empty

                int x = array[top--];
                currentSize--;
                return;

            }else{
                // stack is empty
                cout << "Stack Underflow" << endl;
                return;
            }

        }
        int peek(){
            if(top==-1){
                cout << "Stack is empty" <<endl;
                return -1;
            }else{
                cout <<"Top of stack: "<< array[top] <<endl;
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

        void remove_lower(int val){
            Stack temp_stack;

            while(!isEmpty()){
                if(array[top] >= val){
                    temp_stack.push(array[top]);
                }
                pop();
            }

            while(!temp_stack.isEmpty()){
                push(temp_stack.array[temp_stack.top]);
                temp_stack.pop();
            }

            return;
        }

        void remove_upper(int val){
            Stack temp_stack;

            while(!isEmpty()){
                if(array[top] <= val){
                    temp_stack.push(array[top]);
                }
                pop();
            }

            while(!temp_stack.isEmpty()){
                push(temp_stack.array[temp_stack.top]);
                temp_stack.pop();
            }

            return;
        }
};


int main(){

    Stack stack;
    stack.peek();
    stack.push(3);
    stack.peek();
    stack.push(4);
    stack.push(2);
    stack.remove_upper(3);
    stack.peek();
    cout << stack.getCurrentSize() << endl;;
    return 0;
}