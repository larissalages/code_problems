// First Approach
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(auto it=nums.begin();it!=nums.end();it++)
        {
         if(*it==val)
         {
           nums.erase(it);
             --it;
         }
        }
       return nums.size(); 
    }
};

//Using stacks
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n=nums.size();
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=val)
                s.push(nums[i]);
        }
        nums.clear();
         while(!s.empty())
         {
             nums.push_back(s.top());
             s.pop();
         }
        return nums.size();
    }
};
