#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


int main(int argc, char const *argv[])
{
    //以，分割字符串
    int n;
    cin >> n;
    string  str;
    string temp;
    stringstream ss;
    for(int i = 0;i < n;i++){
        cin >> str;//控制台输入一串带，的字符串
        ss << str;//获取的输入存进stringstream中
        int j = 0;
        while(getline(ss,temp,',')&& j < 4){//getline(ss,temp,',')以，为分隔符将每次读取的字符串存到temp中
            if(j == 1)
                client_name.push_back(temp);
            if(j == 2)
                factor.push_back(temp);
            if(j == 3){
                if(stoi(temp) >= 1 && stoi(temp) <= 100)
                    num.push_back(stoi(temp));
                else
                    num.push_back(0);
            }
                
            j++;
        }
        ss.clear();
    }
    // int factor_num;
    // cin >> factor_num;
    // for(int i = 0;i < factor_num;i++){

    // }

    
    return 0;
}
