#include <iostream>

using namespace std;

class Node {
    public:
        int value;      //value for the current node
        Node* next;     //pointer point to the next node

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
        /* data */
        Node* head;
        Node* tail;
        int length;
    public:
        /* LinkedList constructor */
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
        /* LinkedList destructor */
        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head -> next;
                delete temp;
                temp = head;
            }
        }
        /* Print LinkedList */
        void printList() {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }
        /* Obtain Head pointer */
        void getHead() {
            if (head == nullptr) {
                cout << "Head: nullptr" << endl;
            } else {
                cout << "Head: " << head->value << endl;
            }
        }
        /* Obtain Tail pointer */
        void getTail() {
            if (tail == nullptr) {
                cout << "Tail: nullptr" << endl;
            } else { 
                cout << "Tail: " << tail->value << endl;
            }  
        }
        /* Obtain length */
        void getLength() {
            cout << "Length: " << length << endl;
        }

};

int main() {
    /* Create LinkedList*/
    LinkedList* myLinkedList = new LinkedList(4);
    /*Obtain LinkedList info*/
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    
    cout << "\nLinked List:\n";
    myLinkedList->printList();
    /*  
        EXPECTED OUTPUT:
    	----------------
        Head: 4
        Tail: 4
        Length: 1

        Linked List:
        4

    */
   delete myLinkedList; //delete the LinkedList
}

