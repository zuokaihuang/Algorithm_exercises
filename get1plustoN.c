
#include <stdio.h>

int get1PlustoN(int begin, int end);
typedef int (*helper_func)(int begin, int end);

int helper_just_return_parameter(int begin, int end) {
	return end;
}

int helper_just_return_parameter_plus(int begin, int end) {
	return begin + get1PlustoN(begin + 1, end);
}
int get1PlustoN(int begin, int end) {
	
	int ret = 0;
	
	helper_func  func[2];
	func[0] = helper_just_return_parameter;
	func[1] = helper_just_return_parameter_plus;
	
	return func[begin < end](begin, end);
}

int main() {

	int result = 0;
	int begin = 1, end = 100;
	

	result = helper_just_return_parameter_plus(begin, end);

	printf("result : %d\n", result);

	return 0;
}



