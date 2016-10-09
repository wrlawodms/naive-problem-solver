#include <iostream>
 
using namespace std;
 
int main()
{
    int T, N;
    int *input_stocks;
 
    cin >> T;
    while (T--)
    {
        cin >> N;
        input_stocks = new int[N];
 
        for (int i = 0; i < N; i++)
        {
            cin >> input_stocks[i];
        }
        int max = input_stocks[N - 1];
         
        long long int result = 0;
 
        for (int i = N - 2; i >= 0; i--)
        {
            if (max < input_stocks[i])
                max = input_stocks[i];
            else
                result += max - input_stocks[i];
        }
 
        cout << result << endl;
 
        delete[] input_stocks;
    }
}
