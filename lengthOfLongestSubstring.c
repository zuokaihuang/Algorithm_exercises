#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(const char* s);




int lengthOfLongestSubstring(const char* s) {
	int ret_len = 0;
	int max_len = 0;
	int length = strlen(s);
	int index = 0;
	int pre_index = 0;
	int hash[256] = {0};
	const char* pString = s;
	
	if (!pString) {
		return 0;
	}
	if (length == 1) {
		return 1;
	}
	
	max_len = 0;
	pre_index = index = 0;
	memset(hash, 0, sizeof(hash));
	
	while (pre_index < length) {
		
		if (index < hash[pString[pre_index]])
			index = hash[pString[pre_index]];
			
		max_len = (max_len >= (pre_index - index + 1)) ? max_len : (pre_index - index + 1);
		//printf("max_len:%d \n", max_len);

		hash[pString[pre_index]] = pre_index + 1;
		pre_index++;
		
		if (ret_len <= max_len) {
			ret_len = max_len;
		}
	}
	
	return ret_len;
}

int main () {

	printf("len = %d \n\n\n", lengthOfLongestSubstring("hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"));
	printf("len = %d \n\n\n", lengthOfLongestSubstring("aabaab!bb"));
	printf("len = %d \n\n\n", lengthOfLongestSubstring("dvdfeee"));
	printf("len = %d \n\n\n", lengthOfLongestSubstring("aab"));
	printf("len = %d \n\n\n", lengthOfLongestSubstring("tmmzuxt"));
	return 0;
}