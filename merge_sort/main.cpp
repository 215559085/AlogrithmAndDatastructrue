#include <iostream>
#include <vector>
using namespace std;
vector<int> merge_twins(vector<vector<int>>* twin_group){
    auto* tg = twin_group;
    int i = 1;
    do{
        vector<int> result;
        vector<int> Vs1 = (*tg)[i-1];
        vector<int> Vs2 = (*tg)[i];
        for(int a=0,b=0;a<Vs1.size()||b<Vs2.size();){
            if(a>=Vs1.size()){
                result.push_back(Vs2[b]);++b;
            } else if(b>=Vs2.size()){
                result.push_back(Vs1[a]);++a;
            } else{
                if(Vs1[a] > Vs2[b]){ result.push_back(Vs1[a]);++a;}
                else{result.push_back(Vs2[b]);++b;}
            }
        }
        tg->push_back(result);
        i+=2;
    }while(i < tg->size());
    delete(tg);
    return tg->back();
}
vector<int> merge_sort(vector<int>& Vs,int start,int end){
    auto* twin_group = new vector<vector<int>>;
    for(int i = start+1;i<end;){
        vector<int> twin = * new vector<int>;
        if(Vs[i] > Vs[i-1]){
            twin.push_back(Vs[i]);
            twin.push_back(Vs[i-1]);
        }
        else{
            twin.push_back(Vs[i-1]);
            twin.push_back(Vs[i]);
        }
        twin_group->push_back(twin);
        if(end-i == 1){
            vector<int> alone = * new vector<int>;
            alone.push_back(Vs[end]);
            twin_group->push_back(alone);
        }
        i+=2;
    }
    return merge_twins(twin_group);
}
int main() {
    vector<int> Vs={8,5,4,6,8,8,5,4,6,32,1,8,9,6,7,5,1,5,8,6,6,4,5,621,77,54,8,5,1,7,5,46,8,13,5,4,68,6,5,13,4,15};
    cout << "Hello, World!" << endl;
    vector<int> res = merge_sort(Vs,0,Vs.size()-1);
    for(auto i : res){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}