#include <iostream>

using namespace std;

void print_array(int* A, int size){
    cout << "Array: " << endl;
    cout << "[" ;
    for(int i = 0; i < size; i++){
        cout << A[i];
        if(i != size -1){
            cout << ", ";
        }
    }
    cout << "]";
    cout << endl;
}

void print_mem_locations(int *A, int size){
    for(int i = 0; i < size; i++){
        cout << &A[i] << " : " << A[i] << endl;
    }
}

void array_to_string(int* A, int size){
    cout << "Array size: " << size << endl;
    cout << endl;

    print_array(A, size);
    cout << endl;

    cout << "Memory locations:" << endl;
    print_mem_locations(A, size);

}

int main() {
    cout << "Hello, World!" << endl;

    int A[] = {1, 2, 3, 4};
    int arraySize = sizeof(A) / sizeof(A[0]);

    array_to_string(A, arraySize);

    return 0;
}