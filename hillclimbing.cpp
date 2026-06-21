#include <iostream>
#include <vector>
using namespace std;

int hillClimbing(vector<int>& arr, int start) {
    int current=start;
    int n=arr.size();

    while(true){
        int left,right;
        if(current>0){
            left=arr[current-1];
        }else{
            left=-1;
        }

        if(current<n-1){
            right=arr[current+1];
        }else{
            right=-1;
        }

        if(left>arr[current] || right>arr[current]){
            if(left>right){
                current=current-1;
            }else{
                current=current+1;
            }
        }else{
            return current;
        }
    }
}

int main() {
    vector<int> arr={10,22,15,30,25,18};
    int start=2; 
    int result=hillClimbing(arr,start);

    cout<<"Peak found at index: "<<result<<endl;
    cout<<"Value: "<<arr[result]<<endl;
    return 0;
}