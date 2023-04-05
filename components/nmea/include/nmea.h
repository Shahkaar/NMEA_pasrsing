#ifndef HEADER_FILE
#define HEADER_FILE

typedef struct
{
  char* msg_ID;
  char* time;
  float raw_latitude;
  char* n_s;
  float raw_longitutde;
  char* e_w;
  int quality;
  int sat;
  float hdop;
  float alt;
  char* ualt;
  float undulation;
  char* unit_undulation;
  float age;
  int staID;
  char* check;
}gpgga;

// Function Declaration
void parsing_gpgga(gpgga *g1,char str[]);
void display(gpgga *g1);

#endif
