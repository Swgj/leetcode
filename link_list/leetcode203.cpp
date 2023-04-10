#include<iostream>
#include<string>
#include<sstream>

using namespace std;

struct ListNode
{
    int val;
    ListNode * next;

    ListNode(int x): val(x), next(nullptr){};
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //删除头,中间和尾
        ListNode* p = head;
        ListNode* q = nullptr;
        if(p!=nullptr) q = head->next;
        
        while (q!=nullptr)
        {
            if(q->val == val){
                p->next = q->next;
                q = p->next;
                continue;
            }
            p = p->next;
            q = p->next;
        }

        if(head!=nullptr && head->val==val) {//头
            head = head->next;
        }
        return head;
    }
};

int main(){
    freopen("leetcode203.txt","r",stdin);
    int val;
    cin >> val;
    cin.ignore();
    string line;
    getline(cin,line);
    stringstream ss(line);
    string str;
    ListNode* head = nullptr;
    ListNode* ptr = head;
    while (getline(ss,str,','))
    {
        if(ptr==nullptr&&ptr==head) {
            head = new ListNode(stoi(str));
            ptr = head;
        }else {
            ptr->next = new ListNode(stoi(str));
            ptr = ptr->next;
        }
    }
    Solution so;
    head = so.removeElements(head,val);

    ptr = head;
    while (ptr!=nullptr)
    {
        cout << ptr->val <<" ";
        ptr = ptr->next;
    }
    
}