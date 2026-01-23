*This project has been created as part of the 42 curriculum by somenvie.*

# DESCRIPTION


# INSTRUCTIONS


# RESOURCES


# PROJECT SETUP


PRINT  STACK AND  OP
TEST LST SIZE
IF OK 
	START NORMALIZE 
	TEST AGAIN PRINT STACK AND OP



/*
int	main(int argc, char **argv)
{
	t_dlst	*a;
	t_dlst	*b;
	t_dlst	*tmpa;
	t_dlst	*tmpb;

	a = parsing(argc, argv);
	b = NULL;

	if (!a)
		ft_printf("Error\n");
	else
	{
		normalize(a);

		tmpa = a;
		tmpb = b;

		ft_printf("\nSTACKS \n");
		ft_printf("------\n");

		while (tmpa || tmpb)
		{
			if (tmpb)
			{
				ft_printf("%d    %d\n", tmpa->content, tmpb->content);
				tmpb = tmpb->next;
			}
			else
				ft_printf("%d    \n", tmpa->content);
			tmpa = tmpa->next;
		}

		free_list(a);
		free_list(b);
	}
}
*/