#include<iostream>
#include<vector>
using namespace std;

void reverseString(vector<char>& s) {
    int low = 0;
    int high = s.size()-1;
    while(low < high){
        char temp = s[low];
        s[low] = s[high];
        s[high] = temp;
        low++;
        high--;
    }
}

int main(int argc, char const *argv[])
{
    vector<char> s;
    s.push_back('h');
    s.push_back('e');
    s.push_back('l');
    s.push_back('l');
    s.push_back('o');
    reverseString(s);
    return 0;
}

