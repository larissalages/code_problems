class Solution {
public:
	int findMin(vector<int>& nums) {
		int t = INT_MAX;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] < t)
			{
				t = nums[i];
			}
		}
		return t;
	}
};
