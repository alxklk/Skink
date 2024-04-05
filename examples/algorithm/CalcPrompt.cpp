/**
 * @file Calc.cpp
 * @author klk
 * @brief Simple calculator usage example
 * @version 0.1
 * @date 2024-03-28
 * 
 * @copyright Copyright (c) 2024
 * 
 *  See Calc.h for details
 * 
 */

#include "Calc.h"

int main()
{
	Calc c;
	strcp(&(c.vars[0].name[0]),"pi",TOK_LEN);
	c.vars[0].value=M_PI;
	while(1)
	{
		char g[256];
		printf("\n>");
		if(fgets(g,256,stdin))
		{
			//printf("Got line `%s`", g);
			c.t[0].SetEnd();
			MakeTokens(c.t,g);
			if(c.t[0].IsEnd())
			{
				continue;
			}
			/*
			bool end=false;
			for(int i=0;i<NTOK;i++)
			{
				if(i)printf(" ");
				int type=t[i].type;
				switch(type)
				{
					case NUM: printf("%f", t[i].GetNumber());break;
					case ID:  printf("%s", t[i].value);break;
					case OP:  printf("%c", t[i].value[0]);break;
					case END: printf("\n"); end=true; break;
				}
				if(end)
				{
					break;
				}
			}*/
			Stx s={&c, 0, YES};
			float res;
			Stx e=s.TryAssign(res);
			if(!e.Yes())
				e=s.TryExpr(res);
			if(e.Yes())
			{
				printf("Result: %f\n", res);
			}
			else
			{
				// printf("No expr or error\n");
			}
		}else return 0;
	}
	return 0;
}
