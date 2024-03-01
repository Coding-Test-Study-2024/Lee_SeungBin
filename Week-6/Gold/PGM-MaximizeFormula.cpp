#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

long long calculate(long long num1, long long num2, char op)
{
    if (op == '+') return num1 + num2;
    else if (op == '-') return num1 - num2;
    else return num1 * num2;
}

long long solution(string expression)
{
    long long answer = 0;
    set<char> operset;
    vector<long long> nums;
    vector<char> ops;

    string num = "";
    // 1. 연산자와 숫자 분리해서 저장하기
    for (char c : expression)
    {
        if (isdigit(c)) // isdigit는 숫자와 문자 구분해주는 함수 문자면 0 반환 , 해당 경우는 문자가 아닌 경우
        {
            num += c; // 나온 숫자들을 문자열에 저장
        }
        else // 문자면
        {
            nums.push_back(stoll(num)); // 숫자 벡터에 저장해둔 문자열을 long long 타입으로 바꿔서 저장
            num = "";
            ops.push_back(c); // 연산자 벡터에 연산자 저장
            operset.insert(c); //  set에 연산자 저장
        }
    }
    nums.push_back(stoll(num)); // 마지막 숫자 저장

    vector<char> tempoper(operset.begin(), operset.end()); // 연산자 순열을 위한 연산자 벡터 생성
    // 2. 계산 순서 정하기
    do {
        vector<long long> tempnums = nums; // 숫자 벡터 복사
        vector<char> tempops = ops; // 연산자 벡터 복사

        for (char op : tempoper)
        {
            for (int i = 0; i < tempops.size();)
            {
                // 3. 계산하기
                if (tempops[i] == op) // 순서에 맞는 연산자이면 계속 계산
                {
                    tempnums[i] = calculate(tempnums[i], tempnums[i + 1], op); // 연산 수행
                    tempnums.erase(tempnums.begin() + i + 1); // 뒷 숫자 제거
                    tempops.erase(tempops.begin() + i); // 사용된 연산자 제거
                }
                else // 순서에 맞지 않으면 다음 요소 검색
                {
                    i++;
                }
            }
        }
        // 4. 결과 최댓값 구하기
        answer = max(answer, abs(tempnums.front()));

    } while (next_permutation(tempoper.begin(), tempoper.end()));

    return answer;
}
