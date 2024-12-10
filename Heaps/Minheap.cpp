#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[parent] > heap[index]) {
            swap(heap[parent], heap[index]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap() {}

    int extractMinElement() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty.");
        }
        
        int minElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        
        return minElement;
    }

    void deleteElement(int ind) {
        if (ind < 0 || ind >= heap.size()) {
            throw out_of_range("Invalid index.");
        }
        
        heap[ind] = INT_MIN;
        heapifyUp(ind);
        extractMinElement();
    }

1    void insert(int val) {
        heap.push_back(val);
        int lastIndex = heap.size() - 1;
        heapifyUp(lastIndex);
    }
};

int main() {
    MinHeap heap;
    
    heap.insert(10);
    heap.insert(5);
    heap.insert(15);
    heap.insert(3);

    cout << "Minimum element: " << heap.extractMinElement() << endl;
    cout << "Minimum element: " << heap.extractMinElement() << endl;

    heap.deleteElement(1);

    return 0;
}
