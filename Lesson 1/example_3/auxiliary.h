struct CHAR_VEC
{
    int len;
    char *arr;
};
struct FLOAT_VEC
{
    int len;
    float *arr;
};

struct CHAR_VEC input_numbers(char *label)
{
    size_t len = 0;
    char *input = NULL;
    printf("%s: ", label);
    int actual_size = getline(&input, &len, stdin);
    struct CHAR_VEC char_vec = {actual_size, input};
    return char_vec;
}

struct FLOAT_VEC char_to_float(struct CHAR_VEC arr_char)
{
    float *arr_float = malloc(sizeof(float) * 2048);
    char *ptr = strtok(arr_char.arr, ",");
    int i = 0;
    while (ptr != NULL)
    {
        arr_float[i] = atof(ptr);
        ptr = strtok(NULL, ",");
        i++;
    }
    struct FLOAT_VEC float_vec = {i, arr_float};
    return float_vec;
}