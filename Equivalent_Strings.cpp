// Author : khalid007

// Question: https://codeforces.com/problemset/problem/559/B
// Solution: https://codeforces.com/contest/559/submission/57198780

#include <bits/stdc++.h>

#define ln "\n"
#define len(v) (v).size()
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

 
// This will return Lexicographically minimum string(Sorted by smallest units) of the provided string
// Size of smallest unit is largest odd number that devide the length of the string
string smallest(string a) {
 
    // Check is length of a is odd
    if(len(a) & 1) return a; 
    // Else call smallest recurssively for two half of the string
    
    else{
        
        ll sub_size = len(a)/2;
        
        // Call smallest recussively
        string a1 = smallest(a.substr(0, sub_size));  
        string a2 = smallest(a.substr(sub_size, sub_size));
        
        //Lexicographically concatenate the two lexicographically smallest substrings
        if(a1 < a2) return (a1 + a2);
        else return (a2 + a1);
    }
}
 
int main() {
    
    fio;
    
    string a, b;
    cin >> a; cin >> b;
    
    
    // Two strings will be said to be equal if each smallest unit of a and b are same
    // So, We are just gonna check if the two lexicographically smallest strings (of a and b) are equalt are not
    
    if(smallest(a) == smallest(b)) cout << "YES" << ln;
    else cout << "NO" << ln;
 
    return 0;
}
 
