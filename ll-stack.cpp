#include "ll-stack.h"
#include <iostream>

template <typename T> void Stack<T>::push(T data) {
    Node<T> *newNode = new Node<T>(data);
    newNode->next = top;
    top = newNode;
};

template <typename T> bool Stack<T>::isEmpty() { return top == nullptr; };

template <typename T> T Stack<T>::peek() {
    if (!isEmpty())
        return top->data;
    else
        exit(1);
};

template <typename T> T Stack<T>::peek_next() {
    if (!isEmpty())
        return top->next->data;
    else
        exit(1);
};


template <typename T> void Stack<T>::pop() {
    Node<T> *tmp;
    if (top == nullptr)
        std::cout << "pop() on empty List\n";
    else {
        tmp = top;
        top = top->next;
        free(tmp);
    }
}

template <typename T> void Stack<T>::display() {
    Node<T> *tmp;
    if (top == nullptr) {
        std::cout << "empty List\n";
    } else {
        std::cout << "-> ";
        tmp = top;
        while (tmp != nullptr) {
            std::cout << tmp->data;
            tmp = tmp->next;
            if (tmp != nullptr)
                std::cout << " ";
        }
        std::cout << "\n";
    }
}
