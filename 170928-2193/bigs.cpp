#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  
  unsigned long* s = new unsigned long[N];

  s[0] = 1;
  s[1] = 2;

  unsigned long p = 1;
  for(int i=2; i<N; i++) {
    p = s[i-2] + 1;
    s[i] = s[i-1] + p;
//    cout << s[i] <<endl;
//    cout << p << endl;
  }
  printf("%lu", p);
  delete [] s;
  return 0;
}
