#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

class ArrayDS 
{
private:
    int arr[10000];
    int size;

public:
    ArrayDS() { size = 0; }


    void inputElements() 
    {
        cout << "Enter number of elements: ";
        cin >> size;
        if (size > 100) 
        {
            cout << "Max 100 elements allowed. Setting size = 100.\n";
            size = 100;
        }

        for (int i = 0; i < size; i++) 
        {
            cout << "Enter element " << i + 1 << ": ";
            cin >> arr[i];
        }
    }


    void print() 
    {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        cout << "Array: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }


    int sum() 
    {
        int total = 0;
        for (int i = 0; i < size; i++)
            total += arr[i];
        return total;
    }


    float average() 
    {
        if (size == 0) return 0;
        return (float)sum() / size;
    }


    int getMaximum()
     {
        if (size == 0) return INT_MIN;
        int maxNum = arr[0];
        for (int i = 1; i < size; i++)
            if (arr[i] > maxNum)
                maxNum = arr[i];
        return maxNum;
    }


    int getMinimum() 
    {
        if (size == 0) return INT_MAX;
        int minNum = arr[0];
        for (int i = 1; i < size; i++)
            if (arr[i] < minNum)
                minNum = arr[i];
        return minNum;
    }


    int getSecondMaximum() 
    {
        if (size < 2) {
            cout << "Need at least 2 elements!\n";
            return INT_MIN;
        }
        int maxNum = INT_MIN;
        int secondMax = INT_MIN;
        for (int i = 0; i < size; i++) 
        {
            if (arr[i] > maxNum) 
            {
                secondMax = maxNum;
                maxNum = arr[i];
            }
            else if (arr[i] > secondMax && arr[i] < maxNum) 
            {
                secondMax = arr[i];
            }
        }
        return secondMax;
    }


    bool search() 
    {
        int target;
        cout << "Enter the number to search: ";
        cin >> target;
        for (int i = 0; i < size; i++)
            if (arr[i] == target) {
                cout << "Found at index: " << i << endl;
                return true;
            }
        return false;
    }


    int count() 
    {
        int target;
        cout << "Enter the number to count: ";
        cin >> target;
        int cnt = 0;
        for (int i = 0; i < size; i++)
            if (arr[i] == target)
                cnt++;
        return cnt;
    }


    void deleteAt() 
    {
        int index;
        cout << "Enter index to delete (0 to " << size-1 << "): ";
        cin >> index;
        if (index < 0 || index >= size) 
        {
            cout << "Error: index out of range!\n";
            return;
        }
        for (int i = index; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
        cout << "Element deleted successfully!\n";
    }


    void append() 
    {
        if (size >= 10000) {
            cout << "Array is full!\n";
            return;
        }
        int item;
        cout << "Enter number to append: ";
        cin >> item;
        arr[size] = item;
        size++;
        cout << "Element appended successfully!\n";
    }


    void prepend()
    { 
        if (size >= 10000) {
            cout << "Array is full!\n";
            return;
        }
        int item;
        cout << "Enter number to prepend: ";
        cin >> item;
        for (int i = size; i > 0; i--)
            arr[i] = arr[i - 1];
        arr[0] = item;
        size++;
        cout << "Element prepended successfully!\n";
    }

 
    bool isSorted() 
    {
        for (int i = 0; i < size - 1; i++)
            if (arr[i] > arr[i + 1])
                return false;
        return true;
    }


    void mergeSorted(ArrayDS &other) 
    {
        ArrayDS merged;
        int i = 0, j = 0, k = 0;
        while (i < size && j < other.size) 
        {
            if (arr[i] <= other.arr[j])
                merged.arr[k++] = arr[i++];
            else
                merged.arr[k++] = other.arr[j++];
        }
        while (i < size)
            merged.arr[k++] = arr[i++];
        while (j < other.size)
            merged.arr[k++] = other.arr[j++];
        merged.size = k;

        cout << "Merged array: ";
        merged.print();
    }


    void reverseInGroups() 
    {
        int k;
        cout << "Enter group size k: ";
        cin >> k;
        if (k <= 0) {
            cout << "Invalid group size!\n";
            return;
        }
        for (int i = 0; i < size; i += k) 
        {
            int start = i;
            int end = min(i + k - 1, size - 1);
            while (start < end) 
            {
                int temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
                start++;
                end--;
            }
        }
        cout << "Array reversed in groups!\n";
    }


    void moveZerosToEnd()
    {
        int pos = 0;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] != 0)
            {
                arr[pos] = arr[i];
                pos++;
            }
        }

        while (pos < size)
        {
            arr[pos] = 0;
            pos++;
        }
        cout << "Zeros moved to end!\n";
    }


    void findMissingElements()
    {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        int minVal = getMinimum();
        int maxVal = getMaximum();

        cout << "Missing elements between " << minVal << " and " << maxVal << ": ";
        bool found = false;
        for (int num = minVal; num <= maxVal; num++)
        {
            bool exists = false;
            for (int i = 0; i < size; i++)
            {
                if (arr[i] == num)
                {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                cout << num << " ";
                found = true;
            }
        }
        if (!found) cout << "None";
        cout << endl;
    }


    void countEvenOdd() 
    {
        int evenCount = 0;
        int oddcount = 0;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] % 2 == 0)
                evenCount++;
            else
                oddcount++;
        }
        cout << "Even count: " << evenCount << ", Odd count: " << oddcount << endl;
    }


    void rearrange()
    {
        int j = 0;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] < 0)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                j++;
            }
        }
        cout << "Negative numbers moved to front!\n";
    }


    void checkDuplicates()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++) 
            {
                if (arr[i] == arr[j])
                {
                    cout << "Duplicates Found: " << arr[i] << endl;
                    return;
                }
            }
        }
        cout << "No Duplicates\n";
    }

    
    void twoSum() 
    {
        int target;
        cout << "Enter Target sum: ";
        cin >> target;

        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] + arr[j] == target)
                {
                    cout << "Pair found: arr[" << i << "] + arr[" << j << "] = " << arr[i] << " + " << arr[j] << " = " << target << endl;
                    return;
                }
            }
        }
        cout << "No pair found that sums to " << target << endl;
    }


    int maxSubarraySum()
    {
        if (size == 0) return 0;
        int maxSoFar = arr[0];
        int currentMax = arr[0];

        for (int i = 1; i < size; i++)
        {
            currentMax = max(arr[i], currentMax + arr[i]);
            maxSoFar = max(maxSoFar, currentMax);
        }
        return maxSoFar;
    }


    int mostFrequent()
    {
        if (size == 0) return 0;
        int maxCount = 0;
        int mostFrequentNum = arr[0];

        for (int i = 0; i < size; i++)
        {
            int cnt = 0;
            for (int j = 0; j < size; j++)
            {
                if (arr[i] == arr[j])
                {
                    cnt++;
                }
            }
            if (cnt > maxCount)
            {
                maxCount = cnt;
                mostFrequentNum = arr[i];
            }
        }
        return mostFrequentNum;
    }


    void printSubarrays()
    {
        cout << "All subarrays:\n";
        for (int i = 0; i < size; i++)
        {
            for (int j = i; j < size; j++)
            {
                cout << "[ ";
                for (int k = i; k <= j; k++)
                {
                    cout << arr[k] << " ";
                }
                cout << "]\n";
            }
        }
    }


    bool isPermutation(int n)
    {
        if (size != n) return false;

        bool* visited = new bool[n + 1]();

        for (int i = 0; i < size; i++)
        {
            int x = arr[i];
            if (x < 1 || x > n)
            {
                delete[] visited;
                return false;
            }
            if (visited[x])
            {
                delete[] visited;
                return false;
            }
            visited[x] = true;
        }
        
        delete[] visited;
        return true;
    }


    double findMedian()
    {
        if (size == 0) return 0;
        
        int temp[10000];
        for (int i = 0; i < size; i++)
            temp[i] = arr[i];
        
        sort(temp, temp + size);

        if (size % 2 == 1)
            return temp[size / 2];
        else
        {
            int mid1 = temp[(size / 2) - 1];
            int mid2 = temp[size / 2];
            return (mid1 + mid2) / 2.0;
        }
    }


    int findMode()
    {
        if (size == 0) return 0;
        int maxCount = 0;
        int mode = arr[0];

        for (int i = 0; i < size; i++)
        {
            int cnt = 0;
            for (int j = 0; j < size; j++)
            {
                if (arr[i] == arr[j])
                    cnt++;
            }
            if (cnt > maxCount)
            {
                maxCount = cnt;
                mode = arr[i];
            }
        }
        return mode;
    }


    void rotateLeft(int k)
    {
        if (k <= 0) {
            cout << "Invalid rotation count!\n";
            return;
        }
        k = k % size; // FIXED: لو k اكبر من size
        
        for (int r = 0; r < k; r++)
        {
            int temp = arr[0];
            for (int i = 0; i < size - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            arr[size - 1] = temp;
        }
        cout << "Array rotated left by " << k << " positions!\n";
    }


    void rotateRight(int k)
    {
        if (k <= 0) {
            cout << "Invalid rotation count!\n";
            return;
        }
        k = k % size;
        
        for (int r = 0; r < k; r++)
        {
            int temp = arr[size - 1];
            for (int i = size - 1; i > 0; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[0] = temp;
        }
        cout << "Array rotated right by " << k << " positions!\n";
    }


    void removeDuplicates()
    {
        if (size == 0 || size == 1) {
            cout << "New size: " << size << endl;
            return;
        }
        
        int temp[10000];
        for (int i = 0; i < size; i++)
            temp[i] = arr[i];
        
        sort(temp, temp + size);
        
        int j = 0;
        for (int i = 0; i < size - 1; i++)
        {
            if (temp[i] != temp[i + 1])
            {
                arr[j] = temp[i];
                j++;
            } 
        }
        arr[j] = temp[size - 1];
        j++;
        
        size = j;
        cout << "Duplicates removed! New size: " << size << endl;
    }


    void bubbleSort()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++) 
            {
                if (arr[j] > arr[j + 1]) 
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        cout << "Array sorted using Bubble Sort!\n";
    }


    void frequencyTable()
    {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        
        bool visited[10000] = {false};

        cout << "\nFrequency Table:\n";
        cout << "----------------\n";
        
        for (int i = 0; i < size; i++)
        {
            if (visited[i] == true)
            {
                continue;
            }
            
            int count = 1; 
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] == arr[j])
                {
                    visited[j] = true;
                    count++;
                }
            }
            cout << arr[i] << " occurs " << count << " times" << endl; 
        }
    }


    bool isPalindrome()
    {
        for (int i = 0; i < size / 2; i++)
        {
            if (arr[i] != arr[size - 1 - i])
                return false;
        }
        return true;
    }


    void subArraySum()
    {
        int target;
        cout << "Enter target sum: ";
        cin >> target;

        for (int i = 0; i < size; i++)
        {
            int sum = 0;
            for (int j = i; j < size; j++) 
            {
                sum += arr[j];
                
                if (sum == target) 
                {
                    cout << "Subarray Found From Index " << i << " to " << j << endl;
                    return;
                }
            }
        }
        cout << "No Subarray With Given Sum" << endl;
    }

    
    int getSize() { return size; }
};

// ------------------- MENU -------------------
void displayMenu() 
{
    cout << "\n============ ARRAY OPERATIONS MENU ============\n";
    cout << "1.  Input Array Elements\n";
    cout << "2.  Print Array\n";
    cout << "3.  Sum of Elements\n";
    cout << "4.  Average of Elements\n";
    cout << "5.  Find Maximum\n";
    cout << "6.  Find Minimum\n";
    cout << "7.  Find Second Maximum\n";
    cout << "8.  Search Element\n";
    cout << "9.  Count Occurrences\n";
    cout << "10. Delete Element at Index\n";
    cout << "11. Append Element\n";
    cout << "12. Prepend Element\n";
    cout << "13. Check if Sorted\n";
    cout << "14. Reverse in Groups\n";
    cout << "15. Move Zeros to End\n";
    cout << "16. Find Missing Elements\n";
    cout << "17. Count Even and Odd\n";
    cout << "18. Rearrange (Negatives First)\n";
    cout << "19. Check Duplicates\n";
    cout << "20. Two Sum Problem\n";
    cout << "21. Max Subarray Sum (Kadane's)\n";
    cout << "22. Most Frequent Element\n";
    cout << "23. Print All Subarrays\n";
    cout << "24. Check if Permutation\n";
    cout << "25. Find Median\n";
    cout << "26. Find Mode\n";
    cout << "27. Rotate Left\n";
    cout << "28. Rotate Right\n";
    cout << "29. Remove Duplicates\n";
    cout << "30. Bubble Sort\n";
    cout << "31. Frequency Table\n";
    cout << "32. Check Palindrome\n";
    cout << "33. Subarray with Given Sum\n";
    cout << "0.  Exit\n";
    cout << "===============================================\n";
    cout << "Enter your choice: ";
}

int main() 
{
    ArrayDS a;
    int choice;
    
    cout << "====== Welcome to Array Data Structure Program ======\n";
    
    do {
        displayMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                a.inputElements();
                break;
            case 2:
                a.print();
                break;
            case 3:
                cout << "Sum: " << a.sum() << endl;
                break;
            case 4:
                cout << "Average: " << a.average() << endl;
                break;
            case 5:
                cout << "Maximum: " << a.getMaximum() << endl;
                break;
            case 6:
                cout << "Minimum: " << a.getMinimum() << endl;
                break;
            case 7:
                cout << "Second Maximum: " << a.getSecondMaximum() << endl;
                break;
            case 8:
                if (!a.search())
                    cout << "Element not found!\n";
                break;
            case 9:
                cout << "Count: " << a.count() << endl;
                break;
            case 10:
                a.deleteAt();
                break;
            case 11:
                a.append();
                break;
            case 12:
                a.prepend();
                break;
            case 13:
                cout << "Is array sorted? " << (a.isSorted() ? "Yes" : "No") << endl;
                break;
            case 14:
                a.reverseInGroups();
                break;
            case 15:
                a.moveZerosToEnd();
                break;
            case 16:
                a.findMissingElements();
                break;
            case 17:
                a.countEvenOdd();
                break;
            case 18:
                a.rearrange();
                break;
            case 19:
                a.checkDuplicates();
                break;
            case 20:
                a.twoSum();
                break;
            case 21:
                cout << "Max Subarray Sum: " << a.maxSubarraySum() << endl;
                break;
            case 22:
                cout << "Most Frequent Element: " << a.mostFrequent() << endl;
                break;
            case 23:
                a.printSubarrays();
                break;
            case 24: {
                int n;
                cout << "Enter n for permutation check: ";
                cin >> n;
                cout << "Is permutation of 1 to " << n << "? " << (a.isPermutation(n) ? "Yes" : "No") << endl;
                break;
            }
            case 25:
                cout << "Median: " << a.findMedian() << endl;
                break;
            case 26:
                cout << "Mode: " << a.findMode() << endl;
                break;
            case 27: {
                int k;
                cout << "Enter rotation count: ";
                cin >> k;
                a.rotateLeft(k);
                break;
            }
            case 28: {
                int k;
                cout << "Enter rotation count: ";
                cin >> k;
                a.rotateRight(k);
                break;
            }
            case 29:
                a.removeDuplicates();
                break;
            case 30:
                a.bubbleSort();
                break;
            case 31:
                a.frequencyTable();
                break;
            case 32:
                cout << "Is palindrome? " << (a.isPalindrome() ? "Yes" : "No") << endl;
                break;
            case 33:
                a.subArraySum();
                break;
            case 0:
                cout << "\nThank you for using the program!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
        
    } while(choice != 0);
    
    return 0;
}