#include <iostream>

using namespace std;

class Node{
    public:
        int val;
        Node *next;

        Node(int val) : val(val) , next(nullptr) {}
};

class DynamicStack{
    public:
        Node *head;

        DynamicStack(): head(nullptr) {}

        // functions 

        //push
        void push(int val){

            Node *newNode = new Node(val) ;

            if(head == nullptr){
                // stack is empty
                head = newNode ;
                return;
            }else{
                // stack is not empty
                Node *temp = head;
                head = newNode;
                head->next = temp;
                return;

            }

        }

        //pop

        int pop(){
            if(head==nullptr){
                cout << "Stack Underflow" << endl;
                return 0;
            }else{
                Node *popped = head;
                head = head->next;
                return popped->val;
            }
        }

        //peek

        int peek(){
            if(head==nullptr){
                // stack is empty
                cout << "Stack is empty" << endl;
                return 0;

            }else{
                // stack is not empty
                cout << "Top element is : " << head->val << endl;
                return head->val;
            }
        }

        //isEmpty

        bool isEmpty(){
            if(head==nullptr){
                return true;
            }else{
                return false;
            }
        }



};

int main(){
    DynamicStack stack;
    stack.peek();
    stack.push(2);
    stack.peek();
    cout << stack.isEmpty() << endl;
    cout << stack.pop() << endl;;
    cout << stack.isEmpty() << endl;
    return 0;
}