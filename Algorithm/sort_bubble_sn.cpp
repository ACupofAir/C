#include <iostream>

using namespace std;

int main(void) {
    int n;
    cout<<"Input the number of students: "<<endl;
    cin>>n;
    int snCode[n] = {0};

    for(int i = 0; i < n; i++) {
        cout<<"Input your sn code: "<<endl;
        cin>>snCode[i];
    }

    cout<<"Before sort: "<<endl;
    cout<<"There are "<<n<<"students"<<endl;
    for(int i = 0; i < n; i++) {
        cout<<snCode[i]<<"\t";
    }

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(snCode[j] > snCode[j+1]) {
                swap(snCode[j], snCode[j+1]);
            }
        }
    }


    cout<<endl<<"After sort: "<<endl;
    cout<<"There are "<<n<<"students"<<endl;
    cout<<snCode[0]<<"\t";
    for(int i = 1; i < n; i++) {
        if(snCode[i] != snCode[i-1]) {
            cout<<snCode[i]<<"\t";
        }
    }
    return 0;
}