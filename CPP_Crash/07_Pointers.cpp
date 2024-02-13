#include<iostream>
using namespace std;


int main(){

    int num = 50;
    cout<<"Address of num : "<<&num<<endl;

    // creating pointer
    int *ptrToNum = &num;

    cout<<num<<endl;
    cout<<&num<<endl;
    cout<<ptrToNum<<endl;
    cout<<&ptrToNum<<endl;
    cout<<*ptrToNum<<endl;

    /*
     * *ptrToNum = value store at address that is store at ptrToNum 
    */

    // * : derefrence operator

    // updating
    (*ptrToNum)++;
    cout<<"value after num : "<<num<<endl;
    cout<<"value after num : "<<*ptrToNum<<endl;


    // creating null pointer
    // int *ptr = NULL;
    // cout<<*ptr<<endl;

    // ! throw : segmentation fault
}