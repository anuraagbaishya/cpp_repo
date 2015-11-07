#include<fstream>

int main()
{
	std::ifstream infile("Generate1.txt");
	int a,arr[100000],i=0,j;
	while(infile>>a)
    {
        arr[i]=a;
        i++;
    }
	for (i=0;i<99999;i++)
	{
		int small=i;
		for(j=i+1;j<100000;j++)
			if (arr[j]<arr[small])
				small=j;

		int temp=arr[i];
		arr[i]=arr[small];
		arr[small]=temp;
	}
}


