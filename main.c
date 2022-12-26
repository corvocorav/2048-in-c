#include <stdio.h>
#include<string.h>
#include <stdlib.h>



int disp(); int loopRight(); int loopLeft(); int loopUp(); int loopDown(); int sweep(int direction);
int tab[4][4] = {   {2,2,2,4},
                    {2,0,0,2},
                    {4,0,0,0},
                    {4,2,0,2}
              };
int main()
{
    char cmd[100];
    
    while(1==1)
    {

    system("clear");
    disp();
    scanf("%s" , &cmd);
    

    if(!(strcmp(cmd , "right")))
    {
        loopRight();
        sweep(1);
    }
    else if(!(strcmp(cmd , "left"))) 
    {
       loopLeft();
       sweep(2);
    }
    else if(!(strcmp(cmd , "up"))) 
    {
        loopUp();
        sweep(3);
    }
    else if(!(strcmp(cmd , "down"))) 
    {
        loopDown();
        sweep(4);
    }
    else  return 0; 
    
    //wait

    }
    
}
int loopRight()
{
	
    for(int x = 0; x< 4 ; x++)
    { 
	for (int y = 3; y >= 0; y--)
	{
		if (tab[x][y] != 0)
		{
			if (tab[x][y] == tab[x][y - 1] && y - 1 >= 0 && y-1 < 4)
			{
				tab[x][y] *= 2;
				tab[x][y - 1] = 0;
			}
			else if (tab[x][y] == tab[x][y - 2] && tab[x][y - 1] == 0 && y - 2 >= 0 && y-2 < 4)
			{
				tab[x][y] *= 2;
				tab[x][y - 2] = 0;
			}
			else if (tab[x][y] == tab[x][y - 3] && tab[x][y - 2] == 0 && tab[x][y - 1] == 0 && y - 3 >= 0 && y-3 < 4)
			{
				tab[x][y] *= 2;
				tab[x][y - 3] = 0;
			}
		}
	}
    }
	
}
int loopLeft()
{
	
    for(int x = 0; x< 4 ; x++)
    { 
	for (int y = 0; y <= 3; y++)
	{
		if (tab[x][y] != 0)
		{
			if (tab[x][y] == tab[x][y + 1] && y + 1 >= 0 && y+1 < 4)
			{
				tab[x][y] *= 2;//printf("\ninstance 1");
				tab[x][y + 1] = 0;
			}
			else if (tab[x][y] == tab[x][y + 2] && tab[x][y + 1] == 0 && y + 2 >= 0 && y+2 <4)
			{
				tab[x][y] *= 2;//printf("\ninstance 2");
				tab[x][y + 2] = 0;
			}
			else if (tab[x][y] == tab[x][y + 3] && tab[x][y + 2] == 0 && tab[x][y + 1] == 0 && y + 3 >= 0 && y+3 < 4)
			{
				tab[x][y] *= 2;//printf("\ninstance 3");
				tab[x][y + 3] = 0;
			}
		}
	}
    }
	
}
int loopUp()
{
    
    for(int y = 0 ; y < 4 ; y++)
    {
	for (int x = 0; x <= 3; x++)
	{
		if (tab[x][y] != 0)
		{
            
			if (tab[x][y] == tab[x+1][y] && x + 1 >= 0 && x+1<4)
			{   
				tab[x][y] *= 2;// printf("instance 1");
				tab[x+1][y] = 0;
			}
			else if (tab[x][y] == tab[x+2][y] && tab[x+1][y] == 0 && x + 2 >= 0 && x+2<4)
			{
				tab[x][y] *= 2; //printf("instance 2");
				tab[x+2][y] = 0;
			}
			else if (tab[x][y] == tab[x+3][y] && tab[x+2][y] == 0 && tab[x+1][y] == 0 && x + 3 >= 0 && x+3 <4)
			{
				tab[x][y] *= 2; //printf("instance 3");
				tab[x+3][y] = 0;
			}
		}
	}
    }
	
}
int loopDown()
{
    
    for(int y = 0 ; y < 4 ; y++)
    {
	for (int x = 3; x >= 0; x--)
	{
		if (tab[x][y] != 0)
		{
            
			if (tab[x][y] == tab[x-1][y] && x - 1 >= 0 && x-1 <4)
			{   
				tab[x][y] *= 2;// printf("instance 1");
				tab[x-1][y] = 0;
			}
			else if (tab[x][y] == tab[x-2][y] && tab[x-1][y] == 0 && x - 2 >= 0 && x-2 <4)
			{
				tab[x][y] *= 2; //printf("instance 2");
				tab[x-2][y] = 0;
			}
			else if (tab[x][y] == tab[x-3][y] && tab[x-2][y] == 0 && tab[x-1][y] == 0 && x - 3 >= 0 && x-3 <4)
			{
				tab[x][y] *= 2; //printf("instance 3");
				tab[x-3][y] = 0;
			}
		}
	}
    }
	
}
int disp()
{   printf("\n\n");    
    for(int x = 0 ; x<4 ; x++)
    {   printf("\n");
        for(int y = 0; y<4; y++)
        {
        printf("%d " , tab[x][y]);
        }
    }
}
int sweep(int direction)
{  // 
    for(int loop = 0 ; loop < 3 ; loop++)
    {
    switch(direction)
    {
        case 1: // right
        for(int x = 0 ; x<4 ; x++)
        {  
            for(int y = 0; y<4; y++)
            {
                if(tab[x][y] != 0 && tab[x][y+1] == 0 && y+1 < 4)
                {
                    tab[x][y+1] = tab[x][y];
                    tab[x][y] = 0;
                }
            }
        }
        break;

        case 2: // left
        for(int x = 0 ; x<4 ; x++)
        {  
            for(int y = 0; y<4; y++)
            {
                if(tab[x][y] != 0 && tab[x][y-1] == 0 && y-1 >= 0)
                {
                    tab[x][y-1] = tab[x][y];
                    tab[x][y] = 0;
                }
            }
        }
        break;
        case 3: // up
        for(int x = 0 ; x<4 ; x++)
        {  
            for(int y = 0; y<4; y++)
            {
                if(tab[x][y] != 0 && tab[x-1][y] == 0 && x-1 >= 0)
                {
                    tab[x-1][y] = tab[x][y];
                    tab[x][y] = 0;
                }
            }
        }
        break;
        case 4: // down
        for(int x = 0 ; x<4 ; x++)
        {  
            for(int y = 0; y<4; y++)
            {
                if(tab[x][y] != 0 && tab[x+1][y] == 0 && x+1 < 4)
                {
                    tab[x+1][y] = tab[x][y];
                    tab[x][y] = 0;
                }
            }
        }
        break;
    }
    }
 //   
}