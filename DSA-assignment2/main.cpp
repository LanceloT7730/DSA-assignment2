//
//  main.cpp
//  DSA-assignment2
//
//  Created by DONIYORBEK IBROKHIMOV on 10/12/22.
//

#include <iostream>
#include <vector>

using namespace std;


struct Node {
    int data;
    Node *next;

    Node() {
        data = 0;
        next = NULL;

    }
};


class LinkedList {
private:
    Node *head, *last;
public:

    LinkedList() {
        head = NULL;
        last = NULL;
    }

    int size() {
        Node *temp = head;
        int counter = 0;

        while (temp) {
            counter++;
            temp = temp->next;
        }
        return counter;
    }


    void BubbleSort() {
        Node *curr = head;
        Node *nextNode = head->next;
        int counter = size();
        while (counter) {
            if (curr->data > nextNode->data) swapNodes(curr, nextNode);
            curr = curr->next;
            nextNode = nextNode->next;

            if (!nextNode) {
                counter--;
                curr = head;
                nextNode = head->next;
            }
        }
    }

    void swapNodes(Node *curr, Node *next) {
        int temp = curr->data;
        curr->data = next->data;
        next->data = temp;
    }

    void insertAtLast(int data) {
        auto *newNode = new Node;
        newNode->data = data;

        if (!head) {
            head = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    void printAll() {
        Node *temp = head;

        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int getMin(Node *curr) {
        Node *temp = curr;
        int min;
        if (!head) {
            cout << "Empty list\n";
            return 0;
        } else if(!curr) {
            cout << "Reached the end of the list\n";
            return 0;
        }
        min = curr->data;

        while (temp) {
            if (temp->data <= min) {
                min = temp->data;
            }
            temp = temp->next;
        }
        return min;
    }

    void SelectionSort() {
        if (!head) {
            cout << "Empty list";
            return;
        }

        Node *tempHead = head;
        Node *iterator = head;
        int min = 0;
        while (tempHead) {
            min = getMin(tempHead);
            while (iterator->data != min) {
                iterator = iterator->next;
            }
            swapNodes(tempHead, iterator);
            tempHead = tempHead->next;
            iterator = tempHead;
        }

    }
};


int main() {

    LinkedList list1;

    list1.insertAtLast(5);
    list1.insertAtLast(4);
    list1.insertAtLast(3);
    list1.insertAtLast(2);
    list1.insertAtLast(1);
    list1.insertAtLast(1);
    list1.printAll();

    list1.SelectionSort();
    cout << "After sorting\n";
    list1.printAll();


    return 0;
}
