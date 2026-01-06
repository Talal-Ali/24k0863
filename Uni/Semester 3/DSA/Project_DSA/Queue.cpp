#include <iostream>
using namespace std;

class Queue {
private:
    static const int MAX = 100;
    int arr[MAX];
    int frontIndex;
    int rearIndex;
    int count;

public:
    Queue() {
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    void enqueue(int value) {
        if (count == MAX)
            throw runtime_error("Queue overflow");
        rearIndex = (rearIndex + 1) % MAX;
        arr[rearIndex] = value;
        count++;
    }

    int dequeue() {
        if (isEmpty())
            throw runtime_error("Queue underflow");
        int value = arr[frontIndex];
        frontIndex = (frontIndex + 1) % MAX;
        count--;
        return value;
    }

    int peek() {
        if (isEmpty())
            throw runtime_error("Queue is empty");
        return arr[frontIndex];
    }

    bool isEmpty() {
        return count == 0;
    }

    int size() {
        return count;
    }
};


class PriorityQueue {
private:
    static constexpr int MAX = 100;
    int value[MAX];   
    int node[MAX];    
    int count;

public:
    PriorityQueue() : count(0) {}

    
    void pqenqueue(int city, int distance) {
        if (count == MAX)
            throw runtime_error("Priority queue overflow");

        int i = count - 1;

        
        while (i >= 0 && value[i] > distance) {
            value[i + 1] = value[i];
            node[i + 1]  = node[i];
            --i;
        }

        value[i + 1] = distance;
        node[i + 1]  = city;
        ++count;
    }

    int pqdequeue() {
        if (pqisEmpty())
            throw runtime_error("Priority queue underflow");
        int city = node[0];

        for (int i = 1; i < count; ++i) {
            node[i - 1]  = node[i];
            value[i - 1] = value[i];
        }
        --count;
        return city;
    }

    int pqpeekCity() const {
        if (pqisEmpty())
            throw runtime_error("Priority queue is empty");
        return node[0];
    }

    int pqpeekDistance() const {
        if (pqisEmpty())
            throw runtime_error("Priority queue is empty");
        return value[0];
    }

    bool pqisEmpty() const {
        return count == 0;
    }

    int pqsize() const {
        return count;
    }
};
