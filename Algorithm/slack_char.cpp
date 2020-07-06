#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
    char slack[20];
    int top = 0;

    char testText[20];
    cout<<"Input a string: "<<endl;
    cin>>testText;

    int len = strlen(testText);
    int mid = len/2-1;

    //Popin slack
    for(int i = 0; i <= mid; i++) {
        slack[top++]=testText[i];
    }

    //check arrary
    int next;
    if(len%2==0) {
        next = mid + 1;
    } else {
        next = mid + 2;
    }

    for(int i = next; i < len; i++) {
        if(testText[i] != slack[--top]) {
            break;
        }
    }

    if(top == 0) {
        cout<<"It is symmetry.";
    } else {
        cout<<"It is not symmetry.";
    }
    return 0;
}
