#include<iostream>
#include<string>
#include<algorithm>

#define endl "\n"
using namespace std;

string Inp, Answer;
int Len;

void Input()
{
    cin >> Inp;
    Len = Inp.length();
}

void Divide(string S, int First, int Second)
{
    string A, B, C;
    A = B = C = "";

    for (int i = 0; i <= First; i++)
        A = A + S[i];
    for (int i = First + 1; i <= Second; i++)
        B = B + S[i];
    for (int i = Second + 1; i < Len; i++)
        C = C + S[i];

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    reverse(C.begin(), C.end());

    string Temp_Answer = A + B + C;

    if (Answer == "") Answer = Temp_Answer;
    else
    {
        if (Answer > Temp_Answer) Answer = Temp_Answer;
    }
}

void Solution()
{
    //i j를 돌리는데, 0~i번까지 i + 1번부터 j번까지, j + 1 ~ Len번까지
    for (int i = 0; i < Len-2; i++)
    {
        for (int j = i+1; j < Len-1; j++)
        {
            string Temp = Inp;
            Divide(Temp, i, j);
        }
    }
    cout << Answer << endl;
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}


