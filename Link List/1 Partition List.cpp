/*********************************************************************************************************************************************************************
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200
*************************************************************************************************************************************************************************/

Divide the given list head into 2 linked lists, greater & smaller. Then connect these 2 lists and return the result.

Approach
[Please turn on english subtitles if necessary]
https://youtu.be/LZ6oARGKnZA
[1,4,3,2,5,2]
3





Use while loop to traverse and partition

smaller->0->1->2->2
greater->0->4->3->5->NULL

then connect 2 lists by

smallerTail->next = greaterHead->next;
Obtain
smaller->0->1->2->2->4->3->5->NULL

Finally

head = smallerHead->next;
Have
head->1->2->2->4->3->5->NULL
Return head

The whole process shown by modifying submitted code in playground

1<3:smaller
smaller:0->1->4->3->2->5->2
greater:0
-------
4>=3: greater
smaller:0->1->4->3->2->5->2
greater:0->4->3->2->5->2
-------
3>=3: greater
smaller:0->1->4->3->2->5->2
greater:0->4->3->2->5->2
-------
2<3:smaller
smaller:0->1->2->5->2
greater:0->4->3->2->5->2
-------
5>=3: greater
smaller:0->1->2->5->2
greater:0->4->3->5->2
-------
2<3:smaller
smaller:0->1->2->2
greater:0->4->3->5->2
-------
ans:
1->2->2->4->3->5




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
    ListNode* partition(ListNode* head, int x) {
        
        
          if (head == NULL) return head;
        ListNode* smallerHead=new ListNode(); //Head of the list with nodes <x
        ListNode* smallerTail=smallerHead; //Tail of the list with nodes <x
        
        ListNode* greaterHead=new ListNode();//Head of the list with nodes >=x
        ListNode* greaterTail=greaterHead; //Tail of the list with nodes >=x
        
        ListNode* curr = head;
        while (curr) {//partition into greater & smaller lists
            if (curr->val < x) {
                smallerTail->next = curr;
                smallerTail =smallerTail->next;
                
                
            } 
            else {
                greaterTail->next = curr;
                greaterTail=greaterTail->next;
                
                
            }
           
            curr = curr->next;
        }
        
        greaterTail->next = NULL; 
        smallerTail->next = greaterHead->next;//Connect the smaller and the greater lists
        
        head = smallerHead->next; //Update the head of the list
       
        return head;
    }
    
};

/*******************************************************************************************************************************************************************/

Traverse the linked list and when you see the node less than target then remove this node and insert it after the previous smaller node.
Take care of boundary cases.

Complexity
Time complexity:
O(n)

Space complexity:
O(1) extra space

Code
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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return head;
        if(head->next == NULL) return head;
        if(head->val >= x){
            ListNode* k1,*k2;
            k2 = head->next;
            k1 = head;
            while(k2 && k2->val>=x){                            
                k1 = k1->next;
                k2 = k2->next;
            }
            if(k2!=NULL){
                k1->next = k2->next;
                k2->next = head;
                head = k2;
            }
        }
        ListNode* l1,*l2,*l3;
        l1 = head;
        while(l1 && l1->next && l1->next->val < x && l1->val < x){
            l1 = l1->next;
        }    
        if(l1==NULL){
            return head;
        }                                                                  
        l2 = l1;
        l3 = l1->next;
        while(l3&&l2){
            if(l3->val >= x){
                l3 = l3->next;
                l2 = l2->next;
                continue;
            }
            l2->next = l3->next;
            l3->next = l1->next;
            l1->next = l3;
            l1 = l1->next;
            l3 = l2->next;
        }
        return head;
    }
};
