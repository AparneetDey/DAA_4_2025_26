// UID : 24BCS10972

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int counter = 0;
int depth = 0;
int i = 0;

void complexRec(int n) {
   if (n <= 2) {
       return;
   }

    if (i==0) {
        depth++;
    }
    i++;
    if (i==3) {
        i = 0;
    }

   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
           counter++;
       }
       p >>= 1;
       counter++;
   }


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
       counter++;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
       counter++;
   } else {
       reverse(small.begin(), small.end());
       counter++;
   }


   complexRec(n / 2);
   complexRec(n / 2);
   complexRec(n / 2);
}

int main() {
    auto start = high_resolution_clock::now();
    complexRec(4);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout<<counter<<endl;
    cout<<depth<<endl;
    cout<<duration.count();
}

// Recursive Function : T(n) = 3T(n/2) + nlogn
// Master Theorem Complexity: T(n) = O(n^log(base 2)3)