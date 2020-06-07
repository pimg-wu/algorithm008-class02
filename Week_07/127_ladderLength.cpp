//200607 pimg
//127、单词接龙：找出两个单词的最短转换序列的长度

/*描述：给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：每次转换只能改变一个字母、转换过程中的中间单词必须是字典中的单词。*/

//双向BFS （高级搜索）

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        queue<string> queue1;
        queue<string> queue2;
        unordered_set<string> visited1;
        unordered_set<string> visited2;

        queue1.push(beginWord);
        queue2.push(endWord);
        visited1.insert(beginWord);
        visited2.insert(endWord);

        unordered_set<string> wordListSet(wordList.begin(), wordList.end(), wordList.size());
        
        int count = 0;
        if(wordListSet.find(endWord) == wordListSet.end())
            return count;
        while(!queue1.empty() && !queue2.empty()) {
            count++;
            if(queue1.size() > queue2.size()) {
                queue1.swap(queue2);
                visited1.swap(visited2);
            }
            int length = queue1.size();
            while(length--) {
                string str(queue1.front());
                queue1.pop();
                for(int i = 0; i < str.length(); i++) {
                    char ch = str[i];
                    for(char c = 'a'; c <= 'z'; ++c) {
                        str[i] = c;
                        if(visited1.find(str) != visited1.end())
                            continue;
                        if(visited2.find(str) != visited2.end())
                            return count + 1;
                        if(wordListSet.find(str) != wordListSet.end()) {
                            queue1.push(str);
                            visited1.insert(str);
                        }
                    }
                    str[i] = ch;
                }
            }
        }
        return 0;
    }
};