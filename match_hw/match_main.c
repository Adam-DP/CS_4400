/* Author: Adam Della-Piana, CS 4400, Match HW Assignment, 8/30/2018
*
*
*/

int read_arguments(int argc, char *argv[]); // The idea is that if it's not valid input it prints something out and exits the program
void interpret_flag(int modifier); // This should read in a flag and adjust the settings
void check_match();

int main(int argc, char *argv[])
{
  /* Read in arguments to prepare for processing */
  int modifier = read_arguments(argc, argv);

  /* Adjust the settings based on the flags */
  interpret_flag(modifier);

  /* Process the string as specified by the user */

}

int process_arg(char* arg)
{
  if(arg[0]=='-')
  {
    printf("Argument %s is a flag\n", arg);
    switch(arg[1])
    {
      case 'a'  :
      case 'b'  :
      case 'c'  :
        return arg;
      case 't'  :
        printf("Case T Happened\n");
      default   :
        return 0;
    }

  }
  else
  {
    printf("Argument %s is not a flag\n", arg);
  }
}

int read_arguments(int argc, char *argv[])
{
  int idx = 1;
  while(idx < argc)
  {
    process_arg(argv[idx]);
    idx++;
  }
  return 0;
}

void interpret_flag(int modifier)
{
  printf("The modifier is %d\n", modifier);
}
