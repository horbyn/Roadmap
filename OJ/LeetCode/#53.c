int maxSubArray(int* nums, int numsSize){
    int i;
    int max = nums[0], tmp;

    if(numsSize == 1)    return max;

    tmp = max;
    for(i = 1; i < numsSize; i++){
        tmp += nums[i];

        if(tmp < max){
            if(tmp < 0){    
                //max = tmp;
                tmp = 0;
            }
        }
        else    max = tmp;
    }

    return max;
}