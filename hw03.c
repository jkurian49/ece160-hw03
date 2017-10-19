#include <stdio.h>
#include <stdlib.h>

typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2
} Mode;

typedef struct {
  char *first_name;
  char *last_name;
  char *major;
  char *year;

} Student;

void print_student(Mode m, Student s) {
  switch (m) {
    case NAME_ONLY:
      printf("%s %s\n", s.first_name, s.last_name);
      break;
    case MAJOR_AND_NAME:
      printf("%s %s %s\n", s.major, s.first_name, s.last_name);
      break;
    case YEAR_AND_NAME:
      printf("%s %s %s\n", s.year, s.first_name, s.last_name);
      break;
    default:
      printf("Error\n");
  }
}

int main(int argc, char *argv[]) {

  int students = (argc - 2)/4;

  for (int i = 1; i <= students; i++) {
    Student s;
    s.first_name = argv[(i*4)-2];
    s.last_name = argv[(i*4)-1];
    s.major = argv[(i*4)];
    s.year = argv[(i*4)+1];
    print_student(atoi(argv[1]), s);
  }
  return 0;
}
