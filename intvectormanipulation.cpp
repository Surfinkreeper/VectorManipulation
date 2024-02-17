#include "header.h"

static void IntVectorManipulation::minSubArrayLen(const vector<int>& nums, int target) {

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
    cout << (ans==INT_MAX) ? 0 : ans << endl << endl;
}

static void IntVectorManipulation::numSubarrayBoundedMax(const vector<int>& nums, int left, int right) {
    cout << count(nums, right) - count(nums, left - 1) << endl << endl;
    //cout << # subarrays with right as max - # subarrays with left-1 as mx
}

static void IntVectorManipulation::productExceptSelf(vector<int>& nums) {
    vector<int> preProduct = makePreProduct(nums);
    vector<int> sufProduct = makeSufProduct(nums);
    vector<int> ans(nums);
    for( int i = 0; i < ans.size(); i++ ) {
        ans[i] = preProduct[i] * sufProduct[i];
    }
    print(ans);
}

vector<int> makePreSum(const vector<int>& myArr) {
    vector<int> preSum(myArr.size()+1, 0);
    for(int i=0; i<myArr.size(); i++) {
        preSum[i+1] = preSum[i] + myArr[i];
    }
    return preSum;
}

int IntVectorManipulation::count(const vector<int>& myArr, int max) {
    nt count = 0, answer = 0;
    for( int x : myArr ) {
        if( x <= max )
            count++;
    else
        count = 0;
        answer += count;
    }
    return answer;
}

void IntVectorManipulation::print(const vector<int>& myArr) {
    cout <<  "[";
    for( int x : myArr ) {
        cout << x << "\t";
    }
    cout << "]\n\n";
}