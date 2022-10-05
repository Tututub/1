#include<stdio.h>

void input(int num[],char name[][8],int length)
{
//输入姓名与职工号  
	int c;
	for(c=0;c<length;c++){
		printf("请输入职工姓名:");
		scanf("%7s",&name[c]);
	    printf("请输入该职工的职工号:");
	    scanf("%d",&num[c]);
	    printf("\n");
	}
}

void sort(int num[],char name[][8],char m[],int length)
{
//选择排序 	
	int c,j,l;
	for(c=0;c<length;c++)
	{
		int k = c;
		for(j=k+1;j<length;j++)
		{
			if(num[j]<num[k])
			{
				int k = j;
				int temp = num[k];
				num[k]=num[c];
				num[c]=temp;
				for(l=0;l<8;l++)
				{
					m[l] = name[k][l];
					name[k][l] = name[c][l];
					name[c][l] = m[l];
				}
			}
		}
		
	}
}	

int main()
{		
	int c,l,n;
	
	printf("需要排序的人数:");
	scanf("%d",&n);
	printf("\n");
	
	int num[n];
	char M[8];
	char name[n][8];
	
	int length=sizeof(num)/sizeof(num[0]);
	
	input(num,name,length);
	sort(num,name,M,length);
	//打印检验 
	for(c=0;c<length;c++)
	{
		printf("%d ",num[c]);
		for(l=0;l<8;l++)
		{
			printf("%c",name[c][l]);
		}
		printf("\n");
	}
	return 0;
}
