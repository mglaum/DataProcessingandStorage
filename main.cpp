#include <iostream>
#include "InMemoryDB.h"
using namespace std;

int main() {
    InMemoryDB inmemoryDB;

    inmemoryDB.get("A");

    inmemoryDB.put("A", 5);

    inmemoryDB.begin_transaction();

    inmemoryDB.put("A", 5);

    inmemoryDB.get("A");

    inmemoryDB.put("A", 6);

    inmemoryDB.commit();

    inmemoryDB.get("A");

    inmemoryDB.commit();

    inmemoryDB.rollback();

    inmemoryDB.get("B");

    inmemoryDB.begin_transaction();

    inmemoryDB.put("B", 10);

    inmemoryDB.rollback();

    inmemoryDB.get("B");

    return 0;
}
