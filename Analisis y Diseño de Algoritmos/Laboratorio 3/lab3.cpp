#include <chrono>
#include <random>
#include <cstdlib>

#include <string>
#include <fstream>
#include <iostream>

/********************************************************************************
 * Timestamp class that measures time                                           *
 ********************************************************************************/
class Timestamp
{
public:
    Timestamp() {}
    ~Timestamp() {}

    void stamp();
    float operator-(const Timestamp& o);

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> now;
};

void Timestamp::stamp()
{
    now = std::chrono::high_resolution_clock::now();
}

float Timestamp::operator-(const Timestamp& o)
{
    std::chrono::duration<float, std::milli> diff = now - o.now;
    return diff.count();
}
/********************************************************************************/


/********************************************************************************
 * Utility functions                                                            *
 ********************************************************************************/
void genArrays(int** arrays, int n, int size, int lBound, int rBound)
{
    std::random_device rd;
    std::mt19937_64 mt(rd());
    std::uniform_real_distribution<double> dist(lBound, rBound);

    for(int j = 0; j < size; ++j)
    {
        int val = dist(mt);
        for(int i = 0; i < n; ++i)
        {
            arrays[i][j] = val;
        }
    }
}

void printArray(int* data, int size)
{
    for(int i = 0; i < size; ++i)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
}
/********************************************************************************/


/********************************************************************************
 * Merge (intercala) and MergeSort implementation                               *
 * mergesortInternal is just a sugar syntactic in order to just get the         *
 * data and the size of data as the only parameters in mergeSort                *
 ********************************************************************************/
void merge(int* data, int* aux, int p, int q, int r)
{
    int i {};
    int j {};
    for(i = p; i <= q; ++i)
    {
        aux[i] = data[i];
    }
    for(j = q + 1; j <= r; ++j)
    {
        aux[(q + 1) + (r - j)] = data[j];
    }
    i = p;
    j = r;

    for(int k = p; k <= r; ++k)
    {
        if(aux[i] <= aux[j])
        {
            data[k] = aux[i];
            ++i;
        }
        else
        {
            data[k] = aux[j];
            --j;
        }
    }
}

void mergeSortInternal(int* data, int* aux, int p, int r)
{
    if(p < r)
    {
        int q = (p + r) / 2;
        mergeSortInternal(data, aux, p, q);
        mergeSortInternal(data, aux, q + 1, r);
        merge(data, aux, p, q, r);
    }
}

void mergeSort(int* data, int size)
{
    int* aux = new int[size];
    mergeSortInternal(data, aux, 0, size - 1);
    delete[] aux;
}
/********************************************************************************/


/********************************************************************************
 * Quick sort comare function                                                   *
 * The third condition is omitted because the last ones ensures all conditions  *
 ********************************************************************************/
int compare(const void* p1, const void* p2)
{
    if(*(reinterpret_cast<const int*>(p1)) < *(reinterpret_cast<const int*>(p2)))
    {
        return -1;
    }
    if(*(reinterpret_cast<const int*>(p1)) == *(reinterpret_cast<const int*>(p2)))
    {
        return 0;
    }
    //  if(*(reinterpret_cast<const int*>(p1)) > *(reinterpret_cast<const int*>(p2)))
    //  {
            return 1;
    //  }
}
/********************************************************************************/


/********************************************************************************
 * Permormance test function                                                    *
 ********************************************************************************/
void performanceTest(int size, float& mt, float& qt)
{
    int* A = new int[size];
    int* B = new int[size];
    int** arrays = new int*[2] {A, B};

    float mergeTime {};
    float quickTime {};

    genArrays(arrays, 2, size, 0, 512);

    Timestamp begin;
    Timestamp end;

        begin.stamp();
            mergeSort(A, size);
        end.stamp();
        mergeTime = end - begin;

        begin.stamp();
            std::qsort(B, size, sizeof(int), compare);
        end.stamp();
        quickTime = end - begin;

    std::cout << "\tDuration of MergeSort: " << mergeTime << " ms" << std::endl;
    std::cout << "\tDuration of Quicksort: " << quickTime << " ms" << std::endl;

    mt = mergeTime;
    qt = quickTime;

    delete[] A;
    delete[] B;
    delete[] arrays;
}
/********************************************************************************/


/********************************************************************************
 * Main function                                                                *
 ********************************************************************************/
int main()
{
    int numTests {};
    std::cout << "Insert the number of tests (Stepped by 1000):\n";
    std::cout << "\ti.e. 100 is for testing n from 1K to 100K\n\t";
    std::cin  >> numTests;
    std::cout << std::endl;

    int rightLimit {numTests * 1000};

    float* msResults = new float[numTests];
    float* qsResults = new float[numTests];

    std::cout << "Performance test started!\n" << std::endl;
    for(int i = 1000, j = 0; i <= rightLimit; i += 1000, ++j)
    {
        std::cout << "Data size: " << i << ':' << std::endl;
        performanceTest(i, msResults[j], qsResults[j]);
    }

    std::string resultsFilename {"./results/resultsE5_"};
    resultsFilename += std::to_string(numTests) + ".dt";

    std::ofstream of {};
    of.open(resultsFilename);
    for(int i = 0; i < numTests; ++i)
    {
        of << msResults[i] << ' ' << qsResults[i] << '\n';
        of.flush();
    }
    of.close();

    delete[] msResults;
    delete[] qsResults;
    return 0;
}