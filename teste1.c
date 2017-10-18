#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"


void loop(int p){
	double i, j;

	for(i = 0; i < 10000; i++)
		for(j=0; j < 10000; j++);

	printf(1, "\np%d -- Terminei\n", p);
}

int main(void){
	int p[5];


	p[0] = fork(10);
	if(p[0] == 0){
		loop(0);
		exit();
	}
		
	p[1] = fork(30);
	if(p[1] == 0){
		loop(1);
		exit();
	}
		
	p[2] = fork(50);
	if(p[2] == 0){
		loop(2);
		exit();
	}	
	
	p[3] = fork(100);
	if(p[3] == 0){
		loop(3);
		exit();	
	}

	p[4] = fork(300);
	if(p[4] == 0){
		loop(4);
		exit();
	}	

	wait();
	wait();
	wait();	
	wait();
	wait();	
	
	exit();

return 0;
}
