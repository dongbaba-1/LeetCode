#include<vector>
#include<iostream>
using namespace std;



//首先要处理digits字符串
vector<int> handle(string digits){
    vector<int> numbers;
    for (int i = 0; i < digits.size(); i++)
    {
        char temp = digits[i];
        int num_temp = temp - '0';
        numbers.push_back(num_temp);
    }
    return numbers;
    
}

vector<vector<string> > num_to_letter(vector<int> numbers){
    vector<vector<string> > num_result;
    for (int i = 0; i < numbers.size(); i++)
    {
        if(numbers[i] == 2){
            vector<string> temp = {"a","b","c"};
            num_result.push_back(temp);
        }
        else if(numbers[i] == 3){
            vector<string> temp = {"d","e","f"};
            num_result.push_back(temp);
        }
            
        else if(numbers[i] == 4){
            vector<string> temp = {"g","h","i"};
            num_result.push_back(temp);
        }
        else if(numbers[i] == 5){
            vector<string> temp = {"j","k","l"};
            num_result.push_back(temp);
        }
            
        else if(numbers[i] == 6){
            vector<string> temp = {"m","n","o"};
            num_result.push_back(temp);
        }
            
        else if(numbers[i] == 7){
            vector<string> temp = {"p","q","r","s"};
            num_result.push_back(temp);
        }
            
        else if(numbers[i] == 8){
            vector<string> temp = {"t","u","v"};
            num_result.push_back(temp);
        }
            
        else if(numbers[i] == 9){
            vector<string> temp = {"w","x","y", "z"};
            num_result.push_back(temp);
        }
            
    }
    return num_result;

}

vector<string> letterCombinations(string digits) {
    vector<int> numbers = handle(digits);
    vector<vector<string> > letter_vecs = num_to_letter(numbers);
    vector<string> result;
    if (digits.empty())
    {
        return result;
    }
    else if(digits.size() == 1){
        for(int i = 0;i<letter_vecs[0].size();++i){
            result.push_back(letter_vecs[0][i]);
        }
    }
    else if(digits.size() == 2){
        for(int i = 0;i<letter_vecs[0].size();++i){
            for(int j = 0;j<letter_vecs[1].size();++j){
                string temp = letter_vecs[0][i] + letter_vecs[1][j];
                result.push_back(temp);
            }
        }
    }
    else if(digits.size() == 3){
        for(int i = 0;i<letter_vecs[0].size();++i){
            for(int j = 0;j<letter_vecs[1].size();++j){
                for (int k = 0; k < letter_vecs[2].size(); k++){
                    string temp = letter_vecs[0][i] + letter_vecs[1][j] + letter_vecs[2][k];
                    result.push_back(temp);
                }
                
            }
        }
    }
    else{
        for(int i = 0;i<letter_vecs[0].size();++i){
            for(int j = 0;j<letter_vecs[1].size();++j){
                for (int k = 0; k < letter_vecs[2].size(); k++)
                {
                    for (int l = 0; l < letter_vecs[3].size(); l++)
                    {
                        string temp = letter_vecs[0][i] + letter_vecs[1][j] + letter_vecs[2][k] + letter_vecs[3][l];
                        result.push_back(temp);
                    }
                    
                }
                
            }
        }
    }

    return result;
    
}
int main(int argc, char const *argv[])
{
    vector<string> result = letterCombinations("2347");
    for(int i = 0;i<result.size();++i){
        cout<<result[i]<<endl;
    }
    return 0;
}
