#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<ctype.h>
// my_atoi(NULL)
// my_atoi("")
// my_atoi("123")
// my_atoi("-123")
// my_atoi("     123")
// my_atoi("111111111111111111111")越界
enum Status
{
	VALID,
	INVALID
};
enum Status status = INVALID;
int my_atoi(const char* str)
{
	if (str == NULL)
	{
		return 0;
	}
	if (*str == '\0')
	{
		return 0;
	}
	//空白字符
	while (isspace(*str))
	{
		str++;
	}
	int flag = 1;
	if (*str == '+')
	{
		flag = 1;
		str++;
	}
	else if (*str == '-')
	{
		flag = -1;
		str++;
	}
	//处理数字字符
	long long ret = 0;
	while (isdigit(*str))
	{
		ret = ret * 10 + flag*(*str - '0');
		if (ret<INT_MIN || ret>INT_MAX)
		{
			return 0;
		}
		str++;
	}
	if (*str == '\0')
	{
		status = VALID;
		return (int)ret;
	}
	else
	{
		return (int)ret;
	}
}

int main()
{
	int ret = my_atoi("123qqq");
	if(status==VALID)
		printf("合法的转换：%d\n", ret);
	else
		printf("不合法的转换：%d\n", ret);
	return 0;
}