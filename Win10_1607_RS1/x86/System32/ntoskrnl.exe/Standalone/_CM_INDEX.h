typedef struct _CM_COMPONENT_HASH
{
  /* 0x0000 */ unsigned long Hash;
} CM_COMPONENT_HASH, *PCM_COMPONENT_HASH; /* size: 0x0004 */

typedef struct _CM_INDEX
{
  /* 0x0000 */ unsigned long Cell;
  union
  {
    /* 0x0004 */ unsigned char NameHint[4];
    /* 0x0004 */ struct _CM_COMPONENT_HASH HashKey;
  }; /* size: 0x0004 */
} CM_INDEX, *PCM_INDEX; /* size: 0x0008 */

