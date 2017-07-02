#include<iostream>
#include<queue>

using namespace std;

int main()
{
    int space[100001] = {0,};    
    int src, dest;
    queue<pair<int, int> > q;

    scanf("%d %d", &src, &dest);
    if(src == dest){
        cout<<0<<endl;
        return 0;
    }
    q.push(pair<int,int>(src, 0));
    while(!q.empty()){
        pair<int,int> pos_dist = q.front();
        int pos = pos_dist.first;
        int cur_dist = pos_dist.second;
        q.pop();
        if(pos-1 >= 0 && !space[pos-1]){
            if(pos-1 == dest){
                cout << cur_dist+1 <<endl;
                break;
            }   
            space[pos-1] = cur_dist+1;
            q.push(pair<int,int>(pos-1, cur_dist+1));
        }
        if(pos+1 <= 100000 && !space[pos+1]){
            if(pos+1 == dest){
                cout << cur_dist+1 <<endl;
                break;
            }   
            space[pos+1] = cur_dist+1;
            q.push(pair<int,int>(pos+1, cur_dist+1));
        }
        if(pos*2 <= 100000 && !space[pos*2]){
            if(pos*2 == dest){
                cout << cur_dist+1 <<endl;
                break;
            }   
            space[pos*2] = cur_dist+1;
            q.push(pair<int,int>(pos*2, cur_dist+1));
        }
    }
    return 0;
}


