/*
 * 1、外循环找出待移除的元素
 * 2、内循环将余下不用移除的第一个元素替换该移除元素(另外，设置了一个映射来判断数组该位置是否缺少由于移除元素后遗留的空位)
 */

/*
 * Remarks：
 *     85 / 113 个通过测试用例
 */

int removeElement(int* nums, int numsSize, int val){
    if(!numsSize)    return 0;

    int map[numsSize];
    int ptr_move = 0, ptr_retrieval;

    memset(map, 1, sizeof(map));

    for(; ptr_move < numsSize; ptr_move++){
        if(nums[ptr_move] == val || !map[ptr_move]){
            for(ptr_retrieval = ptr_move + 1; ptr_retrieval < numsSize; ptr_retrieval++){
                if(nums[ptr_retrieval] != val && map[ptr_retrieval]){
                    map[ptr_retrieval] = 0;
                    map[ptr_move] = 1;
                    nums[ptr_move] = nums[ptr_retrieval];
                    break;
                }
            }
        }
    }

    for(ptr_retrieval = 0; ptr_retrieval < numsSize && map[ptr_retrieval]; ptr_retrieval++);

    return ptr_retrieval;
}