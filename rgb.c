#include<stdio.h>

void rgbtohsv(float R1,float G1,float B1)
{
float r,g,b,cmax,cmin,delta,S,V,x=6;
int H;
r=R1/255.0;
g=G1/255.0;
b=B1/255.0;

//To find the cmax value
if(r>=g && r>=b)
{
cmax=r;
}
if(g>=r && g>=b)
{
cmax=g;
}
if(b>=r && b>=g)
{
cmax=b;
}

//To find the cmin value
if(r<=g && r<=b)
{
cmin=r;
}
if(g<=r && g<=b)
{
cmin=g;
}
if(b<=r && b<=g)
{
cmin=b;
}

//Calculation of the delta;
delta=cmax-cmin;

//Hue calculation
if(delta==0)
{
H=0;
}
else
{
if(cmax==r)
{
H=60*((g-b)/delta);
H=H%6;
} 
if(cmax==g)
{
H=60*((b-r)/delta +2);
}
if(cmax==b)
{
H=60*((r-g)/delta +4);
}
}

//Saturation calculation;

if(cmax==0)
{
S=0;
}
else
{
S=(delta/cmax)*100;//To find the percentage has multiplyied by the 100;
}

//Value calcluation
V=cmax*100; //Multiplying by 100 to find the percentage

printf("\n\nHSV COORDINATES......\n\n");
printf("H = %d°\nS = %0.2f%%\nV = %0.2f%%",H,S,V);
}

int main()
{
float R,G,B;
printf("\n\t\tEnter the rgb coordinate\n");
scanf("%f%f%f",&R,&G,&B);
rgbtohsv(R,G,B);
}
