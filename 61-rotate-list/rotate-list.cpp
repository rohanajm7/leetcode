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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
           return head; 
        }
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }

        int pos = k%count;
        if(pos == 0){
            return head;
        }
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for(int i = 0; i < pos; i++){
            fast = fast->next;
        }

        if(fast == NULL){
            return dummy->next;
        }

        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        fast->next = head;
        head = slow->next;
        slow->next = NULL;

        return head;
    }
};