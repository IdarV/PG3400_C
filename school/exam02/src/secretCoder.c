//#include "secretCoder.h"
/*
* output. Note that I need two outputs from the encoder - One is the encoded
* stream, the other is the status if success or fail. Hence, I can use two
* different forms. I am placing both the forms here.
*
*/
//char *encode(const char *inputMessageFile, const char *keyFile, int *status);
//// This form returns char * array of encoded stream and status into the
//// reference.
//int encode(const char *inputMessageFile, const char *keyFile, char *encodedStream);
// This form returns the status and takes the reference to the encoded stream as
// an argument
/* Some documentation regarding decode function and what to expect as output.
* This functions pretty much the same as encode function
*/
//char *decode(const char *inputCodeFile, const char *keyFile, int *status);
//int decode(const char *inputCodeFile, const char *keyFile, char *decodedMessage);