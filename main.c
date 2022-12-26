#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>

// see https://medium.com/swlh/i-made-a-game-in-c-run-in-a-web-browser-and-so-can-you-2911b9fe2368

int disp(); int loopRight(); int loopLeft(); int loopUp(); int loopDown(); int sweep(int direction); int clear(); //int spawn(int x , int y,int spot);
int tab[4][4] = {   {2,0,2,0},
                    {0,0,0,0},
                    {0,0,0,0},
                    {0,0,0,0}
              };
int main()
{
    char cmd[100];
    
    while(1==1)
    {

    system("cls");
    disp();
    scanf("%s" , &cmd);
    

    if(!(strcmp(cmd , "d")))
    {
        loopRight();
        sweep(1);
    }
    else if(!(strcmp(cmd , "q"))) 
    {
       loopLeft();
       sweep(2);
    }
    else if(!(strcmp(cmd , "z"))) 
    {
        loopUp();
        sweep(3);
    }
    else if(!(strcmp(cmd , "s"))) 
    {
        loopDown();
        sweep(4);
    }
    else if(!(strcmp(cmd , "exit"))) return 0; 
    
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
{
    printf("D : swipe right Q swipe left Z swipe up S swipe down");
    printf("\n\n"); 
    printf("\n_________________________\n");
    for(int x = 0 ; x<4 ; x++)
    {  
	 
        for(int y = 0; y<4; y++)
        {
            //see number of spaces in it
        if(tab[x][y] == 0)
        {
        	printf("|     " , tab[x][y]);
		}
        else if((tab[x][y]/10) == 0)
        {
            printf("|  %d  " , tab[x][y]);
        }
        else if((tab[x][y]/100) == 0)
        {
            printf("| %d  " , tab[x][y]);
        }
        else if((tab[x][y]/1000) == 0)
        {
            printf("|%d " , tab[x][y]);
        }
        }
        printf("|\n_________________________\n");
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
 clear();
}

int clear()
{   
    int Xs[16]; int Ys[16];
    

    int emptySpots = 0;
    int spawnCoords = 0;

    for(int x = 0 ; x<4 ; x++)
    {   
        for(int y = 0; y<4; y++)
        {

        if(tab[x][y] == 0) 
        {
        //    printf("\n empty %d " , tab[x][y]);
            
            Xs[emptySpots] = x;
            Ys[emptySpots] = y;
            emptySpots += 1;
      //      printf("\n empty at (%d,%d) number %d" , Xs[emptySpots],Ys[emptySpots],emptySpots);
           // spawn(x,y,emptySpots);
        }

        }
        
    }
    if(emptySpots > 0)
    {
    //    printf("\nthere is %d empty places" , emptySpots);
        spawnCoords = (rand() % (emptySpots));
        spawnCoords = (rand() % (emptySpots));
        
    //    printf("\nrand is %d" , spawnCoords);
        //here spawn a num
    //    printf("spawning at (%d,%d)" ,Xs[spawnCoords],Ys[spawnCoords]);
        tab[Xs[spawnCoords]][Ys[spawnCoords]] = 2;
    }
    else printf("\n ####GAME OVER#####");
}
/*
int spawn(int x , int y,int spot)
{   

    int Xs[16] ; int Ys[16];
    Xs[spot] = x;
    Ys[spot] = y;
    
    printf("\n empty at (%d,%d) number %d" , Xs[spot],Ys[spot],spot);
  //  printf("\n empty at ( %d , %d ) number %d" , x,y, spot);
    

}*/
