#include <stdio.h>

void println(){
	printf("\n");
}

void print_char_array(char arr[]){
	for(int i = 0; arr[i] != 0; i++){
		printf("%c", arr[i]);
	}
	println();
}

void print_char_array_overflow(char arr[]){
	int i = 0;
	for(; arr[i] != 0; i++){
		printf("%c", arr[i]);
	}
	for(int x = i; x < (i+10); x++){
		printf("%c", arr[x]);
	}
	println();
}

int get_array_size(char arr[]){
	int size = 0;
	for(int i = 0; arr[i] != 0; i++){
		size ++;
	}
	return size;
}

void read_in(char *s){
	scanf("%99[^\n]", s);
}

void print_array_size(char arr[]){
	int size = get_array_size(arr);
	printf("%d\n", size);
}

void print_char_array_backwards(char arr[]){
	int size = get_array_size(arr);
	
	for(int i = size; i >= 0; i--){
		printf("%c", arr[i]);
	}
	println();
}

void print_memory_loc(char arr[]){
	int size = get_array_size(arr);
	int first_mem = &arr[0];
	int last_mem = &arr[size - 1];
	printf("[%x - %x]", first_mem, last_mem);
	println();
}

void print_unicode(char arr[]){
	for(int i = 0; arr[i] != 0; i++){
		printf("U+%x ", arr[i]);
	}
	println();
}

void print_unicode_sum(char arr[]){
	int sum = 0;
	for(int i = 0; arr[i] != 0; i++){
			sum += arr[i];
	}
	printf("%d (0x%x)", sum, sum);
	println();
}

int main(){
	println();

	char myname[101];
	printf("Enter something between 0-100 characters: ");
	read_in(myname);

	printf("%-20s", "String: ");
	print_char_array(myname);
	printf("%-20s", "String backwards: ");
	print_char_array_backwards(myname);
	printf("%-20s", "String size: ");
	print_array_size(myname);
	printf("%-20s", "String malloc: ");
	print_memory_loc(myname);
	printf("%-20s", "String in unicode:");
	print_unicode(myname);
	printf("%-20s", "String unicode sum:");
	print_unicode_sum(myname);

	println();
}
