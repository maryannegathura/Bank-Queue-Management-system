#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>
using namespace std;

// Node represents one item in the queue
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    // Constructor
    Node(T value) {
        data = value;
        next = nullptr;
    }
};


// Queue class
template <typename T>
class Queue {
private:
    Node<T>* frontNode;
    Node<T>* rearNode;
    int count;

public:

    // Constructor
    Queue() {
        frontNode = nullptr;
        rearNode = nullptr;
        count = 0;
    }

    // Destructor
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }


    // ENQUEUE
    // Adds a customer to the rear of the queue
    void enqueue(T value) {

        Node<T>* newNode = new Node<T>(value);

        // If the queue is empty
        if (isEmpty()) {
            frontNode = newNode;
            rearNode = newNode;
        }
        else {
            // Add the new customer after the current rear
            rearNode->next = newNode;

            // Move rear to the new customer
            rearNode = newNode;
        }

        count++;
    }


    // DEQUEUE
    // Removes and returns the customer at the front
    T dequeue() {

        // Check if queue is empty
        if (isEmpty()) {
            throw runtime_error("Cannot dequeue. The queue is empty.");
        }

        // Store the current front
        Node<T>* temp = frontNode;

        // Store the customer's data
        T value = temp->data;

        // Move front to the next customer
        frontNode = frontNode->next;

        // If the queue becomes empty,
        // rear must also become null
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }

        // Delete the old front node
        delete temp;

        count--;

        return value;
    }


    // FRONT
    // Returns the customer at the front
    // without removing them
    T front() {

        if (isEmpty()) {
            throw runtime_error("The queue is empty.");
        }

        return frontNode->data;
    }


    // ISEMPTY
    // Checks whether the queue is empty
    bool isEmpty() {

        return frontNode == nullptr;
    }


    // SIZE
    // Returns the number of customers
    int size() {

        return count;
    }


    // DISPLAY
    // Displays all customers from front to rear
    void display() {

        if (isEmpty()) {
            cout << "The queue is empty." << endl;
            return;
        }

        Node<T>* current = frontNode;

        cout << "Queue: ";

        while (current != nullptr) {

            cout << current->data;

            if (current->next != nullptr) {
                cout << " -> ";
            }

            current = current->next;
        }

        cout << endl;
    }
};

#endif