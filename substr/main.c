#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substr(char *string, int index, char *temp, char **result, int* result_index) {

    int temp_index = strlen(temp);

    if (index == strlen(string)) {
		return;
	}

	temp[temp_index] = string[index];
	temp[temp_index+1] = '\0';

	/* result[*result_index] = temp; */
	result[*result_index] = malloc(sizeof(char) * 128);
	strcpy(result[*result_index], temp);
	*result_index = *result_index + 1;

    substr(string, index+1, temp, result, result_index);

    temp[temp_index] = '\0';

    if (strlen(temp) == 0) {
		substr(string, index+1, temp, result, result_index);
	}
}

int main(void) {

	char* string = "something";
	char* result[1024];
	int result_index = 0;

	substr(string, 0, "", result, &result_index);

	for (int i = 0; i < result_index; i++) {
		printf("%s\n", result[i]);
		free(result[i]);
	}

    return 0;
}
