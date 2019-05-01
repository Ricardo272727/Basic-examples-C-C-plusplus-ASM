#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

struct termios orig_termios;

void enableRawMode(){
	struct termios raw;
	
	tcgetattr(STDIN_FILENO,&raw);
	
	raw.c_lflag &= ~(ECHO);
	
	tcsetattr(STDIN_FILENO,TCSAFLUSH,&raw);
}

void disableRawMode(){
	tcsetattr(STDIN_FILENO,TCSAFLUSH,&orig_termios);
}

int main(){
	enableRawMode();
	char c;
	while(read(STDIN_FILENO,&c,1)==1 && c!='q');
	disableRawMode();
    return 0;
}
