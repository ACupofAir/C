#include <iostream>

using namespace std;

class student {
    public:
        int score;
        string name;
};

int main(void) {

    student array[11];

    for(int i = 0; i < 5; i++) {
        cout<<"Input student's name(new in macos): "<<endl;
        cin>>array[i].name;   
        cout<<"Input its score: "<<endl;
        cin>>array[i].score;   
    } 

    cout<<"Before sort: "<<endl;
    for(int i = 0; i < 5; i++) {
        cout<<array[i].name<<" got "<<array[i].score<<endl;
    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < (4-i); j++) {
            if(array[j].score > array[j+1].score) {
                continue;
            } else {
                swap(array[j], array[j+1]);
            }
        }
    }
    
    cout<<"After sort: "<<endl;
    for(int i = 0; i < 5; i++) {
        cout<<array[i].name<<" got "<<array[i].score<<endl;
    }
    return 0;
}