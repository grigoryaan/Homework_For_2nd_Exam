long substrCount(int n, string s) {                 
    n = (int)s.size();                              
    if (n == 0) return 0;                             

    long qanak = 0;                                     

    vector<int> len;                                  
    vector<char> ch;                                
    len.reserve(n);                                
    ch.reserve(n);                                    

    for (int i = 0; i < n; ) {                        
        char c = s[i];                                
        int j = i;                                     

        while (j < n && s[j] == c) j++;              

        ch.push_back(c);                              
        len.push_back(j - i);                          
        
        i = j;                                         
    }

    int m = (int)len.size();                          

    for (int i = 0; i < m; i++) {                      
        long L = len[i];                               
        qanak += L * (L + 1) / 2;                      
    }

    for (int i = 1; i < m - 1; i++) {                  
        if (len[i] == 1 && ch[i - 1] == ch[i + 1]) {   
            qanak += (len[i - 1] < len[i + 1])          
                   ? len[i - 1]                        
                   : len[i + 1];                   
        }
    }

    return qanak;                                        
}
