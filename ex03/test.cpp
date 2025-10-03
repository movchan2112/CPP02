#include <iostream>

int minimal(int arr[], int len){
    return 1;
}

int main(){
    int val = 1;
    int &num = val; 
    int arr[] = {1,2,3,4,5};


    minimal(arr,1);
    // int *ptrval = &val;
    // std::cout << val << std::endl;
    // std::cout << num << std::endl;
    // std::cout << *ptrval << std::endl;
}