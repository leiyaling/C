//给定两个整数 left 和 right ，返回一个列表，列表的元素是范围 [left, right] 内所有的 自除数 。

int* selfDividingNumbers(int left, int right, int* returnSize){
        int *ret = (int *)calloc(1000, sizeof(int));//动态申请足够大的空间用于存放返回的自除数
        *returnSize = 0;
        for (int i = left; i <= right; i++) {
                int num = i;//48
                while(num) {
                int remainder = num % 10;//计算余数 8
                if (remainder == 0 || (i % remainder) != 0) {//判断i自身与余数取模是否为0
                break;
                }
                num /= 10;
                }
                //如果num==0表示通过了每一位数的取模判断，则i就是自除数
                if (num == 0) ret[(*returnSize)++] = i;
        }
        return ret;
}