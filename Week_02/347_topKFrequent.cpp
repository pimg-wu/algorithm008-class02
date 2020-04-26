//200426 pimg
//347、前k个高频元素：在非空整数数组中返回其中出现频率前k高的元素

//堆：求前k大，用小根堆；求前k小，用大根堆
//topk：维护堆大小不超过k，每次压入堆前和堆顶元素比较（小根堆的堆顶元素总是最小的），
//如果比堆顶元素还小，扔掉，否则压入堆，检查堆大小是否超过k，超过则弹出堆顶，O(nlongk)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        using E = pair<int, int>;
        priority_queue<E, vector<E>, greater<E>> minHeap;
        unordered_map<int, int> mp;
        for(auto i : nums)  ++mp[i];
        for(auto& x : mp) {
            auto pair = make_pair(x.second, x.first);
            if(minHeap.size() == k) {
                if(pair < minHeap.top()) continue;
                minHeap.pop();
            }
            minHeap.push(move(pair));
        }
        vector<int> res(minHeap.size());
        k = res.size();
        while(!minHeap.empty()) {
            res[--k] = minHeap.top().second;
            minHeap.pop();
        }
        return res;
    }
};