#include <iostream>

using namespace std;

void swap(int& m, int& n) {
    int temp = m;
    m = n;
    n = temp;
}

int main(void) {
    int array[5];
    for(int i = 0; i < 5; i++) {
        cout<<"Input a number: "<<endl;
        cin>>array[i];
    }

    cout<<"Before sort: "<<endl;
    for(int i = 0; i < 5; i++) {
        cout<<array[i]<<"\t";
    }

    for(int i = 0; i < 4; i++) {
        for(int index = 0; index < (4 - i); index++) {
            if(array[index] > array[index+1]) {
                continue;
            } else {
                swap(array[index], array[index+1]);
                // int swap_temp = array[index];
                // array[index] = array[index+1];
                // array[index+1] = swap_temp;
            }
        }
    }


    cout<<endl;
    cout<<"After sort: "<<endl;
    for(int i = 0; i < 5; i++) {
        cout<<array[i]<<"\t";
    }
    return 0;
}