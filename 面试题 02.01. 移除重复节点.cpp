/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。
 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]
 输入：[1, 1, 1, 1, 2]
 输出：[1, 2]

 */
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(head==NULL) return NULL;
        int mp[20005]={0};
        mp[head->val]=1;
        ListNode * q=head->next;
        ListNode *p=head;
        while(q)
        {
            if(mp[q->val]==0)//没出现过，不用删除
            {
                mp[q->val]=1;
                p=p->next;
                q=q->next;
            }
            else{
                p->next=p->next->next;
                q=p->next;
            }
        }
        return head;

    }
};
