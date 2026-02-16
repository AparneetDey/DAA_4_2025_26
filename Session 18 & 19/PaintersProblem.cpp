// class Solution {
//     public:
//       bool canPaint(vector<int> arr, int k, int tm) {
//           int painters = 1;
//           int currTm = 0;
          
//           for(int i=0; i<arr.size(); i++) {
//               if(arr[i] + currTm <= tm) {
//                   currTm += arr[i];
//               } else {
//                   painters++;
//                   currTm = arr[i];
//               }
//           }
          
//           return painters <= k;
//       }
//       int minTime(vector<int>& arr, int k) {
//           // code here
//           int low = *max_element(arr.begin(), arr.end());
//           int high = accumulate(arr.begin(), arr.end(), 0);
//           int ans = 0;
          
//           while(low<=high) {
//               int mid = (low + high)/2;
//               if(canPaint(arr, k, mid)) {
//                   ans = mid;
//                   high = mid - 1;
//               } else {
//                   low = mid + 1;
//               }
//           }
          
//           return ans;
//       }
//   };