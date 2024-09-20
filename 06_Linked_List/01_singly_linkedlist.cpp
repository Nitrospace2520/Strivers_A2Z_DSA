/**
 * @file 01_singly_linkedlist.cpp
 * @author Nirmalya Dhara
 * @brief
 * @date 2024-06-23
 */
#include <bits/stdc++.h>

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *link)
    {
        this->data = data;
        this->next = next;
    }
    ~Node()
    {
        delete this->next;
    }
};

Node *array_to_linkedlist(int nums[], int n)
{
    Node *node = new Node(nums[0]);
    Node *curr = node;
    for (int i = 1; i < n; i++)
    {
        curr->next = new Node(nums[i]);
        curr = curr->next;
    }
    return node;
}

void print_linkedlist(Node *node)
{
    while (node)
    {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(nums) / sizeof(nums[0]);

    Node *node = array_to_linkedlist(nums, n);
    print_linkedlist(node);

    return 0;
}