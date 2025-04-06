#include <iostream>

class CircularQueue{
    public:
        int front;
        int rear;
        int size;
        static const int MaxSize = 4;
        int array[MaxSize] = {};

        //constructor 
        CircularQueue() : front(0),rear(-1),size(0) {}

        //functions 

        //enqueue

        void enqueue(int val){
            if(size>=MaxSize){
                // queue is full
                std::cout << "Queue Overflow"<<std::endl;
                return;
            }
            
            // queue is not full
            rear = (rear+1) % MaxSize;
            array[rear] = val;
            size++;
            return;

        }
        
        //dequeue 

        int dequeue(){
            if(size <= 0){
                // queue is empty
                std::cout << "Queue underflow" <<std::endl;
                return 0;
            }

            // queue is not empty
            int dequeued = array[front];
            front = (front+1) % MaxSize;
            size--;
            return dequeued;

        }

        // peek 

        void peek(){
            if (size <= 0){
                std::cout << "Empty" <<std::endl;
                return;
            }
            std::cout << array[front] << std::endl;
            return;
        }

        //printQueue

        void printQueue(){
            for(int i =front ; i<= rear;i++){
                std::cout << array[i] << std::endl;


            }
            return;
        }

        // isEmpty

        bool isEmpty(){
            if(size <= 0){
                return true;
            }
            return false;
        }

        // isFull

        bool isFull(){
            if (size >= MaxSize){
                return true;
            }
            return false;

        }


};

int main(){
    CircularQueue queue;
    queue.enqueue(3);
    queue.enqueue(5);
    queue.enqueue(7);
    queue.enqueue(2);
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.enqueue(1);
    queue.enqueue(10);
    queue.printQueue();
    return 0;
}
