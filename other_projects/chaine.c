#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
void	ft_putnbr(int nb);
typedef struct Noeud
{
  int valeur;
  struct Noeud *suivant;
} Noeud ;

Noeud *add_debut(Noeud *nd, int valeur)
{
	Noeud *s1 = malloc(sizeof(struct Noeud));
	s1->suivant = nd;
	s1->valeur = valeur;
	return (s1);
}

Noeud *add_fin(Noeud *nd, int valeur)
{
	Noeud *s1 = malloc(sizeof(struct Noeud));
	if (nd == NULL)
	{
		s1->suivant = NULL;
		s1->valeur = valeur;
		return (s1);
	}
	Noeud *actuel = nd;
	while (actuel->suivant != NULL)
	{
		actuel = actuel->suivant;
	}
	s1->valeur = valeur;
	actuel->suivant = s1;
	return (nd);
}

void view(Noeud *p)
{
	while (p)
	{
		int print = p->valeur;
		ft_putnbr(print);
		p = p->suivant;
	}
}

int main(void)
{
	Noeud *s1 = NULL ;
	s1 = add_debut(s1, 5);
	s1 = add_debut(s1, 20);
	s1 = add_debut(s1, 3);
	s1 = add_fin(s1, 3);
	view(s1);
	return (0);
}
