#include <stdio.h>
#include <stdlib.h>

static void comp_result(char *string, int rc)
{
	if (rc) {
		printf("Error on : %s, rc=%d", string, rc);	
		exit(EXIT_FAILURE);
	}
}
