#include <stdio.h>
#include <stdlib.h>
#include <glib.h>


gchar* get_contents (void) {
	const gchar *filename = "dracula.txt";
	gchar *contents;
	gsize len;
	GError *error = NULL;

	if (! g_file_get_contents (filename, &contents, &len, &error))
		g_error ("g_file_get_contents() failed: %s", error->message);
	return contents;

}

void print_hash(gpointer key, gpointer value, gpointer user_data){
	printf("%s - %d\n", key, value);
}

void count_words(gchar *contents){
	gchar **strings = g_strsplit(contents, " ", -1);
	
	gchar **ptr;

	GHashTable* counts = g_hash_table_new(g_str_hash, g_str_equal);

    gchar *key;
    for (ptr = strings; *ptr; ptr++) {
    	key = *ptr;
	    if (g_hash_table_lookup(counts, g_strdup(key)) != NULL) {
	        
	        //count = GINT_TO_POINTER(GPOINTER_TO_INT(count)+1);
	        // Insert the new value 
	        g_hash_table_insert(counts, g_strdup(key), g_hash_table_lookup(counts, g_strdup(key))+1);
	    } else {
	   
	        // Insert into our hash table it is not a duplicate.
	        g_hash_table_insert(counts, g_strdup(key), 1);
		}
	}

	g_hash_table_foreach(counts, print_hash, NULL);
}	

int main(int argc, char** argv) {
    gchar *contents = get_contents();
    count_words(contents);
    return 0;
}