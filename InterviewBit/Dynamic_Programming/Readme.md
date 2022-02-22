Problem:- https://www.interviewbit.com/problems/merge-elements/
Problem Description in other words:- within a collection, reduce the cost of merging two adjacent elements.

Solution approach:-
   One approach could be, 
      - between start-element and end-element, break the collection, 
      - calculate left side's minimum sum of merging and right side's minimum sum of merging, and 
      - add both side to get minimum cost of merging at that break point, and 
      - save merging cost to memory. 
   Move break-point ahead of current one, and follow same process to get the minimum sum of merging at that point, and so on till break point reaches to end-element.

   As, solution hints for recursion, as well as memoization, this makes it a Dynamic Programming Problem.

   Perticularly, for this case, Matrix Chain Multiplication case of Dynamic Programming matches the current problem. All this specific case requires is replacement of addition in place of multiplication, which will solve the problem.