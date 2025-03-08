//overloading of subscript operator.
#include<iostream>
using namespace std;
class myclass{
    private:
    int arr[10];
  public:
  int operator[](int index){
     return arr[index];
  }
  void setdata(int ind,int val){
    arr[ind]=val;
  }
};
int main(){
   myclass obj;
for(int i=0;i<10;++i){
    obj.setdata(i,i+1);
}
for(int i=0;i<10;++i){
    cout<<obj[i]<<" "; // obj.operator[](i);
}
}