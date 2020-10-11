
#include <iostream>
#include <stdlib.h>//srand and rand 
using namespace std;

//Struct for Number data members value and quantity
struct Number
{
    int value;
    int quantity;
};

void merge( Number *arrayPtr, int start, int end, int middle )
{
    int s, e, m, temp[ end - start + 1];
    s = start;
    e = end;
    m = middle + 1;
    
    while ( s <= middle && m <= e )
    {
        if ( arrayPtr[s].quantity < arrayPtr[m].quantity  )
        {
            temp
        }
    }
}

//using mergesort
void mergeSort( Number *arrayPtr, int start, int end )
{
    int middle;
    if ( start < end )
    {
        mid = (start + end) / 2;
        
        mergeSort( arrayPtr, start, middle );
        mergeSort( arrayPtr, mid + 1, high );
        
        merge( arrayPtr, start, high, middle );
    }
}


//function called find mode
void findMode( int size, int list[] )
{
    int modeQuantity;
    Number listNumbers[size] = {0};
    for ( int p = 0; p < size; p++)
    {
        int newQuantity = listNumbers[list[p]].quantity + 1;
        listNumbers[list[p]] = { list[p], newQuantity };
        if ( newQuantity > modeQuantity )
        {
            modeQuantity = newQuantity;
        }
        cout<<"listNumbers[list[p]] "<<list[p]<<" quantity "<<newQuantity<<endl;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //displaying part of method, not included in the runtime
    // cout<<"modes are ";
    // for ( int y = 0; y < size; y++ )
    // {
    //     //cout<<"modes[y].quantity "<<y<<" Value "<<modes[y].quantity<<endl;
        
    //     if ( modes[y].quantity > 1 )
    //     {
    //         cout<< modes[y].value<<" ";
    //     }
    // }
    
}

int main()
{

    //get n a size for the lost from user
    cout<<"Enter a list size: "<<endl;
    int n;
    cin>>n;
    int list[n];
    //create randomized list with value less than n
    srand(time(0));
    for ( int i = 0; i < n; i++)
    {
        int randomNum = rand() % n;
        list[i] = randomNum;
        cout<<list[i]<<endl;
    }
    //callfind mode
    findMode( n, list );
    return 0;
}



