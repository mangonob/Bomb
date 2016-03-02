//
//  main.cpp
//  Bomb
//
//  Created by Trinity on 16/3/2.
//  Copyright © 2016年 Trinity. All rights reserved.
//

#include <stdio.h>
#include <string.h>
typedef unsigned long long ull;
ull dp[25][3];

void genDp(){
    dp[0][0] = 1;
    for (int i = 1; i <= 22; i++) {
        dp[i][0] = dp[i-1][0]*10 - dp[i-1][1];
        dp[i][1] = dp[i-1][0];
        dp[i][2] = dp[i-1][2]*10 + dp[i-1][1];
    }
}


ull solve(ull n) {
    ull result = 0;
    int a[25], len = 0;
    while (n) {
        a[++len] = n % 10;
        n/=10;
    }
    a[len + 1] = 0;
    
    bool flag = false;
    for (int i = len; i >= 1; i--) {
        int curr = a[i];
        int prev = a[i + 1];
        if(flag) { result += curr * (dp[i - 1][0] + dp[i - 1][2]); }
        else {
            result += curr * dp[i - 1][2];
            if (curr > 4) result += dp[i - 1][1];
            if (curr == 9 && prev == 4) {
                result++;
                flag = true;
            }
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    genDp();
    int n;
    ull v;
    scanf("%d", &n);
    for(;n--;) {
        scanf("%llu", &v);
        ull value = solve(v);
        printf("%llu\n", value);
    }
    return 0;
}