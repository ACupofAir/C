#include <iostream>

using namespace std;

int main(void) {
    int book[1000] = {0};

    int n = 10;
    int input_num;
    for(int i = 0; i < n; i++) {
        cout<<"Input a number from 0 to 1000: "<<endl;
        cin>>input_num;
        book[input_num]++;
    }

    cout<<"After sort: "<<endl;
    for(int i = 1000; i >= 0; i--) {
        for(int k = 1; k <= book[i]; k++) {
            cout<<i<<" ";
        }
    }
    return 0;
}