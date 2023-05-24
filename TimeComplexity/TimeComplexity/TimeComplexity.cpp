#include <iostream>
using namespace std;
#include <chrono>


bool isSubsetAlgorithm1(int arr1[], int arr2[], int n, int m) {
    int j = 0;
    for (int i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (arr1[j] == arr2[i]) {
                break;
            }
        }
        if (j == n){
            return 0;
        }
    }
    return 1;
}

int binarySearch(int arr[], int low, int high, int point) {
    if (high < low || arr == NULL) {
        return -1;
    }
    else {
        int mid = (low + high) / 2;
        if ((mid == 0 || point > arr[mid - 1])){
            if (arr[mid] > point) {
                return binarySearch(arr, low, mid - 1, point);
            }
            else if (arr[mid] < point){
                return binarySearch(arr, mid + 1, high, point);
            }
            else {
                return mid;
            }
        }
    }
}

bool isSubsetAlgorithm2(int arr1[], int arr2[], int n, int m){
    for (int i = 0; i < m; i++) {
        if (binarySearch(arr1, 0, n - 1, arr2[i]) == -1) {
            return 0;
        }
    }
    return 1;
}



int main() {
    int n, m;
    //int n = 500000000;
    //int m = 10000;
    //int* arr1 = new int[n];
    //for (int i = 0; i < n; i++) {
      //  arr1[i] = 0;
    //}
    //int* arr2 = new int[m];
    //for (int i = 0; i < m; i++) {
      //  arr2[i] = 0;
    //}

    //std::chrono::time_point< std::chrono::system_clock > startTime;
    //std::chrono::duration< double, milli > elapsedTime;
    //Store the starting time
    //startTime = std::chrono::system_clock::now();
    //cout << isSubsetAlgorithm1(arr1, arr2, n, m) << endl;

    //elapsedTime = std::chrono::system_clock::now() - startTime;
    //cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

                    //** ALGORYTHM 1 **\\
    // n = 10^4, m = 10^3 ==>Execution took 0.1113 milliseconds.
    // n = 10^4, m = 10^4 ==>Execution took 0.1244 milliseconds.
    // n = 5*10^4, m = 10^3 ==>Execution took 0.1311 milliseconds.
    // n = 5*10^4, m = 10^4 ==>Execution took 0.1342 milliseconds.
    // n = 10^5, m = 10^3 ==>Execution took 0.1433 milliseconds.
    // n = 10^5, m = 10^4 ==>Execution took 0.1555 milliseconds.
    // n = 5*10^5, m = 10^3 ==>Execution took 0.1421 milliseconds.
    // n = 5*10^5, m = 10^4 ==>Execution took 0.1561 milliseconds.
    // n = 10^6, m = 10^3 ==>Execution took 0.2017 milliseconds.
    // n = 10^6, m = 10^4 ==>Execution took 0.2225 milliseconds.
    // n = 5*10^6, m = 10^3 ==>Execution took 0.1969 milliseconds.
    // n = 5*10^6, m = 10^4 ==>Execution took 0.2563 milliseconds.
    // n = 10^7, m = 10^3 ==>Execution took 0.4017 milliseconds.
    // n = 10^7, m = 10^4 ==>Execution took 0.4851 milliseconds.
    // n = 5*10^7, m = 10^3 ==>Execution took 0.4339 milliseconds.
    // n = 5*10^7, m = 10^4 ==>Execution took 0.4938 milliseconds.
    // n = 10^8, m = 10^3 ==>Execution took 0.5043 milliseconds.
    // n = 10^8, m = 10^4 ==>Execution took 0.5429 milliseconds.
    // n = 5*10^8, m = 10^3 ==>Execution took 0.5717 milliseconds.
    // n = 5*10^8, m = 10^4 ==>Execution took 0.58 milliseconds.


    n = 10000;
    m = 1000;
    int* arr1 = new int[n];
    for (int i = 0; i < n; i++) {
        arr1[i] = 0;
    }
    int* arr2 = new int[m];
    for (int i = 0; i < m; i++) {
        arr2[i] = 0;
    }

    std::chrono::time_point< std::chrono::system_clock > startTime;
    std::chrono::duration< double, milli > elapsedTime;
    //Store the starting time
    startTime = std::chrono::system_clock::now();
    cout << isSubsetAlgorithm2(arr1, arr2, n, m) << endl;

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "n = " << n << " m = " << m << " ";
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

    /////////////////////////////////


    n = 10000;
    m = 10000;
    int* arr39 = new int[n];
    for (int i = 0; i < n; i++) {
        arr39[i] = 0;
    }
    int* arr40 = new int[m];
    for (int i = 0; i < m; i++) {
        arr40[i] = 0;
    }


    //Store the starting time
    startTime = std::chrono::system_clock::now();
    cout << isSubsetAlgorithm2(arr39, arr40, n, m) << endl;

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "n = " << n << " m = " << m << " ";
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        /////////////////////////////////


    n = 50000;
    m = 1000;
    int* arr3 = new int[n];
    for (int i = 0; i < n; i++) {
        arr3[i] = 0;
    }
    int* arr4 = new int[m];
    for (int i = 0; i < m; i++) {
        arr4[i] = 0;
    }


    //Store the starting time
    startTime = std::chrono::system_clock::now();
    cout << isSubsetAlgorithm2(arr3, arr4, n, m) << endl;

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "n = " << n << " m = " << m << " ";
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        /////////////////////////////////


    n = 50000;
    m = 10000;
    int* arr5 = new int[n];
    for (int i = 0; i < n; i++) {
        arr5[i] = 0;
    }
    int* arr6 = new int[m];
    for (int i = 0; i < m; i++) {
        arr6[i] = 0;
    }


    //Store the starting time
    startTime = std::chrono::system_clock::now();
    cout << isSubsetAlgorithm2(arr5, arr6, n, m) << endl;

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "n = " << n << " m = " << m << " ";
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        /////////////////////////////////


    n = 100000;
    m = 1000;
    int* arr7 = new int[n];
    for (int i = 0; i < n; i++) {
        arr7[i] = 0;
    }
    int* arr8 = new int[m];
    for (int i = 0; i < m; i++) {
        arr8[i] = 0;
    }


    //Store the starting time
    startTime = std::chrono::system_clock::now();
    cout << isSubsetAlgorithm2(arr7, arr8, n, m) << endl;

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "n = " << n << " m = " << m << " ";
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        /////////////////////////////////


    n = 100000;
    m = 10000;
    int* arr9 = new int[n];
    for (int i = 0; i < n; i++) {
        arr9[i] = 0;
    }
    int* arr10 = new int[m];
    for (int i = 0; i < m; i++) {
        arr10[i] = 0;
    }


    //Store the starting time
    startTime = std::chrono::system_clock::now();
    cout << isSubsetAlgorithm2(arr9, arr10, n, m) << endl;

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "n = " << n << " m = " << m << " ";
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        /////////////////////////////////


    n = 500000;
    m = 1000;
    int* arr11 = new int[n];
    for (int i = 0; i < n; i++) {
        arr11[i] = 0;
    }
    int* arr12 = new int[m];
    for (int i = 0; i < m; i++) {
        arr12[i] = 0;
    }


    //Store the starting time
    startTime = std::chrono::system_clock::now();
    cout << isSubsetAlgorithm2(arr11, arr12, n, m) << endl;

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "n = " << n << " m = " << m << " ";
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        /////////////////////////////////


    n = 500000;
    m = 10000;
    int* arr13 = new int[n];
    for (int i = 0; i < n; i++) {
        arr13[i] = 0;
    }
    int* arr14 = new int[m];
    for (int i = 0; i < m; i++) {
        arr14[i] = 0;
    }


    //Store the starting time
    startTime = std::chrono::system_clock::now();
    cout << isSubsetAlgorithm2(arr13, arr14, n, m) << endl;

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "n = " << n << " m = " << m << " ";
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        /////////////////////////////////


    n = 1000000;
    m = 1000;
    int* arr15 = new int[n];
    for (int i = 0; i < n; i++) {
        arr15[i] = 0;
    }
    int* arr16 = new int[m];
    for (int i = 0; i < m; i++) {
        arr16[i] = 0;
    }


    //Store the starting time
    startTime = std::chrono::system_clock::now();
    cout << isSubsetAlgorithm2(arr15, arr16, n, m) << endl;

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "n = " << n << " m = " << m << " ";
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        /////////////////////////////////


    n = 1000000;
    m = 10000;
    int* arr17 = new int[n];
    for (int i = 0; i < n; i++) {
        arr17[i] = 0;
    }
    int* arr18 = new int[m];
    for (int i = 0; i < m; i++) {
        arr18[i] = 0;
    }


    //Store the starting time
    startTime = std::chrono::system_clock::now();
    cout << isSubsetAlgorithm2(arr17, arr18, n, m) << endl;

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "n = " << n << " m = " << m << " ";
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        /////////////////////////////////


    n = 5000000;
    m = 1000;
    int* arr19 = new int[n];
    for (int i = 0; i < n; i++) {
        arr19[i] = 0;
    }
    int* arr20 = new int[m];
    for (int i = 0; i < m; i++) {
        arr20[i] = 0;
    }

    //Store the starting time
    startTime = std::chrono::system_clock::now();
    cout << isSubsetAlgorithm2(arr19, arr20, n, m) << endl;

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "n = " << n << " m = " << m << " ";
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        /////////////////////////////////


    n = 5000000;
    m = 10000;
    int* arr21 = new int[n];
    for (int i = 0; i < n; i++) {
        arr21[i] = 0;
    }
    int* arr22 = new int[m];
    for (int i = 0; i < m; i++) {
        arr22[i] = 0;
    }


    //Store the starting time
    startTime = std::chrono::system_clock::now();
    cout << isSubsetAlgorithm2(arr21, arr22, n, m) << endl;

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "n = " << n << " m = " << m << " ";
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        /////////////////////////////////


    n = 10000000;
    m = 1000;
    int* arr23 = new int[n];
    for (int i = 0; i < n; i++) {
        arr23[i] = 0;
    }
    int* arr24 = new int[m];
    for (int i = 0; i < m; i++) {
        arr24[i] = 0;
    }


    //Store the starting time
    startTime = std::chrono::system_clock::now();
    cout << isSubsetAlgorithm2(arr23, arr24, n, m) << endl;

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "n = " << n << " m = " << m << " ";
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        /////////////////////////////////


    n = 10000000;
    m = 10000;
    int* arr25 = new int[n];
    for (int i = 0; i < n; i++) {
        arr25[i] = 0;
    }
    int* arr26 = new int[m];
    for (int i = 0; i < m; i++) {
        arr26[i] = 0;
    }


    //Store the starting time
    startTime = std::chrono::system_clock::now();
    cout << isSubsetAlgorithm2(arr25, arr26, n, m) << endl;

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "n = " << n << " m = " << m << " ";
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        /////////////////////////////////


    n = 50000000;
    m = 1000;
    int* arr27 = new int[n];
    for (int i = 0; i < n; i++) {
        arr1[i] = 0;
    }
    int* arr28 = new int[m];
    for (int i = 0; i < m; i++) {
        arr2[i] = 0;
    }


    //Store the starting time
    startTime = std::chrono::system_clock::now();
    cout << isSubsetAlgorithm2(arr27, arr28, n, m) << endl;

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "n = " << n << " m = " << m << " ";
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        /////////////////////////////////


    n = 50000000;
    m = 10000;
    int* arr29 = new int[n];
    for (int i = 0; i < n; i++) {
        arr29[i] = 0;
    }
    int* arr30 = new int[m];
    for (int i = 0; i < m; i++) {
        arr30[i] = 0;
    }


    //Store the starting time
    startTime = std::chrono::system_clock::now();
    cout << isSubsetAlgorithm2(arr29, arr30, n, m) << endl;

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "n = " << n << " m = " << m << " ";
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        /////////////////////////////////


    n = 100000000;
    m = 1000;
    int* arr31 = new int[n];
    for (int i = 0; i < n; i++) {
        arr31[i] = 0;
    }
    int* arr32 = new int[m];
    for (int i = 0; i < m; i++) {
        arr32[i] = 0;
    }


    //Store the starting time
    startTime = std::chrono::system_clock::now();
    cout << isSubsetAlgorithm2(arr31, arr32, n, m) << endl;

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "n = " << n << " m = " << m << " ";
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        /////////////////////////////////


    n = 100000000;
    m = 10000;
    int* arr33 = new int[n];
    for (int i = 0; i < n; i++) {
        arr33[i] = 0;
    }
    int* arr34 = new int[m];
    for (int i = 0; i < m; i++) {
        arr34[i] = 0;
    }


    //Store the starting time
    startTime = std::chrono::system_clock::now();
    cout << isSubsetAlgorithm2(arr33, arr34, n, m) << endl;

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "n = " << n << " m = " << m << " ";
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        /////////////////////////////////


    n = 500000000;
    m = 1000;
    int* arr35 = new int[n];
    for (int i = 0; i < n; i++) {
        arr35[i] = 0;
    }
    int* arr36 = new int[m];
    for (int i = 0; i < m; i++) {
        arr36[i] = 0;
    }


    //Store the starting time
    startTime = std::chrono::system_clock::now();
    cout << isSubsetAlgorithm2(arr35, arr36, n, m) << endl;

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "n = " << n << " m = " << m << " ";
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        /////////////////////////////////


    n = 500000000;
    m = 10000;
    int* arr37 = new int[n];
    for (int i = 0; i < n; i++) {
        arr37[i] = 0;
    }
    int* arr38 = new int[m];
    for (int i = 0; i < m; i++) {
        arr38[i] = 0;
    }


    //Store the starting time
    startTime = std::chrono::system_clock::now();
    cout << isSubsetAlgorithm2(arr37, arr38, n, m) << endl;

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "n = " << n << " m = " << m << " ";
    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;


                    //** ALGORYTHM 2 **\\
    // n = 10^4, m = 10^3 ==>Execution took 0.1267 milliseconds.
    // n = 10^4, m = 10^4 ==>Execution took 0.1763 milliseconds.
    // n = 5*10^4, m = 10^3 ==>Execution took 0.138 milliseconds.
    // n = 5*10^4, m = 10^4 ==>Execution took 0.2004 milliseconds.
    // n = 10^5, m = 10^3 ==>Execution took 0.1547 milliseconds.
    // n = 10^5, m = 10^4 ==>Execution took 0.2234 milliseconds.
    // n = 5*10^5, m = 10^3 ==>Execution took 0.1739 milliseconds.
    // n = 5*10^5, m = 10^4 ==>Execution took 0.257 milliseconds.
    // n = 10^6, m = 10^3 ==>Execution took 0.1757 milliseconds.
    // n = 10^6, m = 10^4 ==>Execution took 0.2677 milliseconds.
    // n = 5*10^6, m = 10^3 ==>Execution took 0.2278 milliseconds.
    // n = 5*10^6, m = 10^4 ==>Execution took 0.3039 milliseconds.
    // n = 10^7, m = 10^3 ==>Execution took 0.4052 milliseconds.
    // n = 10^7, m = 10^4 ==>Execution took 0.5892 milliseconds.
    // n = 5*10^7, m = 10^3 ==>Execution took 0.4347 milliseconds.
    // n = 5*10^7, m = 10^4 ==>Execution took 0.6169 milliseconds.
    // n = 10^8, m = 10^3 ==>Execution took 0.5246 milliseconds.
    // n = 10^8, m = 10^4 ==>Execution took 0.6366 milliseconds.
    // n = 5*10^8, m = 10^3 ==>Execution took 0.466 milliseconds.
    // n = 5*10^8, m = 10^4 ==>Execution took 0.6576 milliseconds.

    return 0;
}
