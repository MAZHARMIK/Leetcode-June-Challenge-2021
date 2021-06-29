/*
    Company Tags  : Amazon, Oracle, VMWare
    Leetcode Link : https://leetcode.com/problems/armstrong-number/
    Since this is a Premium Qn, I have provided the descrition below.
*/

/*
The k-digit number N is an Armstrong number if and only if the k-th power of each digit sums to N.
Given a positive integer N, return true if and only if it is an Armstrong number.
 Example 1:
 Input: 153
 Output: true
 Explanation:
 153 is a 3-digit number, and 153 = 1^3 + 5^3 + 3^3.

 Example 2:
 Input: 123
 Output: false
 Explanation:
 123 is a 3-digit number, and 123 != 1^3 + 2^3 + 3^3 = 36.

 Note:
 1 <= N <= 10^8
*/

class Solution {
  public:
    int getLength(int n) {
        int count = 0;
        while(n) {
            n = n/10;
            count++;
        }
        return count;
    }
    string armstrongNumber(int n){
        int temp = n;
        int length = getLength(n);
        int sum = 0;
        
        while(n) {
            int remain = n%10;
            sum += pow(remain, length);
            n /= 10;
        }
        return sum == temp;
    }
};
