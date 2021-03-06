typedef struct _EXHANDLE
{
  union
  {
    struct /* bitfield */
    {
      /* 0x0000 */ unsigned long TagBits : 2; /* bit position: 0 */
      /* 0x0000 */ unsigned long Index : 30; /* bit position: 2 */
    }; /* bitfield */
    /* 0x0000 */ void* GenericHandleOverlay;
    /* 0x0000 */ unsigned long Value;
  }; /* size: 0x0004 */
} EXHANDLE, *PEXHANDLE; /* size: 0x0004 */

typedef struct _HANDLE_TABLE_ENTRY
{
  union
  {
    /* 0x0000 */ volatile long VolatileLowValue;
    /* 0x0000 */ long LowValue;
    /* 0x0000 */ struct _HANDLE_TABLE_ENTRY_INFO* volatile InfoTable;
    struct /* bitfield */
    {
      /* 0x0000 */ unsigned long Unlocked : 1; /* bit position: 0 */
      /* 0x0000 */ unsigned long Attributes : 2; /* bit position: 1 */
      /* 0x0000 */ unsigned long ObjectPointerBits : 29; /* bit position: 3 */
    }; /* bitfield */
  }; /* size: 0x0004 */
  union
  {
    /* 0x0004 */ long HighValue;
    /* 0x0004 */ struct _HANDLE_TABLE_ENTRY* NextFreeHandleEntry;
    /* 0x0004 */ struct _EXHANDLE LeafHandleValue;
    struct /* bitfield */
    {
      /* 0x0004 */ unsigned long GrantedAccessBits : 25; /* bit position: 0 */
      /* 0x0004 */ unsigned long ProtectFromClose : 1; /* bit position: 25 */
      /* 0x0004 */ unsigned long RefCnt : 6; /* bit position: 26 */
    }; /* bitfield */
  }; /* size: 0x0004 */
} HANDLE_TABLE_ENTRY, *PHANDLE_TABLE_ENTRY; /* size: 0x0008 */

