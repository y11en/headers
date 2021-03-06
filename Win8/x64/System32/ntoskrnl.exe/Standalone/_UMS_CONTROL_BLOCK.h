typedef struct _LIST_ENTRY
{
  /* 0x0000 */ struct _LIST_ENTRY* Flink;
  /* 0x0008 */ struct _LIST_ENTRY* Blink;
} LIST_ENTRY, *PLIST_ENTRY; /* size: 0x0010 */

typedef struct _DISPATCHER_HEADER
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned char Type;
      union
      {
        /* 0x0001 */ unsigned char TimerControlFlags;
        struct /* bitfield */
        {
          /* 0x0001 */ unsigned char Absolute : 1; /* bit position: 0 */
          /* 0x0001 */ unsigned char Wake : 1; /* bit position: 1 */
          /* 0x0001 */ unsigned char EncodedTolerableDelay : 6; /* bit position: 2 */
        }; /* bitfield */
        /* 0x0001 */ unsigned char Abandoned;
        struct
        {
          /* 0x0001 */ unsigned char Signalling;
          union
          {
            /* 0x0002 */ unsigned char ThreadControlFlags;
            struct /* bitfield */
            {
              /* 0x0002 */ unsigned char CycleProfiling : 1; /* bit position: 0 */
              /* 0x0002 */ unsigned char CounterProfiling : 1; /* bit position: 1 */
              /* 0x0002 */ unsigned char GroupScheduling : 1; /* bit position: 2 */
              /* 0x0002 */ unsigned char AffinitySet : 1; /* bit position: 3 */
              /* 0x0002 */ unsigned char Reserved : 4; /* bit position: 4 */
            }; /* bitfield */
            /* 0x0002 */ unsigned char Hand;
            struct
            {
              /* 0x0002 */ unsigned char Size;
              union
              {
                /* 0x0003 */ unsigned char TimerMiscFlags;
                struct /* bitfield */
                {
                  /* 0x0003 */ unsigned char Index : 6; /* bit position: 0 */
                  /* 0x0003 */ unsigned char Inserted : 1; /* bit position: 6 */
                  /* 0x0003 */ volatile unsigned char Expired : 1; /* bit position: 7 */
                }; /* bitfield */
                /* 0x0003 */ unsigned char DebugActive;
                struct /* bitfield */
                {
                  /* 0x0003 */ unsigned char ActiveDR7 : 1; /* bit position: 0 */
                  /* 0x0003 */ unsigned char Instrumented : 1; /* bit position: 1 */
                  /* 0x0003 */ unsigned char Reserved2 : 4; /* bit position: 2 */
                  /* 0x0003 */ unsigned char UmsScheduled : 1; /* bit position: 6 */
                  /* 0x0003 */ unsigned char UmsPrimary : 1; /* bit position: 7 */
                }; /* bitfield */
                /* 0x0003 */ unsigned char DpcActive;
              }; /* size: 0x0001 */
            }; /* size: 0x0002 */
          }; /* size: 0x0002 */
        }; /* size: 0x0003 */
      }; /* size: 0x0003 */
    }; /* size: 0x0004 */
    /* 0x0000 */ volatile long Lock;
    /* 0x0000 */ long LockNV;
  }; /* size: 0x0004 */
  /* 0x0004 */ long SignalState;
  /* 0x0008 */ struct _LIST_ENTRY WaitListHead;
} DISPATCHER_HEADER, *PDISPATCHER_HEADER; /* size: 0x0018 */

typedef struct _KQUEUE
{
  /* 0x0000 */ struct _DISPATCHER_HEADER Header;
  /* 0x0018 */ struct _LIST_ENTRY EntryListHead;
  /* 0x0028 */ volatile unsigned long CurrentCount;
  /* 0x002c */ unsigned long MaximumCount;
  /* 0x0030 */ struct _LIST_ENTRY ThreadListHead;
} KQUEUE, *PKQUEUE; /* size: 0x0040 */

typedef struct _KEVENT
{
  /* 0x0000 */ struct _DISPATCHER_HEADER Header;
} KEVENT, *PKEVENT; /* size: 0x0018 */

typedef struct _UMS_CONTROL_BLOCK
{
  /* 0x0000 */ struct _RTL_UMS_CONTEXT* UmsContext;
  /* 0x0008 */ struct _SINGLE_LIST_ENTRY* CompletionListEntry;
  /* 0x0010 */ struct _KEVENT* CompletionListEvent;
  /* 0x0018 */ unsigned long ServiceSequenceNumber;
  union
  {
    struct
    {
      /* 0x0020 */ struct _KQUEUE UmsQueue;
      /* 0x0060 */ struct _LIST_ENTRY QueueEntry;
      /* 0x0070 */ struct _RTL_UMS_CONTEXT* YieldingUmsContext;
      /* 0x0078 */ void* YieldingParam;
      /* 0x0080 */ void* UmsTeb;
    }; /* size: 0x0068 */
    struct
    {
      /* 0x0020 */ struct _KQUEUE* UmsAssociatedQueue;
      /* 0x0028 */ struct _LIST_ENTRY* UmsQueueListEntry;
      /* 0x0030 */ struct _KEVENT UmsWaitEvent;
      /* 0x0048 */ void* StagingArea;
      union
      {
        struct /* bitfield */
        {
          /* 0x0050 */ unsigned long UmsPrimaryDeliveredContext : 1; /* bit position: 0 */
          /* 0x0050 */ unsigned long UmsAssociatedQueueUsed : 1; /* bit position: 1 */
          /* 0x0050 */ unsigned long UmsThreadParked : 1; /* bit position: 2 */
        }; /* bitfield */
        /* 0x0050 */ unsigned long UmsFlags;
      }; /* size: 0x0004 */
    }; /* size: 0x0034 */
  }; /* size: 0x0068 */
  /* 0x0088 */ unsigned short TebSelector;
  /* 0x008a */ char __PADDING__[6];
} UMS_CONTROL_BLOCK, *PUMS_CONTROL_BLOCK; /* size: 0x0090 */

