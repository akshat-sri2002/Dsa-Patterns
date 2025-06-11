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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode * >,vector<pair<int,ListNode * >>,greater<pair<int,ListNode * >>>pq;
        ListNode * ans = new ListNode();
        ListNode * temp = ans;
        for(auto it : lists){
            if(it!=nullptr) pq.push({it->val,it});
        }
        while(!pq.empty()){
            
            pair<int,ListNode * > curr = pq.top();
            pq.pop();
            ans->next = curr.second;
            ans = ans->next;
            if(curr.second->next!=nullptr){
                curr.first = curr.second->next->val;
                curr.second = curr.second->next;
                pq.push(curr);
            }
        }
        return temp->next;
    }
};