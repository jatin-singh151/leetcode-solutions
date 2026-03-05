#include <stdlib.h> 
int evalRPN(char** tokens, int tokensSize) {
    int n = tokensSize;
    int j=0;
    int arr[n];
    int c=0;
    for(int i=0; i<n;i++){
        if(*tokens[i] == '+' && tokens[i][1] == '\0'){
            c = arr[j-2] + arr[j-1];
            j = j-2;
            arr[j] = c;
            j++;
        }
         else if(*tokens[i] == '-' && tokens[i][1] == '\0'){
            c = arr[j-2] - arr[j-1];
            j = j-2;
            arr[j] = c;
            j++;
        }
        else if(*tokens[i] == '*' && tokens[i][1] == '\0'){
            c = arr[j-2] * arr[j-1];
            j = j-2;
            arr[j] = c;
            j++;
        }
         else if(*tokens[i] == '/' && tokens[i][1] == '\0'){
            c = arr[j-2] / arr[j-1];
            j = j-2;
            arr[j] = c;
            j++;
        }
        else{
            arr[j] = atoi(tokens[i]);
            j++;

        }

    }
    int result = arr[j-1];

    return result;
}
