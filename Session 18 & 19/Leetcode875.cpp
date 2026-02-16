// class Solution
// {
// public:
//     long long eating(vector<int> &piles, int k)
//     {
//         long long tm = 0;
//         for (int i = 0; i < piles.size(); i++)
//         {
//             tm += (piles[i] + k - 1) / k;
//             if (k == 23)
//             {
//                 cout << tm << endl;
//             }
//         }
//         return tm;
//     }
//     int minEatingSpeed(vector<int> &piles, int h)
//     {
//         int mxBanana = *max_element(piles.begin(), piles.end());
//         int mn = mxBanana;
//         int beg = 1, end = mxBanana, mid = (beg + end) / 2;
//         while (beg <= end)
//         {
//             long long tm = eating(piles, mid);
//             if (h >= tm)
//             {
//                 end = mid - 1;
//                 mn = mid;
//             }
//             else
//             {
//                 beg = mid + 1;
//             }
//             mid = (beg + end) / 2;
//         }

//         return mn;
//     }
// };