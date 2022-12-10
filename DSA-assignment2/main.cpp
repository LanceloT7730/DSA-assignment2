//
//  main.cpp
//  DSA-assignment2
//
//  Created by DONIYORBEK IBROKHIMOV on 10/12/22.
//

#include <iostream>
#include <vector>

using namespace std;

template <class Type>
struct Node {
    Type data;
    Node *next;

    Node() {
        data = 0;
        next = NULL;
    }
};

template <class Type>
class LinkedListBubbleSort {
private:
    Node<Type> *head;
public:

    LinkedListBubbleSort() {
        head = NULL;
    }

    Type BubleSort(vector<Type>, unsigned int size) {
        Node<Type> *curr;
        Node<Type> *prev;
        if(head && head->next) {
            curr = head->next;
            prev = head;
        } else if (head) {
            curr = head;
            prev = head;
        } else {
            cout << "Empty list\n";
            return;
        }

        bool flag = false;
        Type counter = 0;

        while (prev) {
            while(curr) {
                if(++counter && (prev->data < curr->data) ) {

                }
            }
        }
    }

    void swapLists(Node<Type> *prev, Node<Type> *curr) {
        Node<Type> *temp = curr->next;
        curr->next = prev;
        prev->next = temp;

    }

    void insertAtFront(int data) {
        auto *newNode = new Node<Type>;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void printAll() {
        Node<Type> *temp = head;

        while (temp) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

};


int main() {

    LinkedListBubbleSort<int> list1;
    list1.insertAtFront(4);

    for (int i = 0; i < 10; i++) {
        list1.insertAtFront(i);
    }



    return 0;
}
