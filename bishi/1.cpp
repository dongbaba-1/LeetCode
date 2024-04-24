#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,m;
    int result = 0;
    cin>>n>>m;
    //二维数组存放
    vector<vector<int> > vec(n,vector<int>(m));
    // vec.resize(n);
    // for(int i = 0;i <vec.size();i++){
    //     vec[i].resize(m);
    // }
    cin.ignore();
    // string s; //存放每一行数组，s.size() == m
    // for(int i = 0 ;i < n;i++){
    //     getline(cin,s);
    //     int num = 0;
    //     vector<string> str_vec;
    //     string str = "";
    //     for(int j = 0;j < s.size();j++){
    //         if(s[j] == ' ' || j == s.size() - 1){
    //             if(j == s.size() - 1)
    //                 str += s[j];
    //             vec[i][num] = stoi(str);
    //             num++;
    //             str = "";
    //         }
    //         else{
    //             str += s[j];
    //         }
               
    //     }
    // }
    int num1 = 0;
    int num2 = 0;
    while(num2 < n){//总共有n行，读n个
        int a;
        num1 = 0;
        while(cin >> a && num1 < m){
            vec[num2][num1] = a;
            num1++;
        }
        num2++;
    }

    //以2*2的格式遍历二维数组
    int temp;
    for(int i = 0 ;i < m - 1;i++){
        for(int j = 0;j < n - 1;j++){
            //2*2的小方格内部
            temp = vec[j][i];//temp等于小方格的第一个数
            if(vec[j+1][i] != temp || vec[j][i+1] != temp || vec[j+1][i+1] != temp)
                continue;
            else
                result++;
            
        }
    }
    cout<<result<<endl;
 
}