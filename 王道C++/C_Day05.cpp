#include <iostream>
using namespace std;

// 实现一个交换函数
#if 0
void swap(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

int main()
{
	int a = 1;
	int b = 2;
	cout << "a = " << a << "  b = " << b << endl;
	swap(a, b);
	cout << "a = " << a << "  b = " << b << endl;
}
#endif

#if 0
// 求斐波那契数列
// 递归版本
long long fib1(int n)
{
	if (n == 1 or n == 2)
	{
		return 1;
	}
	return fib1(n - 1) + fib1(n - 2);
}

// 非递归版本
long long fib2(int n)
{
	if (n == 1 or n == 2)
	{
		return 1;
	}
	long long item_1 = 1;
	long long item_2 = 1;
	int i = 3;
	long long ans = 0;
	while (i <= n)
	{
		ans = item_1 + item_2;
		item_1 = item_2;
		item_2 = ans;
		i++;
	}
	return ans;
}

int main()
{
	clock_t start = clock();
	cout << "第50项斐波那契树为： " << fib1(50) << endl;
	clock_t end = clock();
	cout << "fib1(50)的运行时间为: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

	start = clock();
	cout << "第50项斐波那契树为： " << fib2(50) << endl;
	end = clock();
	cout << "fib2(50)的运行时间为: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

	return 0;
}
#endif