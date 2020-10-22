vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> result;
    if (A.empty())
        return result;
    
    int z = 0; int size = A.size();
    while (z < size && A[z] == 0)
        ++z;
    if (z == size)
        return vector<int> {1};
    
    int carry = 0;
    for (int end = size-1; end>=z; --end)
    {
        if (end == size-1 && A[end] != 9)
        {
            ++A[end]; 
            break;
        }
        
        if (A[end] == 9)
        {
            A[end] = 0;
            carry = 1;
        }
        else
        {
            ++A[end]; 
            carry = 0; 
            break;
        }
    }
    
    if (carry)
    {
        result.emplace_back(carry);
        vector<int> temp(A.cbegin() + z, A.cend());
        for (auto& t : temp)
            result.emplace_back(t);
    }
    else
        result = vector<int>(A.cbegin() + z, A.cend());
    return result;
}
