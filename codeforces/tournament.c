#include <stdio.h>

struct non_null {
    int a;
    int b;
};

int get_size(int *arr, int arrSize) {
    int count = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] != -1) {
            count++;
        }
    }
    return count;
}

struct non_null get_non_null(int *arr, int arrSize, int exclude) {
    int temp1, temp2;
    int flag1 = 0, flag2 = 0;
	int found = 0;
    struct non_null ret = {-1, -1};
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] != -1 && (i + 1) != exclude || found) {
            temp1 = arr[i];
            ret.a = i;
            arr[i] = -1;
            flag1 = 1;
            break;
        }
    }
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] != -1 && (i + 1) != exclude) {
            temp2 = arr[i];
            ret.b = i;
            arr[i] = -1;
            flag2 = 1;
            break;
        }
    }

    if (flag1) {
        arr[ret.a] = temp1;
    }
    if (flag2) {
        arr[ret.b] = temp2;
    }

    return ret;
}

void print(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {

    int t;
    scanf("%d", &t);

    // test cases
    for (int i = 0; i < t; i++) {

        int n, j, k;
        scanf("%d %d %d", &n, &j, &k);

        int arr[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
        }

        int flag = 0;
        while (get_size(arr, n) > k) {

            struct non_null temp = get_non_null(arr, n, j);
            printf("a: %d, b: %d\n", temp.a, temp.b);

            if (temp.a == -1 || temp.b == -1) {
                printf("NO\n");
				flag = 1;
				break;
            }

            if (arr[temp.a] < arr[temp.b]) {
                arr[temp.a] = -1;
            } else {
                arr[temp.b] = -1;
            }
            print(arr, n);
        }

		if(!flag)
			printf("YES\n");
    }

    return 0;
}
