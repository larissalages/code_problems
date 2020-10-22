/**
 * Problem : https://leetcode.com/problems/circular-array-loop/submissions/
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 */
public class CircularArrayLoop {
    public boolean circularArrayLoop(int[] nums) {
        int N = nums.length;
        int K = 1001;

        for (int i=0; i<N; i++) {
            if (nums[i]>1000 || nums[i]<-1000)
                continue;

            boolean direction = (nums[i]>0);
            int ix=i;
            int nextIndex;
            while (true) {
                nextIndex = getNextIndex(nums, ix);

                if(
                    (nums[nextIndex]>1000 && nums[nextIndex]!=K) || (nums[nextIndex]<-1000 && nums[nextIndex]!=-K) ||
                    nextIndex==ix || nums[nextIndex]>0)!=direction {
                    break;
                }
                if(nums[nextIndex]==(direction?K:-K)){
                    return true;
                }

                nums[ix] = (direction?K:-K);
                ix = nextIndex;
            }
            K+=1;
        }
        return false;
    }
    private int getNextIndex(int[] nums, int i) {
        int N = nums.length;
        int out = (nums[i] + i)%N;
        return (out>=0)?out:(out+N);
    }

}
