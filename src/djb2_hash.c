#include "djb2_hash.h"
#include <stdlib.h>

djb2_state_t *djb2_state_new()
{
	djb2_state_t *state = (djb2_state_t *)malloc(sizeof(djb2_state_t));
	state->hashfunc = HASH_DJB2;
	return state;
}

void djb2_state_destroy(djb2_state_t *state)
{
	free(state);
}

uint32 djb2_hash(djb2_state_t *state, const char *k, uint32 keylen)
{
	register unsigned int hash = 5381;
	const unsigned char *ptr = k;
	int i = 0;
	while (i < keylen) 
	{
		hash = hash*33 ^ *ptr;
		++ptr, ++i;
	}
	return hash;
}


void djb2_state_dump(djb2_state_t *state, char **buf, uint32 *buflen)
{
	*buf = NULL;
	*buflen = 0;
	return;
}

djb2_state_t *djb2_state_load(const char *buf, uint32 buflen)
{
	djb2_state_t *state = (djb2_state_t *)malloc(sizeof(djb2_state_t));
	state->hashfunc = HASH_DJB2;
	return state;
}
