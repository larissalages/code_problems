class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1,area,x,y,temp;
        while(left<right){
            x=right-left;
            y=min(height[left],height[right]);
            temp=x*y;
            if(temp>area){
                area=temp;
            }
            if(height[left]<height[right]){
                left+=1;
            }else{
                right-=1;
            }
        }
        return area;
    }
};