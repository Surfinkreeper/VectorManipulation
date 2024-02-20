#include "header.h"

//PUBLIC:
void IntVectorManipulation::minSubArrayLen(const vector<int>& nums, int target) {

    int n=nums.size();
    int ans=INT_MAX;
    int sum=0,k=0;

    for(int i=0; i<n; i++){
        sum+=nums[i];
        while(sum >= target){
            //If new range is smaller, it will replace answer
            ans=min(ans,i-k+1);
            //Moves beginning of subarray froward
            sum-=nums[k];
            k++;
        }
    }
    ans = (ans ==INT_MAX) ? 0 : ans;
    cout << "Minimum subarray length: " << ans << endl << endl;
}

void IntVectorManipulation::numSubarrayBoundedMax(const vector<int>& nums, int left, int right) {
    cout << "Number of subarrays: " << count(nums, right) - count(nums, left - 1) << endl << endl;
    //cout << # subarrays with right as max - # subarrays with left-1 as mx
}

void IntVectorManipulation::productExceptSelf(const vector<int>& nums) {
    vector<int> preProduct = makePreProduct(nums);
    vector<int> sufProduct = makeSufProduct(nums);
    vector<int> ans(nums);
    int n = ans.size();
    for( int i = 0; i < n; i++ ) {
        ans[i] = preProduct[i] * sufProduct[i];
    }
    cout << "Result: ";
    print(ans);
    cout << endl << endl;
}

void IntVectorManipulation::printSum(const vector<int>& nums) {
    vector<int> preSum = makePreSum(nums);
    cout << "Sum: " << preSum[nums.size()] << endl << endl;
}

void IntVectorManipulation::printProduct(const vector<int>& nums) {
    vector<int> preProduct = makePreProduct(nums);
    cout << "Product: " << preProduct[nums.size()] << endl << endl;
}

void IntVectorManipulation::print(const vector<int>& myArr) {
    cout <<  "[\t";
    for( int x : myArr ) {
        cout << x << "\t";
    }
    cout << "]";
}

//PRIVATE:
vector<int> IntVectorManipulation::makePreSum(const vector<int>& myArr) {
    int n = myArr.size();
    vector<int> preSum(n+1, 0);
    for( int i=0; i<n; i++ ) {
        preSum[i+1] = preSum[i] + myArr[i];
    }
    return preSum;
}

vector<int> IntVectorManipulation::makePreProduct(const vector<int>& myArr) {
    int n = myArr.size();
    vector<int> preProduct(n+1, 1);
    for( int i=0; i<n; i++ ) {
        preProduct[i+1] = preProduct[i] * myArr[i];
    }
    return preProduct;
}

vector<int> IntVectorManipulation::makeSufProduct(const vector<int>& myArr) {
    int n = myArr.size();
    vector<int> sufProduct(n+1, 1);
    for( int i=n-1; i>0; i-- ) {
        sufProduct[i-1] = sufProduct[i] * myArr[i];
    }
    return sufProduct;
}

int IntVectorManipulation::count(const vector<int>& myArr, int max) {
    int count = 0, answer = 0;
    for( int x : myArr ) {
        if( x <= max )
            count++;
        else
            count = 0;
        answer += count;
    }
    return answer;
}