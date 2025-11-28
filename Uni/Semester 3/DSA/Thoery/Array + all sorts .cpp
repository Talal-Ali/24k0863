    #include<iostream>
    using namespace std;

    class Array{
        int *array;
        int size;
        public:
            Array(int s, int* data)
            {
                size = s;
                array = new int[s];
                for(int i=0; i<s; i++)
                {
                    array[i] = data[i];
                }
            }
            Array(Array& other)
            {
                size = other.size;
                array = new int[size];
                for(int i =0; i<size; i++)
                {
                    array[i] = other.array[i];
                }
            }
            ~Array()
            {
                delete[] array;
            }
            Array& operator=(Array& other)
            {
                if (this != &other)
                {
                    delete[] array;
                    size = other.size;
                    array = new int[size];
                    for (int i = 0; i < size; i++)
                    {
                        array[i] = other.array[i];
                    }
                }
                return *this;
            }
            int* getArray(){return array;}
            void setArray(int* arr){array = arr;}
            int getSize(){return size;}
            void removedata(int d)
            {
                int newSize = 0;
                for (int i = 0; i < size; i++)
                {
                    if (array[i] != d)
                    {
                        array[newSize++] = array[i];
                    }
                }
                if (newSize == size) return;
                int* arr2 = new int[newSize];
                for (int i = 0; i < newSize; i++)
                {
                    arr2[i] = array[i];
                }

                delete[] array;
                array = arr2;
                size = newSize;
            }
            void printIteratively()
            {
                cout<<"{";
                for(int i=0; i<size; i++)
                {
                    
                    cout<<array[i]<<",";
                }
                cout<<"}"<<endl;
            }
            void printRecurrsively(int i)
            {
                if(i>=size)
                {
                    return;
                }
                cout<<array[i]<<endl;
                printRecurrsively(i+1);
            }
            // Searchers
            bool iLinearSearch(int search)
            {
                for(int i=0; i<size; i++)
                {
                    if(array[i] == search)
                    {
                        return true;
                    }
                }
                return false;
            }
            bool rLinearSearch(int search, int i)
            {
                if(i >= size)
                {
                    return false;
                }
                if(array[i] == search){
                    return true;
                }
                return rLinearSearch(search, i+1);
                
            }
            bool iBinarySearch(int search)
            {
                int lower = 0;
                int high = size-1;
                while(lower<=high)
                {
                    int mid = lower + (high-lower)/2;
                    if(array[mid] == search)
                    {
                        return true;
                    }
                    if(search > array[mid])
                    {
                        lower = mid+1;
                    }
                    if(search < array[mid])
                    {
                        high = mid-1;
                    }
                }
                return false;
            }
            bool rBinarySearch(int search, int lower, int high)
            {
                int mid = lower + (high-lower)/2; 
                if(lower>high){return false;}
                if(array[mid] == search)
                {
                    return true;
                }
                else if(array[mid] > search)
                {
                    return rBinarySearch(search, lower, mid-1);
                    
                }
                else
                {
                    return rBinarySearch(search, mid+1, high);
                }
            }
            bool iInterpolationSearch(int search)
            {
                int low = 0;
                int high = size-1;
                if(array[low] == search){return true;}
                
                while(search>= array[low] && search<= array[high] && low<=high)
                {
                    int pos = low + (((high - low) * (search - array[low])) / (array[high] - array[low]));
                    if(array[pos] == search)
                    {
                        return true;
                    }
                    if(array[pos]< search)
                    {
                        low = pos +1;
                    }
                    else
                    {
                        high = pos -1;
                    }
                }
            }
            bool rInterpolationsSearch(int search, int low, int high)
            {
                if((low > high || search < array[low] || search > array[high])){return false;}
                if (array[high] == array[low])
                    return (array[low] == search);

                int pos = low + (((high - low) * (search - array[low])) / (array[high] - array[low]));

                if (pos < low || pos > high)
                    return false;
                if(array[pos] == search){return true;}
                if(array[pos] < search)
                {
                    return rInterpolationsSearch(search, pos +1, high);
                }
                else
                {
                    return rInterpolationsSearch(search, low, pos -1);
                }
            }
            //Sorting Algos
            void iBubbleSort()//Stable
            {
                int i =0;
                bool swap = false;
                do{
                    swap = false;
                    while(i<=size-1)
                    {
                        if(array[i] > array[i+1])
                        {
                            int temp = array[i];
                            array[i] = array[i+1];
                            array[i+1] = temp;
                            swap = true;
                        }
                    }
                    i++;
                    
                }while(swap);
            }
            void rBubbleSort(int i)//Stable
            {
                if(i==size-1)
                {
                    return;
                }
                bool swap = false;
                for(int j = 0; j<size-i-1; j++)
                {
                    if(array[j]>array[j+1])
                    {
                        int temp = array[j];
                        array[j] = array[j+1];
                        array[j+1] = temp;
                        swap = true;
                    }
                    
                }
                if(!swap)
                {
                    return;
                }
                rBubbleSort(i+1);
            }
            void iInsertionSort()//Stable
            {
                for(int i = 1; i<size; i++)
                {
                    int key = array[i];
                    int j =i-1;
                    while(j>=0 && array[j] > key)
                    {
                        array[j+1] = array[j];
                        j--; 
                    }
                    array[j+1] = key;
                }
            }
            void rInsertionSort(int i =1, int j =-1)
            {
                if(i>=size){return;}
                int key = array[i];
                if(j == -1)
                    j = i-1;
                if(j<0 || array[j]<= key){
                    array[j+1] = key;
                }
                else{
                    array[j+1] = array[j];
                    rInsertionSort(i, j-1);// Inner Loop
                    return;
                }
                rInsertionSort(i+1, j); //Outer Loop

            }
            void iSelectionSort()
            {
                for(int i=0; i<size-1; i++)
                {
                    int min = i;
                    for(int j=i+1; j<size; j++)
                    {
                        if(array[j]< array[min])
                        {
                            min = j;
                        }
                    }
                    swap(array[i], array[min]);
                }   
            }
            void rSelectionSort(int i, int j, int min)
            {
                if(i>=size-1)
                {
                    return;
                }
                //Inner Loop is goin to terminate here hence here we are going to use the logic of the outer loop and recurrse in the inner loop
                if(j>=size)
                {
                    swap(array[i], array[min]);
                    rSelectionSort(i + 1, i + 2, i + 1);//Outer Loop
                    /*
                        rSelectionSort(i + 1, i + 2, i + 1) is doin 3 things at once (Assume i starts with 0)
                        1. min = i + 1
                        2. Next iteration of outerloop
                        3. j = i + 2
                    */  
                    return;
                }
                else // This block has the logic of the inner loop
                {
                    if(array[j]<array[min]){
                        min = j;
                    }
                }
                rSelectionSort(i, j+1, min);//Inner Loop is recurrsed through
            }
            int helper_combsort(int gap)
            {
                gap = (gap*10)/13;
                if(gap<1){gap = 1;}
                return gap;
            }
            void iCombSort()
            {
                int gap = size;
                bool swapped = true;
                while (gap != 1 || swapped == true)
                {
                    gap = helper_combsort(gap);
                    swapped = false;
                    for(int i=0; i<size-gap; i++)
                    {
                        if(array[i]>array[i+gap])
                        {
                            swap(array[i], array[i+gap]);
                            swapped = true;
                        }
                    }
                }
            }
            void rCombSort(int i, int gap, bool swapped)
            {
                if (gap == 1 && !swapped)
                    return;
                if (i >= size - gap)
                {
                    gap = helper_combsort(gap);
                    rCombSort(0, gap, false);
                    return;
                }
                if (array[i] > array[i + gap])
                {
                    swap(array[i], array[i + gap]);
                    swapped = true;
                }
                rCombSort(i + 1, gap, swapped);
            }
            void iShellSort()
            {
                for(int gap =size/2; gap>0; gap/= 2)
                {
                    for(int i=gap; i<size; i++)
                    {
                        int temp = array[i];
                        int j;
                        for(int j = i; j>=gap && array[j-gap]>temp; j++)
                        {
                            array[j] = array[j-gap];
                        }
                        array[j] = temp;
                    }

                }
            }
            void rShellSort(int gap, int i, int j, int temp, bool shifting)
            {
                if (gap < 1)
                    return;
                if (shifting)
                {
                    if (j < gap || array[j - gap] <= temp)
                    {
                        array[j] = temp;
                        rShellSort(gap, i + 1, i + 1, 0, false);
                        return;
                    }
                    array[j] = array[j - gap];
                    rShellSort(gap, i, j - gap, temp, true);
                    return;
                }
                if (i >= size)
                {
                    rShellSort(gap / 2, gap / 2, gap / 2, 0, false);
                    return;
                }

                temp = array[i];
                rShellSort(gap, i, i, temp, true);
            }
        void merge(int *arr, int left, int mid, int right)
        {
            int n1 = mid - left + 1;
            int n2 = right - mid;

            int *L = new int[n1];
            int *R = new int[n2];

            for (int i = 0; i < n1; i++)
                L[i] = arr[left + i];
            for (int j = 0; j < n2; j++)
                R[j] = arr[mid + 1 + j];

            int i = 0, j = 0, k = left;

            while (i < n1 && j < n2)
            {
                if (L[i] <= R[j])
                    arr[k++] = L[i++];
                else
                    arr[k++] = R[j++];
            }


            while (i < n1)
                arr[k++] = L[i++];

            while (j < n2)
                arr[k++] = R[j++];

            delete[] L;
            delete[] R;
        }

        void imergesort()
        {
            for(int curSize = 1; curSize<= size -1; curSize*=2)
            {
                for(int left = 0; left<size -1; left += 2*curSize)
                {
                    int mid = min(left + curSize -1, size -1);
                    int right  = min(left + 2 * curSize -1, size-1);
                    merge(array, left, right, mid);
                }
            }
        }
        void rmergesort(int left, int right)
        {
            if (left >= right)
                return;

            int mid = left + (right - left) / 2;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
            rmergesort(left, mid);
            rmergesort(mid + 1, right);

            merge(array, left, mid, right);
        }
        void quick_sort_Naive()
        {
            int n = size;
            int pivot = array[n-1];

            int* temp = new int[n];
            int j = 0;

            for(int i = 0; i<n; i++)
            {
                if(array[i]<=pivot)
                {
                    temp[j++] = array[i];
                }
            }
            for(int i = 0; i<n; i++)
            {
                if(array[i] > pivot)
                {
                    temp[j++] = array[i];
                }
            }

        }
        int quicksorthelper(int left, int right)
        {
            int pivot = array[right];
            int i = left - 1;

            for (int j = left; j < right; j++)
            {
                if (array[j] < pivot)
                {
                    i++;
                    swap(array[i], array[j]);
                }
            }

            swap(array[i + 1], array[right]);
            return i + 1;
        }

        void rQuickSort(int left, int right)
        {
            if (left >= right)
                return;

            int pivotIndex = quicksorthelper(left, right);
            rQuickSort(left, pivotIndex - 1);
            rQuickSort(pivotIndex + 1, right);
        }
        int getMax()
        {
            int mx = array[0];
            for (int i = 1; i < size; i++)
                if (array[i] > mx)
                    mx = array[i];
            return mx;
        }

        void countingSort(int exp)
        {
            int *output = new int[size];
            int count[10] = {0};

            for (int i = 0; i < size; i++)
                count[(array[i] / exp) % 10]++;

            for (int i = 1; i < 10; i++)
                count[i] += count[i - 1];

            for (int i = size - 1; i >= 0; i--)
            {
                int digit = (array[i] / exp) % 10;
                output[count[digit] - 1] = array[i];
                count[digit]--;
            }

            for (int i = 0; i < size; i++)
                array[i] = output[i];

            delete[] output;
        }

        void radixSort()
        {
            int m = getMax();

            for (int exp = 1; m / exp > 0; exp *= 10)
                countingSort(exp);
        }



    };


    int main()
    {
        /*
            List of Functions

            Attributes:
                int *array
                int size

            Constructors & Destructors:
                1. Array(int s, int* data)
                2. Array(Array& other)
                3. ~Array()
                4. Array& operator=(Array& other)

            Regular Functions
                1. void removedata(int d): d -> data to remove (deletes redundant data as well)
                2. void printIteratively()
                3. void printRecurrsively(int i): i -> Starting position
                4. int* getArray()
                5. void setArray(int* arr)
                6. int getSize()

            (Functions starting with i are iterative approaches and r are recursive)

            ──────────────────────────────────────────────────────────────
            Searches:
                1. bool iLinearSearch(int search): search -> data to search
                2. bool rLinearSearch(int search, int i): search -> data to search, i -> Starting Position
                3. bool iBinarySearch(int search): search -> data to search
                4. bool rBinarySearch(int search, int lower, int high): search -> data to search, lower -> start of array, high -> size of array -1
                5. bool iInterpolationSearch(int search): search -> data to search
                6. bool rInterpolationsSearch(int search, int low, int high): search -> data to search, low -> start index, high -> end index

            ──────────────────────────────────────────────────────────────
            Sorts:
                Stable Sorts:
                1. void iBubbleSort() — iterative bubble sort
                2. void rBubbleSort(int i): i -> initial position
                3. void iInsertionSort()
                4. void rInsertionSort(int i = 1, int j = -1): i -> start of outer loop, j -> start of inner loop

                Unstable Sorts:
                5. void iSelectionSort()
                6. void rSelectionSort(int i, int j, int min): i -> start of outer loop, j -> start of inner loop, min -> initialized to i
                7. int helper_combsort(int gap): used internally by CombSort to reduce gap
                8. void iCombSort()
                9. void rCombSort(int i, int gap, bool swapped = false): i -> start with 0, gap -> start with size
                10. void iShellSort()
                11. void rShellSort(int gap, int i, int j, int temp, bool shift): gap -> size/2, i -> size/2, j -> size/2, temp -> 0, shift -> false

                Divide & Conquer Sorts:
                12. void imergeSort(): iterative merge sort
                13. void rmergeSort(int curSize, int left): recursive merge sort
                14. void quick_sort_Naive(): simple one-pass pivot rearrangement (demonstration only)
                15. void rQuickSort(int left, int right): recursive quick sort using partition helper
                16. int quicksorthelper(int left, int right): partition logic used by quicksort

                Non-Comparative Sorts:
                17. void radixSort(): iterative LSD (least significant digit) radix sort using counting sort per digit
                18. void countingSort(int exp): internal helper for radixSort (sorts by a single digit)
                19. int getMax(): finds maximum element to determine number of digits
                20. void rRadixSort(int exp, int max): recursive version of radix sort (calls countingSort for each digit)

            ──────────────────────────────────────────────────────────────
            Notes:
                • All recursive functions (r-prefixed) use nested recursion where possible to mirror loop structures.
                • Sorting functions assume integer arrays (but can be extended for templates).
                • Stable sorts preserve order of equal elements; unstable sorts do not.
                • QuickSort and MergeSort are comparison-based O(n log n) sorts.
                • RadixSort is non-comparative and runs in O(n · k), where k = number of digits.
        */

        int *arr = new int[5];
        for (int i = 0; i < 5; i++)
            cin >> arr[i];

        Array a(5, arr);
        a.printIteratively();
        a.rQuickSort(0, a.getSize() - 1);
        a.printIteratively();
    }