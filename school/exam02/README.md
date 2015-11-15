# C for Linux, exam02: encryption.
###### by Idar Vassdal

My main focus was to keep valgrind at ```0 errors from 0 contexts``` under the entire development period, which I succeeded. \
I have made it to compile as a library, and have tested sending it to Fredrick Biering. He had to recompile the library as mentioned below, but after he did it ran flawlessly.

## The program

#####  How to recompile
If you cannot go to ```/program``` and just run it, you must recompile it. Delete ```libsecretcoder.a``` from ```/program```, go to ```/src``` and run ```make clean``` , then ```make``` to compile a new one. Then copy the new ```libsecretCoder.a``` from ```/src``` to ```/program```. Go to ```/program```, run  ```make clean``` and ```make``` and try to run it again.

##### Encrypt a text
```./program encode [file to encode] [keyfile]```  \
i.e. \
```$ ./program encode ../secretMessage.txt ../HE2/songLibrary/wakaWaka.txt``` \
```=> Encoded message:[-35] [26][278] [26] [127][3][24][21] [31][3][38][24][3][52] [52][3][467][52] [26][44][30] [30][3][278][26][44][30] [52][0] [50][3] [31][3][38][24][3][52] ```


##### Decrypt a text
```./program decode [file to decode] [keyfile]``` \
i.e. \
```$ ./program decode ../encodedMessage.txt ../HE2/songLibrary/wakaWaka.txt``` \
```=> Decoded message: I am a very secret text and demand to be secret```

##### Bruteforce the keyfile used to encrypt an encoded text
```./program decode [file to crack] [folder of potential keyfiles]``` \
i.e. \
```$ ./program crack ../encodedMessage.txt ../HE2/songLibrary``` \
```=> Most likely key file is ../HE2/songLibrary/wakaWaka.txt```

## How it works
The program uses Book Cypher to encode messages. The encoder encrypts the secret message with an index of each character in a keyfile. If the keyfile says ```iamakeyfile```, the letter ``` 'i' ``` is on index ```1``` and ```9```.  The decoder then matches these indexes with a keyfile, and goes to said index and gets the character there. That means you need to have the same keyfile to decode the messages. 

##### Key files
Key files are used to encode a message. The keyfile can look like this
```I am a keyfile``` and will be pased to ```iamakeyfile```.

##### Secret message
The secret message will take the message, i.e. ```fake``` and turn it into ```[8][2][5][6]``` which are the indexes that character has in the keyfile. To decode it, you need the keyfile.

##### Cracker
The cracker brute-forces a collection of keyfiles, decodes the message and checks them for words found in the dictionary. The keyfile with the most hits to the dictionary is returned. 
