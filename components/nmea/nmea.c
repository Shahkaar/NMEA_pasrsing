#include <stdio.h>
#include "nmea.h"
#include <stdlib.h>
#include <string.h>

// Function difinition
void parsing_gpgga(gpgga *g1,char str[])
{
	// char is used just to play with the string the extracted data is converted and saved in there respective data type
  char* msg_ID = str;char*time= strchr(msg_ID, ',');*time = '\0'; ++time;
  char*raw_latitude= strchr(time, ',');*raw_latitude = '\0'; ++raw_latitude;
  char*n_s= strchr(raw_latitude, ',');*n_s = '\0'; ++n_s;
  char*raw_longitutde= strchr(n_s, ',');*raw_longitutde = '\0'; ++raw_longitutde;
  char*e_w= strchr(raw_longitutde, ',');*e_w = '\0'; ++e_w;
  char*quality= strchr(e_w, ',');*quality= '\0'; ++quality;
  char*sat= strchr(quality, ',');*sat= '\0'; ++sat;
  char*hdop= strchr(sat, ',');*hdop= '\0'; ++hdop;
  char*alt= strchr(hdop, ',');*alt= '\0'; ++alt;
  char*ualt= strchr(alt, ',');*ualt= '\0'; ++ualt;
  char*undulation= strchr(ualt, ',');*undulation= '\0'; ++undulation;
  char*unit_undulation= strchr(undulation, ',');*unit_undulation= '\0'; ++unit_undulation;
  char*age= strchr(unit_undulation, ',');*age= '\0'; ++age;
  char*staID= strchr(age, ',');*staID= '\0'; ++staID;
  char*check= strchr(staID, '*');*check= '\0'; ++check;

  g1->msg_ID = msg_ID;
  g1->time = time;
  g1->raw_latitude = atof(raw_latitude);
  g1->n_s = n_s;
  g1->raw_longitutde = atof(raw_longitutde);
  g1->e_w = e_w;
  g1->quality = atoi(quality);
  g1->sat = atoi(sat);
  g1->hdop = atof(hdop);
  g1->alt = atof(alt);
  g1->ualt = ualt;
  g1->undulation = atof(undulation);
  g1->unit_undulation = unit_undulation;
  g1->age = atof(age);
  g1->staID = atoi(staID);
  g1->check = check;

  display(g1);
}

// as the name says the function is to display the data in the structure pointer
void display(gpgga *g1)
{
  printf("The Message ID is : %s\n", g1->msg_ID);
  printf("The Time is : %s\n", g1->time);
  printf("The Latitude is : %f\n", g1->raw_latitude);
  if((strcmp(g1->n_s,"N") == 0) || (strcmp(g1->n_s,"S") == 0))
  {
    printf("The N_S is : %s\n", g1->n_s);
  }
  else if ((strcmp(g1->n_s,"N") != 0) || (strcmp(g1->n_s,"S") != 0))
  {
        printf("Invalid entity for N_S");
  }
  printf("The Longitude is : %f\n", g1->raw_longitutde);
  if((strcmp(g1->e_w,"E") == 0) || (strcmp(g1->e_w,"W") == 0))
  {
    printf("The E_W is : %s\n", g1->e_w);
  }
  else if ((strcmp(g1->e_w,"E") != 0) || (strcmp(g1->e_w,"W") != 0))
  {
        printf("Invalid entity for E_W");
  }
  printf("The Quality is : %d\n", g1->quality);
  printf("The number of satalites is : %d\n", g1->sat);
  printf("The hdop is : %f\n", g1->hdop);
  printf("The altitude of anteena is : %f\n", g1->alt);
  printf("The unit of altite is : %s\n", g1->ualt);
  printf("The undulation is : %f\n", g1->undulation);
  printf("The unit of undulation is : %s\n", g1->unit_undulation);
  printf("The age of data is : %f\n", g1->age);
  printf("The stationID is : %d\n", g1->staID);
  printf("The checksum is : %s\n", g1->check);
}
