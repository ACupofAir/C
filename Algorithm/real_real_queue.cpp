#include <iostream>

using namespace std;

class queue {
    public: 
        char data[20];
        int head;
        int tail;
};

int main(void) {
    queue qqCodes;
    cout<<"Input your qq numbers (only 9 numbers): "<<endl;
    cin>>qqCodes.data;

    qqCodes.head = 0;
    qqCodes.tail = 8;

    cout<<"The real qq code is ";
    for(int i = 0; i < 9; i++) {
        cout<<qqCodes.data[qqCodes.head];
        qqCodes.head++;
        qqCodes.tail++;
        qqCodes.data[qqCodes.tail] = qqCodes.data[qqCodes.head];
        qqCodes.head++;
    }

    return 0;
}