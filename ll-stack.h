#pragma once

template <typename T> class Node {
  public:
    T data;
    Node *next;

    Node(T n) {
        this->data = n;
        this->next = nullptr;
    }
};

template <typename T> class Stack {
    Node<T> *top;

  public:
    Stack<T>() { top = nullptr; };
    void push(T data);
    bool isEmpty();
    T peek();
    T peek_next();
    bool peek_next_exists();
    void pop();
    void display(bool wide);
};



template <typename T> class Queue {
    Node<T> *front;
    Node<T> *rear;

public:
    Queue<T>() { front = rear = nullptr; };
    void enqueue(T data);
    bool isEmpty();
    T peek();
    void dequeue();
    void display(bool wide);
};



