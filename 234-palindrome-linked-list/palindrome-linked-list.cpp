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
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL){
            head = head->next;
            curr->next = prev;
            prev = curr;
            curr = head;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        int total = 0;
        ListNode* temp = head;

        while(temp != NULL){
            total++;
            temp = temp->next;
        }

        int half = ceil(total/2);
        ListNode* halfptr = head;
        for(int i = 0; i < half; i++){
            halfptr = halfptr->next;
        }

        ListNode* reverseHead = reverseList(halfptr);
        ListNode* curr = head;

        for(int i = 0; i < half; i++){
            if(curr->val != reverseHead->val){
                return false;
                break;
            }
            curr = curr->next;
            reverseHead = reverseHead->next;
        }

        return true;
    }
};