/**
 * @file 00_queue_implementation.cpp
 * @author Nirmalya Dhara
 * @brief implementation of queue using array and linked list
 * @date 2024-12-20
 */

#include <bits/stdc++.h>

/**
 * @brief A class implementing a circular queue using an array
 *
 * This class provides a fixed-size circular queue implementation with basic queue operations.
 * The queue uses modular arithmetic to maintain circularity in the array representation.
 *
 * @note The queue has a fixed capacity defined at construction time
 *
 * Time Complexity:
 * - Enqueue: O(1)
 * - Dequeue: O(1)
 * - Front/Rear access: O(1)
 * - Size/Empty check: O(1)
 *
 * Space Complexity: O(n) where n is the capacity
 */
class QueueUsingArray
{
private:
    int front;
    int rear;
    int size;
    int capacity;
    int *arr;

public:
    QueueUsingArray(int capacity)
    {
        this->capacity = capacity;
        this->front = this->rear = -1;
        this->size = 0;
        this->arr = new int[capacity];
    }
    ~QueueUsingArray()
    {
        delete[] arr;
    }

    // * Enqueue operation:=
    void enqueue(int data)
    {
        if (size == capacity)
        {
            std::cout << "Queue is full" << std::endl;
            return;
        }
        if (front == -1)
        {
            front++;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = data;
        size++;
    }
    // * Dequeue operation:=
    int dequeue()
    {
        if (size == 0)
        {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        int data = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % capacity;
        size--;
        return data;
    }
    // * Front operation:=
    int getFront()
    {
        if (size == 0)
        {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        return arr[front];
    }
    // * Rear operation:=
    int getRear()
    {
        if (size == 0)
        {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        return arr[rear];
    }
    // * Size operation:=
    int getSize()
    {
        return size;
    }
    // * isEmpty operation:=
    bool isEmpty()
    {
        return size == 0;
    }
};

class QueueUsingLinkedList
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
    Node *front;
    Node *rear;
    int size;

public:
    QueueUsingLinkedList()
    {
        front = rear = nullptr;
        size = 0;
    }
    ~QueueUsingLinkedList()
    {
        Node *temp = front;
        while (temp != nullptr)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
    }
    // * Enqueue operation:=
    void enqueue(int data)
    {
        Node *newNode = new Node(data);
        if (rear == nullptr)
            front = rear = newNode;
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
    // * Dequeue operation:=
    int dequeue()
    {
        if (front == nullptr)
        {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        int data = front->data;
        Node *temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
        size--;
        return data;
    }
    // * Front operation:=
    int getFront()
    {
        if (front == nullptr)
        {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        return front->data;
    }
    // * Rear operation:=
    int getRear()
    {
        if (rear == nullptr)
        {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        return rear->data;
    }
    // * Size operation:=
    int getSize()
    {
        return size;
    }
    // * isEmpty operation:=
    bool isEmpty()
    {
        return size == 0;
    }
};

int main(int argc, char const *argv[])
{
    // QueueUsingArray q(5);
    // q.enqueue(10);
    // q.enqueue(20);
    // q.enqueue(30);
    // std::cout << "Front element: " << q.getFront() << std::endl;
    // std::cout << "Rear element: " << q.getRear() << std::endl;
    // std::cout << "Size: " << q.getSize() << std::endl;
    // //$ OR
    // QueueUsingArray *queue = new QueueUsingArray(5);
    // queue->enqueue(10);
    // queue->enqueue(20);
    // queue->enqueue(30);
    // std::cout << "Front element: " << queue->getFront() << std::endl;
    // std::cout << "Rear element: " << queue->getRear() << std::endl;
    // std::cout << "Size: " << queue->getSize() << std::endl;

    //! QueueUsingLinkedList
    QueueUsingLinkedList q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    std::cout << "Front element: " << q.getFront() << std::endl;
    std::cout << "Rear element: " << q.getRear() << std::endl;
    std::cout << "Size: " << q.getSize() << std::endl;
    // //$ OR
    QueueUsingLinkedList *queue = new QueueUsingLinkedList();
    queue->enqueue(10);
    queue->enqueue(20);
    queue->enqueue(30);
    std::cout << "Front element: " << queue->getFront() << std::endl;
    std::cout << "Rear element: " << queue->getRear() << std::endl;
    std::cout << "Size: " << queue->getSize() << std::endl;

    return 0;
}
