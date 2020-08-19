class Solution {
public:
    bool isVowel(char c){
        string vowels = "aeiouAEIOU";
        for(int i=0;i<vowels.length();i++){
            if( c == vowels[i]) return true;
        }
        return false;
    }
    string appender(string toAppend,int a_no){
        if( isVowel(toAppend[0]) ){
            toAppend.append("ma");
            for(int i=0;i<a_no;i++)
                toAppend.push_back('a');
        }    
        else{
            toAppend.push_back(toAppend[0]);
            toAppend.erase(0,1);
            toAppend.append("ma");
            for(int i=0;i<a_no;i++)
                toAppend.push_back('a');
        }
        return toAppend;
    }
    
    vector<string> splitString(string toSplit){
        vector<string> splitter;
        int j=0;
        for(int i=0;i<toSplit.length();i++){
            if(toSplit[i]==' '){
                splitter.push_back(toSplit.substr(j,i-j));
                j=i+1;
            }
        }
        splitter.push_back(toSplit.substr(j,toSplit.length()));
        return splitter;
    }
    string toGoatLatin(string S) {
        vector<string> inp = splitString(S);
        string finalString;
        for(int i=0;i<inp.size();i++){
            finalString += " " + appender(inp[i],i+1);
        }
        finalString.erase(0,1);
        return finalString;
    }
};
