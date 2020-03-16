#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int>& Vs,int start,int end){
    int l=start,r=end,temp;
    if(l>=r) return;
        temp=Vs[l]; //挖坑，center,you can random it between lower and higher every time;
            while(l<r){
                while(temp < Vs[r]  && l<r) --r;//找一个比枢纽大的数
                Vs[l] = Vs[r];//移入坑中
                while(temp >= Vs[l] && l<r) ++l;//找一个比枢纽小或相等的数
                Vs[r] = Vs[l];//移入坑中
            }
            Vs[l] = temp;
            quick_sort(Vs,start,l-1);
            quick_sort(Vs,l+1,end);
}
int main() {
    vector<int> Vs = {10,2,3,5,4,6,9,8,7,0,0,0,9,8,7};
    quick_sort(Vs,0,Vs.size()-1);
    for(int i=0;i<Vs.size();++i){
        cout <<Vs[i]<< endl;
    }
    return 0;
}