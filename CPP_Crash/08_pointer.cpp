#include<iostream>
using namespace std;


void printSize(int arr[]){
    cout<<"Size inside function : "<<sizeof(arr)<<endl; // 4
}


int main(){

    int arr[4] = {1,2,3,4};
    cout<<"Size inside main : "<<sizeof(arr)<<endl; //16

    // calling function
    printSize(arr);

}