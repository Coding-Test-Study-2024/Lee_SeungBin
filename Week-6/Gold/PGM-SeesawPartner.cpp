#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

long long solution(vector<int> weights)
{
    //long long answer = 0;

    //// 모든 조합에 대해서 탐색
    //for (int i = 0; i < weights.size(); i++)
    //{
    //    for (int j = i + 1; j < weights.size(); j++)
    //    {
    //        // 두 사람의 몸무게와 거리 비율 계산
    //        // 시소 축과 좌석 간의 거리 2, 3, 4
    //        vector<int> distance = { 2,3,4 };
    //        for (int v : distance)
    //        {
    //            if (weights[i] * v == weights[j] * v)
    //            {
    //                answer++;
    //                break;
    //            }

    //            for (int v2 : distance)
    //            {
    //                if (weights[i] * v == weights[j] * v2)
    //                {
    //                    answer++;
    //                    break;
    //                }
    //            }
    //        }
    //    }
    //}
    //return answer;

    // 시도 #1 시간 초과 발생

    //long long answer = 0;
    //unordered_map<int, int> counter;
    //// 나온 숫자들 전부 저장
    //for (int w : weights)
    //{
    //    counter[w]++;
    //}

    //for (auto it = counter.begin(); it != counter.end(); it++)
    //{
    //    int n = it->second;
    //    // 2번이상 나온 숫자 검색
    //    if (n >= 2)
    //    {
    //        // 2번이상 나온 숫자의 가짓수는 나온 횟수 * (나온 횟수 - 1) / 2 임 >> nC2
    //        answer += n * (n - 1) / 2;
    //    }
    //}

    //// weights를 전부 순회하면서 2:3 2:4 3:4 비율을 만들고 
    //for (int w : weights)
    //{
    //    // weights안에 있는 무게 w에 대해 비율이 2:3 2:4 3:4인 무게를 찾는다.
    //    // 찾으면 두 무게를 가지고 있는 사람 수를 곱하여 더함
    //    if (counter.find(w * 2 / 3) != counter.end())
    //    {
    //        answer += counter[w * 2 / 3] * counter[w];
    //    }
    //    if (counter.find(w * 2 / 4) != counter.end())
    //    {
    //        answer += counter[w * 2 / 4] * counter[w];
    //    }
    //    if (counter.find(w * 3 / 4) != counter.end())
    //    {
    //        answer += counter[w * 3 / 4] * counter[w];
    //    }
    //}
    //return answer;
    
    // 시도 #2 실패 처리

    long long answer = 0;
    // weights를 먼저 정렬하기 (정렬된 배열을 사용하면 순차적으로 비교할 때 시간 복잡도 감소)
    sort(weights.begin(), weights.end());

    // 완전 탐색을 통해 4:2, 4:3, 3:2, 1:1인 경우의 수 찾기
    for (int i = 0; i < weights.size(); i++)
    {
        for (int j = i + 1; j < weights.size(); j++)
        {
            if (weights[i] * 4 == weights[j] * 2 ||
                weights[i] * 4 == weights[j] * 3 ||
                weights[i] * 3 == weights[j] * 2 ||
                weights[i] == weights[j])
            {
                answer++;
            }
        }
    }

    return answer;

  // 시도 #3 성공 (제일 많이 걸린 시간 4초)
}
