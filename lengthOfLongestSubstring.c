#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(const char* s);




int lengthOfLongestSubstring(const char* s) {
	
	int ret_len = 0;
	int max_len = 0;
	int length = strlen(s);
	int index = 0;
	int loop = 0;
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
	max_len = 0;

	for (; loop < length; loop++) {
		
		for (index = loop; index < length; index++) {
			if (hash[pString[index]] == 0) {
				hash[pString[index]] = 1;
				max_len++;
			}
			else {
				break;
			}
		}
		if (ret_len < max_len) {
			ret_len = max_len;
		}
		max_len = 0;
		memset(hash, 0, sizeof(hash));
	}
	
	return ret_len;
}

int main () {

	printf("len = %d \n", lengthOfLongestSubstring("abcabcbb"));
	printf("len = %d \n", lengthOfLongestSubstring("dvdf"));
	printf("len = %d \n", lengthOfLongestSubstring("aaaaaaaaaaaaaaaaaaaaa"));
	printf("len = %d \n", lengthOfLongestSubstring(""));
	return 0;
}