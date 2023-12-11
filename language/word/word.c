#include "word.h"
#include "letter.h"
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

word Word(unsigned int n, ...)
{
    va_list args;
    va_start(args, n);

    unsigned int total_length = 0;
    for (unsigned int i = 0; i < n; i++)
    {
        void *w_or_l = va_arg(args, void *);
        if (w_or_l >= (void *)latin_alphabet_with_epsilon && w_or_l < (void *)(latin_alphabet_with_epsilon + SIZE_OF_LATIN_ALPHABET_WITH_EPSILON))
        {
            total_length++;
        }
        else
        {
            word w = (word)w_or_l;
            total_length += getLength(w);
        }
    }

    va_end(args);

    void *contents[(total_length + 1)];
    contents[0] = &total_length;

    va_start(args, n);

    unsigned int index = 1;
    for (unsigned int i = 0; i < n; i++)
    {
        void *w_or_l = va_arg(args, void *);
        if (w_or_l >= (void *)latin_alphabet_with_epsilon && w_or_l < (void *)(latin_alphabet_with_epsilon + SIZE_OF_LATIN_ALPHABET_WITH_EPSILON))
        {
            contents[index] = w_or_l;
            index++;
        }
        else
        {
            word w = (word)w_or_l;
            for (unsigned int j = 0; j < getLength(w); j++)
            {
                contents[index] = getObjectByIndex(w, j);
                index++;
            }
        }
    }

    va_end(args);

    n_tuple w = NTupleFromVoidPointerArray(contents);
    return w;
}

void print(const wchar_t *format, ...)
{
    long unsigned int format_length = wcslen(format);

    va_list args;
    va_start(args, format);

    for (unsigned int i = 0; i < format_length; i++)
    {
        if (i < (format_length - 2) && format[i] == '%' && format[i + 1] == 'l' && format[i + 2] == 'w')
        {
            word w = va_arg(args, word);
            for (unsigned int j = 0; j < getLength(w); j++)
            {
                letter l = getObjectByIndex(w, j);
                wprintf(L"%lc", *l);
            }
            i += 2;
        }
        else if (i < (format_length - 2) && format[i] == '%' && format[i + 1] == 'l' && format[i + 2] == 'l')
        {
            wprintf(L"%lc", *va_arg(args, letter));
            i += 2;
        }
        else if (i < (format_length - 1) && format[i] == '%' && format[i + 1] == 'u')
        {
            wprintf(L"%u", va_arg(args, unsigned int));
        }
        else if (i < (format_length - 1) && format[i] == '%' && format[i + 1] == 'd')
        {
            wprintf(L"%u", va_arg(args, int));
        }
        else
        {
            wprintf(L"%lc", format[i]);
        }
    }

    va_end(args);
}

word wordFromString(const wchar_t *str)
{
    size_t length = wcslen(str);
    void *contents[(length + 1)];
    contents[0] = &length;
    for (unsigned int i = 0; i < length; i++)
    {
        if (str[i] >= 97 && str[i] <= 122)
        {
            contents[i + 1] = (void *)(latin_alphabet_with_epsilon + (str[i] - 97));
        }
        else if (str[i] >= 48 && str[i] <= 57)
        {
            contents[i + 1] = (void *)(latin_alphabet_with_epsilon + 26 + (str[i] - 48));
        }
        else if (str[i] == L'ε')
        {
            contents[i + 1] = (void *)(latin_alphabet_with_epsilon + 36);
        }
        else if (str[i] == L'|')
        {
            contents[i + 1] = (void *)(latin_alphabet_with_epsilon + 37);
        }
        else if (str[i] == L'*')
        {
            contents[i + 1] = (void *)(latin_alphabet_with_epsilon + 38);
        }
        else if (str[i] == L'(')
        {
            contents[i + 1] = (void *)(latin_alphabet_with_epsilon + 39);
        }
        else if (str[i] == L')')
        {
            contents[i + 1] = (void *)(latin_alphabet_with_epsilon + 40);
        }
    }
    n_tuple w = NTupleFromVoidPointerArray(contents);
    return w;
}

letter getLetterByIndex(word w, unsigned int idx)
{
    assert(idx < getLength(w));
    return getObjectByIndex(w, idx);
}

word getSubword(word w, unsigned int start, unsigned int end)
{
    assert(start <= end);
    assert(end <= getLength(w));
    unsigned int length = end - start;
    void *contents[(length + 1)];
    contents[0] = &length;
    for (unsigned int i = 0; i < length; i++)
    {
        contents[i + 1] = getObjectByIndex(w, start + i);
    }
    n_tuple subword = NTupleFromVoidPointerArray(contents);
    return subword;
}
