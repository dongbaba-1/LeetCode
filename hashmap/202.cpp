#include<unordered_set>
#include<iostream>
using namespace std;


int getSum(int n){
    int sum = 0;
    while(n){
        int temp = n % 10;
        sum += temp*temp;
        n = n / 10;
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> result_set;
    while(n != 1){
        int temp = getSum(n);
        if(result_set.find(temp) != result_set.end()){
            return false;
        }
        else{
            result_set.insert(temp);
        }
        n = temp;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    cout<<getSum(82)<<endl;
    if(isHappy(2)){
        cout<<"happy"<<endl;
    }
    else{
        cout<<"unhappy"<<endl;
    }
    return 0;
}
