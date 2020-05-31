#include<iostream>
#include<time.h>
#include <queue>

using namespace std;

const int ARRAY_SIZE = 40e3;



// A class for Min Heap
class MinHeap
{
    public:
        MinHeap(int capacity);
        ~MinHeap();
        void push(int k);
        int pop();
        int peek() { return heap[1]; }
        void printHeap();
    private:
        int *heap; // pointer to array of elements in heap
        int capacity; // maximum possible size of min heap
        int currentSize; // Current number of elements in min heap      
        void MinHeapify(int index);
        int parent(int i) { return (i-1)/2; }
        int left(int i) { return (2*i+1); }
        int right(int i) { return (2*i + 2); }
        void swap(int &x, int &y);
};
 
MinHeap::MinHeap(int cap)
{
    currentSize = 0;
    capacity = cap; 
    heap = new int[capacity];
}

MinHeap::~MinHeap()
{
    delete [] heap;
}
 
void MinHeap::push(int k)
{
    /*
    COMPLETE
    */
}
 
// for now, just return -1 if there's nothing to pop
int MinHeap::pop()
{
    /*
    COMPLETE
    */
 
    return -1;
}
 
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    /*
    COMPLETE
    */
}
 
void MinHeap::swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void MinHeap::printHeap() {
    cout << "The heap array is currently {";
    for (int i = 0; i < currentSize; i++) 
    {
        cout << heap[i];
        if (i < currentSize-1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}
 
int main()
{

    ////////////////////////////////////////////////////////////////////////
    // CREAT A TEST ARRAY OF RANDOM INTEGERS
    int arr[ARRAY_SIZE];
    for( int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = rand()%1000;


    // cout << "the array is: " << endl;

    // for( int i = 0; i < ARRAY_SIZE; i ++ )
    //     cout << arr[i] << " ";


    int startTime, endTime;   
    double execTime;

    ////////////////////////////////////////////////////////////////////////
    // TEST BUBBLE SORT

    startTime = clock();

    for ( int i = ARRAY_SIZE-1; i > 0; i-- )
    {
        for ( int j = 0; j < i; j++ )
            if ( arr[j] > arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
    }
    
    endTime = clock();

    execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;

    cout << "bubble execution time: " << execTime << endl;

    ////////////////////////////////////////////////////////////////////////
    // TEST HEAP SORT

    // Re-populate test array with random ints
    for( int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = rand()%1000;


    return 0;
}