#include <unordered_map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    std::unordered_map<ListNode*, bool> list_hash;
    bool cycle_found = false;

    while(!cycle_found && head != nullptr) {
        if(list_hash[head] == true) {
            cycle_found = true;
        }
        else {
            list_hash[head] = true;
        }

        head = head->next;
    }

    return cycle_found;

}