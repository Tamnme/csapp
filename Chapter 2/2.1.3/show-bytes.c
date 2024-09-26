#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i=0;i<len;i++) printf(" %.2x", start[i]);
    printf("\n");
}
void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}
void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}
void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

int main() {
//--- Practice Problem 2.5 
    // int a = 0x12345678;
    // byte_pointer ap = (byte_pointer) &a;
    // show_bytes(ap, 1); /* A. */
    // show_bytes(ap, 2); /* B. */
    // show_bytes(ap, 3); /* C. */
    // //==========================
    // const char *m = "mnopqr";
    // show_bytes((byte_pointer) m, strlen(m));
    // return -1;
//---- 2.2.5 Signed versus Unsigned in C
    short sx = -12345; /* -12345 */
    unsigned short usx = sx; /* 53191 */
    int x = sx; /* -12345 */
    unsigned ux = usx; /* 53191 */

    printf("sx = %d:\t", sx);
    show_bytes((byte_pointer) &sx, sizeof(short));
    printf("usx = %u:\t", usx);
    show_bytes((byte_pointer) &usx, sizeof(unsigned short));
    printf("x = %d:\t", x);
    show_bytes((byte_pointer) &x, sizeof(int));
    printf("ux = %u:\t", ux);
    show_bytes((byte_pointer) &ux, sizeof(unsigned));
}