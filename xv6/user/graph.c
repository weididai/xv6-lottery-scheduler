#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

#define check(exp, msg) if(exp) {} else {\
   printf(1, "%s:%d check (" #exp ") failed: %s\n", __FILE__, __LINE__, msg);\
   exit();}
void spin()
{
        int i = 0;
        for(i = 0; i <= 100000000; ++i)
        {
		
        }
}
void print(struct pstat *st)
{
   int i;
   int j = 0;
   for(i = 0; i < NPROC; i++) {
      if (st->inuse[i]) {
		j ++;
         // printf(1, "%d		", st->ticks[i]);
      }
	if (st->inuse[i] && j > 3) {
		printf(1, "%d ", st->ticks[i]);
	}
   }
	printf(1,"\n");
}

int
main(int argc, char *argv[])
{
//   int pid_low = getpid();
 //  int lowtickets = 10, middletickets = 20, hightickets = 30;
  // check(settickets(lowtickets) == 0, "settickets");
	int tickets[3];
	tickets[0] = 100;
	tickets[1] = 200;
	tickets[2] = 300;
   	for (int i = 0; i < 3; i++){
		if(fork() == 0)
   		{
            		check(settickets(tickets[i]) == 0, "settickets");
			//struct pstat st_before;
        		//check(getpinfo(&st_before) == 0, "getpinfo");
			//print(&st_before);
			int k = 0;
			while (k < 10000) {
				struct pstat st_after;
				spin();
				//printf(1, "..%d..\n", k);
        			check(getpinfo(&st_after) == 0, "getpinfo");
              			print(&st_after);
			}
        	//compare(pid_low, pid_high, &st_before, &st_after);
              	//printf(1, "Should print 1");
              	//exit();
   		}
	}
   printf(1, " then 2");
   while (wait() > 0);
   exit();
}
