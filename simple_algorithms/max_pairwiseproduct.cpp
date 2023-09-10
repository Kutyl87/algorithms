#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using std::vector;
using std::cin;
using std::cout;
using std::max;
#include <ctime>

long long MaxPairWiseProduct(std::vector<int> nums)
{
    int n = nums.size();
    int max_index = -1;
    for(int i =0; i<n;i++)
    {
        if ((max_index == -1) || (nums[i] > nums[max_index]))
        {
            max_index = i;
        }
    }
    int max_index2 = -1;
    for(int i =0; i<n;i++)
    {
        if ((i != max_index) && ((max_index2 == -1) || (nums[i] > nums[max_index2])))
        {
            max_index2 = i;
        }
    }
    return ((long long)(nums[max_index2]) * nums[max_index]);
}

long long MaxPairWiseProductWhile(std::vector<int> nums)
{
    int n = nums.size();
    int i = 0;
    int j = nums.size() -1;
    long long result = 0;
    while(i!=j)
    {
                long long curr_result = nums[i] * nums[j];
        if(nums[i]>nums[j])
        {
            j--;
        }
        else{
            i++;
        }
        result = max<long long>(curr_result, result);
    }
    return result;
}

void measureTime(long long (*func)(vector<int>), vector<int> numbers)
{
    clock_t start = clock();
    long long result = func(numbers);
    clock_t end = clock();
    double duration1 = (double)(end - start) / CLOCKS_PER_SEC;
    cout <<"Time elapsed : "<<duration1 <<"\n";
    cout <<result<<"\n";
}
int main(){
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i=0;i<n; i++)
    {
        cin >> numbers[i];
    }
    measureTime(MaxPairWiseProduct, numbers);
    measureTime(MaxPairWiseProductWhile, numbers);
    return 0;
}