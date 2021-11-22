#pragma once
#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
public:
	Matrix(); //Ĭ�Ϲ��캯��
	Matrix(int n); //���캯��
	~Matrix(); //��������
	
	void create(); //�������
	void print();  //��ӡ����
	bool save(const char*); //������洢���ļ���
	void read(); //���ļ��ж�ȡ����

//private:
	int size; //�����С,Ĭ�ϳ��Ϳ����
	int** arr; //��������
	int* index; //����洢���ļ��е�����
};

#endif