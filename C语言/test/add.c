int Add(int num1, int num2 ) {
    // write code here
   while(num2 != 0) {//进位不为0则持续与相加结果进行相加
        int tmp = num1 ^ num2;//得到每位相加不考虑进位的数据
        num2 = (num1 & num2) << 1;//同1的位相加则会进位
        num1 = tmp;
    }
    return num1;
}

