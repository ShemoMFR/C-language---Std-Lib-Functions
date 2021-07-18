#include <stdio.h>
#include "g.h"

int main(void)
{
	printf("%d", g_s);
	
	foo(g_s);
	
	printf("%d", g_s);
	
	return 0;

}
