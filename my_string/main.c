#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_string.h"

void my_string_print(my_string_t* my_str)
{
	if (my_str == NULL || my_str->data == NULL)
	{
		return;
	}

	printf("size=%lu capacity=%lu str=", my_str->size, my_str->capacity);

	for (size_t idx = 0; idx < my_str->size; ++idx)
	{
		char ch = my_str->data[idx];

		if (isprint(ch))
		{
			printf("%c", ch);
		}
		else
		{
			printf("\\x%02x", (uint8_t)ch);
		}
	}

	printf("\n");
}

void my_string_array_print(my_string_array_t* my_str_array)
{
	if (my_str_array == NULL || my_str_array->data == NULL)
	{
		return;
	}

	printf("size=%lu capacity=%lu\n", my_str_array->size, my_str_array->capacity);

	for (size_t idx = 0; idx < my_str_array->size; ++idx)
	{
		printf("  ");
		my_string_print(my_str_array->data[idx]);
	}
}

void foo()
{
	my_string_t* my_str = my_string_create(128);

	my_string_append(my_str, "hello", strlen("hello"));
	my_string_append(my_str, " ", strlen(" "));
	my_string_append(my_str, "world", strlen("world"));

	my_string_print(my_str);

	my_str = my_string_destroy(my_str);
}

void foo2()
{
	my_string_array_t* my_str_array = my_string_array_create(16);

	my_string_array_append(my_str_array, "hello", strlen("hello"));
	my_string_array_append(my_str_array, "world", strlen("world"));

	my_string_array_print(my_str_array);

	my_str_array = my_string_array_destroy(my_str_array);
}

int main(int argc, char** argv)
{
	foo();
	foo2();

	return 0;
}
