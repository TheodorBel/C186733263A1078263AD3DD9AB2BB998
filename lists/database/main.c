#include "db.h"

int main() {
    int test_to_finder;
    db_type *db = create_database();
    db_insert_by_index(db,0,-1);
    db_insert_by_index(db,11,-1);
    db_insert_by_index(db,1,-1);
    db_insert_by_index(db,4,1);
    db_insert_by_index(db,1,-1);
    test_to_finder = db_read_by_index(db,3);
    printf("Readden element:%d\nSize of my base:%d\n", test_to_finder, db_getsize(db));
    db_delete_by_index(db,3);
    test_to_finder = db_read_by_index(db,3);
    printf("Readden element:%d\nSize of my base:%d\n", test_to_finder, db_getsize(db));



    return 0;
}
