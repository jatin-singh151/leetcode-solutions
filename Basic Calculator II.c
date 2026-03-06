int calculate(char* s){
   int nums[150000];
    int top = -1;
    int CrrNum = 0;
    char PrevOperator = '+';

    for (int i = 0; s[i] != '\0'; i++){
        char c = s[i];

        if (isdigit(c)) {
            CrrNum = CrrNum * 10 + (c - '0');
        }

        if (c == '+' || c == '-' || c == '*' || c == '/' || s[i + 1] == '\0'){
            if (PrevOperator == '+') {
                nums[++top] = CrrNum;
            } else if (PrevOperator == '-'){
                nums[++top] = -CrrNum;
            } else if (PrevOperator == '*'){
                nums[top] *= CrrNum;
            } else if (PrevOperator == '/'){
                nums[top] = nums[top] / CrrNum;
            }
            PrevOperator = c;
            CrrNum = 0;
        }
    }
    int result = 0;
    for (int i = 0; i <= top; i++){
        result += nums[i];
    }

    return result;
}
