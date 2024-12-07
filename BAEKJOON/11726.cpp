/*
    24.11.07.
    2xn 타일링
    11726

    다이나믹 프로그래밍(동적계획법) 은
    문제를 작은 문제들의 합으로 보고
    작은 문제들의 해법을 저장해놨다가 중복을 방지하며 사용한다.
    작은 문제들 부터 해답을 써가며 이것을 상위 문제에서 어떻게 활용할지 생각하기
*/
#include <iostream>

using namespace std;

int main()
{
    long long a[1001]; // 숫자가 커지기에 일단 long long

    int N;
    cin >> N;
    a[1]=1, a[2]=2;

    for (int i=3; i <= N; i++)
    {
        a[i] = a[i-1] + a[i-2]; 
        // 2xN 타일을 채울 떄 N-1과 N-2에서
        // N-1에서 맨 끝에 1x2를 채운다 생각
        // N-2에서 맨 끝에 2x1 두 개를 가로로 채운다 생각
        // 2x1 두 개를 세로로 채우면 N-1에서 겹치는 경우가 생김
        if (a[i] > 10006)
            a[i] %= 10007;
    }

    cout << a[N]%10007;
    
    return 0;
}