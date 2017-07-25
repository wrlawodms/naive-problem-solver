#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int parent;
    vector<int> children;
    int dist;
};

int main()
{
    int N, M;
    scanf("%d, %d", &N, &M;
    int **net = new int*[N];
    for(int i=0; i<N; i++)
        net[i] = new int[N];
     

    for(int i=0; i<M; i++){
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        src--;
        dest--;
        net[dest][src] = net[src][dest] = weight;
    }
    
    TreeNode tree_node[N];
    for(int i=0; i<N; i++){
        tree_node[i].parent = -1;
        tree_node[i].dist = 0;
    }
    int *weight = new int[N];
    vector<int> active;
    int edge_cnt = 0;
    active.push_back(0); 
    while(!active.empty()){
        auto srcit = min_element(active.begin(), active.end());
        active.erase(srcit);
        int src = *srcit;
        for(int i=0; i<N; i++){
            if(!net[src][i]){
                if(weight[i] || weight[i] >= weight[src]+net[src][i]){
                    if(weight[i] == weight[src]+net[src][i]){
                        if(tree_node[i].dist >= tree_node[src].dist+1){
                            continue;
                        }
                        else{
                            tree_node[tree_node[i].parent].children.erase(active.find(i));
                            edge_cnt -= 1;
                        }
                    }
                    tree_node[i].parent = src;
                    tree_node[i].dist = tree_node[src].dist+1;
                    tree_node[src].children.push_back(i);
                    
                    weight[i] = weight[src]+net[src][i];
                    edge_cnt += 1;
                    active.push_back(i); 
                }
                net[src][i] = net[i][src] = 0;
            }
        }
    }
    cout << edge_cnt << endl;
    queue<int> nodes;
    nodes.push(0);
    while(!nodes.empty()){
        int src = nodes.front();
        nodes.pop();
        for(auto it=tree_node[src].children.begin(); 
            it!=tree_node[src].children.end(); it++){
            cout << src+" "+*it <<endl;
            nodes.push(*it);
        }
    }
    return 0;
}

