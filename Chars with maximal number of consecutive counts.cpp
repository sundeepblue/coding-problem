/*

Given a string, print out the chars with maximal number of consecutive counts

"this is a sentence" => [t, h, i, s, i, s, a, s, e, n, t, e, n, c, e]
"thiis iss a senntencee" => [i, s, n, e]
"thiisss iss a senntttenceee" => [s, t, e]
"thiisss iss a sennnntttenceee" => [n]

*/

#include<iostream>
#include<string>
using namespace std;

/*

solution1: whenever the two different consecutive chars occur, update the count and final result
if the count is equal to larger than current maximal count, otherwise, just reset the count.

*/



void maxRepCount1(char *sen) {
  if (!sen || !(*sen)) return;
  int maxcount = 0;
  int curcount = 0;
  string result;

  char prechar=*sen;
  do {
       if (*sen!=prechar) {
       
          if(curcount >=  maxcount && isalpha(prechar)) {
              if(curcount> maxcount) result.clear();
              result+=prechar;
              maxcount=curcount;
          }
          
          prechar=*sen;
          curcount=1;
          
       } else {
       
       count++;
       
       }
       
  } while(*sen++);

  cout<<result<<endl;
}

/*

solution2: scan the array to find the maximal count, scan again to output the chars with maximal count.
O(n) time, O(1) space

*/

void maxRepCount2(char *sen) {
    if (!sen || !(*sen)) return;
    int table[256] = {0};
    char *p = sen;
    int maxcount = 1;
    int curcount = 1;
    int index = 0;
    char c = *p;
   

    // first pass to count and find max
    while (*p) {
        c = *p;
        curcount = 0;
        while(*p == c) {
        
            curcount++;
            p++;
            index++;
        }
        
        if (curcount >= maxcount) {
        
            maxcount = curcount;
            table[index-1] = curcount;
        }
    }
   

    // second pass to output each max alphabet only once
    p=sen;
    index=0;
    cout<<"[";
    while (*p) {
        
        c=*p;
        if((table[index]==max)&&(isalpha(c))) {
        
            cout<<c<<",";
        }    
        
        p++;
        index++;
    }
    cout<<"]"<<endl;
}


int main()
{
    //char s[]="this is a sentence";
    //char s[]="thiis iss a senntencee";
    char s[]="thiisss iss a senntttenceee";
    //char s[]="thiisss iss a sennnntttenceee";
    maxRepCount1(s);
    maxRepCount2(s);
    return 0;
}

