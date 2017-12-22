 /* hellotest.c
 *
 * Author  :  Leonardo Suriano<leonardo.suriano@live.it>
 *
 * A simple example of a C program to test some of the
 * operations of the "/dev/hello" device (a.k.a "hello0"),
 *
 * To compile the file: aarch64-linux-gnu-gcc test_hello.c -o test_hello.elf
 *
 */
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int main() {

    int fd, result, len;

    printf("\n-- TEST hello device_driver--\n");
    /* Open operation */
    if ((fd = open("/dev/hello", O_RDONLY)) < 0 ) {
        perror("1. open failed \n");
        goto fail;
    }
		else{
			  printf("file opend\n");
		}

    /* Read operation */

    long *a;
    result = read(fd, (void*)a, sizeof(long));
    if ( result != 0 ){
        printf("ERROR read operation: %d byte(s) cuold NOT be copied\n");
        goto fail;
    }
    else{
        printf("read operation executed succesfully\n");
        printf("a = %ld \n",*a);
    }

    /* Close operation */
    if (close(fd)){
		    perror("1. close failed \n");
        goto fail;
		}
		else{
		    printf("file closed\n");
		}
		printf("-- TEST PASSED --\n");
    return 0;
    fail:
    printf("-- TEST FAILED --\n");
    return -1;

}