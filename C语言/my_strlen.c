#include<stdio.h>

int my_strlen(char *str)
{
	/*int count = 0;
	while(*str!='\0')
	{
		count++;
		str++;
	}
	return count;*/
	if (*str != '\0')
	{
		return 1 + my_strlen(str+1);
	}
	else
	{
		return 0;
	}
}
int main()
{
	char arr[] ="abcd";
	int len=my_strlen(arr);
	printf("%d\n", len);
	return 0;
}