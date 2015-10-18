#include<stdio.h>
#include<stdlib.h>

struct Matrix
{
	int row;
	int col;
	int dir;
};
struct Sets
{
	int vert;
	int horiz;
};
int Pop(struct Matrix temp[],int count)
{	
	temp[count].dir+=1;
	if(count!=0||count!=1)
	{
		temp[count].row=NULL;
		temp[count].col=NULL;		
	}
	if(count!=0)
		count--;
	return count;
}
void main()
{
	FILE *fPtr;
	int num,c=0,etotal=1,rend=5,cend=5,dir=0;
	int nextrow,nextcol;
	int maze[7][7];
	int mark[7][7];
	struct Matrix stack[25];
	struct Sets move[8];
	move[0].vert=-1;
	move[0].horiz=0;
	move[1].vert=-1;
	move[1].horiz=1;
	move[2].vert=0;
	move[2].horiz=1;
	move[3].vert=1;
	move[3].horiz=1;
	move[4].vert=1;
	move[4].horiz=0;
	move[5].vert=1;
	move[5].horiz=-1;
	move[6].vert=0;
	move[6].horiz=-1;
	move[7].vert=-1;
	move[7].horiz=-1;
	stack[0].row=1;
	stack[0].col=1;
	stack[0].dir=2;

	for(int i=0;i<7;i++)
	{
		for(int j=0;j<7;j++)
			maze[i][j]=1;
	}
	for(int i=0;i<=7;i++)
	{
		for(int j=0;j<=7;j++)
		{
			if(i!=0 && j!=0 && j!=7 && i!=7)
				mark[i][j]=0;
			else if(i==7 || j==7)
				mark[i][j]=1;
			else
				mark[i][j]=1;
		}
	}	
	fPtr = fopen("maze.txt","r");
	for(int i=0;i<5;i++)
	{	
		for(int j=0;j<5;j++)
		{
			fscanf(fPtr,"%d",&num);
			if(num==0)
			{
				maze[i+1][j+1]=0;
			}
		}
	}	
	fclose(fPtr);	
	while(stack!=NULL)
	{
		
		while(stack[c].dir!=8)
		{
			nextrow=stack[c].row+move[stack[c].dir].vert;
			nextcol=stack[c].col+move[stack[c].dir].horiz;
			dir=++stack[c].dir;
			if(stack[c].row==rend && stack[c].col==cend)
			{
				printf("路徑 %d \n",etotal);
				printf("=======================================\n");
				for(int i=0;i<=c;i++)
				{		
					if(i!=0&&i<=c)
						printf(" --> ");
					printf("(%d,%d)",stack[i].row,stack[i].col);					
				}
				printf("\n");
				etotal++;
				if(etotal>0)
				{
					c=Pop(stack,c);					
					maze[rend][cend]=0;
					mark[rend][cend]=0;
				}
			} //是否到終點
			else if(maze[nextrow][nextcol]==0&&mark[nextrow][nextcol]==0)
			{				
				mark[nextrow][nextcol]=1;
				c++;
				stack[c].row=nextrow;
				stack[c].col=nextcol;
				stack[c].dir=0;
			}			
		}
		if(c==1)
		{
			maze[stack[c].row][stack[c].col]=1;
			mark[stack[c].row][stack[c].col]=1;
		}
		else
		{
			maze[stack[c].row][stack[c].col]=0;
			mark[stack[c].row][stack[c].col]=0;
		}
		c=Pop(stack,c);
		if(stack[0].col==NULL)
			system("pause");
	}
}