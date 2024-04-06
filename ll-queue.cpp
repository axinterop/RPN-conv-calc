#include "ll-stack.h"
#include <iostream>

template <typename T> void Queue<T>::enqueue(T data) {
    auto *newNode = new Node<T>(data);
    if (rear == nullptr) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

template <typename T> bool Queue<T>::isEmpty() {
    return front == nullptr;
}

template <typename T> T Queue<T>::peek() {
    if (!isEmpty()) {
        return front->data;
    } else {
        std::cerr << "peek() on empty Queue\n";
        exit(1);
    }
}

template <typename T> void Queue<T>::dequeue() {
    if (isEmpty()) {
        std::cerr << "dequeue() on empty Queue\n";
        return;
    }
    Node<T> *temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
}

template <typename T> void Queue<T>::display(bool wide) {
    if (isEmpty()) {
        std::cout << "Empty Queue\n";
        return;
    }
    Node<T> *temp = front;
//    std::cout << "Front -> ";
    while (temp != nullptr) {
        std::cout << temp->data;
        temp = temp->next;
        if (temp != nullptr) {
            if (wide)
                std::cout << "  ";
            else
                std::cout << " ";
        }
    }
//    std::cout << " <- Rear\n";
}