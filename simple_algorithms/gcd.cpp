#include <iostream>

int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    a%=b;
    return gcd(b,a);
}
int main()
{
    int a;
    int b;
    std::cin >> a;
    std::cin >> b;
    int greatest_common_divisor = gcd(a,b);
    std::cout<< greatest_common_divisor <<'\n';
}