#include <iostream>
#include <vector>
using namespace std;

#define MAX 100

int heap[MAX];
int heapSize = 0;

/*
The insertion at an arbritary place of heap takes O(n) not O(nlogn) because, during insertion we do shifting which costs O(n), then we do heapify which costs O(logn), since we do not repeat heapify, the largest complexity is choosen which is O(n).
*/

void heapifyUp(int i)
{
    while (i > 0 && heap[(i - 1) / 2] > heap[i])
    {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    return;
}

void heapifyDown(int i)
{
    int smallest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    if (left < heapSize && heap[left] < heap[smallest])
        smallest = left;
    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;
    if (smallest != i)
    {
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
    return;
}

void insert(int val)
{
    if (heapSize == MAX)
    {
        cout << "Heap overflow" << endl;
        return;
    }
    heap[heapSize] = val;
    heapifyUp(heapSize);
    heapSize++;
    return;
}

void deletion(int i)
{
    if (heapSize == 0)
    {
        cout << "Underflow" << endl;
        return;
    }
    int val = heap[i];
    heap[i] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(i);
    cout << "Value: " << val << endl;
}

int search(int val) {
    for(int i=0; i<heapSize; i++) {
        if(val == heap[i]) return i;
    }

    return -1;
}

int main()
{
    insert(4);
    insert(3);
    insert(5);
    insert(1);
    insert(2);
    insert(3);
    insert(-2);
    for (int i = 0; i < heapSize; i++)
    {
        cout << heap[i] << " ";
    }
    cout<<endl;
    cout<<"Index: "<<search(4)<<endl;
    deletion(0);
    insert(1);
    deletion(3);
    cout<<"Index: "<<search(1)<<endl;
    deletion(2);
    insert(4);
    cout<<"Index: "<<search(0)<<endl;
    deletion(5);

    for (int i = 0; i < heapSize; i++)
    {
        cout << heap[i] << " ";
    }
}