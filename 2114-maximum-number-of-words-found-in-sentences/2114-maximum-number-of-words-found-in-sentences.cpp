class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n=sentences.size();
        int Maxcount=0;
        for(string s: sentences){
            int word=1;
            for(char ch: s){
                if(ch==' '){
                    word++;
                }
                Maxcount= max(Maxcount, word);
            }
        }
        return Maxcount;

        
    }
};