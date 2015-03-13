#include <iostream>
#include <stdio.h>

using namespace std;

void get(int *a, int tail, int origin)
{
	*(a+tail) = origin;
}

void get(char *str, int tail, char s)
{
	*(str+tail) = s;
}

void sort(int *a,int tail)
{
	int i;
	int j;
	int temp;

	for(i=0; i<tail-1; i++)
	{
		for(j=i; j<tail; j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}


void sort(char *str,int tail)
{
	int i;
	int j;
	char temp;

	for(i=0; i<tail-1; i++)
	{
		for(j=i; j<tail; j++)
		{
			if(str[j] > str[j+1])
			{
				temp = str[j];
				str[j] = str[j+1];
				str[j+1] = temp;
			}
		}
	}
}

void myprint(int *a, int tail)
{
	int i;

	for(i=0; i<tail; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}

void myprint(char *str, int tail)
{
	int i;

	for(i=0; i<tail; i++)
	{
		cout << str[i] << " ";
	}
	cout << "\n";
}

int main()
{
	int array[80];
	char str[80];
	char buff[80];
	int temp;
	int array_tail = 0;
	int str_tail = 0;
	int i = 0;

	scanf("%s",buff);
//cout << "scanf is ok" << endl;

	while('\n' != buff[i])
	{
		if((buff[i] > '0') && (buff[i] < '9'))
		{
			temp = buff[i] - '0';
			get(array, array_tail, temp);
			array_tail++;
		}
		else
		{
			get(str, str_tail, buff[i]);
			str_tail++;
		}

		i++;
	}

	sort(array, array_tail);
	sort(str, str_tail);

	myprint(array, array_tail);
	myprint(str, str_tail);

	return 0;
}
