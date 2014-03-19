echo "Compil server"
clang get_cl_th.c get_lst_cl.c get_stage.c main_serv.c -I ../ -I ../libft/includes -L../libft/ -lft_core -lft_printf -lft_list -o server
echo "Compil client"
clang -Wall -Wextra -o client tmp_client.c
