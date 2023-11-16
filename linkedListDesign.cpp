#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class MyLinkedList {
private:
    struct SinglyLinkedNode {
        int value;
        SinglyLinkedNode *next;
        SinglyLinkedNode(int x) : value(x), next(NULL) {}
    };

    SinglyLinkedNode* getNode(int index) {
        SinglyLinkedNode* current = head;
        for (int i = 0; i < index; i++) {
            if (current == NULL) {
                return NULL;
            } else if (current->next == NULL) {
                return NULL;
            } else {
                current = current->next;
            }
        }

        return current;
    }

    SinglyLinkedNode *head;
public:
    MyLinkedList() {
        cout << "Hello List" << endl;
        head = NULL;
    }

    int get(int index) {
        SinglyLinkedNode* node = getNode(index);
        if (node) {
            return node->value;
        } else {
            return -1;
        }
    }

    void addAtHead(int val) {
        SinglyLinkedNode* newNode = new SinglyLinkedNode(val);
        // Point newNode to the former head.  Will just stay null if the list is empty.
        newNode->next = head;
        head = newNode;
        return;
    }

    void addAtTail(int val) {
        if (head == NULL) {
            addAtHead(val);
            return;
        }

        SinglyLinkedNode* current = head;
        while (current) {
            if (current->next == NULL) {
                current->next = new SinglyLinkedNode(val);
                return;
            }
            current = current->next;
        }

    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        SinglyLinkedNode* prev = getNode(index - 1);
        if (!prev) {
            return;
        }
        SinglyLinkedNode* newNode = new SinglyLinkedNode(val);
        newNode->next = prev->next;
        prev->next = newNode;
    }

    void deleteAtIndex(int index) {
        SinglyLinkedNode* current = getNode(index);
        if (index == 0) {
            head = current->next;
            free(current);
            return;
        }

        SinglyLinkedNode* previous = getNode(index - 1);
        if (!previous || !current) {
            return;
        }

        previous->next = current->next;
        free(current);
    }

    void printList() {
        cout << "List: ";
        SinglyLinkedNode* current = head;
        while (current){
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
        return;
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
    MyLinkedList* aList = new MyLinkedList();
    aList->addAtTail(1);
    cout << aList->get(0) << endl;
    aList->addAtHead(1);
    aList->addAtHead(5);
    aList->addAtTail(5);
    aList->addAtIndex(1, 2);
    aList->addAtIndex(5, 7);
    aList->printList();
    aList->deleteAtIndex(1);
    aList->deleteAtIndex(3);
    aList->printList();
    cout << aList->get(0) << endl;
    //vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
    //string haystack = "sadbutsad", needle = "sad";
    //auto result = strStr(haystack, needle);

    //cout << "Index: " << result << endl;
    //for (auto n: result) {
        //cout << n;
    //}
    //for (int i = 0; i < result.size(); i++) {
        //for (int j = 0; j < result[i].size(); j++) {
            //cout << result[i][j] << " ";
        //}
        //cout << endl;
    //}
    //cout << endl;
}