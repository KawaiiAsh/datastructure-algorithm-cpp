#include <iostream>
using namespace std;

/* 链表节点结构体 */
struct ListNode {
    int val;         // 节点值
    ListNode *next;  // 指向下一节点的指针
    ListNode(int x) : val(x), next(nullptr) {}  // 构造函数
};

// 打印链表
void printlist(ListNode *head){
    if(head -> next == nullptr){
        cout << " nullptr." << endl; 
        return;
    }
    cout << head->val << " -> ";
    printlist(head->next);
}

int main(){
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;

    printlist(l1);
    return 0;
}