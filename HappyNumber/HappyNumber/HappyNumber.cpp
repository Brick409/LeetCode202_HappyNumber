// HappyNumber.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
判断一个数是否为happy nuumber，所谓happy number是指一个数，
将其替换为其各位数字的平方和，重复这个过程，如果最终能得到1，
这就是happy number；如果陷入一个不包含1的循环中，就不是happy number；
例如：19为happyNumber
1的平方+9的平方=82；
8的平方+2的平方=68；
6的平方+8的平方=100；
1的平方+0的平方+0的平方=1；
*/
class Solution {
public:
	int sum(int n)
	{
		int sum = 0; //存放各位的平方和
		int k = 0;  //临时变量，存放n对10的余数

		while (n!=0)
		{
			k = n % 10;
			sum = sum + k * k;
			n = n / 10;
		}
		return sum;
	}

	bool isHappy(int n) {
		double A = sum(n); //存放n数的平方和
		double B = sum(A); //存放A数各位的平方和

		//判断条件，当A==1或者A==B的时候跳出循环
		while (A!=1 && A!=B)
		{
			A = sum(A);
			B = sum(sum(B));
		}

		//当A==B的时候肯定不等于1，所以通过下面A==1的结果来作为返回值

		return A == 1;
	}


};

int main()
{
	int n = 29;

	if (Solution().isHappy(n))
	{
		cout << n << " is a happy number!\n";
	}
	else
	{
		cout << n << " is not a happy number!\n";
	}

    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
