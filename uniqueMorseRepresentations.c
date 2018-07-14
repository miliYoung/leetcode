/**
 * LEETCODE 804. Unique Morse Code Words
 */

/**
 * International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes,
 * as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.
 * 
 * For convenience, the full table for the 26 letters of the English alphabet is given below:
 * [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
 * Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, 
 * "cab" can be written as "-.-.-....-", (which is the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation, the transformation of a word.
 * 
 * Return the number of different transformations among all words we have.
 * 
 * Example:
 * Input: words = ["gin", "zen", "gig", "msg"]
 * Output: 2
 * Explanation: 
 * The transformation of each word is:
 * "gin" -> "--...-."
 * "zen" -> "--...-."
 * "gig" -> "--...--."
 * "msg" -> "--...--."
 * There are 2 different transformations, "--...-." and "--...--.".
 */

int uniqueMorseRepresentations(char** words, int wordsSize) {
    if(NULL == words || wordsSize == 0)
    {
        return 0;
    }
    
    if(wordsSize == 1) return 1;
    
    char* table[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int i = 0;
    int length = 0;
    
    char** word_t = (char**)malloc(sizeof (char*) * wordsSize);
    for( i = 0; i < wordsSize; ++i)
    {
        word_t[i] = malloc(sizeof(char) * 12 * 100);
        memset(word_t[i], 0, sizeof(char) * 12 * 100);
    }
    
    for(i = 0; i < wordsSize; i++){
        char* word = words[i];
        length = 0;
        for(int j = 0; j < strlen(word); j++){
            strncpy(word_t[i] + length, table[word[j] -'a'], strlen(table[word[j] - 'a']));
            length += strlen(table[word[j] - 'a']);
        }
    }
  
    int *visited = (int*)malloc(sizeof(int) * wordsSize);
    if( NULL != visited)
    {
        memset(visited, 0, sizeof(int) * wordsSize);
    }
    else
    {
        return -1;
    }
    
    int count = 0;
    for(int i = 0; i < wordsSize; i++){
        for(int j = i + 1; j < wordsSize; j++){
            if(strcmp(word_t[i], word_t[j]) == 0 && !visited[i])
            {
                count++;
                visited[i] = 1;
            }
            
        }
    }
    printf("count = %d, wordsSize = %d\n",count, wordsSize);
    
    free(visited);
    for( i = 0; i < wordsSize; ++i)
    {
        free(word_t[i]);
    }
    free(word_t);
    
    return wordsSize - count;
    
}