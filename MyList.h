#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>

// Forward declaration of MyList to make it a friend class
template <typename T>
class MyList;

// Node class template
template <typename T>
class Node {
    friend class MyList<T>; // Make MyList a friend class
private:
    T data;
    Node<T>* next;
public:
    // Constructor
    Node(T data) : data(data), next(nullptr) {}
};

// MyList class template
template <typename T>
class MyList {
private:
    Node<T>* head;
public:
    // Constructor
    MyList() : head(nullptr) {}

    // Destructor
    ~MyList() {
        while (head != nullptr) {
            deleteHead();
        }
    }

    // Insert an element at the head of the list
    void insertHead(T theData) {
        Node<T>* newNode = new Node<T>(theData);
        newNode->next = head;
        head = newNode;
    }

    // Delete the head node and return its data
    T deleteHead() {
        if (head == nullptr) {
            throw std::runtime_error("List is empty, cannot delete head.");
        }
        Node<T>* oldHead = head;
        T headData = head->data;
        head = head->next;
        delete oldHead;
        return headData;
    }

    bool search(T &target) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == target) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Display all elements in the list
    void display() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }
};

#endif // MYLIST_H