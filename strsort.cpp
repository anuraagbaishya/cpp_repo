#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int strcomp(char str1[80],char str2[80])
{
	int count=0;
	int minlen=strlen(str1)<strlen(str2)?strlen(str1):strlen(str2);
	for(int i=0;i<minlen;i++)
	{
		if(str1[i]==str2[i])
			continue;
		else
        {
            count=((int)str1[i]-(int)str2[i]);
            break;
        }
	}
    return count;
}
void strcopy(char *target, char *source)
{
   while (*source) {
      *target = *source;
      source++;
      target++;
   }
   *target = '\0';
}
int main()
{
    char str[10][80],temp[80];
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
        gets(str[i]);
    for(int k=0;k<=n;k++)
    {
        for(int j=0;j<=n;j++)
        {
            if(strcomp(str[j],str[j+1])>0)
            {
                strcopy(temp,str[j]);
                strcopy(str[j],str[j+1]);
                strcopy(str[j+1],temp);
            }
        }
    }
    for(int i=1;i<=n;i++)
        puts(str[i+1]);
}

