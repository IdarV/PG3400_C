#include <stdio.h>

void print_char_array(char arr[]){
	for(int i = 0; arr[i] != 0; i++){
		printf("%c", arr[i]);
	}
}

void print_array_size(char arr[]){
	int size = 0;
	for(int i = 0; arr[i] != 0; i++){
		size ++;
	}
	printf("%d\n", size);
}

int main(){
	printf("\n");
	char myname[] = "Idar Vassdal";
	//int size = sizeof(myname);
	//printf("%d\n", size);
	print_array_size(myname);
	print_char_array(myname);
	printf("\n");
}


