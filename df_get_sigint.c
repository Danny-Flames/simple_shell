#include "main.h"

/**
 * get_sigint - To handle the crtl + c call in prompt
 * @sig_hdlr: The signal handler
 */
void get_sigint(int sig_hdlr)
{
	(void)sig_hdlr;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
