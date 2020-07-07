#include <iostream>

using namespace std;

int main(void) {
    char qqCodes[20] = {0};
    cout<<"Input your qq codes(only 9 numbers): "<<endl;
    cin>>qqCodes;
    int head = 0;
    int tail = 8;

    cout<<"The original qq code is "<<qqCodes<<endl;
    
    cout<<"The real qq code is ";

    for(int i = 0; i < 9; i++) {
        cout<<qqCodes[head];
        head++;
        tail++;
        qqCodes[tail] = qqCodes[head];
        head++;
    }
     
    cout<<endl;

    return 0;
}
