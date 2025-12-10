#include <stdio.h>
#include <string.h>

int main() {

int counter1[] = {0, 0, 0 , 0};
int counter2[] = {0, 0, 0 , 0};


char s1[] = "dbb cccccaacb cdbababdcdcdab dcdad";
char s2[] = "bbbcc bddddddddddccccccccad cdbbaaacaccdabdd";

int length = strlen(s1);
int length2 = strlen(s2);
int flag = 0;

for(int i = 0; i < strlen(s1); i++) {
  if (s1[i] == 'a') {
    counter1[0]++;
  } else if(s1[i] == 'b') {
    counter1[1]++;
  } else if(s1[i] == 'c') {
    counter1[2]++;
  } else if(s1[i] == 'd') {
    counter1[3]++;
  } else { continue; }
}

for(int i = 0; i < strlen(s2); i++) {
  if (s2[i] == 'a') {
    counter2[0]++;
  } else if(s2[i] == 'b') {
    counter2[1]++;
  } else if(s2[i] == 'c') {
    counter2[2]++;
  } else if(s2[i] == 'd') {
    counter2[3]++;
  } else { continue; }

}

int longest_length = (length > length2) ? length : length2;

for(int i = 0; i < 4; i++) {
  if (counter1[i] != counter2[i]) {
    flag = 1;
    break;
  }
}

if (flag ==0) {
  printf("Anagram!\n");
} else {
  printf("Not Anagram!\n");
}


}
