#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

const int SIZE = 1000;
size_t GO = 0;
 int LL = 1;

void insertionSort(int data[], int length){
	for(size_t i=1; i<length; i++){//loop through the entire array starting at the 2nd position
		int j(i);
		while(j>=1 and data[j]<data[j-1]){
			int temp = data[j];
			data[j] = data[j-1];
			data[j-1] = temp;
			j--;
			GO++;
		}
	}
}

void merge(int nums[], int aux[], int lo, int mid, int hi){
	//PRE:nums from lo to mid is sorted
	//PRE:nums from mid+ 1 to hi is sorted

	for(int i(lo); i<=hi; i++){
		aux[i] = nums[i];
	}
	int i = lo;
	int j = mid + 1;

	for(int k(lo); k <= hi; k++){
		//Case 3 - all that remains is the right half
		if(i > mid){
			nums[k] = aux[j];
			j++;
		}
		//Case 4 - all that remains is the left half
		else if(j > hi){
			nums[k] = aux[i];
			i++;
		}
		//Case 1 - right val < left val
		else if(aux[j] < aux[i]){
			nums[k] = aux[j];
			j++;
		}
		//Case 2 - right val > left val
		else{
			nums[k] = aux[i];
			i++;
		}
		
		GO++;
	}
}

void sort(int nums[], int aux[], int lo, int hi){

	//base case
	if(hi <= lo){
		return;
	}
	if(hi-lo+1 <= LL){
		insertionSort(nums+lo,hi-lo+1);
		//cout<<"IT DID THE THING"<<endl;
		return;
	}

	//seperate, sort each, then merge
	int mid = (lo+hi)/2;
	sort(nums, aux, lo, mid);
	sort(nums, aux, mid+1,hi);
	merge(nums, aux, lo, mid, hi);
}

void printArr(int nums[]){
	cout<<"[";
	for(int i(0); i < SIZE; i++){
		cout<<nums[i];
		if(i < SIZE-1){
			cout<<", ";
		}
	}
	cout << "]"<<endl;
}

int main(){
	for(int z(0); z<30; z++){
		LL=z;
	int tee=0;
	srand(time(NULL));
	for(int mat(0);mat<10000;mat++){
		
		int nums[SIZE];

		int test[SIZE];

		for(int i(0); i < SIZE; i++){
			int m = rand() % 5048;
			nums[i] = m;
			test[i] = m;
		}

		int aux[SIZE]; //for use in merging

		//printArr(nums);
		sort(nums,aux,0,SIZE-1);
		//printArr(nums);
		
		tee+=GO;
		GO=0;
	}
	cout<<LL<<" ; "<<(tee/10000)<<endl;
	}
}