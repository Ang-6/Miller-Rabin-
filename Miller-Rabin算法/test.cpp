#include "pch.h"
#include <iostream>
#include <cstdlib> 

using namespace std;

typedef long long ll;

ll qul_mul(ll a, ll b, ll n)  //���ٻ����㣬�������a^m^*a^m^�����ܷ�ֹ����
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

ll qul_pow(ll a, ll b, ll n) //�����ݼ���������a^m^��ֵ
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

	//���n-1 = m*2^t��m��t��
	while (!(m & 1))
	{
		m >>= 1;
		t++;
	}

	for (int i = 0; i < 20; i++)
	{
		//�����a
		ll a = rand() % (n - 1) + 1;
		// ����a^m
		ll x = qul_pow(a, m, n), y;

		for (int j = 0; j < t; j++)
		{
			y = qul_mul(x, x, n);  //����(x*x)%n������

			//���������̽�ⶨ��Ҳ����y��1�˵���x��������1����n-1����ôn��һ������������
			if (y == 1 && x != 1 && x != n - 1)
			{
				return false;
			}

			x = y;
		}
		//����ѭ�������ˣ�������x��������1����ôһ����һ�������ˡ�
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
