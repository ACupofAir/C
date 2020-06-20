#include <iostream>

using namespace std;

int main(void) {
    int array[11] = {0};
    
    int input_num;
    for(int i = 0; i < 5; i++) {
        cout<<"Input a number from 0 to 10: "<<endl;
        cin>>input_num;
        array[input_num]++; 
    }

    cout<<"After sort: "<<endl;

    for(int i = 10; i >= 0; i--) {
        for(int k = 0; k < array[i]; k++) {
            cout<<i;
        }
    }

    return 0;
}