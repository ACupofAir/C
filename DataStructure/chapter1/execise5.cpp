void Transpose(int** a; int n) 
{
  for(int i = 0; i < n-1; i++) 
  {
    count++; //for for_i
    for(int j = i+1; j < n; j++)
    {
      count++; //for for_j
      swap(a[i][j], a[j][i]);
      count++; //for swap
    }
    count++; //for last for_j
  }
  count++; //for last for_i
}

void Transpose(int** a; int n) 
{
  for(int i = 0; i < n-1; i++) 
  {
    count++; //for for_i
    for(int j = i+1; j < n; j++)
    {
      count += 2; //for swap
    }
    count++; //for last for_j
  }
  count++; //for last for_i
}

