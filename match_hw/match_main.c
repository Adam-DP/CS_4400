/* Author: Adam Della-Piana, CS 4400, Match HW Assignment, 8/30/2018
*
*
*/

#include <stdio.h>


void read_arguments(int argc, char *argv[]); // The idea is that if it's not valid input it prints something out and exits the program
void interpret_flag(int modifier); // This should read in a flag and adjust the settings
void process_data_a();
void process_data_b();
void process_data_c();


char mode_flag; /* This determines the mode. It will be set in the read_arguments method*/
char * data;
char t_true; /*If this is set to 't' then it will say that the t mode is on. Otherwise default it to 0*/

int main(int argc, char *argv[])
{
  mode_flag = 'a';
  t_true = 0;
  //data char * [10];

  /* Read in arguments to prepare for processing */
  read_arguments(argc, argv);

  /* Process the string as specified by the user */

  switch(mode_flag)
  {
    case 'a':
      process_data_a();
      break;
    case 'b':
      process_data_b();
      break;
    case 'c':
      process_data_c();
      break;
    default:
      printf("Invalid processing mode_flag");

  }

  printf("Data: %s \n", data);

}

void process_flag(char* arg)
{
  printf("Argument %s is a flag\n", arg);
  switch(arg[1])
  {
    case 'a'  :
    case 'b'  :
    case 'c'  :
      mode_flag = arg[1];
      break;
    case 't'  :
      printf("Case T Happened\n");
      t_true = 't';
      break;
    default   :
      printf("That's not valid...");
      break;
  }
}

void read_arguments(int argc, char *argv[])
{
  char * output;
  int idx = 1;
  while(idx < argc)
  {
    if(argv[idx][0]=='-')
    {
      process_flag(argv[idx]);
    }
    else
    {
      data = argv[idx];
    }
    idx++;
  }
}

/*
Description of pattern:
1. Any number (including zero) b's
2. Exactly two :'s \
3. 1 or more o's
4. Exactly one :
5. an odd number of uppercase letters
*/
void process_data_a()
{
  printf("process data a\n");
  char * arrow = data;

  // First check if it starts with b's
  while(*arrow == 'b') arrow++;
  // Then check to see if it has two :'s immediately
  if(* arrow==':') arrow++;
  else  {printf("no 1, %c", arrow); return;}
  if(* arrow==':') arrow++;
  else  {printf("no 2"); return;}
  // Check that it has at least 1 o
  if(* arrow=='o') arrow++;
  else  {printf("no 3"); return;}
  while(* arrow=='o') arrow++;
  // Check for Exactly one :
  if(* arrow==':') arrow++;
  else  {printf("no 4"); return;}
  // Check for an odd number of uppercase letters
  int count = 0;
  while(* arrow >= 'A' && * arrow <='Z'){count++; arrow++;}
  // make sure it's odd
  if((count & 1)&& * arrow == 0) printf("yes");
  else  {printf("no 5"); return;}

  // For matches, move the first character to the end
  if(t_true)
  {

  }
}

void process_data_b()
{
  printf("process data b\n");

}

void process_data_c()
{
  printf("process data c\n");

}
