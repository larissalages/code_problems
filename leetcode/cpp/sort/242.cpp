class Solution {
public:
    string selectionSort(string s){
        int index;
        for(int i=0;i<s.length();i++){
            index=i;
            for(int j=i;j<s.length();j++){
                if(s[j]<s[index]) index=j;
            }
            auto temp=s[i];
            s[i]=s[index];
            s[index]=temp;
        }
        return s;
    }
    
    string insertionSort(string s){
        int j;
        for(int i=1;i<s.length();i++){
            char key=s[i];
            j=i-1;
            while(j>=0 && key<s[j]){
                s[j+1]=s[j];
                j--;
            }
            s[j+1]=key;
        }
        return s;
    }
    
    string bubbleSort(string s){
        for(int i=0;i<s.length();i++){
            for(int j=0;j<s.length()-i-1;j++){
                if(s[j]>s[j+1]){
                    auto temp=s[j+1];
                    s[j+1]=s[j];
                    s[j]=temp;
                }
            }
        }
        return s;
    }
    
    void merge(string &s,int l,int m,int r){
        int n1=m-l+1,n2=r-m,i,j,k=l;
        string s1,s2;
        for(i=0;i<n1;i++) s1+=s[l+i];
        for(j=0;j<n2;j++) s2+=s[m+1+j];
        i=0,j=0;
        while(i<n1 && j<n2){
            if(s1[i]<s2[j]){
                s[k]=s1[i];
                i++;
            }
            else{
                 s[k]=s2[j];
                 j++;
            }
            k++;
        }
        while(i<n1){
            s[k]=s1[i];
            i++;
            k++;
        }
        while(j<n2){
            s[k]=s2[j];
            j++;
            k++;
        }
    }
    
    void mergeSort(string &s,int l,int r){
        if(l<r){
            int mid=(l+r)/2;
            mergeSort(s,l,mid);
            mergeSort(s,mid+1,r);
            merge(s,l,mid,r);
        }
    }
    
    bool isAnagram(string s, string t) {
        mergeSort(s,0,s.length()-1);
        mergeSort(t,0,t.length()-1);
        return s==t;
    }
};

//method 2: without sorting
class Solution {
public:
    bool isAnagram(string s, string t) {
      int len = s.length();
      if (len != t.length()) return false;
      vector<int> Hash(26, 0);

      for(int i=0;i<len;i++){
          Hash[s[i]-'a']++;
          Hash[t[i]-'a']--;
      }

      for(int i=0;i<26;i++){
          if(Hash[i]) return false;
      }
      return true;
    }
};