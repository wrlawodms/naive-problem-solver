#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int get_dividers(int num, vector<int>& ds){
    int m = sqrt(num);
    int i;
    for(i=2; i<=m; i++){
        if ( num%i == 0){
            ds.push_back(i);
            if( i != num/i)
                ds.push_back(num/i);
        }
    }
    ds.push_back(num);
    sort(ds.begin(), ds.end());
    return ds.size();
}

int main(){
    int cnt;
    int i,j;
    int nums[100];
    int min = 1000000001;
    int max = 0;
    int b;
    int r;
    int m;
    vector<int> ds;

    scanf("%d",&cnt);
    for(i=0; i<cnt; i++){
        scanf("%d", &nums[i]);
        if(min > nums[i])
            min = nums[i];
        if(max < nums[i])
            max = nums[i];
    }
    
    get_dividers(max-min, ds);
    vector<int>::iterator it = ds.begin();
    for(;it != ds.end(); it++){
        b = 0;
        r = nums[0]%(*it);
        for(j=1; j<cnt; j++){
            if(nums[j]%(*it) != r){
                b = 1;
                break;
            }
        } 
        if(!b)
            printf("%d ", *it);  
    }
    
    return 0;
}
