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

//Optimized approach
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *slow = head,*fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev=nullptr,*tmp,*curr = slow;
        while(curr){
            tmp = curr->next; 
            curr->next = prev;
            prev = curr; 
            curr = tmp;
        }
        ListNode *n1 =head,*n2 = prev;
        while(n2->next){
            tmp = n1->next;
            n1->next = n2;
            n1 = tmp;
            
            tmp = n2->next;
            n2->next = n1;
            n2 = tmp;
        }
    }
};


//Trivial approach

// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         stack<ListNode*> stk;
//         auto curr = head;
//         while(curr){
//             stk.push(curr);
//             curr = curr->next;
//         }
//         curr = head;
//         int n = stk.size();
//         if (n<=2) return;
//         ListNode* next;
//         for(int i=0; i< n/2;i++){
//             next = curr->next;
//             curr->next = stk.top();
//             stk.pop();
//             curr = curr->next; 
//             curr->next = next; //5->next =2
//             curr = curr->next; //curr=2
//         }
//         curr->next = nullptr;
        
//     }
// };