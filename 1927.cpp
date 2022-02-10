#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<unsigned int>heap(1);

void reHeapup(int idx, int size){
    int p_idx = idx/2;
    int pKey = heap[p_idx];
    if(idx>0){
        if(heap[idx]<pKey){
            heap[p_idx] = heap[idx];
            heap[idx] = pKey;
            reHeapup(p_idx,size);
        }
    }
}
void inserHeap(int n, int size){
    if(size+1>heap.capacity()) heap.resize(size*2);
    heap[size] = n;
    // reheap_up size->last index and index of the insert num exist
    reHeapup(size,size);
}
void reHeapdown(int idx, int size){
    int l_idx = idx*2;
    int r_idx = idx*2+1;

    if(l_idx <= size){
        int small_idx;
        if(r_idx<=size) small_idx = heap[l_idx]<heap[r_idx] ? l_idx : r_idx;
        else small_idx = l_idx;
        if(heap[idx]>heap[small_idx]){
            int t = heap[small_idx];
            heap[small_idx] = heap[idx];
            heap[idx] = t;

            reHeapdown(small_idx,size);
        }
    }
}
void deleteHeap(int size){
    // cout<<"delete val = ";
    if(size==0&&heap[1]==0) cout<<0;
    else if(size==0&&heap[1]>0){
        cout<<heap[1];
        heap[1] = 0;
    }
    else {
        cout<<heap[1];
        heap[1] = heap[size+1];
        heap[size+1] = 0;
        reHeapdown(1,size);
    }
    cout<<"\n";
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int n,t;

    cin>>n;

    heap.push_back(0);
    int size = 0;
    for(int i=0;i<n;i++){
        cin>>t;
        if(t==0) {
            if(size>0)size--;
            deleteHeap(size);
        }
        if(t>0&&size==0){
            size++;
            heap[1]=t;
        }
        else if(t>0){
            size++;
            inserHeap(t,size);
        }
        // cout<<"size = "<<size;
        // for(int i=0;i<heap.size();i++) cout<<", "<<heap[i];
        // cout<<"\n";
    }


    return 0;
}
