#include "InMemoryDB.h"

int InMemoryDB::get(string key) {
    if (database.find(key) == database.end()) {
        cout << "GET: Returning null: key not found" << endl;
         return NULL;
    }
    else {
        cout << "GET: Success. Value: " << database[key] << endl;
        return database[key];
    }
}

void InMemoryDB::put(string key, int val) {
    try {
        if (transactionsInProgress.empty()) {
            throw invalid_argument("PUT: No transaction in progress");
        } else {
            cout << "PUT: key value pair put into transaction: " << key << ", " << val << endl;
            dummyDatabase[key] = val;
        }
    }
    catch (const invalid_argument& e) {
        cout << "PUT: ERROR THROWN" << endl;
        cerr << e.what() << endl;
    }
}

void InMemoryDB::begin_transaction() {
    try {
        if (transactionsInProgress.empty()) {
            transactionsInProgress.push(1);
            cout << "BEGIN_TRANSACTION: Transaction started" << endl;
        } else {
            throw invalid_argument("Transaction already in progress");
        }
    } catch (const invalid_argument& e) {
        cout << "BEGIN_TRANSACTION: ERROR THROWN" << endl;
        cerr << e.what() << endl;
    }
}

void InMemoryDB::commit() {
    try {
        if (!transactionsInProgress.empty()) {
            database = dummyDatabase;
            dummyDatabase.clear();
            transactionsInProgress.pop();
            cout << "COMMIT: Commit successful" << endl;
        } else {
            throw invalid_argument("COMMIT: No open transaction to commit");
        }
    }
    catch(invalid_argument& e) {
        cout << "COMMIT: ERROR THROWN" << endl;
        cerr  << e.what() << endl;
    }

}

void InMemoryDB::rollback() {
    try {
        if (!transactionsInProgress.empty()) {
            dummyDatabase.clear();
            transactionsInProgress.pop();
            cout << "ROLLBACK: Rollback successful" << endl;
        } else {
            throw invalid_argument("ROLLBACK: No open transaction to rollback");
        }
    }
    catch(invalid_argument& e) {
        cout << "ROLLBACK: ERROR THROWN" << endl;
        cerr  << e.what() << endl;
    }
}







