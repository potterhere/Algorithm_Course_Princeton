﻿// w11_3_Compression_LZW.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "LZW.h"

int main()
{
	string txt = "ABRACADABRABRABRA";

	LZW lzw;
	string result = lzw.compress(txt);
	cout << result << endl;

	cout << "Origin:" << txt << endl;
	cout << "Restored: " << lzw.expand(result) << endl;
}
