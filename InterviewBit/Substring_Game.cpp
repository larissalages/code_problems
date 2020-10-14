string Solution::solve(string A) {
   if(A.size()==1)
   {
       return "Bob";
   }
   if(A[0]!=A[1])
   {
       return "Alice";
   }
   return "Bob";
}
