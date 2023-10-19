#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> result;
    for (size_t i = 0; i < nums.size()-1; i++)
        for(int j = i+1; j < nums.size(); j++)
            if(nums[i]+nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                }
    return result;
}


int main()
{   
   vector<int> nums={2,5,5,11};
   int target=10;
   vector<int>result=twoSum(nums,target);
   for(int i=0;i<result.size();i++)
    cout << result[i] <<"   ";
}