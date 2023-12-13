#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdint.h>

typedef struct _my_string
{
	char* data;
	size_t size;
	size_t capacity;
} my_string_t;

typedef struct _my_string_array
{
	my_string_t** data;
	size_t size;
	size_t capacity;
} my_string_array_t;


/***********************************************************************************
 *
 * MY STRING OPERATION
 *
 ***********************************************************************************/
my_string_t* my_string_create(size_t capacity);

my_string_t* my_string_destroy(my_string_t* my_str);

void my_string_clean(my_string_t* my_str);

/**
 * @brief 重新分配字符容器的容量
 *
 * @param my_string_t*      存放字符的容器
 * @param size_t            新容量
 *
 * @return char*            新分配的内存空间地址
 */
char* my_string_realloc(my_string_t* my_str, size_t new_capacity);

/**
 * @brief 添加一个字符到字符容器的末尾
 * @detail 字符容器的容量会动态增长
 *
 * @param my_string_t*      存放字符的容器
 * @param const char        字符
 */
void my_string_append_one_char(my_string_t* my_str, const char data);

/**
 * @brief 添加一段字符串到字符容器的末尾
 * @detail 字符容器的容量会动态增长，添加的字符串长度由size决定
 *
 * @param my_string_t*      存放字符的容器
 * @param const char*       字符串
 * @param size_t            字符串长度
 */
void my_string_append(my_string_t* my_str, const char* str, size_t size);

size_t my_string_get_size(my_string_t* my_str);

/**
 * @brief 获取原生字符串的引用
 *
 * @param my_string_t*     存放字符的容器
 *
 * @return char*           指向原生字符串的指针
 */
char* my_string_get_raw_str(my_string_t* my_str);

/**
 * @brief 将原生字符串从容器中分离出来
 *
 * @param my_string_t*     存放字符的容器
 *
 * @return char*           指向原生字符串的指针
 * @attention 数据分离后，要手动释放
 */
char* my_string_detach_raw_str(my_string_t* my_str);

/**
 * @brief 复制一份my_string_t副本
 *
 * @param my_string_t*     存放字符的容器
 *
 * @return my_string_t*    存放字符的容器
 * @attention 返回值需要调用my_string_destroy()释放
 */
my_string_t* my_string_duplicate(my_string_t* my_str);

/**
 * @brief 根据原生字符串复制一份my_string_t副本
 *
 * @param const char*     字符串
 * @param size_t          字符串长度
 *
 * @return my_string_t*    存放字符的容器
 * @attention 返回值需要调用my_string_destroy()释放
 */
my_string_t* my_string_duplicate_by_raw_str(const char* str, size_t size);
/***********************************************************************************/



/***********************************************************************************
 *
 * MY STRING ARRAY OPERATION
 *
 ***********************************************************************************/
my_string_array_t* my_string_array_create(size_t capacity);

my_string_array_t* my_string_array_destroy(my_string_array_t* my_str_array);

void my_string_array_clean(my_string_array_t* my_str_array);

/**
 * @brief 重新分配字符串容器的容量
 *
 * @param my_string_array_t*      存放字符串的容器
 * @param size_t                  新容量
 *
 * @return my_string_t**          新分配的内存空间地址
 */
my_string_t** my_string_array_realloc(my_string_array_t* my_str_array, size_t new_capacity);

/**
 * @brief 添加一个字符串到字符串容器的末尾
 * @detail 字符串容器的容量会动态增长
 *
 * @param my_string_array_t*      存放字符串的容器
 * @param const char*             字符串
 * @param size_t                  字符串长度
 */
void my_string_array_append(my_string_array_t* my_str_array, const char* str, size_t size);

size_t my_string_array_get_size(my_string_array_t* my_str_array);

size_t my_string_array_get_str_size_by_index(my_string_array_t* my_str_array, size_t idx);

/**
 * @brief 通过索引值获取字符串容器中某个原生字符串的引用
 *
 * @param my_string_array_t* 存放字符串的容器
 * @param size_t             索引值
 *
 * @return char*             指向原生字符串的指针
 */
char* my_string_array_get_raw_str_by_index(my_string_array_t* my_str_array, size_t idx);
/***********************************************************************************/


/***********************************************************************************
 *
 * OTHER STRING OPERATION
 *
 ***********************************************************************************/
/**
 * @brief 根据分隔符分割字符串
 *
 * @param const char*          源字符串
 * @param const char*          分隔符
 *
 * @return my_string_array_t*  存放分割后的子串
 * @attention 返回值需要调用my_string_array_destroy()释放
 */
my_string_array_t* my_raw_str_split(const char* src, const char* sep);


#endif // MY_STRING_H
