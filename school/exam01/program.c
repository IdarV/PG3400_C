#include "helpers/FileElement/FileElement.h"
#include "helpers/Dynarray/dynarray.h"
#include "sorters/sorters.h"
#include "searchers/searchers.h"
#include "helpers/helpers.h"
#include "helpers/FileHandler/filehandler.h"
#include <string.h>
#include <sys/time.h>

#include "helpers/helpers.c"
#include "helpers/Dynarray/dynarray.c"
#include "sorters/bubblesort.c"
#include "sorters/mergesort.c"
#include "searchers/binary_search.c"
#include "helpers/FileHandler/filehandler.c"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        // kill program if no file is defined in args
        die("Didn't find any file argument. \n"
                    "Usage: \"./program [file] [opt: sorting_method]\"\n");
    }

    // open the file
    open_file(argv[1]);

    Dynarray numbers;
    Dynarray_init(&numbers);
    file_to_array(&numbers);

    char *sorting_method = set_sort_method(argc, argv);

    long timestart = 0;
    timestart = current_timestamp();

    sort_array(sorting_method, &numbers);

    long timestop = current_timestamp();

    print_array_if_told(argc, argv, &numbers);
    printf("(sorting with %s took %ld ms.)\n\n", sorting_method, (timestop - timestart));
    search_number_interaction(&numbers, argv[1]);

    //close the file
    close_file();
    Dynarray_free(&numbers);

    return 0;
}