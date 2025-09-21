//Map 
#include <bits/stdc++.h>
using namespace std;

//Some operation on map that is mostly used in competitive programming and DSA interview
/*
Are as follows :

1. Creation
2. Insertion
3. Accessing values
4. Iterating over the map
5. Checking if a key exists 
6. Deletion
7. Size of the map
8. Clear the map
9. Count of a key
10. Lower bound and Upper bound
11. Swap two maps
12. Emplace
13. Find
14. Empty
15. Erase
16. Key and Value types
17. Custom comparator for keys
18. Nested maps
19. Using map with user-defined types
20. Performance considerations
21. Common pitfalls and best practices
22. When to use map vs unordered_map
23. Real-world applications of map
24. Summary
25. Conclusion
26. References


*/

//Code Implementation for all the above operations

int main() {
    // 1. Creation
    map<int, string> ;

    // 2. Insertion
    myMap[1] = "One";
    myMap.insert({2, "Two"});
    myMap.emplace(3, "Three");

    // 3. Accessing values
    cout << "Key 1: " << myMap[1] << endl;
    cout << "Key 2: " << myMap.at(2) << endl;

    // 4. Iterating over the map
    cout << "Iterating over map:" << endl;
    for (const auto &pair : myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // 5. Checking if a key exists
    if (myMap.find(2) != myMap.end()) {
        cout << "Key 2 exists in the map." << endl;
    }

    // 6. Deletion
    myMap.erase(3);
    cout << "After deleting key 3:" << endl;
    for (const auto &pair : myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // 7. Size of the map
    cout << "Size of the map: " << myMap.size() << endl;

    // 8. Clear the map
    myMap.clear();
    cout << "Size after clearing the map: " << myMap.size() << endl;

    return 0;
}