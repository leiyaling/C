int FirstNotRepeatingChar(char* str ) {
    int len = strlen(str);
    for(int i=0;i<len;i++)
    {
        int flag = 1;
        for(int j=0;j<len;j++)
        {
            if(j != i && str[i] == str[j])
            {
                flag = 0;
                break;
            }
                
        }
        if(flag == 1)
            return i;
    }
    return -1;
}

更优思想：小写字母 [a, z] 的 ascii 值为 [97, 122] ，大写字母 [A, Z] 的 ascii 值为 [65, 90]
这时候只需要定义一个统计各个字符出现次数的表（数组），然后遍历字符串，以字符的 ascii 值为下标对表中对
应位置的计数 +1 ，完成后，重新遍历字符串，从前往后判断哪个字符在表中统计的次数是 1 即可。
int FirstNotRepeatingChar(char* str ) {
// write code here
//小写字母[a, z]-[97,122], 大写字母[A, Z]-[65,90]
char table[128] = {0};//以字符ascii值为下标，存放各个字符出现的次数
int len = strlen(str);
for (int i = 0; i < len; i++) {
if (table[str[i]] < 256)//防止字符出现次数过多，导致溢出截断
table[str[i]] += 1; //以字符ascii值为下标，对应位置次数+1
}
//从第0个字符开始在表中查看对应字符的出现次数，第一个次数为1则找到
for (int j = 0; j < len; j++) {
if (table[str[j]] == 1){
return j;
}
}
return -1;
}