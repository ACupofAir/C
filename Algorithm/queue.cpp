#include <iostream>

using namespace std;

int main(void) {
    char qqCodes[9] = {0};
    char qqCodesTemp[9] = {0};

    cout<<"Type your QQ codes (only 9 numbers): "<<endl;

    cin>>qqCodesTemp;

    cout<<"The original code is ";
    for(int i = 0; i < 9; i++) {
        cout<<qqCodesTemp[i];
    }
    cout<<endl;

    for(int i = 0; i < 9; i++) {
        qqCodes[i] = qqCodesTemp[8-i];
    }

    for(int i = 8; i > 0; i--) {
        int temp = qqCodes[i-1];

        //Move queue:
        for(int k = i-1; k > 0; k--) {
            qqCodes[k] = qqCodes[k-1];
        }

        qqCodes[0] = temp;
    }

    
    cout<<"The real code is ";
    for(int i = 8; i >= 0; i--) {
        cout<<qqCodes[i];
    }
    cout<<endl;
    return 0;
}
