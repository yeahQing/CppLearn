#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, V;
    int maxW = 0;
    cin>>n>>V;
    vector<int> dp(V+1, 0);
    int vi, wi;
    for (int i=0;i<n;i++) {
        cin>>vi>>wi;
        if(vi<=V) {
            dp[vi] = max(dp[vi], wi);
        }
    }
 
    for(int i=0;i<=V;i++) {
        for(int j=1;j<=i/2;j++) {
            if(dp[j]&&dp[i-j]) {
                dp[i] = max(dp[i], dp[j]+dp[i-j]);
            }  
        }
        maxW = max(maxW, dp[i]);
    }
    cout<<maxW<<endl;
    cout<<dp[V]<<endl;
    return 0;
}