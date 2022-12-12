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
        } else if (!curr) {
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

    /*void InsertionSort() {
        if(!head) {
            cout << "List is empty\n";
            return;
        }
        auto *sortedListList = new Node;
        sortedListList->data = head->data;
        Node *temp_sortedList = sortedListList;
        Node *temp = head;
        while (temp) {
            if(temp->data < temp_sortedList->data) {
                auto *newNode = new Node;
                newNode->data = temp->data;
                newNode->next = temp_sortedList;
                temp_sortedList = newNode;
                temp = temp->next;
            }else {
                while( (temp->data > temp_sortedList->data) && temp_sortedList) {
                    temp_sortedList = temp_sortedList->next;
                }
                auto *newNode = new Node;
                newNode->data = temp->data;
                temp_sortedList->next = newNode;
                temp = temp->next;
            }
        }
        head = temp_sortedList;
    }*/

    void InsertionSort() {
        Node *sortedList = NULL;
        Node *currUnsortedNode = head;
        while (currUnsortedNode) {
            if (!sortedList) {
                Node *newNode = new Node;
                newNode->data = currUnsortedNode->data;
                newNode->next = sortedList;
                sortedList = newNode;
            } else {
                Node *currentSortedNode = sortedList;
                Node *prev = NULL;
                bool flag = false;
                while (currentSortedNode && !flag) {
                    if (currentSortedNode->data > currUnsortedNode->data) flag = true;
                    else {
                        prev = currentSortedNode;
                        currentSortedNode = currentSortedNode->next;
                    }
                }
                Node *newNode = new Node;
                newNode->data = currUnsortedNode->data;
                if (!prev) {
                    newNode->next = sortedList;
                    sortedList = newNode;
                } else {
                    newNode->next = currentSortedNode;
                    prev->next = newNode;
                }
            }
            currUnsortedNode = currUnsortedNode->next;
        }
        head = sortedList;
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

    list1.InsertionSort();
    cout << "After sorting\n";
    list1.printAll();


    return 0;
}
