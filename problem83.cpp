#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==nullptr) return head;
        ListNode* prev = head;

        while (prev->next != nullptr) {
            if (prev->val==prev->next->val) {
                ListNode* curr = prev->next;
                prev->next = curr->next;
                delete curr;
            }
            else {
                prev = prev->next;
            }
        }
        return head;
    }
};

void add(ListNode* head, int x) {
    ListNode* next = new ListNode(x);
    ListNode* curr = head;

    while (curr->next!=nullptr) {
        curr = curr->next;
    }
    curr -> next = next;
}

void print(ListNode* head) {
    ListNode* curr = head;
    while (curr!=nullptr) {
        cout << curr->val << ' ';
        curr = curr->next;
    }
}

int main() {
    ListNode* dummyHead = new ListNode();

    cout << "Input Size of List" << endl;
    int n; cin >> n;

    cout << "Input Elements of List" << endl;
    for (int i=0; i<n; i++) {
        int input; cin >> input;
        add(dummyHead, input);
    }

    cout << endl;
    cout << "****************print*****************" << endl;
    Solution sol;
    print(sol.deleteDuplicates(dummyHead->next));
}