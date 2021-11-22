#include"matrix.h"
#include<iostream>
#include<fstream>
#include<string.h>
#include<cstdlib>
#include<ctime>
using namespace std;
unsigned a = 0;


Matrix::Matrix()
{
	size = 0;
	arr = nullptr;
	index = nullptr;
}

Matrix::Matrix(int n)
{
	size = n;
	arr = new int* [size];

	for (int i = 0; i < size; i++) {
		arr[i] = new int[size];
	}
	index = new int[size];
	int* tag = (int*)malloc(size * sizeof(int));
	int count = 0;
	memset(tag, 0, size * sizeof(int));
	srand(time(NULL));
	while (count < size)
	{
		int val = rand() % size;
		if (!tag[val])
		{
			tag[val] = 1;
			index[count] = val;
			++count;
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < size; i++)
		delete[] arr[i];
	delete[] arr;
	size = 0;
	delete[] index;
}

void Matrix::create() 
{
	//unsigned a = 0;
	//srand((unsigned)time(NULL));  // �����������
	srand(++a);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = rand() % 100; //����0-100�����
		}
	}
}

void Matrix::print() 
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout<<arr[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
}

bool Matrix::save(const char* filename) {
	ofstream outfile;
	outfile.open(filename,ios::out);
	if (!outfile) {
		cout << "Fail to open "<<filename;
		return false;
		exit(1);
	}
	outfile << size<<" ";

	int* index_file = new int[size];
	for (int i = 0; i < size; i++) {
		index_file[index[i]] = i;
	}
	for (int i = 0; i < size; i++) {
		outfile << index_file[i]+2 << " ";
	}
	outfile << endl;
	int j = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			outfile << arr[index[i]][j]<<" ";
		}
		outfile << endl;
	}

}


int main() {
	Matrix A(3);	
	A.create();
	A.print();
	//cout << &A;
	A.save("A.txt");
	Matrix B(3);
	B.create();
	B.print();
	//cout << &B;
	B.save("B.txt");
}
