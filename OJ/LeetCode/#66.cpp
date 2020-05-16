/*
 * Note:
 *      有种情况是给出9，最后输出10。
 *
 * 1、从末尾开始检查，如果不是9直接加1，就加这一位便退出循环
 * 2、如果是9变成0，且一直检查下去
 * 3、最后检查最高位，如果是0说明加一前是9，需要额外补多一个元素
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();

        for(int i = size - 1; i >= 0; i--){
            if(digits[i] != 9){
                digits[i]++;
                break;
            }else{
                digits[i] = 0;
            }
        }

        if(!digits[0]){
            digits[0] = 1;
            digits.push_back(0);
        }

        return digits;
    }
};