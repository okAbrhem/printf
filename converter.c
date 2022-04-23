#include "main.h"
/**
 * converter - Receives the main string and all the necessary parameters to
 * print a formated string.
 * @format: A string containing all the desired characters.
 * @f_list: A list of all the posible functions.
 * @arg_list: A list containing all the argumentents passed to the program.
 * Return: Number of characters printed.
 */
int converter(const char *format, convert_t f_list[], va_list arg_list)
{
	int i, j, ret_val, numberOfchars;

	numberOfchars = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; f_list[j].sel != NULL; j++)
			{
				if (format[i + 1] == f_list[j].sel[0])
				{
					ret_val = f_list[j].f(arg_list);

					if (ret_val == -1)
					{
						return (-1);

						numberOfchars += ret_val;
						break;
					}
				}
			if (f_list[j].sel == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_write_char(format[i]);
					_write_char(format[i + 1]);

					numberOfchars = numberOfchars + 2;
				}
				else
				{
					return (-1);
				}
				i = i + 1;
			}
			else
			{
				_write_char(format[i]);
				numberOfchars++;
			}
			}
		}
	}
			return (numberOfchars);
}
