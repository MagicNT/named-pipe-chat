////////////////////////////////////////////
///                                      ///
///           TONY NASR                  ///
///            SERVER                    ///
////////////////////////////////////////////

																																																																																																																							
#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/stat.h>
#include  <unistd.h>
#include  <string.h> 
#include  <linux/stat.h>

#define  RED       "\033[1;31m"
#define  GREEN     "\033[1;32m"
#define  YELLOW    "\033[1;33m"
#define  BLUE      "\033[1;34m"
#define  PURPLE    "\033[1;35m"
#define  CYAN      "\033[1;36m"
#define  WHITE     "\033[1;37m"
#define  ORANGE    "\e[38;5;166m"
#define  FIFO_1    "/tmp/chat1"
#define  FIFO_2    "/tmp/chat2"


void logo();
void send_prompt();
void rec_prompt(char*);
void send_msg(int, int, char*);


int main() {
	logo();
	FILE *f1, *f2;
	char sendBUFF[60], recBUFF[60];
	umask(0);
	mknod(FIFO_1, S_IFIFO|0666, 1);
	mknod(FIFO_2, S_IFIFO|0666, 1);

	while(1) {
		f1 = fopen(FIFO_1, "r");
		fgets(recBUFF, 60, f1);	
		send_msg(1, 2, recBUFF);
		f2 = fopen(FIFO_2, "r+");		
		fputs(recBUFF, f2);
		fclose(f1);
		fclose(f2);
		
		f2 = fopen(FIFO_2, "r");		
		fgets(sendBUFF, 60, f2);
		send_msg(2, 1, sendBUFF);	
		f1 = fopen(FIFO_1, "r+");		
		fputs(sendBUFF, f1);
		fclose(f1);
		fclose(f2);
		
	}
	return 0;
}



void logo() {
	system("reset");
	printf("\n\n");
	printf( CYAN "\t\t\tAuthor: TONY NASR\n");		
	printf( YELLOW "\t ▄▄▄▄▄▄▄▄▄▄▄   ▄         ▄   ▄▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄ \n");
	printf( YELLOW "\t▐░░░░░░░░░░░▌ ▐░▌       ▐░▌ ▐░░░░░░░░░░░▌ ▐░░░░░░░░░░░▌\n");
	printf( YELLOW "\t▐░█▀▀▀▀▀▀▀▀▀  ▐░▌       ▐░▌ ▐░█▀▀▀▀▀▀▀█░▌  ▀▀▀▀█░█▀▀▀▀ \n");
	printf( YELLOW "\t▐░▌           ▐░▌       ▐░▌ ▐░▌       ▐░▌      ▐░▌     \n");
	printf( YELLOW "\t▐░▌           ▐░█▄▄▄▄▄▄▄█░▌ ▐░█▄▄▄▄▄▄▄█░▌      ▐░▌     \n");
	printf( YELLOW "\t▐░▌           ▐░░░░░░░░░░░▌ ▐░░░░░░░░░░░▌      ▐░▌     \n");
	printf( YELLOW "\t▐░▌           ▐░█▀▀▀▀▀▀▀█░▌ ▐░█▀▀▀▀▀▀▀█░▌      ▐░▌     \n");
	printf( YELLOW "\t▐░▌           ▐░▌       ▐░▌ ▐░▌       ▐░▌      ▐░▌     \n");
	printf( YELLOW "\t▐░█▄▄▄▄▄▄▄▄▄  ▐░▌       ▐░▌ ▐░▌       ▐░▌      ▐░▌     \n");
	printf( YELLOW "\t▐░░░░░░░░░░░▌ ▐░▌       ▐░▌ ▐░▌       ▐░▌      ▐░▌     \n");
	printf( YELLOW "\t ▀▀▀▀▀▀▀▀▀▀▀   ▀         ▀   ▀         ▀        ▀      \n");
	printf( YELLOW "\t\t\t" GREEN "SERVER \n\n");	
}


void send_msg(int a, int b, char *msg) {
	if (a == 1) {
		printf(PURPLE " # " YELLOW "CLIENT" BLUE "~" WHITE "[" GREEN "%d" WHITE "]" WHITE " --> " YELLOW "CLIENT" BLUE "~" WHITE "[" GREEN "%d" WHITE "]" RED ": " CYAN "%s", a, b, msg);
	}
	else if (a == 2) {
		printf(PURPLE " # " YELLOW "CLIENT" BLUE "~" WHITE "[" GREEN "%d" WHITE "]" WHITE " --> " YELLOW "CLIENT" BLUE "~" WHITE "[" GREEN "%d" WHITE "]" RED ": " ORANGE "%s", a, b, msg);
	}	
}




