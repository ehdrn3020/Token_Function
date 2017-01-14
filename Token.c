#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{
	char name[10];
	int number;
}STU;
void bin(int num);                     
//Functions to change the number of the table to binary
int String(char arr[],char st[]);      
//A function that finds a string in a table from a char type character
void Fileter(char token[],STU st[]);   
//filtering Char type or number type, load to array
void FuncToken(char *arr);             
//Functions that define tokens

void bin(int num)
 { 
  char binary[50] = {"\0", }; 
  int i, cnt = 0; 
  
  while (num > 0)
  {  
   binary[cnt++] = (num% 2) + '0';  
   num/= 2;  
  } 
  binary[cnt] = '\0';
  
  for(i = cnt-1; i >= 0; i--)  
   printf("%c", binary[i]);
  
  printf("\n"); 
 }
int String(char arr[],char st[])
{
	int len1,len2;
	int i,j1,j2=0;
	len1=strlen(arr);
	len2=strlen(st);

	for(i=0;i<=len1;i++)
	    if(arr[i]==st[j2])
		{
			j2++;
			continue;
		}

	if((j2-1)==len2)
		return 1;
	else
		return 0;
}
void Fileter(char token[],STU st[])
{
	char arr[10][10]={NULL,};
	int i=0,j=0,k=0,s,n=1,l;
	int num=0;
	char ch[15];

	while(token[i]!='\0')
	{
		if('0'<=token[i]&& token[i]<='9')
		{
		    while('0'<=token[i]&& token[i]<='9')
		    {
			  arr[j][k++]=token[i++];
			 }
		k=0;j++;
		}

        if(('a'<=token[i]&&token[i]<='z')||('A'<=token[i]&&token[i]<='Z'))
		{
			while(('a'<=token[i]&&token[i]<='z')||('A'<=token[i]&&token[i]<='Z'))
		    {
			  arr[j][k++]=token[i++];
			}
		k=0;j++;
		}
	}
	
	for(k=0;k<j;k++)
	{
	if(('a'<=arr[k][0]&&arr[k][0]<='z')||('A'<=arr[k][0]&&arr[k][0]<='Z'))
		{
			for(l=0;l<20;l++)
					if(String(arr[k],st[l].name))
					    bin(st[l].number);
		}
        if('0'<=arr[k][0]&& arr[k][0]<='9')
		{
			for(s=9;0<=s;s--)
			{
				if(arr[k][s]<='\0')
					continue;
				else
				{num=atoi(arr[k]);}
	        }
			printf("0x%x\n",num);
			num=0;n=1;
        }
	}
}
void FuncToken(char *arr)
{
 int i=0;
 char enter[]={"`!@#$%^&*()_+-=[];,./<>?: \' \" \t \b \" \" |" };
 int count=1;
 char *token;
 
 FILE* fp = fopen("input.txt", "rt");
 STU student[20];
 for (i = 0; i < 20; i++){
		fscanf(fp, "%s %d\n", &student[i].name, &student[i].number);
	}//enter the value to table
 token = strtok(arr,enter);
 while (token != '\0')
 {
   printf("[%d]\n",count);
  Fileter(token,student);
  printf("\n");
  token = strtok('\0', enter);
  count++;
 }
 count -= 1;
 printf("-----------------------------\n");
 printf("Output a total of %d tokens.\n\n", count);
}
	
int main(void)
{
 char arr[50];
 int i;
 
 printf("Input String:");
 gets(arr);
 FuncToken(arr);

 return 0;
}
