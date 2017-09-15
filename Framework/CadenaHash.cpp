#include "CadenaHash.h"

nat CadenaHash::CodigoDeHash(const Cadena& c) const
{
	nat hashCode = 0;
	for (nat i = 0; i < c.Largo; i++)
		hashCode += c[i]*i;
	return hashCode;
}
