/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        if(head == NULL)
            return NULL;
        RandomListNode *h1=head;
        while(h1!=NULL)
        {
            RandomListNode *n=new RandomListNode(h1->label);
            n->next = h1->next;
            n->random=h1;
            h1->next = n;
            h1=h1->next->next;
        }
        h1=head;
        RandomListNode *n1=h1->next, *retn=h1->next;
        while(n1 !=NULL)
        {
            n1->random = n1->random->random? n1->random->random->next : NULL;
            n1 = n1->next ? n1->next->next:NULL;
        }
        n1=retn;
        while(h1!=NULL)
        {
            h1->next = h1->next->next?h1->next->next : NULL;
            n1->next = n1->next? n1->next->next : NULL;
            h1=h1->next;
            n1=n1->next;
        }
        return retn;
        
    }
};