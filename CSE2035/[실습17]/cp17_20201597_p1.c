#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
	double x;
	double y;
	double z;
	double r;
} SPHERE;

double Distance(SPHERE a, SPHERE b){
	double temp;
	temp = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
	return temp;
}

double CrossSectionArea(SPHERE a, SPHERE b){
	double temp;
	temp = 3.14*(a.r*a.r+b.r*b.r);
	return temp;
}

double SurfaceArea(SPHERE a, SPHERE b){
	double temp;
	temp = 4*3.14*(a.r*a.r+b.r*b.r);
	return temp;
}

double Volume(SPHERE a, SPHERE b){
	double temp;
	temp = 4*3.14*(a.r*a.r*a.r+b.r*b.r*b.r)/3;
	return temp;
}

int main(){
	SPHERE* spr;
	spr = (SPHERE*)malloc(sizeof(SPHERE)*2);
	printf("Type First Sphere Coordinate : ");
	scanf("%lf %lf %lf",&spr[0].x,&spr[0].y,&spr[0].z);
	printf("Type First Sphere Radius : ");
	scanf("%lf",&spr[0].r);
	
	printf("Type Second Sphere Coordinate : ");
	scanf("%lf %lf %lf",&spr[1].x,&spr[1].y,&spr[1].z);
	printf("Type Second Sphere Radius : ");
	scanf("%lf",&spr[1].r);
	double dis;
	dis = Distance(spr[0],spr[1]);
	double result;
	if ((dis==(spr[0].r+spr[1].r)) || (dis==fabs(spr[0].r-spr[1].r))){
		result = SurfaceArea(spr[0],spr[1]);
		printf("Sum of Surface Area : %.2lf\n",result);
	}
	if (dis>(spr[0].r+spr[1].r)){
		result = CrossSectionArea(spr[0],spr[1]);
		printf("Sum of Cross Section Area : %.2lf\n",result);
	}
	if (dis<(spr[0].r+spr[1].r)){
		result = Volume(spr[0],spr[1]);
		printf("Sum of Volume : %.2lf\n",result);
	}
	return 0;
}
