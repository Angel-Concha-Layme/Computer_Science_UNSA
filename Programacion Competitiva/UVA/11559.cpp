// participantes - presupuesto - hoteles - semanas
//  3 1000 2 3
//  200     -> precio por persona   -> [hoteles]
//  0 2 2   -> numero de camas      -> [hoteles]
//  300     -> precio por persona   -> [hoteles]
//  27 3 20 -> numero de camas      -> [hoteles]

#include <stdio.h>

int main() {
	int participantes, presupuesto, num_hoteles, semanas;
	int P, i, a;
	while(scanf("%d %d %d %d", &participantes, &presupuesto, &num_hoteles, &semanas) == 4) {
		int min = presupuesto+1;
		while(num_hoteles--) {
			scanf("%d", &P);
			for(i = 0; i < semanas; i++) {
				scanf("%d", &a);
				if(a >= participantes && participantes*P < min)
					min = participantes*P;
			}
		}
		if(min == presupuesto+1)
			puts("stay home");
		else
			printf("%d\n", min);
	}
    return 0;
}