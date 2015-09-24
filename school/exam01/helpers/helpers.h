void die(const char *message);
void sort_array(char *sorting_method, int array_size, FileElement *array);
void search_number_interaction(int int_array_size, FileElement *array, char *filename);
long long current_timestamp();
void print_array_if_told(int argc, char *argv[], Dynarray dynarray);
char *set_sort_method(int argc, char *argv[]);