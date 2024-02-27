#include<vector>
using namespace std;


bool isAnagram(string s, string t) {
    int records[26] = {0};//26个元素全为0
    for (int i = 0; i < s.length(); i++)
    {
        records[s[i] - 'a']++;
    }
    for(int i = 0;i<t.length();i++){
        records[t[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++){
        if(records[i] != 0)
            return false;
    }
    return true;
}