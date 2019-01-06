#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(const char* s);




int lengthOfLongestSubstring(const char* s) {
	
	int ret_len = 1, ret_len1 = 1,  ret_len2= 1;
	int length = strlen(s);
	int index = 0;
	char hash[256] = {0};
	const char* pString = s;
	
	if (!pString) {
		return 0;
	}
	if (length == 1) {
		return 1;
	}
	
	for (; index < length - 1; index++) {
	    if (pString[index] != pString[index+1]) {
			break;
		}
	}
	
	pString = pString + index;
	length = strlen(pString);
	//printf("string: %s, len = %d index = %d \n", pString, length, index);
	

	for (index = 0; index < length; index++) {
		if (hash[pString[index]] == 0) {
			hash[pString[index]] = 1;
		}
		else {
			break;
		}
	}
	
	ret_len1 = index;
	ret_len2 = length - ret_len1;
	
	if (ret_len1 > ret_len2) {
		ret_len = ret_len1;
	}else {
		ret_len = lengthOfLongestSubstring(pString + index);
	}
	
	return ret_len;
}

int main () {

	printf("len = %d \n", lengthOfLongestSubstring("abcabcbb"));
	printf("len = %d \n", lengthOfLongestSubstring("bbbbb"));
	printf("len = %d \n", lengthOfLongestSubstring("pwwkew"));
	return 0;
}