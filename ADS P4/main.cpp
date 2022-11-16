#define CATCH_CONFIG_RUNNER
#include "catch.h"

#include <iostream>
#include <omp.h>

#include "sorting.h"
#include "hashtable.h"

using namespace std;

//benchmark functions
void benchmark_quicksort();
void benchmark_mergesort();
void benchmark_heapsort();
void benchmark_shellsort();

int main(int argc, char argv) {

	Catch::Session().run();

	/*/ std::cout << "\nPress Enter to run measurement" << std::endl;
	std::cin.get(); /*/

		/*benchmark_quicksort();
		benchmark_mergesort();
		benchmark_heapsort();*/
		//benchmark_shellsort();
		/**
		 run all benchmarks *
		****/
	system("PAUSE");
		return 0;
}


//executes benchmark for quicksort
void benchmark_quicksort() {

	//file stream
	fstream quicksort_measurement;
	quicksort_measurement.open("quicksort.txt", ios::out | ios::app);

	//benchmark parameters / variables
	double dtime;
	int n_start = 1000;
	int n_step = 1000;
	int n_end = 1000000;

	vector<int> V;

	//actual benchmark loop
	for (int n = n_start; n <= n_end; n += n_step) {

		//"progress bar"
		//std::cout << "Running Quicksort with n: " << n << std::endl;

		//generate n random integers
		sorting::randomizeVector(V, n);

		//start measurement
		dtime = omp_get_wtime();

		//execzute sorting algorithm
		sorting::QuickSort(V, 0, V.size() - 1);

		//stop time
		dtime = omp_get_wtime() - dtime;

		//write to file
		quicksort_measurement << n << "\t" << setprecision(10) << scientific << dtime << endl;
	}

	//close file handle
	quicksort_measurement.close();
}

void benchmark_mergesort() {

	//file stream
	fstream mergesort_measurement;
	mergesort_measurement.open("mergesort.txt", ios::out | ios::app);

	//benchmark parameters / variables
	double dtime;
	int n_start = 1000;
	int n_step = 1000;
	int n_end = 1000000;

	vector<int> V;
	vector<int> b;
	b.resize(V.size());
	//actual benchmark loop
	for (int n = n_start; n <= n_end; n += n_step) {

		//"progress bar"
		//std::cout << "Running Mergesort with n: " << n << std::endl;

		//generate n random integers
		sorting::randomizeVector(V, n);

		//start measurement
		dtime = omp_get_wtime();

		//execzute sorting algorithm
		sorting::MergeSort(V, b, 0, V.size() - 1);

		//stop time
		dtime = omp_get_wtime() - dtime;

		//write to file
		mergesort_measurement << n << "\t" << setprecision(10) << scientific << dtime << endl;
	}

	//close file handle
	mergesort_measurement.close();
}

void benchmark_heapsort() {

	//file stream
	fstream heapsort_measurement;
	heapsort_measurement.open("heapsort.txt", ios::out | ios::app);

	//benchmark parameters / variables
	double dtime;
	int n_start = 1000;
	int n_step = 1000;
	int n_end = 1000000;

	vector<int> V;

	//actual benchmark loop
	for (int n = n_start; n <= n_end; n += n_step) {

		//"progress bar"
		//std::cout << "Running Heapsort with n: " << n << std::endl;

		//generate n random integers
		sorting::randomizeVector(V, n);

		//start measurement
		dtime = omp_get_wtime();

		//execzute sorting algorithm
		sorting::HeapSort(V, V.size());

		//stop time
		dtime = omp_get_wtime() - dtime;

		//write to file
		heapsort_measurement << n << "\t" << setprecision(10) << scientific << dtime << endl;
	}

	//close file handle
	heapsort_measurement.close();
}

void benchmark_shellsort() {

	//file stream
	fstream shellsort_measurement;
	shellsort_measurement.open("shellsort.txt", ios::out | ios::app);

	//benchmark parameters / variables
	double dtime;
	int n_start = 1000;
	int n_step = 1000;
	int n_end = 1000000;

	vector<int> V;

	//actual benchmark loop
	for (int n = n_start; n <= n_end; n += n_step) {

		//"progress bar"
		//std::cout << "Running Shellsort with n: " << n << std::endl;

		//generate n random integers
		sorting::randomizeVector(V, n);

		//start measurement
		dtime = omp_get_wtime();

		//execzute sorting algorithm
		sorting::ShellSort(V, V.size());

		//stop time
		dtime = omp_get_wtime() - dtime;

		//write to file
		shellsort_measurement << n << "\t" << setprecision(10) << scientific << dtime << endl;
	}

	//close file handle
	shellsort_measurement.close();
}