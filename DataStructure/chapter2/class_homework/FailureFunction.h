#ifndef FAILUREFUNCTION_H
#define FAILUREFUNCTION_H        
                                                                      
void String::FailFunction()                                           
{                                                                     
  int lengthP = length();                                             
  f[0] = -1;                                                          
  for (int j = 1; j < lengthP; j++)                                   
  {                                                                   
    int i = f[j - 1];                                                 
    while ((str[j] != str[i + 1] ) && (i >= 0))                        
      i = f[i];                                                        
    if (str[j] == str[i + 1] && str[j + 1] != str[i + 2])                                          
      f[j] = i + 1;                                                    
    else                                                               
      f[j] = -1;                                                       
  }                                                                    
}                                                                      
                                                                       
#endif                                                                 
                                                                       