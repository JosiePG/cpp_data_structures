#include <iostream>

using namespace std;

class Node {
    public :
        int val;
        Node *next;
    
    Node(int val): val(val) , next(nullptr) {}
};

class SinglyLinkedList{
    public:
        Node *head;

        //constructor 
        SinglyLinkedList() : head(nullptr) {}

        // functions


        void printList(){
            // prints out linked list starting from head

            if(head == nullptr){
                // list is empty
                cout << "Empty list" << endl;
                return;
            }
            Node *temp = head;
            while(temp!=nullptr){
                cout << temp->val << " ";
                temp = temp->next;
            }
            cout<< endl;
            return;

        }

        // insert
        // inserts a node at the end of the list

        void insert(int val){
            Node *newNode = new Node(val);
        
            if(head==nullptr){
                head = newNode;
                return;
            }

            Node *temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }

        // reverse

        void reverse() {
            Node *prev = nullptr;
            Node *current = head;
            Node *next = nullptr;

            if(current == nullptr){
                //empty list
                return;
            }else if (current->next == nullptr)
            {
                // one node in list
                return;
            }

            // if list contains 2 or more nodes
            while(current->next!= nullptr){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            current->next = prev;
            head = current;
            return;

            

        }




    

};

class DoublyNode{
    public:
        int val;
        DoublyNode *prev;
        DoublyNode *next;

        DoublyNode(int val) : val(val) , prev(nullptr) , next(nullptr) {}

};

class DoublyLinkedList{
    public:
        DoublyNode *head;
        DoublyNode *tail;

        DoublyLinkedList() : head(nullptr) , tail(nullptr) {} ;

        //functions

        //print doubly linked list

        void printList(bool reverse){
            if(!reverse){
                if(head==nullptr){
                    cout << "Empty List" <<endl;
                    return;
                }else if (head->next == nullptr){
                    cout << head->val <<endl;
                    return;
                }

                // two or more elements in list
                DoublyNode *temp = head;
                while(temp != nullptr){
                    cout << temp->val << " ";
                    temp = temp->next;
                }
                cout << endl;
                return;

            }else{
                    // print in reverse

                if(head==nullptr && tail==nullptr){ // no elements in list
                    cout << "Empty List" <<endl;
                    return;
                }else if(tail == nullptr){ // one element in list
                    cout << head->val <<endl;
                    return;

                }

                // two or more elements in list
                DoublyNode *temp = tail;
                while(temp != nullptr){
                    cout << temp->val << " ";
                    temp = temp->prev;
                }
                cout << endl;
                return;


            }

           
        }

        //insert
        void insert(int val){
            // insert at the end of the list
            DoublyNode *newNode = new DoublyNode(val);
            if(head==nullptr){
                head = newNode;
                return;
            }else if (tail == nullptr){
                tail = newNode;
                tail->prev = head;
                head->next = tail;
                return;
            }

            DoublyNode *temp = tail;
            tail = newNode;
            temp->next = tail;
            tail->prev = temp;
            return;
        }

        void insert(DoublyNode *Node){
            // insert at the end of the list
            DoublyNode *newNode = Node;
            if(head==nullptr){
                head = newNode;
                return;
            }else if (tail == nullptr){
                tail = newNode;
                tail->prev = head;
                head->next = tail;
                return;
            }

            DoublyNode *temp = tail;
            tail = newNode;
            temp->next = tail;
            tail->prev = temp;
            return;
        }

        //delete

        void deleteNode(DoublyNode *node){
            
            if(node->prev != nullptr){
                node->prev->next = node->next;
            }else{
                //if node to be deleted is head
                node->next->prev = nullptr;
            }

            if(node->next!=nullptr){
                node->next->prev = node->prev;
            }else{
                //if node to be deleted is tail
                node->prev->next = nullptr;
            }


            return;
        }

} ;

int main()
{

    DoublyLinkedList Dlinked_list;
    DoublyNode *Node1 = new DoublyNode(1);
    DoublyNode *Node2 = new DoublyNode(2);
    DoublyNode *Node3 = new DoublyNode(3);
    DoublyNode *Node4 = new DoublyNode(4);
    Dlinked_list.insert(Node1);
    Dlinked_list.insert(Node2);
    Dlinked_list.insert(Node3);
    Dlinked_list.insert(Node4);
    Dlinked_list.printList(false);
    Dlinked_list.deleteNode(Node2);
    Dlinked_list.printList(false);

    return 0;
}