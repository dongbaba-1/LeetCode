#include<iostream>
#include<string>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    int array[26] = {0};
    if(ransomNote.size() > magazine.size()){
        return false;
    }
    for (int i = 0; i < magazine.size(); i++)
    {
        array[magazine[i] - 'a']++;
    }
    for (int i = 0; i < ransomNote.size(); i++)
    {
        array[ransomNote[i] - 'a']--;
        if(array[ransomNote[i] - 'a'] < 0)
            return false;
    }
    return true;
}