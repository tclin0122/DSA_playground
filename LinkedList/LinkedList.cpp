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
        /* Append LinkedList*/
        void append(int value) {
            Node* newNode = new Node(value);
            // check if the list is empty
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }
        /* Delete Last*/
        void deleteLast() {
            // check if the list is empty
            if (length == 0) return;
            // create to node pointer
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                Node* pre = head;
                while (temp -> next) {
                    pre = temp;
                    temp = temp -> next;
                }
                tail = pre;
                tail -> next = nullptr;
            }
            delete temp;
            length--;
        }
        /* Prepend */
        void prepend(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
            length++;
        }
        /* Delete first*/
        void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
            }
            delete temp;
            length--;
        }
        /* Get value*/
        Node* get(int index) {
            if (index < 0 || index>= length) {
                return nullptr;
            }
            Node* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp;
        }
        /* set value to the node and see if it succeed or not*/
        bool set(int index, int value) {
            Node* temp = get(index);
            if (temp) {
                temp->value = value;
                return true;
            }
            return false;
        }
        /* insert new Node in the List */
        bool insert(int index, int value) {
            if (index < 0 || index > length) return false;
            if (index == 0) {
                prepend(value);
                return true;
            }
            if (index == length) {
                append(value);
                return true;
            }
            Node* newNode = new Node(value);
            Node* temp = get(index - 1);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
            return true;
        }
        /* delete node*/
        void deleteNode(int index) {
            if (index < 0 || index >= length) return;
            if (index == 0) return deleteFirst();
            if (index == length) return deleteLast();

            Node* prev = get(index - 1);
            Node* temp = prev->next;

            prev->next = temp->next;
            delete temp;
            length--;
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
   myLinkedList->append(3);
   cout << "\nLinked List:\n";
   myLinkedList->printList();
}

