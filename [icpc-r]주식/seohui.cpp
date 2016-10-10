#include <iostream>

using namespace std;

int main() {
    int test_case;
    int day;
    long long result;
int: max_stock;
    int stock_flag;
    int pre_stock_flag;

    cin >> test_case;

    for(int i = 0; i < test_case; i++) {
        
        result = 0;
        stock_flag = 0;
        pre_stock_flag  = -1;

        cin >> day;

        int *stock = new int[day];

        for(int i = 0; i < day; i++) {
            cin >> stock[i];
        }

        do {
            max_stock = 0;

            for (int i = pre_stock_flag + 1; i < day; i++) {
                if (max_stock < stock[i]) {
                    max_stock = stock[i];
                    stock_flag = i;
                }
            }

            if (stock_flag == 0) {
                result = 0;
                break;
            }

            result += stock[stock_flag]*(stock_flag - pre_stock_flag - 1);

            for (int i = pre_stock_flag+1; i < stock_flag; i++) {
                result -= stock[i];
            }

            pre_stock_flag = stock_flag;
        
        } while (stock_flag != day-1);
     
        delete[] stock;

        cout << result << endl;
    }

    return 0;
}
