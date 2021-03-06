// Week1_QuickFind.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 记录每颗树的大小，在合并树时，一直把小树放入大树中去。
// Weighted Quik Find

// index 0 1 2 3 4 5 6 7 8 9
// id[i] 0 1 9 4 9 6 6 7 8 9

// In Graph:
// 0 1  9   6  7  8
//     | |  |
//     2 4  5
//       |
//       3

int index[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int id[] =	  {6, 2, 6, 4, 4, 6, 6, 2, 4, 4};

vector<int> vecIndex;
vector<int> vecID;

void Init();
int GetRootID(int index);

void connect(int index, int index2)
{
	cout << "connecting " << index << " with " << index2<< endl;

	int rootP = GetRootID(index);
	int rootQ = GetRootID(index2);
	if (rootP == rootQ)
		return;

	vecID[index2] = rootP;
}

int GetRootID(int index)
{
	while (vecID[index] != index)
	{
		index = vecID[index];
	}
	return index;
}

bool IsConnect(int index, int index2)
{	
	bool bResult = GetRootID(index) == GetRootID(index2);

	cout << "IsConnect(" 
		<< index << "-" << index2 << "): " 
		<< bResult << endl;

	return bResult;
}

void Print()
{
	// 先把Root一样的都放一起
	// 遍历时，把过程量也放到一起


}

int _tmain(int argc, _TCHAR* argv[])
{
	Init();

	cout << "Original" << endl;
	Print();
	IsConnect(0, 1);
	IsConnect(7, 8);

	//////////////////////////////////////////////////////////////////////////
	cout << endl;	
	IsConnect(9, 6);
	IsConnect(9, 5);
	connect(9, 6);
	Print();

	IsConnect(9, 6);
	IsConnect(9, 5);
	IsConnect(2, 3);

	return 0;
}

void Init()
{
	vecIndex.assign(index, index+10);
	vecID.assign(id, id+10);
}
