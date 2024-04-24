#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s)
{
    string answer = "";

    bool flag = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ') // 공백나오면 초기화
        {
            answer += ' ';
            flag = 0;
        }
        else if(!flag) // 맨 앞이면 대문자로 변환 (숫자면 상관없음)
        {
            answer += toupper(s[i]);
            flag = 1;
        }
        else // 아니면 소문자로 변환
        {
            answer += tolower(s[i]);
        }
    }

    return answer;
}
