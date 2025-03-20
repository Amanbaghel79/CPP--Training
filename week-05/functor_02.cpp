#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct dog{
    int age;
    int weight;
    dog(int val,int wval): age(val),weight(wval){}
    bool operator<(dog &other){
        return age<other.age;
    } 
};
struct sortbyweight{
    bool operator()(dog &lhs ,dog &rhs){
        return lhs.weight<rhs.weight;
    } 
}; 
struct findbyweight{
    int m_weight;
    findbyweight(int v): m_weight(v){}
    bool operator()(dog d){
        return m_weight==d.weight;
    }
};
ostream& operator<<(ostream&os, dog d){
    os<<d.age<<" ";
     os<<d.weight<<" ";
    return os;
}
// istream &operator>>(istream &in, dog d){
//     in>>d.age>>d.weight;
//     return in;
// }
int main(){
    vector<dog> list={dog(1,3),dog(2,7),dog(3,5),dog(4,5)};
    sort(list.begin(),list.end());
    for(int i=0;i<list.size();i++){
        cout<<list[i]<<" ";
    }
    auto it=find_if(begin(list),end(list),findbyweight(4));
    if (it != end(list)) {
        cout << "Found dog with weight : " << *it << endl;
    } else {
        cout << "No dog found with weight " << endl;
    }

}