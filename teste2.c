#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"

int main(){
	int nprocess = 8, i, pid = 0, j, p, p1, p2; 
	int tickets = nprocess+1;
	for(i = 0; i < nprocess; i++){
		tickets -= 1;
		pid = fork(tickets);													
		if(pid == 0) break;
	}

	if(pid == 0){																
		printf(1, "COMECOU PID%d - %d tickets\n", getpid(), tickets);
		for(p = 0; p < 500; p++)						
			for(p1 = 0; p1 < 500; p1++)
				for(p2 = 0; p2 < 300; p2++)
					printf(1, "");													
		printf(1, "ACABOU PID%d - %d tickets\n", getpid(), tickets);
	}

	if(pid > 0){
		for(j = 0; j < nprocess; j++)
			wait();
	}
	exit();
	return 0;
}

