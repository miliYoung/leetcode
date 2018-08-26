/**
 * 	LEETCODE 599. Minimum Index Sum of Two Lists
 */

/**
 * Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.
 * You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers,
 *  output all of them with no order requirement. You could assume there always exists an answer.
 *  
 *  Example 1:
 *  Input:
 *  ["Shogun", "Tapioca Express", "Burger King", "KFC"]
 *  ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
 *  Output: ["Shogun"]
 *  Explanation: The only restaurant they both like is "Shogun".
 *  
 *  Example 2:
 *  Input:
 *  ["Shogun", "Tapioca Express", "Burger King", "KFC"]
 *  ["KFC", "Shogun", "Burger King"]
 *  Output: ["Shogun"]
 *  Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
 *  
 *  Note:
 *  The length of both lists will be in the range of [1, 1000].
 *  The length of strings in both lists will be in the range of [1, 30].
 *  The index is starting from 0 to the list length minus 1.
 *  No duplicates in both lists.
 */

#define MAX_NAME 256

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {
    
    if(list1Size == 0 || list2Size == 0)
    {
        return NULL;
    }
    
    int i = 0;
    int j = 0;
    int len = list1Size > list2Size ? list1Size : list2Size;
    int max_index = INT_MAX;
    char** res = (char**)malloc(len * sizeof(char*));
    for(i = 0; i < len; i++)
    {
        *(res+i) = (char*)malloc(MAX_NAME);
        memset( *(res+i), 0,MAX_NAME);
    }
    
    for(i = 0; i < list1Size; i++)
    {
         for(j = 0; j < list2Size; j++)
         {
             //printf("%s, %s\n",*(list1+i),*(list2+j));
             if(strcmp(*(list1+i),*(list2+j)) == 0)
             {
                   if(max_index > (i+j))
                   {
                       max_index = i + j;
                       *returnSize =  1;
                       memset(*(res+(*returnSize)-1),0, strlen(*(res+(*returnSize)-1))+1);
                       memcpy(*(res+(*returnSize)-1),*(list1+i),strlen(*(list1+i)));
                   }
                   else if(max_index == (i+j))
                   {
                       *returnSize = (*returnSize) + 1;
                        memset(*(res+(*returnSize)-1),0, strlen(*(res+(*returnSize)-1))+1);
                        memcpy(*(res+(*returnSize)-1),*(list1+i),strlen(*(list1+i)));
                   }
             }   
         }
         
    }
    
    return res;
}

