#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 5
typedef struct node{
    int x,y,dir;
}node;

// maze of n*m matrix 
int n = N, m = N; 
int fx, fy; 
int sol[N][N] ={ 
		{ 1, 1, 1, 1, 1 }, 
		{ 1, 1, 1, 1, 1 }, 
		{ 1, 1, 1, 1, 1 }, 
		{ 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1 }, 
	};
node stack[1000];
int top = -1;

int isempty()
{
    return(top==-1);
}

void push(node id)
{
    stack[++top] = id;
    return;
}

void pop()
{
    top--;
    return;
}

node peek(){
    return(stack[top]);
}




int isRechable(int maze[N][N])
{
    int i = 0,j = 0;
    sol[i][j] = 0;
    node temp = {i,j,0};
    push(temp);
    while(!isempty())
    {
        temp = peek();
        int d = temp.dir;
        i = temp.x;
        j = temp.y;

        temp.dir++;
        pop();
        push(temp);

        if (i == fx && j == fy) { 
			return 1; 
		} 

        if(d==0){
            if (i - 1 >= 0 && maze[i - 1][j] && sol[i - 1][j]) { 
				node temp1 = {i - 1, j, 0}; 
				sol[i - 1][j] = 0; 
				push(temp1);
			} 
        }

        else if (d == 1) { 
			if (j - 1 >= 0 && maze[i][j - 1] && sol[i][j - 1]) { 
				node temp1 = {i, j - 1, 0}; 
				sol[i][j - 1] = 0; 
				push(temp1); 
			} 
		} 

        else if (d == 2) { 
			if (i + 1 < n && maze[i + 1][j] && sol[i + 1][j]) { 
				node temp1 = {i + 1, j, 0}; 
				sol[i + 1][j] = 0; 
				push(temp1); 
			} 
		} 

        else if (d == 3) { 
			if (j + 1 < m && maze[i][j + 1] && sol[i][j + 1]) { 
				node temp1 = {i, j + 1, 0}; 
				sol[i][j + 1] = 0; 
				push(temp1); 
			}
		}

        else { 
			sol[temp.x][temp.y] = 1; 
			pop(); 
		}
    }
    return 0;
}

void print(int vis[N][N])
{
    printf("\n");
    for(int i=0 ;i<N ;i++)
    {
        for(int j=0; j<N; j++)
        {
            printf("%d ",vis[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    //memset(sol,1,sizeof(sol));
    int maze[N][N] = { 
		{ 1, 0, 1, 1, 1 }, 
		{ 1, 1, 1, 0, 1 }, 
		{ 0, 0, 0, 1, 1 }, 
		{ 1, 1, 1, 1, 0 },
        { 0, 0, 0, 1, 1 } 
	};

    fx = 3; 
	fy = 3; 
    
    if(isRechable(maze)){
        printf("Path Possible");
        print(sol);
    }
    else
    {
        printf("Path not possible");
    }

    return 0;
}
