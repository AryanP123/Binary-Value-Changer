/***********************************************************
Purpose: Replaces specified bits of a value with a 1 as well as 0 and then displaying the binary of the values of the array.
***********************************************************/

#include <stdio.h>
#include <stdlib.h>

void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);

int check_flag(unsigned int flag_holder[], int flag_position);

void display_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);


int main(int argc, char* argv[])
{
    unsigned int flag_holder[5] = { 0 };//Set the first integer to zero and all others to zero by default.

    set_flag(flag_holder, 3);
    set_flag(flag_holder, 16);
    set_flag(flag_holder, 31);
    set_flag(flag_holder, 87);
    display_flags(flag_holder, 5);

    printf("\n\n");

    unset_flag(flag_holder, 31);
    unset_flag(flag_holder, 3);
    set_flag(flag_holder, 99);
    set_flag(flag_holder, 100);
    display_flags(flag_holder, 5);

    return 0;
}

void set_flag(unsigned int flag_holder[], int flag_position)
{
  flag_holder[flag_position/32] = flag_holder[flag_position/32] | (1<<flag_position);
}

void unset_flag(unsigned int flag_holder[], int flag_position)
{
    flag_holder[flag_position/32] = flag_holder[flag_position/32] & (~(1<<flag_position));
}

int check_flag(unsigned int flag_holder[], int flag_position)
{
    return (flag_holder[flag_position/32]>>flag_position&1);
}

void display_flags_as_array(unsigned int flag_holder)
{
  int i = 0;

    for(i=0; i<(32); i++)
    {
      if(i%4 == 0)
      {
        printf(" ");
      }
      if(i%32 == 0)
      {
        printf("\n");
      }
      printf("%d", check_flag(&flag_holder, i));
    }
}

void display_flags(unsigned int flag_holder[], int size)
{
  int i;
  for(i = 0; i < size; i++)
  {
    display_flags_as_array(flag_holder[i]);
  }
}

