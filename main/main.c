#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nmea.h"

void app_main(void)
{
	 char str[] = "$GPGGA,002153.000,3342.6618,N,11751.3858,W,1,10,1.2,27.0,M,-34.2,M,,0000*5E";
	 int x = strlen(str);
	 char string[x+1];
	 strcpy(string,str);

	// checking $
	if((strchr(str,'$')) != NULL)
	{
	  char* Message_ID = str;
	  char* Time = strchr(Message_ID, ',');
	  *Time = '\0';
	  ++Time;
	// checking GPGGA
	  if ((strcmp(Message_ID,"$GPGGA")) == 0)
	  {
		  gpgga g0;
	      gpgga *g1 = &g0 ;
	      parsing_gpgga(g1,string);
	  }

	}
}
