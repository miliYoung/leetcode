/**
 * 
 */

/**
 * You are given a string representing an attendance record for a student. 
 * The record only contains the following three characters:
 * 'A' : Absent.
 * 'L' : Late.
 * 'P' : Present.
 * 
 * A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or 
 * more than two continuous 'L' (late).
 * 
 * You need to return whether the student could be rewarded according to his attendance record.
 * 
 * Example 1:
 * Input: "PPALLP"
 * Output: True
 * 
 * Example 2:
 * Input: "PPALLL"
 * Output: False
 */

/**
 * [checkRecord description] 检查学生的缺席记录
 * @param  s [description]   缺席记录
 * @return   [description]   是否值得表扬
 * @note  注意语义：缺席超过1次或者连续迟到两次以上的学生不值得表扬，返回值false
 */
bool checkRecord(char* s) {
    
    if( NULL == s) return false;
    
    int i = 0;
    int countA = 0, countLL = 0;
    
    if(*s == 'A') countA++;
    
    for(i = 1; i < strlen(s)-1; ++i)
    {
        if(*(s+i) == 'A')
        {
            countA++;
            if(countA > 1)
            {
               return false;
            }   
        }
        
        if(*(s+i) == 'L' && *(s+i-1) == 'L' && *(s+i+1) == 'L')
        {
            return false;
        }
    }
    
    if(*(s+strlen(s)-1) == 'A' && strlen(s) != 1) countA++;
    if(countA > 1)
    {
         return false;  
    }   
    
    
    return true;
}