// Longest Palindrome by Concatenating Two Letter Words
//You are given an array of strings words. Each element of words consists of two lowercase English letters.

// Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

// Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

// A palindrome is a string that reads the same forward and backward.

 

// Example 1:

// Input: words = ["lc","cl","gg"]
// Output: 6
// Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
// Note that "clgglc" is another longest palindrome that can be created.
// Example 2:

// Input: words = ["ab","ty","yt","lc","cl","ab"]
// Output: 8
// Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
// Note that "lcyttycl" is another longest palindrome that can be created.
// Example 3:

// Input: words = ["cc","ll","xx"]
// Output: 2
// Explanation: One longest palindrome is "cc", of length 2.
// Note that "ll" is another longest palindrome that can be created, and so is "xx".
 

// Constraints:

// 1 <= words.length <= 105
// words[i].length == 2
// words[i] consists of lowercase English letters.


//SOLUTION
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        bool center = 0;
        for (int i = 0; i < words.size(); i++) {
            freq[words[i]]++;
        }
        int max_len = 0;
        for (pair<const string, int>& it : freq) {
            string word = it.first;
            string rev = word;
            reverse(rev.begin(), rev.end());
            if (word != rev) {
                if (freq.find(rev) != freq.end() && freq[word] != 0 && freq[rev] != 0 ) {
                        int pairs = min(freq[word],freq[rev]);
                        max_len += pairs*4;
                        freq[word] -= pairs; 
                        freq[rev] -= pairs;
                }
            }
            else{
                int pairs = freq[word] / 2;
                max_len += pairs*4;
                freq[word] -= pairs*2;
                if(!center && freq[word] > 0){
                    max_len += 2;
                   freq[word] --;
                   center = 1;
                }
                
            }
        }
        return max_len;
    }
};