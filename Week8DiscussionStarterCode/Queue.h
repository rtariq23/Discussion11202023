#ifndef WEEK8_QUEUE_H
#define WEEK8_QUEUE_H
using namespace std;

template<class T>
class Queue {
private:
    struct Node {
        T element;
        Node* next;
        Node(T elem, Node* nex = nullptr){
            element = elem,
            next = nex;
        }
    };

    Node* front;
    Node* back;
    int numNodes;

public:
    Queue();
    ~Queue();
    void enqueue(T);
    void dequeue(T &);
    bool isEmpty();
    void clear();
};

//************************************************
// Constructor                                   *
//************************************************

template <class T>
Queue<T>::Queue(){
    front = nullptr;
    back = nullptr;
    numNodes = 0;
};

//************************************************
// Destructor                                    *
//************************************************
template <class T>
Queue<T>::~Queue(){
    clear();
};

//************************************************
// Function enqueue inserts the value in num     *
// at the rear of the queue.                     *
//************************************************
template <class T>
void Queue<T>::enqueue(T num){
    Node *tempNode = new Node(num);
    if(isEmpty()){
        front = tempNode;
        back = tempNode;
    } else {
        back->next = tempNode;
        back = tempNode;
    }
    ++numNodes;
}

//************************************************
// Function dequeue removes the value at the     *
// front of the queue, and copies it into num.   *
//************************************************
template <class T>
void Queue<T>::dequeue(T &num){
    Node* tempNodePtr = nullptr;
    if(isEmpty()){
        cout << "Queue is empty" << endl;
    } else {
        num = front->element;
        tempNodePtr = front->next;
        delete front;
        front = tempNodePtr;
        --numNodes;
    }
}

//************************************************
// Function isEmpty returns true if the queue    *
// is empty, and false otherwise.                *
//************************************************
template <class T>
bool Queue<T>::isEmpty(){
    return (0 == numNodes);
}

//************************************************
// Function clear dequeues all the elements      *
// in the queue.                                 *
//************************************************
template <class T>
void Queue<T>::clear(){
    T value;
    while(!isEmpty()){
        dequeue(value);
    }
}

#endif //WEEK8_QUEUE_H
