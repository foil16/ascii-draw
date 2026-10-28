#include <stdio.h>
#include <math.h>
#include <string.h>
	
int main(void){
	char* b = "b";
	int max = 30;
	char endw[] = "END";
	char space[] = " ";
	char gridw[] = "GRID";
	char displw[] = "DISPLAY";
	char sgnw[] = "CHAR";
	char circlew[] = "CIRCLE";
	char f1[15];
	char f2[15];
	char newline[] = "\n";
	char rectw[] = "RECTANGLE";
	char linew[] = "LINE";
	int empty = 0;
	int r = 0;
	int i = 0;
	int t = 0;
	char star[] = "*";
	char input[30];
	char grid[1000][1000];		
	int v1,canvas;
	int v2;
	int x0,y0,x1,y1,y2,n1;
	int c;
	float m;
	int p=0;
	int lo=0;
	float ca1,ca2,ca3;
//We keep asking for input until the END command is input
	while (strcmp (input,endw) != 0)
	{
	fgets(input,max,stdin);
	input[strcspn(input,newline)] = empty;
	sscanf(star,"%c",star);	
	char* command = strtok(input," ");		
	if (strcmp(command,sgnw) == 0)//If we get the sign command we change the sign
	{sscanf(strtok(NULL," "),"%c", star);}
	if (strcmp(command,gridw) == 0)//If we get the grid command we set the grid size and initialize it

		{
		sscanf(strtok(NULL," "),"%d", &v1);
		sscanf(strtok(NULL," "),"%d", &v2);
		canvas = v1 * v2;
		for(i=0;i<v2;i++)
		
		{for (t=1;t<=v1;t++)
			{grid[i][t]=*space;
				;
			}
		};	
		
	
		

	while (strcmp (input,endw) != 0)		//start a new while loop since we want to have commands exclusive to when you have already set your grid
	{fgets(input,max,stdin);
		input[strcspn(input,newline)] = empty;
	
	char* command = strtok(input," ");
	if (strcmp(command, circlew) == 0)
	{sscanf(strtok(NULL," "),"%d,%d",&x0,&y0);
	sscanf(strtok(NULL," "),"%d",&r);
	grid[(v2-y0)-r][x0]=*star;
	grid[(v2-y0)+r][x0]=*star;
	grid[v2-y0][x0-r]=*star;
	grid[v2-y0][x0+r]=*star;
	int vax,vay; 
	vay = y0+r;	
	
//Here I check which of the three options is the closest to the radius, since we want our points to be as close as possible to the radius away from the center.
//First I calculate the distance then I subtract it to 1 if its greater than 1 and subtract 1 from it if its higher than 1 then compare those values
//Depending on which is optimal that is the one where the character will be drawn, I used 4 loops for the 4 quadrants
	for(i=x0;i<=x0+r;i++){
	vax=i;	
	ca1=(float)sqrt(pow((vax-x0+1),2)+pow((vay-y0),2));
	ca2=(float)sqrt(pow((vax-x0+1),2)+pow((vay-y0-1),2));
	ca3=(float)sqrt(pow((vax-x0),2)+pow((vay-y0-1),2));
	float ca12, ca22, ca32;
	ca12=r/ca1;
	ca22=r/ca2;
	ca32=r/ca3;
	if ((float)ca12 < 1)
	{ca12=1-ca12;}
	if ((float)ca22 < 1)
	{ca22=1-ca22;}
	if ((float)ca32 < 1)
	{ca32=1-ca32;}
	if ((float)ca12 >= 1)
	{ca12=ca12-1;}
	if ((float)ca22 >= 1)
	{ca22=ca22-1;}
	if ((float)ca32 >= 1)
	{ca32=ca32-1;}

	if ((float) ca12 < ca22 && (float) ca12 < ca32 && vay>y0+1)
	{
	grid[v2-vay][vax+1]=*star;}
	if ((float) ca22 < ca12 && (float) ca22 < ca32 && vay>y0+1)
	{vay=vay-1;
	
	grid[v2-vay][vax+1]=*star;}
	if ((float) ca32 < ca12 && (float) ca32 < ca22 && vay>y0+1)
	{vay=vay-1;
	grid[v2-vay][vax]=*star;
	}
	}
	vax=x0;
	vay=y0-r-1;	
	 for(i=x0;i<=x0+r;i++){
        vax=i;
        ca1=(float)sqrt(pow((vax-x0+1),2)+pow((vay-y0),2));
        ca2=(float)sqrt(pow((vax-x0+1),2)+pow((vay-y0+1),2));
        ca3=(float)sqrt(pow((vax-x0),2)+pow((vay-y0)+1,2));
        float ca12, ca22, ca32;
        ca12=r/ca1;
        ca22=r/ca2;
        ca32=r/ca3;
        if ((float)ca12 < 1)
        {ca12=1-ca12;}
        if ((float)ca22 < 1)
        {ca22=1-ca22;}
        if ((float)ca32 < 1)
        {ca32=1-ca32;}
        if ((float)ca12 >= 1)
        {ca12=ca12-1;}
        if ((float)ca22 >= 1)
        {ca22=ca22-1;}
        if ((float)ca32 >= 1)
        {ca32=ca32-1;}

        if ((float) ca12 < ca22 && (float) ca12 < ca32 && vay<y0+1)
        {
        grid[v2-vay][vax+1]=*star;}
        if ((float) ca22 < ca12 && (float) ca22 < ca32 && vay<y0+1)
        {vay=vay+1;

        grid[v2-vay][vax+1]=*star;}
        if ((float) ca32 < ca12 && (float) ca32 < ca22 && vay<y0+1)
        {vay=vay+1;
        grid[v2-vay][vax]=*star;
        }
        }
	vax=x0;
	vay=y0+r;
	 for(i=x0;i>=x0-r;i--){
        vax=i;
        ca1=(float)sqrt(pow((vax-x0-1),2)+pow((vay-y0),2));
        ca2=(float)sqrt(pow((vax-x0-1),2)+pow((vay-y0-1),2));
        ca3=(float)sqrt(pow((vax-x0),2)+pow((vay-y0)-1,2));
        float ca12, ca22, ca32;
        ca12=r/ca1;
        ca22=r/ca2;
        ca32=r/ca3;
        if ((float)ca12 < 1)
        {ca12=1-ca12;}
        if ((float)ca22 < 1)
        {ca22=1-ca22;}
        if ((float)ca32 < 1)
        {ca32=1-ca32;}
        if ((float)ca12 >= 1)
        {ca12=ca12-1;}
        if ((float)ca22 >= 1)
        {ca22=ca22-1;}
        if ((float)ca32 >= 1)
        {ca32=ca32-1;}

        if ((float) ca12 < ca22 && (float) ca12 < ca32 && vay>y0+1)
        {
        grid[v2-vay][vax-1]=*star;}
        if ((float) ca22 < ca12 && (float) ca22 < ca32 && vay>y0+1)
        {vay=vay-1;

        grid[v2-vay][vax-1]=*star;}
        if ((float) ca32 < ca12 && (float) ca32 < ca22 && vay>y0+1)
        {vay=vay-1;
        grid[v2-vay][vax]=*star;
        }
        }
	vax=x0;
	vay=y0-r-1;
	for(i=x0;i>=x0-r;i--){
        vax=i;
        ca1=(float)sqrt(pow((vax-x0-1),2)+pow((vay-y0),2));
        ca2=(float)sqrt(pow((vax-x0-1),2)+pow((vay-y0+1),2));
        ca3=(float)sqrt(pow((vax-x0),2)+pow((vay-y0)+1,2));
        float ca12, ca22, ca32;
        ca12=r/ca1;
        ca22=r/ca2;
        ca32=r/ca3;
        if ((float)ca12 < 1)
        {ca12=1-ca12;}
        if ((float)ca22 < 1)
        {ca22=1-ca22;}
        if ((float)ca32 < 1)
        {ca32=1-ca32;}
        if ((float)ca12 >= 1)
        {ca12=ca12-1;}
        if ((float)ca22 >= 1)
        {ca22=ca22-1;}
        if ((float)ca32 >= 1)
        {ca32=ca32-1;}

        if ((float) ca12 < ca22 && (float) ca12 < ca32 && vay<y0+1)
        {
        grid[v2-vay][vax-1]=*star;}
        if ((float) ca22 < ca12 && (float) ca22 < ca32 && vay<y0+1)
        {vay=vay+1;

        grid[v2-vay][vax-1]=*star;}
        if ((float) ca32 < ca12 && (float) ca32 < ca22 && vay<y0+1)
        {vay=vay+1;
        grid[v2-vay][vax]=*star;
        }
        }
	}
	//sign command again
	if (strcmp(command, sgnw) == 0)
	{sscanf(strtok(NULL," "),"%c", star);
	
			
	}
	// rectangle command we set the corners and use for loops to set every point between those points to the character
	if (strcmp(command, rectw) == 0)
	{
	
	sscanf(strtok(NULL," "),"%d,%d",&x0,&y0);
	sscanf(strtok(NULL," "),"%d,%d",&x1,&y1);



	y0 = v2- y0;
	y1 = v2-y1;
	
	for (i=x0;i<=x1;i++)
	{grid[y0][i]=*star;
	grid[y1][i]=*star;};
	for (t=y1;t>=y0;t--)
	{grid[t][x0] = *star;
	grid[t][x1]=*star;}}	

	// we find the m and c of mx+c=y and using that we set the coordinates and set them to the character.
	if (strcmp(command,linew) == 0)
	{sscanf(strtok(NULL," "),"%d,%d",&x0,&y0);
	sscanf(strtok(NULL," "),"%d,%d",&x1,&y1);	
	float m = (float) (y1-y0)/(x1-x0);	
	float c = (float) y1 - m*x1;
	grid[v2-y0][x0]=*star;
	grid[v2-y1][x1]=*star;
	int dist = (pow(x1-x0,2))+(pow(y1-y0,2));
	dist = sqrt(dist);
	if (x0 == x1) {	
	if (y0 > y1)
	{for (i=v2-y0;i<=v2-y1;i++)
		{grid[i][x0]=*star;}
	;}
	if (y1 > y0)
	{for (i=y0;i<=y1;i++)
		{grid[i][x1]=*star;}
	;}}
		
	if (x0<x1)
	{for (i=x0;i<=x1;i++){
	float y2 = (float)m*i+c;
	float y3 = (float)(m*(i+1))+c;
	int r = round(y2);
	int r2 = round(y3);
	if ((r-t) >= 1)
	{for (p=(v2-r2),lo=0;p<=(v2-r);p++,lo++)
		{grid[v2-r+lo][i-1]=*star;
		grid[v2-r][i]=*star;
		}}
		
	if ((t-r) >1)
	{for (p=(v2-r2),lo=0;p>=(v2-r);p--,lo--){
							grid[v2-r+lo][i]=*star;
						grid[v2-r][i]=*star;}
		;}	
			     		     
	


		else {grid[v2-r][i]=*star;}
	
	t=r;	
			     }	}
			  		
	if (x1<x0)
	{for(i=x1;i<=x0;i++){
	float y2= (float)m*i+c;
	float y3= (float)(m*(i+1))+c;
	int r = round(y2);
	int r2 = round(y3);
	if((r-t)>=1){
	for (p=(v2-r2),lo=0;p<=(v2-r);p++,lo++)
	{grid[v2-r+lo][i-1] =*star;
		grid[v2-r][i]=*star;
	}}
	
	if ((t-r)>1){
	for (p=(v2-r2),lo=0;p>=(v2-r);p--,lo--)
	{grid[v2-r+lo][i] = *star;
	grid[v2-r][i]=*star;}
	}
	
	

	else
	{grid[v2-r][i]=*star;}
	t=r;
			    };}	
			     }
		
	//Display command we go through each element of the grid that was initialized and print them skipping a line once we hit the end of a row.
	
	if (strcmp(command, displw) == 0)
	{
	for (i=0;i<=v2;i++)
	
	{for (t=0;t<=v1;t++)
	 	
		{if (t == 0 && i != (v2)) {printf("%d",(v2-i-1)%10);}
			
			else {if (i == v2 && t != 0) {printf("%d",(t-1)%10);}
				 else {if (i == v2 && t == 0){printf(" ");}
					 else {printf("%c",grid[i][t]);};};};
	
	};
	printf("\n");
		}	
	}	
			
				
		
			
	}
		}
	
}	


	
}
