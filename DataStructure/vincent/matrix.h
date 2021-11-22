#pragma once
#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
public:
	Matrix(); //默认构造函数
	Matrix(int n); //构造函数
	~Matrix(); //析构函数
	
	void create(); //创造矩阵
	void print();  //打印矩阵
	bool save(const char*); //将矩阵存储在文件中
	void read(); //从文件中读取矩阵

//private:
	int size; //矩阵大小,默认长和宽相等
	int** arr; //矩阵内容
	int* index; //矩阵存储在文件中的索引
};

#endif