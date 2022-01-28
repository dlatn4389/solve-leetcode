#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1==nullptr) return list2;
        if (list2==nullptr) return list1;

        ListNode* head = new ListNode();
        ListNode* curr = head;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        if (curr1->val<curr2->val) {
            head->val = curr1->val;
            curr1 = curr1->next;
        }
        else {
            head->val = curr2->val;
            curr2 = curr2->next;
        }

        while (curr1!=nullptr and curr2!=nullptr) {
            ListNode* node = new ListNode();
            if (curr1->val<curr2->val) {
                node->val = curr1->val;
                curr1 = curr1->next;
            }
            else {
                node->val = curr2->val;
                curr2 = curr2->next;
            }
            curr->next = node;
            curr = curr->next;
        }

        if (curr1==nullptr) {
            while (curr2!=nullptr) {
                curr->next = new ListNode(curr2->val);
                curr2 = curr2->next;
                curr = curr->next;
            }
        }
        if (curr2==nullptr) {
            while (curr1!=nullptr) {
                curr->next = new ListNode(curr1->val);
                curr1 = curr1->next;
                curr = curr->next;
            }
        }
        return head;
    }
};

void add(ListNode *head, int n) {
    ListNode* node = new ListNode(n);
    ListNode* curr = head;

    while (curr->next!=nullptr) {
        curr = curr->next;
    }
    curr->next = node;
}
void print(ListNode* head) {
    ListNode* curr = head;
    while (curr!=nullptr) {
        cout << curr->val << ' ';
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    ListNode* list1 = new ListNode();
    ListNode* list2 = new ListNode();

    int n1, n2;
    cout << "Input list1's size below" << endl;
    cin >> n1;
    cout << "Input list1's Element below" << endl;
    for (int i=0; i<n1; i++) {
        int in; cin >> in;
        if (i==0) {
            list1->val = in;
        }
        else {
            add(list1, in);
        }
    }
    cout << "Input list2's size below" << endl;
    cin >> n2;
    cout << "Input list2's Element below" << endl;
    for (int i=0; i<n2; i++) {
        int in; cin >> in;
        if (i==0) {
            list2->val = in;
        }
        else {
            add(list2, in);
        }
    }

    cout << endl;
    cout << "**************print***************" << endl;
    Solution sol;
    print(sol.mergeTwoLists(list1, list2));
}



