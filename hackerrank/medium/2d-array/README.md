# Arrays - DS

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a $6 \times 6$ 2D array, $arr$, an hourglass is a subset of values with indices falling in the following pattern:

```
a b c  
  d  
e f g
```

There are $16$ hourglasses in a $6 \times 6$ array. The $hourglass\ sum$ is the sum of the values in an hourglass. Calculate the hourglass sum for every hourglass in $arr$, then print the $maximum$ hourglass sum.

**Example**  

$arr =$

    -9 -9 -9  1 1 1 
	 0 -9  0  4 3 2
	-9 -9 -9  1 2 3
	 0  0  8  6 6 0
	 0  0  0 -2 0 0
	 0  0  1  2 4 0

The $16$ hourglass sums are:

    -63, -34, -9, 12, 
	-10,   0, 28, 23, 
	-27, -11, -2, 10, 
	  9,  17, 25, 18
    
The highest hourglass sum is $28$ from the hourglass beginning at row $1$, column $2$:

    0 4 3
      1
    8 6 6
    
**Note:** If you have already solved the Java domain's *Java 2D Array* challenge, you may wish to skip this challenge.

**Function Description**

Complete the function $hourglassSum$ with the following parameter(s):

- $int\ arr[6][6]$: a 2-D array of integers  

**Returns**  

- $int$: the maximum hourglass sum

**Input Format**

Each of the $6$ lines of inputs $arr[i]$ contains $6$ space-separated integers $arr[i][j]$.

**Constraints**

- $-9 \le arr[i][j] \le 9$	
- $0 \le i,j \le 5$

**Output Format**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-25T12:50:10.796Z  

```cpp
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'reverseArray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

vector<int> reverseArray(vector<int> a) {
    int i =0;
    int j=a.size()-1;
    while(i<=j){
        swap(a[i],a[j]);
        i++;
        j--;
    }
    return a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> res = reverseArray(arr);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

```

---

[View on HackerRank](https://www.hackerrank.com/challenges/2d-array/problem)