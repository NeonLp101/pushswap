/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lernst <lernst@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 12:00:00 by lernst            #+#    #+#             */
/*   Updated: 2026/06/16 17:53:07 by lernst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_pair(char *label, int n)
{
	ft_putstr_fd(label, 2);
	ft_putnbr_fd(n, 2);
	ft_putstr_fd("  ", 2);
}

static void	put_header(t_args *opts)
{
	long	scaled;

	scaled = (long)(opts->disorder * 10000.0 + 0.5);
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_putnbr_fd((int)(scaled / 100), 2);
	ft_putstr_fd(".", 2);
	if (scaled % 100 < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd((int)(scaled % 100), 2);
	ft_putstr_fd("%\n[bench] strategy:  ", 2);
	ft_putstr_fd(strat_name(opts->requested), 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(strat_class(opts->resolved), 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_args *opts, t_count *cnt)
{
	put_header(opts);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total_ops(cnt), 2);
	ft_putstr_fd("\n[bench] ", 2);
	put_pair("sa: ", cnt->ops[OP_SA]);
	put_pair("sb: ", cnt->ops[OP_SB]);
	put_pair("ss: ", cnt->ops[OP_SS]);
	put_pair("pa: ", cnt->ops[OP_PA]);
	put_pair("pb: ", cnt->ops[OP_PB]);
	ft_putstr_fd("\n[bench] ", 2);
	put_pair("ra: ", cnt->ops[OP_RA]);
	put_pair("rb: ", cnt->ops[OP_RB]);
	put_pair("rr: ", cnt->ops[OP_RR]);
	put_pair("rra: ", cnt->ops[OP_RRA]);
	put_pair("rrb: ", cnt->ops[OP_RRB]);
	put_pair("rrr: ", cnt->ops[OP_RRR]);
	ft_putstr_fd("\n", 2);
}
