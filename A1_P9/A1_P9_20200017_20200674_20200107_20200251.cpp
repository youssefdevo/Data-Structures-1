/*  name : ahmed said - id : 20200017
 *  name : aya mohamed monir - id : 20200107
 *  name : shrouk ayman ali - id : 20200251
 *  name : youssef nasser - id : 20200674
 */

#include <iostream>
#include <vector>
#include <random>
#include<cstdlib>
#include <chrono>
#include<iomanip>

using namespace std;
using namespace chrono;

class Sorter {

public:
    virtual void sort(vector<long long>& arr, long long size) {};
};


class SelectionSort :public Sorter {

public:
    SelectionSort() {
        cout << "<<Selection Sort>>\n____________________\n";
    }
    void sort(vector<long long>& arr, long long size) {

        for (long long i = 0; i < size - 1; i++)
        {
            int mini = i;
            for (long long j = i + 1; j < size; j++)
                if (arr[j] < arr[mini])
                    mini = j;

            swap(arr[mini], arr[i]);
        }
    }
};


class QuickSort :public Sorter {

public:
    QuickSort() {
        cout << "<<Quick Sort>>\n________________\n";
    }

    void sort(vector<long long>& arr, long long size) {

        quick(arr, 0, size - 1);

    }
    void quick(vector<long long>& arr, long long left, long long right) {

        long long i = left, j = right, pivot = arr[(left + right) / 2];

        while (i <= j) {
            while (arr[i] < pivot)
                i++;
            while (arr[j] > pivot)
                j--;
            if (i <= j) {
                swap(arr[i], arr[j]);
                i++; j--;
            }
        }

        if (left < j)
            quick(arr, left, j);

        if (i < right)
            quick(arr, i, right);

    }
};

class Testbed {
private:

public:

    //1) GenerateRandomList
    vector<long long> GenerateRandomList(long long min, long long max, long long size) {

        vector<long long>v;
        long long t = size;
        while (t--)
        {
            long long random = min + (rand() % max - min + 1);
            v.push_back(random);
        }

        return v;
    }

    //2) GenerateReverseOrderedList
    vector<long long> GenerateReverseOrderedList(long long min, long long max, long long size) {

        vector<long long>v;
        v = GenerateRandomList(min, max, size);

        int t = size - 1;
        for (long long i = t; i >= 0; i--)
            for (long long j = t; j > t - i; j--)
                if (v[j] > v[j - 1])
                    swap(v[j], v[j - 1]);

        return v;
    }

    //3) RunOnce
    auto  RunOnce(Sorter* sorter, vector<long long>& data, long long size) {

        auto start = high_resolution_clock::now();

        sorter->sort(data, size);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);


        return duration.count();
    }


    //4) RunAndAverage
    long long RunAndAverage(Sorter* sorter, int type, long long min, long long max, long long size, long long sets_num) {

        long long average = 0;

        long long t = sets_num;

        while (t--) {
            vector<long long>v;

            if (type == 0)
                v = GenerateRandomList(min, max, size);
            else
                v = GenerateReverseOrderedList(min, max, size);

            average += RunOnce(sorter, v, size);
        }

        return (average / sets_num);
    }

    //5) RunExperient

    void RunExperient(Sorter* sorter, int type, long long min, long long max, long long min_val, long long max_val, long long sets_num, long long step) {

        if (type == 0)
            cout << "Random List\n_____________\n";
        else
            cout << "Reversed List\n________________\n";

        cout << setw(12) << "[Set Size]" << setw(34) << "[Average time]\n";

        //Vector to store average if needed
        vector<long long>StoreAverage;

        long long average = 0;
        while (min_val <= max_val) {

            if (min_val == 0)
                min_val += step;

            average = RunAndAverage(sorter, type, min, max, min_val, sets_num);

            StoreAverage.push_back(average);

            cout << setw(9) << min_val << setw(26) << average << "   MicroSec" << '\n';

            min_val += step;
        }

        cout << "\n\n";
    }


};


int main() {
    Testbed obj;


    Sorter* Qrand = new QuickSort;
    obj.RunExperient(Qrand, 0, 0, 600000000, 0, 10000, 4, 500);

    Sorter* Srand = new SelectionSort;
    obj.RunExperient(Srand, 0, 0, 600000000, 0, 10000, 4, 500);



    Sorter* Qrev = new QuickSort;
    obj.RunExperient(Qrev, 1, 0, 600000000, 0, 10000, 4, 500);

    Sorter* Srev = new SelectionSort;
    obj.RunExperient(Srev, 1, 0, 600000000, 0, 10000, 4, 500);


    return 0;
}