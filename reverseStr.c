/**
 * LEETCODE  541. Reverse String II
 */

/**
 * Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, 
 * then reverse the first k characters and left the other as original.
 * Example:
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 * Restrictions:
 * The string consists of lower English letters only.
 * Length of the given string and k will in the range [1, 10000]
 */

void reverse(char *s,int m,int n){
	int mid,i;
	char temp;
	mid=(m+n)/2;
	
	if(m!=n){
		for(i=m;i<=mid&&m<=n;i++){
			temp=s[m];
			s[m]=s[n];
			s[n]=temp;
			m++;
			n--;
		}
	}
}

char* reverseStr(char* s, int k) {
    int temp,length;
	int i,j;
	length=strlen(s);
		temp=length/(2*k);
		for(i=0;i<temp;i++){
				reverse(s,i*2*k,i*2*k+k-1);
		}
		if(length%(2*k)<k){
			reverse(s,temp*2*k,length-1);
		}else{
			reverse(s,temp*2*k,temp*2*k+k-1);
		}
		return s;
}

