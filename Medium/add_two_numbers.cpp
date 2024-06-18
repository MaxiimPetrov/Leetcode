#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* new_list = new ListNode();
    ListNode* current = new_list;

    int list_1_num;
    int list_2_num;
    int new_num;

    bool carry_over;
    bool first_iteration = true;


    while(l1 != nullptr || l2 != nullptr) {
        if(!first_iteration) {
            current->next = new ListNode(1);
            current = current->next;
        }

        if(l1 == nullptr) {
            list_1_num = 0;
        }
        else {
            list_1_num = l1->val;
        }
        if(l2 == nullptr) {
            list_2_num = 0;
        }
        else {
            list_2_num = l2->val;
        }

        new_num = list_1_num + list_2_num;

        if(carry_over) {
            new_num++;
        }

        if(new_num >= 10) {
            new_num -= 10;
            carry_over = true;
        }
        else {
            carry_over = false;
        }

        current->val = new_num;

        if(l1 != nullptr) {
            l1 = l1->next;
        }
        if(l2 != nullptr) {
            l2 = l2->next;
        }

        if(first_iteration) {
            first_iteration = false;
        }

    }

    if(carry_over) {
        current->next = new ListNode(1);
    }

    return new_list;
}