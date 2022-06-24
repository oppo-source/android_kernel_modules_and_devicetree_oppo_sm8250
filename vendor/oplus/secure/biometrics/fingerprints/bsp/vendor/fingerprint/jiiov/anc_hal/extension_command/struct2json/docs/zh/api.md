# struct2json API �ĵ�

---

����֧�ֵ�API�ӿڶ��� `\struct2json\inc\s2j.h` ���������������ݽ϶࣬����ʹ�� CTRL+F ������

## 1���û�ʹ�ýӿ�

### 1.1 ��ʼ��

��ʼ����struct2json�⡣

> ע��Ŀǰ��Ҫ��ʼ���ÿ⼰cJSON��������ڴ��������Ĭ��ʹ�õ� `malloc` �� `free` ��Ϊ�ڴ�������������ʼ����

### 1.2 ���ṹ�����ת�������л���ΪJSON����

ע�⣺����API�����ú궨�巽ʽ����ʹ��ʱ�볣��API������ʽ���в�ͬ����ע��鿴Demo��

#### 1.2.1 ����JSON����

```C
s2j_create_json_obj(json_obj)
```

|����                                    |����|
|:-----                                  |:----|
|json_obj                                |JSON����|

#### 1.2.2 ת����������Ԫ��

ע�⣺����Ľṹ��Ԫ�ػ�������ֻ֧�� `int` �� `string` �� `double` ����������ת��ʱӦ����ѡȡ�����е�����һ����Ŀ�����ͣ�ѡ���׼Ϊ�������ͼ�ɱ������໥ת�������磺�ṹ��Ԫ������Ϊ `uint8_t` ��`uint16_t` ��`int16_t` �� `size_t` ��`ĳָ���ַ` �����Ϳ���ѡ�� `int` ��Ϊ��Ρ�

```C
s2j_json_set_basic_element(to_json, from_struct, type, element)
```

|����                                    |����|
|:-----                                  |:----|
|to_json                                 |Ŀ��JSON����|
|from_struct                             |Դ�ṹ�����|
|type                                    |Դ�ṹ�����Ԫ�����ͣ�����ֻ֧��int��string��double|
|element                                 |Դ�ṹ�����Ԫ��|

#### 1.2.3 ת����������Ԫ��

```C
s2j_json_set_array_element(to_json, from_struct, type, element, size)
```

|����                                    |����|
|:-----                                  |:----|
|to_json                                 |Ŀ��JSON����|
|from_struct                             |Դ�ṹ�����|
|type                                    |Դ�ṹ�����Ԫ�صĻ������͡��ο�1.2.2�жԻ������͵�Ҫ��|
|element                                 |Դ�ṹ�����Ԫ��|
|size                                    |Դ�ṹ���������Ԫ�صĳ���|

#### 1.2.4 ת���ṹ������Ԫ�أ����ӽṹ�壩

```C
s2j_json_set_struct_element(child_json, to_json, child_struct, from_struct, type, element)
```

|����                                    |����|
|:-----                                  |:----|
|child_json                              |Ŀ��JSON�������JSON����|
|to_json                                 |Ŀ��JSON����|
|child_struct                            |Դ�ṹ�������ӽṹ�����|
|from_struct                             |Դ�ṹ�����|
|type                                    |Դ�ṹ�����Ԫ�أ��ӽṹ�壩����|
|element                                 |Դ�ṹ�����Ԫ��|

���ӣ�
```C
typedef struct {
    char name[16];
} Hometown;

typedef struct {
    uint8_t id;
    char name[10];
    Hometown hometown;
} Student;

Student orignal_struct_student = {
        .id = 24,
        .name = "armink",
        .hometown.name = "China",
}
Student *struct_student = &orignal_struct_student;
/* ������Student JSON���� */
s2j_create_json_obj(json_student);
/* ���л���ת����Student�ṹ���idԪ�� */
s2j_json_set_basic_element(json_student, struct_student, int, id);
/* ���л�Student�ṹ���nameԪ�� */
s2j_json_set_basic_element(json_student, struct_student, string, name);
/* ���л�Student�ṹ����ӽṹ��hometownԪ�� */
s2j_json_set_struct_element(json_hometown, json_student, struct_hometown, struct_student, Hometown, hometown);
/* ���л�Hometown�ṹ���nameԪ�� */
s2j_json_set_basic_element(json_hometown, struct_hometown, string, name);
```

### 1.3 ��JSON����ת���������л���Ϊ�ṹ�����

#### 1.3.1 �����ṹ�����

```C
s2j_create_struct_obj(struct_obj, type)
```

|����                                    |����|
|:-----                                  |:----|
|struct_obj                              |�ṹ�����|
|type                                    |�ṹ������|

#### 1.3.2 ת����������Ԫ��

```C
s2j_struct_get_basic_element(to_struct, from_json, type, element)
```

|����                                    |����|
|:-----                                  |:----|
|to_struct                               |Ŀ��ṹ�����|
|from_json                               |ԴJSON����|
|type                                    |Ŀ��ṹ�����Ԫ�����͡��ο�1.2.2�жԻ������͵�Ҫ��|
|element                                 |Ŀ��ṹ�����Ԫ��|

#### 1.3.3 ת����������Ԫ��

```C
s2j_struct_get_array_element(to_struct, from_json, type, element)
```

|����                                    |����|
|:-----                                  |:----|
|to_struct                               |Ŀ��ṹ�����|
|from_json                               |ԴJSON����|
|type                                    |Ŀ��ṹ�����Ԫ�����͡��ο�1.2.2�жԻ������͵�Ҫ��|
|element                                 |Ŀ��ṹ�����Ԫ��|

#### 1.3.4 ת���ṹ������Ԫ�أ�����JSON��

```C
s2j_struct_get_struct_element(child_struct, to_struct, child_json, from_json, type, element)
```

|����                                    |����|
|:-----                                  |:----|
|child_struct                            |Ŀ��ṹ�������ӽṹ�����|
|to_struct                               |Ŀ��ṹ�����|
|child_json                              |ԴJSON�������JSON����|
|from_json                               |ԴJSON����|
|type                                    |ԴJSON����Ԫ�أ���JSON������|
|element                                 |ԴJSON����Ԫ��|

���ӣ�
```C
typedef struct {
    char name[16];
} Hometown;

typedef struct {
    uint8_t id;
    char name[10];
    Hometown hometown;
} Student;

char orignal_json_string_student[] = "{\"id\":24, \"name\":\"armink\", \"hometown\":{\"name\":\"China\"}}";
/* ����Student JSON���� */
cJSON *json_student = cJSON_Parse(orignal_json_string_student);
/* ������Student�ṹ����� */
s2j_create_struct_obj(struct_student, Student);
/* �����л�Student�ṹ���idԪ�� */
s2j_struct_get_basic_element(struct_student, json_student, int, id);
/* �����л�Student�ṹ���nameԪ�� */
s2j_struct_get_basic_element(struct_student, json_student, string, name);
/* �����л�Student�ṹ����ӽṹ��hometownԪ�� */
s2j_struct_get_struct_element(struct_hometown, struct_student, json_hometown, json_student, Hometown, hometown);
/* �����л�Hometown�ṹ���nameԪ�� */
s2j_struct_get_basic_element(struct_hometown, json_hometown, string, name);
```

## 2��ע��

- �ÿ�ֻ������C99�������ϱ�׼������