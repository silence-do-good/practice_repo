class Solution {
public:
    bool a[1001][1001];
    string longestPalindrome(string s) {
        int len=s.length();
      //  bool a[len+1][len+1];
      //  for(int i=0;i<len;i++)
     //      for(int j=i;j<len;j++)
      //          a[i][j]=0;
        for(int i=0;i<len;i++)
            a[i][i]=1;
        for(int i=0,j=1;i<len && j<len;i++,j++)
        {
            if(s[i] == s[j])
                a[i][j]=1;
        }
        for(int k=2;k<len;k++)
        {
            for(int i=0,j=i+k;i<len && j<len;i++,j++)
            {
                if(a[i+1][j-1]==1)
                {
                    if(s[i]==s[j])
                        a[i][j]=1;
                }
            }
        }
        int start=0,end=0;
        bool flag=false;
        for(int k=len-1;k>=0;k--)
        {
            
            for(int i=0,j=i+k;i<len && j<len;i++,j++)
            {
                if(a[i][j]==1)
                {
                    start=i;
                    end=j;
                    flag=true;
                    break;
                }
            }
            if(flag)
                break;
        }
        /*
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++)
                cout<<a[i][j]<<"\t";
            cout<<endl;
        }
       
        cout<<start<<"\t"<<end<<endl;
        */
        
        string ret=s.substr(start,end-start+1);
        return ret;
    }
};