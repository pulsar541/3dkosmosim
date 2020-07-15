#include	<math.h>

void DELETE_PLANET(PLANET pl)
{
 E_planet[pl.NUM]=false;
 	GeneratePortalSystem();
}