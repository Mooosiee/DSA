//Hard Question has a diffrent approach for leetcode,this approahc will work for gfg and in interveiws
//Leetcode approach is kind of a CP way of doing it.
//Leetcode q.
// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

 

// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
// Explanation: There are 2 shortest transformation sequences:
// "hit" -> "hot" -> "dot" -> "dog" -> "cog"
// "hit" -> "hot" -> "lot" -> "log" -> "cog"
// Example 2:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: []
// Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

// Constraints:

// 1 <= beginWord.length <= 5
// endWord.length == beginWord.length
// 1 <= wordList.length <= 500
// wordList[i].length == beginWord.length
// beginWord, endWord, and wordList[i] consist of lowercase English letters.
// beginWord != endWord
// All the words in wordList are unique.
// The sum of all shortest transformation sequences does no

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        set<string> s(wordList.begin(),wordList.end());
        vector<string> usedOnLevel;
        queue<vector<string>> q;
        q.push({beginWord});
        usedOnLevel.push_back(beginWord);
        int level = 0;
        int word_len = beginWord.size();
        int shortest_len = 0;
        while(!q.empty()){
           auto it = q.front();
           string word = it.back();
           q.pop();
           if(word == endWord){
                if(ans.size() == 0){
                    ans.push_back(it);
                    shortest_len = it.size();
                }
                else if(shortest_len == it.size()){
                    ans.push_back(it);
                }
               
           }
           if(it.size() > level){
            level++;
            for(string it : usedOnLevel){
                s.erase(it);
            }
            usedOnLevel.clear();
           }
           for(int i = 0;i < word_len;i++){
                char org_chr = word[i];
                for(char c = 'a'; c <= 'z';c++){
                    word[i] = c;
                    if(s.find(word) != s.end()){
                        it.push_back(word);
                        usedOnLevel.push_back(word);
                        q.push(it);
                        it.pop_back();
                    }
                }
                word[i] = org_chr;
           }
        }
        return ans;

    }
};