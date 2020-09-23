#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int h,m,s,ms,v,numero,ttotal; 
    float t; 
} Piloto;

int main(){
	Piloto piloto[20];
	Piloto aux[1];
//	int h[10], m[10], s[10], ms[10], v[10],i,j,piloto[10];
	int i, j;
	float d=4309;
	srand( (unsigned)time(NULL) );
	for (i=0;i<20;i++){
			piloto[i].h=0;
			piloto[i].m=0;
			piloto[i].s=0;
			piloto[i].ms=0;
			piloto[i].v=0;
			piloto[i].t=0;
			piloto[i].ttotal=0;
			piloto[i].numero = 100+i;
		}
	for (j=0;j<20;j++){
		printf("\nVolta %d \n\n",j+1);
		for(i=0;i<20;i++){
			piloto[i].v=222+(rand() % 10);
			piloto[i].t+= (d/piloto[i].v)*3600;
			piloto[i].ttotal+=piloto[i].t;
			while(piloto[i].t>=1000){
				piloto[i].t-=1000;
				piloto[i].ms=piloto[i].t;
				piloto[i].s++;
			};
			while(piloto[i].s>=60){
			piloto[i].s-=60;
			piloto[i].m++;
			};
			while(piloto[i].m>=60){
				piloto[i].m-=60;
				piloto[i].h++;
			};
			printf("%d %d h . %d m . %d s . %d ms %d  Total = %d\n",piloto[i].numero, piloto[i].h, piloto[i].m, piloto[i].s, piloto[i].ms, piloto[i].v, piloto[i].ttotal);
		}
		printf ("\n\n");
	}
	
	for (j=0;j<20;j++){
		for (i=j+1;i<20;i++){
			if(piloto[j].ttotal>piloto[i].ttotal){
				aux[0].ttotal = piloto[j].ttotal;
				aux[0].h = piloto[j].h;
				aux[0].m = piloto[j].m;
				aux[0].ms = piloto[j].ms;
				aux[0].numero = piloto[j].numero;
				aux[0].s = piloto[j].s;
				aux[0].t = piloto[j].t;
				aux[0].v = piloto[j].v;
				piloto[j].ttotal = piloto[i].ttotal;
				piloto[j].h = piloto[i].h;
				piloto[j].m = piloto[i].m;
				piloto[j].ms = piloto[i].ms;
				piloto[j].numero = piloto[i].numero;
				piloto[j].s = piloto[i].s;
				piloto[j].t = piloto[i].t;
				piloto[j].v = piloto[i].v;
				piloto[i].ttotal = aux[0].ttotal;
				piloto[i].h = aux[0].h;
				piloto[i].m = aux[0].m;
				piloto[i].ms = aux[0].ms;
				piloto[i].numero = aux[0].numero;
				piloto[i].s = aux[0].s;
				piloto[i].t = aux[0].t;
				piloto[i].v = aux[0].v;
			}else{
				break;
			}
		}
	}
	
	for(i=0;i<20;i++){
		printf("%d - %d %d h . %d m . %d s . %d ms %d  Total = %d\n", i+1, piloto[i].numero, piloto[i].h, piloto[i].m, piloto[i].s, piloto[i].ms, piloto[i].v, piloto[i].ttotal);
	}
	
	return 0;
}
