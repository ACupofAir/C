#include <stdio.h>

void print_day(int day) {                                                       
  switch (day) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
			printf("It's weekday.\n");
			break;
    case 6:
    case 7:
			printf("It's weekend.\n");
			break;
    default:
      printf("Ileegal day number!\n");
      break;
  }
}

int main(void) {
  print_day(6);
  return 0;
}
