#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
void insertion_sort(void *base, size_t elem_size, size_t n, int(*comp) (const void *, const void *))
{
	char *cbase = base;
	char key[elem_size];
	for (size_t i = 1; i < n; i++) {
		memcpy(key, &cbase[i * elem_size], elem_size);
		/*�� base[i] ���뵽�ź���� base[0..i-1]�� */
		int j = i - 1;
		while (j >= 0 && comp(&cbase[j * elem_size], key) > 0) {
			memcpy(&cbase[(j + 1) * elem_size],
				&cbase[j * elem_size], elem_size);
			j--;
		}

		memcpy(&cbase[(j + 1) * elem_size], key, elem_size);
	}
}


void swap(void *a, void *b, size_t elem_size)
{
	if (a == NULL || b == NULL || a == b)
		return;
	char temp[elem_size];	/*�䳤���� */
	memcpy(temp, a, elem_size); memcpy(a, b, elem_size); memcpy(b, temp, elem_size);
}
void randomized_in_place(void *array, size_t elem_size, int n)
{
	char *carray = array;
	for (int i = 0; i < n; i++) {
		int index = rand() % (n - i) + i;
		swap(&carray[i * elem_size], &carray[index * elem_size],
			elem_size);
	}
}


void print_array(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}


int cmp_int(const void *p1, const void *p2)
{
	const int *pa = p1; const int *pb = p2; if (*pa < *pb)
		return -1;
	if (*pa == *pb)
		return 0;
	return 1;
}
int main(void)
{
	srand((unsigned)time(NULL));

	int a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = i;
	}
	randomized_in_place(a, sizeof(int), 10);
	printf("����ǰ:\n");
	print_array(a, 10);
	insertion_sort(a, sizeof(int), 10, cmp_int);
	printf("�����:\n");
	print_array(a, 10);
	return 0;
}

