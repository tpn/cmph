#ifndef __CMPH_CHM_H__
#define __CMPH_CHM_H__

#include "cmph.h"

typedef struct __chm_data_t chm_data_t;
typedef struct __chm_config_data_t chm_config_data_t;

chm_config_data_t *chm_config_new();
void chm_config_set_hashfuncs(cmph_config_t *mph, CMPH_HASH *hashfuncs);
void chm_config_destroy(cmph_config_t *mph);
cmph_t *chm_new(cmph_config_t *mph, double c);

void chm_load(FILE *f, cmph_t *mphf);
int chm_dump(cmph_t *mphf, FILE *f);
void chm_destroy(cmph_t *mphf);
cmph_uint32 chm_search(cmph_t *mphf, const char *key, cmph_uint32 keylen);

/** cmph_uint32 chm_search_fingerprint(cmph_t *mphf, const char *key, cmph_uint32 keylen, cmph_uint32 * fingerprint);
 *  \brief Computes the mphf value and a fingerprint of 12 bytes (i.e., figerprint should be a prealocated area to fit three 4-byte integers). 
 *  \param mphf pointer to the resulting function
 *  \param key is the key to be hashed
 *  \param keylen is the key legth in bytes
 *  \return The mphf value
 * 
 * Computes the mphf value and a fingerprint of 12 bytes. The figerprint pointer should be 
 * a prealocated area to fit three 4-byte integers. You don't need to use all the 12 bytes
 * as fingerprint. According to the application, just few bits can be enough, once mphf does
 * not allow collisions for the keys previously known.
 */
cmph_uint32 chm_search_fingerprint(cmph_t *mphf, const char *key, cmph_uint32 keylen, cmph_uint32 * fingerprint);

/** \fn void chm_pack(cmph_t *mphf, void *packed_mphf);
 *  \brief Support the ability to pack a perfect hash function into a preallocated contiguous memory space pointed by packed_mphf.
 *  \param mphf pointer to the resulting mphf
 *  \param packed_mphf pointer to the contiguous memory area used to store the resulting mphf. The size of packed_mphf must be at least cmph_packed_size() 
 */
void chm_pack(cmph_t *mphf, void *packed_mphf);

/** \fn cmph_uint32 chm_packed_size(cmph_t *mphf);
 *  \brief Return the amount of space needed to pack mphf.
 *  \param mphf pointer to a mphf
 *  \return the size of the packed function or zero for failures
 */ 
cmph_uint32 chm_packed_size(cmph_t *mphf);

/** cmph_uint32 chm_search(void *packed_mphf, const char *key, cmph_uint32 keylen);
 *  \brief Use the packed mphf to do a search. 
 *  \param  packed_mphf pointer to the packed mphf
 *  \param key key to be hashed
 *  \param keylen key legth in bytes
 *  \return The mphf value
 */
cmph_uint32 chm_search_packed(void *packed_mphf, const char *key, cmph_uint32 keylen);

#endif
