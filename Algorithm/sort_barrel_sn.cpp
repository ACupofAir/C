#include <iostream>

using namespace std;

int main(void) {    
    int book[1000] = {0};
    int n;

    cout<<"Input the number of students: "<<endl;
    cin>>n;

    cout<<"Input all of sn codes: "<<endl;
    for(int i = 0; i < n; i++) {
        cout<<"Input you sn codes: "<<endl;
        int input_sn_code;
        cin>>input_sn_code;
        book[input_sn_code]++;
    }

    
    cout<<"After sort: "<<endl;
    for(int i = 0; i < 1000; i++) {
        if(book[i] != 0) {
            cout<<i<<"\t";
        }
    }
    return 0;
}