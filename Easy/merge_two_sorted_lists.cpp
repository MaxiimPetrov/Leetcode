struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == nullptr && list2 == nullptr) {
        return nullptr;
    }

    ListNode* new_list = new ListNode();
    ListNode* list_ptr = new_list;

    while(list1 != nullptr || list2 != nullptr) {

        if(list1 != nullptr && list2 != nullptr) {
            if(list1->val == list2->val) {
                list_ptr->val = list2->val;
                list2 = list2->next;
                list_ptr->next = new ListNode();
                list_ptr = list_ptr->next;
                list_ptr->val = list1->val;
                list1 = list1->next;
                if(list1 != nullptr || list2 != nullptr) {
                    list_ptr->next = new ListNode();
                    list_ptr = list_ptr->next;
                }
            }
            else if(list1->val > list2->val) {
                list_ptr->val = list2->val;
                list2 = list2->next;
                if(list2 != nullptr || list1 != nullptr) {
                    list_ptr->next = new ListNode();
                    list_ptr = list_ptr->next;
                }
                
            }
            else {
                list_ptr->val = list1->val;
                list1 = list1->next;
                if(list2 != nullptr || list1 != nullptr) {
                    list_ptr->next = new ListNode();
                    list_ptr = list_ptr->next;
                }
            }
        }
        else if(list1 != nullptr && list2 == nullptr) {
            list_ptr->val = list1->val;
            list1 = list1->next;
            if(list1 != nullptr) {
                list_ptr->next = new ListNode();
                list_ptr = list_ptr->next;
            }
        }
        else {
            list_ptr->val = list2->val;
            list2 = list2->next;
            if(list2 != nullptr) {
                list_ptr->next = new ListNode();
                list_ptr = list_ptr->next;
            }
        }
    }


    return new_list;
}