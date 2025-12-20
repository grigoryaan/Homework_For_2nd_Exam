int commonChild(string s1, string s2) {
    int n = (int)s1.size();        
    vector<int> prev(n + 1, 0);     
    vector<int> current(n + 1, 0);     
    for (int i = 1; i <= n; i++) {    
        current[0] = 0;                

        for (int j = 1; j <= n; j++) {     


            if (s1[i - 1] == s2[j - 1]) {             
                current[j] = prev[j - 1] + 1;            

            }
            else {
               
                current[j] = max(prev[j], current[j - 1]);
                  }
        }

        prev = current;              
    }

    return prev[n];                 
}
