#define Weeks 5



int nutrientData[Weeks][4] = {
                              {6,6,10,800},
                              {3,7,12,1000},
                              {3,8,14,1000},
                              {3,8,16,1000},
                              {0,7,20,1000}                           
                             };
                            
void assign()
{
  totalWeeks = Weeks;
  for(int i= 0;i<totalWeeks;i++)
  {
    for(int j=0;j<4;j++)
    {
      data[i][j] = nutrientData[i][j];
    }
  } 
}
