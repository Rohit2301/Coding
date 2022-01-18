#include<iostream>
#include<vector>
#include <numeric>
using namespace std;


int main()
{
    vector<int> nums(6);
    for (int i = 0; i < nums.size(); i++)
    {
        cin>>nums[i];
    }
    int n =nums.size();
    int ind = -1;
    int left = 0;
    
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int right=sum - nums[0];
    cout<<"\nsum "<<sum;

    for (int i = 0; i < n; i++)
    {
        if (left == right)
        {
            ind = i;
        }
        right = right - nums[i+1];
        left = left+ nums[i];
        
    }
    cout<<" index : "<<ind;





    return 0;
}