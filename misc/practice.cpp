#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

void generateSubsequence(string s, unordered_set<string> &st ) {
    
    for(int i = 0; i < s.size(); i++) {
        for(int j = s.size(); j > i; j--) {
            string sub = s.substr(i, j);
            st.insert(sub);
            
            for(int k = 1; k < sub.size() - 1; k++) {
                
                string sb = sub;
                sb.erase(sb.begin() + k);
                generateSubsequence(sb, st);
            }
        }
    }
    
}
int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    
	    string s;
        unordered_set<string> st;
	    cin >> s;
	    generateSubsequence(s, st);
	    
	    string s1, s2;
	    vector<int> ans;
	    
	    for(auto it : st) {
	        s1 = it;
	        s2 = it;
	        reverse(s2.begin(), s2.end());
	        if(s1 == s2)
	            ans.push_back(s1.size());
	    }
	    
	    cout << *max_element(ans.begin(), ans.end()) << endl;
	}
	return 0;
}