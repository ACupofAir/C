#include <iostream>

using namespace std;

class Queue {
 public:
  char data[100];
  int head;
  int tail;
};

class Slack {
 public:
  char data[10];
  int top;
};

int main(void) {
  // init tatble
  Slack table;
  table.top = 0;
  Queue xiaoHa, xiaoHeng;
  cout << "3Input six numbers to init xiaoHa: \n";
  cin >> xiaoHa.data;
  cout << "Input six numbers to init xiaoHeng: \n";
  cin >> xiaoHeng.data;
  xiaoHa.head = 0;
  xiaoHa.tail = 5;
  xiaoHeng.head = 0;
  xiaoHeng.tail = 5;

  // Start
  while (xiaoHa.head < xiaoHa.tail && xiaoHeng.head < xiaoHeng.tail) {
    int temp = xiaoHa.data[xiaoHa.head++];
    int flag = 0;
    for (int i = 0; i < table.top; i++) {
      if (temp == table.data[table.top]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      table.data[++table.top] = temp;
    } else {
      xiaoHa.data[++xiaoHa.tail] = temp;
      while (table.data[table.top] != temp) {
        xiaoHa.data[++xiaoHa.tail] = table.data[table.top--];
      }
    }

    temp = xiaoHeng.data[xiaoHeng.head++];
    for (int i = 0; i < table.top; i++) {
      if (temp == table.data[table.top]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      table.data[++table.top] = temp;
    } else {
      xiaoHeng.data[++xiaoHeng.tail] = temp;
      while (table.data[table.top] != temp) {
        xiaoHeng.data[++xiaoHeng.tail] = table.data[table.top--];
      }
    }
  }
  cout << "On the table: " << table.data << endl;
  if (xiaoHa.head == xiaoHa.tail) {
    cout << "Xiaoheng win" << endl;
    cout << "xiaoHeng's pai: " << xiaoHeng.data;
  } else {
    cout << "Xiaoha win" << endl;
    cout << "xiaoHa's pai: " << xiaoHa.data;
  }
  return 0;
}
