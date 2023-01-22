#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "hash_set.h"

int main(int argc, char **argv)
{
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    struct HashSet *hashSet = createHashSet(arr);

    // insert 69
    insertHashSet(hashSet, 69);

    // get 69
    int res = getHashSet(hashSet, 69);
    printf("res: %d\n", res);

    // delete 69
    deleteHashSet(hashSet, 69);

    // get 69
    res = getHashSet(hashSet, 69);
    printf("res: %d\n", res);

    // get 2
    res = getHashSet(hashSet, 2);
    printf("res: %d\n", res);

    freeHashSet(hashSet);
    return 0;
}
