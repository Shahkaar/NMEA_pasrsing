#include <stdio.h>
#include "nmea.h"
#include <stdlib.h>
#include <string.h>

void parsing_gpgga(gpgga g1,char str[])
{
  g1.msg_ID = str;
  g1.msg_ID = str;g1.time= strchr(g1.msg_ID, ',');*g1.time = '\0'; ++g1.time;
  g1.raw_latitude= strchr(g1.time, ',');*g1.raw_latitude = '\0'; ++g1.raw_latitude;
  g1.n_s= strchr(g1.raw_latitude, ',');*g1.n_s = '\0'; ++g1.n_s;
  g1.raw_longitutde= strchr(g1.n_s, ',');*g1.raw_longitutde = '\0'; ++g1.raw_longitutde;
  g1.e_w= strchr(g1.raw_longitutde, ',');*g1.e_w = '\0'; ++g1.e_w;
  g1.quality= strchr(g1.e_w, ',');*g1.quality= '\0'; ++g1.quality;
  g1.sat= strchr(g1.quality, ',');*g1.sat= '\0'; ++g1.sat;
  g1.hdop= strchr(g1.sat, ',');*g1.hdop= '\0'; ++g1.hdop;
  g1.alt= strchr(g1.hdop, ',');*g1.alt= '\0'; ++g1.alt;
  g1.ualt= strchr(g1.alt, ',');*g1.ualt= '\0'; ++g1.ualt;
  g1.undulation= strchr(g1.ualt, ',');*g1.undulation= '\0'; ++g1.undulation;
  g1.unit_undulation= strchr(g1.undulation, ',');*g1.unit_undulation= '\0'; ++g1.unit_undulation;
  g1.age= strchr(g1.unit_undulation, ',');*g1.age= '\0'; ++g1.age;
  g1.staID= strchr(g1.age, ',');*g1.staID= '\0'; ++g1.staID;
  g1.check= strchr(g1.staID, '*');*g1.check= '\0'; ++g1.check;

   double Latitude = atof(g1.raw_latitude);
   double Longitude = atof(g1.raw_longitutde);

  printf("The Message ID is : %s\n", g1.msg_ID);
  printf("The Time is : %s\n", g1.time);
  printf("The Latitude is : %f\n", Latitude);
  if((strcmp(g1.n_s,"N") == 0) || (strcmp(g1.n_s,"S") == 0))
  {
    printf("The N_S is : %s\n", g1.n_s);
  }
  else if ((strcmp(g1.n_s,"N") != 0) || (strcmp(g1.n_s,"S") != 0))
  {
        printf("Invalid entity for N_S");
  }
  printf("The Longitude is : %f\n", Longitude);
  if((strcmp(g1.e_w,"E") == 0) || (strcmp(g1.e_w,"W") == 0))
  {
    printf("The E_W is : %s\n", g1.e_w);
  }
  else if ((strcmp(g1.e_w,"E") == 0) || (strcmp(g1.e_w,"W") == 0))
  {
        printf("Invalid entity for E_W");
  }
  printf("The Quality is : %s\n", g1.quality);
  printf("The number of satalites is : %s\n", g1.sat);
  printf("The hdop is : %s\n", g1.hdop);
  printf("The altitude of anteena is : %s\n", g1.alt);
  printf("The unit of altite is : %s\n", g1.ualt);
  printf("The undulation is : %s\n", g1.undulation);
  printf("The unit of undulation is : %s\n", g1.unit_undulation);
  printf("The age of data is : %s\n", g1.age);
  printf("The stationID is : %s\n", g1.staID);
  printf("The checksum is : %s\n", g1.check);
}
