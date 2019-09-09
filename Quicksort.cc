#include <cstdlib>
#include <iostream>

using namespace std;

const int SIZE = 10;

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

//Swaps 2 values in an array
void swap(int nums[], int i, int j){
	int temp = nums[j];
	nums[j] = nums[i];
	nums[i] = temp;
	//printArr(nums);
}

int partition(int nums[], int lo, int hi){

	int i = lo;
	int j = hi + 1;
	int p = nums[lo];//Partitioning item

	while(true){
		while(nums[++i] < p){ //Find something >= v
			if (i == hi)
				break;
		}
		while (nums[--j] > p){ //Find something <= v
			if(j == lo)
				break;
		}
		if (i >= j)		//Those two things are in the right order
			break;

		swap(nums, i, j); //If they are in the wrong order, swap the things
	}
	//Parition & item must swap so partition in right spot
	swap(nums, lo, j);
	return j;
}

//Helper sort - with correct parameters
void sort(int nums[], int lo, int hi){
	if(hi <= lo)
		return;

	int j = partition(nums,lo,hi);		//All things < nums[j] to left
										//All things > are to right
	sort(nums, lo, j-1);				//Sort left chunk
	sort(nums, j+1, hi);				//Sort right chunk
}

//Outward facing sort
void sort(int nums[]){
	sort(nums,0,SIZE-1);
}

int main(){
	srand(time(NULL));
	int nums[SIZE];
	for(int i(0); i < SIZE; i++){
			int m = rand() % (SIZE*3);
			nums[i] = m;
	}
	printArr(nums);
	sort(nums);
	printArr(nums);
}