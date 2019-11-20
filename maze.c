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

        if (i == fy && j == fx) { 
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
    int maze_edit[N][N];
    
    int maze[N][N] = { 
		{ 1, 0, 1, 1, 1 }, 
		{ 1, 1, 1, 0, 1 }, 
		{ 0, 0, 0, 1, 1 }, 
		{ 1, 1, 1, 1, 0 },
        { 0, 0, 0, 1, 1 } 
	};

    printf("------------------------RAT MAZE------------------------\n");
    printf("\n1.Use the pre-defined Maze");
    printf("\n2.Initialize your own maze(maze has to be 30 x 30)\n");
    int choice;
    scanf("%d",&choice);
    if(choice == 1)
    {
        printf("The maze which is initialized is as follows\n");
        print(maze);
        printf("Enter the destination co-ordinates(first X then Y\n");
        scanf("%d%d",&fx,&fy);
        printf("\n");
        if(fx < 0 || fx > 29){
            printf("Invalid Co-ordinates\n");
            printf("Exiting.............");
            return 0;
        }
        else if(fy < 0 || fy > 29){
            printf("Invalid Co-ordinates\n");
            printf("Exiting.............");
            return 0;
        }
        else
        {
            printf("Processing..............\n");
            if(isRechable(maze)){
                printf("Path Possible");
                print(sol);
                printf("\nThe path that has to be followed by the rat is given by 0's\n");
            }
            else
            {
                printf("Path not possible");
            }
        }
        
    }
    else if(choice==2)
    {
        printf("\nEnter the maze one value at a time\n");
        for(int k=0;k<N;k++)
        {
            for(int l=0;l<N;l++)
            {
                scanf("%d",maze_edit[k][l]);
            }
        }
        printf("The maze which is initialized is as follows\n");
        print(maze);
        printf("Enter the destination co-ordinates(first X then Y\n");
        scanf("%d%d",&fx,&fy);
        printf("\n");
        if(fx < 0 || fx > 29){
            printf("Invalid Co-ordinates\n");
            printf("Exiting.............");
            return 0;
        }
        else if(fy < 0 || fy > 29){
            printf("Invalid Co-ordinates\n");
            printf("Exiting.............");
            return 0;
        }
        else
        {
            printf("Processing..............\n");
            if(isRechable(maze_edit)){
                printf("Path Possible");
                print(sol);
                printf("\nThe path that has to be followed by the rat is given by 0's\n");
            }
            else
            {
                printf("Path not possible");
            }
        }

    }
    else
    {
        return 0;
    }
    

    return 0;
}
