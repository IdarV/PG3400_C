# Ex17

### Changed
structs have been changed from
```
struct MyStruct{
	int someint;
};

struct MyStruct mystruct = {.someint = 1}
```
to
```
typedef struct{
    int someint;
} MyStruct;

MyStruct mystruct = {.someint = 1};
```

to avoid repeating the ```struct``` defining every time a struct is used.


### Run it

Make:
```sh
make program
```
Create database( c ): 
```sh
./program db.dat c 
```
Insert data ( s ):
```sh
./program db.dat s 1 idarv idarv@something.com
```
Delete data ( d ):
```sh
./program db.dat d 1 
```
List data:
```sh
./program db.dat l
```

