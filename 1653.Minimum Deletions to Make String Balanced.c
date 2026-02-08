int minimumDeletions(char* s) {
    int bCount = 0;
    int del = 0;      

    for (int i = 0; s[i] != '\0'; i++) {

        if (s[i] == 'b') {
            bCount++;   
        } 
        else { 
            if (del + 1 < bCount)
                del = del + 1;
            else
                del = bCount;
        }
    }

    return del;
}
