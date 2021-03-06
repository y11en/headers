typedef struct _VF_ADDRESS_RANGE
{
  /* 0x0000 */ unsigned char* Start;
  /* 0x0008 */ unsigned char* End;
} VF_ADDRESS_RANGE, *PVF_ADDRESS_RANGE; /* size: 0x0010 */

typedef struct _VI_DEADLOCK_GLOBALS
{
  /* 0x0000 */ __int64 TimeAcquire;
  /* 0x0008 */ __int64 TimeRelease;
  /* 0x0010 */ struct _LIST_ENTRY* ResourceDatabase;
  /* 0x0018 */ unsigned __int64 ResourceDatabaseCount;
  /* 0x0020 */ struct _VF_ADDRESS_RANGE ResourceAddressRange[1023];
  /* 0x4010 */ struct _LIST_ENTRY* ThreadDatabase;
  /* 0x4018 */ unsigned __int64 ThreadDatabaseCount;
  /* 0x4020 */ struct _VF_ADDRESS_RANGE ThreadAddressRange[1023];
  /* 0x8010 */ unsigned long AllocationFailures;
  /* 0x8014 */ unsigned long NodesTrimmedBasedOnAge;
  /* 0x8018 */ unsigned long NodesTrimmedBasedOnCount;
  /* 0x801c */ unsigned long NodesSearched;
  /* 0x8020 */ unsigned long MaxNodesSearched;
  /* 0x8024 */ unsigned long SequenceNumber;
  /* 0x8028 */ unsigned long RecursionDepthLimit;
  /* 0x802c */ unsigned long SearchedNodesLimit;
  /* 0x8030 */ unsigned long DepthLimitHits;
  /* 0x8034 */ unsigned long SearchLimitHits;
  /* 0x8038 */ unsigned long ABC_ACB_Skipped;
  /* 0x803c */ unsigned long OutOfOrderReleases;
  /* 0x8040 */ unsigned long NodesReleasedOutOfOrder;
  /* 0x8044 */ unsigned long TotalReleases;
  /* 0x8048 */ unsigned long RootNodesDeleted;
  /* 0x804c */ unsigned long ForgetHistoryCounter;
  /* 0x8050 */ void* Instigator;
  /* 0x8058 */ unsigned long NumberOfParticipants;
  /* 0x8060 */ struct _VI_DEADLOCK_NODE* Participant[32];
  /* 0x8160 */ long ChildrenCountWatermark;
  /* 0x8164 */ long __PADDING__[1];
} VI_DEADLOCK_GLOBALS, *PVI_DEADLOCK_GLOBALS; /* size: 0x8168 */

