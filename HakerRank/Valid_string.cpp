string isValid(string s) {
int count[26] = {0};

    for (int i = 0; i < s.length(); i++) { 
        count[s[i] - 'a']++;   
    }

    int qanak = 0;      
    int diff_Count = 0;  

    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            qanak = count[i];
            break;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] > 0 && count[i] != qanak) { 
            if (count[i] == 1 || count[i] == qanak + 1)  

                diff_Count++;
            else
                return "NO";
        }
    }

  
    if (diff_Count > 1)   
        return "NO";

    return "YES";
}
