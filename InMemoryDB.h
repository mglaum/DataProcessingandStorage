#include <string>
#include <iostream>
#include <stack>

using namespace std;

class InMemoryDB {
    unordered_map<string, int> database;
    unordered_map<string, int> dummyDatabase;
    stack<int> transactionsInProgress;
    pair<string, int> previous;
public:
    int get(string key);
    void put (string key, int val);
    void begin_transaction();
    void commit();
    void rollback();
};


