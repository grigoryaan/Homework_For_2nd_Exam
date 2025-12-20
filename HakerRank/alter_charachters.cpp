int alternatingCharacters(string s) {
    int del_count = 0;

    for (int i = 1; i < s.length(); i++) {   
        if (s[i] == s[i - 1])                 // եթե հարևան տառերը նույնն են
            del_count++;                      
    }

    return del_count;                         
}
