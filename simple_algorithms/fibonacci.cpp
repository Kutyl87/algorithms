#include <iostream>
#include <vector>

int slow_fibonacci(int n)
{

    if(n<=1)
    {
        return n;
    }
    else
    {
        return slow_fibonacci(n-1) + slow_fibonacci(n-2);
    }
}
int faster_fibonacci(int n)
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
        fibo[1] = fibo[0] + fibo_first;
        
    }
    return fibo[1];
}

std::vector<int> return_fibonacci_sequence(int n)
{
    std::vector<int> fibonacci_sequence(n+1);
    for(int i; i<n+1;i++)
    {
        fibonacci_sequence[i] = slow_fibonacci(i);
    }
    return fibonacci_sequence;
}

void cout_fibonacci_sequence(std::vector<int> fibo_seq)
{
    std::cout<<"Whole fibonacci sequence" << " : ";
    for(int elem: fibo_seq)
    {
            std::cout << std::to_string(elem) << " ";
    }
}

int main()
{
    int n;
    std::cin >> n;
    int fibo= slow_fibonacci(n);
    std::vector<int> fibo_seq = return_fibonacci_sequence(n);
    std::cout << "The " + std::to_string(n) + "th " "element of fibonnaci sequence is "<<std::to_string(fibo) <<"\n";
    int fibo_faster= faster_fibonacci(n);
    std::cout << "The " + std::to_string(n) + "th " "element of fibonnaci sequence is "<<std::to_string(fibo_faster) <<"\n";
    cout_fibonacci_sequence(fibo_seq);
}