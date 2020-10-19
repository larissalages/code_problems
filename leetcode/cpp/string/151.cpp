class Solution
{
public:
    string reverseWords(string a)
    {
        int i = 0, n;
        string st = "";
        vector<string> wd;
        for (i = a.length() - 1; i >= 0; i--)
        {
            if (a[i] != ' ')
            {
                break;
            }
        }
        n = i + 1;
        for (i = 0; i < n; i++)
        {
            if (a[i] != ' ')
            {
                break;
            }
        }
        for (; i < n; i++)
        {
            if (a[i] == ' ')
            {
                if (a[i - 1] != ' ')
                {
                    wd.push_back(st);
                    st = "";
                }
            }
            else
            {
                st += a[i];
            }
        }
        wd.push_back(st);
        st = "";
        for (i = wd.size() - 1; i >= 0; i--)
        {
            st += wd[i];
            if (i != 0)
            {
                st += " ";
            }
        }
        return st;
    }
};