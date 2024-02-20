#include <stdio.h>
#include "StrList.h"
#include <string.h>
#define TRUE 1
#define FALSE 0



struct _StrList {
    char** data;
    size_t size;
    size_t capacity;
};

StrList* StrList_alloc() {  //initilazing list
    StrList* newList = (StrList*)malloc(sizeof(StrList));
    if (newList == NULL) {
        return NULL;
    }

    newList->data = NULL;
    newList->size = 0;
    newList->capacity = 0;

    return newList;
}

void StrList_free(StrList* strList) {
    if (strList == NULL) {
        return;
    }

    for (size_t i = 0; i < strList->size; ++i) {
        free(strList->data[i]);
    }

    free(strList->data);
    
    strList->data = NULL; //initilazing again inorder to add items to the list after deleting
    strList->size = 0;
    strList->capacity = 0;
    
}



void StrList_insertLast(StrList* strList, const char* data) {
    if (strList == NULL || data == NULL) {
        return;
    }

    if (strList->size >= strList->capacity) {
        strList->capacity = (strList->capacity == 0) ? 1 : strList->capacity * 2;
        strList->data = (char**)realloc(strList->data, strList->capacity * sizeof(char*));
        if (strList->data == NULL) {
            return;
        }
    }

    strList->data[strList->size] = strdup(data);
    if (strList->data[strList->size] == NULL) {
        return;
    }

    ++strList->size;
}

void StrList_insertAt(StrList* strList, const char* data, int index) {
    if (strList == NULL || data == NULL || index < 0 || index > strList->size) {
        return;
    }

    if (strList->size >= strList->capacity) {
        strList->capacity = (strList->capacity == 0) ? 1 : strList->capacity * 2;
        strList->data = (char**)realloc(strList->data, strList->capacity * sizeof(char*));
        if (strList->data == NULL) {
            return;
        }
    }

    for (int i = strList->size; i > index; --i) {
        strList->data[i] = strList->data[i - 1];
    }

    strList->data[index] = strdup(data);
    if (strList->data[index] == NULL) {
        return;
    }

    ++strList->size;
}

size_t StrList_size(const StrList* strList) {
    return (strList != NULL) ? strList->size : 0;
}

char* StrList_firstData(const StrList* strList) {
    return (strList != NULL && strList->size > 0) ? strList->data[0] : NULL;
}

void StrList_print(const StrList* strList) {
    if (strList == NULL) {
        return;
    }

    for (size_t i = 0; i < strList->size; ++i) {
        if(i < (strList->size - 1)){
        printf("%s ", strList->data[i]);
        }
        else{
        printf("%s", strList->data[i]);
        }
    }

    printf("\n");
}

void StrList_printAt(const StrList* strList, int index) {
    if (strList == NULL || index < 0 || (size_t)index >= strList->size) {
        return;
    }

    printf("%s\n", strList->data[index]);
}

int StrList_printLen(const StrList* strList) {
    int totalLen = 0;
    if (strList == NULL) {
        return totalLen;
    }

    for (size_t i = 0; i < strList->size; ++i) {
        totalLen += strlen(strList->data[i]);
    }

    return totalLen;
}

int StrList_count(StrList* strList, const char* data) {
    int count = 0;
    if (strList == NULL || data == NULL) {
        return count;
    }

    for (size_t i = 0; i < strList->size; ++i) {
        if (strcmp(strList->data[i], data) == 0) {
            ++count;
        }
    }

    return count;
}

void StrList_remove(StrList* strList, const char* data) {
    if (strList == NULL || data == NULL) {
        return;
    }

    size_t i = 0;
    size_t j = 0;
    while (i < strList->size) {
        if (strcmp(strList->data[i], data) != 0) {
            strList->data[j] = strList->data[i];
            ++j;
        } else {
            free(strList->data[i]);
        }
        ++i;
    }

    strList->size = j;
}

void StrList_removeAt(StrList* strList, int index) {
    if (strList == NULL || index < 0 || (size_t)index >= strList->size) {
        return;
    }

    free(strList->data[index]);

    for (size_t i = index; i < strList->size - 1; ++i) {
        strList->data[i] = strList->data[i + 1];
    }

    --strList->size;
}

int StrList_isEqual(const StrList* strList1, const StrList* strList2) {
    if (strList1 == NULL || strList2 == NULL || strList1->size != strList2->size) {
        return 0;
    }

    for (size_t i = 0; i < strList1->size; ++i) {
        if (strcmp(strList1->data[i], strList2->data[i]) != 0) {
            return 0;
        }
    }

    return 1;
}

StrList* StrList_clone(const StrList* strList) {
    if (strList == NULL) {
        return NULL;
    }

    StrList* newStrList = StrList_alloc();
    if (newStrList == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < strList->size; ++i) {
        StrList_insertLast(newStrList, strList->data[i]);
    }

    return newStrList;
}

void StrList_reverse(StrList* strList) {
    if (strList == NULL || strList->size <= 1) {
        return;
    }

    size_t i = 0;
    size_t j = strList->size - 1;
    while (i < j) {
        char* temp = strList->data[i];
        strList->data[i] = strList->data[j];
        strList->data[j] = temp;

        ++i;
        --j;
    }
}

int compareStrings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

void StrList_sort(StrList* strList) {
    if (strList == NULL || strList->size <= 1) {
        return;
    }

    qsort(strList->data, strList->size, sizeof(char*), compareStrings);
}

int StrList_isSorted(StrList* strList) {
    if (strList == NULL || strList->size <= 1) {
        return 1;
    }

    for (size_t i = 0; i < strList->size - 1; ++i) {
        if (strcmp(strList->data[i], strList->data[i + 1]) > 0) {
            return 0;
        }
    }

    return 1; 
}
