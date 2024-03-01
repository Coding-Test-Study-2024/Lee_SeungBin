#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, result;
int a[54], b[54];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    // 단순히 a는 오름차순, b는 내림차순으로 풀 수 있으나
    // 문제에서 b는 재배열하지 말라는 것을 지켜보기
    // 1. a를 먼저 오름차순 정렬
    sort(a, a + n);
    int maxindex = 0;
    int bsize = sizeof(b) / sizeof(b[0]);
    for (int i = 0; i < n; i++)
    {
        // 2. b의 가장 큰 수의 인덱스를 구해서
        maxindex = max_element(b, b + bsize) - b;
        // 3. 식에 대입하기
        result += (a[i] * b[maxindex]);
        // 4. 사용한 b의 가장 큰수는 초기화
        b[maxindex] = 0;
    }

    cout << result;
    return 0;
}
