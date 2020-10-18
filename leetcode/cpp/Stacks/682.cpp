//Problem 682 : Baseball Game(using stack)

class Solution {
public:
	int calPoints(vector<string>& ops) 
	{
		int result = 0; 
		stack <int> score;
		for (auto x : ops)
		{
			if (x == "C" && !score.empty()) 
				score.pop();
			else if(x == "D" && !score.empty())
				score.push(2*score.top());
			else if(x == "+" && !score.empty())
			{
				int top1 = score.top();
				score.pop();
				int top2 = score.top();
				score.push(top1);
				score.push((top1+top2));
			}
			else 
				score.push(stoi(x)); // convert from string to int then push on stack
		}
		while(!score.empty())
		{
			result += score.top();
			score.pop();
		}
		return result;
	}
};