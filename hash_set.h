
int N = 20;

struct HashSet
{
    struct Node **modArr;
};

void insertHashSet(struct HashSet *hashSet, int val)
{
    if (hashSet == NULL)
    {
        return;
    }

    pushNode(&hashSet->modArr[val % 20], val);
}

struct HashSet *createHashSet(int *initialValues)
{
    struct Node **array = malloc(sizeof(struct Node) * N);

    for (int i = 0; i < N; i += 1)
    {
        array[i] = NULL;
    }

    struct HashSet *hashSet = malloc(sizeof(struct HashSet));
    hashSet->modArr = array;

    if (initialValues != NULL)
    {
        for (int i = 0; initialValues[i] != -1; i += 1)
        {
            insertHashSet(hashSet, initialValues[i]);
        }
    }

    return hashSet;
}

void deleteHashSet(struct HashSet *hashSet, int val)
{
    if (hashSet == NULL)
    {
        return;
    }

    popNode(&hashSet->modArr[val % 20], val);
}

int getHashSet(struct HashSet *hashSet, int val)
{

    int res = findNode(hashSet->modArr[val % 20], val);

    if (res == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void freeHashSet(struct HashSet *hashSet)
{
    if (hashSet == NULL)
    {
        return;
    }

    for (int i = 0; i < N; i += 1)
    {
        freeNode(hashSet->modArr[i]);
    }

    free(hashSet->modArr);
    free(hashSet);
}
