/* Simple example using Glib.

From http://www.ibm.com/developerworks/linux/tutorials/l-glib/

gcc -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include-lglib-2.0 -o ex_compile ex_compile.c

*/

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

int main(int argc, char** argv) {
    GList* list = NULL;
    list = g_list_append(list, "Hello world!");
    printf("The first item is '%s'\n", (char *) g_list_first(list)->data);
    return 0;
}
