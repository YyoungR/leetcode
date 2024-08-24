/**
 * @file reverseList.cpp
 * @author your name (you@domain.com)
 * @brief leetcode 206. 反转链表
 * @version 0.1
 * @date 2024-08-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    
    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

int main() {
    // 创建一个链表
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    
    // 反转链表
    ListNode* reversedHead = reverseList(head);
    
    // 打印反转后的链表
    ListNode* curr = reversedHead;
    while (curr != nullptr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    
    // 释放内存
    curr = reversedHead;
    while (curr != nullptr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
    
    return 0;
}