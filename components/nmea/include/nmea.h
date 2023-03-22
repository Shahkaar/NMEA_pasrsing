#ifndef HEADER_FILE
#define HEADER_FILE

typedef struct
{
  char* msg_ID;
  char* time;
  char* raw_latitude;
  char* n_s;
  char* raw_longitutde;
  char* e_w;
  char* quality;
  char* sat;
  char* hdop;
  char* alt;
  char* ualt;
  char* undulation;
  char* unit_undulation;
  char* age;
  char* staID;
  char* check;
}gpgga;

void parsing_gpgga(gpgga g1,char str[]);

#endif
