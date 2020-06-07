//200607 pimg
//212、单词搜索II、找出所有同时在二维网格和字典中出现的单词
//（单词必须按字母顺序、通过相邻的单元格（四联通）内的字母构成，同一个单元格内的字母不重复）

//字典树 trie，又称单词查找树/前缀树

class TrieNode {
public:
    string word = "";
    vector<TrieNode*> nodes;
    TrieNode():nodes(26, 0) {}
};

class Solution {
    int rows, cols;
    vector<string> res;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = rows ? board[0].size() : 0;
        if(rows == 0 || cols == 0) return res;

        //建立字典树模板
        TrieNode* root = new TrieNode();
        for(string word : words) {
            TrieNode *cur = root;
            for(int i = 0; i < word.size(); ++i) {
                int idx = word[i] - 'a';
                if(cur->nodes[idx] == 0)
                    cur->nodes[idx] = new TrieNode();
                cur = cur->nodes[idx];
            }
            cur->word = word;
        }

        //DFS模板
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                dfs(board, root, i, j);
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& board, TrieNode* root, int x, int y) {
        char c = board[x][y];
        //递归边界
        if(c == '.' || root->nodes[c-'a'] == 0) return;
        root = root->nodes[c-'a'];
        if(root->word != "") {
            res.push_back(root->word);
            root->word = "";
        }

        board[x][y] = '.';
        if(x > 0) dfs(board, root, x - 1, y);
        if(y > 0) dfs(board, root, x, y - 1);
        if(x + 1 < rows) dfs(board, root, x + 1, y);
        if(y + 1 < cols) dfs(board, root, x, y + 1);
        board[x][y] = c;
    }
};