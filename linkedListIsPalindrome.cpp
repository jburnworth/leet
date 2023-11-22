#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class MyLinkedList {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* getNode(int index) {
        ListNode* current = head;
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

    ListNode *head;
public:
    MyLinkedList() {
        cout << "Hello List" << endl;
        head = NULL;
    }

    int get(int index) {
        ListNode* node = getNode(index);
        if (node) {
            return node->val;
        } else {
            return -1;
        }
    }

    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
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

        ListNode* current = head;
        while (current) {
            if (current->next == NULL) {
                current->next = new ListNode(val);
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

        ListNode* prev = getNode(index - 1);
        if (!prev) {
            return;
        }
        ListNode* newNode = new ListNode(val);
        newNode->next = prev->next;
        prev->next = newNode;
    }

    void deleteAtIndex(int index) {
        ListNode* current = getNode(index);
        if (index == 0) {
            head = current->next;
            free(current);
            return;
        }

        ListNode* previous = getNode(index - 1);
        if (!previous || !current) {
            return;
        }

        previous->next = current->next;
        free(current);
    }

    void printList() {
        cout << "List: ";
        ListNode* current = head;
        while (current){
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
        return;
    }

    ListNode* reverseList() {
        ListNode *temp = head;
        if (!temp) return NULL;

        while (temp->next) {
            ListNode *oldHead = head;
            ListNode *nextNode = temp->next;
            ListNode *nextNext = temp->next->next;
            std::cout << "temp val: " << temp->val << " temp next val: " << temp->next->val << std::endl;

            head = nextNode;
            head->next = oldHead;
            temp->next = nextNext;

            if (temp->next == NULL) {
                std::cout << "Last loop" << std::endl;
            }
        }
        return head;
    }

    bool isPalindrome() {
        ListNode *current = head;
        vector<int> palli = {};

        while (current) {
            palli.push_back(current->val);
            current = current->next;
        }

        int f = 0;
        int b = (palli.size() - 1);
        while (f < b) {
            std::cout << palli[f] << " = " << palli[b] << std::endl;
            if (palli[f] != palli[b]) {
                return false;
            }
            f++;
            b--;
        }
        return true;
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
    aList->addAtTail(2);
    aList->addAtTail(3);
    aList->addAtTail(4);
    aList->addAtTail(5);
    aList->printList();

    aList->isPalindrome();
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