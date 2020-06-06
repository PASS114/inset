#include <stdio.h>
#include <stdlib.h>
#define LINE 15

void draw(int arr[LINE][LINE]);
int check(int arr[LINE][LINE],int x,int y);
int win(int arr[LINE][LINE]);

void draw(int arr[LINE][LINE])
{
	int i, j;

	printf("  1 2 3 4 5 6 7 8 9 A B C D E F\n");
	
	for(i = 0; i < LINE; i++)
	{
		printf("%X", i + 1);
		for(j = 0; j < LINE; j++)
		{
			switch(arr[i][j])
			{
				case 0 : printf(" +"); break;
				case 1 : printf(" O"); break;
				case 2 : printf(" X"); break;
			}
		}
		printf("\n");
	}
}

int check(int arr[LINE][LINE],int x,int y)
{	
  
	if(x>=1&&x<=LINE&&y>=1&&y<=LINE)
	{
		if(arr[x-1][y-1]!=0){
			return 0;
		}
		else return 1;
	}
	else if(x<1||x>LINE||y<1||y>LINE)
	{
			return 0;
	}
}

int win(int arr[LINE][LINE])
{	
	int i,j;
	for(i=0;i < LINE; i++)
	{
		for(j = 0; j < LINE-4; j++){
	
			if(arr[i][j]==arr[i+1][j+1]&&
				arr[i+1][j+1]==arr[i+2][j+2]&&
			    arr[i+2][j+2]==arr[i+3][j+3]&&
			    arr[i+3][j+3]==arr[i+4][j+4]&&
				arr[i][j]!=0)                   //向右倾斜的斜线上连成五子
				{
					return arr[i][j];
				}
			else if(arr[i][j]==arr[i-1][j+1]&&
	    		     arr[i-1][j+1]==arr[i-2][j+2]&&
					 arr[i-2][j+2]==arr[i-3][j+3]&&
					 arr[i-3][j+3]==arr[i-4][j+4]&&
					 arr[i][j]!=0)              //向左倾斜的斜线上连成五子
					 {
					     return arr[i][j];
					 }
			else if(arr[i][j]==arr[i][j+1]&&
	   		    	 arr[i][j+1]==arr[i][j+2]&&
					 arr[i][j+2]==arr[i][j+3]&&
					 arr[i][j+3]==arr[i][j+4]&&
					 arr[i][j]!=0)              //横线上连成五子
					 {
					 	return arr[i][j];
					 }                        
			else if(arr[i][j]==arr[i+1][j]&&
	    			 arr[i+1][j]==arr[i+2][j]&&
					 arr[i+2][j]==arr[i+3][j]&&
					 arr[i+3][j]==arr[i+4][j]&&
					 arr[i][j]!=0)              //竖线上连成五子
					 {
					 	return arr[i][j];
					 }
			}
	}
}
int main(void)
{
	int arr[LINE][LINE] = {0};//用于存储五子棋的棋盘
	int x = 0, y = 0;//用于录入下棋的坐标
	int flag = 1;//flag标记玩家
	int a = 0;//存放win()的返回值
	int b = 0;//存放check的返回值
	do
	{
	 	system("clear");
		draw(arr);//通过draw函数画棋盘
	    printf("Player %d > ", flag);
		scanf("%d%d", &x, &y);
		check(arr,x,y);//判断下棋的位置是否是重复位置或者下出棋盘
		b =check(arr,x,y);
		if(b==0){	
			printf("Please play chess again.");
			continue;
		}
		arr[x - 1][y - 1] = flag;
		win(arr);//判断是否能赢
		a =win(arr);
		if(a==1)	printf("Player1  win.");
		else if(a==2)	printf("Player2 win.");
		
		flag ^= 3;
	}while(1);

	return 0;
}
