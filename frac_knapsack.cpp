#include<iostream>
using namespace std;

float weight[20],profits[20],maxProfit=0.0,fraction[20];
int numberofitems,i,capacity,temp,j,remainingCapacity;

class FractionalKnapsack {
 public:
  void getData() {
    cout<<"Enter the maximum weight capacity of the bag: ";
    cin>>capacity;
    cout<<"Enter the number of objects you want to store inside the bag: ";
    cin>>numberofitems;
    cout<<"Enter the weight of the objects: ";
    for(i=1;i<=numberofitems;i++)
    {
      cin>>weight[i];
    }
    cout<<"Enter the profit per unit weight of the objects: ";
    for(i=1;i<=numberofitems;i++)
    {
      cin>>profits[i];
    }
  }
  void sortData() {
    for(i=1;i<=numberofitems;i++) {
      for(j=1;j<=numberofitems;j++) {
        if((profits[j]/weight[j]) < (profits[j+1]/weight[j+1])) {
          temp = profits[j];
          profits[j] = profits[j+1];
          profits[j+1] = temp;
          temp = weight[j];
          weight[j] = weight[j+1];
          weight[j+1] = temp;
        }
      }
    }
  }
  void calculation() {
    for(i=0;i<numberofitems;i++) {
      fraction[i] = 0.0;
    }
    remainingCapacity = capacity;
    for(i=0;i<numberofitems;i++) {
      if(weight[i] > remainingCapacity) {
        break;
      }
      fraction[i] = 1.0;
      remainingCapacity = remainingCapacity - weight[i];
    }
    if(i<numberofitems) {
      fraction[i] = remainingCapacity / weight[i];
    }
    for(i=0;i<numberofitems;i++) {
      maxProfit = maxProfit + (profits[i] * fraction[i]);
    }
  }
  void displayData() {
    cout<<"-------------------------------------------\n";
    cout<<"Item No.\t Weight\t Profits\t Fraction\n";
    cout<<"-----------------------------------------------\n";
    for(i=1;i<=numberofitems;i++) {
      cout<<i<<"\t\t"<<weight[i]<<"\t"<<profits[i]<<"\t\t"<<fraction[i]<<endl;
    }
    cout<<"MAXIMUM PROFIT: "<<maxProfit;
  }
};

// main function
int main() {
  FractionalKnapsack obj;
  obj.getData();
  obj.sortData();
  obj.calculation();
  obj.displayData();
  return 0;
}
