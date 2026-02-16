#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//Binary Search
int BS(int* arr, int n, int item) {
    int beg = 0, end = n-1, mid = (beg+end)/2;
    while(beg<end && arr[mid]!=item) {
        if(item>arr[mid]) {
            beg = mid+1;
        } else {
            end = mid-1;
        }
        mid = (beg+end)/2;
    }

    return mid;
}

int upperBound(vector<int>& arr, int n, int item) {
    int beg = 0, end = n-1, mid = (beg+end)/2;
    int ub = -1;
    while(beg<end) {
        if(item>=arr[mid]) {
            beg = mid+1;
            if(item==arr[mid]) {
                ub = mid + 1;
            }
        } else {
            end = mid - 1;
        }
        mid = (beg+end)/2;
    }

    return ub;
}

int lowerBound(vector<int>& arr, int n, int item) {
    int beg = 0, end = n-1, mid = (beg+end)/2;
    int lb = -1;
    while(beg<end) {
        if(item>arr[mid]) {
            beg = mid + 1;
        } else {
            end = mid;
            if(arr[mid]==item) {
                lb = mid;
            }
        }
        mid = (beg+end)/2;
    }
    return lb;
}

int main() {
    int n=5;
    vector<int> arr1(n);
    arr1 = {7,4,1,2,3};
    vector<int> arr2(n);
    arr2 = {4,2,1,5,4};
    int target = 8;
    sort(arr2.begin(), arr2.end());
    int pair = 0;
    for(int i=0; i<n; i++) {
        int item = target - arr1[i];
        int ub = upperBound(arr2, n, item);
        int lb = lowerBound(arr2, n, item);
        if(ub==-1 || lb==-1) {
            continue;
        }
        pair += (ub-lb);
    }

    cout<<"Number of pair to give sum as "<<target<<" is: "<<pair<<endl;
}