/*
 * NOTE:
 *      1、需要另外判断0数组的情况
 *      2、当某一个数组全部移动至 nums1[]，直接将另一个数组剩余元素移动到 nums1[]即可，需要引入标记表明某个数组全部移动完
 *
 * 1、设双指针从后往前比较
 * 2、比较 nums2[j] 是否大于等于 nums1[i]
 * 3、若是复制 nums2[] 到 nums1[] 后面；
 * 4、如不是，复制 nums1[] 到 nums1[] 后面
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i, j;
        int nr = m + n - 1;
        int fi = 0, fj = 0;

        // 处理 0 数组的情况
        if(!n)    return;
        else if(!m){
            j = n - 1;
            while(nr >= 0 && j >= 0){
                nums1[nr--] = nums2[j--];
            }
            return;
        }

        // 处理普通数组的情况
        i = m - 1; j = n - 1;
        while(!fi && !fj){
            if(nums1[i] <= nums2[j]){
                nums1[nr] = nums2[j];
                if(j > 0)    j--;
                else{
                    // 数组已全部移动完，设置完成标记
                    fj = 1;
                }
            }else{
                nums1[nr] = nums1[i];
                if(i > 0)    i--;
                else{
                    // 数组已全部移动完，设置完成标记
                    fi = 1;
                }
            }
            nr--;
        }

        // 将另外一个数组剩余元素移动到 nums1[] 余下位置
        if(fi){
            while(nr >= 0 && j >= 0){
                nums1[nr--] = nums2[j--];
            }
        }else if(fj){
            while(nr >= 0 && i >= 0){
                nums1[nr--] = nums1[i--];
            }
        }
    }
};