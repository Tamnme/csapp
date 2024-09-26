#include<stdio.h>
#include<string.h>

const char* binary(int n) {
  static const char binnums[16][5] = { "0000","0001","0010","0011",
    "0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111" };
  static const char* hexnums = "0123456789abcdef";
  static char inbuffer[16], outbuffer[4*16];
  const char *i;
  sprintf(inbuffer,"%x",n); // hexadecimal n -> inbuffer
  for(i=inbuffer; *i!=0; ++i) { // for each hexadecimal cipher
    int d = strchr(hexnums,*i) - hexnums; // store its decimal value to d
    char* o = outbuffer+(i-inbuffer)*4; // shift four characters in outbuffer
    sprintf(o,"%s",binnums[d]); // place binary value of d there
  }
  return strchr(outbuffer,'1'); // omit leading zeros
}

void print_binary_sized(unsigned int number, unsigned int digits) {
    static char ZERO = '0';
    int digitsLeft = digits;
    
    do{
        putchar(ZERO + ((number >> digitsLeft) & 1));
    }while(digitsLeft--);
}

void print_binary(unsigned int number) {
    int digitsLeft = sizeof(number) * 8;
    
    while((~(number >> digitsLeft) & 1) && digitsLeft){
        digitsLeft--;
    }
    print_binary_sized(number, digitsLeft);
}

int main(){
  int tx = -2147483647 - 1;
  int ty = -2147483647 - 1u;
  
  printf("tx = %u = %d\n", tx, tx);
  printf("ty = %u = %d\n", ty, ty);
  
  puts(binary(tx));
  puts(binary(ty));
  print_binary((unsigned) tx);
  print_binary((unsigned) ty);

  // if ((unsigned) tx < ux) {
  //   printf("t2u \n");
  // }
  // if ( tx < (int) ux) {
  //   printf("u2t \n");
  // }

  return 0;
}