/*
 *
 * @file     1014.cpp
 * @author   errcodex
 * @brief
 * 6 cases passed on 9/3/2020 with 4ms max time use
 * and 512KB max space use.
 *
 */
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int min(const int m, const int n);

int main(int argc, char* argv[])
{
    string input[4];
    vector<pair<int, char>> arr[2];

    for (int i = 0; i < 4; i++)
        getline(cin, input[i]);

    for (int i = 0; i < 4; i += 2)
    {
        int length = min(input[i].length(), input[i + 1].length());
        for (int idx = 0; idx < length; idx++)
        {
            if (input[i][idx] == input[i + 1][idx])
                arr[i / 2].push_back(pair<int, char>(idx, input[i][idx]));
        }
    }
    int last           = 0;
    const char* day[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    for (auto i : arr[0])
    {
        if (i.second >= 'A' && i.second <= 'G')  // err: <=G �δ���
        {
            cout << day[i.second - 'A'] << " ";
            last = i.first;
            break;
        }
    }

    for (auto i : arr[0])
    {
        if (i.first <= last)
            continue;
        if ((i.second >= 'A' && i.second <= 'N') || ((i.second >= '0' && i.second <= '9')))
        {
            if (i.second >= 'A')
            {
                cout << setw(2) << setfill('0') << i.second - 'A' + 1 + 9;
            }
            else
            {
                cout << setw(2) << setfill('0') << i.second;
            }
            break;
        }
    }

    for (auto i : arr[1])
    {
        if ((i.second >= 'a' && i.second <= 'z') || (i.second >= 'A' && i.second <= 'Z'))
        {
            cout << ":" << setw(2) << i.first;
            break;
        }
    }
    return 0;
}

int min(const int m, const int n)
{
    return m > n ? n : m;
}