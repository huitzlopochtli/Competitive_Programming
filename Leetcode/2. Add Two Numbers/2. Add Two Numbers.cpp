#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v, ListNode *n){
        val = v;
        next = n;
    }
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Track the head and the tail 
        // head: return value of this function
        // tail: keep track of the currect index of in the ListNode
        ListNode *head = NULL, *tail = NULL;

        // carry 
        int carry = 0;

        // while l1 or l2 both are not null
        while(l1 != nullptr || l2 != nullptr){

            int sum = carry;

            // if l1 is not null
            // add l1.val to sum
            // move l1 to l1.next
            if(l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;    
            }

            // if l2 is not null
            // add l2.val to sum
            // move l2 to l2.next
            if(l2 != nullptr){
                sum += l2->val;
                l2 = l2->next;
            }

            // create a new listNode 
            // sum modulus 10 to keep sum inside 10
            // calculate carry
            auto *node = new ListNode(sum % 10, nullptr);
            carry = sum / 10;

            // if the current node/tail is unll
            // assign head and tail with the new node 
            if(tail == nullptr){
                tail = head = node;
            }
            // else tail to new node
            // and move tail to next node
            else {
                tail->next = node;
                tail = tail->next;
            }
        }

        // if there is any last carry
        // put it the tail next node
        if(carry > 0) {
            tail->next = new ListNode(carry, nullptr);
        }

        return head;
    }

};

int main(){
    auto *l1 = new ListNode(2, new ListNode(3, new ListNode(4, nullptr)));
    auto *l2 = new ListNode(2, new ListNode(3, new ListNode(4, nullptr)));

    auto s = new Solution();
    s->addTwoNumbers(l1, l2);

    return 0;

}