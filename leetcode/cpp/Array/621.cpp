class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        int max_freq=0,min_units,task_count=tasks.size();
        for(auto elem: tasks){
            count[elem-'A']++;
            if(count[elem-'A']>max_freq) max_freq=count[elem-'A'];
        }
        min_units=(max_freq-1)*(n+1);
        for(int i=0;i<26;i++){
            if(count[i]==max_freq) min_units++;
        }
        return max(min_units,task_count);
    }
};