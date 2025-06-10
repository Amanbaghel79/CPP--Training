//The SOLID principle helps in reducing tight coupling. Tight coupling means a group of
// classes are highly dependent on one another which you should avoid in your code.
#include<iostream>
using namespace std;
class breadbaker{
   public:
   void bakebread(){
       cout<<"breaker is doing a job"<<endl;
   }
};
class inventorymanager{
    public:
    void manageinventory(){
        cout<<"managing the inventory"<<endl;
    }
};
int main(){
    breadbaker obj;
    obj.bakebread();
    inventorymanager obj1;
    obj1.manageinventory();
}
/*
++++DEFINATION->A class should have only one reason to change.
This means that a class should have only one job or responsibility, and all its methods 
and properties should contribute to that single purpose.
This principle helps in creating classes that are focused, cohesive, and easier to manage.

++++ADVANTAGES+++++
- Improved Maintainability   Since each class handles one responsibility.
- Better Readability	Focused classes are easier to read, understand, and explain.
- Simpler Testing	Unit testing becomes easier and more targeted, as each class has a clear and limited scope.
- Reusability	
-Supports Clean Architecture	
*/

/*QUES-->"We can define different methods with different names in a class — why do we 
need to separate them into different classes?"*/