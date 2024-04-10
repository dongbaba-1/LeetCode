#include<vector>
using namespace std;

vector<vector<int> > result;
vector<int> path;
int sum = 0;
void backtracing(int k, int n, int index){
    if(path.size() == k){
        if(sum == n)
            result.push_back(path);
        return;
    }
    for(int i = index;i <= 9;++i){
        path.push_back(i);
        sum += i;
        if (sum > targetSum) { // 剪枝操作
            sum -= i; // 剪枝之前先把回溯做了
            path.pop_back(); // 剪枝之前先把回溯做了
            return;
        }
        backtracing(k,n,i+1);
        path.pop_back();
        sum -= i;
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    backtracing(k,n,1);
    return result;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> result = combinationSum3(3,7);
    return 0;
}
