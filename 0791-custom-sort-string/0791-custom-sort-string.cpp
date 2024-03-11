class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> frequency(26);
        //Counting the Characters frequency
        for(int i=0;i<s.length();i++){
            frequency[s[i]-'a']++;
        }
        string out="";
        //Looping Through Order String
        for(int i=0;i<order.length();i++){
            out.append(frequency[order[i]-'a'], order[i]);
            //Making the frequency to zero so no appending will happen again
            frequency[order[i]-'a']=0;
        }
        //Appending the remaning Characters
        for(int i=0;i<26;i++){
            out.append(frequency[i], 'a'+i); 
        }
        return out;
    }
};
