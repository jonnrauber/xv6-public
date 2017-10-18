#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"


void loop(int p){
	double i, j;

	for(i = 0; i < 10000; i++)
		for(j=0; j < 10000; j++);

	printf(1, "%d\n", p);
}

int main(void){
	int p[5];


	p[0] = fork(1);
	if(p[0] == 0){
		loop(0);
		exit();
	}
		
	p[1] = fork(2);
	if(p[1] == 0){
		loop(1);
		exit();
	}
		
	p[2] = fork(3);
	if(p[2] == 0){
		loop(2);
		exit();
	}	
	
	p[3] = fork(4);
	if(p[3] == 0){
		loop(3);
		exit();	
	}

	p[4] = fork(5);
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
