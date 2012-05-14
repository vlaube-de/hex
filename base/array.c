#include <assert.h>
#include <string.h>
#include <limits.h>

#define INITIAL_CAPACITY 4
#define MAX_CAPACITY ((int)UINT_MAX/sizeof(void*))

typedef struct HexArray_s {
	void** content;
	size_t size;
	size_t capacity;
} Array;


Array*
array_create() {
	return MALLOC(Array);
}

void
array_free(Array *array) {
	assert(array);
	free(array->content);
	free(array);
}

static int
_ensure_capacity(Array* array, size_t capacity) {
	int oldCapacity = array->capacity;
	if(capacity > oldCapacity) {
		size_t newCapcity = (oldCapacity == 0) ?
			INITIAL_CAPACITY : oldCapacity;

		while(newCapcity < capacity) {
			int newCap = newCapcity * 2;
			if(newCap < newCapcity || newCap > MAX_CAPACITY) {
				newCap = MAX_CAPACITY;
			}
			newCapcity = newCap;
		}

		void **newContent;
		if(!array->content) {
			newContent = malloc(newCapcity * sizeof(void*));
			if(!newContent) {
				return -1;
			}
		} else {
			newContent = realloc(array->content, sizeof(void*) * newCapcity);
			if(!newContent) {
				return -1;
			}
		}

		array->capacity = newCapcity;
		array->content = newContent;
	}

	return 1;
}

int
array_append(Array *array, void* ptr) {
	assert(array);
	size_t size = array->size;
	int res = _ensure_capacity(array, size+1);
	if(!res) {
		return res;
	}
	array->content[size] = ptr;
	array->size++;
	return 0;
}

static void
_check_bound(Array* array, int index) {
	assert(array);
	assert(index < array->size);
	assert(index >= 0);
}

void*
array_remove(Array *array, int index) {
	_check_bound(array, index);

	void *ptr = array->content[index];

	int newSize = array->size - 1;

	if(index != newSize) {
		memmove(array->content + index, array->content + index + 1,
			(sizeof(void*)) * (newSize - index));
	}

	array->size = newSize;

	return ptr;
}

void*
array_set(Array *array, int index, void* ptr) {
	_check_bound(array, index);
	void* old = array->content[index];
	array->content[index] = ptr;
	return old;
}

int
array_set_size(Array *array, int newSize) {
	assert(array);
	assert(newSize >= 0);

	int oldSize = array->size;

	if(newSize > oldSize) {
		int res = _ensure_capacity(array, newSize);
		if(res < 0) {
			return res;
		}

		memset(array->content+sizeof(void*)*oldSize,0, sizeof(void*)*(newSize - oldSize));

		array->size = newSize;

		return 1;
	}
}

int
array_size(Array *array) {
	assert(array);
	return array->size;
}

const void**
array_content(Array *array) {
	return (const void**)array->content;
}