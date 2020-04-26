//200426 pimg
//有效的字母异位词：判断字符串s和t是否为字母异位词

// 1、先排序，比较，相同则为异位词
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())  return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t ? true : false;
    }
};

// 2、使用数组，记录字母出现频次，s出现+1，t出现-1
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.len!gth() != t.length())  return false;
        int n = s.length();
        int nums[26] = {0};
        for(int i = 0; i < n; ++i) {
            nums[s[i] - 'a']++;
            nums[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; ++i) {
            if(nums[i] = 0)
                return false;
        }
        return true;
    }
};

// 3、使用哈希表hash table
// 使用到unordered_map 结构，不熟悉，学习STL
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())  return false;
        int n = s.length();
        unordered_map<char, int> counts;
        for(int i = 0; i < n; ++i) {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for(auto count : counts) {
            if(count.second) return false;
        }
        return true;
    }
};