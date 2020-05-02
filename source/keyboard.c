#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <switch.h>
#include <stddef.h>

void userAppInit(void)
{
	void *addr = NULL;
	if (svcSetHeapSize(&addr, 0x4000000) == (Result)-1)
		fatalSimple(0);
}

char	*popKeyboardf(char *message, size_t size)
{
	SwkbdConfig	skp; 
	Result		rc = swkbdCreate(&skp, 0);
	char		*swkdbout = NULL;

	
	swkdbout = (char *)calloc(sizeof(char), size + 1);
	if (swkdbout == NULL)
		return (NULL);

	if (R_SUCCEEDED(rc)) {
		swkbdConfigMakePresetDefault(&skp);
		swkbdConfigSetGuideText(&skp, message);
		rc = swkbdShow(&skp, swkdbout, size);
		swkbdClose(&skp);
	} else {
		free(swkdbout);
		swkdbout = NULL;
	}

	return (swkdbout);
}