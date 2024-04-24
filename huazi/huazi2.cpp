#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char const *argv[])
{
    int n ;
    cin >> n;
    cin.ignore();
    string temp;
    vector<string> vec;
    while (n > 0 && cin >> temp)
    {
        vec.push_back(temp);
        n--;
    }
    
    if(vec.size() < 3){
        for(int i = 0;i < vec.size();i++)
            cout <<vec[i]<<" ";
        return 0;
    }
    int i = 0, j = 1 , k = 2;
    while(k < vec.size()){

        if(vec[i] == vec[j] && vec[j] == vec[k]){
            int index1 = i;
            int index2 = k + 1;
            while(index2 < vec.size()){
                vec[index1] =vec[index2];
                index1++;
                index2++;
            }
            vec.resize(vec.size() - 3);
            i = 0;
            j = 1;
            k = 2;
        }
        else{
            i++;
            j++;
            k++;
        }
    }
    if(vec.size() == 0)
        cout<<0<<endl;
    else{
        for(int i =0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
    }
    return 0;
}
