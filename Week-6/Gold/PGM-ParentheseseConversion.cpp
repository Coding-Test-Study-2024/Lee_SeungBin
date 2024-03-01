#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

// "올바론 괄호 문자열 "판별
bool isRightStr(string s)
{
    stack<char> stk;

    for (int i = 0; i < s.length(); i++)
    {
        // 문자열을 순회하면서 '(' 를 찾으면 스택에 넣고 다른 문자 ')' 을 만나면 pop함
        if (s[i] == '(')
        {
            stk.push(s[i]);
        }
        else if(stk.size()) // 해당 부분은 스택이 비어있을 때 pop하면 런타임 에러 발생
        {
            stk.pop();
        }
    }

    // 마지막에 스택이 비어있지 않으면 "올바른 괄호 문자열"이 아님
    if (stk.size())
    {
        return false;
    }

    return true;
}

string solution(string p)
{
    string answer;

    // 1. 입력이 빈 문자열인 경우, 빈 문자열 반환
    if (!p.size()) return "";

    //2. 문자열 w를 두 "군형잡힌 괄호 문자열" u, v로 분리
    //단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있음
    string u, v;
    int left = 0, right = 0;
    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] == '(')
        {
            left++;
        }
        else
        {
            right++;
        }

        // "균형잡힌 괄호 문자열"을 찾으면 바로 분리
        // u = 처음 ~ 찾은 부분까지, v = 찾은 부분 ~ 끝까지
        if (left == right)
        {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }

    //3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계 부터 다시 수행
    if (isRightStr(u))
    {
        v = solution(v);
        // 3-1. 수행한 결과를 u에 이어 붙인후 반환
        answer = u + v;
        return answer;
    }
    //4. 문자열 u가 "올바른 괄호 문자열"이 아니라면
    else
    {
        // 4-1. 빈 문자열에 첫 번째 문자로 '(' 붙임
        string temp;
        temp += '(';
        // 4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙임
        temp += solution(v);
        // 4-3. ')'을 다시 붙임
        temp += ')';
        // 4-4. u의 첫 번째와 마지막 문자 제거, 나머지 문자열의 괄호 방향을 뒤집에서 뒤에 붙임
        u.erase(0, 1);
        u.erase(u.length() - 1, 1);
        for (int i = 0; i < u.length(); i++)
        {
            if (u[i] == '(')
            {
                temp += ')';
            }
            else
            {
                temp += '(';
            }
        }
        // 4-5. 생성된 문자열 반환
        return temp;
    }
}
