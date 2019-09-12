#include <iostream>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode* l) {
    std::cout << "[";
    while (l != nullptr) {
        std::cout << l->val << ", ";
        l = l->next;
    }
    std::cout << "]" << std::endl;
}

ListNode* make_data(const vector<int>& v) {
    ListNode* head = nullptr;
    ListNode* curnode = nullptr;
    if (v.empty()) {
        return head;
    }
    for (size_t i = 0; i < v.size(); ++i) {
        ListNode* newnode = new ListNode(v[i]);
        if (i == 0) {
            head = newnode;
            curnode = newnode;
        } else {
            curnode->next = newnode;
            curnode = newnode;
        }
    }
    return head;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr || l2 == nullptr) {
            return nullptr;
        }
        // ListNode* p1 = reverse(l1);
        // ListNode* p2 = reverse(l2);
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int jinwei = 0;
        ListNode* l3 = nullptr;
        ListNode* curnode = nullptr;
        while (p1 != nullptr && p2 != nullptr) {
            ListNode* newnode = new ListNode((p1->val + p2->val + jinwei)%10);
            jinwei = (p1->val + p2->val + jinwei) / 10;
            if (curnode == nullptr) {
                l3 = newnode;
                curnode = newnode;
            } else {
                curnode->next = newnode;
                curnode = newnode;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        
        while (p1 != nullptr) {
            ListNode* newnode = new ListNode((p1->val + jinwei)%10);
            jinwei = (p1->val + jinwei) / 10;
            curnode->next = newnode;
            curnode = newnode;
           
            p1 = p1->next;
        }
        
        while (p2 != nullptr) {
            ListNode* newnode = new ListNode((p2->val + jinwei)%10);
            jinwei = (p2->val + jinwei) / 10;
            curnode->next = newnode;
            curnode = newnode;
           
            p2 = p2->next;
        }
        
        if (jinwei > 0) {
            ListNode* newnode = new ListNode(jinwei);
            curnode->next = newnode;
        }
        
        return l3;
    }
    
    ListNode* reverse(ListNode* n) {
        if (n == nullptr || n -> next == nullptr) {
            return n;
        }
        ListNode* head = nullptr;
        ListNode* p = n;
        ListNode* q = nullptr;
        
        while (p != nullptr) {
            q = p->next;
            p->next = head;
            head = p;
            p = q;
        }
        return head;
    }
};

int main() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(8);
    vector<int> v2;
    v2.push_back(0);
    ListNode* l1 = make_data(v1);
    ListNode* l2 = make_data(v2);
    print_list(l1);
    print_list(l2);

    Solution s;
    ListNode* rl1 = s.reverse(l1);
    print_list(rl1);
    return 0;
}

