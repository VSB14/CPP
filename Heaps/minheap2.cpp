#include <iostream>
using namespace std;

class minheap2
{
private:
    /* data */
public:
    int arr[100];
    int size = 0;
    void insert(int val){

        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index>1)
        {
            int parent = index/2;
            
        }
        

    }
};

minheap2::minheap2(/* args */)
{
}

minheap2::~minheap2()
{
}
