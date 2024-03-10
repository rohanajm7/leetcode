/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast){
            if(fast->next == NULL){
                return slow;
                break;
            }
            if(fast->next->next == NULL){
                return slow->next;
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }

        if(list1->val > list2->val){
            swap(list1, list2);
        }

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        while(curr1 != NULL && curr2 != NULL){
            ListNode* temp = NULL;
            while(curr1 != NULL && curr1->val <= curr2->val){
                temp = curr1;
                curr1 = curr1->next;
            }
            temp->next = curr2;
            swap(curr1, curr2);
        }

        return list1;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* middle = middleNode(head);
        ListNode* right = middle->next;
        ListNode* left = head;
        middle->next = NULL;

        left = sortList(left);
        right = sortList(right);
        return mergeTwoLists(left, right);
    }
};