////////////////////////////////////////////
///                                      ///
///           TONY NASR                  ///
///            CLIENT 1                  ///
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
#define  FIFO_1 "/tmp/chat1"


void logo();
void send_prompt();
void rec_prompt(char*);


int main() {
	logo();
	FILE *fp;
	char sendBUFF[60], recBUFF[60];
	umask(0);
	mknod(FIFO_1, S_IFIFO|0666, 1);
				
	while(1) {
		if ((fp = fopen(FIFO_1, "r+")) == NULL) {
			printf("ERROR: Cannot open %s", FIFO_1);
			exit(1);
		}
		send_prompt();
		fgets(sendBUFF, 60, stdin);
		fputs(sendBUFF, fp);
		fclose(fp);	
		
		fp = fopen(FIFO_1, "r");
		fgets(recBUFF, 60, fp);
		rec_prompt(recBUFF);
		fclose(fp);
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
	printf( YELLOW "\t\t\t" GREEN "CLIENT " WHITE "[" RED "1" WHITE "]  \n\n");	
}


void send_prompt() {
	printf(PURPLE " # " YELLOW "CLIENT" BLUE "~" WHITE "[" GREEN "%d" WHITE "]" RED ": " CYAN, 1);
}


void rec_prompt(char *recBUFF) {
	printf(PURPLE " # " YELLOW "CLIENT" BLUE "~" WHITE "[" GREEN "%d" WHITE "]" RED ": " ORANGE "%s", 2, recBUFF);
}




