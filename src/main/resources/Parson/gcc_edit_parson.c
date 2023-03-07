# 0 "edit_parson.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "edit_parson.c"
# 27 "edit_parson.c"
# 1 "parson.h" 1
# 43 "parson.h"
# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 1 3 4
# 143 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4

# 143 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
typedef long int ptrdiff_t;
# 209 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 321 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
typedef int wchar_t;
# 415 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
# 426 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 3 4
} max_align_t;
# 44 "parson.h" 2



# 46 "parson.h"
typedef struct json_object_t JSON_Object;
typedef struct json_array_t JSON_Array;
typedef struct json_value_t JSON_Value;

enum json_value_type {
    JSONError = -1,
    JSONNull = 1,
    JSONString = 2,
    JSONNumber = 3,
    JSONObject = 4,
    JSONArray = 5,
    JSONBoolean = 6
};
typedef int JSON_Value_Type;

enum json_result_t {
    JSONSuccess = 0,
    JSONFailure = -1
};
typedef int JSON_Status;

typedef void * (*JSON_Malloc_Function)(size_t);
typedef void (*JSON_Free_Function)(void *);





typedef int (*JSON_Number_Serialization_Function)(double num, char *buf);



void json_set_allocation_functions(JSON_Malloc_Function malloc_fun, JSON_Free_Function free_fun);



void json_set_escape_slashes(int escape_slashes);




void json_set_float_serialization_format(const char *format);



void json_set_number_serialization_function(JSON_Number_Serialization_Function fun);


JSON_Value * json_parse_file(const char *filename);



JSON_Value * json_parse_file_with_comments(const char *filename);


JSON_Value * json_parse_string(const char *string);



JSON_Value * json_parse_string_with_comments(const char *string);


size_t json_serialization_size(const JSON_Value *value);
JSON_Status json_serialize_to_buffer(const JSON_Value *value, char *buf, size_t buf_size_in_bytes);
JSON_Status json_serialize_to_file(const JSON_Value *value, const char *filename);
char * json_serialize_to_string(const JSON_Value *value);


size_t json_serialization_size_pretty(const JSON_Value *value);
JSON_Status json_serialize_to_buffer_pretty(const JSON_Value *value, char *buf, size_t buf_size_in_bytes);
JSON_Status json_serialize_to_file_pretty(const JSON_Value *value, const char *filename);
char * json_serialize_to_string_pretty(const JSON_Value *value);

void json_free_serialized_string(char *string);


int json_value_equals(const JSON_Value *a, const JSON_Value *b);
# 134 "parson.h"
JSON_Status json_validate(const JSON_Value *schema, const JSON_Value *value);




JSON_Value * json_object_get_value (const JSON_Object *object, const char *name);
const char * json_object_get_string (const JSON_Object *object, const char *name);
size_t json_object_get_string_len(const JSON_Object *object, const char *name);
JSON_Object * json_object_get_object (const JSON_Object *object, const char *name);
JSON_Array * json_object_get_array (const JSON_Object *object, const char *name);
double json_object_get_number (const JSON_Object *object, const char *name);
int json_object_get_boolean(const JSON_Object *object, const char *name);





JSON_Value * json_object_dotget_value (const JSON_Object *object, const char *name);
const char * json_object_dotget_string (const JSON_Object *object, const char *name);
size_t json_object_dotget_string_len(const JSON_Object *object, const char *name);
JSON_Object * json_object_dotget_object (const JSON_Object *object, const char *name);
JSON_Array * json_object_dotget_array (const JSON_Object *object, const char *name);
double json_object_dotget_number (const JSON_Object *object, const char *name);
int json_object_dotget_boolean(const JSON_Object *object, const char *name);


size_t json_object_get_count (const JSON_Object *object);
const char * json_object_get_name (const JSON_Object *object, size_t index);
JSON_Value * json_object_get_value_at(const JSON_Object *object, size_t index);
JSON_Value * json_object_get_wrapping_value(const JSON_Object *object);



int json_object_has_value (const JSON_Object *object, const char *name);
int json_object_has_value_of_type(const JSON_Object *object, const char *name, JSON_Value_Type type);

int json_object_dothas_value (const JSON_Object *object, const char *name);
int json_object_dothas_value_of_type(const JSON_Object *object, const char *name, JSON_Value_Type type);



JSON_Status json_object_set_value(JSON_Object *object, const char *name, JSON_Value *value);
JSON_Status json_object_set_string(JSON_Object *object, const char *name, const char *string);
JSON_Status json_object_set_string_with_len(JSON_Object *object, const char *name, const char *string, size_t len);
JSON_Status json_object_set_number(JSON_Object *object, const char *name, double number);
JSON_Status json_object_set_boolean(JSON_Object *object, const char *name, int boolean);
JSON_Status json_object_set_null(JSON_Object *object, const char *name);



JSON_Status json_object_dotset_value(JSON_Object *object, const char *name, JSON_Value *value);
JSON_Status json_object_dotset_string(JSON_Object *object, const char *name, const char *string);
JSON_Status json_object_dotset_string_with_len(JSON_Object *object, const char *name, const char *string, size_t len);
JSON_Status json_object_dotset_number(JSON_Object *object, const char *name, double number);
JSON_Status json_object_dotset_boolean(JSON_Object *object, const char *name, int boolean);
JSON_Status json_object_dotset_null(JSON_Object *object, const char *name);


JSON_Status json_object_remove(JSON_Object *object, const char *name);


JSON_Status json_object_dotremove(JSON_Object *object, const char *key);


JSON_Status json_object_clear(JSON_Object *object);




JSON_Value * json_array_get_value (const JSON_Array *array, size_t index);
const char * json_array_get_string (const JSON_Array *array, size_t index);
size_t json_array_get_string_len(const JSON_Array *array, size_t index);
JSON_Object * json_array_get_object (const JSON_Array *array, size_t index);
JSON_Array * json_array_get_array (const JSON_Array *array, size_t index);
double json_array_get_number (const JSON_Array *array, size_t index);
int json_array_get_boolean(const JSON_Array *array, size_t index);
size_t json_array_get_count (const JSON_Array *array);
JSON_Value * json_array_get_wrapping_value(const JSON_Array *array);



JSON_Status json_array_remove(JSON_Array *array, size_t i);




JSON_Status json_array_replace_value(JSON_Array *array, size_t i, JSON_Value *value);
JSON_Status json_array_replace_string(JSON_Array *array, size_t i, const char* string);
JSON_Status json_array_replace_string_with_len(JSON_Array *array, size_t i, const char *string, size_t len);
JSON_Status json_array_replace_number(JSON_Array *array, size_t i, double number);
JSON_Status json_array_replace_boolean(JSON_Array *array, size_t i, int boolean);
JSON_Status json_array_replace_null(JSON_Array *array, size_t i);


JSON_Status json_array_clear(JSON_Array *array);



JSON_Status json_array_append_value(JSON_Array *array, JSON_Value *value);
JSON_Status json_array_append_string(JSON_Array *array, const char *string);
JSON_Status json_array_append_string_with_len(JSON_Array *array, const char *string, size_t len);
JSON_Status json_array_append_number(JSON_Array *array, double number);
JSON_Status json_array_append_boolean(JSON_Array *array, int boolean);
JSON_Status json_array_append_null(JSON_Array *array);




JSON_Value * json_value_init_object (void);
JSON_Value * json_value_init_array (void);
JSON_Value * json_value_init_string (const char *string);
JSON_Value * json_value_init_string_with_len(const char *string, size_t length);
JSON_Value * json_value_init_number (double number);
JSON_Value * json_value_init_boolean(int boolean);
JSON_Value * json_value_init_null (void);
JSON_Value * json_value_deep_copy (const JSON_Value *value);
void json_value_free (JSON_Value *value);

JSON_Value_Type json_value_get_type (const JSON_Value *value);
JSON_Object * json_value_get_object (const JSON_Value *value);
JSON_Array * json_value_get_array (const JSON_Value *value);
const char * json_value_get_string (const JSON_Value *value);
size_t json_value_get_string_len(const JSON_Value *value);
double json_value_get_number (const JSON_Value *value);
int json_value_get_boolean(const JSON_Value *value);
JSON_Value * json_value_get_parent (const JSON_Value *value);


JSON_Value_Type json_type (const JSON_Value *value);
JSON_Object * json_object (const JSON_Value *value);
JSON_Array * json_array (const JSON_Value *value);
const char * json_string (const JSON_Value *value);
size_t json_string_len(const JSON_Value *value);
double json_number (const JSON_Value *value);
int json_boolean(const JSON_Value *value);
# 28 "edit_parson.c" 2



# 1 "/usr/include/stdio.h" 1 3 4
# 27 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 33 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 392 "/usr/include/features.h" 3 4
# 1 "/usr/include/features-time64.h" 1 3 4
# 20 "/usr/include/features-time64.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 21 "/usr/include/features-time64.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
# 19 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4
# 22 "/usr/include/features-time64.h" 2 3 4
# 393 "/usr/include/features.h" 2 3 4
# 486 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 559 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 560 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 561 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 487 "/usr/include/features.h" 2 3 4
# 510 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 511 "/usr/include/features.h" 2 3 4
# 34 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 2 3 4
# 28 "/usr/include/stdio.h" 2 3 4





# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 1 3 4
# 34 "/usr/include/stdio.h" 2 3 4


# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stdarg.h" 1 3 4
# 40 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stdarg.h" 3 4

# 40 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 37 "/usr/include/stdio.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 28 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
# 19 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4
# 29 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;






typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;



typedef long int __quad_t;
typedef unsigned long int __u_quad_t;







typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
# 141 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 1 3 4
# 142 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/time64.h" 1 3 4
# 143 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;

typedef int __daddr_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;


typedef long int __fsword_t;

typedef long int __ssize_t;


typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;




typedef int __sig_atomic_t;
# 39 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h" 1 3 4




# 1 "/usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h" 1 3 4
# 13 "/usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h" 3 4
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
# 6 "/usr/include/x86_64-linux-gnu/bits/types/__fpos_t.h" 2 3 4




typedef struct _G_fpos_t
{
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
# 40 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/bits/types/__fpos64_t.h" 3 4
typedef struct _G_fpos64_t
{
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;
# 41 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__FILE.h" 1 3 4



struct _IO_FILE;
typedef struct _IO_FILE __FILE;
# 42 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h" 1 3 4



struct _IO_FILE;


typedef struct _IO_FILE FILE;
# 43 "/usr/include/stdio.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 1 3 4
# 35 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h" 3 4
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;




typedef void _IO_lock_t;





struct _IO_FILE
{
  int _flags;


  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;


  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;
  int _flags2;
  __off_t _old_offset;


  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];

  _IO_lock_t *_lock;







  __off64_t _offset;

  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;

  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
# 44 "/usr/include/stdio.h" 2 3 4
# 52 "/usr/include/stdio.h" 3 4
typedef __gnuc_va_list va_list;
# 63 "/usr/include/stdio.h" 3 4
typedef __off_t off_t;
# 77 "/usr/include/stdio.h" 3 4
typedef __ssize_t ssize_t;






typedef __fpos_t fpos_t;
# 133 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/stdio_lim.h" 1 3 4
# 134 "/usr/include/stdio.h" 2 3 4
# 143 "/usr/include/stdio.h" 3 4
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;






extern int remove (const char *__filename) __attribute__ ((__nothrow__ , __leaf__));

extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));



extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__ , __leaf__));
# 178 "/usr/include/stdio.h" 3 4
extern int fclose (FILE *__stream);
# 188 "/usr/include/stdio.h" 3 4
extern FILE *tmpfile (void)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
# 205 "/usr/include/stdio.h" 3 4
extern char *tmpnam (char[20]) __attribute__ ((__nothrow__ , __leaf__)) ;




extern char *tmpnam_r (char __s[20]) __attribute__ ((__nothrow__ , __leaf__)) ;
# 222 "/usr/include/stdio.h" 3 4
extern char *tempnam (const char *__dir, const char *__pfx)
   __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (__builtin_free, 1)));






extern int fflush (FILE *__stream);
# 239 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 258 "/usr/include/stdio.h" 3 4
extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;




extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) ;
# 293 "/usr/include/stdio.h" 3 4
extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
# 308 "/usr/include/stdio.h" 3 4
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;




extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (fclose, 1))) ;
# 328 "/usr/include/stdio.h" 3 4
extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__ , __leaf__));




extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__ , __leaf__));


extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));







extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...);




extern int printf (const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) __attribute__ ((__nothrow__));





extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg);




extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));



extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));
# 403 "/usr/include/stdio.h" 3 4
extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));







extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) ;




extern int scanf (const char *__restrict __format, ...) ;

extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__));





# 1 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 1 3 4
# 119 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 25 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 2 3 4
# 120 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 2 3 4
# 431 "/usr/include/stdio.h" 2 3 4



extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf")

                               ;
extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf")
                              ;
extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__ , __leaf__))

                      ;
# 459 "/usr/include/stdio.h" 3 4
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;





extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;


extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));





extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")



     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")

     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__ , __leaf__))



     __attribute__ ((__format__ (__scanf__, 2, 0)));
# 513 "/usr/include/stdio.h" 3 4
extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);





extern int getchar (void);






extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
# 538 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked (FILE *__stream);
# 549 "/usr/include/stdio.h" 3 4
extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);





extern int putchar (int __c);
# 565 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked (int __c, FILE *__stream);







extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream);


extern int putw (int __w, FILE *__stream);







extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     __attribute__ ((__access__ (__write_only__, 1, 2)));
# 632 "/usr/include/stdio.h" 3 4
extern __ssize_t __getdelim (char **__restrict __lineptr,
                             size_t *__restrict __n, int __delimiter,
                             FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
                           size_t *__restrict __n, int __delimiter,
                           FILE *__restrict __stream) ;







extern __ssize_t getline (char **__restrict __lineptr,
                          size_t *__restrict __n,
                          FILE *__restrict __stream) ;







extern int fputs (const char *__restrict __s, FILE *__restrict __stream);





extern int puts (const char *__s);






extern int ungetc (int __c, FILE *__stream);






extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;




extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);
# 702 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);







extern int fseek (FILE *__stream, long int __off, int __whence);




extern long int ftell (FILE *__stream) ;




extern void rewind (FILE *__stream);
# 736 "/usr/include/stdio.h" 3 4
extern int fseeko (FILE *__stream, __off_t __off, int __whence);




extern __off_t ftello (FILE *__stream) ;
# 760 "/usr/include/stdio.h" 3 4
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);




extern int fsetpos (FILE *__stream, const fpos_t *__pos);
# 786 "/usr/include/stdio.h" 3 4
extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));

extern int feof (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;

extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;



extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;







extern void perror (const char *__s);




extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
# 823 "/usr/include/stdio.h" 3 4
extern int pclose (FILE *__stream);





extern FILE *popen (const char *__command, const char *__modes)
  __attribute__ ((__malloc__)) __attribute__ ((__malloc__ (pclose, 1))) ;






extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1)));
# 867 "/usr/include/stdio.h" 3 4
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));



extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;


extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
# 885 "/usr/include/stdio.h" 3 4
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);
# 902 "/usr/include/stdio.h" 3 4

# 32 "edit_parson.c" 2
# 1 "/usr/include/stdlib.h" 1 3 4
# 26 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 27 "/usr/include/stdlib.h" 2 3 4





# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 1 3 4
# 33 "/usr/include/stdlib.h" 2 3 4







# 1 "/usr/include/x86_64-linux-gnu/bits/waitflags.h" 1 3 4
# 41 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 1 3 4
# 42 "/usr/include/stdlib.h" 2 3 4
# 59 "/usr/include/stdlib.h" 3 4
typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;





__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;
# 98 "/usr/include/stdlib.h" 3 4
extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__ , __leaf__)) ;



extern double atof (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern int atoi (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern long int atol (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;



__extension__ extern long long int atoll (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;



extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 177 "/usr/include/stdlib.h" 3 4
extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));




__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 386 "/usr/include/stdlib.h" 3 4
extern char *l64a (long int __n) __attribute__ ((__nothrow__ , __leaf__)) ;


extern long int a64l (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;




# 1 "/usr/include/x86_64-linux-gnu/sys/types.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4






typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;


typedef __loff_t loff_t;




typedef __ino_t ino_t;
# 59 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;
# 97 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __pid_t pid_t;





typedef __id_t id_t;
# 114 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;




# 1 "/usr/include/x86_64-linux-gnu/bits/types/clock_t.h" 1 3 4






typedef __clock_t clock_t;
# 127 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/types/clockid_t.h" 1 3 4






typedef __clockid_t clockid_t;
# 129 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/time_t.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/bits/types/time_t.h" 3 4
typedef __time_t time_t;
# 130 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/timer_t.h" 1 3 4






typedef __timer_t timer_t;
# 131 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 144 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 1 3 4
# 145 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;




# 1 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h" 3 4
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
# 156 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4


typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;


typedef int register_t __attribute__ ((__mode__ (__word__)));
# 176 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
# 24 "/usr/include/endian.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/endian.h" 1 3 4
# 35 "/usr/include/x86_64-linux-gnu/bits/endian.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/endianness.h" 1 3 4
# 36 "/usr/include/x86_64-linux-gnu/bits/endian.h" 2 3 4
# 25 "/usr/include/endian.h" 2 3 4
# 35 "/usr/include/endian.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 1 3 4
# 33 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
static __inline __uint16_t
__bswap_16 (__uint16_t __bsx)
{

  return __builtin_bswap16 (__bsx);



}






static __inline __uint32_t
__bswap_32 (__uint32_t __bsx)
{

  return __builtin_bswap32 (__bsx);



}
# 69 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
__extension__ static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{

  return __builtin_bswap64 (__bsx);



}
# 36 "/usr/include/endian.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/uintn-identity.h" 1 3 4
# 32 "/usr/include/x86_64-linux-gnu/bits/uintn-identity.h" 3 4
static __inline __uint16_t
__uint16_identity (__uint16_t __x)
{
  return __x;
}

static __inline __uint32_t
__uint32_identity (__uint32_t __x)
{
  return __x;
}

static __inline __uint64_t
__uint64_identity (__uint64_t __x)
{
  return __x;
}
# 37 "/usr/include/endian.h" 2 3 4
# 177 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/sys/select.h" 1 3 4
# 30 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/select.h" 1 3 4
# 31 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/bits/types/sigset_t.h" 1 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h" 1 3 4




typedef struct
{
  unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} __sigset_t;
# 5 "/usr/include/x86_64-linux-gnu/bits/types/sigset_t.h" 2 3 4


typedef __sigset_t sigset_t;
# 34 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h" 1 3 4







struct timeval
{




  __time_t tv_sec;
  __suseconds_t tv_usec;

};
# 38 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 3 4
struct timespec
{



  __time_t tv_sec;




  __syscall_slong_t tv_nsec;
# 31 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 3 4
};
# 40 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4



typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
# 59 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
typedef struct
  {






    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];


  } fd_set;






typedef __fd_mask fd_mask;
# 91 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4

# 102 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
# 127 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);
# 153 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4

# 180 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4





typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 227 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 1 3 4
# 23 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 1 3 4
# 44 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h" 1 3 4
# 21 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h" 2 3 4
# 45 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h" 1 3 4
# 25 "/usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h" 3 4
typedef union
{
  __extension__ unsigned long long int __value64;
  struct
  {
    unsigned int __low;
    unsigned int __high;
  } __value32;
} __atomic_wide_counter;
# 47 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 2 3 4




typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;

typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
# 76 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/struct_mutex.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/struct_mutex.h" 3 4
struct __pthread_mutex_s
{
  int __lock;
  unsigned int __count;
  int __owner;

  unsigned int __nusers;



  int __kind;

  short __spins;
  short __elision;
  __pthread_list_t __list;
# 53 "/usr/include/x86_64-linux-gnu/bits/struct_mutex.h" 3 4
};
# 77 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 2 3 4
# 89 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/struct_rwlock.h" 1 3 4
# 23 "/usr/include/x86_64-linux-gnu/bits/struct_rwlock.h" 3 4
struct __pthread_rwlock_arch_t
{
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;

  int __cur_writer;
  int __shared;
  signed char __rwelision;




  unsigned char __pad1[7];


  unsigned long int __pad2;


  unsigned int __flags;
# 55 "/usr/include/x86_64-linux-gnu/bits/struct_rwlock.h" 3 4
};
# 90 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 2 3 4




struct __pthread_cond_s
{
  __atomic_wide_counter __wseq;
  __atomic_wide_counter __g1_start;
  unsigned int __g_refs[2] ;
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};

typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;

typedef struct
{
  int __data ;
} __once_flag;
# 24 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 2 3 4



typedef unsigned long int pthread_t;




typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;




typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;



typedef unsigned int pthread_key_t;



typedef int pthread_once_t;


union pthread_attr_t
{
  char __size[56];
  long int __align;
};

typedef union pthread_attr_t pthread_attr_t;




typedef union
{
  struct __pthread_mutex_s __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;


typedef union
{
  struct __pthread_cond_s __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;





typedef union
{
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;

typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;





typedef volatile int pthread_spinlock_t;




typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;
# 228 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4



# 396 "/usr/include/stdlib.h" 2 3 4






extern long int random (void) __attribute__ ((__nothrow__ , __leaf__));


extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));





extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));



extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));

extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));





extern int rand (void) __attribute__ ((__nothrow__ , __leaf__));

extern void srand (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));



extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__ , __leaf__));







extern double drand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int lrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int mrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern void srand48 (long int __seedval) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;

  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern void *malloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) ;

extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1, 2))) ;






extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__)) __attribute__ ((__alloc_size__ (2)));


extern void free (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));







extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__))
     __attribute__ ((__alloc_size__ (2, 3)))
    __attribute__ ((__malloc__ (__builtin_free, 1)));


extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__ (reallocarray, 1)));



# 1 "/usr/include/alloca.h" 1 3 4
# 24 "/usr/include/alloca.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 1 3 4
# 25 "/usr/include/alloca.h" 2 3 4







extern void *alloca (size_t __size) __attribute__ ((__nothrow__ , __leaf__));






# 575 "/usr/include/stdlib.h" 2 3 4





extern void *valloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__))
     __attribute__ ((__alloc_size__ (1))) ;




extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;




extern void *aligned_alloc (size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_align__ (1)))
     __attribute__ ((__alloc_size__ (2))) ;



extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







extern int at_quick_exit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));






extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern void exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));





extern void quick_exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));





extern void _Exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));




extern char *getenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 654 "/usr/include/stdlib.h" 3 4
extern int putenv (char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern int setenv (const char *__name, const char *__value, int __replace)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));


extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));






extern int clearenv (void) __attribute__ ((__nothrow__ , __leaf__));
# 682 "/usr/include/stdlib.h" 3 4
extern char *mktemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 695 "/usr/include/stdlib.h" 3 4
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
# 717 "/usr/include/stdlib.h" 3 4
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
# 738 "/usr/include/stdlib.h" 3 4
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 791 "/usr/include/stdlib.h" 3 4
extern int system (const char *__command) ;
# 808 "/usr/include/stdlib.h" 3 4
extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__ , __leaf__)) ;






typedef int (*__compar_fn_t) (const void *, const void *);
# 828 "/usr/include/stdlib.h" 3 4
extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;







extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
# 848 "/usr/include/stdlib.h" 3 4
extern int abs (int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;


__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;






extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;


__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
# 880 "/usr/include/stdlib.h" 3 4
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;




extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));

extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));





extern int mblen (const char *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));


extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));


extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ , __leaf__));



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__))
    __attribute__ ((__access__ (__read_only__, 2)));

extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__access__ (__write_only__, 1, 3)))
  __attribute__ ((__access__ (__read_only__, 2)));






extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 967 "/usr/include/stdlib.h" 3 4
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3))) ;
# 1013 "/usr/include/stdlib.h" 3 4
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 1023 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/stdlib-float.h" 1 3 4
# 1024 "/usr/include/stdlib.h" 2 3 4
# 1035 "/usr/include/stdlib.h" 3 4

# 33 "edit_parson.c" 2
# 1 "/usr/include/string.h" 1 3 4
# 26 "/usr/include/string.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 27 "/usr/include/string.h" 2 3 4






# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 1 3 4
# 34 "/usr/include/string.h" 2 3 4
# 43 "/usr/include/string.h" 3 4
extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));





extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__access__ (__write_only__, 1, 4)));




extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 80 "/usr/include/string.h" 3 4
extern int __memcmpeq (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 107 "/usr/include/string.h" 3 4
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 141 "/usr/include/string.h" 3 4
extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
    __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) __attribute__ ((__access__ (__write_only__, 1, 3)));



# 1 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h" 3 4
struct __locale_struct
{

  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
};

typedef struct __locale_struct *__locale_t;
# 23 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 2 3 4

typedef __locale_t locale_t;
# 173 "/usr/include/string.h" 2 3 4


extern int strcoll_l (const char *__s1, const char *__s2, locale_t __l)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));


extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    locale_t __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)))
     __attribute__ ((__access__ (__write_only__, 1, 3)));





extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));






extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
# 246 "/usr/include/string.h" 3 4
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 273 "/usr/include/string.h" 3 4
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 293 "/usr/include/string.h" 3 4
extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 323 "/usr/include/string.h" 3 4
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 350 "/usr/include/string.h" 3 4
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));



extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));

extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
# 407 "/usr/include/string.h" 3 4
extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern char *strerror (int __errnum) __attribute__ ((__nothrow__ , __leaf__));
# 432 "/usr/include/string.h" 3 4
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__ , __leaf__))

                        __attribute__ ((__nonnull__ (2)))
    __attribute__ ((__access__ (__write_only__, 2, 3)));
# 458 "/usr/include/string.h" 3 4
extern char *strerror_l (int __errnum, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));



# 1 "/usr/include/strings.h" 1 3 4
# 23 "/usr/include/strings.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/11/include/stddef.h" 1 3 4
# 24 "/usr/include/strings.h" 2 3 4










extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bcopy (const void *__src, void *__dest, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 68 "/usr/include/strings.h" 3 4
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 96 "/usr/include/strings.h" 3 4
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));






extern int ffs (int __i) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));





extern int ffsl (long int __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__ extern int ffsll (long long int __ll)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));






extern int strcasecmp_l (const char *__s1, const char *__s2, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));



extern int strncasecmp_l (const char *__s1, const char *__s2,
     size_t __n, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 4)));



# 463 "/usr/include/string.h" 2 3 4



extern void explicit_bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)))
    __attribute__ ((__access__ (__write_only__, 1, 2)));



extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
# 489 "/usr/include/string.h" 3 4
extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
# 539 "/usr/include/string.h" 3 4

# 34 "edit_parson.c" 2
# 1 "/usr/include/ctype.h" 1 3 4
# 28 "/usr/include/ctype.h" 3 4

# 46 "/usr/include/ctype.h" 3 4
enum
{
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
# 79 "/usr/include/ctype.h" 3 4
extern const unsigned short int **__ctype_b_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern const __int32_t **__ctype_tolower_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern const __int32_t **__ctype_toupper_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 108 "/usr/include/ctype.h" 3 4
extern int isalnum (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isalpha (int) __attribute__ ((__nothrow__ , __leaf__));
extern int iscntrl (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isdigit (int) __attribute__ ((__nothrow__ , __leaf__));
extern int islower (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isgraph (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isprint (int) __attribute__ ((__nothrow__ , __leaf__));
extern int ispunct (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isspace (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isupper (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isxdigit (int) __attribute__ ((__nothrow__ , __leaf__));



extern int tolower (int __c) __attribute__ ((__nothrow__ , __leaf__));


extern int toupper (int __c) __attribute__ ((__nothrow__ , __leaf__));




extern int isblank (int) __attribute__ ((__nothrow__ , __leaf__));
# 142 "/usr/include/ctype.h" 3 4
extern int isascii (int __c) __attribute__ ((__nothrow__ , __leaf__));



extern int toascii (int __c) __attribute__ ((__nothrow__ , __leaf__));



extern int _toupper (int) __attribute__ ((__nothrow__ , __leaf__));
extern int _tolower (int) __attribute__ ((__nothrow__ , __leaf__));
# 251 "/usr/include/ctype.h" 3 4
extern int isalnum_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isalpha_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int iscntrl_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isdigit_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int islower_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isgraph_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isprint_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int ispunct_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isspace_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isupper_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isxdigit_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));

extern int isblank_l (int, locale_t) __attribute__ ((__nothrow__ , __leaf__));



extern int __tolower_l (int __c, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern int tolower_l (int __c, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));


extern int __toupper_l (int __c, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern int toupper_l (int __c, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
# 327 "/usr/include/ctype.h" 3 4

# 35 "edit_parson.c" 2
# 1 "/usr/include/math.h" 1 3 4
# 27 "/usr/include/math.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 28 "/usr/include/math.h" 2 3 4












# 1 "/usr/include/x86_64-linux-gnu/bits/math-vector.h" 1 3 4
# 25 "/usr/include/x86_64-linux-gnu/bits/math-vector.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libm-simd-decl-stubs.h" 1 3 4
# 26 "/usr/include/x86_64-linux-gnu/bits/math-vector.h" 2 3 4
# 41 "/usr/include/math.h" 2 3 4
# 152 "/usr/include/math.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/flt-eval-method.h" 1 3 4
# 153 "/usr/include/math.h" 2 3 4
# 163 "/usr/include/math.h" 3 4
typedef float float_t;
typedef double double_t;
# 204 "/usr/include/math.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/fp-logb.h" 1 3 4
# 205 "/usr/include/math.h" 2 3 4
# 247 "/usr/include/math.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/fp-fast.h" 1 3 4
# 248 "/usr/include/math.h" 2 3 4
# 312 "/usr/include/math.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/mathcalls-helper-functions.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/mathcalls-helper-functions.h" 3 4
extern int __fpclassify (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));


extern int __signbit (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));



extern int __isinf (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __finite (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __isnan (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __iseqsig (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));


extern int __issignaling (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
# 313 "/usr/include/math.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 1 3 4
# 53 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
 extern double acos (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __acos (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double asin (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __asin (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double atan (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atan (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double atan2 (double __y, double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atan2 (double __y, double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern double cos (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cos (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double sin (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sin (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double tan (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __tan (double __x) __attribute__ ((__nothrow__ , __leaf__));




 extern double cosh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cosh (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double sinh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sinh (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double tanh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __tanh (double __x) __attribute__ ((__nothrow__ , __leaf__));
# 85 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
 extern double acosh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __acosh (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double asinh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __asinh (double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern double atanh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atanh (double __x) __attribute__ ((__nothrow__ , __leaf__));





 extern double exp (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double frexp (double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern double __frexp (double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));


extern double ldexp (double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern double __ldexp (double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));


 extern double log (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log (double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern double log10 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log10 (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double modf (double __x, double *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern double __modf (double __x, double *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
# 119 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
 extern double expm1 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __expm1 (double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern double log1p (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log1p (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double logb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __logb (double __x) __attribute__ ((__nothrow__ , __leaf__));




 extern double exp2 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp2 (double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern double log2 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log2 (double __x) __attribute__ ((__nothrow__ , __leaf__));






 extern double pow (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __pow (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));


extern double sqrt (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sqrt (double __x) __attribute__ ((__nothrow__ , __leaf__));



 extern double hypot (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __hypot (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));




 extern double cbrt (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cbrt (double __x) __attribute__ ((__nothrow__ , __leaf__));






extern double ceil (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __ceil (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern double fabs (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fabs (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern double floor (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __floor (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern double fmod (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __fmod (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
# 177 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
extern int isinf (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));




extern int finite (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern double drem (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __drem (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));



extern double significand (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __significand (double __x) __attribute__ ((__nothrow__ , __leaf__));






extern double copysign (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __copysign (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern double nan (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern double __nan (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
# 213 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
extern int isnan (double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));





extern double j0 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __j0 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double j1 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __j1 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double jn (int, double) __attribute__ ((__nothrow__ , __leaf__)); extern double __jn (int, double) __attribute__ ((__nothrow__ , __leaf__));
extern double y0 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __y0 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double y1 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __y1 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double yn (int, double) __attribute__ ((__nothrow__ , __leaf__)); extern double __yn (int, double) __attribute__ ((__nothrow__ , __leaf__));





 extern double erf (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __erf (double) __attribute__ ((__nothrow__ , __leaf__));
 extern double erfc (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __erfc (double) __attribute__ ((__nothrow__ , __leaf__));
extern double lgamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __lgamma (double) __attribute__ ((__nothrow__ , __leaf__));




extern double tgamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __tgamma (double) __attribute__ ((__nothrow__ , __leaf__));





extern double gamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __gamma (double) __attribute__ ((__nothrow__ , __leaf__));







extern double lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern double __lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));






extern double rint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __rint (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double nextafter (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __nextafter (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));

extern double nexttoward (double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __nexttoward (double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
# 275 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
extern double remainder (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __remainder (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));



extern double scalbn (double __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalbn (double __x, int __n) __attribute__ ((__nothrow__ , __leaf__));



extern int ilogb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogb (double __x) __attribute__ ((__nothrow__ , __leaf__));
# 293 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
extern double scalbln (double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalbln (double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));



extern double nearbyint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __nearbyint (double __x) __attribute__ ((__nothrow__ , __leaf__));



extern double round (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __round (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern double trunc (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __trunc (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern double remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern double __remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));






extern long int lrint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrint (double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrint (double __x) __attribute__ ((__nothrow__ , __leaf__));



extern long int lround (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lround (double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llround (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llround (double __x) __attribute__ ((__nothrow__ , __leaf__));



extern double fdim (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __fdim (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));



extern double fmax (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmax (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern double fmin (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmin (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern double fma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__)); extern double __fma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__));
# 435 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
extern double scalb (double __x, double __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalb (double __x, double __n) __attribute__ ((__nothrow__ , __leaf__));
# 314 "/usr/include/math.h" 2 3 4
# 329 "/usr/include/math.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/mathcalls-helper-functions.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/mathcalls-helper-functions.h" 3 4
extern int __fpclassifyf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));


extern int __signbitf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));



extern int __isinff (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __finitef (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __isnanf (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __iseqsigf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));


extern int __issignalingf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
# 330 "/usr/include/math.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 1 3 4
# 53 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
 extern float acosf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __acosf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float asinf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __asinf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float atanf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atanf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float atan2f (float __y, float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atan2f (float __y, float __x) __attribute__ ((__nothrow__ , __leaf__));


 extern float cosf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __cosf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float sinf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sinf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float tanf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __tanf (float __x) __attribute__ ((__nothrow__ , __leaf__));




 extern float coshf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __coshf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float sinhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sinhf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float tanhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __tanhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
# 85 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
 extern float acoshf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __acoshf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float asinhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __asinhf (float __x) __attribute__ ((__nothrow__ , __leaf__));

 extern float atanhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atanhf (float __x) __attribute__ ((__nothrow__ , __leaf__));





 extern float expf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __expf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern float __frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));


extern float ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern float __ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));


 extern float logf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __logf (float __x) __attribute__ ((__nothrow__ , __leaf__));


 extern float log10f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log10f (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float modff (float __x, float *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern float __modff (float __x, float *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
# 119 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
 extern float expm1f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __expm1f (float __x) __attribute__ ((__nothrow__ , __leaf__));


 extern float log1pf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log1pf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float logbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __logbf (float __x) __attribute__ ((__nothrow__ , __leaf__));




 extern float exp2f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __exp2f (float __x) __attribute__ ((__nothrow__ , __leaf__));


 extern float log2f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log2f (float __x) __attribute__ ((__nothrow__ , __leaf__));






 extern float powf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __powf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));


extern float sqrtf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sqrtf (float __x) __attribute__ ((__nothrow__ , __leaf__));



 extern float hypotf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __hypotf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));




 extern float cbrtf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __cbrtf (float __x) __attribute__ ((__nothrow__ , __leaf__));






extern float ceilf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __ceilf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern float fabsf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fabsf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern float floorf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __floorf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern float fmodf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __fmodf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
# 177 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
extern int isinff (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));




extern int finitef (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern float dremf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __dremf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));



extern float significandf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __significandf (float __x) __attribute__ ((__nothrow__ , __leaf__));






extern float copysignf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __copysignf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern float nanf (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern float __nanf (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
# 213 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
extern int isnanf (float __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));





extern float j0f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __j0f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float j1f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __j1f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float jnf (int, float) __attribute__ ((__nothrow__ , __leaf__)); extern float __jnf (int, float) __attribute__ ((__nothrow__ , __leaf__));
extern float y0f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __y0f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float y1f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __y1f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float ynf (int, float) __attribute__ ((__nothrow__ , __leaf__)); extern float __ynf (int, float) __attribute__ ((__nothrow__ , __leaf__));





 extern float erff (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __erff (float) __attribute__ ((__nothrow__ , __leaf__));
 extern float erfcf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __erfcf (float) __attribute__ ((__nothrow__ , __leaf__));
extern float lgammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __lgammaf (float) __attribute__ ((__nothrow__ , __leaf__));




extern float tgammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __tgammaf (float) __attribute__ ((__nothrow__ , __leaf__));





extern float gammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __gammaf (float) __attribute__ ((__nothrow__ , __leaf__));







extern float lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern float __lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));






extern float rintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __rintf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float nextafterf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __nextafterf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));

extern float nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
# 275 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
extern float remainderf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __remainderf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));



extern float scalbnf (float __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalbnf (float __x, int __n) __attribute__ ((__nothrow__ , __leaf__));



extern int ilogbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbf (float __x) __attribute__ ((__nothrow__ , __leaf__));
# 293 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
extern float scalblnf (float __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalblnf (float __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));



extern float nearbyintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __nearbyintf (float __x) __attribute__ ((__nothrow__ , __leaf__));



extern float roundf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __roundf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern float truncf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __truncf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern float remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern float __remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));






extern long int lrintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintf (float __x) __attribute__ ((__nothrow__ , __leaf__));



extern long int lroundf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundf (float __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundf (float __x) __attribute__ ((__nothrow__ , __leaf__));



extern float fdimf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __fdimf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));



extern float fmaxf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fmaxf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern float fminf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fminf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern float fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__ , __leaf__)); extern float __fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__ , __leaf__));
# 435 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
extern float scalbf (float __x, float __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalbf (float __x, float __n) __attribute__ ((__nothrow__ , __leaf__));
# 331 "/usr/include/math.h" 2 3 4
# 398 "/usr/include/math.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/mathcalls-helper-functions.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/mathcalls-helper-functions.h" 3 4
extern int __fpclassifyl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));


extern int __signbitl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));



extern int __isinfl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __finitel (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __isnanl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __iseqsigl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));


extern int __issignalingl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
# 399 "/usr/include/math.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 1 3 4
# 53 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
 extern long double acosl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __acosl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double asinl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __asinl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double atanl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atanl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double atan2l (long double __y, long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atan2l (long double __y, long double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern long double cosl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __cosl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double sinl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sinl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double tanl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tanl (long double __x) __attribute__ ((__nothrow__ , __leaf__));




 extern long double coshl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __coshl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double sinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double tanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
# 85 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
 extern long double acoshl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __acoshl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double asinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __asinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

 extern long double atanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));





 extern long double expl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __expl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern long double __frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));


extern long double ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern long double __ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));


 extern long double logl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __logl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern long double log10l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log10l (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern long double __modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
# 119 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
 extern long double expm1l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __expm1l (long double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern long double log1pl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log1pl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double logbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __logbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));




 extern long double exp2l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __exp2l (long double __x) __attribute__ ((__nothrow__ , __leaf__));


 extern long double log2l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log2l (long double __x) __attribute__ ((__nothrow__ , __leaf__));






 extern long double powl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __powl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));


extern long double sqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));



 extern long double hypotl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __hypotl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));




 extern long double cbrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __cbrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));






extern long double ceill (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __ceill (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern long double fabsl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fabsl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern long double floorl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __floorl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern long double fmodl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fmodl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
# 177 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
extern int isinfl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));




extern int finitel (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern long double dreml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __dreml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));



extern long double significandl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __significandl (long double __x) __attribute__ ((__nothrow__ , __leaf__));






extern long double copysignl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __copysignl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern long double nanl (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nanl (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__));
# 213 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
extern int isnanl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));





extern long double j0l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __j0l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double j1l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __j1l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double jnl (int, long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __jnl (int, long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double y0l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __y0l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double y1l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __y1l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double ynl (int, long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __ynl (int, long double) __attribute__ ((__nothrow__ , __leaf__));





 extern long double erfl (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __erfl (long double) __attribute__ ((__nothrow__ , __leaf__));
 extern long double erfcl (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __erfcl (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double lgammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __lgammal (long double) __attribute__ ((__nothrow__ , __leaf__));




extern long double tgammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tgammal (long double) __attribute__ ((__nothrow__ , __leaf__));





extern long double gammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __gammal (long double) __attribute__ ((__nothrow__ , __leaf__));







extern long double lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern long double __lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));






extern long double rintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __rintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));

extern long double nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
# 275 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
extern long double remainderl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __remainderl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));



extern long double scalbnl (long double __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalbnl (long double __x, int __n) __attribute__ ((__nothrow__ , __leaf__));



extern int ilogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
# 293 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
extern long double scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));



extern long double nearbyintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nearbyintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));



extern long double roundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __roundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern long double truncl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __truncl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));




extern long double remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern long double __remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));






extern long int lrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));



extern long int lroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__));



extern long double fdiml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fdiml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));



extern long double fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern long double fminl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fminl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));



extern long double fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__));
# 435 "/usr/include/x86_64-linux-gnu/bits/mathcalls.h" 3 4
extern long double scalbl (long double __x, long double __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalbl (long double __x, long double __n) __attribute__ ((__nothrow__ , __leaf__));
# 400 "/usr/include/math.h" 2 3 4
# 481 "/usr/include/math.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/mathcalls-helper-functions.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/mathcalls-helper-functions.h" 3 4
extern int __fpclassifyf128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));


extern int __signbitf128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));



extern int __isinff128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __finitef128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __isnanf128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
  __attribute__ ((__const__));


extern int __iseqsigf128 (_Float128 __x, _Float128 __y) __attribute__ ((__nothrow__ , __leaf__));


extern int __issignalingf128 (_Float128 __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
# 482 "/usr/include/math.h" 2 3 4
# 854 "/usr/include/math.h" 3 4
extern int signgam;
# 934 "/usr/include/math.h" 3 4
enum
  {
    FP_NAN =

      0,
    FP_INFINITE =

      1,
    FP_ZERO =

      2,
    FP_SUBNORMAL =

      3,
    FP_NORMAL =

      4
  };
# 1423 "/usr/include/math.h" 3 4

# 36 "edit_parson.c" 2
# 1 "/usr/include/errno.h" 1 3 4
# 28 "/usr/include/errno.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/errno.h" 1 3 4
# 26 "/usr/include/x86_64-linux-gnu/bits/errno.h" 3 4
# 1 "/usr/include/linux/errno.h" 1 3 4
# 1 "/usr/include/x86_64-linux-gnu/asm/errno.h" 1 3 4
# 1 "/usr/include/asm-generic/errno.h" 1 3 4




# 1 "/usr/include/asm-generic/errno-base.h" 1 3 4
# 6 "/usr/include/asm-generic/errno.h" 2 3 4
# 2 "/usr/include/x86_64-linux-gnu/asm/errno.h" 2 3 4
# 2 "/usr/include/linux/errno.h" 2 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/errno.h" 2 3 4
# 29 "/usr/include/errno.h" 2 3 4








extern int *__errno_location (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 52 "/usr/include/errno.h" 3 4

# 37 "edit_parson.c" 2
# 51 "edit_parson.c"

# 51 "edit_parson.c"
static JSON_Malloc_Function parson_malloc = malloc;
static JSON_Free_Function parson_free = free;

static int parson_escape_slashes = 1;

static char *parson_float_format = 
# 56 "edit_parson.c" 3 4
                                  ((void *)0)
# 56 "edit_parson.c"
                                      ;

static JSON_Number_Serialization_Function parson_number_serialization_function = 
# 58 "edit_parson.c" 3 4
                                                                                ((void *)0)
# 58 "edit_parson.c"
                                                                                    ;


typedef int parson_bool_t;


typedef struct json_string {
    char *chars;
    size_t length;
} JSON_String;


typedef union json_value_value {
    JSON_String string;
    double number;
    JSON_Object *object;
    JSON_Array *array;
    int boolean;
    int null;
} JSON_Value_Value;

struct json_value_t {
    JSON_Value *parent;
    JSON_Value_Type type;
    JSON_Value_Value value;
};

struct json_object_t {
    JSON_Value *wrapping_value;
    size_t *cells;
    unsigned long *hashes;
    char **names;
    JSON_Value **values;
    size_t *cell_ixs;
    size_t count;
    size_t item_capacity;
    size_t cell_capacity;
};

struct json_array_t {
    JSON_Value *wrapping_value;
    JSON_Value **items;
    size_t count;
    size_t capacity;
};


static char * read_file(const char *filename);
static void remove_comments(char *string, const char *start_token, const char *end_token);
static char * parson_strndup(const char *string, size_t n);
static char * parson_strdup(const char *string);
static int hex_char_to_int(char c);
static JSON_Status parse_utf16_hex(const char *string, unsigned int *result);
static int num_bytes_in_utf8_sequence(unsigned char c);
static JSON_Status verify_utf8_sequence(const unsigned char *string, int *len);
static parson_bool_t is_valid_utf8(const char *string, size_t string_len);
static parson_bool_t is_decimal(const char *string, size_t length);
static unsigned long hash_string(const char *string, size_t n);


static JSON_Object * json_object_make(JSON_Value *wrapping_value);
static JSON_Status json_object_init(JSON_Object *object, size_t capacity);
static void json_object_deinit(JSON_Object *object, parson_bool_t free_keys, parson_bool_t free_values);
static JSON_Status json_object_grow_and_rehash(JSON_Object *object);
static size_t json_object_get_cell_ix(const JSON_Object *object, const char *key, size_t key_len, unsigned long hash, parson_bool_t *out_found);
static JSON_Status json_object_add(JSON_Object *object, char *name, JSON_Value *value);
static JSON_Value * json_object_getn_value(const JSON_Object *object, const char *name, size_t name_len);
static JSON_Status json_object_remove_internal(JSON_Object *object, const char *name, parson_bool_t free_value);
static JSON_Status json_object_dotremove_internal(JSON_Object *object, const char *name, parson_bool_t free_value);
static void json_object_free(JSON_Object *object);


static JSON_Array * json_array_make(JSON_Value *wrapping_value);
static JSON_Status json_array_add(JSON_Array *array, JSON_Value *value);
static JSON_Status json_array_resize(JSON_Array *array, size_t new_capacity);
static void json_array_free(JSON_Array *array);


static JSON_Value * json_value_init_string_no_copy(char *string, size_t length);
static const JSON_String * json_value_get_string_desc(const JSON_Value *value);


static JSON_Status skip_quotes(const char **string);
static JSON_Status parse_utf16(const char **unprocessed, char **processed);
static char * process_string(const char *input, size_t input_len, size_t *output_len);
static char * get_quoted_string(const char **string, size_t *output_string_len);
static JSON_Value * parse_object_value(const char **string, size_t nesting);
static JSON_Value * parse_array_value(const char **string, size_t nesting);
static JSON_Value * parse_string_value(const char **string);
static JSON_Value * parse_boolean_value(const char **string);
static JSON_Value * parse_number_value(const char **string);
static JSON_Value * parse_null_value(const char **string);
static JSON_Value * parse_value(const char **string, size_t nesting);


static int json_serialize_to_buffer_r(const JSON_Value *value, char *buf, int level, parson_bool_t is_pretty, char *num_buf);
static int json_serialize_string(const char *string, size_t len, char *buf);


static char * read_file(const char * filename) {
    FILE *fp = fopen(filename, "r");
    size_t size_to_read = 0;
    size_t size_read = 0;
    long pos;
    char *file_contents;
    if (!fp) {
        return 
# 164 "edit_parson.c" 3 4
              ((void *)0)
# 164 "edit_parson.c"
                  ;
    }
    fseek(fp, 0L, 2);
    pos = ftell(fp);
    if (pos < 0) {
        fclose(fp);
        return 
# 170 "edit_parson.c" 3 4
              ((void *)0)
# 170 "edit_parson.c"
                  ;
    }
    size_to_read = pos;
    rewind(fp);
    file_contents = (char*)parson_malloc(sizeof(char) * (size_to_read + 1));
    if (!file_contents) {
        fclose(fp);
        return 
# 177 "edit_parson.c" 3 4
              ((void *)0)
# 177 "edit_parson.c"
                  ;
    }
    size_read = fread(file_contents, 1, size_to_read, fp);
    if (size_read == 0 || ferror(fp)) {
        fclose(fp);
        parson_free(file_contents);
        return 
# 183 "edit_parson.c" 3 4
              ((void *)0)
# 183 "edit_parson.c"
                  ;
    }
    fclose(fp);
    file_contents[size_read] = '\0';
    return file_contents;
}

static void remove_comments(char *string, const char *start_token, const char *end_token) {
    parson_bool_t in_string = 0, escaped = 0;
    size_t i;
    char *ptr = 
# 193 "edit_parson.c" 3 4
               ((void *)0)
# 193 "edit_parson.c"
                   , current_char;
    size_t start_token_len = strlen(start_token);
    size_t end_token_len = strlen(end_token);
    if (start_token_len == 0 || end_token_len == 0) {
        return;
    }
    while ((current_char = *string) != '\0') {
        if (current_char == '\\' && !escaped) {
            escaped = 1;
            string++;
            continue;
        } else if (current_char == '\"' && !escaped) {
            in_string = !in_string;
        } else if (!in_string && strncmp(string, start_token, start_token_len) == 0) {
            for(i = 0; i < start_token_len; i++) {
                string[i] = ' ';
            }
            string = string + start_token_len;
            ptr = strstr(string, end_token);
            if (!ptr) {
                return;
            }
            for (i = 0; i < (ptr - string) + end_token_len; i++) {
                string[i] = ' ';
            }
            string = ptr + end_token_len - 1;
        }
        escaped = 0;
        string++;
    }
}

static char * parson_strndup(const char *string, size_t n) {

    char *output_string = (char*)parson_malloc(n + 1);
    if (!output_string) {
        return 
# 229 "edit_parson.c" 3 4
              ((void *)0)
# 229 "edit_parson.c"
                  ;
    }
    output_string[n] = '\0';
    memcpy(output_string, string, n);
    return output_string;
}

static char * parson_strdup(const char *string) {
    return parson_strndup(string, strlen(string));
}

static int hex_char_to_int(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    return -1;
}

static JSON_Status parse_utf16_hex(const char *s, unsigned int *result) {
    int x1, x2, x3, x4;
    if (s[0] == '\0' || s[1] == '\0' || s[2] == '\0' || s[3] == '\0') {
        return JSONFailure;
    }
    x1 = hex_char_to_int(s[0]);
    x2 = hex_char_to_int(s[1]);
    x3 = hex_char_to_int(s[2]);
    x4 = hex_char_to_int(s[3]);
    if (x1 == -1 || x2 == -1 || x3 == -1 || x4 == -1) {
        return JSONFailure;
    }
    *result = (unsigned int)((x1 << 12) | (x2 << 8) | (x3 << 4) | x4);
    return JSONSuccess;
}

static int num_bytes_in_utf8_sequence(unsigned char c) {
    if (c == 0xC0 || c == 0xC1 || c > 0xF4 || (((unsigned char)(c) & 0xC0) == 0x80)) {
        return 0;
    } else if ((c & 0x80) == 0) {
        return 1;
    } else if ((c & 0xE0) == 0xC0) {
        return 2;
    } else if ((c & 0xF0) == 0xE0) {
        return 3;
    } else if ((c & 0xF8) == 0xF0) {
        return 4;
    }
    return 0;
}

static JSON_Status verify_utf8_sequence(const unsigned char *string, int *len) {
    unsigned int cp = 0;
    *len = num_bytes_in_utf8_sequence(string[0]);

    if (*len == 1) {
        cp = string[0];
    } else if (*len == 2 && (((unsigned char)(string[1]) & 0xC0) == 0x80)) {
        cp = string[0] & 0x1F;
        cp = (cp << 6) | (string[1] & 0x3F);
    } else if (*len == 3 && (((unsigned char)(string[1]) & 0xC0) == 0x80) && (((unsigned char)(string[2]) & 0xC0) == 0x80)) {
        cp = ((unsigned char)string[0]) & 0xF;
        cp = (cp << 6) | (string[1] & 0x3F);
        cp = (cp << 6) | (string[2] & 0x3F);
    } else if (*len == 4 && (((unsigned char)(string[1]) & 0xC0) == 0x80) && (((unsigned char)(string[2]) & 0xC0) == 0x80) && (((unsigned char)(string[3]) & 0xC0) == 0x80)) {
        cp = string[0] & 0x7;
        cp = (cp << 6) | (string[1] & 0x3F);
        cp = (cp << 6) | (string[2] & 0x3F);
        cp = (cp << 6) | (string[3] & 0x3F);
    } else {
        return JSONFailure;
    }


    if ((cp < 0x80 && *len > 1) ||
        (cp < 0x800 && *len > 2) ||
        (cp < 0x10000 && *len > 3)) {
        return JSONFailure;
    }


    if (cp > 0x10FFFF) {
        return JSONFailure;
    }


    if (cp >= 0xD800 && cp <= 0xDFFF) {
        return JSONFailure;
    }

    return JSONSuccess;
}

static int is_valid_utf8(const char *string, size_t string_len) {
    int len = 0;
    const char *string_end = string + string_len;
    while (string < string_end) {
        if (verify_utf8_sequence((const unsigned char*)string, &len) != JSONSuccess) {
            return 0;
        }
        string += len;
    }
    return 1;
}

static parson_bool_t is_decimal(const char *string, size_t length) {
    if (length > 1 && string[0] == '0' && string[1] != '.') {
        return 0;
    }
    if (length > 2 && !strncmp(string, "-0", 2) && string[2] != '.') {
        return 0;
    }
    while (length--) {
        if (strchr("xX", string[length])) {
            return 0;
        }
    }
    return 1;
}

static unsigned long hash_string(const char *string, size_t n) {
    unsigned long hash = 5381;
    unsigned char c;
    size_t i = 0;
    for (i = 0; i < n; i++) {
        c = string[i];
        if (c == '\0') {
            break;
        }
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}


static JSON_Object * json_object_make(JSON_Value *wrapping_value) {
    JSON_Status res = JSONFailure;
    JSON_Object *new_obj = (JSON_Object*)parson_malloc(sizeof(JSON_Object));
    if (new_obj == 
# 369 "edit_parson.c" 3 4
                  ((void *)0)
# 369 "edit_parson.c"
                      ) {
        return 
# 370 "edit_parson.c" 3 4
              ((void *)0)
# 370 "edit_parson.c"
                  ;
    }
    new_obj->wrapping_value = wrapping_value;
    res = json_object_init(new_obj, 0);
    if (res != JSONSuccess) {
        parson_free(new_obj);
        return 
# 376 "edit_parson.c" 3 4
              ((void *)0)
# 376 "edit_parson.c"
                  ;
    }
    return new_obj;
}

static JSON_Status json_object_init(JSON_Object *object, size_t capacity) {
    unsigned int i = 0;

    object->cells = 
# 384 "edit_parson.c" 3 4
                   ((void *)0)
# 384 "edit_parson.c"
                       ;
    object->names = 
# 385 "edit_parson.c" 3 4
                   ((void *)0)
# 385 "edit_parson.c"
                       ;
    object->values = 
# 386 "edit_parson.c" 3 4
                    ((void *)0)
# 386 "edit_parson.c"
                        ;
    object->cell_ixs = 
# 387 "edit_parson.c" 3 4
                      ((void *)0)
# 387 "edit_parson.c"
                          ;
    object->hashes = 
# 388 "edit_parson.c" 3 4
                    ((void *)0)
# 388 "edit_parson.c"
                        ;

    object->count = 0;
    object->cell_capacity = capacity;
    object->item_capacity = (unsigned int)(capacity * 0.7f);

    if (capacity == 0) {
        return JSONSuccess;
    }

    object->cells = (size_t*)parson_malloc(object->cell_capacity * sizeof(*object->cells));
    object->names = (char**)parson_malloc(object->item_capacity * sizeof(*object->names));
    object->values = (JSON_Value**)parson_malloc(object->item_capacity * sizeof(*object->values));
    object->cell_ixs = (size_t*)parson_malloc(object->item_capacity * sizeof(*object->cell_ixs));
    object->hashes = (unsigned long*)parson_malloc(object->item_capacity * sizeof(*object->hashes));
    if (object->cells == 
# 403 "edit_parson.c" 3 4
                        ((void *)0)
        
# 404 "edit_parson.c"
       || object->names == 
# 404 "edit_parson.c" 3 4
                           ((void *)0)
        
# 405 "edit_parson.c"
       || object->values == 
# 405 "edit_parson.c" 3 4
                            ((void *)0)
        
# 406 "edit_parson.c"
       || object->cell_ixs == 
# 406 "edit_parson.c" 3 4
                              ((void *)0)
        
# 407 "edit_parson.c"
       || object->hashes == 
# 407 "edit_parson.c" 3 4
                            ((void *)0)
# 407 "edit_parson.c"
                                ) {
        goto error;
    }
    for (i = 0; i < object->cell_capacity; i++) {
        object->cells[i] = ((size_t)-1);
    }
    return JSONSuccess;
error:
    parson_free(object->cells);
    parson_free(object->names);
    parson_free(object->values);
    parson_free(object->cell_ixs);
    parson_free(object->hashes);
    return JSONFailure;
}

static void json_object_deinit(JSON_Object *object, parson_bool_t free_keys, parson_bool_t free_values) {
    unsigned int i = 0;
    for (i = 0; i < object->count; i++) {
        if (free_keys) {
            parson_free(object->names[i]);
        }
        if (free_values) {
            json_value_free(object->values[i]);
        }
    }

    object->count = 0;
    object->item_capacity = 0;
    object->cell_capacity = 0;

    parson_free(object->cells);
    parson_free(object->names);
    parson_free(object->values);
    parson_free(object->cell_ixs);
    parson_free(object->hashes);

    object->cells = 
# 444 "edit_parson.c" 3 4
                   ((void *)0)
# 444 "edit_parson.c"
                       ;
    object->names = 
# 445 "edit_parson.c" 3 4
                   ((void *)0)
# 445 "edit_parson.c"
                       ;
    object->values = 
# 446 "edit_parson.c" 3 4
                    ((void *)0)
# 446 "edit_parson.c"
                        ;
    object->cell_ixs = 
# 447 "edit_parson.c" 3 4
                      ((void *)0)
# 447 "edit_parson.c"
                          ;
    object->hashes = 
# 448 "edit_parson.c" 3 4
                    ((void *)0)
# 448 "edit_parson.c"
                        ;
}

static JSON_Status json_object_grow_and_rehash(JSON_Object *object) {
    JSON_Value *wrapping_value = 
# 452 "edit_parson.c" 3 4
                                ((void *)0)
# 452 "edit_parson.c"
                                    ;
    JSON_Object new_object;
    char *key = 
# 454 "edit_parson.c" 3 4
               ((void *)0)
# 454 "edit_parson.c"
                   ;
    JSON_Value *value = 
# 455 "edit_parson.c" 3 4
                       ((void *)0)
# 455 "edit_parson.c"
                           ;
    unsigned int i = 0;
    size_t new_capacity = ((object->cell_capacity * 2) > (b) ? (object->cell_capacity * 2) : (b));
    JSON_Status res = json_object_init(&new_object, new_capacity);
    if (res != JSONSuccess) {
        return JSONFailure;
    }

    wrapping_value = json_object_get_wrapping_value(object);
    new_object.wrapping_value = wrapping_value;

    for (i = 0; i < object->count; i++) {
        key = object->names[i];
        value = object->values[i];
        res = json_object_add(&new_object, key, value);
        if (res != JSONSuccess) {
            json_object_deinit(&new_object, 0, 0);
            return JSONFailure;
        }
        value->parent = wrapping_value;
    }
    json_object_deinit(object, 0, 0);
    *object = new_object;
    return JSONSuccess;
}

static size_t json_object_get_cell_ix(const JSON_Object *object, const char *key, size_t key_len, unsigned long hash, parson_bool_t *out_found) {
    size_t cell_ix = hash & (object->cell_capacity - 1);
    size_t cell = 0;
    size_t ix = 0;
    unsigned int i = 0;
    unsigned long hash_to_check = 0;
    const char *key_to_check = 
# 487 "edit_parson.c" 3 4
                              ((void *)0)
# 487 "edit_parson.c"
                                  ;
    size_t key_to_check_len = 0;

    *out_found = 0;

    for (i = 0; i < object->cell_capacity; i++) {
        ix = (cell_ix + i) & (object->cell_capacity - 1);
        cell = object->cells[ix];
        if (cell == ((size_t)-1)) {
            return ix;
        }
        hash_to_check = object->hashes[cell];
        if (hash != hash_to_check) {
            continue;
        }
        key_to_check = object->names[cell];
        key_to_check_len = strlen(key_to_check);
        if (key_to_check_len == key_len && strncmp(key, key_to_check, key_len) == 0) {
            *out_found = 1;
            return ix;
        }
    }
    return ((size_t)-1);
}

static JSON_Status json_object_add(JSON_Object *object, char *name, JSON_Value *value) {
    unsigned long hash = 0;
    parson_bool_t found = 0;
    size_t cell_ix = 0;
    JSON_Status res = JSONFailure;

    if (!object || !name || !value) {
        return JSONFailure;
    }

    hash = hash_string(name, strlen(name));
    found = 0;
    cell_ix = json_object_get_cell_ix(object, name, strlen(name), hash, &found);
    if (found) {
        return JSONFailure;
    }

    if (object->count >= object->item_capacity) {
        res = json_object_grow_and_rehash(object);
        if (res != JSONSuccess) {
            return JSONFailure;
        }
        cell_ix = json_object_get_cell_ix(object, name, strlen(name), hash, &found);
    }

    object->names[object->count] = name;
    object->cells[cell_ix] = object->count;
    object->values[object->count] = value;
    object->cell_ixs[object->count] = cell_ix;
    object->hashes[object->count] = hash;
    object->count++;
    value->parent = json_object_get_wrapping_value(object);

    return JSONSuccess;
}

static JSON_Value * json_object_getn_value(const JSON_Object *object, const char *name, size_t name_len) {
    unsigned long hash = 0;
    parson_bool_t found = 0;
    size_t cell_ix = 0;
    size_t item_ix = 0;
    if (!object || !name) {
        return 
# 554 "edit_parson.c" 3 4
              ((void *)0)
# 554 "edit_parson.c"
                  ;
    }
    hash = hash_string(name, name_len);
    found = 0;
    cell_ix = json_object_get_cell_ix(object, name, name_len, hash, &found);
    if (!found) {
        return 
# 560 "edit_parson.c" 3 4
              ((void *)0)
# 560 "edit_parson.c"
                  ;
    }
    item_ix = object->cells[cell_ix];
    return object->values[item_ix];
}

static JSON_Status json_object_remove_internal(JSON_Object *object, const char *name, parson_bool_t free_value) {
    unsigned long hash = 0;
    parson_bool_t found = 0;
    size_t cell = 0;
    size_t item_ix = 0;
    size_t last_item_ix = 0;
    size_t i = 0;
    size_t j = 0;
    size_t x = 0;
    size_t k = 0;
    JSON_Value *val = 
# 576 "edit_parson.c" 3 4
                     ((void *)0)
# 576 "edit_parson.c"
                         ;

    if (object == 
# 578 "edit_parson.c" 3 4
                 ((void *)0)
# 578 "edit_parson.c"
                     ) {
        return JSONFailure;
    }

    hash = hash_string(name, strlen(name));
    found = 0;
    cell = json_object_get_cell_ix(object, name, strlen(name), hash, &found);
    if (!found) {
        return JSONFailure;
    }

    item_ix = object->cells[cell];
    if (free_value) {
        val = object->values[item_ix];
        json_value_free(val);
        val = 
# 593 "edit_parson.c" 3 4
             ((void *)0)
# 593 "edit_parson.c"
                 ;
    }

    parson_free(object->names[item_ix]);
    last_item_ix = object->count - 1;
    if (item_ix < last_item_ix) {
        object->names[item_ix] = object->names[last_item_ix];
        object->values[item_ix] = object->values[last_item_ix];
        object->cell_ixs[item_ix] = object->cell_ixs[last_item_ix];
        object->hashes[item_ix] = object->hashes[last_item_ix];
        object->cells[object->cell_ixs[item_ix]] = item_ix;
    }
    object->count--;

    i = cell;
    j = i;
    for (x = 0; x < (object->cell_capacity - 1); x++) {
        j = (j + 1) & (object->cell_capacity - 1);
        if (object->cells[j] == ((size_t)-1)) {
            break;
        }
        k = object->hashes[object->cells[j]] & (object->cell_capacity - 1);
        if ((j > i && (k <= i || k > j))
         || (j < i && (k <= i && k > j))) {
            object->cell_ixs[object->cells[j]] = i;
            object->cells[i] = object->cells[j];
            i = j;
        }
    }
    object->cells[i] = ((size_t)-1);
    return JSONSuccess;
}

static JSON_Status json_object_dotremove_internal(JSON_Object *object, const char *name, parson_bool_t free_value) {
    JSON_Value *temp_value = 
# 627 "edit_parson.c" 3 4
                            ((void *)0)
# 627 "edit_parson.c"
                                ;
    JSON_Object *temp_object = 
# 628 "edit_parson.c" 3 4
                              ((void *)0)
# 628 "edit_parson.c"
                                  ;
    const char *dot_pos = strchr(name, '.');
    if (!dot_pos) {
        return json_object_remove_internal(object, name, free_value);
    }
    temp_value = json_object_getn_value(object, name, dot_pos - name);
    if (json_value_get_type(temp_value) != JSONObject) {
        return JSONFailure;
    }
    temp_object = json_value_get_object(temp_value);
    return json_object_dotremove_internal(temp_object, dot_pos + 1, free_value);
}

static void json_object_free(JSON_Object *object) {
    json_object_deinit(object, 1, 1);
    parson_free(object);
}


static JSON_Array * json_array_make(JSON_Value *wrapping_value) {
    JSON_Array *new_array = (JSON_Array*)parson_malloc(sizeof(JSON_Array));
    if (new_array == 
# 649 "edit_parson.c" 3 4
                    ((void *)0)
# 649 "edit_parson.c"
                        ) {
        return 
# 650 "edit_parson.c" 3 4
              ((void *)0)
# 650 "edit_parson.c"
                  ;
    }
    new_array->wrapping_value = wrapping_value;
    new_array->items = (JSON_Value**)
# 653 "edit_parson.c" 3 4
                                    ((void *)0)
# 653 "edit_parson.c"
                                        ;
    new_array->capacity = 0;
    new_array->count = 0;
    return new_array;
}

static JSON_Status json_array_add(JSON_Array *array, JSON_Value *value) {
    if (array->count >= array->capacity) {
        size_t new_capacity = ((array->capacity * 2) > (b) ? (array->capacity * 2) : (b));
        if (json_array_resize(array, new_capacity) != JSONSuccess) {
            return JSONFailure;
        }
    }
    value->parent = json_array_get_wrapping_value(array);
    array->items[array->count] = value;
    array->count++;
    return JSONSuccess;
}

static JSON_Status json_array_resize(JSON_Array *array, size_t new_capacity) {
    JSON_Value **new_items = 
# 673 "edit_parson.c" 3 4
                            ((void *)0)
# 673 "edit_parson.c"
                                ;
    if (new_capacity == 0) {
        return JSONFailure;
    }
    new_items = (JSON_Value**)parson_malloc(new_capacity * sizeof(JSON_Value*));
    if (new_items == 
# 678 "edit_parson.c" 3 4
                    ((void *)0)
# 678 "edit_parson.c"
                        ) {
        return JSONFailure;
    }
    if (array->items != 
# 681 "edit_parson.c" 3 4
                       ((void *)0) 
# 681 "edit_parson.c"
                            && array->count > 0) {
        memcpy(new_items, array->items, array->count * sizeof(JSON_Value*));
    }
    parson_free(array->items);
    array->items = new_items;
    array->capacity = new_capacity;
    return JSONSuccess;
}

static void json_array_free(JSON_Array *array) {
    size_t i;
    for (i = 0; i < array->count; i++) {
        json_value_free(array->items[i]);
    }
    parson_free(array->items);
    parson_free(array);
}


static JSON_Value * json_value_init_string_no_copy(char *string, size_t length) {
    JSON_Value *new_value = (JSON_Value*)parson_malloc(sizeof(JSON_Value));
    if (!new_value) {
        return 
# 703 "edit_parson.c" 3 4
              ((void *)0)
# 703 "edit_parson.c"
                  ;
    }
    new_value->parent = 
# 705 "edit_parson.c" 3 4
                       ((void *)0)
# 705 "edit_parson.c"
                           ;
    new_value->type = JSONString;
    new_value->value.string.chars = string;
    new_value->value.string.length = length;
    return new_value;
}


static JSON_Status skip_quotes(const char **string) {
    if (**string != '\"') {
        return JSONFailure;
    }
    ((*string)++);
    while (**string != '\"') {
        if (**string == '\0') {
            return JSONFailure;
        } else if (**string == '\\') {
            ((*string)++);
            if (**string == '\0') {
                return JSONFailure;
            }
        }
        ((*string)++);
    }
    ((*string)++);
    return JSONSuccess;
}

static JSON_Status parse_utf16(const char **unprocessed, char **processed) {
    unsigned int cp, lead, trail;
    char *processed_ptr = *processed;
    const char *unprocessed_ptr = *unprocessed;
    JSON_Status status = JSONFailure;
    unprocessed_ptr++;
    status = parse_utf16_hex(unprocessed_ptr, &cp);
    if (status != JSONSuccess) {
        return JSONFailure;
    }
    if (cp < 0x80) {
        processed_ptr[0] = (char)cp;
    } else if (cp < 0x800) {
        processed_ptr[0] = ((cp >> 6) & 0x1F) | 0xC0;
        processed_ptr[1] = ((cp) & 0x3F) | 0x80;
        processed_ptr += 1;
    } else if (cp < 0xD800 || cp > 0xDFFF) {
        processed_ptr[0] = ((cp >> 12) & 0x0F) | 0xE0;
        processed_ptr[1] = ((cp >> 6) & 0x3F) | 0x80;
        processed_ptr[2] = ((cp) & 0x3F) | 0x80;
        processed_ptr += 2;
    } else if (cp >= 0xD800 && cp <= 0xDBFF) {
        lead = cp;
        unprocessed_ptr += 4;
        if (*unprocessed_ptr++ != '\\' || *unprocessed_ptr++ != 'u') {
            return JSONFailure;
        }
        status = parse_utf16_hex(unprocessed_ptr, &trail);
        if (status != JSONSuccess || trail < 0xDC00 || trail > 0xDFFF) {
            return JSONFailure;
        }
        cp = ((((lead - 0xD800) & 0x3FF) << 10) | ((trail - 0xDC00) & 0x3FF)) + 0x010000;
        processed_ptr[0] = (((cp >> 18) & 0x07) | 0xF0);
        processed_ptr[1] = (((cp >> 12) & 0x3F) | 0x80);
        processed_ptr[2] = (((cp >> 6) & 0x3F) | 0x80);
        processed_ptr[3] = (((cp) & 0x3F) | 0x80);
        processed_ptr += 3;
    } else {
        return JSONFailure;
    }
    unprocessed_ptr += 3;
    *processed = processed_ptr;
    *unprocessed = unprocessed_ptr;
    return JSONSuccess;
}




static char* process_string(const char *input, size_t input_len, size_t *output_len) {
    const char *input_ptr = input;
    size_t initial_size = (input_len + 1) * sizeof(char);
    size_t final_size = 0;
    char *output = 
# 786 "edit_parson.c" 3 4
                  ((void *)0)
# 786 "edit_parson.c"
                      , *output_ptr = 
# 786 "edit_parson.c" 3 4
                                      ((void *)0)
# 786 "edit_parson.c"
                                          , *resized_output = 
# 786 "edit_parson.c" 3 4
                                                              ((void *)0)
# 786 "edit_parson.c"
                                                                  ;
    output = (char*)parson_malloc(initial_size);
    if (output == 
# 788 "edit_parson.c" 3 4
                 ((void *)0)
# 788 "edit_parson.c"
                     ) {
        goto error;
    }
    output_ptr = output;
    while ((*input_ptr != '\0') && (size_t)(input_ptr - input) < input_len) {
        if (*input_ptr == '\\') {
            input_ptr++;
            switch (*input_ptr) {
                case '\"': *output_ptr = '\"'; break;
                case '\\': *output_ptr = '\\'; break;
                case '/': *output_ptr = '/'; break;
                case 'b': *output_ptr = '\b'; break;
                case 'f': *output_ptr = '\f'; break;
                case 'n': *output_ptr = '\n'; break;
                case 'r': *output_ptr = '\r'; break;
                case 't': *output_ptr = '\t'; break;
                case 'u':
                    if (parse_utf16(&input_ptr, &output_ptr) != JSONSuccess) {
                        goto error;
                    }
                    break;
                default:
                    goto error;
            }
        } else if ((unsigned char)*input_ptr < 0x20) {
            goto error;
        } else {
            *output_ptr = *input_ptr;
        }
        output_ptr++;
        input_ptr++;
    }
    *output_ptr = '\0';

    final_size = (size_t)(output_ptr-output) + 1;

    resized_output = (char*)parson_malloc(final_size);
    if (resized_output == 
# 825 "edit_parson.c" 3 4
                         ((void *)0)
# 825 "edit_parson.c"
                             ) {
        goto error;
    }
    memcpy(resized_output, output, final_size);
    *output_len = final_size - 1;
    parson_free(output);
    return resized_output;
error:
    parson_free(output);
    return 
# 834 "edit_parson.c" 3 4
          ((void *)0)
# 834 "edit_parson.c"
              ;
}



static char * get_quoted_string(const char **string, size_t *output_string_len) {
    const char *string_start = *string;
    size_t input_string_len = 0;
    JSON_Status status = skip_quotes(string);
    if (status != JSONSuccess) {
        return 
# 844 "edit_parson.c" 3 4
              ((void *)0)
# 844 "edit_parson.c"
                  ;
    }
    input_string_len = *string - string_start - 2;
    return process_string(string_start + 1, input_string_len, output_string_len);
}

static JSON_Value * parse_value(const char **string, size_t nesting) {
    if (nesting > 2048) {
        return 
# 852 "edit_parson.c" 3 4
              ((void *)0)
# 852 "edit_parson.c"
                  ;
    }
    while (__is(unsigned char)(**string)type(((unsigned char)(**string)), _ISspa(unsigned char)(**string)e)) { ((*string)++); };
    switch (**string) {
        case '{':
            return parse_object_value(string, nesting + 1);
        case '[':
            return parse_array_value(string, nesting + 1);
        case '\"':
            return parse_string_value(string);
        case 'f': case 't':
            return parse_boolean_value(string);
        case '-':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            return parse_number_value(string);
        case 'n':
            return parse_null_value(string);
        default:
            return 
# 871 "edit_parson.c" 3 4
                  ((void *)0)
# 871 "edit_parson.c"
                      ;
    }
}

static JSON_Value * parse_object_value(const char **string, size_t nesting) {
    JSON_Status status = JSONFailure;
    JSON_Value *output_value = 
# 877 "edit_parson.c" 3 4
                              ((void *)0)
# 877 "edit_parson.c"
                                  , *new_value = 
# 877 "edit_parson.c" 3 4
                                                 ((void *)0)
# 877 "edit_parson.c"
                                                     ;
    JSON_Object *output_object = 
# 878 "edit_parson.c" 3 4
                                ((void *)0)
# 878 "edit_parson.c"
                                    ;
    char *new_key = 
# 879 "edit_parson.c" 3 4
                   ((void *)0)
# 879 "edit_parson.c"
                       ;

    output_value = json_value_init_object();
    if (output_value == 
# 882 "edit_parson.c" 3 4
                       ((void *)0)
# 882 "edit_parson.c"
                           ) {
        return 
# 883 "edit_parson.c" 3 4
              ((void *)0)
# 883 "edit_parson.c"
                  ;
    }
    if (**string != '{') {
        json_value_free(output_value);
        return 
# 887 "edit_parson.c" 3 4
              ((void *)0)
# 887 "edit_parson.c"
                  ;
    }
    output_object = json_value_get_object(output_value);
    ((*string)++);
    while (__is(unsigned char)(**string)type(((unsigned char)(**string)), _ISspa(unsigned char)(**string)e)) { ((*string)++); };
    if (**string == '}') {
        ((*string)++);
        return output_value;
    }
    while (**string != '\0') {
        size_t key_len = 0;
        new_key = get_quoted_string(string, &key_len);

        if (!new_key) {
            json_value_free(output_value);
            return 
# 902 "edit_parson.c" 3 4
                  ((void *)0)
# 902 "edit_parson.c"
                      ;
        }
        if (key_len != strlen(new_key)) {
            parson_free(new_key);
            json_value_free(output_value);
            return 
# 907 "edit_parson.c" 3 4
                  ((void *)0)
# 907 "edit_parson.c"
                      ;
        }
        while (__is(unsigned char)(**string)type(((unsigned char)(**string)), _ISspa(unsigned char)(**string)e)) { ((*string)++); };
        if (**string != ':') {
            parson_free(new_key);
            json_value_free(output_value);
            return 
# 913 "edit_parson.c" 3 4
                  ((void *)0)
# 913 "edit_parson.c"
                      ;
        }
        ((*string)++);
        new_value = parse_value(string, nesting);
        if (new_value == 
# 917 "edit_parson.c" 3 4
                        ((void *)0)
# 917 "edit_parson.c"
                            ) {
            parson_free(new_key);
            json_value_free(output_value);
            return 
# 920 "edit_parson.c" 3 4
                  ((void *)0)
# 920 "edit_parson.c"
                      ;
        }
        status = json_object_add(output_object, new_key, new_value);
        if (status != JSONSuccess) {
            parson_free(new_key);
            json_value_free(new_value);
            json_value_free(output_value);
            return 
# 927 "edit_parson.c" 3 4
                  ((void *)0)
# 927 "edit_parson.c"
                      ;
        }
        while (__is(unsigned char)(**string)type(((unsigned char)(**string)), _ISspa(unsigned char)(**string)e)) { ((*string)++); };
        if (**string != ',') {
            break;
        }
        ((*string)++);
        while (__is(unsigned char)(**string)type(((unsigned char)(**string)), _ISspa(unsigned char)(**string)e)) { ((*string)++); };
        if (**string == '}') {
            break;
        }
    }
    while (__is(unsigned char)(**string)type(((unsigned char)(**string)), _ISspa(unsigned char)(**string)e)) { ((*string)++); };
    if (**string != '}') {
        json_value_free(output_value);
        return 
# 942 "edit_parson.c" 3 4
              ((void *)0)
# 942 "edit_parson.c"
                  ;
    }
    ((*string)++);
    return output_value;
}

static JSON_Value * parse_array_value(const char **string, size_t nesting) {
    JSON_Value *output_value = 
# 949 "edit_parson.c" 3 4
                              ((void *)0)
# 949 "edit_parson.c"
                                  , *new_array_value = 
# 949 "edit_parson.c" 3 4
                                                       ((void *)0)
# 949 "edit_parson.c"
                                                           ;
    JSON_Array *output_array = 
# 950 "edit_parson.c" 3 4
                              ((void *)0)
# 950 "edit_parson.c"
                                  ;
    output_value = json_value_init_array();
    if (output_value == 
# 952 "edit_parson.c" 3 4
                       ((void *)0)
# 952 "edit_parson.c"
                           ) {
        return 
# 953 "edit_parson.c" 3 4
              ((void *)0)
# 953 "edit_parson.c"
                  ;
    }
    if (**string != '[') {
        json_value_free(output_value);
        return 
# 957 "edit_parson.c" 3 4
              ((void *)0)
# 957 "edit_parson.c"
                  ;
    }
    output_array = json_value_get_array(output_value);
    ((*string)++);
    while (__is(unsigned char)(**string)type(((unsigned char)(**string)), _ISspa(unsigned char)(**string)e)) { ((*string)++); };
    if (**string == ']') {
        ((*string)++);
        return output_value;
    }
    while (**string != '\0') {
        new_array_value = parse_value(string, nesting);
        if (new_array_value == 
# 968 "edit_parson.c" 3 4
                              ((void *)0)
# 968 "edit_parson.c"
                                  ) {
            json_value_free(output_value);
            return 
# 970 "edit_parson.c" 3 4
                  ((void *)0)
# 970 "edit_parson.c"
                      ;
        }
        if (json_array_add(output_array, new_array_value) != JSONSuccess) {
            json_value_free(new_array_value);
            json_value_free(output_value);
            return 
# 975 "edit_parson.c" 3 4
                  ((void *)0)
# 975 "edit_parson.c"
                      ;
        }
        while (__is(unsigned char)(**string)type(((unsigned char)(**string)), _ISspa(unsigned char)(**string)e)) { ((*string)++); };
        if (**string != ',') {
            break;
        }
        ((*string)++);
        while (__is(unsigned char)(**string)type(((unsigned char)(**string)), _ISspa(unsigned char)(**string)e)) { ((*string)++); };
        if (**string == ']') {
            break;
        }
    }
    while (__is(unsigned char)(**string)type(((unsigned char)(**string)), _ISspa(unsigned char)(**string)e)) { ((*string)++); };
    if (**string != ']' ||
        json_array_resize(output_array, json_array_get_count(output_array)) != JSONSuccess) {
            json_value_free(output_value);
            return 
# 991 "edit_parson.c" 3 4
                  ((void *)0)
# 991 "edit_parson.c"
                      ;
    }
    ((*string)++);
    return output_value;
}

static JSON_Value * parse_string_value(const char **string) {
    JSON_Value *value = 
# 998 "edit_parson.c" 3 4
                       ((void *)0)
# 998 "edit_parson.c"
                           ;
    size_t new_string_len = 0;
    char *new_string = get_quoted_string(string, &new_string_len);
    if (new_string == 
# 1001 "edit_parson.c" 3 4
                     ((void *)0)
# 1001 "edit_parson.c"
                         ) {
        return 
# 1002 "edit_parson.c" 3 4
              ((void *)0)
# 1002 "edit_parson.c"
                  ;
    }
    value = json_value_init_string_no_copy(new_string, new_string_len);
    if (value == 
# 1005 "edit_parson.c" 3 4
                ((void *)0)
# 1005 "edit_parson.c"
                    ) {
        parson_free(new_string);
        return 
# 1007 "edit_parson.c" 3 4
              ((void *)0)
# 1007 "edit_parson.c"
                  ;
    }
    return value;
}

static JSON_Value * parse_boolean_value(const char **string) {
    size_t true_token_size = (sizeof("true") - 1);
    size_t false_token_size = (sizeof("false") - 1);
    if (strncmp("true", *string, true_token_size) == 0) {
        *string += true_token_size;
        return json_value_init_boolean(1);
    } else if (strncmp("false", *string, false_token_size) == 0) {
        *string += false_token_size;
        return json_value_init_boolean(0);
    }
    return 
# 1022 "edit_parson.c" 3 4
          ((void *)0)
# 1022 "edit_parson.c"
              ;
}

static JSON_Value * parse_number_value(const char **string) {
    char *end;
    double number = 0;
    (*__errno_location ()) = 0;
    number = strtod(*string, &end);
    if ((*__errno_location ()) == 34 && (number <= -
# 1030 "edit_parson.c" 3 4
                                                   (__builtin_huge_val ()) 
# 1030 "edit_parson.c"
                                                            || number >= 
# 1030 "edit_parson.c" 3 4
                                                                         (__builtin_huge_val ())
# 1030 "edit_parson.c"
                                                                                 )) {
        return 
# 1031 "edit_parson.c" 3 4
              ((void *)0)
# 1031 "edit_parson.c"
                  ;
    }
    if (((*__errno_location ()) && 
# 1033 "edit_parson.c" 3 4
                                  (*__errno_location ()) 
# 1033 "edit_parson.c"
                                        != 34) || !is_decimal(*string, end - *string)) {
        return 
# 1034 "edit_parson.c" 3 4
              ((void *)0)
# 1034 "edit_parson.c"
                  ;
    }
    *string = end;
    return json_value_init_number(number);
}

static JSON_Value * parse_null_value(const char **string) {
    size_t token_size = (sizeof("null") - 1);
    if (strncmp("null", *string, token_size) == 0) {
        *string += token_size;
        return json_value_init_null();
    }
    return 
# 1046 "edit_parson.c" 3 4
          ((void *)0)
# 1046 "edit_parson.c"
              ;
}
# 1057 "edit_parson.c"
static int json_serialize_to_buffer_r(const JSON_Value *value, char *buf, int level, parson_bool_t is_pretty, char *num_buf)
{
    const char *key = 
# 1059 "edit_parson.c" 3 4
                     ((void *)0)
# 1059 "edit_parson.c"
                         , *string = 
# 1059 "edit_parson.c" 3 4
                                     ((void *)0)
# 1059 "edit_parson.c"
                                         ;
    JSON_Value *temp_value = 
# 1060 "edit_parson.c" 3 4
                            ((void *)0)
# 1060 "edit_parson.c"
                                ;
    JSON_Array *array = 
# 1061 "edit_parson.c" 3 4
                       ((void *)0)
# 1061 "edit_parson.c"
                           ;
    JSON_Object *object = 
# 1062 "edit_parson.c" 3 4
                         ((void *)0)
# 1062 "edit_parson.c"
                             ;
    size_t i = 0, count = 0;
    double num = 0.0;
    int written = -1, written_total = 0;
    size_t len = 0;

    switch (json_value_get_type(value)) {
        case JSONArray:
            array = json_value_get_array(value);
            count = json_array_get_count(array);
            do { written = (sizeof(("[")) - 1); if (buf != 
# 1072 "edit_parson.c" 3 4
                                                                                                                        ((void *)0)
# 1072 "edit_parson.c"
                                                                                                                            ) { memcpy(buf, ("["), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0);
            if (count > 0 && is_pretty) {
                do { written = (sizeof(("\n")) - 1); if (buf != 
# 1074 "edit_parson.c" 3 4
                                                                                                                             ((void *)0)
# 1074 "edit_parson.c"
                                                                                                                                 ) { memcpy(buf, ("\n"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0);
            }
            for (i = 0; i < count; i++) {
                if (is_pretty) {
                    do { int level+1_i = 0; for (level+1_i = 0; level+1_i < (level+1); level+1_i++) { do { written = (sizeof(("    ")) - 1); if (buf != 
# 1078 "edit_parson.c" 3 4
                                                                                                                                                                                                                                                                                                                      ((void *)0)
# 1078 "edit_parson.c"
                                                                                                                                                                                                                                                                                                                          ) { memcpy(buf, ("    "), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); } } while (0);
                }
                temp_value = json_array_get_value(array, i);
                written = json_serialize_to_buffer_r(temp_value, buf, level+1, is_pretty, num_buf);
                if (written < 0) {
                    return -1;
                }
                if (buf != 
# 1085 "edit_parson.c" 3 4
                          ((void *)0)
# 1085 "edit_parson.c"
                              ) {
                    buf += written;
                }
                written_total += written;
                if (i < (count - 1)) {
                    do { written = (sizeof((",")) - 1); if (buf != 
# 1090 "edit_parson.c" 3 4
                                                                                                                                ((void *)0)
# 1090 "edit_parson.c"
                                                                                                                                    ) { memcpy(buf, (","), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0);
                }
                if (is_pretty) {
                    do { written = (sizeof(("\n")) - 1); if (buf != 
# 1093 "edit_parson.c" 3 4
                                                                                                                                 ((void *)0)
# 1093 "edit_parson.c"
                                                                                                                                     ) { memcpy(buf, ("\n"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0);
                }
            }
            if (count > 0 && is_pretty) {
                do { int level_i = 0; for (level_i = 0; level_i < (level); level_i++) { do { written = (sizeof(("    ")) - 1); if (buf != 
# 1097 "edit_parson.c" 3 4
                                                                                                                                                                                                                                                                                                        ((void *)0)
# 1097 "edit_parson.c"
                                                                                                                                                                                                                                                                                                            ) { memcpy(buf, ("    "), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); } } while (0);
            }
            do { written = (sizeof(("]")) - 1); if (buf != 
# 1099 "edit_parson.c" 3 4
                                                                                                                        ((void *)0)
# 1099 "edit_parson.c"
                                                                                                                            ) { memcpy(buf, ("]"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0);
            return written_total;
        case JSONObject:
            object = json_value_get_object(value);
            count = json_object_get_count(object);
            do { written = (sizeof(("{")) - 1); if (buf != 
# 1104 "edit_parson.c" 3 4
                                                                                                                        ((void *)0)
# 1104 "edit_parson.c"
                                                                                                                            ) { memcpy(buf, ("{"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0);
            if (count > 0 && is_pretty) {
                do { written = (sizeof(("\n")) - 1); if (buf != 
# 1106 "edit_parson.c" 3 4
                                                                                                                             ((void *)0)
# 1106 "edit_parson.c"
                                                                                                                                 ) { memcpy(buf, ("\n"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0);
            }
            for (i = 0; i < count; i++) {
                key = json_object_get_name(object, i);
                if (key == 
# 1110 "edit_parson.c" 3 4
                          ((void *)0)
# 1110 "edit_parson.c"
                              ) {
                    return -1;
                }
                if (is_pretty) {
                    do { int level+1_i = 0; for (level+1_i = 0; level+1_i < (level+1); level+1_i++) { do { written = (sizeof(("    ")) - 1); if (buf != 
# 1114 "edit_parson.c" 3 4
                                                                                                                                                                                                                                                                                                                      ((void *)0)
# 1114 "edit_parson.c"
                                                                                                                                                                                                                                                                                                                          ) { memcpy(buf, ("    "), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); } } while (0);
                }

                written = json_serialize_string(key, strlen(key), buf);
                if (written < 0) {
                    return -1;
                }
                if (buf != 
# 1121 "edit_parson.c" 3 4
                          ((void *)0)
# 1121 "edit_parson.c"
                              ) {
                    buf += written;
                }
                written_total += written;
                do { written = (sizeof((":")) - 1); if (buf != 
# 1125 "edit_parson.c" 3 4
                                                                                                                            ((void *)0)
# 1125 "edit_parson.c"
                                                                                                                                ) { memcpy(buf, (":"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0);
                if (is_pretty) {
                    do { written = (sizeof((" ")) - 1); if (buf != 
# 1127 "edit_parson.c" 3 4
                                                                                                                                ((void *)0)
# 1127 "edit_parson.c"
                                                                                                                                    ) { memcpy(buf, (" "), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0);
                }
                temp_value = json_object_get_value_at(object, i);
                written = json_serialize_to_buffer_r(temp_value, buf, level+1, is_pretty, num_buf);
                if (written < 0) {
                    return -1;
                }
                if (buf != 
# 1134 "edit_parson.c" 3 4
                          ((void *)0)
# 1134 "edit_parson.c"
                              ) {
                    buf += written;
                }
                written_total += written;
                if (i < (count - 1)) {
                    do { written = (sizeof((",")) - 1); if (buf != 
# 1139 "edit_parson.c" 3 4
                                                                                                                                ((void *)0)
# 1139 "edit_parson.c"
                                                                                                                                    ) { memcpy(buf, (","), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0);
                }
                if (is_pretty) {
                    do { written = (sizeof(("\n")) - 1); if (buf != 
# 1142 "edit_parson.c" 3 4
                                                                                                                                 ((void *)0)
# 1142 "edit_parson.c"
                                                                                                                                     ) { memcpy(buf, ("\n"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0);
                }
            }
            if (count > 0 && is_pretty) {
                do { int level_i = 0; for (level_i = 0; level_i < (level); level_i++) { do { written = (sizeof(("    ")) - 1); if (buf != 
# 1146 "edit_parson.c" 3 4
                                                                                                                                                                                                                                                                                                        ((void *)0)
# 1146 "edit_parson.c"
                                                                                                                                                                                                                                                                                                            ) { memcpy(buf, ("    "), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); } } while (0);
            }
            do { written = (sizeof(("}")) - 1); if (buf != 
# 1148 "edit_parson.c" 3 4
                                                                                                                        ((void *)0)
# 1148 "edit_parson.c"
                                                                                                                            ) { memcpy(buf, ("}"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0);
            return written_total;
        case JSONString:
            string = json_value_get_string(value);
            if (string == 
# 1152 "edit_parson.c" 3 4
                         ((void *)0)
# 1152 "edit_parson.c"
                             ) {
                return -1;
            }
            len = json_value_get_string_len(value);
            written = json_serialize_string(string, len, buf);
            if (written < 0) {
                return -1;
            }
            if (buf != 
# 1160 "edit_parson.c" 3 4
                      ((void *)0)
# 1160 "edit_parson.c"
                          ) {
                buf += written;
            }
            written_total += written;
            return written_total;
        case JSONBoolean:
            if (json_value_get_boolean(value)) {
                do { written = (sizeof(("true")) - 1); if (buf != 
# 1167 "edit_parson.c" 3 4
                                                                                                                               ((void *)0)
# 1167 "edit_parson.c"
                                                                                                                                   ) { memcpy(buf, ("true"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0);
            } else {
                do { written = (sizeof(("false")) - 1); if (buf != 
# 1169 "edit_parson.c" 3 4
                                                                                                                                ((void *)0)
# 1169 "edit_parson.c"
                                                                                                                                    ) { memcpy(buf, ("false"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0);
            }
            return written_total;
        case JSONNumber:
            num = json_value_get_number(value);
            if (buf != 
# 1174 "edit_parson.c" 3 4
                      ((void *)0)
# 1174 "edit_parson.c"
                          ) {
                num_buf = buf;
            }
            if (parson_number_serialization_function) {
                written = parson_number_serialization_function(num, num_buf);
            } else if (parson_float_format) {
                written = sprintf(num_buf, parson_float_format, num);
            } else {
                written = sprintf(num_buf, "%1.17g", num);
            }
            if (written < 0) {
                return -1;
            }
            if (buf != 
# 1187 "edit_parson.c" 3 4
                      ((void *)0)
# 1187 "edit_parson.c"
                          ) {
                buf += written;
            }
            written_total += written;
            return written_total;
        case JSONNull:
            do { written = (sizeof(("null")) - 1); if (buf != 
# 1193 "edit_parson.c" 3 4
                                                                                                                           ((void *)0)
# 1193 "edit_parson.c"
                                                                                                                               ) { memcpy(buf, ("null"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0);
            return written_total;
        case JSONError:
            return -1;
        default:
            return -1;
    }
}

static int json_serialize_string(const char *string, size_t len, char *buf) {
    size_t i = 0;
    char c = '\0';
    int written = -1, written_total = 0;
    do { written = (sizeof(("\"")) - 1); if (buf != 
# 1206 "edit_parson.c" 3 4
                                                                                                                 ((void *)0)
# 1206 "edit_parson.c"
                                                                                                                     ) { memcpy(buf, ("\""), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0);
    for (i = 0; i < len; i++) {
        c = string[i];
        switch (c) {
            case '\"': do { written = (sizeof(("\\\"")) - 1); if (buf != 
# 1210 "edit_parson.c" 3 4
                                                                                                                                      ((void *)0)
# 1210 "edit_parson.c"
                                                                                                                                          ) { memcpy(buf, ("\\\""), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\\': do { written = (sizeof(("\\\\")) - 1); if (buf != 
# 1211 "edit_parson.c" 3 4
                                                                                                                                      ((void *)0)
# 1211 "edit_parson.c"
                                                                                                                                          ) { memcpy(buf, ("\\\\"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\b': do { written = (sizeof(("\\b")) - 1); if (buf != 
# 1212 "edit_parson.c" 3 4
                                                                                                                                     ((void *)0)
# 1212 "edit_parson.c"
                                                                                                                                         ) { memcpy(buf, ("\\b"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\f': do { written = (sizeof(("\\f")) - 1); if (buf != 
# 1213 "edit_parson.c" 3 4
                                                                                                                                     ((void *)0)
# 1213 "edit_parson.c"
                                                                                                                                         ) { memcpy(buf, ("\\f"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\n': do { written = (sizeof(("\\n")) - 1); if (buf != 
# 1214 "edit_parson.c" 3 4
                                                                                                                                     ((void *)0)
# 1214 "edit_parson.c"
                                                                                                                                         ) { memcpy(buf, ("\\n"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\r': do { written = (sizeof(("\\r")) - 1); if (buf != 
# 1215 "edit_parson.c" 3 4
                                                                                                                                     ((void *)0)
# 1215 "edit_parson.c"
                                                                                                                                         ) { memcpy(buf, ("\\r"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\t': do { written = (sizeof(("\\t")) - 1); if (buf != 
# 1216 "edit_parson.c" 3 4
                                                                                                                                     ((void *)0)
# 1216 "edit_parson.c"
                                                                                                                                         ) { memcpy(buf, ("\\t"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x00': do { written = (sizeof(("\\u0000")) - 1); if (buf != 
# 1217 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1217 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u0000"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x01': do { written = (sizeof(("\\u0001")) - 1); if (buf != 
# 1218 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1218 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u0001"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x02': do { written = (sizeof(("\\u0002")) - 1); if (buf != 
# 1219 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1219 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u0002"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x03': do { written = (sizeof(("\\u0003")) - 1); if (buf != 
# 1220 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1220 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u0003"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x04': do { written = (sizeof(("\\u0004")) - 1); if (buf != 
# 1221 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1221 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u0004"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x05': do { written = (sizeof(("\\u0005")) - 1); if (buf != 
# 1222 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1222 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u0005"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x06': do { written = (sizeof(("\\u0006")) - 1); if (buf != 
# 1223 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1223 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u0006"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x07': do { written = (sizeof(("\\u0007")) - 1); if (buf != 
# 1224 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1224 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u0007"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;



            case '\x0b': do { written = (sizeof(("\\u000b")) - 1); if (buf != 
# 1228 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1228 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u000b"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;


            case '\x0e': do { written = (sizeof(("\\u000e")) - 1); if (buf != 
# 1231 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1231 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u000e"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x0f': do { written = (sizeof(("\\u000f")) - 1); if (buf != 
# 1232 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1232 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u000f"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x10': do { written = (sizeof(("\\u0010")) - 1); if (buf != 
# 1233 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1233 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u0010"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x11': do { written = (sizeof(("\\u0011")) - 1); if (buf != 
# 1234 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1234 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u0011"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x12': do { written = (sizeof(("\\u0012")) - 1); if (buf != 
# 1235 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1235 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u0012"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x13': do { written = (sizeof(("\\u0013")) - 1); if (buf != 
# 1236 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1236 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u0013"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x14': do { written = (sizeof(("\\u0014")) - 1); if (buf != 
# 1237 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1237 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u0014"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x15': do { written = (sizeof(("\\u0015")) - 1); if (buf != 
# 1238 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1238 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u0015"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x16': do { written = (sizeof(("\\u0016")) - 1); if (buf != 
# 1239 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1239 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u0016"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x17': do { written = (sizeof(("\\u0017")) - 1); if (buf != 
# 1240 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1240 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u0017"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x18': do { written = (sizeof(("\\u0018")) - 1); if (buf != 
# 1241 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1241 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u0018"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x19': do { written = (sizeof(("\\u0019")) - 1); if (buf != 
# 1242 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1242 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u0019"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x1a': do { written = (sizeof(("\\u001a")) - 1); if (buf != 
# 1243 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1243 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u001a"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x1b': do { written = (sizeof(("\\u001b")) - 1); if (buf != 
# 1244 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1244 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u001b"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x1c': do { written = (sizeof(("\\u001c")) - 1); if (buf != 
# 1245 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1245 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u001c"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x1d': do { written = (sizeof(("\\u001d")) - 1); if (buf != 
# 1246 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1246 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u001d"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x1e': do { written = (sizeof(("\\u001e")) - 1); if (buf != 
# 1247 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1247 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u001e"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '\x1f': do { written = (sizeof(("\\u001f")) - 1); if (buf != 
# 1248 "edit_parson.c" 3 4
                                                                                                                                           ((void *)0)
# 1248 "edit_parson.c"
                                                                                                                                               ) { memcpy(buf, ("\\u001f"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0); break;
            case '/':
                if (parson_escape_slashes) {
                    do { written = (sizeof(("\\/")) - 1); if (buf != 
# 1251 "edit_parson.c" 3 4
                                                                                                                                  ((void *)0)
# 1251 "edit_parson.c"
                                                                                                                                      ) { memcpy(buf, ("\\/"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0);
                } else {
                    do { written = (sizeof(("/")) - 1); if (buf != 
# 1253 "edit_parson.c" 3 4
                                                                                                                                ((void *)0)
# 1253 "edit_parson.c"
                                                                                                                                    ) { memcpy(buf, ("/"), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0);
                }
                break;
            default:
                if (buf != 
# 1257 "edit_parson.c" 3 4
                          ((void *)0)
# 1257 "edit_parson.c"
                              ) {
                    buf[0] = c;
                    buf += 1;
                }
                written_total += 1;
                break;
        }
    }
    do { written = (sizeof(("\"")) - 1); if (buf != 
# 1265 "edit_parson.c" 3 4
                                                                                                                 ((void *)0)
# 1265 "edit_parson.c"
                                                                                                                     ) { memcpy(buf, ("\""), written); buf[written] = '\0'; buf += written; } written_total += written; } while (0);
    return written_total;
}



JSON_Value * json_parse_file(const char *filename) {
    char *file_contents = read_file(filename);
    JSON_Value *output_value = 
# 1273 "edit_parson.c" 3 4
                              ((void *)0)
# 1273 "edit_parson.c"
                                  ;
    if (file_contents == 
# 1274 "edit_parson.c" 3 4
                        ((void *)0)
# 1274 "edit_parson.c"
                            ) {
        return 
# 1275 "edit_parson.c" 3 4
              ((void *)0)
# 1275 "edit_parson.c"
                  ;
    }
    output_value = json_parse_string(file_contents);
    parson_free(file_contents);
    return output_value;
}

JSON_Value * json_parse_file_with_comments(const char *filename) {
    char *file_contents = read_file(filename);
    JSON_Value *output_value = 
# 1284 "edit_parson.c" 3 4
                              ((void *)0)
# 1284 "edit_parson.c"
                                  ;
    if (file_contents == 
# 1285 "edit_parson.c" 3 4
                        ((void *)0)
# 1285 "edit_parson.c"
                            ) {
        return 
# 1286 "edit_parson.c" 3 4
              ((void *)0)
# 1286 "edit_parson.c"
                  ;
    }
    output_value = json_parse_string_with_comments(file_contents);
    parson_free(file_contents);
    return output_value;
}

JSON_Value * json_parse_string(const char *string) {
    if (string == 
# 1294 "edit_parson.c" 3 4
                 ((void *)0)
# 1294 "edit_parson.c"
                     ) {
        return 
# 1295 "edit_parson.c" 3 4
              ((void *)0)
# 1295 "edit_parson.c"
                  ;
    }
    if (string[0] == '\xEF' && string[1] == '\xBB' && string[2] == '\xBF') {
        string = string + 3;
    }
    return parse_value((const char**)&string, 0);
}

JSON_Value * json_parse_string_with_comments(const char *string) {
    JSON_Value *result = 
# 1304 "edit_parson.c" 3 4
                        ((void *)0)
# 1304 "edit_parson.c"
                            ;
    char *string_mutable_copy = 
# 1305 "edit_parson.c" 3 4
                               ((void *)0)
# 1305 "edit_parson.c"
                                   , *string_mutable_copy_ptr = 
# 1305 "edit_parson.c" 3 4
                                                                ((void *)0)
# 1305 "edit_parson.c"
                                                                    ;
    string_mutable_copy = parson_strdup(string);
    if (string_mutable_copy == 
# 1307 "edit_parson.c" 3 4
                              ((void *)0)
# 1307 "edit_parson.c"
                                  ) {
        return 
# 1308 "edit_parson.c" 3 4
              ((void *)0)
# 1308 "edit_parson.c"
                  ;
    }
    remove_comments(string_mutable_copy, "");
    remove_comments(string_mutable_copy, "//", "\n");
    string_mutable_copy_ptr = string_mutable_copy;
    result = parse_value((const char**)&string_mutable_copy_ptr, 0);
    parson_free(string_mutable_copy);
    return result;
}



JSON_Value * json_object_get_value(const JSON_Object *object, const char *name) {
    if (object == 
# 1321 "edit_parson.c" 3 4
                 ((void *)0) 
# 1321 "edit_parson.c"
                      || name == 
# 1321 "edit_parson.c" 3 4
                                 ((void *)0)
# 1321 "edit_parson.c"
                                     ) {
        return 
# 1322 "edit_parson.c" 3 4
              ((void *)0)
# 1322 "edit_parson.c"
                  ;
    }
    return json_object_getn_value(object, name, strlen(name));
}

const char * json_object_get_string(const JSON_Object *object, const char *name) {
    return json_value_get_string(json_object_get_value(object, name));
}

size_t json_object_get_string_len(const JSON_Object *object, const char *name) {
    return json_value_get_string_len(json_object_get_value(object, name));
}

double json_object_get_number(const JSON_Object *object, const char *name) {
    return json_value_get_number(json_object_get_value(object, name));
}

JSON_Object * json_object_get_object(const JSON_Object *object, const char *name) {
    return json_value_get_object(json_object_get_value(object, name));
}

JSON_Array * json_object_get_array(const JSON_Object *object, const char *name) {
    return json_value_get_array(json_object_get_value(object, name));
}

int json_object_get_boolean(const JSON_Object *object, const char *name) {
    return json_value_get_boolean(json_object_get_value(object, name));
}

JSON_Value * json_object_dotget_value(const JSON_Object *object, const char *name) {
    const char *dot_position = strchr(name, '.');
    if (!dot_position) {
        return json_object_get_value(object, name);
    }
    object = json_value_get_object(json_object_getn_value(object, name, dot_position - name));
    return json_object_dotget_value(object, dot_position + 1);
}

const char * json_object_dotget_string(const JSON_Object *object, const char *name) {
    return json_value_get_string(json_object_dotget_value(object, name));
}

size_t json_object_dotget_string_len(const JSON_Object *object, const char *name) {
    return json_value_get_string_len(json_object_dotget_value(object, name));
}

double json_object_dotget_number(const JSON_Object *object, const char *name) {
    return json_value_get_number(json_object_dotget_value(object, name));
}

JSON_Object * json_object_dotget_object(const JSON_Object *object, const char *name) {
    return json_value_get_object(json_object_dotget_value(object, name));
}

JSON_Array * json_object_dotget_array(const JSON_Object *object, const char *name) {
    return json_value_get_array(json_object_dotget_value(object, name));
}

int json_object_dotget_boolean(const JSON_Object *object, const char *name) {
    return json_value_get_boolean(json_object_dotget_value(object, name));
}

size_t json_object_get_count(const JSON_Object *object) {
    return object ? object->count : 0;
}

const char * json_object_get_name(const JSON_Object *object, size_t index) {
    if (object == 
# 1389 "edit_parson.c" 3 4
                 ((void *)0) 
# 1389 "edit_parson.c"
                      || index >= json_object_get_count(object)) {
        return 
# 1390 "edit_parson.c" 3 4
              ((void *)0)
# 1390 "edit_parson.c"
                  ;
    }
    return object->names[index];
}

JSON_Value * json_object_get_value_at(const JSON_Object *object, size_t index) {
    if (object == 
# 1396 "edit_parson.c" 3 4
                 ((void *)0) 
# 1396 "edit_parson.c"
                      || index >= json_object_get_count(object)) {
        return 
# 1397 "edit_parson.c" 3 4
              ((void *)0)
# 1397 "edit_parson.c"
                  ;
    }
    return object->values[index];
}

JSON_Value *json_object_get_wrapping_value(const JSON_Object *object) {
    if (!object) {
        return 
# 1404 "edit_parson.c" 3 4
              ((void *)0)
# 1404 "edit_parson.c"
                  ;
    }
    return object->wrapping_value;
}

int json_object_has_value (const JSON_Object *object, const char *name) {
    return json_object_get_value(object, name) != 
# 1410 "edit_parson.c" 3 4
                                                 ((void *)0)
# 1410 "edit_parson.c"
                                                     ;
}

int json_object_has_value_of_type(const JSON_Object *object, const char *name, JSON_Value_Type type) {
    JSON_Value *val = json_object_get_value(object, name);
    return val != 
# 1415 "edit_parson.c" 3 4
                 ((void *)0) 
# 1415 "edit_parson.c"
                      && json_value_get_type(val) == type;
}

int json_object_dothas_value (const JSON_Object *object, const char *name) {
    return json_object_dotget_value(object, name) != 
# 1419 "edit_parson.c" 3 4
                                                    ((void *)0)
# 1419 "edit_parson.c"
                                                        ;
}

int json_object_dothas_value_of_type(const JSON_Object *object, const char *name, JSON_Value_Type type) {
    JSON_Value *val = json_object_dotget_value(object, name);
    return val != 
# 1424 "edit_parson.c" 3 4
                 ((void *)0) 
# 1424 "edit_parson.c"
                      && json_value_get_type(val) == type;
}


JSON_Value * json_array_get_value(const JSON_Array *array, size_t index) {
    if (array == 
# 1429 "edit_parson.c" 3 4
                ((void *)0) 
# 1429 "edit_parson.c"
                     || index >= json_array_get_count(array)) {
        return 
# 1430 "edit_parson.c" 3 4
              ((void *)0)
# 1430 "edit_parson.c"
                  ;
    }
    return array->items[index];
}

const char * json_array_get_string(const JSON_Array *array, size_t index) {
    return json_value_get_string(json_array_get_value(array, index));
}

size_t json_array_get_string_len(const JSON_Array *array, size_t index) {
    return json_value_get_string_len(json_array_get_value(array, index));
}

double json_array_get_number(const JSON_Array *array, size_t index) {
    return json_value_get_number(json_array_get_value(array, index));
}

JSON_Object * json_array_get_object(const JSON_Array *array, size_t index) {
    return json_value_get_object(json_array_get_value(array, index));
}

JSON_Array * json_array_get_array(const JSON_Array *array, size_t index) {
    return json_value_get_array(json_array_get_value(array, index));
}

int json_array_get_boolean(const JSON_Array *array, size_t index) {
    return json_value_get_boolean(json_array_get_value(array, index));
}

size_t json_array_get_count(const JSON_Array *array) {
    return array ? array->count : 0;
}

JSON_Value * json_array_get_wrapping_value(const JSON_Array *array) {
    if (!array) {
        return 
# 1465 "edit_parson.c" 3 4
              ((void *)0)
# 1465 "edit_parson.c"
                  ;
    }
    return array->wrapping_value;
}


JSON_Value_Type json_value_get_type(const JSON_Value *value) {
    return value ? value->type : JSONError;
}

JSON_Object * json_value_get_object(const JSON_Value *value) {
    return json_value_get_type(value) == JSONObject ? value->value.object : 
# 1476 "edit_parson.c" 3 4
                                                                           ((void *)0)
# 1476 "edit_parson.c"
                                                                               ;
}

JSON_Array * json_value_get_array(const JSON_Value *value) {
    return json_value_get_type(value) == JSONArray ? value->value.array : 
# 1480 "edit_parson.c" 3 4
                                                                         ((void *)0)
# 1480 "edit_parson.c"
                                                                             ;
}

static const JSON_String * json_value_get_string_desc(const JSON_Value *value) {
    return json_value_get_type(value) == JSONString ? &value->value.string : 
# 1484 "edit_parson.c" 3 4
                                                                            ((void *)0)
# 1484 "edit_parson.c"
                                                                                ;
}

const char * json_value_get_string(const JSON_Value *value) {
    const JSON_String *str = json_value_get_string_desc(value);
    return str ? str->chars : 
# 1489 "edit_parson.c" 3 4
                             ((void *)0)
# 1489 "edit_parson.c"
                                 ;
}

size_t json_value_get_string_len(const JSON_Value *value) {
    const JSON_String *str = json_value_get_string_desc(value);
    return str ? str->length : 0;
}

double json_value_get_number(const JSON_Value *value) {
    return json_value_get_type(value) == JSONNumber ? value->value.number : 0;
}

int json_value_get_boolean(const JSON_Value *value) {
    return json_value_get_type(value) == JSONBoolean ? value->value.boolean : -1;
}

JSON_Value * json_value_get_parent (const JSON_Value *value) {
    return value ? value->parent : 
# 1506 "edit_parson.c" 3 4
                                  ((void *)0)
# 1506 "edit_parson.c"
                                      ;
}

void json_value_free(JSON_Value *value) {
    switch (json_value_get_type(value)) {
        case JSONObject:
            json_object_free(value->value.object);
            break;
        case JSONString:
            parson_free(value->value.string.chars);
            break;
        case JSONArray:
            json_array_free(value->value.array);
            break;
        default:
            break;
    }
    parson_free(value);
}

JSON_Value * json_value_init_object(void) {
    JSON_Value *new_value = (JSON_Value*)parson_malloc(sizeof(JSON_Value));
    if (!new_value) {
        return 
# 1529 "edit_parson.c" 3 4
              ((void *)0)
# 1529 "edit_parson.c"
                  ;
    }
    new_value->parent = 
# 1531 "edit_parson.c" 3 4
                       ((void *)0)
# 1531 "edit_parson.c"
                           ;
    new_value->type = JSONObject;
    new_value->value.object = json_object_make(new_value);
    if (!new_value->value.object) {
        parson_free(new_value);
        return 
# 1536 "edit_parson.c" 3 4
              ((void *)0)
# 1536 "edit_parson.c"
                  ;
    }
    return new_value;
}

JSON_Value * json_value_init_array(void) {
    JSON_Value *new_value = (JSON_Value*)parson_malloc(sizeof(JSON_Value));
    if (!new_value) {
        return 
# 1544 "edit_parson.c" 3 4
              ((void *)0)
# 1544 "edit_parson.c"
                  ;
    }
    new_value->parent = 
# 1546 "edit_parson.c" 3 4
                       ((void *)0)
# 1546 "edit_parson.c"
                           ;
    new_value->type = JSONArray;
    new_value->value.array = json_array_make(new_value);
    if (!new_value->value.array) {
        parson_free(new_value);
        return 
# 1551 "edit_parson.c" 3 4
              ((void *)0)
# 1551 "edit_parson.c"
                  ;
    }
    return new_value;
}

JSON_Value * json_value_init_string(const char *string) {
    if (string == 
# 1557 "edit_parson.c" 3 4
                 ((void *)0)
# 1557 "edit_parson.c"
                     ) {
        return 
# 1558 "edit_parson.c" 3 4
              ((void *)0)
# 1558 "edit_parson.c"
                  ;
    }
    return json_value_init_string_with_len(string, strlen(string));
}

JSON_Value * json_value_init_string_with_len(const char *string, size_t length) {
    char *copy = 
# 1564 "edit_parson.c" 3 4
                ((void *)0)
# 1564 "edit_parson.c"
                    ;
    JSON_Value *value;
    if (string == 
# 1566 "edit_parson.c" 3 4
                 ((void *)0)
# 1566 "edit_parson.c"
                     ) {
        return 
# 1567 "edit_parson.c" 3 4
              ((void *)0)
# 1567 "edit_parson.c"
                  ;
    }
    if (!is_valid_utf8(string, length)) {
        return 
# 1570 "edit_parson.c" 3 4
              ((void *)0)
# 1570 "edit_parson.c"
                  ;
    }
    copy = parson_strndup(string, length);
    if (copy == 
# 1573 "edit_parson.c" 3 4
               ((void *)0)
# 1573 "edit_parson.c"
                   ) {
        return 
# 1574 "edit_parson.c" 3 4
              ((void *)0)
# 1574 "edit_parson.c"
                  ;
    }
    value = json_value_init_string_no_copy(copy, length);
    if (value == 
# 1577 "edit_parson.c" 3 4
                ((void *)0)
# 1577 "edit_parson.c"
                    ) {
        parson_free(copy);
    }
    return value;
}

JSON_Value * json_value_init_number(double number) {
    JSON_Value *new_value = 
# 1584 "edit_parson.c" 3 4
                           ((void *)0)
# 1584 "edit_parson.c"
                               ;
    if ((
# 1585 "edit_parson.c" 3 4
        _Generic ((
# 1585 "edit_parson.c"
        ((number))
# 1585 "edit_parson.c" 3 4
        ), float: 
# 1585 "edit_parson.c"
        __isnanf ((number))
# 1585 "edit_parson.c" 3 4
        , _Float32: 
# 1585 "edit_parson.c"
        __isnanf ((number))
# 1585 "edit_parson.c" 3 4
        , default: 
# 1585 "edit_parson.c"
        __isnan ((number))
# 1585 "edit_parson.c" 3 4
        , long double: 
# 1585 "edit_parson.c"
        __isnanl ((number))
# 1585 "edit_parson.c" 3 4
        , _Float64x: 
# 1585 "edit_parson.c"
        __isnanl ((number))
# 1585 "edit_parson.c" 3 4
        , _Float128: 
# 1585 "edit_parson.c"
        __isnanf128 ((number))
# 1585 "edit_parson.c" 3 4
        ) 
# 1585 "edit_parson.c"
                                                    || 
# 1585 "edit_parson.c" 3 4
                                                       _Generic ((
# 1585 "edit_parson.c"
                                                       ((number))
# 1585 "edit_parson.c" 3 4
                                                       ), float: 
# 1585 "edit_parson.c"
                                                       __isinff ((number))
# 1585 "edit_parson.c" 3 4
                                                       , _Float32: 
# 1585 "edit_parson.c"
                                                       __isinff ((number))
# 1585 "edit_parson.c" 3 4
                                                       , default: 
# 1585 "edit_parson.c"
                                                       __isinf ((number))
# 1585 "edit_parson.c" 3 4
                                                       , long double: 
# 1585 "edit_parson.c"
                                                       __isinfl ((number))
# 1585 "edit_parson.c" 3 4
                                                       , _Float64x: 
# 1585 "edit_parson.c"
                                                       __isinfl ((number))
# 1585 "edit_parson.c" 3 4
                                                       , _Float128: 
# 1585 "edit_parson.c"
                                                       __isinff128 ((number))
# 1585 "edit_parson.c" 3 4
                                                       )
# 1585 "edit_parson.c"
                                                                                                  )) {
        return 
# 1586 "edit_parson.c" 3 4
              ((void *)0)
# 1586 "edit_parson.c"
                  ;
    }
    new_value = (JSON_Value*)parson_malloc(sizeof(JSON_Value));
    if (new_value == 
# 1589 "edit_parson.c" 3 4
                    ((void *)0)
# 1589 "edit_parson.c"
                        ) {
        return 
# 1590 "edit_parson.c" 3 4
              ((void *)0)
# 1590 "edit_parson.c"
                  ;
    }
    new_value->parent = 
# 1592 "edit_parson.c" 3 4
                       ((void *)0)
# 1592 "edit_parson.c"
                           ;
    new_value->type = JSONNumber;
    new_value->value.number = number;
    return new_value;
}

JSON_Value * json_value_init_boolean(int boolean) {
    JSON_Value *new_value = (JSON_Value*)parson_malloc(sizeof(JSON_Value));
    if (!new_value) {
        return 
# 1601 "edit_parson.c" 3 4
              ((void *)0)
# 1601 "edit_parson.c"
                  ;
    }
    new_value->parent = 
# 1603 "edit_parson.c" 3 4
                       ((void *)0)
# 1603 "edit_parson.c"
                           ;
    new_value->type = JSONBoolean;
    new_value->value.boolean = boolean ? 1 : 0;
    return new_value;
}

JSON_Value * json_value_init_null(void) {
    JSON_Value *new_value = (JSON_Value*)parson_malloc(sizeof(JSON_Value));
    if (!new_value) {
        return 
# 1612 "edit_parson.c" 3 4
              ((void *)0)
# 1612 "edit_parson.c"
                  ;
    }
    new_value->parent = 
# 1614 "edit_parson.c" 3 4
                       ((void *)0)
# 1614 "edit_parson.c"
                           ;
    new_value->type = JSONNull;
    return new_value;
}

JSON_Value * json_value_deep_copy(const JSON_Value *value) {
    size_t i = 0;
    JSON_Value *return_value = 
# 1621 "edit_parson.c" 3 4
                              ((void *)0)
# 1621 "edit_parson.c"
                                  , *temp_value_copy = 
# 1621 "edit_parson.c" 3 4
                                                       ((void *)0)
# 1621 "edit_parson.c"
                                                           , *temp_value = 
# 1621 "edit_parson.c" 3 4
                                                                           ((void *)0)
# 1621 "edit_parson.c"
                                                                               ;
    const JSON_String *temp_string = 
# 1622 "edit_parson.c" 3 4
                                    ((void *)0)
# 1622 "edit_parson.c"
                                        ;
    const char *temp_key = 
# 1623 "edit_parson.c" 3 4
                          ((void *)0)
# 1623 "edit_parson.c"
                              ;
    char *temp_string_copy = 
# 1624 "edit_parson.c" 3 4
                            ((void *)0)
# 1624 "edit_parson.c"
                                ;
    JSON_Array *temp_array = 
# 1625 "edit_parson.c" 3 4
                            ((void *)0)
# 1625 "edit_parson.c"
                                , *temp_array_copy = 
# 1625 "edit_parson.c" 3 4
                                                     ((void *)0)
# 1625 "edit_parson.c"
                                                         ;
    JSON_Object *temp_object = 
# 1626 "edit_parson.c" 3 4
                              ((void *)0)
# 1626 "edit_parson.c"
                                  , *temp_object_copy = 
# 1626 "edit_parson.c" 3 4
                                                        ((void *)0)
# 1626 "edit_parson.c"
                                                            ;
    JSON_Status res = JSONFailure;
    char *key_copy = 
# 1628 "edit_parson.c" 3 4
                    ((void *)0)
# 1628 "edit_parson.c"
                        ;

    switch (json_value_get_type(value)) {
        case JSONArray:
            temp_array = json_value_get_array(value);
            return_value = json_value_init_array();
            if (return_value == 
# 1634 "edit_parson.c" 3 4
                               ((void *)0)
# 1634 "edit_parson.c"
                                   ) {
                return 
# 1635 "edit_parson.c" 3 4
                      ((void *)0)
# 1635 "edit_parson.c"
                          ;
            }
            temp_array_copy = json_value_get_array(return_value);
            for (i = 0; i < json_array_get_count(temp_array); i++) {
                temp_value = json_array_get_value(temp_array, i);
                temp_value_copy = json_value_deep_copy(temp_value);
                if (temp_value_copy == 
# 1641 "edit_parson.c" 3 4
                                      ((void *)0)
# 1641 "edit_parson.c"
                                          ) {
                    json_value_free(return_value);
                    return 
# 1643 "edit_parson.c" 3 4
                          ((void *)0)
# 1643 "edit_parson.c"
                              ;
                }
                if (json_array_add(temp_array_copy, temp_value_copy) != JSONSuccess) {
                    json_value_free(return_value);
                    json_value_free(temp_value_copy);
                    return 
# 1648 "edit_parson.c" 3 4
                          ((void *)0)
# 1648 "edit_parson.c"
                              ;
                }
            }
            return return_value;
        case JSONObject:
            temp_object = json_value_get_object(value);
            return_value = json_value_init_object();
            if (!return_value) {
                return 
# 1656 "edit_parson.c" 3 4
                      ((void *)0)
# 1656 "edit_parson.c"
                          ;
            }
            temp_object_copy = json_value_get_object(return_value);
            for (i = 0; i < json_object_get_count(temp_object); i++) {
                temp_key = json_object_get_name(temp_object, i);
                temp_value = json_object_get_value(temp_object, temp_key);
                temp_value_copy = json_value_deep_copy(temp_value);
                if (!temp_value_copy) {
                    json_value_free(return_value);
                    return 
# 1665 "edit_parson.c" 3 4
                          ((void *)0)
# 1665 "edit_parson.c"
                              ;
                }
                key_copy = parson_strdup(temp_key);
                if (!key_copy) {
                    json_value_free(temp_value_copy);
                    json_value_free(return_value);
                    return 
# 1671 "edit_parson.c" 3 4
                          ((void *)0)
# 1671 "edit_parson.c"
                              ;
                }
                res = json_object_add(temp_object_copy, key_copy, temp_value_copy);
                if (res != JSONSuccess) {
                    parson_free(key_copy);
                    json_value_free(temp_value_copy);
                    json_value_free(return_value);
                    return 
# 1678 "edit_parson.c" 3 4
                          ((void *)0)
# 1678 "edit_parson.c"
                              ;
                }
            }
            return return_value;
        case JSONBoolean:
            return json_value_init_boolean(json_value_get_boolean(value));
        case JSONNumber:
            return json_value_init_number(json_value_get_number(value));
        case JSONString:
            temp_string = json_value_get_string_desc(value);
            if (temp_string == 
# 1688 "edit_parson.c" 3 4
                              ((void *)0)
# 1688 "edit_parson.c"
                                  ) {
                return 
# 1689 "edit_parson.c" 3 4
                      ((void *)0)
# 1689 "edit_parson.c"
                          ;
            }
            temp_string_copy = parson_strndup(temp_string->chars, temp_string->length);
            if (temp_string_copy == 
# 1692 "edit_parson.c" 3 4
                                   ((void *)0)
# 1692 "edit_parson.c"
                                       ) {
                return 
# 1693 "edit_parson.c" 3 4
                      ((void *)0)
# 1693 "edit_parson.c"
                          ;
            }
            return_value = json_value_init_string_no_copy(temp_string_copy, temp_string->length);
            if (return_value == 
# 1696 "edit_parson.c" 3 4
                               ((void *)0)
# 1696 "edit_parson.c"
                                   ) {
                parson_free(temp_string_copy);
            }
            return return_value;
        case JSONNull:
            return json_value_init_null();
        case JSONError:
            return 
# 1703 "edit_parson.c" 3 4
                  ((void *)0)
# 1703 "edit_parson.c"
                      ;
        default:
            return 
# 1705 "edit_parson.c" 3 4
                  ((void *)0)
# 1705 "edit_parson.c"
                      ;
    }
}

size_t json_serialization_size(const JSON_Value *value) {
    char num_buf[PARSON_NUM_BUF_SIZE];
    int res = json_serialize_to_buffer_r(value, 
# 1711 "edit_parson.c" 3 4
                                               ((void *)0)
# 1711 "edit_parson.c"
                                                   , 0, 0, num_buf);
    return res < 0 ? 0 : (size_t)(res) + 1;
}

JSON_Status json_serialize_to_buffer(const JSON_Value *value, char *buf, size_t buf_size_in_bytes) {
    int written = -1;
    size_t needed_size_in_bytes = json_serialization_size(value);
    if (needed_size_in_bytes == 0 || buf_size_in_bytes < needed_size_in_bytes) {
        return JSONFailure;
    }
    written = json_serialize_to_buffer_r(value, buf, 0, 0, 
# 1721 "edit_parson.c" 3 4
                                                          ((void *)0)
# 1721 "edit_parson.c"
                                                              );
    if (written < 0) {
        return JSONFailure;
    }
    return JSONSuccess;
}

JSON_Status json_serialize_to_file(const JSON_Value *value, const char *filename) {
    JSON_Status return_code = JSONSuccess;
    FILE *fp = 
# 1730 "edit_parson.c" 3 4
              ((void *)0)
# 1730 "edit_parson.c"
                  ;
    char *serialized_string = json_serialize_to_string(value);
    if (serialized_string == 
# 1732 "edit_parson.c" 3 4
                            ((void *)0)
# 1732 "edit_parson.c"
                                ) {
        return JSONFailure;
    }
    fp = fopen(filename, "w");
    if (fp == 
# 1736 "edit_parson.c" 3 4
             ((void *)0)
# 1736 "edit_parson.c"
                 ) {
        json_free_serialized_string(serialized_string);
        return JSONFailure;
    }
    if (fputs(serialized_string, fp) == (-1)) {
        return_code = JSONFailure;
    }
    if (fclose(fp) == (-1)) {
        return_code = JSONFailure;
    }
    json_free_serialized_string(serialized_string);
    return return_code;
}

char * json_serialize_to_string(const JSON_Value *value) {
    JSON_Status serialization_result = JSONFailure;
    size_t buf_size_bytes = json_serialization_size(value);
    char *buf = 
# 1753 "edit_parson.c" 3 4
               ((void *)0)
# 1753 "edit_parson.c"
                   ;
    if (buf_size_bytes == 0) {
        return 
# 1755 "edit_parson.c" 3 4
              ((void *)0)
# 1755 "edit_parson.c"
                  ;
    }
    buf = (char*)parson_malloc(buf_size_bytes);
    if (buf == 
# 1758 "edit_parson.c" 3 4
              ((void *)0)
# 1758 "edit_parson.c"
                  ) {
        return 
# 1759 "edit_parson.c" 3 4
              ((void *)0)
# 1759 "edit_parson.c"
                  ;
    }
    serialization_result = json_serialize_to_buffer(value, buf, buf_size_bytes);
    if (serialization_result != JSONSuccess) {
        json_free_serialized_string(buf);
        return 
# 1764 "edit_parson.c" 3 4
              ((void *)0)
# 1764 "edit_parson.c"
                  ;
    }
    return buf;
}

size_t json_serialization_size_pretty(const JSON_Value *value) {
    char num_buf[PARSON_NUM_BUF_SIZE];
    int res = json_serialize_to_buffer_r(value, 
# 1771 "edit_parson.c" 3 4
                                               ((void *)0)
# 1771 "edit_parson.c"
                                                   , 0, 1, num_buf);
    return res < 0 ? 0 : (size_t)(res) + 1;
}

JSON_Status json_serialize_to_buffer_pretty(const JSON_Value *value, char *buf, size_t buf_size_in_bytes) {
    int written = -1;
    size_t needed_size_in_bytes = json_serialization_size_pretty(value);
    if (needed_size_in_bytes == 0 || buf_size_in_bytes < needed_size_in_bytes) {
        return JSONFailure;
    }
    written = json_serialize_to_buffer_r(value, buf, 0, 1, 
# 1781 "edit_parson.c" 3 4
                                                          ((void *)0)
# 1781 "edit_parson.c"
                                                              );
    if (written < 0) {
        return JSONFailure;
    }
    return JSONSuccess;
}

JSON_Status json_serialize_to_file_pretty(const JSON_Value *value, const char *filename) {
    JSON_Status return_code = JSONSuccess;
    FILE *fp = 
# 1790 "edit_parson.c" 3 4
              ((void *)0)
# 1790 "edit_parson.c"
                  ;
    char *serialized_string = json_serialize_to_string_pretty(value);
    if (serialized_string == 
# 1792 "edit_parson.c" 3 4
                            ((void *)0)
# 1792 "edit_parson.c"
                                ) {
        return JSONFailure;
    }
    fp = fopen(filename, "w");
    if (fp == 
# 1796 "edit_parson.c" 3 4
             ((void *)0)
# 1796 "edit_parson.c"
                 ) {
        json_free_serialized_string(serialized_string);
        return JSONFailure;
    }
    if (fputs(serialized_string, fp) == (-1)) {
        return_code = JSONFailure;
    }
    if (fclose(fp) == (-1)) {
        return_code = JSONFailure;
    }
    json_free_serialized_string(serialized_string);
    return return_code;
}

char * json_serialize_to_string_pretty(const JSON_Value *value) {
    JSON_Status serialization_result = JSONFailure;
    size_t buf_size_bytes = json_serialization_size_pretty(value);
    char *buf = 
# 1813 "edit_parson.c" 3 4
               ((void *)0)
# 1813 "edit_parson.c"
                   ;
    if (buf_size_bytes == 0) {
        return 
# 1815 "edit_parson.c" 3 4
              ((void *)0)
# 1815 "edit_parson.c"
                  ;
    }
    buf = (char*)parson_malloc(buf_size_bytes);
    if (buf == 
# 1818 "edit_parson.c" 3 4
              ((void *)0)
# 1818 "edit_parson.c"
                  ) {
        return 
# 1819 "edit_parson.c" 3 4
              ((void *)0)
# 1819 "edit_parson.c"
                  ;
    }
    serialization_result = json_serialize_to_buffer_pretty(value, buf, buf_size_bytes);
    if (serialization_result != JSONSuccess) {
        json_free_serialized_string(buf);
        return 
# 1824 "edit_parson.c" 3 4
              ((void *)0)
# 1824 "edit_parson.c"
                  ;
    }
    return buf;
}

void json_free_serialized_string(char *string) {
    parson_free(string);
}

JSON_Status json_array_remove(JSON_Array *array, size_t ix) {
    size_t to_move_bytes = 0;
    if (array == 
# 1835 "edit_parson.c" 3 4
                ((void *)0) 
# 1835 "edit_parson.c"
                     || ix >= json_array_get_count(array)) {
        return JSONFailure;
    }
    json_value_free(json_array_get_value(array, ix));
    to_move_bytes = (json_array_get_count(array) - 1 - ix) * sizeof(JSON_Value*);
    memmove(array->items + ix, array->items + ix + 1, to_move_bytes);
    array->count -= 1;
    return JSONSuccess;
}

JSON_Status json_array_replace_value(JSON_Array *array, size_t ix, JSON_Value *value) {
    if (array == 
# 1846 "edit_parson.c" 3 4
                ((void *)0) 
# 1846 "edit_parson.c"
                     || value == 
# 1846 "edit_parson.c" 3 4
                                 ((void *)0) 
# 1846 "edit_parson.c"
                                      || value->parent != 
# 1846 "edit_parson.c" 3 4
                                                          ((void *)0) 
# 1846 "edit_parson.c"
                                                               || ix >= json_array_get_count(array)) {
        return JSONFailure;
    }
    json_value_free(json_array_get_value(array, ix));
    value->parent = json_array_get_wrapping_value(array);
    array->items[ix] = value;
    return JSONSuccess;
}

JSON_Status json_array_replace_string(JSON_Array *array, size_t i, const char* string) {
    JSON_Value *value = json_value_init_string(string);
    if (value == 
# 1857 "edit_parson.c" 3 4
                ((void *)0)
# 1857 "edit_parson.c"
                    ) {
        return JSONFailure;
    }
    if (json_array_replace_value(array, i, value) != JSONSuccess) {
        json_value_free(value);
        return JSONFailure;
    }
    return JSONSuccess;
}

JSON_Status json_array_replace_string_with_len(JSON_Array *array, size_t i, const char *string, size_t len) {
    JSON_Value *value = json_value_init_string_with_len(string, len);
    if (value == 
# 1869 "edit_parson.c" 3 4
                ((void *)0)
# 1869 "edit_parson.c"
                    ) {
        return JSONFailure;
    }
    if (json_array_replace_value(array, i, value) != JSONSuccess) {
        json_value_free(value);
        return JSONFailure;
    }
    return JSONSuccess;
}

JSON_Status json_array_replace_number(JSON_Array *array, size_t i, double number) {
    JSON_Value *value = json_value_init_number(number);
    if (value == 
# 1881 "edit_parson.c" 3 4
                ((void *)0)
# 1881 "edit_parson.c"
                    ) {
        return JSONFailure;
    }
    if (json_array_replace_value(array, i, value) != JSONSuccess) {
        json_value_free(value);
        return JSONFailure;
    }
    return JSONSuccess;
}

JSON_Status json_array_replace_boolean(JSON_Array *array, size_t i, int boolean) {
    JSON_Value *value = json_value_init_boolean(boolean);
    if (value == 
# 1893 "edit_parson.c" 3 4
                ((void *)0)
# 1893 "edit_parson.c"
                    ) {
        return JSONFailure;
    }
    if (json_array_replace_value(array, i, value) != JSONSuccess) {
        json_value_free(value);
        return JSONFailure;
    }
    return JSONSuccess;
}

JSON_Status json_array_replace_null(JSON_Array *array, size_t i) {
    JSON_Value *value = json_value_init_null();
    if (value == 
# 1905 "edit_parson.c" 3 4
                ((void *)0)
# 1905 "edit_parson.c"
                    ) {
        return JSONFailure;
    }
    if (json_array_replace_value(array, i, value) != JSONSuccess) {
        json_value_free(value);
        return JSONFailure;
    }
    return JSONSuccess;
}

JSON_Status json_array_clear(JSON_Array *array) {
    size_t i = 0;
    if (array == 
# 1917 "edit_parson.c" 3 4
                ((void *)0)
# 1917 "edit_parson.c"
                    ) {
        return JSONFailure;
    }
    for (i = 0; i < json_array_get_count(array); i++) {
        json_value_free(json_array_get_value(array, i));
    }
    array->count = 0;
    return JSONSuccess;
}

JSON_Status json_array_append_value(JSON_Array *array, JSON_Value *value) {
    if (array == 
# 1928 "edit_parson.c" 3 4
                ((void *)0) 
# 1928 "edit_parson.c"
                     || value == 
# 1928 "edit_parson.c" 3 4
                                 ((void *)0) 
# 1928 "edit_parson.c"
                                      || value->parent != 
# 1928 "edit_parson.c" 3 4
                                                          ((void *)0)
# 1928 "edit_parson.c"
                                                              ) {
        return JSONFailure;
    }
    return json_array_add(array, value);
}

JSON_Status json_array_append_string(JSON_Array *array, const char *string) {
    JSON_Value *value = json_value_init_string(string);
    if (value == 
# 1936 "edit_parson.c" 3 4
                ((void *)0)
# 1936 "edit_parson.c"
                    ) {
        return JSONFailure;
    }
    if (json_array_append_value(array, value) != JSONSuccess) {
        json_value_free(value);
        return JSONFailure;
    }
    return JSONSuccess;
}

JSON_Status json_array_append_string_with_len(JSON_Array *array, const char *string, size_t len) {
    JSON_Value *value = json_value_init_string_with_len(string, len);
    if (value == 
# 1948 "edit_parson.c" 3 4
                ((void *)0)
# 1948 "edit_parson.c"
                    ) {
        return JSONFailure;
    }
    if (json_array_append_value(array, value) != JSONSuccess) {
        json_value_free(value);
        return JSONFailure;
    }
    return JSONSuccess;
}

JSON_Status json_array_append_number(JSON_Array *array, double number) {
    JSON_Value *value = json_value_init_number(number);
    if (value == 
# 1960 "edit_parson.c" 3 4
                ((void *)0)
# 1960 "edit_parson.c"
                    ) {
        return JSONFailure;
    }
    if (json_array_append_value(array, value) != JSONSuccess) {
        json_value_free(value);
        return JSONFailure;
    }
    return JSONSuccess;
}

JSON_Status json_array_append_boolean(JSON_Array *array, int boolean) {
    JSON_Value *value = json_value_init_boolean(boolean);
    if (value == 
# 1972 "edit_parson.c" 3 4
                ((void *)0)
# 1972 "edit_parson.c"
                    ) {
        return JSONFailure;
    }
    if (json_array_append_value(array, value) != JSONSuccess) {
        json_value_free(value);
        return JSONFailure;
    }
    return JSONSuccess;
}

JSON_Status json_array_append_null(JSON_Array *array) {
    JSON_Value *value = json_value_init_null();
    if (value == 
# 1984 "edit_parson.c" 3 4
                ((void *)0)
# 1984 "edit_parson.c"
                    ) {
        return JSONFailure;
    }
    if (json_array_append_value(array, value) != JSONSuccess) {
        json_value_free(value);
        return JSONFailure;
    }
    return JSONSuccess;
}

JSON_Status json_object_set_value(JSON_Object *object, const char *name, JSON_Value *value) {
    unsigned long hash = 0;
    parson_bool_t found = 0;
    size_t cell_ix = 0;
    size_t item_ix = 0;
    JSON_Value *old_value = 
# 1999 "edit_parson.c" 3 4
                           ((void *)0)
# 1999 "edit_parson.c"
                               ;
    char *key_copy = 
# 2000 "edit_parson.c" 3 4
                    ((void *)0)
# 2000 "edit_parson.c"
                        ;

    if (!object || !name || !value || value->parent) {
        return JSONFailure;
    }
    hash = hash_string(name, strlen(name));
    found = 0;
    cell_ix = json_object_get_cell_ix(object, name, strlen(name), hash, &found);
    if (found) {
        item_ix = object->cells[cell_ix];
        old_value = object->values[item_ix];
        json_value_free(old_value);
        object->values[item_ix] = value;
        value->parent = json_object_get_wrapping_value(object);
        return JSONSuccess;
    }
    if (object->count >= object->item_capacity) {
        JSON_Status res = json_object_grow_and_rehash(object);
        if (res != JSONSuccess) {
            return JSONFailure;
        }
        cell_ix = json_object_get_cell_ix(object, name, strlen(name), hash, &found);
    }
    key_copy = parson_strdup(name);
    if (!key_copy) {
        return JSONFailure;
    }
    object->names[object->count] = key_copy;
    object->cells[cell_ix] = object->count;
    object->values[object->count] = value;
    object->cell_ixs[object->count] = cell_ix;
    object->hashes[object->count] = hash;
    object->count++;
    value->parent = json_object_get_wrapping_value(object);
    return JSONSuccess;
}

JSON_Status json_object_set_string(JSON_Object *object, const char *name, const char *string) {
    JSON_Value *value = json_value_init_string(string);
    JSON_Status status = json_object_set_value(object, name, value);
    if (status != JSONSuccess) {
        json_value_free(value);
    }
    return status;
}

JSON_Status json_object_set_string_with_len(JSON_Object *object, const char *name, const char *string, size_t len) {
    JSON_Value *value = json_value_init_string_with_len(string, len);
    JSON_Status status = json_object_set_value(object, name, value);
    if (status != JSONSuccess) {
        json_value_free(value);
    }
    return status;
}

JSON_Status json_object_set_number(JSON_Object *object, const char *name, double number) {
    JSON_Value *value = json_value_init_number(number);
    JSON_Status status = json_object_set_value(object, name, value);
    if (status != JSONSuccess) {
        json_value_free(value);
    }
    return status;
}

JSON_Status json_object_set_boolean(JSON_Object *object, const char *name, int boolean) {
    JSON_Value *value = json_value_init_boolean(boolean);
    JSON_Status status = json_object_set_value(object, name, value);
    if (status != JSONSuccess) {
        json_value_free(value);
    }
    return status;
}

JSON_Status json_object_set_null(JSON_Object *object, const char *name) {
    JSON_Value *value = json_value_init_null();
    JSON_Status status = json_object_set_value(object, name, value);
    if (status != JSONSuccess) {
        json_value_free(value);
    }
    return status;
}

JSON_Status json_object_dotset_value(JSON_Object *object, const char *name, JSON_Value *value) {
    const char *dot_pos = 
# 2083 "edit_parson.c" 3 4
                         ((void *)0)
# 2083 "edit_parson.c"
                             ;
    JSON_Value *temp_value = 
# 2084 "edit_parson.c" 3 4
                            ((void *)0)
# 2084 "edit_parson.c"
                                , *new_value = 
# 2084 "edit_parson.c" 3 4
                                               ((void *)0)
# 2084 "edit_parson.c"
                                                   ;
    JSON_Object *temp_object = 
# 2085 "edit_parson.c" 3 4
                              ((void *)0)
# 2085 "edit_parson.c"
                                  , *new_object = 
# 2085 "edit_parson.c" 3 4
                                                  ((void *)0)
# 2085 "edit_parson.c"
                                                      ;
    JSON_Status status = JSONFailure;
    size_t name_len = 0;
    char *name_copy = 
# 2088 "edit_parson.c" 3 4
                     ((void *)0)
# 2088 "edit_parson.c"
                         ;

    if (object == 
# 2090 "edit_parson.c" 3 4
                 ((void *)0) 
# 2090 "edit_parson.c"
                      || name == 
# 2090 "edit_parson.c" 3 4
                                 ((void *)0) 
# 2090 "edit_parson.c"
                                      || value == 
# 2090 "edit_parson.c" 3 4
                                                  ((void *)0)
# 2090 "edit_parson.c"
                                                      ) {
        return JSONFailure;
    }
    dot_pos = strchr(name, '.');
    if (dot_pos == 
# 2094 "edit_parson.c" 3 4
                  ((void *)0)
# 2094 "edit_parson.c"
                      ) {
        return json_object_set_value(object, name, value);
    }
    name_len = dot_pos - name;
    temp_value = json_object_getn_value(object, name, name_len);
    if (temp_value) {

        if (json_value_get_type(temp_value) != JSONObject) {
            return JSONFailure;
        }
        temp_object = json_value_get_object(temp_value);
        return json_object_dotset_value(temp_object, dot_pos + 1, value);
    }
    new_value = json_value_init_object();
    if (new_value == 
# 2108 "edit_parson.c" 3 4
                    ((void *)0)
# 2108 "edit_parson.c"
                        ) {
        return JSONFailure;
    }
    new_object = json_value_get_object(new_value);
    status = json_object_dotset_value(new_object, dot_pos + 1, value);
    if (status != JSONSuccess) {
        json_value_free(new_value);
        return JSONFailure;
    }
    name_copy = parson_strndup(name, name_len);
    if (!name_copy) {
        json_object_dotremove_internal(new_object, dot_pos + 1, 0);
        json_value_free(new_value);
        return JSONFailure;
    }
    status = json_object_add(object, name_copy, new_value);
    if (status != JSONSuccess) {
        parson_free(name_copy);
        json_object_dotremove_internal(new_object, dot_pos + 1, 0);
        json_value_free(new_value);
        return JSONFailure;
    }
    return JSONSuccess;
}

JSON_Status json_object_dotset_string(JSON_Object *object, const char *name, const char *string) {
    JSON_Value *value = json_value_init_string(string);
    if (value == 
# 2135 "edit_parson.c" 3 4
                ((void *)0)
# 2135 "edit_parson.c"
                    ) {
        return JSONFailure;
    }
    if (json_object_dotset_value(object, name, value) != JSONSuccess) {
        json_value_free(value);
        return JSONFailure;
    }
    return JSONSuccess;
}

JSON_Status json_object_dotset_string_with_len(JSON_Object *object, const char *name, const char *string, size_t len) {
    JSON_Value *value = json_value_init_string_with_len(string, len);
    if (value == 
# 2147 "edit_parson.c" 3 4
                ((void *)0)
# 2147 "edit_parson.c"
                    ) {
        return JSONFailure;
    }
    if (json_object_dotset_value(object, name, value) != JSONSuccess) {
        json_value_free(value);
        return JSONFailure;
    }
    return JSONSuccess;
}

JSON_Status json_object_dotset_number(JSON_Object *object, const char *name, double number) {
    JSON_Value *value = json_value_init_number(number);
    if (value == 
# 2159 "edit_parson.c" 3 4
                ((void *)0)
# 2159 "edit_parson.c"
                    ) {
        return JSONFailure;
    }
    if (json_object_dotset_value(object, name, value) != JSONSuccess) {
        json_value_free(value);
        return JSONFailure;
    }
    return JSONSuccess;
}

JSON_Status json_object_dotset_boolean(JSON_Object *object, const char *name, int boolean) {
    JSON_Value *value = json_value_init_boolean(boolean);
    if (value == 
# 2171 "edit_parson.c" 3 4
                ((void *)0)
# 2171 "edit_parson.c"
                    ) {
        return JSONFailure;
    }
    if (json_object_dotset_value(object, name, value) != JSONSuccess) {
        json_value_free(value);
        return JSONFailure;
    }
    return JSONSuccess;
}

JSON_Status json_object_dotset_null(JSON_Object *object, const char *name) {
    JSON_Value *value = json_value_init_null();
    if (value == 
# 2183 "edit_parson.c" 3 4
                ((void *)0)
# 2183 "edit_parson.c"
                    ) {
        return JSONFailure;
    }
    if (json_object_dotset_value(object, name, value) != JSONSuccess) {
        json_value_free(value);
        return JSONFailure;
    }
    return JSONSuccess;
}

JSON_Status json_object_remove(JSON_Object *object, const char *name) {
    return json_object_remove_internal(object, name, 1);
}

JSON_Status json_object_dotremove(JSON_Object *object, const char *name) {
    return json_object_dotremove_internal(object, name, 1);
}

JSON_Status json_object_clear(JSON_Object *object) {
    size_t i = 0;
    if (object == 
# 2203 "edit_parson.c" 3 4
                 ((void *)0)
# 2203 "edit_parson.c"
                     ) {
        return JSONFailure;
    }
    for (i = 0; i < json_object_get_count(object); i++) {
        parson_free(object->names[i]);
        object->names[i] = 
# 2208 "edit_parson.c" 3 4
                          ((void *)0)
# 2208 "edit_parson.c"
                              ;

        json_value_free(object->values[i]);
        object->values[i] = 
# 2211 "edit_parson.c" 3 4
                           ((void *)0)
# 2211 "edit_parson.c"
                               ;
    }
    object->count = 0;
    for (i = 0; i < object->cell_capacity; i++) {
        object->cells[i] = ((size_t)-1);
    }
    return JSONSuccess;
}

JSON_Status json_validate(const JSON_Value *schema, const JSON_Value *value) {
    JSON_Value *temp_schema_value = 
# 2221 "edit_parson.c" 3 4
                                   ((void *)0)
# 2221 "edit_parson.c"
                                       , *temp_value = 
# 2221 "edit_parson.c" 3 4
                                                       ((void *)0)
# 2221 "edit_parson.c"
                                                           ;
    JSON_Array *schema_array = 
# 2222 "edit_parson.c" 3 4
                              ((void *)0)
# 2222 "edit_parson.c"
                                  , *value_array = 
# 2222 "edit_parson.c" 3 4
                                                   ((void *)0)
# 2222 "edit_parson.c"
                                                       ;
    JSON_Object *schema_object = 
# 2223 "edit_parson.c" 3 4
                                ((void *)0)
# 2223 "edit_parson.c"
                                    , *value_object = 
# 2223 "edit_parson.c" 3 4
                                                      ((void *)0)
# 2223 "edit_parson.c"
                                                          ;
    JSON_Value_Type schema_type = JSONError, value_type = JSONError;
    const char *key = 
# 2225 "edit_parson.c" 3 4
                     ((void *)0)
# 2225 "edit_parson.c"
                         ;
    size_t i = 0, count = 0;
    if (schema == 
# 2227 "edit_parson.c" 3 4
                 ((void *)0) 
# 2227 "edit_parson.c"
                      || value == 
# 2227 "edit_parson.c" 3 4
                                  ((void *)0)
# 2227 "edit_parson.c"
                                      ) {
        return JSONFailure;
    }
    schema_type = json_value_get_type(schema);
    value_type = json_value_get_type(value);
    if (schema_type != value_type && schema_type != JSONNull) {
        return JSONFailure;
    }
    switch (schema_type) {
        case JSONArray:
            schema_array = json_value_get_array(schema);
            value_array = json_value_get_array(value);
            count = json_array_get_count(schema_array);
            if (count == 0) {
                return JSONSuccess;
            }

            temp_schema_value = json_array_get_value(schema_array, 0);
            for (i = 0; i < json_array_get_count(value_array); i++) {
                temp_value = json_array_get_value(value_array, i);
                if (json_validate(temp_schema_value, temp_value) != JSONSuccess) {
                    return JSONFailure;
                }
            }
            return JSONSuccess;
        case JSONObject:
            schema_object = json_value_get_object(schema);
            value_object = json_value_get_object(value);
            count = json_object_get_count(schema_object);
            if (count == 0) {
                return JSONSuccess;
            } else if (json_object_get_count(value_object) < count) {
                return JSONFailure;
            }
            for (i = 0; i < count; i++) {
                key = json_object_get_name(schema_object, i);
                temp_schema_value = json_object_get_value(schema_object, key);
                temp_value = json_object_get_value(value_object, key);
                if (temp_value == 
# 2265 "edit_parson.c" 3 4
                                 ((void *)0)
# 2265 "edit_parson.c"
                                     ) {
                    return JSONFailure;
                }
                if (json_validate(temp_schema_value, temp_value) != JSONSuccess) {
                    return JSONFailure;
                }
            }
            return JSONSuccess;
        case JSONString: case JSONNumber: case JSONBoolean: case JSONNull:
            return JSONSuccess;
        case JSONError: default:
            return JSONFailure;
    }
}

int json_value_equals(const JSON_Value *a, const JSON_Value *b) {
    JSON_Object *a_object = 
# 2281 "edit_parson.c" 3 4
                           ((void *)0)
# 2281 "edit_parson.c"
                               , *b_object = 
# 2281 "edit_parson.c" 3 4
                                             ((void *)0)
# 2281 "edit_parson.c"
                                                 ;
    JSON_Array *a_array = 
# 2282 "edit_parson.c" 3 4
                         ((void *)0)
# 2282 "edit_parson.c"
                             , *b_array = 
# 2282 "edit_parson.c" 3 4
                                          ((void *)0)
# 2282 "edit_parson.c"
                                              ;
    const JSON_String *a_string = 
# 2283 "edit_parson.c" 3 4
                                 ((void *)0)
# 2283 "edit_parson.c"
                                     , *b_string = 
# 2283 "edit_parson.c" 3 4
                                                   ((void *)0)
# 2283 "edit_parson.c"
                                                       ;
    const char *key = 
# 2284 "edit_parson.c" 3 4
                     ((void *)0)
# 2284 "edit_parson.c"
                         ;
    size_t a_count = 0, b_count = 0, i = 0;
    JSON_Value_Type a_type, b_type;
    a_type = json_value_get_type(a);
    b_type = json_value_get_type(b);
    if (a_type != b_type) {
        return 0;
    }
    switch (a_type) {
        case JSONArray:
            a_array = json_value_get_array(a);
            b_array = json_value_get_array(b);
            a_count = json_array_get_count(a_array);
            b_count = json_array_get_count(b_array);
            if (a_count != b_count) {
                return 0;
            }
            for (i = 0; i < a_count; i++) {
                if (!json_value_equals(json_array_get_value(a_array, i),
                                       json_array_get_value(b_array, i))) {
                    return 0;
                }
            }
            return 1;
        case JSONObject:
            a_object = json_value_get_object(a);
            b_object = json_value_get_object(b);
            a_count = json_object_get_count(a_object);
            b_count = json_object_get_count(b_object);
            if (a_count != b_count) {
                return 0;
            }
            for (i = 0; i < a_count; i++) {
                key = json_object_get_name(a_object, i);
                if (!json_value_equals(json_object_get_value(a_object, key),
                                       json_object_get_value(b_object, key))) {
                    return 0;
                }
            }
            return 1;
        case JSONString:
            a_string = json_value_get_string_desc(a);
            b_string = json_value_get_string_desc(b);
            if (a_string == 
# 2327 "edit_parson.c" 3 4
                           ((void *)0) 
# 2327 "edit_parson.c"
                                || b_string == 
# 2327 "edit_parson.c" 3 4
                                               ((void *)0)
# 2327 "edit_parson.c"
                                                   ) {
                return 0;
            }
            return a_string->length == b_string->length &&
                   memcmp(a_string->chars, b_string->chars, a_string->length) == 0;
        case JSONBoolean:
            return json_value_get_boolean(a) == json_value_get_boolean(b);
        case JSONNumber:
            return fabs(json_value_get_number(a) - json_value_get_number(b)) < 0.000001;
        case JSONError:
            return 1;
        case JSONNull:
            return 1;
        default:
            return 1;
    }
}

JSON_Value_Type json_type(const JSON_Value *value) {
    return json_value_get_type(value);
}

JSON_Object * json_object (const JSON_Value *value) {
    return json_value_get_object(value);
}

JSON_Array * json_array(const JSON_Value *value) {
    return json_value_get_array(value);
}

const char * json_string(const JSON_Value *value) {
    return json_value_get_string(value);
}

size_t json_string_len(const JSON_Value *value) {
    return json_value_get_string_len(value);
}

double json_number(const JSON_Value *value) {
    return json_value_get_number(value);
}

int json_boolean(const JSON_Value *value) {
    return json_value_get_boolean(value);
}

void json_set_allocation_functions(JSON_Malloc_Function malloc_fun, JSON_Free_Function free_fun) {
    parson_malloc = malloc_fun;
    parson_free = free_fun;
}

void json_set_escape_slashes(int escape_slashes) {
    parson_escape_slashes = escape_slashes;
}

void json_set_float_serialization_format(const char *format) {
    if (parson_float_format) {
        parson_free(parson_float_format);
        parson_float_format = 
# 2385 "edit_parson.c" 3 4
                             ((void *)0)
# 2385 "edit_parson.c"
                                 ;
    }
    if (!format) {
        parson_float_format = 
# 2388 "edit_parson.c" 3 4
                             ((void *)0)
# 2388 "edit_parson.c"
                                 ;
        return;
    }
    parson_float_format = parson_strdup(format);
}

void json_set_number_serialization_function(JSON_Number_Serialization_Function func) {
    parson_number_serialization_function = func;
}
