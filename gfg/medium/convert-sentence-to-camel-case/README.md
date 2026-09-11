# Convert Sentence to Camel Case

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a sentence  **`s`**, your task is to remove all spaces and convert it to  **Camel Case**. In Camel Case, words are joined without spaces, the first word keeps its original case, and each subsequent word starts with an uppercase letter.

 **Note:**  It is guaranteed that the sample test cases don't contain leading spaces.

 **Examples:** 

```
Input: s = "i got intern at geeksforgeeks"
Output: "iGotInternAtGeeksforgeeks"
Explanation: All spaces are removed and each word starts with a capital letter, except the first word which retains its original capitalization.
```

```
Input: s = "here comes the garden"
Output: "hereComesTheGarden"
Explanation: Spaces are removed and each word after the first is capitalized.
```

```
Input: s = "coding is fun"
Output: "codingIsFun"
Explanation: Spaces are removed, the first word retains its original case, and each subsequent word starts with a capital letter.
```

**Constraints:
**1 <= s.size() <= 106

The string  **s** contains only lowercase english alphabets and spaces.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-11T11:13:46.517Z  

```cpp
class Solution {
  public:
    // Function to convert the given string to Camel Case
    string convertToCamelCase(string& s) {
        // code here
        string res;
        bool captalize=false;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                captalize=true;
            }
            else if(captalize==true){
                res+=toupper(s[i]);
                captalize=false;
            }
            else{
                res+=s[i];
            }
        }
        return res;
    }
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/convert-sentence-to-camel-case/1)