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
    if (!isEmpty() && top->next != nullptr)
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
    }
    delete tmp;
}

template <typename T> void Stack<T>::display(bool wide) {
    Node<T> *tmp;
    if (top == nullptr) {
        std::cout << "empty List\n";
    } else {
        tmp = top;
        while (tmp != nullptr) {
            std::cout << tmp->data;
            tmp = tmp->next;
            if (tmp != nullptr)
                if (wide)
                    std::cout << "  ";
                else
                    std::cout << " ";
        }
        std::cout << "\n";
    }
}
