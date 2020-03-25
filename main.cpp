/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void insertNode(ListNode* head,vector<int> &oddNode,vector<int> &evenNode)
    {
        int count=0;
        while(head!=NULL)
        {
            count++;
            if(count%2==0)
            {
                evenNode.push_back(head->val);
            }
            else{
                oddNode.push_back(head->val);
            }
            head=head->next;
        }
    }
    ListNode* oddEvenList(ListNode* head)
    {
        if(head==NULL)
        {
            return NULL;
        }
        vector<int> oddNode;
        vector<int> evenNode;
        insertNode(head,oddNode,evenNode);
         for(int i=0;i<evenNode.size();i++)
         {
             oddNode.push_back(evenNode[i]);
         }
        ListNode* root=NULL;
        for(int i=0;i<oddNode.size();i++)
        {
            ListNode* temp = new ListNode();
            temp->val=oddNode[i];
            temp->next=NULL;
            if(root==NULL)
            {
                root=temp;
            }
            else
            {
                ListNode* ptr=root;
                while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=temp;
            }
        }
        return root;
    }
};
