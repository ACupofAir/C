#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;

typedef HANDLE Semaphore;

const int n = 5; //thread
const int m = 3; //resource

int Work[m], running = 5;
vector<int> safe_squen;
BOOL Finish[n];
int Max[n][m] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}};
int Allocation[n][m] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}};
int Need[n][m] = {
    {7, 4, 3},
    {1, 2, 2},
    {6, 0, 0},
    {0, 1, 1},
    {4, 3, 1}};
int Available[m] = {3, 3, 2};
Semaphore rmutex, wmutex[n];
void Request(int i, int r[]);
BOOL check();
DWORD WINAPI Processor(LPVOID pParam)
{
	int i = (int)pParam, j, res[m], c = 0;
	while (TRUE)
	{
		srand(time(NULL));
		WaitForSingleObject(rmutex, INFINITE);
		for (j = 0; j < m; j++)
		{
			if (Need[i][j] > 0)
				break;
			if (j == m) //all need is 0
			{
				running--; //one thread is over
				if (running == 0)
					printf("all thread is over!\n");
				ReleaseSemaphore(rmutex, 1, NULL);
				break;
			}
		}

		for (j = 0; j < m; j++)
			res[j] = (1 + Need[i][j]) * (((float)(rand() % 10)) / 10);
		ReleaseSemaphore(rmutex, 1, NULL);
		Request(i, res);
		Sleep(rand() % 10 / 10 * 1000);
	}
	return 1;
}
void Request(int i, int res[])
{
	int j;
	WaitForSingleObject(rmutex, INFINITE);
	for (j = 0; j < m; j++)
		if (res[j] > 0)
			break;
	if (j == m) //all resources is zero
	{
		ReleaseSemaphore(rmutex, 1, NULL);
		return;
	}
	printf("P%d request:", i);
	for (j = 0; j < m; j++)
		printf("%d ", res[j]);
	printf("\t");
	for (j = 0; j < m; j++)
	{
		if (res[j] > Need[i][j])
			break;
	}
	if (j < m)
	{
		printf("P%d request error\n", i);
		ReleaseSemaphore(rmutex, 1, NULL);
		return;
	}
	for (j = 0; j < m; j++)
	{
		if (res[j] > Available[j])
			break;
		Available[j] -= res[j];
		Allocation[i][j] += res[j];
		Need[i][j] -= res[j];
	}
	if (j < m)
	{
		printf("not enough resource,P%d is waiting....\n", i);
		for (j--; j >= 0; j--)
		{
			Available[j] += res[j];
			Allocation[i][j] -= res[j];
			Need[i][j] += res[j];
		}
		//for(j=0;j<m;j++)printf("%d ",Available[j]);
		ReleaseSemaphore(rmutex, 1, NULL);
		WaitForSingleObject(wmutex[i], INFINITE);
		Request(i, res);
	}
	else if (check())
	{
		printf("P%d request is agree\n", i);
		for (j = 0; j < m; j++)
			if (Need[i][j] > 0)
				break;
		if (j == m)
		{
			printf("P%d is ok\n", i);
			safe_squen.push_back(i);
			for (j = 0; j < m; j++)
			{ //release resources
				Available[j] += Allocation[i][j];
				Allocation[i][j] = 0;
				Need[i][j] = 0;
			}
			running--; //one thread is over
			if (running == 0)
				printf("\nall request is ok!\n");
		}
		for (i = 0; i < n; i++)
			ReleaseSemaphore(wmutex[i], 1, NULL);
		ReleaseSemaphore(rmutex, 1, NULL);
		return;
	}
	else
	{
		printf("no safe sequence,P%d is waiting....\n", i);
		for (j = 0; j < m; j++)
		{
			Available[j] += res[j];
			Allocation[i][j] -= res[j];
			Need[i][j] += res[j];
		}
		ReleaseSemaphore(rmutex, 1, NULL);
		WaitForSingleObject(wmutex[i], INFINITE);
		Request(i, res);
	}
}

BOOL check()
{
	int i, j, s[n], t = 0;
	BOOL bFlag = TRUE;
	for (j = 0; j < m; j++)
		Work[j] = Available[j];
	for (i = 0; i < n; i++)
	{
		Finish[i] = FALSE;
	}
	while (bFlag)
	{
		bFlag = FALSE;
		for (i = 0; i < n; i++)
		{
			if (Finish[i] == TRUE)
				continue;
			for (j = 0; j < m; j++)
			{
				if (Need[i][j] > Work[j])
				{
					for (j--; j >= 0; j--)
					{
						Work[j] -= Allocation[i][j];
					}
					break;
				}
				Work[j] += Allocation[i][j];
			}
			if (j == m)
			{
				Finish[i] = TRUE;
				s[t] = i;
				t++;
				bFlag = TRUE;
				break;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if (Finish[i] == FALSE)
			break;
	}
	if (i == n)
	{
		return TRUE;
	}
	return FALSE;
}

int main()
{

	DWORD tid;
	int i;
	BOOL bFlag = TRUE;

	rmutex = CreateSemaphore(NULL, 1, 1, "rmutex");
	char Wmutex[2] = {'w'};
	for (i = 0; i < n; i++)
	{
		Wmutex[1] = '0' + i; //Wmutex[]=wi
		wmutex[i] = CreateSemaphore(NULL, 1, 1, Wmutex);
	}

	if (!rmutex || !wmutex) 
	{
		cout << "Create Semaphore Error!\n";
		return 0;
	}

	//create thread
	for (i = 0; i < n; i++)
	{
		HANDLE h = CreateThread(NULL, 0, Processor, (LPVOID)i, 0, &tid);
	}

	Sleep(10000);
	cout<<"Safe Sequence:\n";
	for (int i = 0; i < n; i++)
	{
		cout<<safe_squen[i]<<" ";
	}
}
