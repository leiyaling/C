/*[2, 3, 3, 2, 4] 注意数组10个元素，值为[1-10]， 但是访问下标应该在[0-9]之内,因此修改位置下标应该是值-1
0号元素是2，则将1号位置置为对应负值 [2, -3, 3, 2, 4]
1号元素是3，则将2号位置置为对应负值 [2, -3, -3, 2, 4]
2号元素是-3，绝对值为3，将2号位置为负值，但是2号位已经重置过，不需要重置，否则会变正数[2, -3, -3, 2, 4]
3号元素是-2，绝对值为2，将1号位置为负值，但是1号位已经重置过，不需要重置，否则会变正数[2, -3, -3, 2, 4]
4号元素是4，则将3号位置置为对应负值 [2, -3, -3, -2, 4]
遍历数组得到0,4两个位置的数据是大于0的，因为人家数值从1开始，因此+1后得到1， 5两个缺失的数字 */

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    for (int i = 0; i < numsSize; i++) {
        if (nums[abs(nums[i]) - 1] > 0)
        nums[abs(nums[i]) - 1] = -(nums[abs(nums[i]) - 1]);
    }
    int *ret = (int *)malloc(sizeof(int) * (numsSize));
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
        ret[*returnSize] = i + 1;
        *returnSize += 1;
        }
    }
    return ret;
    }