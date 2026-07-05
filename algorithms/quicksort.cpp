    #include<iostream>//quicksort using the hoare partition(pivot is the first element.)
    #include<vector>
    using namespace std;
    void input_vector(vector<int> &v){
        for(int i=0;i<(int)v.size();i++){
            cin>>v[i];
        }
        cout<<"the vector has been appended"<<endl;
    }
    int partition(vector<int>&v,int left,int right){
        int pivot=v[left];
        int i=left-1;
        int j=right+1;
        while(true){
            do{
                i++;
            }while(v[i]<pivot);
            do{
                j--;
            }while(v[j]>pivot);
            if(i>=j){
                return j;
            }
            swap(v[i],v[j]);
        }
    }
    void quicksort(vector<int>&v,int left,int right){
        if(left<right){
            int p=partition(v,left,right);
            quicksort(v,left,p);
            quicksort(v,p+1,right);
            return;
        }
    }
    int main(){
        int n;
        cout<<"enter the size of your sequence"<<endl;
        cin>>n;
        vector<int> vec(n);
        input_vector(vec);
        int l=0;
        int r=(int)vec.size()-1;
        quicksort(vec,l,r);
        for(int val: vec){
            cout<<val<<" ";
        }

        return 0;
    }