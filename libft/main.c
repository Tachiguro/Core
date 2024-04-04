#include <stdio.h>
#include "libft.h"

void del(void *content)
{
    free(content);
}

void *increment(void *content)
{
    int *new_content = malloc(sizeof(int));
    *new_content = *(int *)content + 1;
    return new_content;
}

void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d\n", *(int *)lst->content);
        lst = lst->next;
    }
}

int main()
{
    t_list *lst = NULL;
    t_list *new_lst = NULL;
    int arr[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        int *content = malloc(sizeof(int));
        *content = arr[i];
        ft_lstadd_back(&lst, ft_lstnew(content));
    }

    new_lst = ft_lstmap(lst, increment, del);
    print_list(new_lst);

    ft_lstclear(&lst, del);
    ft_lstclear(&new_lst, del);

    return 0;
}
