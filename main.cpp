
#include <iostream>
#include <stdlib.h>//srand and rand 
using namespace std;

//Struct for Number data members value and quantity
struct Number
{
    int value;
    int quantity;
};

//WAS having trouble implementing mergesort so I used bubblesort instead which change the runtime to from nlogn to n^2  for sorting
// void merge( Number arrayPtr[], int start, int end, int middle )
// {
//     Number temp[ end - start + 1];
//     int s, e, m; 
//     s = start;
//     e = 0;
//     m = middle + 1;
    
//     while ( s <= middle && m <= e )
//     {
//         if ( arrayPtr[s].quantity < arrayPtr[m].quantity  )
//         {
//             temp[e] = arrayPtr[s];
//             e++;
//             s++;
//         }
//         else 
//         {
//             temp[e] = arrayPtr[m];
//             e++;
//             m++;
//         }
//     }
    
    
//     while( s <= middle )
//     {
//         temp[e] = arrayPtr[s];
//         e++;
//         s++;
//     }
    
//     while( m <= end )
//     {
//         temp[e] = arrayPtr[m];
//         e++;
//         m++;
//     }
    
//     for ( int i = 0; i < end; i++ )
//     {
//         arrayPtr[i] = temp[i-start];
//         cout<<"arrayPtr[i] "<<arrayPtr[i].value<<endl;
//     }
// }

// //using mergesort
// void mergeSort( Number arrayPtr[], int start, int end )
// {
//     int middle;
//     if ( start < end )
//     {
//         middle = (start + end) / 2;
        
//         mergeSort( arrayPtr, start, middle );
//         mergeSort( arrayPtr, middle + 1, end );
        
//         merge( arrayPtr, start, end, middle );
//     }
// }



//function called find mode
void findMode( int size, int list[] )
{
    
    Number listNumbers[size] = {0};
    for ( int p = 0; p < size; p++)
    {
        int newQuantity = listNumbers[list[p]].quantity + 1;
        listNumbers[list[p]] = { list[p], newQuantity };
        
    
        //cout<<"listNumbers[list[p]] "<<list[p]<<" quantity "<<newQuantity<<endl;
    }
    //call mergesort by the quantities for Number 
    //mergeSort( listNumbers, 0, size - 1 );
    //couldn't get mergsort to work so i did bubble sort
    
    //Bubblesort
    bool swapped = true;
    while ( swapped )
    {
        swapped = false;
        for ( int i = 0; i < size - 1; i++ )
        {
            if ( listNumbers[i].quantity < listNumbers[i + 1].quantity )
            {
                Number temp =listNumbers[i];
                listNumbers[i] = listNumbers[i + 1];
                listNumbers[i + 1] = temp;
                swapped = true;
            }
            
        }
    }
    for ( int i = 0; i< size - 1; i++)
    {
        cout<<"numbers "<< listNumbers[i].value<<" quantity "<<listNumbers[i].quantity<<endl;
    }
    //int listModes[size/2] ={0};
    int modeQuantity = listNumbers[0].quantity;
    //cout<<"modeQuantity "<<modeQuantity<<endl;
    bool lastMode = false;
    int iterator = 0;
    int lastModeIndex;
    while ( !lastMode )
    {
        //cout<<"listNumbers[i].quantity "<<listNumbers[iterator].quantity<<" modeQuantity "<<modeQuantity<<endl;
        if ( listNumbers[iterator].quantity != modeQuantity )
        {
            lastModeIndex = iterator ;
            lastMode = true;
            
        }
        iterator++;
    }
    //cout<<"lastModeIndex "<<lastModeIndex<<endl;

    //Displaying part of method, not included in the runtime
    cout<<"mode is ";
    for ( int y = 0; y < lastModeIndex ; y++ )
    {
        cout<< listNumbers[y].value<<" ";
    }
    cout<<endl;
    for ( int q = 0; q < size; q++)
    {
        if ( listNumbers[q].quantity > 1 )
        {
            cout<<listNumbers[q].value<<" was repeated "<<listNumbers[q].quantity<<" times"<<endl;
        }
        
    }
    
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




