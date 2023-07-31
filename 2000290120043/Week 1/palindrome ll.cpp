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

    ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


    bool isPalindrome(ListNode *head)
{
    if(head==NULL || head->next==NULL) return true;
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    slow->next = reverse(slow->next);
    slow = slow->next;
    ListNode* dummy = head;

    while(slow){
        if(dummy->val != slow->val) return false;
        dummy = dummy->next;
        slow = slow->next;
    }

    return true;

}
};