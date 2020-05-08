/* 解题思路
 * 1、B[]直接合并到A[]，之后的操作都在A[]进行
 * 2、外循环确定一个元素，内循环依次检索其后的元素是否小于被确定元素
 * 3、满足则两个元素交换彼此位置，外循环回退一个下标重新进入第2步进行检索
 */


void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int tmp, pb = 0;
    int i, j;

    for(i = m; i < ASize; i++){
        A[i] = B[pb++];
    }

    for(i = 0; i < ASize - 1; i++){
        for(j = i + 1; j < ASize; j++){
            if(A[i] > A[j]){
                tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
                i--;
                break;
            }
        }
    }
}