// Problem: https://codeforces.com/problemset/problem/768/B
// Solution: https://codeforces.com/contest/768/submission/57302491


// Few things to note here:
// len(n) = 2len(n/2) + 1
// From induction we can prove: len(n) = 2^(floor(logn) + 1) - 1
// We can also prove that total number of ones in ultimate list will be equal to n
// As the rightmost bit appears only one time in the list
// Similarly second rightmost bit appears only 2 times.
// Example n = 7:
// Total ones = 1*2^0 + 1*2^1 + 1*2^2
// We can calculate total 1s from 1 to index i by recursion
// List is palindromic
// List(n) = [List(n/2) n&1 List(n/2)]

// Author : khalid007
 
#pragma GCC optimize("O3")
 
#include <bits/stdc++.h>
 
#define ln "\n"
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
 
ll len(ll n) 
{
   ll count = 0;
   
   while(n) {count++; n >>= 1;}
    
    return pow(2, count) - 1;
}
 
// Recurrence relation: T(n) = T(n/2) + O(1);
// So Time complexity: T(n) = O(logn) 
 
ll solve(ll n, ll indx) {
    
    // len1: length of list formed by n
    // len2: length of list formed by n//2
    ll len1, len2;
    len1 = len(n);
    len2 = len1>>1;
    
    // ----------------<Base_case>---------------
    if(!n || !indx) return 0;
    // As we have previously proved if for indx = length value returned should be n (Refer to line number 8 of this code)
    if(indx == len1) return n;
    // Refer to line 15 of this code:
    if(indx == len2 + 1) return (n>>1) + (n&1);
    //-----------------</Base_case>--------------
    
    // Else solve recursively.
    //-----------------<Divide&Conquer>-----------
    if(indx <= len2) return solve(n>>1, indx);
    return (n>>1) + (n&1) + solve(n>>1, indx - len2 - 1);
    //-----------------</Divide&Conquer>-----------
    
}
 
int main() {
    
    fio;
    ull n, l, r, ans = 0;
 
    cin >> n >> l >> r;
    
    cout << solve(n, r) - solve(n, l - 1) << ln;
    
    return 0;
}
