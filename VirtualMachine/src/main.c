/*
** EPITECH PROJECT, 2018
** VM
** File description:
** main.c
*/

#include "../include/my.h"

void my_malloc_tab(vm_t *vm)
{
    int i = 0;

    vm->cycle_nb = 0;
    if ((vm->champ = malloc(sizeof(champions_t*) * (vm->nb_champ * 10000))) == NULL)
        exit(84);
    while (i != (vm->nb_champ * 10000)) {
        if ((vm->champ[i] = malloc(sizeof(champions_t))) == NULL)
            exit(84);
        if ((vm->champ[i]->reg = malloc(sizeof(int) * REG_NUMBER)) == NULL)
            exit(84);
        vm->champ[i]->nb = 0;
        vm->champ[i]->dead = 0;
        vm->champ[i]->adress = -1;
        vm->champ[i]->pause = -1;
        vm->champ[i]->live = 0;
        vm->nbr_live = 0;
        vm->nbr_fork = 0;
        vm->champ[i]->real = -1;
        vm->champ[i]->proc = 0;
        i++;
    }
}

int get_lower_champ(vm_t *vm, int opt)
{
    static int low = 1;
    int i = 0;
    int k = -1;

    if (opt == 1)
        low = 1;
    while (i != vm->nb_champ && k != low) {
        if (vm->champ[i]->nb == low)
            k = i;
        i++;
        if (k == -1 && i == vm->nb_champ) {
            low++;
            i = 0;
        }
        if (low == 5)
            return (0);
    }
    low++;
    return (k);
}

void define_adress(vm_t *vm)
{
    int i = 0;
    int j = get_lower_champ(vm, 1);
    int space = MEM_SIZE / vm->nb_champ;

    while (i != vm->nb_champ) {
        if (vm->champ[j]->adress > MEM_SIZE)
            vm->champ[j]->adress %= MEM_SIZE;
        if (vm->champ[j]->adress == -1)
            vm->champ[j]->adress = i * space;
        vm->champ[j]->pc = vm->champ[j]->adress;
        j = get_lower_champ(vm, 0);
        i++;
    }
}

void set_value(vm_t *vm)
{
    int i = 0;
    int j = 1;
    int k = 0;

    for (i = 0; i != (vm->nb_champ * 10000); i++) {
        while (k != REG_NUMBER) {
            vm->champ[i]->reg[k] = 0;
            k++;
        }
        k = 0;
    }
    for (i = 0; i != vm->nb_champ; i++) {
        for (; check_other_nb(j, vm) == 1; j++);
        if (vm->champ[i]->nb == 0) {
            vm->champ[i]->nb = j;
            j++;
        }
        vm->champ[i]->reg[0] = vm->champ[i]->nb;
    }
    define_adress(vm);
}

void find_next_inst(vm_t *vm, int j)
{
    void (*t[16])(vm_t*, int) = {live, ld, st, add, sub, and, or, xor, zjmp,\
    ldi, sti, forke, lld, lldi, lfork, aff};
    int i = 0;

    if (vm->arena[vm->champ[j]->pc] > 16 || vm->arena[vm->champ[j]->pc] <= 0 ) {
        vm->champ[j]->pc += 1;
        return;
    }
    i = vm->arena[vm->champ[j]->pc];
    t[i - 1](vm, j);
}

int count_alive(vm_t *vm)
{
    int i = 0;
    int alive = 0;

    while (i != vm->nb_champ) {
        if (vm->champ[i]->dead  == 0)
            alive++;
        i++;
    }
    return (alive);
}

void end_condition(vm_t *vm)
{
    int i = 0;

    while (i != vm->nb_champ) {
        if (vm->champ[i]->live != 0 && vm->champ[i]->dead == 0)
            vm->champ[i]->live = 0;
        else
            vm->champ[i]->dead = 1;
        i++;
    }
}

int check_cycle(vm_t *vm)
{
    if (vm->check % vm->cycle_to_die == 0 && vm->check != 0) {
        vm->check = 0;
        end_condition(vm);
    }
    if ((vm->cycle) == vm->cycle_nb && vm->cycle != 0) {
        disp_arena(vm);
        return (1);
    }
    return (0);
}

void init_all(vm_t *vm)
{

    vm->cycle = 0;
    vm->check = 0;
    vm->last_live = -1;
    if (vm->g == 1) {
        vm->ncurse = malloc(sizeof(ncurse_t));
        (vm->ncurse == NULL) ? exit(84) : 0;
        init_ncurse_struct(vm);
        stock_shell_infos(vm->ncurse);
        //menu(vm);
        clear();
        create_vm_window(vm->ncurse);
        vm->ncurse->deco = newwin(20, COLS, 79, 0);
        box(vm->ncurse->deco, 0, 0);
        set_mem(vm);
    }
}

void game_loop(vm_t *vm)
{
    int i = 0;
    int alive = count_alive(vm);

    init_all(vm);
    while (alive > 0) {
        while (i != (vm->nb_champ + vm->nbr_fork)) {
            vm->champ[i]->pc %= MEM_SIZE;
            find_next_inst(vm, i);
            if (vm->champ[i]->pause > 0)
                vm->champ[i]->pause--;
            i++;
        }
        i = 0;
        if (check_cycle(vm) == 1) {
            endwin();
            return;
        }
        vm->check++;
        vm->cycle++;
        if (vm->cycle_to_die < 0) {
            endwin();
            return;
        }
        alive = count_alive(vm);
        if (vm->g == 1) {
            for (int j = 0; j < 6; j++)
                wrefresh(vm->ncurse->win[j]);
            information(vm);
            refresh();
            set_mem(vm);
        }
    }
    endwin();
}

void find_winner(vm_t *vm)
{
    if (vm->last_live != -1) {
        my_putstr("The player ");
        my_put_nbr(vm->champ[vm->last_live]->nb);
        my_putstr(" (");
        my_putstr(vm->champ[vm->last_live]->name);
        my_putstr(") has won.\n");
    }
}

int main(int ac, char **av)
{
    vm_t *vm = malloc(sizeof(vm_t));

    if (vm == NULL || ac == 1)
        exit(84);
    vm->g = 0;
    vm->cycle_to_die = CYCLE_TO_DIE;
    find_champ(av, vm);
    my_malloc_tab(vm);
    parse_argument(av, vm);
    set_value(vm);
    my_create_arena(vm);
    put_champion(vm);
    game_loop(vm);
    find_winner(vm);
    return (0);
}