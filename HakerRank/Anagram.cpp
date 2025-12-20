int makeAnagram(string a, string b) {
    if (a == b)                  
        return 0;               

    int count[26] = {0};        

    for (int i = 0; i < a.length(); i++) {   
        int index = a[i] - 'a';             
        count[index]++;                      
    }

    for (int i = 0; i < b.length(); i++) {  
        int index = b[i] - 'a';             
        count[index]--;                       
    }

    int del_count = 0;                       
    for (int i = 0; i < 26; i++) {           
        if (count[i] > 0)                   
            del_count += count[i];           
        else
            del_count -= count[i];             
    }

    return del_count;                         
}
