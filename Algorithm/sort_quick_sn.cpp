#include <iostream>

using namespace std;

void quickSort(int* array, int left, int right) {
    if(left > right ) {
        return;
    }

    int i = left;
    int j = right;
    int standNumber = array[left];

    while(i < j) {
        while(array[j] >= standNumber  && i < j) {
            j--;
        }
        while(array[i] <= standNumber && i < j) {
            i++;
        }
        swap(array[i], array[j]);
    }

    if(i == j) {
        swap(array[i], array[left]);
    }

    quickSort(array, left, i-1);
    quickSort(array, i+1, right);
}

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
    for(int i = 0; i < n; i++) {
        cout<<snCode[i]<<"\t";
    }    

    quickSort(snCode, 0, n-1);
    
    cout<<endl<<"After sort: " <<endl;
    for(int i = 0; i < n; i++) {
        cout<<snCode[i]<<"\t";
    }

    cout<<endl<<"No repeat: "<<endl;
    cout<<snCode[0]<<"\t";
    for(int i = 1; i < n; i++) {
        if(snCode[i] != snCode[i-1]){
            cout<<snCode[i]<<"\t";
        }
    }

    return 0;
}