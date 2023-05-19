#include "shell.h"

/**
 * _myhistory - history list display, one command by line, preceded
 * @info: Struct. has potential arguments.maintain
 * constant function prototype.
 *  Return: 0 Always
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias -this  sets alias to string
 * @info: the parameter structure
 * @str: the string alias
 *
 * Return: 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *q, c;
	int ret;

	p = _strchr(str, '=');
	if (!q)
		return (1);
	c = *q;
	*q = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*q = c;
	return (return);
}

/**
 * set_alias - this sets alias to string
 * @info: the parameter struct
 * @str: string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *q;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	if (!*++q)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - this prints an alias string
 * @node: the alias node
 *
 * Return: 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *q = NULL, *a = NULL;

	if (node)
	{
		q = _strchr(node->str, '=');
		for (a = node->str; a <= q; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(q + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Struct with potential arguments.maintain
 *   constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int j = 0;
	char *q = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (j = 1; info->argv[j]; j++)
	{
		q = _strchr(info->argv[j], '=');
		if (q)
			set_alias(info, info->argv[j]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}


