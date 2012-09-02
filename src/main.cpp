// main.cpp - this function will remove duplicate characters from a string
#include <stdio.h>

// 256 * 1 byte = 256 bytes of storage to keep track of 
// ascii codes which we've seen
bool seen[256] = { false };


// remove_duplicates from string s
// basic approach will be to maintain two pointers 
// one pointer will point to the position to be replaced
// the the pointer will walk the length of the input string
// in O(n) time.

void remove_dups(char* leader){

  // setup two pointers, a trailer and a leader
  char* trailer = leader;
  
  // walk in O(n) time untill we've walked through the string
  while( *leader){
    if(! seen[(int) *leader]){
      
      // mark as 'seen'
      seen[(int) *leader] = true;

      // copy the value of the leader into the place being held 
      // by the trailer
      *trailer = *leader;
      
      leader++;
      trailer++;


    }
    // we're at a duplicate character, move the leader forward
    // but mark the place with the trailer
    else{
      leader++;
    }
  }

  // when we drop out, the leader is pointing at the null terminator
  // copy the null terminator over the trailer pos
  *trailer = *leader;
} 

int main(){

  // test strings defined here
  char a[]="Hello World";
  char b[]="Hello Hubspot";

  remove_dups(b);
  printf("%s",b);

  return 0;
}


