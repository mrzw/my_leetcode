#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string symbol[] =   {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};    
        int value[]     =   {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1}; 
        string result;

        for(int i=0; num!=0; i++){
            while(num >= value[i])
            {
                num -= value[i];
                result+=symbol[i];
            }
        }
        return result;
    }
    string intToRoman2(int num) {
        std::map<int, string> map = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, 
                                     {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        string ret;
        for (auto iter = map.rbegin(); iter != map.rend(); ++iter)
            while (num >= iter->first)
            {
                ret += map[iter->first];
                num -= iter->first;
            }
        return ret;
    }
};

int main(int argc, char** argv)
{
    Solution s;
    cout << s.intToRoman2(3) << endl;
}
