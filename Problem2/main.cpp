//#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <regex>
#include<map>
#include <cstdio>
#include<utility>
#include<stack>
#include <queue>

using namespace std;

int main(){
    int rows,colo;
    cout<<"Enter no. rows : ";
    cin>>rows;
    cout<<"Enter no. Colones : ";
    cin>> colo;
    vector<vector<char>> seats = vector<vector<char>>(rows,vector<char>(colo,0));
    for (int i = 0; i < rows; ++i) {

        for (int j = 0; j < colo; ++j) {
            cin>>seats[i][j];
        }
    }


    const int N = seats.size();
    const int M = seats[0].size();


    vector<int> avail_seats(N+1);

    // for each row, find the avail seats
    for(int i = 1; i <= N; i++)
        for(int j = 0; j < M; j++)
            if(seats[i-1][j] == '.')
                avail_seats[i] = avail_seats[i] | (1 << j);


    vector<vector<int>> dp(N+1, vector<int>(1 << M, -1));


    for(int mask = 0; mask < (1 << M); mask++)
        dp[0][mask] = 0;

    for(int i = 1; i <= N; i++) {
        for (int mask = 0; mask < (1 << M); mask++) {

            if ((mask & avail_seats[i]) != mask)
                continue;

            if ((mask & (mask << 1)) || (mask & (mask >> 1)))
                continue;

            for (int prev_mask = 0; prev_mask < (1 << M); prev_mask++) {

                if (dp[i - 1][prev_mask] == -1)
                    continue;

                if ((mask & (prev_mask << 1)) || (mask & (prev_mask >> 1)))
                    continue;
                dp[i][mask] = max(dp[i][mask],
                                  dp[i - 1][prev_mask] + __builtin_popcount(mask));
            }
        }
    }
    int a = *max_element(dp[N].begin(), dp[N].end());
    cout<<a<<"\n";
    return 0;

}