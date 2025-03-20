#include<iostream>
#include<vector>
using namespace std;

void callback(int x){
  cout<<"callback called with value"<<x<<endl;
}

void fun(int x,void (*ptr)(int)){
    cout<<"function which have a function as aargument"<<endl;
    callback(x);
    cout<<x<<endl;
}

int compare(int a, int b) {
    return(a < b);
}

int compareA(int a, int b) {
    return(a > b);
}

void bubbleSort(vector<int>& v, int (*bubbleCompare)(int, int)) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        bool flag = false;
        for (int j = 0; j < n - i - 1; j++) {

            //if (v[j] < v[j + 1])
            if(bubbleCompare(v[j], v[j + 1]))
            {
                swap(v[j], v[j + 1]);
                flag = true;
            }
        }

        // Checking if the flag is set or not
        if (!flag)
            break;
    }
}
int main(){
    vector<int>v;
    bubbleSort(v,compareA);
   fun(5,callback);
}