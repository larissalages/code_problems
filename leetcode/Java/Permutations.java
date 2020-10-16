package BackTracking;
import java.util.*;

    /*
    Given a collection of distinct integers, return all possible permutations.

    Example:

    Input: [1,2,3]
    Output:
    [
    [1,2,3],
    [1,3,2],
    [2,1,3],
    [2,3,1],
    [3,1,2],
    [3,2,1]
    ]
    */
public class Permutations {
    class Solution {
        public List<List<Integer>> permute(int[] nums) {
            List<List<Integer>> permutations = new ArrayList<>();
            boolean[] seen = new boolean[nums.length];
            if(nums == null || nums.length == 0) {
                return permutations;
            }
            findPermutations(nums, permutations, new ArrayList<>(), seen);
            return permutations;
        }
    
        private void findPermutations (int[] nums, List<List<Integer>> permutations, List<Integer> current, boolean[] seen) {
            if(current.size() > nums.length) {
                return;
            }
        
            if(current.size() == nums.length) {
                permutations.add(new ArrayList<>(current));
                return;
            }
        
            for(int i = 0; i < nums.length; i++) {
                if(seen[i] == true) {
                    continue;
                }
                current.add(nums[i]);
                seen[i] = true;
                findPermutations(nums, permutations, current, seen);
                current.remove(current.size() - 1);
                seen[i] = false;
            }
        
            return;
        }
    } 
}
