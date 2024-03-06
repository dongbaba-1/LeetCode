#include<string>
#include<iostream>
using namespace std;

string reverseStr(string s, int k) {
    int length = s.size();
    int i = 0;
    int j = k-1;
    int i_chushi = 0;
    int j_chushi = k-1;
    while((length / (2*k)) >= 1 ){
        while(i<j){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;

            i++;
            j--;
        }
        i = i_chushi + 2 * k;
        i_chushi = i_chushi + 2 * k;
        j = j_chushi + 2 * k;
        j_chushi = j_chushi + 2 * k;

        length = length - 2*k;
    }
    if(length > k){//剩余长度大于k，则反转前k个
        while(i<j){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }

    }
    else{//若少于k个，则全部反转
        j = s.size()-1;
        while(i<j){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
    return s;
}

int main(int argc, char const *argv[])
{
    string s = "abcdefg";
    string reverseS = reverseStr(s,2);
    cout<<reverseS<<endl;
    return 0;
}
