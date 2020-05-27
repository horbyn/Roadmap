/*
 * 1、利用栈保存字符
 * 2、每读取一个字符就判断栈顶前一个元素是否匹配
 * 3、若是出栈，否则入栈
 * 4、最后检查栈是否为空，若是说明所有括号都匹配，否则不匹配
 */

bool isValid(char* s) {
    int i = 0;
    char stack[10240] = { 0 };
    int top = 0;

    // 遍历每个字符
    while (*(s + i)) {
        if (*(s + i) == '(' || *(s + i) == '{' || *(s + i) == '[') {
            // 如果是开半符就入栈
            stack[top++] = *(s + i);
        }
        else {
            // 闭半符就对比栈中元素，符合条件出栈，否则入栈
            if (*(s + i) == ')') {
                if (!top){
                    // 如果闭半符是第一个字符，那就入栈
                    stack[top++] = *(s + i);
                    continue;
                }

                if (stack[top - 1] == '(')    top--;
                else    stack[top++] = *(s + i);
            }
            else if (*(s + i) == '}') {
                if (!top){
                    // 如果闭半符是第一个字符，那就入栈
                    stack[top++] = *(s + i);
                    continue;
                }

                if (stack[top - 1] == '{')    top--;
                else    stack[top++] = *(s + i);
            }
            else if (*(s + i) == ']') {
                if (!top){
                    // 如果闭半符是第一个字符，那就入栈
                    stack[top++] = *(s + i);
                    continue;
                }

                if (stack[top - 1] == '[')    top--;
                else    stack[top++] = *(s + i);
            }
        }
        i++;
    }

    // 判断栈状态
    if (!top)    return true;
    else    return false;
}