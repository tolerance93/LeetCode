/*
 * Runtime: 60 ms, faster than 99.11% of C++ online submissions for Implement Trie (Prefix Tree).
 * Memory Usage: 44.9 MB, less than 75.80% of C++ online submissions for Implement Trie (Prefix Tree).
 */

#include <string>
#include <iostream>

using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        for (int i = 0; i < 26; i++)
        {
            next[i] = 0;
        }
        exist = false;
    }
    
    void insert(char* str)
    {
        if (*str)
        {
            if (!next[*str - 'a']) next[*str - 'a'] = new Trie();
            next[*str - 'a']->insert(str + 1);
        }
        else exist = true;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        char* str = &word[0];
        insert(str);
    }
    
    Trie* get(char * str)
    {
        if (*str)
        {
            if (next[*str - 'a']) return next[*str - 'a']->get(str + 1);
            return 0;
        }
        return this;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* trie = get(&word[0]);
        if (!trie) return false;
        return trie->exist;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* trie = get(&prefix[0]);
        return trie != 0;
    }
    
private:
    Trie* next[26];
    bool exist;
};
