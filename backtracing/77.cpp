#include <vector>
using namespace std;


vector<int> path;
vector<vector<int> > result;

void backtracing(int n,int k,int index){
    if(path.size() == k){
        result.push_back(path);
        return;
    }
    //for(int i = index;i<=n;++i){
    //剪枝优化
    for(int i = index;i<=n - (k - path.size()) + 1;++i){
        path.push_back(i);
        backtracing(n,k,i+1);
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    backtracing(n,k,1);
    return result;
}