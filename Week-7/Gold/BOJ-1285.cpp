#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, a[44], result = 99999999;
string s;
// 비트 마스킹 방식 풀이
// H를 0으로 T를 1로 보고 뒤집었을때 앞의 자리수는 생각하지 말기

void flip(int here)
{
	if (here == n + 1)
	{
		int sum = 0;
		for (int i = 1; i <= (1 << (n - 1)); i *= 2) // 모든 비트 키기
		{
			int cnt = 0;
			for (int j = 1; j <= n; j++)
			{
				if (a[j] & i)	cnt++;
			}
			sum += min(cnt, n - cnt);
		}
		result = min(result, sum);
		return;
	}
	flip(here + 1);
	a[here] = ~a[here]; // 비트 뒤집기
	flip(here + 1);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		int value = 1;
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == 'T')
			{
				a[i] |= value; // T일때 비트 키기
			}
			value *= 2;
		}
	}
	flip(1);
	cout << result;
    return 0;
}
