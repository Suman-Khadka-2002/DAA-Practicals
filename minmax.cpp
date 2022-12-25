// CPP program to implement Min Max Algorithm using OOP.

#include<iostream>
using namespace std;

class MaxMinFinder
{
  public:
    int max, min;
    int a[100];

    void findMaxMin(int low, int high)
    {
      int max1, min1, mid;
      if(low == high)
      {
        max = min = a[low];
      }
      else if(low == high-1)
        {
          if(a[low] < a[high])
          {
            max = a[high];
            min = a[low];
          }
          else
          {
            max = a[low];
            min = a[high];
          }
        }
        else
        {
          mid = (low+high)/2;
          findMaxMin(low, mid);
          max1 = max; min1 = min;
          findMaxMin(mid+1, high);
          if(max < max1)
            max = max1;
          if(min > min1)
            min = min1;
        }
    }

    int getMax()
    {
      return max;
    }

    int getMin()
    {
      return min;
    }
};

int main ()
{
  MaxMinFinder mmf;
  int i, num;

  cout << "Enter the total number of numbers : ";
  cin >> num;

  cout << "Enter the numbers : " << endl;
  for (i=1; i<=num; i++)
    cin >> mmf.a[i];

  mmf.max = mmf.a[0];
  mmf.min = mmf.a[0];
  mmf.findMaxMin(1, num);
  cout << "Minimum element in an array : " << mmf.getMin() << endl;
  cout << "Maximum element in an array : " << mmf.getMax() << endl;
  return 0;
}

