#include "../include/UART.h"
#include "../include/lib.h"

int main(){
	UART_init();
	//UART_read();
	UART_put("\rtest\n");

	char str[10] = {0};
	int idx = 0;

	while(1){
		char c = UART_read();

		if(c != '\n')
			str[idx++] = c;
		else{
			if(!Strncmp(str, "help", 4))
				UART_put("\rhelp      : print this help menu\nhello     : print Hello World!\nreboot    : reboot the device\n");
			else if(!Strncmp(str, "hello", 5))
				UART_put("\rHello World!\n");
			else
				UART_put("\rNo such command!\n");

			for(int i=0;i<10;i++)
				str[i] = 0;
			idx = 0;
		}
	}
}