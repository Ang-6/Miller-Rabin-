#include "pch.h"
#include <iostream>
#include <cstdlib> 

using namespace std;

typedef long long ll;

ll qul_mul(ll a, ll b, ll n)  //快速积运算，快速求出a^m^*a^m^并且能防止爆掉
{
	ll num = 0;

	while (b)
	{
		if (b & 1)
		{
			num = (num + a) % n;
		}

		a = (a + a) % n;
		b >>= 1;
	}

	return num;
}

ll qul_pow(ll a, ll b, ll n) //快速幂计算快速求出a^m^的值
{
	ll sum = 1;

	while (b)
	{
		if (b & 1)
		{
			sum = sum * a % n;
		}

		a = a * a%n;
		b >>= 1;
	}

	return sum;
}

bool Miller_Rabin(ll n)
{
	int m = n - 1;
	int t = 0;

	if (n == 2)
	{
		return true;
	}
	else if (n < 2 || !(n & 1))
	{
		return false;
	}

	//求出n-1 = m*2^t的m和t。
	while (!(m & 1))
	{
		m >>= 1;
		t++;
	}

	for (int i = 0; i < 4; i++)
	{
		//随机数a
		ll a = rand() % (n - 1) + 1;
		cout <<"a:"<< a<<endl;
		// 计算a^m
		ll x = qul_pow(a, m, n), y;
		cout << "x:"<<x<<endl;
		cout << endl;
		for (int j = 0; j < t; j++)
		{
			y = qul_mul(x, x, n);  //进行(x*x)%n操作。
			cout <<"y:"<< y<<endl;
			cout << endl << endl ;
			//不满足二次探测定理，也就是y得1了但是x并不等于1或者n-1，那么n就一定不是质数。
			if (y == 1 && x != 1 && x != n - 1)
			{
				return false;
			}

			x = y;
		}
		//上面循环跑完了，如果最后x都不等于1，那么一定是一个合数了。
		if (x != 1)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ll n;
	
	while (cin >> n)
	{
		cout << Miller_Rabin(n) << endl;
	}
	
	
	return 0;
}
