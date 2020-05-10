/*
 * 1、固定一个元素，依次检索其后元素是否与被固定元素相等
 * 2、若相等，继续检索下一个元素
 * 3、若不相等，进入下一步处理
 * 
 * 4、不相等元素赋值到数组前面位置
 * 5、所固定的元素变更为当前这个不相等的元素
 * 6、重复第1步直到到达数组末尾
 */

/* EXAMPLE:
 * 0, 0, 1, 1, 1, 2, 2, 3, 3
 * i----->j不同
 *       i-------->j不同
 *                i----->j不同
 *                      i-->不满足(j < numsSize退出)
 */

int removeDuplicates(int* nums, int numsSize){
    int i = 0, j = i + 1;
    int nr = 1;

    if(!numsSize)    return 0;

    while(j < numsSize){
        if(nums[j] != nums[i]){
            nums[nr++] = nums[j];
            i = j;
        }
        j++;
    }

    numsSize = nr;
    return numsSize;
}