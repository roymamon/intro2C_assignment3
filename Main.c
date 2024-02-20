#include <stdio.h>
#include "StrList.h"
#include <stdlib.h>


int main() {
    StrList* strList = StrList_alloc();
    

    int choose;
    char buffer[100];  //could be other sizes aswell
    

    do {

        scanf("%d", &choose);

        switch (choose) {
            case 1:  //insert items to list
                
                
                int numStrings;
                scanf("%d", &numStrings);

                for (int i = 0; i < numStrings; ++i) {
                    scanf("%s", buffer);
                    StrList_insertLast(strList, buffer);
                }
                break;

            case 2:  //insert item in index
                int insertIndex;
                scanf("%d", &insertIndex);

                scanf("%s", buffer);

                StrList_insertAt(strList, buffer, insertIndex);
                break;

            case 3:  //print the list
                StrList_print(strList);
                break;

            case 4:  //print list size
                printf("%zu\n", StrList_size(strList));
                break;

            case 5:  //print string in index
                int printIndex;
                scanf("%d", &printIndex);

                StrList_printAt(strList, printIndex);
                break;

            case 6:  //print #chars in list
                printf("%d\n", StrList_printLen(strList));
                break;

            case 7:  //print how many item in list
                scanf("%s", buffer);
                printf("%d\n", StrList_count(strList, buffer));
                break;

            case 8:  //delete all instances of item
                scanf("%s", buffer);
                StrList_remove(strList, buffer);
                break;

            case 9:  //delete item in index
                int removeIndex;
                scanf("%d", &removeIndex);
                StrList_removeAt(strList, removeIndex);
                break;

            case 10:  //reversing the list
                StrList_reverse(strList);
                break;

            case 11:  //freeing the nodes
                StrList_free(strList);
                break;

            case 12:  //sorting lexicography
                StrList_sort(strList);
                break;

            case 13:  //is sorted
                if (StrList_isSorted(strList)) {
                    printf("true\n");
                } else {
                    printf("false\n");

                }
                break;

            case 0:  //base case free
                
                StrList_free(strList);
                return 0;

            default:
                break;
        }

    } while(1);

       return 0;

    } 
    

   

