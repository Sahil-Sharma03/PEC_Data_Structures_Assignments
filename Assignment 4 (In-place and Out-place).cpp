#include <iostream>
using namespace std;
//Create  Insertion Sort void function for In place
void insertion_sort_InPlace(int arr[],int n){
    //Initialising variables i and j
    int i=0,j=i+1;
    while(j<=n-1){
        int temp=arr[j];
        while(i>=0){
            if(arr[i]>temp){
                arr[i+1]=arr[i];
                i--;
            }
            if(i==-1){arr[0]=temp;break;}
            if(arr[i]<=temp){arr[i+1]=temp;break;}
        }
        j++;
        i=j-1;
    }
    return;
}

//Insertion Sort Using Out-Place Algorithm
void insertion_sort_OutPlace(int arr[],int si,int ei){
    //si=starting index
    //ei=ending index
    if(si==ei){return;}
    int j=si+1;
    int temp=arr[j];
    while(si>=0){
        if(arr[si]>temp){
            arr[si+1]=arr[si];
            si--;
        }
        if(si==-1){arr[0]=temp;break;}
        if(arr[si]<=temp){arr[si+1]=temp;break;}
    }
    insertion_sort_OutPlace(arr,si+1,ei);
}
//Function to print array
void pfun(int arr[],int n){
    for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
}
int main(){
    int n;
    cout << "\n Data Structures Assignment-3 \n \n Submitted by \t Sahil Sharma \n Branch \t Electrical \n SID \t \t  21104019 \n \n " ;
    cout << "Implementing in-place and out place insertion sort \n ";
    // Take a set of inputs from the user in the form of an array
    cout<<"Enter the number of elements in the input array :";
    cin>>n;
    int arr[n],arr2[n];//Two array with same size and elements
    cout<<"Enter the elements being seperated by space : \t ";
    for(int i=0;i<n;i++){cin>>arr[i];}
    //copying arr to arr2
    for(int i=0;i<n;i++){arr2[i]=arr[i];}
    cout<<endl;
    cout<<"Input array : ";pfun(arr,n);
    //Calling insertion sort using in-place algorithm.
    insertion_sort_InPlace(arr,n);
    cout<<endl;
    cout<<"Array after using in place algorithm for Insertion sort : \t";
    
    pfun(arr,n);
    cout<<endl;
    //calling insertiong sort using out-place algorithm.
    insertion_sort_OutPlace(arr2,0,n-1);
    cout<<"Array after using Out place algorithm for Insertion sort : \t";
    
    pfun(arr,n);
    cout<<endl;

}