#include <iostream>

using namespace std;
const int n = 2;

int array[n] = {0};

void quickSort(int left,int right) {

    if(left > right) {
        return;
    } else {
        int temp = array[left];
        int i = left;
        int j = right;

        while(i != j) {
            while(array[j] >= temp && i < j) {
                j--;
            } 
            while(array[i] <= temp && i < j) {
                i++;
            } 
            if(i < j) {
                swap(array[i],array[j]);
            }
        }

        array[left] = array[i];
        array[i] = temp;

        quickSort(left, i-1);
        quickSort(i+1, right);
    }
}

int main(void) {
    cout<<"Input "<<n<< " numbers: "<<endl;
    for(int i = 0; i < n; i++) {
        cin>>array[i];
    }

    cout<<"Before sort: "<<endl;
    for(int i = 0; i < n; i++) {
        cout<<array[i]<<"\t";
    }

    quickSort(0, n-1);

    cout<<endl;
    cout<<"After sort: "<<endl;
    for(int i = 0; i < n; i++) {
        cout<<array[i]<<"\t";
    }

    return 0;
}