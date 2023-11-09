#include <bits/stdc++.h>
using namespace std;


void preprocess_suffix(int *shift, int *borderPosition,
                       char *pattern, int m) {
   int i = m, j = m + 1;
   borderPosition[i] = j;

  
   while (i > 0) {
    
      while (j <= m && pattern[i - 1] != pattern[j - 1]) {
         if (shift[j] == 0)
            shift[j] = j - i;

        
         j = borderPosition[j];
      }
     
      i--;
      j--;
      borderPosition[i] = j;
   }
}

void preprocess_prefix(int *shift, int *borderPosition,
                       char *pattern, int m) {
   int i, j;
   j = borderPosition[0];
   for (i = 0; i <= m; i++) {
    
      if (shift[i] == 0)
         shift[i] = j;

      if (i == j)
         j = borderPosition[j];
   }
}

void BoyerMooreAlgorithm(char *text, char *pattern) {

   int s = 0, j;
   int m = strlen(pattern);
   int n = strlen(text);

   int borderPosition[m + 1], shift[m + 1];

   for (int i = 0; i < m + 1; i++)
      shift[i] = 0;

   preprocess_suffix(shift, borderPosition, pattern, m);
   preprocess_prefix(shift, borderPosition, pattern, m);

   while (s <= n - m) {

      j = m - 1;

      while (j >= 0 && pattern[j] == text[s + j])
         j--;

      if (j < 0) {
         cout << "Pattern found at index:" << s << endl;
         s += shift[0];
      }
      else
 
         s += shift[j + 1];
   }
}

int main() {
   char text[] = "TRUSTHARDTOOTHBRUSHES";
   char pattern[] = "TOOTH";

   BoyerMooreAlgorithm(text, pattern);

   return 0;
}

