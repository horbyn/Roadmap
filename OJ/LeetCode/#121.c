/*
 * 1、固定一个元素，依次检索其后元素是否比被固定元素大
 * 2、若是，再计算它们的差值（保存最大的差值）
 */

/* EXAMPLE:
 * 7, 6, 4, 3, 1
 * ·----------->都没有比7大的         ╮
 *    ·-------->都没有比6大的         │
 *       ·----->都没有比4大的         │全部都没有返回0
 *          ·-->都没有比3大的         │
 *             ·->最后一个元素不用检查 ╯
 * 
 * 7, 1, 5, 3, 6, 4
 * ·-------------->都没有比7大的
 *    ·--------> 6-1为最大值 --------->最大值就是6
 *       ·-----> 非最大值
 *          ·--> 非最大值
 *             ·-->没有比6大的
 */

int maxProfit(int* prices, int pricesSize){
    int i, j;
    int profit = 0;

    if(!pricesSize)    return 0;

    for(i = 0; i < pricesSize - 1; i++){
        for(j = i + 1; j < pricesSize; j++){
            if(prices[i] < prices[j]){
                if(prices[j] - prices[i] > profit){
                    profit = prices[j] - prices[i];
                }
            }
        }
    }

    return profit;
}