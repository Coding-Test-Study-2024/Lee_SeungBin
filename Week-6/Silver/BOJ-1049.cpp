#include <iostream>
#include <algorithm>

using namespace std;

int n, m, package, single, result;
int min_package = 1000, min_single = 1000;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> package >> single;
        // 패키지와 단품 가격중 제일 낮은 가격 저장
        min_package = min(min_package, package);
        min_single = min(min_single, single);
    }

    int case_1, case_2, case_3;

    case_1 = n * min_single; // 단품만 골랐을 경우 case_1
    case_2 = (n / 6) * min_package; // 패키지만 골랐을 경우 case_2
    if (n % 6 != 0) case_2 += min_package; // 나머지가 있는경우 패키지 한 번 더사기
    case_3 = (n / 6) * min_package + (n % 6) * min_single; // 단품 + 패키지를 골랐을 경우 case_3

    result = min(case_1, min(case_2, case_3));

    cout << result;

    return 0;
}
