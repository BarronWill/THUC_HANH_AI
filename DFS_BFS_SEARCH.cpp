#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<queue>
#include<fstream>
#include<math.h>

using namespace std;
const int sz = 9;
const int mx = 1000000;
int parent[sz];
bool mark[sz] = {};

void trace(int root, int goal){
    vector<int> arr;
    arr.push_back(goal);
    while(goal != root){
        goal = parent[goal];
        arr.push_back(goal);
    }
    reverse(arr.begin(), arr.end());
    for(int i : arr){
        cout<<(char)(i + 'A')<<" ";
    }
}

int BFS(int graph[sz][sz], int root, int final_vertex){
    queue<int> child;
    child.push(root);
    while(child.size()){
        int s = child.size();
        while(s--){
            int node = child.front();
            child.pop();
            if(mark[node]) continue;
            mark[node] = true;
            if(node == final_vertex) return 1;
            for(int i = 0; i < sz; i++){
                if(mark[i] == false && graph[node][i]){
                    child.push(i);
                    parent[i] = node;
                }
            }
        }
    }
    return 0;
}

int DFS(int graph[sz][sz], int root, int final_vertex){
    if(root == final_vertex) return 1;
    mark[root] = true;
    int ans = 0;
    for(int i = 0; i < sz; i++){
        if(mark[i] == false && graph[root][i]){
            ans = max(DFS(graph, i, final_vertex), ans);
            parent[i] = root;
        }
    }
    return ans;
}

main(){
    string name_file;   cin>>name_file;
    fstream file(name_file);
    if (file.is_open())
        cout << "Mo file thanh cong\n";
    else{
        cout << "Mo file that bai\n";
        return 1;
    }
    int graph[sz][sz];
    for(int i = 0; i < sz; i++)
        for(int j = 0; j < sz; j++)
            file >> graph[i][j];
    if(DFS(graph, 0, 5)){
        cout<<"Tim thay\n";
        trace(0, 5);
    }
    else cout<<"Khong tim thay\n";
    file.close();
}
