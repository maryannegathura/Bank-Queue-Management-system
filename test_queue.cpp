#include <iostream>
#include "Queue.h"

using namespace std;

int main() {

    // Create a queue for testing
    Queue<int> bankQueue;

    cout << "BANK QUEUE MANAGEMENT SYSTEM" << endl;
    cout << "=============================" << endl;


    // Test 1: Check if queue is empty
    cout << "\n1. Checking if queue is empty..." << endl;

    if (bankQueue.isEmpty()) {
        cout << "The queue is empty." << endl;
    }
    else {
        cout << "The queue is not empty." << endl;
    }


    // Test 2: Add customers to the queue
    cout << "\n2. Adding customers..." << endl;

    bankQueue.enqueue(101);
    bankQueue.enqueue(102);
    bankQueue.enqueue(103);
    bankQueue.enqueue(104);

    cout << "Customers added successfully." << endl;


    // Test 3: Display the queue
    cout << "\n3. Displaying the queue..." << endl;

    bankQueue.display();


    // Test 4: Check queue size
    cout << "\n4. Checking queue size..." << endl;

    cout << "Number of customers waiting: "
         << bankQueue.size() << endl;


    // Test 5: Check front customer
    cout << "\n5. Checking the customer at the front..." << endl;

    cout << "Customer at the front: "
         << bankQueue.front() << endl;


    // Test 6: Dequeue a customer
    cout << "\n6. Serving the first customer..." << endl;

    cout << "Customer served: "
         << bankQueue.dequeue() << endl;


    // Test 7: Display queue after dequeue
    cout << "\n7. Queue after serving one customer..." << endl;

    bankQueue.display();


    // Test 8: Check new front
    cout << "\n8. Checking the new front customer..." << endl;

    cout << "New customer at the front: "
         << bankQueue.front() << endl;


    // Test 9: Check new size
    cout << "\n9. Checking the new queue size..." << endl;

    cout << "Number of customers waiting: "
         << bankQueue.size() << endl;


    return 0;
}