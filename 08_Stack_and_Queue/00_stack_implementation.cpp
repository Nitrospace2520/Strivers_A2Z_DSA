/**
 * @file 00_stack_implementation.cpp
 * @brief Implementation of stack data structure using both array and linked list
 * @author Nirmalya Dhara
 * @date 2024-12-20
 *
 * This file contains implementation of stack data structure using two different approaches:
 * 1. Array-based implementation (StackUsingArray)
 * 2. Linked list based implementation (StackUsingLinkedList)
 */
#include <bits/stdc++.h>

/**
 * @class StackUsingArray
 * @brief Implementation of stack using array
 *
 * This class implements a stack data structure using a fixed-size array.
 * It provides basic stack operations like push, pop, peek and isEmpty.
 * The stack has a fixed capacity defined during initialization.
 * The stack is full when the top index is equal to the size of the array.
 */
class StackUsingArray
{
private:
    int top;
    int size;
    int *arr;

public:
    StackUsingArray(int size)
    {
        this->size = size;
        this->top = -1;
        this->arr = new int[size];
    }
    ~StackUsingArray()
    {
        delete[] this->arr;
    }

    // * push operation:=
    void push(int data)
    {
        if (this->top == this->size - 1)
        {
            std::cout << "StackUsingArray is full\n";
            return;
        }
        this->arr[++this->top] = data;
    }
    // * pop operation:=
    int pop()
    {
        if (this->top == -1)
        {
            std::cout << "StackUsingArray is empty\n";
            return -1;
        }
        int val = this->arr[this->top];
        this->top--;
        return val;
    }
    // * peek operation:=
    int peek()
    {
        if (this->top == -1)
        {
            std::cout << "StackUsingArray is empty\n";
            return -1;
        }
        return this->arr[this->top];
    }
    // * isEmpty operation:=
    bool isEmpty()
    {
        return this->top == -1;
    }
};

/**
 * @class StackUsingLinkedList
 * @brief Implementation of stack using singly linked list
 *
 * This class implements a stack data structure using a singly linked list.
 * It provides basic stack operations like push, pop, peek and isEmpty.
 * The stack can grow dynamically as needed, unlike array implementation.
 * Each node in the linked list contains data and a pointer to the next node.
 */
class StackUsingLinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = nullptr;
        }
    };
    Node *top;

public:
    StackUsingLinkedList()
    {
        this->top = nullptr;
    }
    ~StackUsingLinkedList()
    {
        Node *temp = this->top;
        while (temp != nullptr)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
    }
    // * push operation:=
    void push(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = this->top;
        this->top = newNode;
    }
    // * pop operation:=
    int pop()
    {
        if (this->top == nullptr)
        {
            std::cout << "StackUsingLinkedList is empty\n";
            return -1;
        }
        Node *temp = this->top;
        int val = temp->data;
        this->top = this->top->next;
        delete temp;
        return val;
    }
    // * peek operation:=
    int peek()
    {
        if (this->top == nullptr)
        {
            std::cout << "StackUsingLinkedList is empty\n";
            return -1;
        }
        return this->top->data;
    }
    // * isEmpty operation:=
    bool isEmpty()
    {
        return this->top == nullptr;
    }
};

int main(int argc, char const *argv[])
{
    // ? StackUsingArray
    // StackUsingArray *stack = new StackUsingArray(5);
    // stack->push(1);
    // stack->push(2);
    // stack->push(3);
    // stack->push(4);
    // stack->push(5);
    // stack->push(6);
    // std::cout << stack->pop() << std::endl;
    // std::cout << stack->pop() << std::endl;
    // std::cout << stack->pop() << std::endl;
    //// $ OR
    // StackUsingArray st(5);
    // st.push(1);
    // st.push(2);
    // st.push(3);
    // st.push(4);
    // st.push(5);
    // st.push(6);
    // std::cout << st.pop() << std::endl;
    // std::cout << st.pop() << std::endl;
    // std::cout << st.pop() << std::endl;

    // ? StackUsingLinkedList
    StackUsingLinkedList *stack = new StackUsingLinkedList();
    std::cout << stack->pop() << std::endl;
    std::cout << stack->peek() << std::endl;
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);
    std::cout << stack->pop() << std::endl;
    std::cout << stack->pop() << std::endl;
    std::cout << stack->pop() << std::endl;
    // $ OR
    StackUsingLinkedList st;
    std::cout << st.pop() << std::endl;
    std::cout << st.peek() << std::endl;
    st.push(1);
    st.push(2);
    st.push(3);
    std::cout << st.pop() << std::endl;
    std::cout << st.pop() << std::endl;
    std::cout << st.pop() << std::endl;

    return 0;
}