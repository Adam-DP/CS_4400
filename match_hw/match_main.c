/* Author: Adam Della-Piana, CS 4400, Match HW Assignment, 8/30/2018
*
*
*/

#include <stdio.h>


char * read_arguments(int argc, char *argv[]); // The idea is that if it's not valid input it prints something out and exits the program
void interpret_flag(int modifier); // This should read in a flag and adjust the settings
void process_data();


char mode_flag; /* This determines the mode. It will be set in the read_arguments method*/
char * data;
char t_true; /*If this is set to 't' then it will say that the t mode is on. Otherwise default it to 0*/

int main(int argc, char *argv[])
{
  mode_flag = 'a';
  t_true = 0;

  /* Read in arguments to prepare for processing */
  read_arguments(argc, argv);

  /* Process the string as specified by the user */
  process_data();
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

char * read_arguments(int argc, char *argv[])
{
  char * output;
  int idx = 1;
  while(idx <= argc)
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
  return 0;
}

void process_data()
{

}
