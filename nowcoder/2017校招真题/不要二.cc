#include <iostream>
#include <vector>

using namespace std;

int main(){
    int w,h;
    cin >>w>>h;
    vector<vector<int>> box(w, vector<int>(h));
    int sum=0;
    
    for(int i=0;i<w;++i){
        for(int j=0;j<h;++j){
            if((i<2 || box[i-2][j]==0) && (j<2 || box[i][j-2]==0)){
                box[i][j]=1;
                ++sum;
            }
        }
    }
    cout << sum << endl;
    return 0;
}