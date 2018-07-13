// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
// 在该程序中，设计了一个非常简单的累加运算，然后求平均计算偏差，展示不同的计算精度带来带来的计算误差。
// 该程序要与对应的matlab程序配合使用

#include "stdafx.h"

#include <stdio.h>
#include <tchar.h>
#include <string>
#include <iostream>

using namespace std;


//typedef  double  Datatype;     //  You can change the Datatype to double or float. Note that the matlab program  should be changed corrrespondingly.
typedef  float   Datatype;

#define  PI        3.1415926535 
#define  N_INNER  10             //  You can change the number to others, such as  1,100, 1000,.... 
#define  N_OUT    10000          //  You can change the number to others.


bool SaveDataFloat(Datatype *ga, string filename, int dataNum)
{
	FILE *stream = NULL;
	errno_t err;

	// Open for read (will fail if file "crt_fopen_s.c" does not exist)
	if ((err = fopen_s(&stream, filename.c_str(), "wb")) != 0)
	{
		printf("The file  was not opened\n");
		return false;
	}

	fwrite(ga, sizeof(Datatype), dataNum, stream);

	fclose(stream);
	stream = NULL;

	return true;
}



int _tmain(int argc, _TCHAR* argv[])
{

	Datatype sum = 0.0f, ave = 0.0f;
	Datatype err[N_OUT] = { 0.0f };

	for (int ii = 0; ii < N_OUT; ii++)
	{
		for (int jj = 0; jj < N_INNER; jj++)
		{
			sum = sum + PI;
		}
		ave = sum / (N_INNER*(ii + 1));
		err[ii] = PI - ave;
	}


	string fileName("D:\\err4.raw");
	if (false == SaveDataFloat(err, fileName, N_OUT))
	{
		printf("There is an error during save error data!\n");
		printf("Press any key to exit!\n");
		cin.get();
		exit(0);
	}

	return 0;
}

