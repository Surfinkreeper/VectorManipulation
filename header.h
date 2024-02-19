/************************************************************************
 * VectorManipulation
 * Project by Daniel Salameh
 * 
 * This project is made to practice Prefix Sum array calculations and decreasing 
 * time complexity of functions. There is lots of room to expand with different 
 * static functions in the IntVectorManipulation class.
 * 
*************************************************************************/

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class IntVectorManipulation {
    public:
        static void minSubArrayLen(const vector<int>& nums, int target);                  //Prints the smallest length subarray whose sum is equal to or greater than target
        static void numSubarrayBoundedMax(const vector<int>& nums, int left, int right);  //Prints the number of contiguous non-empty subarrays such that the value of the maximum   array element in that subarray is in the range [left, right]
        static void productExceptSelf(const vector<int>& nums);                           //Prints an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]
        static void printSum(const vector<int>& nums);
        static void printProduct(const vector<int>& nums);
    
    private:
        static vector<int> makePreSum(const vector<int>& myArr);       //Makes and returns Pre Sum Array
        static vector<int> makePreProduct(const vector<int>& myArr);   //Makes and returns Pre Product Array
        static vector<int> makeSufProduct(const vector<int>& myArr);   //Makes and returns Suf Product Array (preproduct but backwards)
        static int count(const vector<int>& myArr, int max);           //Counts number of subarrays that dont have a number higher than max
        static void print(const vector<int>& myArr);                   //Prints out the array

};
/*
class Solution {
public:
 vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
 vector<int> flights (n, 0);
 for( auto & x : bookings ) {
 flights[x[0]-1] += x[2]; // Adds the seats to the first flight in range
 if (x[1] < n) flights[x[1]] -= x[2]; // Subtracts the seats to the flight after the last flight in range
 }
 makePreSum(flights);
 return flights;

 }
 void makePreSum(vector<int>& myArr) {
 for(int i=1; i<myArr.size(); i++) {
 myArr[i] += myArr[i-1];
 }
 }
};

class Solution {
public:
 int sizeX, sizeY;
 int extractSum(int i, int j, const vector<vector<int> >& sum) {
 if (i < 0 || j < 0) return 0;
 if (i >= sizeX) i = sizeX - 1;
 if (j >= sizeY) j = sizeY - 1;
 return sum[i][j];
 }

 vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
 sizeX = mat.size();
 sizeY = mat[0].size();

 vector<vector<int>> sum(sizeX, vector<int>(sizeY, 0));
 // Calculate prefix matrix
 for (int i = 0; i < sizeX; i++) {
 for (int j = 0; j < sizeY; j++) {
 sum[i][j] = mat[i][j] + extractSum(i-1, j, sum) + extractSum(i, j-1, sum) - extractSum(i-1, j-1, sum);
 }
 }

 // Use prefix matrix to calculate our sum
 vector<vector<int>> ans(sizeX, vector<int>(sizeY, 0));
 for (int i = 0; i < sizeX; i++) {
 for (int j = 0; j < sizeY; j++) {
 ans[i][j] = extractSum(i+K, j+K, sum) - extractSum(i+K, j-K-1,sum) - extractSum (i-K-1, j+K, sum) + extract
                    -K-1, j-K-1, sum);
 }
 }

 return ans;
 }

 #include <limits.h>
class Solution {
public:
 int minSubArrayLen(int target, vector<int>& nums) {
 int n=nums.size();
 int ans=INT_MAX;
 int sum=0,k=0;
 for(int i=0; i<n; i++){
 sum+=nums[i];
 while(sum >= target){
 ans=min(ans,i-k+1);
 sum-=nums[k];
 k++;
 }
 }
 return (ans==INT_MAX) ? 0 : ans;
 }
};

class Solution {
public:
 int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
 return count(nums, right) - count(nums, left - 1);
 }
 int count(vector<int>& nums, int max) {
 int count = 0, answer = 0;
 for( int x : nums ) {
 if( x <= max )
 count++;
 else
 count = 0;
 answer += count;
 }
 return answer;
 }
};

class Solution {
public:
 vector<int> productExceptSelf(vector<int>& nums) {
 vector<int> preProduct = makePreProduct(nums);
 vector<int> sufProduct = makeSufProduct(nums);
 for( int i = 0; i < nums.size(); i++ ) {
 nums[i] = preProduct[i] * sufProduct[i];
 }
 return nums;
 }
 vector<int> makePreProduct(const vector<int>& nums) {
 int n = nums.size();
 vector<int> preProduct (n, 1);
 for( int i = 0; i < n-1; i++ ) {
 preProduct[i+1] = preProduct[i] * nums[i];
 }
 return preProduct;
 }
 vector<int> makeSufProduct(const vector<int>& nums) {
 int n = nums.size();
 vector<int> sufProduct (n, 1);
 for( int i = n-1; i > 0; i-- ) {
 sufProduct[i-1] = sufProduct[i] * nums[i];
 }
 return sufProduct;
 }
};

*/
#endif