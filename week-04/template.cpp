//Class template
#include<iostream>
using namespace std;
template<class x> class myclass{
   private:
   struct data_var{
       int size;
       x *ptr;
   };
   data_var *s;
   public:
   myclass(int size){
       this->s=new data_var;
       this->s->size=size;
       this->s->ptr=new x[this->s->size];
   }
   void addelement(int ind,x val){
       if(ind>=0 && ind<=this->s->size-1){
       this->s->ptr[ind]=val;}
       else cout<<"out of bound";
   }
   void viewelement(int ind){
       int i=0;
       for(int i=0;i<this->s->size;i++){
           cout<<s->ptr[i]<<endl;
       }
   }
   
};
int main(){
  myclass <float>obj(4);
  obj.addelement(0,1.1);
  obj.addelement(1,2.2);
  obj.addelement(2,3.3);
  obj.addelement(3,4.4);
  obj.viewelement(0);
}