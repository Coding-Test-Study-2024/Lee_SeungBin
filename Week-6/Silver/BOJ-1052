#include <iostream>
#include <algorithm>

using namespace std;

int n, k, cnt, result;

int main()
{
    cin >> n >> k;

    // n은 주어진 물병의 개수, cnt는 들고가는 물병, result은 상점에서 구매한 물병의 수
    // 1. 주어진 물병을 최대한 합침 (n을 2로 나누기)
    // 2. 나머지가 발생하면 합쳐지지 않은 물병 존재, cnt++
    // 3. n이 0이 될때까지 1~2반복
    // 4. cnt의 개수가 k 이하일 때 result 출력, 아니면 1~3번 반복
    for (result = 0; ; result++) // 
    {
        int temp = n + result; // 상점에서 산 물병 개수 + 주어진 물병의 개수
        cnt = 0;

        while (temp) // temp != 0
        {
            if (temp % 2 == 1)
            {
                cnt++;
            }
            temp /= 2;
        }

        if (cnt <= k)   break;
    }
    cout << result;
    return 0;
}
