#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


void greet();
int userInputTextFile();
int userInputSort1();
int userInputSort2();
void filterText(std::vector<std::string>& a, int textNum);
void bubbleSort(std::vector<std::string>& array, int size);
void selectionSort(std::vector<std::string>& a, int n);
void insertionSort(std::vector<std::string>& a, int n);
void merge(std::vector<std::string>& arr, int from, int mid, int to);
void merge_sort(std::vector<std::string>& a, int from, int to);
void quickSort(std::vector<std::string>& arr, int low, int high);
int partition (std::vector<std::string>& arr, int low, int high);
void swap(std::string& x, std::string& y);
void print(std::vector<std::string> a);
void find(std::vector<std::string> a);

int main(){
  greet();	//greets user and gives brief explanation of program
  std::string again = "yes";	//loops program
  while(again == "yes"){
  int textNum = userInputTextFile(); //user chooses text file
  int sortType1 = userInputSort1(); //user chooses sorting algorithm
  int sortType2 = userInputSort2(); //user chooses second sorting algorithm to compare
  std::vector<std::string> a;  //string vector to store text file
  
  filterText(a, textNum); //removes numbers, non siginificant punctuation, and the words "and", "the", 'an", "a."
  std::vector<std::string> b(a.begin(), a.end()); //makes a copy of vector a called vector b. the second sorting algorithm will sort vector b
  int avgTime = 0;
  srand(time(0));
  if(sortType1 == 1){ //if user chooses bubble sort, call bubble sort function
	for(int i = 0; i < 3; i++){
		int before = time(0);
		bubbleSort(a, a.size());
		int after = time(0);
		avgTime = avgTime + (after - before);
	}
	avgTime = avgTime / 3;
	std::cout << "Bubble Sort ran 3 times with full data set. Average time is: " << avgTime << std::endl;
	for(int i = 0; i < 3; i++){
		int before = time(0);
		bubbleSort(a, a.size() / 2);
		int after = time(0);
		avgTime = avgTime + (after - before);
	}
	avgTime = avgTime / 3;
	std::cout << "Bubble Sort ran 3 times with half data set. Average time is: " << avgTime << std::endl;
  }
  if(sortType1 == 2){ //if user chooses insertion sort, call insertion sort function
	for(int i = 0; i < 3; i++){
		int before = time(0);
		insertionSort(a, a.size());
		int after = time(0);
		avgTime = avgTime + (after - before);
	}
	avgTime = avgTime / 3;
	std::cout << "Insertion Sort ran 3 times with full data set. Average time is: " << avgTime << std::endl;
	for(int i = 0; i < 3; i++){
		int before = time(0);
		insertionSort(a, a.size() / 2);
		int after = time(0);
		avgTime = avgTime + (after - before);
	}
	avgTime = avgTime / 3;
	std::cout << "Insertion Sort ran 3 times with half data set. Average time is: " << avgTime << std::endl;
  }
  if(sortType1 == 3){// if user chooses merge sort, call merge sort function
	for(int i = 0; i < 3; i++){
		int before = time(0);
		merge_sort(a, 0, a.size()-1);
		int after = time(0);
		avgTime = avgTime + (after - before);
    }
    std::cout << "Merge Sort ran 3 times with full data set. Average time is: " << avgTime / 3 << std::endl;
    for(int i = 0; i < 3; i++){
		int before = time(0);
		merge_sort(a, 0, (a.size() / 2)-1);
		int after = time(0);
		avgTime = avgTime + (after - before);
    }
    std::cout << "Merge Sort ran 3 times with half data set. Average time is: " << avgTime / 3 << std::endl;
  }
  if(sortType1 == 4){// if user chooses quick sort, call quick sort function
	for(int i = 0; i < 3; i++){
		int before = time(0);
		quickSort(a, 0, a.size()-1);
		int after = time(0);
		avgTime = avgTime + (after - before);
	}
    std::cout << "Quick Sort ran 3 times with full data set. Average time is: " << avgTime / 3 << std::endl;
    for(int i = 0; i < 3; i++){
		int before = time(0);
		quickSort(a, 0, (a.size() / 2)-1);
		int after = time(0);
		avgTime = avgTime + (after - before);
	}
    std::cout << "Quick Sort ran 3 times with half data set. Average time is: " << avgTime / 3 << std::endl;
  }
  if(sortType1 == 5){// if user chooses selection sort, call selection sort function
	for(int i = 0; i < 3; i++){
		int before = time(0);
		selectionSort(a, a.size());
		int after = time(0);
		avgTime = avgTime + (after - before);
	}
    std::cout << "Selection Sort ran 3 times with full data set. Average time is: " << avgTime / 3 << std::endl;
    for(int i = 0; i < 3; i++){
		int before = time(0);
		selectionSort(a, a.size() / 2);
		int after = time(0);
		avgTime = avgTime + (after - before);
	}
    std::cout << "Selection Sort ran 3 times with half data set. Average time is: " << avgTime / 3 << std::endl;
  }

  if(sortType2 == 1){
    int before = time(0);
    bubbleSort(b, b.size());
    int after = time(0);
    std::cout << "Time elapsed with Bubble Sort: " << after - before << " seconds" << std::endl;
  }
  if(sortType2 == 2){ //if user chooses insertion sort, call insertion sort function
	for(int i = 0; i < 3; i++){
		int before = time(0);
		insertionSort(a, a.size());
		int after = time(0);
		avgTime = avgTime + (after - before);
	}
	avgTime = avgTime / 3;
	std::cout << "Insertion Sort ran 3 times with full data set. Average time is: " << avgTime << std::endl;
	for(int i = 0; i < 3; i++){
		int before = time(0);
		insertionSort(a, a.size() / 2);
		int after = time(0);
		avgTime = avgTime + (after - before);
	}
	avgTime = avgTime / 3;
	std::cout << "Insertion Sort ran 3 times with half data set. Average time is: " << avgTime << std::endl;
  }
  if(sortType2 == 3){// if user chooses merge sort, call merge sort function
    int before = time(0);
    merge_sort(b, 0, b.size()-1);
    int after = time(0);
    std::cout << "Time elapsed with Merge Sort: " << after - before << " seconds" << std::endl;
  }
  if(sortType2 == 4){// if user chooses merge sort, call merge sort function
    int before = time(0);
    quickSort(b, 0, b.size()-1);
    int after = time(0);
    std::cout << "Time elapsed with Quick Sort: " << after - before << " seconds" << std::endl;
  }
  if(sortType2 == 5){// if user chooses selection sort, call selection sort function
    int before = time(0);
    selectionSort(b, b.size());
    int after = time(0);
    std::cout << "Time elapsed with Selection Sort: " << after - before << " seconds" << std::endl;
  }
  print(a);	//print the alphabetically sorted vector
  find(a);	//search vector to find a user inputted word
  std::cout << "Do you want to go again? [yes/no]" << std::endl;
  std::cin >> again;
  if(again == "no")
	break;
  }
}

void greet(){
  std::string name;
  std::cout << "Hello, what is your name?"<<std::endl;
  std::cin >> name;
  std::cout << "Nice to meet you, " << name << std::endl << "In this program, you will be able to compare the run time efficiency of bubble sort, insertion sort, merge sort, quick sort, and selection sort. It will then sort a text file of your choosing with your selected sorting algorithm." << std::endl;
}

int userInputTextFile(){
  int inputFile;
  std::cout << "Please type in the corresponding number of the text file you wish to sort." << std::endl << "1. Explanation of how Crack is made, and a list of scientific papers" << std::endl << "2. Time Line of Space History" << std::endl << "3. Vitamin B12 and Vegans" << std::endl;
  std::cin >> inputFile;
  return inputFile;
}

int userInputSort1(){
  int inputSort1;
  std::cout << "Type in the corresponding number of the sorting methods you wish to compare." << std::endl << "1. Bubble Sort" << std::endl << "2. Insertion Sort" << std::endl << "3. Merge Sort" << std::endl << "4. Quick Sort" << std::endl << "5. Selection Sort" << std::endl;
  std::cin >> inputSort1;
  return inputSort1;
}

int userInputSort2(){
  int inputSort2;
  std::cout << "Input the second algorithm you want to compare." << std::endl;
  std::cin >> inputSort2;
  return inputSort2;
}

void filterText(std::vector<std::string>& a, int textNum){
  std::string textfile;
  if(textNum == 1){textfile = "crack.txt";}
  if(textNum == 2){textfile = "scifi.txt";}
  if(textNum == 3){textfile = "vitamin.txt";}

  std::ifstream infile;
  infile.open(textfile);
  if(infile.fail()){
    std::cout << "failed to open file."<<std::endl;
    return;
  }

  std::string trash;
  while(infile >> trash){
    if(trash == "a"||trash == "an"||trash == "the"||trash == "and"||trash =="AN"||trash == "A"||trash == "AND"||trash == "THE"){
      trash = "";
    }
	trash.erase(std::remove(trash.begin(), trash.end(), '\"'), trash.end());
		if((trash[0] >= 'a'&&trash[0] <= 'z')||(trash[0] >= 'A'&&trash[0] <= 'Z')){
		  a.push_back(trash);
		  }
    }
  infile.close();
}

void bubbleSort(std::vector<std::string>& array, int size){
 size = array.size();	//initialize size of array
 int count = size;
 for(int i = 0; i < count; i++){
   for(int j = 0; j < size; j++){
     if(array[j] > array[j+1]){	//if element is greater than its adjacent element, then swap
       swap(array[j], array[j+1]);	
     }
   }
   size = size - 1;	//size decreases after one element in the vector is sorted
 }
}


void selectionSort(std::vector<std::string>& a, int n)
{
  int i, j, min_idx;  
  for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++)	//loops through whole vector until minimum value of the entire vector is found
        if (a[j] < a[min_idx])
            min_idx = j;
        swap(a[min_idx], a[i]);  //continuously swaps new minimum value
	}
}

void insertionSort(std::vector<std::string>& a, int n){
    int i, j;  
    std::string key;	//holds current value
    for (i = 1; i < n; i++) //starts at the second element of vector
    {  
        key = a[i];  //key initalized as second element
        j = i - 1;  
        while (j >= 0 && a[j] > key) //j is greater than or equal to 0 and a[j] is bigger than key, then swap
        {  
            a[j + 1] = a[j];  
            j = j - 1;  
        }  
        a[j + 1] = key;  
    } 
}

void merge(std::vector<std::string>& arr, int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
    
    std::string L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
			arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  

    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void merge_sort(std::vector<std::string>& a, int from, int to)
{  
   if (from == to) { return; }
   int mid = (from + to) / 2;
   merge_sort(a, from, mid);
   merge_sort(a, mid + 1, to);
   merge(a, from, mid, to);
}

void quickSort(std::vector<std::string>& arr, int low, int high) {  
    if (low < high)  {  
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}

int partition (std::vector<std::string>& arr, int low, int high)  { 
    std::string pivot = arr[high];	//last number in vector is chosen as pivot
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++)  {  
        if (arr[j] < pivot)  {  
            i++;
            swap(arr[i], arr[j]);  
        }  
    }  
    swap(arr[i + 1], arr[high]);  
    return (i + 1);  
}

void swap(std::string& x, std::string& y){ //swaps two strings
  std::string temp = x;	//temp place holder for x
  x = y;	//x now has y value
  y = temp;	//y now has x value
}

void print(std::vector<std::string> a){	//asks user if they want to see first or last 50 words of vector
  std::string answer;
  std::cout << "Would you like to see the first or last 50 words? (type 'first' or 'last')" << std::endl;
  std::cin >> answer;
  if(answer == "last"){
    for(int i = a.size() - 50; i< a.size(); i++){
      std::cout << a[i] << " ";
    }
  }
  if(answer == "first"){
    for(int i = 0; i< 50; i++){
      std::cout << a[i] << " ";
    }
  }
  std::cout << std::endl;
}
void find(std::vector<std::string> a){	//finds a user specified word in vector
	std::string word;
	std::vector<int> index;
	int count = 0;
	std::cout << "Enter a word you want to search for: ";
	std::cin >> word;
	for(int i = 0; i < a.size(); i++){
		if(a[i] == word){	//if targetted word is found, then add index of element into vector and count how many times that word is found
			count++;
			index.push_back(i);
		}
	}
	std::cout << word <<" was found: " << count <<" times in vector index: ";
	for(int i = 0; i < count; i++){
		std::cout << index[i] << ", ";
		}
	std::cout << std::endl;
}
			
