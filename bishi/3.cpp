#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int,char> umap;
    int n;
    cin >>n;
    cin.ignore();
    string s;
    getline(cin,s);
    for(int i = 0;i <n;i++){
        umap.insert(make_pair(i+1,s[i]));
    }
    int num1,num2;
    unordered_map<int,int> num_umap;
    while(cin >> num1>>num2){
        num_umap.insert(make_pair(num1,num2));
    }
    for(int i = 1;i<=n;i++){
        if(num_umap.find(i)){
            char color = umap[i];
            if(color == 'B')
                if(umap[num_umap[i] == 'R'])
        }
    }


}