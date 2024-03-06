#include<iostream>
using namespace std;

void reverseS(string &s,int lowIndex,int highIndex){
    while(lowIndex < highIndex){
        char temp = s[lowIndex];
        s[lowIndex] = s[highIndex];
        s[highIndex] = temp;

        lowIndex++;
        highIndex--;
    }
}

void rightSpin(string &s,int n){
    //先整体翻转
    int lowIndex = 0;
    int highIndex = s.size() - 1;
    reverseS(s,lowIndex,highIndex);

    //然后分部倒转
    int part1low = 0;
    int part1high = n-1;
    int part2low = n;
    int part2high = s.size() - 1;

    reverseS(s,part1low,part1high);
    reverseS(s,part2low,part2high);
}



int main(int argc, char const *argv[])
{
    string s = "abcdefg";
    rightSpin(s,2);
    cout<<s<<endl;
    return 0;
}
