#include <iostream>
#include <vector>
#include <algorithm>
int fibonacci(int n)
{
    std::vector<int> fibo(2);
    if(n<=1)
    {
        return n;
    }
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 1;i<n;i++)
    {   
        int fibo_first = fibo[0];
        fibo[0] = fibo[1];
        fibo[1] = (fibo[0] + fibo_first)%10;
        
    }
    return fibo[1];
}

int main(){
    int n;
    std::cin >> n;
    int fb = fibonacci(n);
    std::cout << fb <<"\n"; 
    return 0;
}