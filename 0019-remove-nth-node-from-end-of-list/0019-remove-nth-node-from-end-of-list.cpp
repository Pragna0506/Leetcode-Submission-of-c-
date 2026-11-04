class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* sentinel = new ListNode(0);
        sentinel->next = head;
        int length = 0;
        ListNode* current = head;
        while (current) {
            length++;
            current = current->next;
        }
        ListNode* prev = sentinel;
        for (int i = 0; i < length - n; i++) {
            prev = prev->next;
        }
        prev->next = prev->next->next;
        return sentinel->next;
    }
};
    
