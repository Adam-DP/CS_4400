/* Author: Adam Della-Piana, CS 4400, Match HW Assignment, 8/30/2018
*
*
*/

#include <stdio.h>
#include <string.h>


void read_arguments(int argc, char *argv[]); // The idea is that if it's not valid input it prints something out and exits the program
void interpret_flag(int modifier); // This should read in a flag and adjust the settings
void process_data_a();
void process_data_b();
void process_data_c();
void process_data(); // Decides which method to use for process

void case_no();
void case_yes();


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

  //process_data();

}

void process_data()
{
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
}

void process_flag(char* arg)
{
  // printf("Argument %s is a flag\n", arg);
  switch(arg[1])
  {
    case 'a'  :
    case 'b'  :
    case 'c'  :
      mode_flag = arg[1];
      break;
    case 't'  :
      // printf("Case T Happened\n");
      t_true = 't';
      break;
    default   :
      // printf("That's not valid...");
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
      process_data();
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
//  printf("process data a\n");
  char * arrow = data;
  // printf("Data size: %d", strlen(data));

  /*  prep output if needed */ 
  char output[strlen(data)*2];

  int index = 0;
  while(index < strlen(data)-1)
  {
    output[index] = data[index+1];
    index++;
  }

  output[strlen(data)-1] = data[0];
  output[strlen(data)] = 0;

  // First check if it starts with b's
  while(*arrow == 'b') arrow++;
  // Then check to see if it has two :'s immediately
  if(* arrow==':') arrow++;
  else  {case_no(); return;}
  if(* arrow==':') arrow++;
  else  {case_no(); return;}
  // Check that it has at least 1 o
  if(* arrow=='o') arrow++;
  else  {case_no(); return;}
  while(* arrow=='o') arrow++;
  // Check for Exactly one :
  if(* arrow==':') arrow++;
  else  {case_no(); return;}
  // Check for an odd number of uppercase letters
  int count = 0;
  while(* arrow >= 'A' && * arrow <='Z'){count++; arrow++;}
  // make sure it's odd
  if((count & 1)&& * arrow == 0) case_yes(output);
  else  {case_no(); return;}

  // For matches, move the first character to the end

  if(t_true)
  {


  }
}


/*
B CONSTRAINTS
1. any number (including zero) repetitions of the letter “g”;
2 exactly two “=”s;
3. between 1 and 3 (inclusive) decimal digits — call this sequence X;
4. 2 or more repetitions of the letter “z”;
5. exactly one “=”;
6. the same characters as the odd-positioned characters in X; and
7. an odd number of uppercase letters.
*/

void process_data_b()
{
//  printf("process data b\n");

  char * arrow = data;

  // First check if it starts with g's
  while(*arrow == 'g') arrow++;
  // Then check to see if it has two ='s immediately
  if(* arrow=='=') arrow++;
  else  {// printf("no 1, %c", arrow);
  case_no(); return;}
  if(* arrow=='=') arrow++;
  else  {case_no(); return;}

  // check that it has between 1 and 3 digits
  int num_X = 0;
  char odd_char = 0;
  while(* arrow >= '0' && * arrow <='9')
  {
    if(num_X&1) odd_char = *arrow;
    num_X++;
    arrow++;
  }
  if(num_X>=1 && num_X<=3) ;
  else  {case_no(); return;}

  // Check for two or more z's
  if(* arrow=='z') arrow++;
  else  {case_no(); return;}
  if(* arrow=='z') arrow++;
  else  {case_no(); return;}
  while(* arrow=='z') arrow++;

  // Check for Exactly one =
  if(* arrow=='=') arrow++;
  else  {case_no(); return;}

  // 6. the same characters as the odd-positioned characters in X;
  if(odd_char)
  {
    if(* arrow==odd_char) arrow++;
    else  {case_no(); return;}
  }

  // Check for an odd number of uppercase letters
  int count = 0;
  while(* arrow >= 'A' && * arrow <='Z'){count++; arrow++;}
  // make sure it's odd
  if((count & 1)&& * arrow == 0) case_yes("test");
  else  {case_no(); return;}

}

/*
1. any odd number of repetitions of the letter “g”;
2. exactly one “:”;
3. between 1 and 3 (inclusive) decimal digits — call this sequence X;
4. any odd number of repetitions of the letter “u”;
5. exactly one “:”;
6. the same characters as X repeated 2 times; and
7. an odd number of uppercase letters.
*/
void process_data_c()
{
  // printf("process data c\n");
  char output[sizeof(data)];
  char * arrow = data;

  // 1. any odd number of repetitions of the letter “g”;
  int count_g = 0;
  while(* arrow == 'g'){count_g++; arrow++;}
  // make sure it's odd
  if(count_g & 1) ;
  else  {case_no(); return;}


  // exactly one “:”;
  if(* arrow==':') arrow++;
  else  {case_no(); return;}

  // check that it has between 1 and 3 digits -> also save X for later
  int num_X = 0;
  char x_seq[3];
  while(* arrow >= '0' && * arrow <='9')
  {
    if(num_X > 3) {case_no(); return;}

    x_seq[num_X] = *arrow;
    num_X++;
    arrow++;
  }
  if(num_X>=1 && num_X<=3) ;
  else  {case_no(); return;}

  // any odd number of u
  int count_u = 0;
  while(* arrow == 'u'){count_u++; arrow++;}
  // make sure it's odd
  if(count_u & 1) ;
  else  {case_no(); return;}

  // Check for Exactly one :
  if(* arrow==':') arrow++;
  else  {case_no(); return;}

  // Check if X then repeats twice
  int idx = 0;
  while(idx < num_X)
  {
    if(* arrow==x_seq[idx]) arrow++;
    else  {case_no(); return;}
    idx++;
  }
  idx = 0;
  while(idx < num_X)
  {
    if(* arrow==x_seq[idx]) arrow++;
    else  {case_no(); return;}
    idx++;
  }

  // Check for an odd number of uppercase letters
  int count = 0;
  while(* arrow >= 'A' && * arrow <='Z'){count++; arrow++;}
  // make sure it's odd
  if((count & 1)&& * arrow == 0) case_yes("test");
  else  {case_no(); return;}

}



void case_no()
{
  if(!t_true)
  {
    printf("no\n");
  }
}


void case_yes(char * output)
{
  if(t_true)
  {
    printf("%s\n",output);
  }
  else
  {
    printf("yes\n");
  }
}
