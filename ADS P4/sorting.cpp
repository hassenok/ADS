#include "sorting.h"


namespace sorting {

	//************
	// QuickSort *
	//************  
	int Parition(vector<int>& a, int p, int r) {
		int x = a[r];// letztes Element als pivot  setzen
		int i = p - 1;
		//vergleichen und das Array durch das Pivot sortieren  
		for (int j = p; j < r; j++) {
			if (a[j] <= x) {
				i++;
				swap(a[i], a[j]);
			}

		}
		swap(a[i + 1], a[r]);
		return i + 1;
	}
	void QuickSort(vector<int>& arr, int left, int right) {

		//***************************
		// implement quicksort here *
		//************ **************
		if (left < right) {
			int q = Parition(arr, left, right);
			QuickSort(arr, left, q - 1);// sortiere linke Teilfolge
			QuickSort(arr, q + 1, right);//sortiere rechte Teilfolge
		}
	}

	//************
	// MergeSort *
	//************

	//***************************
	// implement mergesort here *
	//***************************


	
	void Merge(vector<int>& a, vector<int>& b, int low, int pivot, int high) {
		
		vector<int> Larray(pivot - low + 1);
		vector<int> Rarray(high - pivot );
		//fill the left array
		for (int i = 0; i < Larray.size(); i++) {
			Larray[i] = a[low + i];
		}
		// fill the right one
		for (int i = 0; i < Rarray.size(); i++)
			Rarray[i] = a[pivot + 1 + i];

		//indexe initialisieren
		int leftindex = 0, rightindex = 0;
		int k = low;

		// Merge
		while (leftindex < Larray.size() && rightindex < Rarray.size()) {
			if (Larray[leftindex] <= Rarray[rightindex]) {
				a[k] = Larray[leftindex];
				leftindex++;
			}
			else {
				a[k] = Rarray[rightindex];
				rightindex++;
			}
			k++;
		}
		//den Rest auch mit kopieren
		while (leftindex < Larray.size()) 
			a[k++] = Larray[leftindex++];
			
		while (rightindex < Rarray.size())
			a[k++] = Rarray[rightindex++];
		
		



	}
	void MergeSort(vector<int>& a, vector<int>& b, int low, int high) {
		if (low < high) {
			int mid = (low + high) / 2;//split
			MergeSort(a, b, low, mid);//linker Teil
			MergeSort(a, b, mid + 1, high);// rechter Teil
			Merge(a, b, low, mid , high);// sortieren von den kleinsten Teilfolgen bis zu den Grössten
		}
	}
	



	//************
	// Heapsort  *
	//************
	void percDown(vector<int>& a, int n, int i) {
		int largest = i;
		int rightchild = 2 * i + 2;
		int leftchild = 2 * i + 1;
		// Vergleichen und den Baum balancieren
		if (leftchild<n && a[leftchild]>a[largest]) {
			largest = leftchild;
		}
		if (rightchild<n && a[rightchild]>a[largest])
			largest = rightchild;

		//swap and continue heapifying if root is not largest
		if (largest != i) {
			swap(a[i], a[largest]);
			percDown(a, n, largest);
		}
		
	}
	void HeapSort(vector<int>& a, int n) {


		//***************************
		// implement heapsort here *
		//***************************
		
		// build max heap - eine aufwärts sortierte Folge
		for (int i = n / 2 - 1; i >= 0; i--)
			percDown(a, n, i);
		//heapSort Jetzt
		for (int i = n - 1; i >= 0; i--) {
			swap(a[0], a[i]);

			percDown(a, i, 0);
		}

	}



	//************
	// Shellsort *
	//************
	void ShellSort(vector<int>& a, int n)
	{

		//***************************
		// implement shellsort here *
		//***************************
		 //n = (int)a.size();
		
		for (int gap =n/2; gap > 0; gap/=2) {
			for (int i = gap; i < n; i++) {
				int tmp = a[i];
				int j = i;
				for (; j >= gap && tmp < a[j - gap]; j -= gap) { 
					a[j] = a[j - gap];
				}
				a[j] = tmp;
			}
		}

	}


	void randomizeVector(vector<int>& array, int n) {
		array.resize(n);

		for (unsigned int i = 0; i < array.size(); i++)
			array[i] = rand() % 1000000;
	}


}

