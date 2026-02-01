#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxStableWindow(vector<char> &attend, int n) {
    unordered_map<int, int> mp;
    int sum = 0;
    int mxLen = 0;

    mp[0] = -1;

    for(int i=0; i<n; i++) {
        if(tolower(attend[i]) == 'p') {
            sum++;
        } else {
            sum--;
        }

        if(mp.find(sum) != mp.end()) {
            mxLen = max(mxLen, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }

    return mxLen;
}

int main() {
    int n;
    cin>>n;
    vector<char> attend(n);

    for(int i=0; i<n; i++) {
        cin>>attend[i];
    }

    int mxLen = maxStableWindow(attend, n);
    cout<<mxLen<<endl;
    return 0;
}