#include<bits/stdc++.h>
using namespace std;

/*   time complexity for binary search insertion sort
     best case : O(nlog(n))
     average case , worst case : O(n^2)
*/
int binarySearch(int arr[], int newElement,int left, int right)
{
    if (left >= right) {
        if (newElement > arr[left])
            return (left + 1);
        else
            return left;
    }
    int m = (left + right)/2;

    if(newElement == arr[m])
        return m+1;

    if(newElement > arr[m])
        return binarySearch(arr, newElement, m+1, right );

    return binarySearch(arr, newElement,left, m-1  );
}

void binarySort(int arr[], int n){
    int  element, j;
    for (int i = 1; i < n; i++) {
        element = arr[i];
        j = i - 1;
       int  position = binarySearch(arr, element,0, j ); // to find the position where new element should be insert

       // shift all elements after new position 
        while (j >= position) {
            arr[j+1] = arr[j];
            j --;
        }
        arr[j+1] = element;
    }
}
/*   time complexity for regular insertion sort
     best case : O(n)
     average case , worst case : O(n^2)
*/
void insertionSort(int arr[], int n){
    int temp;
    for (int i = 1,j ; i < n; i++){
        temp = arr[i];

        for (j=i; j >0 &&  temp < arr[j-1];j-- ){
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}

int main(){

    double binaryArray[10] , insertionArray[10];  // to store time complexity for each size of array ( n )
    int j=0;
    
    for(int i=0;i<10;i++){
        cout<<"enter array size: ";
        int size;
        cin>>size;
        
        int arr1[size];
        for (int k = 0; k < size; ++k) {
            arr1[k]=rand() % 10000;  //fill the array with random numbers
        }
        double start=clock();        //  time before calling function
        insertionSort(arr1,size);
        double end=clock();          // time after calling function
        insertionArray[j]= (end-start)/(double)( CLOCKS_PER_SEC/1000); // to get the duration of run time

        
        
        int arr2[size];
        for (int k = 0; k < size; ++k) {
            arr2[k]= rand() % 1000;  //fill the array with random numbers
        }
       start=clock();                //  time before calling function
       binarySort(arr2,size-1);
       end=clock();                  // time after calling function
       binaryArray[j]=(end-start)/(double)( CLOCKS_PER_SEC/1000); // to get the duration of run time


       cout<<"binarySearch: "<<binaryArray[j]<<" msec.\n";
       cout<<"Insertion: "<<insertionArray[j]<<" msec.\n";

       j++;
       
       
    }


}
