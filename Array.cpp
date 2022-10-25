#include<iostream>
using namespace std;

struct Array
{
 int A[10];
 int size;
 int length;
};
void Display( Array arr)
{
 int i;
 for(i=0;i<arr.length;i++)
 cout<<arr.A[i]<<" ";
} 

void Append( Array *arr,int x)
 {
 if(arr->length<arr->size)
 arr->A[arr->length++]=x;
 }

 int Delete( Array *arr,int index)
{
 int x=0;
 int i;
 if(index>=0 && index<arr->length)
 {
 x=arr->A[index];
 for(i=index;i<arr->length-1;i++)
 arr->A[i]=arr->A[i+1];
 arr->length--;
 return x;
 }
 return 0;
}
 void Insert(Array *arr,int index,int x)
 {
 int i;
 
 if(index>=0 && index <=arr->length)
 {
 for(i=arr->length;i>index;i--)
 arr->A[i]=arr->A[i-1];
 arr->A[index]=x;
 arr->length++;
 }
 }

 void swap(int *x,int *y)
 {
 int temp=*x;
 *x=*y;
 *y=temp;
 }
int LinearSearch( Array *arr,int key)
{
 int i;
 for(i=0;i<arr->length;i++)
 {
 if(key==arr->A[i])
 {
 swap(&arr->A[i],&arr->A[0]);
 return i;
 }
 }
 return -1;
}

int BinarySearch(Array arr,int key)
{
 int l,mid,h;
 l=0;
 h=arr.length-1;
 while(l<=h)
 {
 mid=(l+h)/2;
 if(key==arr.A[mid])
 return mid;
 else if(key<arr.A[mid])
 h=mid-1;
 else
 l=mid+1;
 }
return -1;
}
 Array* Union( Array *arr1,struct Array *arr2)
{
 int i,j,k;
 i=j=k=0;
 
struct Array *arr3=new Array;
 
 while(i<arr1->length && j<arr2->length)
 {
 if(arr1->A[i]<arr2->A[j])
 arr3->A[k++]=arr1->A[i++];
 else if(arr2->A[j]<arr1->A[i])
 arr3->A[k++]=arr2->A[j++];
 else
 {
 arr3->A[k++]=arr1->A[i++];
 j++;
 }
 }
 for(;i<arr1->length;i++)
 arr3->A[k++]=arr1->A[i];
 for(;j<arr2->length;j++)
 arr3->A[k++]=arr2->A[j];
 
 arr3->length=k;
 arr3->size=10;
 
 return arr3;
}
 Array* Intersection( Array *arr1, Array
*arr2)
{
 int i,j,k;
 i=j=k=0;
 
 struct Array *arr3= new Array;
 
 while(i<arr1->length && j<arr2->length)
 {
 if(arr1->A[i]<arr2->A[j])
 i++;
 else if(arr2->A[j]<arr1->A[i])
 j++;
 else if(arr1->A[i]==arr2->A[j])
 {
 arr3->A[k++]=arr1->A[i++];
 j++;
 }
 }
 
 arr3->length=k;
 arr3->size=10;
 
 return arr3;
}

int MissingNum(Array arr,int n){
    int sum=0;
    for(int i = 0 ; i<arr.length;i++){
        sum = sum+arr.A[i];
    }
    int s = n*(n+1)/2;
    int ms = s-sum;

    return ms;

}
void Reverse(struct Array *arr)
{
 int *B;
 int i,j;
 
 B= new int [arr->length];
 for(i=arr->length-1,j=0;i>=0;i--,j++)
 B[j]=arr->A[i];
 for(i=0;i<arr->length;i++)
 arr->A[i]=B[i];
 
}
void Reverse2( Array *arr)
{
 int i,j;
 for(i=0,j=arr->length-1;i<j;i++,j--)
 {
 swap(&arr->A[i],&arr->A[j]);
 }
}

int isSorted( Array arr)
{
 int i;
 for(i=0;i<arr.length-1;i++)
 {
 if(arr.A[i]>arr.A[i+1])
 return 0;
 }
 return 1;
}

Array* Merge( Array *arr1, Array *arr2)
{
 int i,j,k;
 i=j=k=0;
 
  Array *arr3 = new int[arr1->length + arr2->length
  ];
 
 while(i<arr1->length && j<arr2->length)
 {
 if(arr1->A[i]<arr2->A[j])
 arr3->A[k++]=arr1->A[i++];
 else
 arr3->A[k++]=arr2->A[j++];
 }
 for(;i<arr1->length;i++)
 arr3->A[k++]=arr1->A[i];
 for(;j<arr2->length;j++)
 arr3->A[k++]=arr2->A[j];
 arr3->length=arr1->length+arr2->length;
 arr3->size=10;
 
 return arr3;
}

void Hash_ms_el(Array arr){
    int H[13]={0,0,0,0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < arr.length; i++)
    {
        H[arr.A[i]]++;
    }
    for (int i = 1; i <=12; i++)
    {
        if(H[i]==0){
            cout<< i<<" ";
        }
    }

}
void Duplicate(Array arr){
    int lastDuplicate=0;
    for (int i = 0; i < arr.length; i++)
    {
        if(arr.A[i]==arr.A[i+1]&& arr.A[i]!=lastDuplicate){
            lastDuplicate=arr.A[i];
            cout<<lastDuplicate<<" ";
        }
    }
}

void CountDuplicates(Array arr){

    for(int i=0;i<arr.length;i++){

        if(arr.A[i]==arr.A[i+1]){
            int j=i+1;
            while(arr.A[i]==arr.A[j])j++;
            cout<<arr.A[i]<<" is appearing "<<j-i<< " times"<<endl;
            i=j-1;
        }
    }
}

void Hash_Table_Duplicate(Array arr){

    int H[10]={0};
    for (int i= 0;i < arr.length;i++){
        H[arr.A[i]]++;
    }
    for (int i = 0; i <= 10; i++)
    {
        if(H[i]>1){
            cout<<i<<" is apearing "<<H[i]<<" times"<<endl;
        }
    }
    
}
void Sum_Pair(Array arr, int k){

    int i=0,j=arr.length-1;
    
    while(i<j){

        if(arr.A[i]+arr.A[j]==k){
            cout<<arr.A[i] << " + "<< arr.A[j]<<" = "<<k<<endl;
            j--,i++;
        }
        else if(arr.A[i]+arr.A[j]<k){
            i++;
        }
        else 
        j--;
    }
}

int main()
{
 struct Array arr1={{4,7,8,9,10,13,14},15,7}; 
 Sum_Pair(arr1,18);
 
 
return 0; 
}