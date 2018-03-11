#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> result;
        unordered_map<string, int> hash;
        for(int i=0; i<n; i++) {
                string word = strs[i];
        		sort(word.begin(), word.end());
        	if(hash.find(word)==hash.end()) {
				vector<string> temp;
				temp.push_back(strs[i]);
				result.push_back(temp);
				hash[word] = result.size()-1;	        		
        	}else {
        		result[hash[word]].push_back(strs[i]); 
        	}
        }
        for(int i=0; i<result.size(); i++) {
            sort(result[i].begin(), result[i].end());
        }
		return result;        
    }
    
	vector< vector<string> > groupAnagrams01(vector<string> &strs) {
        vector< vector<string> > result;
        unordered_map<string, multiset<string>> m;
        for(int i=0; i<strs.size(); i++){
            string word = strs[i];
            sort(word.begin(), word.end());
            m[word].insert(strs[i]);
        }
        for(auto item : m){
            vector<string> v(item.second.begin(), item.second.end());
            result.push_back(v);
        }
        return result;
    }
};

int main(int argc, char** argv) {
	vector<string> a{"eat", "tea", "tan", "ate", "nat", "bat"};
	Solution s;
	vector<vector<string>> result = s.groupAnagrams(a);
	for(auto i:result) {
		for(auto j:i) {
			cout << j << " ";			
		}
		cout << endl;
	}		
}
